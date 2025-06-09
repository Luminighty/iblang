use crate::{
    ast::{AstModule, Identifier},
    utils::Span,
};

use super::{
    TypeIdent,
    checker::TypecheckContext,
    error::{TypecheckError, TypecheckErrorKind},
    module::Module,
    statement::typecheck_typeident,
};

#[derive(Debug)]
pub struct StructDef {
    pub identifier: Identifier,
    pub fields: Vec<(String, TypeIdent)>,
    pub span: Span,
}

pub fn typecheck_structdefs(
    context: &TypecheckContext,
    ast_module: &AstModule,
    module: &mut Module,
    errors: &mut Vec<TypecheckError>,
) {
    for s in &ast_module.structs {
        if !module.types.insert(s.identifier.to_string()) {
            errors.push(TypecheckError::new(
                TypecheckErrorKind::DuplicateTypeDef,
                s.span,
            ));
        }
    }

    for s in &ast_module.structs {
        let mut is_ok = true;
        let mut fields = Vec::new();
        for field in &s.fields {
            match typecheck_typeident(context, &field.1, s.span) {
                Ok(ty) => {
                    fields.push((field.0.to_string(), ty));
                }
                Err(err) => {
                    is_ok = false;
                    errors.push(err);
                }
            }
        }
        if is_ok {
            module.struct_defs.push(StructDef {
                identifier: s.identifier.to_string(),
                fields,
                span: s.span,
            });
        }
    }
}
