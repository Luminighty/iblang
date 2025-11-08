use std::collections::HashMap;
use std::rc::Rc;

use super::{
    TypeIdent, TypeResult,
    checker::{TypecheckFuncContext, TypecheckMode},
    error::{TypecheckError, TypecheckErrorKind},
    expr::Expr,
};
use crate::{
    ast::prelude::*,
    symbol_resolver::SymbolUID,
    typecheck::{
        checker::TypecheckContext,
        expr::{
            ExprKind, ValueKind, expr_type, ident, load_expr, try_cast, typecheck_expr,
            unwrap_typeident,
        },
        type_struct::StructDef,
    },
    utils::Span,
};

pub fn struct_init(
    global_context: &mut TypecheckContext,
    context: &TypecheckFuncContext,
    struct_id: SymbolUID,
    fields: &Vec<AstObjectInitField>,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let symbol = global_context.symbol_table.get_symbol(&struct_id).unwrap();
    let ty: Rc<StructDef> = match symbol.deep_struct() {
        Ok(ty) => ty,
        Err(err) => {
            return Err(TypecheckError::new(
                TypecheckErrorKind::SymbolError(err),
                context.module_id,
                span,
            ));
        }
    };
    let mut fields_map = HashMap::new();
    let mut errors = Vec::new();
    for field in fields {
        match field {
            AstObjectInitField::Named(key, value) => {
                if fields_map.contains_key(key) {
                    errors.push(TypecheckError::new(
                        TypecheckErrorKind::DuplicateStructField {
                            field: key.to_string(),
                        },
                        context.module_id,
                        span,
                    ));
                }
                match typecheck_expr(global_context, context, value, mode) {
                    Ok(f) => {
                        fields_map.insert(key.to_owned(), f);
                    }
                    Err(err) => {
                        return Err(err);
                    }
                }
            }
            AstObjectInitField::Expr(_) => todo!(),
            AstObjectInitField::Ident(identifier) => {
                fields_map.insert(
                    identifier.to_owned(),
                    ident(global_context, context, identifier.to_string(), span, mode)?,
                );
            }
        }
    }
    let mut valid_fields = Vec::new();
    for (key, field_ty) in &ty.fields {
        let field = match fields_map.remove(key) {
            Some(field) => field,
            None => {
                errors.push(TypecheckError::new(
                    TypecheckErrorKind::MissingStructField {
                        field: key.to_string(),
                    },
                    context.module_id,
                    span,
                ));
                continue;
            }
        };
        let got_type = unwrap_typeident(context.module_id, expr_type(&field), field.span)?;
        let field = try_cast(context, field, got_type, field_ty.clone(), false)?;
        valid_fields.push((key.to_string(), field));
    }

    for (field, _expr) in fields_map {
        errors.push(TypecheckError::new(
            TypecheckErrorKind::UnknownStructField {
                field: field.to_string(),
            },
            context.module_id,
            span,
        ));
    }

    if errors.len() > 0 {
        return Err(TypecheckError::new(
            TypecheckErrorKind::BlockErrors(errors),
            context.module_id,
            span,
        ));
    }

    Ok(Expr {
        span,
        kind: ExprKind::StructInit {
            values: valid_fields,
            ty: TypeIdent::Struct(struct_id),
        },
        value_kind: ValueKind::RValue,
    })
}

pub fn field_lookup(
    global_context: &mut TypecheckContext,
    context: &TypecheckFuncContext,
    obj: Expr,
    ty: SymbolUID,
    obj_ty: TypeIdent,
    field: Identifier,
    is_reference: bool,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let struct_def = global_context
        .symbol_table
        .get_symbol(&ty)
        .unwrap()
        .deep_struct()
        .unwrap();

    let field_ty = match struct_def.get_field_type(&field) {
        Some(ty) => ty.clone(),
        None => {
            return Err(TypecheckError::new(
                TypecheckErrorKind::StructInvalidField {
                    strct: obj_ty.clone(),
                    field: field.to_string(),
                },
                context.module_id,
                span,
            ));
        }
    };

    let obj = if is_reference {
        Expr {
            span,
            value_kind: mode.value_kind,
            kind: ExprKind::Deref {
                expr: Box::new(obj),
                ty: obj_ty.clone(),
            },
        }
    } else {
        obj
    };

    let expr = Expr {
        span,
        value_kind: ValueKind::LValue,
        kind: ExprKind::StructFieldLookup {
            obj: Box::new(obj),
            field,
            struct_ty: obj_ty,
            ty: field_ty.clone(),
        },
    };
    let expr = match mode.value_kind {
        ValueKind::RValue => load_expr(expr, &field_ty),
        ValueKind::LValue => expr,
    };
    Ok(expr)
}
