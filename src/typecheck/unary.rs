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
    if UnaryOp::GROUP == op {
        return typecheck_expr(module, expr, mode);
    }
    let expr = typecheck_expr(module, expr, mode)?;
    let expr_ty = unwrap_typeident(expr_type(&expr), span)?;

    match op {
        UnaryOp::REF => {
            let expr = expr.auto_deref(expr_ty);
            let expr_ty = unwrap_typeident(expr_type(&expr), expr.span)?;
            into_ref(expr, expr_ty, span)
        }
        UnaryOp::DEREF => into_deref(expr, expr_ty, span),
        UnaryOp::GROUP => Ok(expr),
        UnaryOp::Arith(op) => {
            let expr = expr.auto_deref(expr_ty);
            let expr_ty = unwrap_typeident(expr_type(&expr), expr.span)?;
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

fn into_ref(expr: Expr, expr_type: TypeIdent, span: Span) -> TypeResult<Expr> {
    match expr.kind {
        ExprKind::Deref { expr, .. } => return Ok(*expr),
        _ => {}
    }
    Ok(Expr {
        span,
        kind: ExprKind::Ref {
            expr: Box::new(expr),
            ty: TypeIdent::Ref(Box::new(expr_type)),
        },
    })
}

fn into_deref(expr: Expr, expr_type: TypeIdent, span: Span) -> TypeResult<Expr> {
    match expr.kind {
        ExprKind::Ref { expr, .. } => return Ok(*expr),
        _ => {}
    }
    match expr_type {
        TypeIdent::Ref(r) => Ok(Expr {
            span,
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
