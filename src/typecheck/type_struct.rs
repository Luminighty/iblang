use crate::{
    ast::{
        AstModule, Identifier,
        prelude::{AstStructDef, AstTypeIdent},
    },
    symbol_resolver::{DeepInfo, ModuleUID, Symbol, SymbolStage, SymbolUID},
    typecheck::{
        TypeResult,
        checker::{TypecheckContext, TypecheckMode, resolve_identifier},
        const_eval::const_eval_expr,
        expr::typecheck_expr,
        module,
    },
    utils::Span,
};
use std::rc::Rc;

use super::{
    TypeIdent,
    checker::TypecheckFuncContext,
    error::{TypecheckError, TypecheckErrorKind},
    statement::typecheck_typeident,
};

#[derive(Debug)]
#[allow(dead_code)]
pub struct StructDef {
    pub identifier: Identifier,
    pub fields: Vec<(String, TypeIdent)>,
    pub span: Span,
    pub align: u32,
    pub size: usize,
    pub field_offsets: Vec<usize>,
}

impl StructDef {
    pub fn get_field_idx(&self, field: &str) -> Option<usize> {
        for (i, (key, _)) in self.fields.iter().enumerate() {
            if key == field {
                return Some(i);
            }
        }
        None
    }

    pub fn get_field_type(&self, field: &str) -> Option<&TypeIdent> {
        for (key, ty) in &self.fields {
            if key == field {
                return Some(ty);
            }
        }
        None
    }
}

pub fn typecheck_structdefs(context: &mut TypecheckContext, errors: &mut Vec<TypecheckError>) {
    let mut cycle = Vec::new();
    for (module_id, ast_module) in context.ast_modules {
        for strct in &ast_module.structs {
            let struct_id = context
                .symbol_table
                .get_symbol_uid(&module_id, &strct.identifier)
                .unwrap();
            typecheck_structdef(context, module_id, strct, struct_id, errors, &mut cycle);
        }
    }
}

fn get_aligned_offset(offset: usize, align: usize) -> usize {
    let padding = offset % align;
    if padding == 0 {
        offset
    } else {
        offset + align - padding
    }
}

fn typecheck_structfield(
    context: &mut TypecheckContext,
    module_id: &ModuleUID,
    ty: &AstTypeIdent,
    span: Span,
    errors: &mut Vec<TypecheckError>,
    is_reference: bool,
    cycle: &mut Vec<SymbolUID>,
) -> TypeResult<TypeIdent> {
    match ty {
        AstTypeIdent::Atomic(atomic) => Ok((*atomic).into()),
        AstTypeIdent::Array(ty, ast_expr) => {
            let ty = typecheck_structfield(context, ty, span, errors, is_reference)?;
            let len = typecheck_expr(context, ast_expr, &TypecheckMode::rvalue())?;
            let len = match const_eval_expr(context, &len) {
                Ok(ConstExpr::Literal(l)) => l.as_i64(),
                _ => {
                    return Err(TypecheckError::new(
                        TypecheckErrorKind::InvalidConst,
                        ast_expr.span,
                    ));
                }
            };
            if len < 0 {
                Err(TypecheckError::new(
                    TypecheckErrorKind::InvalidArrayLength(len),
                    ast_expr.span,
                ))
            } else {
                Ok(TypeIdent::Array(Box::new(ty), len as usize))
            }
        }
        AstTypeIdent::Ref(ty) => {
            let ty = typecheck_structfield(context, module_id, ty, span, errors, true, cycle)?;
            Ok(TypeIdent::Ref(Box::new(ty)))
        }
        AstTypeIdent::Compound(ident) if is_reference => {
            let struct_id = resolve_identifier(context.symbol_table, module_id, ident, &span)?;
            Ok(TypeIdent::Struct(struct_id))
        }
        AstTypeIdent::Compound(ident) => {
            let struct_id = resolve_identifier(context.symbol_table, module_id, ident, &span)?;
            let symbol = context.symbol_table.get_symbol(&struct_id).unwrap();
            match symbol.stage {
                SymbolStage::Typechecked => Ok(TypeIdent::Struct(struct_id)),
                SymbolStage::TypecheckInProgress => Err(TypecheckError::new(
                    TypecheckErrorKind::CircularTypeDependency {
                        cycle: cycle.clone(),
                    },
                    span,
                )),
                SymbolStage::SymbolResolved => {
                    let mut errors = Vec::new();
                    typecheck_structdef(
                        context,
                        &symbol.module_uid,
                        &symbol.shallow_struct().unwrap(),
                        struct_id,
                        &mut errors,
                        cycle,
                    );
                    match errors.len() {
                        0 => Ok(TypeIdent::Struct(struct_id)),
                        1 => Err(errors[0]),
                        _ => Err(TypecheckError::new(
                            TypecheckErrorKind::BlockErrors(errors),
                            span,
                        )),
                    }
                }
                _ => Err(TypecheckError::new(
                    TypecheckErrorKind::UndefinedTypeIdent,
                    span,
                )),
            }
        }
    }
}

pub fn typecheck_structdef(
    context: &mut TypecheckContext,
    module_id: &ModuleUID,
    strct: &AstStructDef,
    struct_id: SymbolUID,
    errors: &mut Vec<TypecheckError>,
    cycle: &mut Vec<SymbolUID>,
) {
    if context.symbol_table.get_stage(&struct_id) == SymbolStage::Typechecked {
        return;
    }
    let mut is_ok = true;
    let mut fields = Vec::new();
    let mut max_align = 1;
    let mut field_offsets = Vec::new();
    let mut offset = 0;
    context
        .symbol_table
        .set_stage(&struct_id, SymbolStage::TypecheckInProgress);
    cycle.push(*module_id);
    for field in &strct.fields {
        let (size, align) = match typecheck_structfield(
            context, module_id, &field.1, strct.span, errors, false, cycle,
        ) {
            Ok(ty) => {
                let module = context.modules.get_mut(module_id).unwrap();
                let size_align = module.type_size_and_align(&ty, &context.symbol_table);
                fields.push((field.0.to_string(), ty));
                size_align
            }
            Err(err) => {
                is_ok = false;
                errors.push(err);
                continue;
            }
        };
        // NOTE: Numbers will become invalid if a typeident is invalid, but we don't really care
        //  for those structs
        max_align = usize::max(max_align, align as usize);
        offset = get_aligned_offset(offset, align as usize);
        field_offsets.push(offset);
        offset += size;
    }
    cycle.pop();
    let size = get_aligned_offset(offset, max_align).max(1);
    if !is_ok {
        return;
    }
    let def = Rc::new(StructDef {
        identifier: strct.identifier.to_string(),
        fields,
        span: strct.span,
        size,
        align: max_align as u32,
        field_offsets,
    });
    context
        .symbol_table
        .attach_deep(&struct_id, DeepInfo::Struct(def.clone()));
    let module = context.modules.get_mut(module_id).unwrap();
    module.struct_defs.push(def);
}
