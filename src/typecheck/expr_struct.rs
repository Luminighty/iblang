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
    typecheck::{
        checker::{TypecheckContext, resolve_identifier},
        expr::{
            ExprKind, ValueKind, as_identifier, expr_type, load_expr, try_cast, typecheck_expr,
            unwrap_typeident,
        },
        type_struct::StructDef,
    },
    utils::Span,
};

pub fn struct_init(
    global_context: &mut TypecheckContext,
    context: &TypecheckFuncContext,
    ty: &Identifier,
    fields: &Vec<AstStructInitField>,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let struct_id = resolve_identifier(global_context.symbol_table, &context.module_id, ty, &span)?;
    let symbol = global_context.symbol_table.get_symbol(&struct_id).unwrap();
    let ty: Rc<StructDef> = match symbol.deep_struct() {
        Ok(ty) => ty,
        Err(err) => {
            return Err(TypecheckError::new(
                TypecheckErrorKind::SymbolError(err),
                span,
            ));
        }
    };
    let mut fields_map = HashMap::new();
    let mut errors = Vec::new();
    for field in fields {
        match field {
            AstStructInitField::Named(key, value) => {
                match typecheck_expr(global_context, context, value, mode) {
                    Ok(f) => {
                        fields_map.insert(key, f);
                    }
                    Err(err) => {
                        return Err(err);
                    }
                }
            }
            AstStructInitField::Expr(_ast_expr) => todo!(),
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
                    span,
                ));
                continue;
            }
        };
        let got_type = unwrap_typeident(expr_type(&field), field.span)?;
        let field = try_cast(field, got_type, field_ty.clone())?;
        valid_fields.push((key.to_string(), field));
    }

    for (field, expr) in fields_map {
        errors.push(TypecheckError::new(
            TypecheckErrorKind::UnknownStructField {
                field: field.to_string(),
            },
            expr.span,
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
    lhs: &AstExpr,
    rhs: &AstExpr,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let obj_span = lhs.span;
    let obj = typecheck_expr(global_context, context, lhs, &TypecheckMode::lvalue())?;
    let field = as_identifier(rhs, rhs.span)?;
    let mut obj_ty = unwrap_typeident(expr_type(&obj), obj.span)?;

    let mut is_reference = false;
    // TODO: Handle errors here
    macro_rules! unwrap_struct_def {
        ($ty: expr) => {
            match $ty {
                TypeIdent::Ref(ty) => match *ty {
                    TypeIdent::Struct(ty) => {
                        is_reference = true;
                        obj_ty = TypeIdent::Struct(ty.clone());
                        Some(
                            global_context
                                .symbol_table
                                .get_symbol(&ty)
                                .unwrap()
                                .deep_struct()
                                .unwrap(),
                        )
                    }
                    _ => None,
                },
                TypeIdent::Struct(ty) => Some(
                    global_context
                        .symbol_table
                        .get_symbol(&ty)
                        .unwrap()
                        .deep_struct()
                        .unwrap(),
                ),
                _ => None,
            }
        };
    }

    let struct_def = match unwrap_struct_def!(obj_ty.clone()) {
        Some(ty) => ty,
        None => {
            return Err(TypecheckError::new(
                TypecheckErrorKind::StructExpected { got: obj_ty },
                obj_span,
            ));
        }
    };

    let field_ty = match struct_def.get_field_type(&field) {
        Some(ty) => ty.clone(),
        None => {
            return Err(TypecheckError::new(
                TypecheckErrorKind::StructInvalidField {
                    strct: obj_ty.clone(),
                    field: field.to_string(),
                },
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
        kind: ExprKind::FieldLookup {
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
