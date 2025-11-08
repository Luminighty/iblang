use crate::{
    ast::{AstModule, Identifier, prelude::AstUnionDef},
    symbol_resolver::{DeepInfo, ModuleUID, SymbolStage, SymbolUID},
    typecheck::{
        checker::TypecheckContext, module::type_size_and_align, statement::typecheck_typeident,
    },
    utils::Span,
};
use std::collections::HashMap;
use std::rc::Rc;

use super::{TypeIdent, error::TypecheckError};

#[derive(Debug)]
#[allow(dead_code)]
pub struct UnionDef {
    pub identifier: Identifier,
    pub fields: Vec<(String, TypeIdent)>,
    pub span: Span,
    pub align: u32,
    pub size: usize,
}

impl UnionDef {
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

pub fn typecheck_uniondefs(
    context: &mut TypecheckContext,
    ast_modules: &HashMap<ModuleUID, AstModule>,
    errors: &mut Vec<TypecheckError>,
) {
    let mut cycle = Vec::new();
    for (module_id, ast_module) in ast_modules {
        for union in &ast_module.unions {
            let union_id = context
                .symbol_table
                .get_symbol_uid(&module_id, &union.identifier)
                .unwrap();
            typecheck_uniondef(context, module_id, union, union_id, errors, &mut cycle);
        }
    }
}

// fn get_aligned_offset(offset: usize, align: usize) -> usize {
//     let padding = offset % align;
//     if padding == 0 {
//         offset
//     } else {
//         offset + align - padding
//     }
// }
//
pub fn typecheck_uniondef(
    context: &mut TypecheckContext,
    module_id: &ModuleUID,
    union: &AstUnionDef,
    union_id: SymbolUID,
    errors: &mut Vec<TypecheckError>,
    cycle: &mut Vec<SymbolUID>,
) {
    if context.symbol_table.get_stage(&union_id) == SymbolStage::Typechecked {
        return;
    }
    let mut is_ok = true;
    let mut fields = Vec::new();
    let mut max_align = 1;
    let mut max_size = 1;
    context
        .symbol_table
        .set_stage(&union_id, SymbolStage::TypecheckInProgress);

    cycle.push(*module_id);
    for field in &union.fields {
        let (size, align) =
            match typecheck_typeident(context, module_id, &field.1, union.span, false, cycle) {
                Ok(ty) => {
                    let _module = context.modules.get_mut(module_id).unwrap();
                    let size_align = type_size_and_align(&ty, &context.symbol_table);
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
        max_size = max_size.max(size);
    }
    cycle.pop();

    if !is_ok {
        return;
    }
    let def = Rc::new(UnionDef {
        identifier: union.identifier.to_string(),
        fields,
        span: union.span,
        size: max_size,
        align: max_align as u32,
    });
    context
        .symbol_table
        .attach_deep(&union_id, DeepInfo::Union(def.clone()));
    let module = context.modules.get_mut(module_id).unwrap();
    module.union_defs.push(def);
}
