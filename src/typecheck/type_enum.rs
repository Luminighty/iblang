use crate::{
    ast::{
        AstModule, Identifier,
        prelude::{AstEnumDef, AstTypeIdent},
    },
    symbol_resolver::{DeepInfo, ModuleUID, Symbol, SymbolStage, SymbolUID},
    typecheck::{
        TypeResult,
        checker::{TypecheckContext, TypecheckMode},
        const_eval::{ConstExpr, const_eval_expr},
        expr::typecheck_expr,
        module,
        statement::typecheck_typeident,
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
    pub fields: Vec<String>,
    pub span: Span,
    pub align: u32,
    pub size: usize,
}

impl EnumDef {
    pub fn get_field_value(&self, field: &str) -> Option<usize> {
        for (i, (key)) in self.fields.iter().enumerate() {
            if key == field {
                return Some(i);
            }
        }
        None
    }
}

pub fn typecheck_enumdefs(
    context: &mut TypecheckContext,
    ast_modules: &HashMap<ModuleUID, AstModule>,
    errors: &mut Vec<TypecheckError>,
) {
    for (module_id, ast_module) in ast_modules {
        for _enum in &ast_module.enums {
            let enum_id = context
                .symbol_table
                .get_symbol_uid(&module_id, &_enum.identifier)
                .unwrap();
            typecheck_enumdef(context, module_id, _enum, enum_id, errors);
        }
    }
}

pub fn typecheck_enumdef(
    context: &mut TypecheckContext,
    module_id: &ModuleUID,
    _enum: &AstEnumDef,
    enum_id: SymbolUID,
    errors: &mut Vec<TypecheckError>,
) {
    if context.symbol_table.get_stage(&enum_id) == SymbolStage::Typechecked {
        return;
    }
    let mut is_ok = true;
    context
        .symbol_table
        .set_stage(&enum_id, SymbolStage::TypecheckInProgress);

    let mut duplicates = Vec::new();
    for i in 0.._enum.fields.len() {
        for j in (i + 1).._enum.fields.len() {
            if _enum.fields[i] == _enum.fields[j] {
                if !duplicates.contains(&_enum.fields[i]) {
                    duplicates.push(_enum.fields[i].to_string());
                    is_ok = false;
                }
            }
        }
    }

    if !is_ok {
        return;
    }
    // TODO: Consider calculating actual required size and alignment
    let def = Rc::new(EnumDef {
        identifier: _enum.identifier.to_string(),
        fields: _enum.fields.clone(),
        span: _enum.span,
        size: 8,
        align: 8 as u32,
    });
    context
        .symbol_table
        .attach_deep(&enum_id, DeepInfo::Enum(def.clone()));
    let module = context.modules.get_mut(module_id).unwrap();
    module.enum_defs.push(def);
}
