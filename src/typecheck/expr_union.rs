use std::collections::HashMap;
use std::rc::Rc;

use super::{
    CastMethod, FlowType, TypeIdent, TypeResult,
    binary::typecheck_binary,
    checker::{TypecheckFuncContext, TypecheckMode},
    error::{TypecheckError, TypecheckErrorKind},
    expr::Expr,
    unary::typecheck_unary,
};
use crate::{
    ast::prelude::*,
    symbol_resolver::SymbolUID,
    typecheck::{
        checker::{TypecheckContext, resolve_identifier},
        expr::{
            ExprKind, ValueKind, as_identifier, expr_type, ident, load_expr, try_cast,
            typecheck_expr, unwrap_typeident,
        },
        type_union::UnionDef,
    },
    utils::Span,
};

pub fn union_init(
    global_context: &mut TypecheckContext,
    context: &TypecheckFuncContext,
    union_id: SymbolUID,
    fields: &Vec<AstObjectInitField>,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let symbol = global_context.symbol_table.get_symbol(&union_id).unwrap();
    let ty: Rc<UnionDef> = match symbol.deep_union() {
        Ok(ty) => ty,
        Err(err) => {
            return Err(TypecheckError::new(
                TypecheckErrorKind::SymbolError(err),
                context.module_id,
                span,
            ));
        }
    };
    if fields.len() > 1 {
        return Err(TypecheckError::new(
            TypecheckErrorKind::MultipleFieldForUnionInit,
            context.module_id,
            span,
        ));
    }
    let field = &fields[0];
    let (field_key, field) = match field {
        AstObjectInitField::Named(key, value) => {
            match typecheck_expr(global_context, context, value, mode) {
                Ok(f) => (key.to_owned(), f),
                Err(err) => {
                    return Err(err);
                }
            }
        }
        AstObjectInitField::Expr(value) => todo!(),
        AstObjectInitField::Ident(identifier) => (
            identifier.to_owned(),
            ident(global_context, context, identifier.to_string(), span, mode)?,
        ),
    };
    let mut validated_field = None;
    for (key, field_ty) in &ty.fields {
        if key != &field_key {
            continue;
        }
        let got_type = unwrap_typeident(context.module_id, expr_type(&field), field.span)?;
        let field = try_cast(context, field, got_type, field_ty.clone())?;
        validated_field = Some(field);
        break;
    }
    let field = if let Some(field) = validated_field {
        field
    } else {
        return Err(TypecheckError::new(
            TypecheckErrorKind::UnknownUnionField { field: field_key },
            context.module_id,
            span,
        ));
    };

    Ok(Expr {
        span,
        kind: ExprKind::UnionInit {
            field: field_key,
            value: Box::new(field),
            ty: TypeIdent::Union(union_id),
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
    let union_def = global_context
        .symbol_table
        .get_symbol(&ty)
        .unwrap()
        .deep_union()
        .unwrap();

    let field_ty = match union_def.get_field_type(&field) {
        Some(ty) => ty.clone(),
        None => {
            return Err(TypecheckError::new(
                TypecheckErrorKind::UnionInvalidField {
                    union: obj_ty.clone(),
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
        kind: ExprKind::UnionFieldLookup {
            obj: Box::new(obj),
            field,
            union_ty: obj_ty,
            ty: field_ty.clone(),
        },
    };
    let expr = match mode.value_kind {
        ValueKind::RValue => load_expr(expr, &field_ty),
        ValueKind::LValue => expr,
    };
    Ok(expr)
}
