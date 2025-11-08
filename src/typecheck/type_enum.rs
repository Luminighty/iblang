use crate::{
    ast::{
        AstModule, Identifier,
        prelude::{AstEnumDef, AstExpr, Literal},
    },
    symbol_resolver::{DeepInfo, ModuleUID, SymbolStage, SymbolUID},
    typecheck::{
        TypeResult,
        atomic::Atomic,
        checker::{TypecheckContext, TypecheckMode},
        const_eval::{ConstExpr, const_eval_expr},
        expr::{expr_type, try_cast, typecheck_expr, unwrap_typeident},
    },
    utils::Span,
};
use std::collections::HashMap;
use std::rc::Rc;

use super::{
    TypeIdent,
    checker::TypecheckFuncContext,
    error::{TypecheckError, TypecheckErrorKind},
};

#[derive(Debug)]
#[allow(dead_code)]
pub struct EnumDef {
    pub identifier: Identifier,
    pub fields: Vec<(String, i64)>,
    pub span: Span,
    pub align: u32,
    pub size: usize,
}

impl EnumDef {
    pub fn get_field_value(&self, field: &str) -> Option<i64> {
        for (_i, (key, v)) in self.fields.iter().enumerate() {
            if key == field {
                return Some(*v);
            }
        }
        None
    }
}

pub fn typecheck_enumdefs(
    global_context: &mut TypecheckContext,
    ast_modules: &HashMap<ModuleUID, AstModule>,
    errors: &mut Vec<TypecheckError>,
) {
    for (module_id, ast_module) in ast_modules {
        let mut context = TypecheckFuncContext::new(*module_id);
        for _enum in &ast_module.enums {
            let enum_id = global_context
                .symbol_table
                .get_symbol_uid(&module_id, &_enum.identifier)
                .unwrap();
            typecheck_enumdef(
                global_context,
                &mut context,
                module_id,
                _enum,
                enum_id,
                errors,
            );
        }
    }
}

fn eval_enum_value(
    global_context: &mut TypecheckContext,
    context: &mut TypecheckFuncContext,
    value: &AstExpr,
) -> TypeResult<ConstExpr> {
    let mut value = typecheck_expr(global_context, context, &value, &TypecheckMode::rvalue())?;
    let value_type = unwrap_typeident(context.module_id, expr_type(&value), value.span)?;
    value = try_cast(
        context,
        value,
        value_type,
        TypeIdent::Atomic(Atomic::int()),
        false,
    )?;
    const_eval_expr(context, &value)
}

pub fn typecheck_enumdef(
    global_context: &mut TypecheckContext,
    context: &mut TypecheckFuncContext,
    module_id: &ModuleUID,
    _enum: &AstEnumDef,
    enum_id: SymbolUID,
    errors: &mut Vec<TypecheckError>,
) {
    if global_context.symbol_table.get_stage(&enum_id) == SymbolStage::Typechecked {
        return;
    }
    let mut is_ok = true;
    global_context
        .symbol_table
        .set_stage(&enum_id, SymbolStage::TypecheckInProgress);

    let mut next_value = 0;
    let mut duplicates = Vec::new();
    let mut fields = Vec::new();
    for i in 0.._enum.fields.len() {
        let variant_i = &_enum.fields[i].0;
        for j in (i + 1).._enum.fields.len() {
            let variant_j = &_enum.fields[j].0;
            if variant_i == variant_j && !duplicates.contains(variant_i) {
                duplicates.push(variant_i.to_string());
                errors.push(TypecheckError::new(
                    TypecheckErrorKind::DuplicateEnumVariant {
                        variant: variant_i.to_string(),
                    },
                    context.module_id,
                    _enum.span,
                ));
                is_ok = false;
            }
        }
        let value = if let Some(value) = &_enum.fields[i].1 {
            match eval_enum_value(global_context, context, value) {
                Ok(ConstExpr::Literal(Literal::Number(v))) => v,
                Ok(value) => {
                    errors.push(TypecheckError::new(
                        TypecheckErrorKind::InvalidEnumValue {
                            variant: variant_i.to_string(),
                            value,
                        },
                        context.module_id,
                        _enum.span,
                    ));
                    is_ok = false;
                    next_value
                }
                Err(err) => {
                    errors.push(err);
                    is_ok = false;
                    next_value
                }
            }
        } else {
            next_value
        };
        next_value = value + 1;
        fields.push((variant_i.to_string(), value))
    }

    if !is_ok {
        return;
    }
    // TODO: Consider calculating actual required size and alignment
    let def = Rc::new(EnumDef {
        identifier: _enum.identifier.to_string(),
        fields,
        span: _enum.span,
        size: 8,
        align: 8 as u32,
    });
    global_context
        .symbol_table
        .attach_deep(&enum_id, DeepInfo::Enum(def.clone()));
    let module = global_context.modules.get_mut(module_id).unwrap();
    module.enum_defs.push(def);
}
