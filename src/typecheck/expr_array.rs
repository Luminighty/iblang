use std::collections::HashMap;

use super::{
    CastMethod, FlowType, TypeIdent, TypeResult,
    atomic::Atomic,
    binary::typecheck_binary,
    checker::{TypecheckContext, TypecheckMode},
    error::{TypecheckError, TypecheckErrorKind},
    expr::{Expr, ExprKind, expr_type, load_expr, try_cast, typecheck_expr, unwrap_typeident},
    unary::typecheck_unary,
};
use crate::{ast::prelude::*, typecheck::expr::ValueKind, utils::Span};

fn find_array_type(
    context: &TypecheckContext,
    exprs: &Vec<Expr>,
    span: Span,
) -> Result<TypeIdent, TypecheckError> {
    macro_rules! unwrap_or_return_typeident {
        ($ty: expr) => {{
            let ty = expr_type($ty);
            match unwrap_typeident(ty.clone(), $ty.span) {
                Ok(ty) => ty,
                _ => {
                    return Err(TypecheckError::new(
                        TypecheckErrorKind::GotArrayElementWithoutValue { got: ty },
                        span,
                    ));
                }
            }
        }};
    }

    if let Some(target_type) = &context.target_type {
        match target_type {
            TypeIdent::Array(array_type, _) => Ok(*array_type.clone()),
            _ => {
                return Err(TypecheckError::new(
                    TypecheckErrorKind::TargetTypeWasNotArray,
                    span,
                ));
            }
        }
    } else {
        // NOTE: We try to figure out what the actual type is gonna be for the array,
        // based on its elements
        let mut shared_type = match exprs.get(0) {
            Some(expr) => unwrap_or_return_typeident!(expr),
            _ => {
                return Err(TypecheckError::new(
                    TypecheckErrorKind::EmptyArrayWithoutType,
                    span,
                ));
            }
        };
        for expr in exprs {
            let ty = unwrap_or_return_typeident!(expr);
            shared_type = match TypeIdent::shared_type(&shared_type, &ty) {
                Ok(ty) => ty,
                _ => {
                    return Err(TypecheckError::new(
                        TypecheckErrorKind::InvalidArrayElementType {
                            expected: shared_type,
                            got: ty,
                        },
                        expr.span,
                    ));
                }
            }
        }
        Ok(shared_type.clone())
    }
}

pub fn array(
    context: &TypecheckContext,
    values: &Vec<AstExpr>,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let mut exprs = Vec::with_capacity(values.len());
    for value in values {
        let expr = typecheck_expr(context, value, &TypecheckMode::rvalue())?;
        exprs.push(expr);
    }

    let target_type = find_array_type(context, &exprs, span)?;
    let mut valid_expr = Vec::with_capacity(exprs.len());
    for expr in exprs.into_iter() {
        let span = expr.span;
        let ty = unwrap_typeident(expr_type(&expr), span)?;
        valid_expr.push(try_cast(expr, ty, target_type.clone())?);
    }

    let len = valid_expr.len();
    let ty = TypeIdent::Array(Box::new(target_type.clone()), len);
    Ok(Expr {
        span,
        kind: ExprKind::Array {
            values: valid_expr,
            ty,
        },
        value_kind: ValueKind::RValue,
    })
}

pub fn index(
    module: &TypecheckContext,
    lhs: &AstExpr,
    rhs: &AstExpr,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let lhs_span = lhs.span;
    let lhs = typecheck_expr(module, lhs, &TypecheckMode::rvalue())?;
    let lhs_type = unwrap_typeident(expr_type(&lhs), lhs.span)?;

    let elem_ty = match lhs_type {
        TypeIdent::Array(ty, _len) => ty,
        TypeIdent::Ref(ty) => match *ty {
            TypeIdent::Array(ty, _) => ty,
            _ => ty,
        },
        TypeIdent::Atomic(_) | TypeIdent::Struct(_) => {
            return Err(TypecheckError::new(
                TypecheckErrorKind::InvalidIndex,
                lhs_span,
            ));
        }
    };

    let rhs = typecheck_expr(module, rhs, &TypecheckMode::rvalue())?;
    let rhs_type = unwrap_typeident(expr_type(&rhs), rhs.span)?;

    let rhs = try_cast(rhs, rhs_type, TypeIdent::Atomic(Atomic::int()))?;

    let expr = Expr {
        span,
        value_kind: ValueKind::LValue,
        kind: ExprKind::Index {
            expr: Box::new(lhs),
            index: Box::new(rhs),
            ty: *elem_ty.clone(),
        },
    };

    let expr = match mode.value_kind {
        ValueKind::RValue => load_expr(expr, &elem_ty),
        ValueKind::LValue => expr,
    };
    Ok(expr)
}
