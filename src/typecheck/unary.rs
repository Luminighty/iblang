use crate::{ast::prelude::*, utils::Span};

use super::{
    TypeIdent, TypeResult,
    atomic::Atomic,
    checker::{TypecheckContext, TypecheckMode},
    error::*,
    expr::*,
};

pub fn typecheck_unary(
    module: &TypecheckContext,
    op: UnaryOp,
    expr: &AstExpr,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    match op {
        UnaryOp::REF => into_ref(module, expr, span, mode),
        UnaryOp::DEREF => into_deref(module, expr, span, mode),
        UnaryOp::GROUP => typecheck_expr(module, expr, mode),
        UnaryOp::Arith(op) => {
            let expr = typecheck_expr(module, expr, mode)?;
            let expr_ty = unwrap_typeident(expr_type(&expr), span)?;
            match expr_ty {
                TypeIdent::Atomic(atom) => atomic(atom, op, expr, expr_ty, span),
                _ => {
                    return Err(TypecheckError::new(
                        TypecheckErrorKind::UnaryTypeMismatch { op, value: expr_ty },
                        span,
                    ));
                }
            }
        }
    }
}

fn into_ref(
    module: &TypecheckContext,
    expr: &AstExpr,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let expr = typecheck_expr(module, expr, &TypecheckMode::lvalue())?;
    let expr_ty = unwrap_typeident(expr_type(&expr), span)?;
    Ok(Expr {
        span,
        value_kind: ValueKind::LValue,
        kind: ExprKind::Ref {
            expr: Box::new(expr),
            ty: TypeIdent::Ref(Box::new(expr_ty)),
        },
    })
}

fn into_deref(
    module: &TypecheckContext,
    expr: &AstExpr,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let expr = typecheck_expr(module, expr, mode)?;
    let expr_ty = unwrap_typeident(expr_type(&expr), span)?;
    match expr_ty {
        TypeIdent::Ref(r) => Ok(Expr {
            span,
            value_kind: mode.value_kind,
            kind: ExprKind::Deref {
                expr: Box::new(expr),
                ty: *r,
            },
        }),
        _ => Err(TypecheckError::new(
            TypecheckErrorKind::DereffedAtomic,
            span,
        )),
    }
}

fn atomic(
    atom: Atomic,
    op: UnaryArith,
    expr: Expr,
    expr_type: TypeIdent,
    span: Span,
) -> TypeResult<Expr> {
    match atom.unary_result(op) {
        Ok(new_type) => {
            let expr = try_cast(expr, expr_type, TypeIdent::Atomic(new_type.clone()))?;
            Ok(Expr {
                span,
                value_kind: ValueKind::RValue,
                kind: ExprKind::Unary {
                    op,
                    expr: Box::new(expr),
                    ty: TypeIdent::Atomic(new_type),
                },
            })
        }
        _ => {
            return Err(TypecheckError::new(
                TypecheckErrorKind::UnaryTypeMismatch {
                    op,
                    value: expr_type,
                },
                span,
            ));
        }
    }
}
