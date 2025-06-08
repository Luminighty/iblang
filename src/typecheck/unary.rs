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
    let expr = typecheck_expr(module, expr, mode)?;
    let expr_type = unwrap_typeident(expr_type(&expr), span)?;

    match op {
        UnaryOp::REF => into_ref(expr, expr_type, span),
        UnaryOp::DEREF => into_deref(expr, expr_type, span),
        UnaryOp::GROUP => Ok(expr),
        UnaryOp::Arith(op) => match expr_type {
            TypeIdent::Atomic(atom) => atomic(atom, op, expr, expr_type, span),
            _ => {
                return Err(TypecheckError::new(
                    TypecheckErrorKind::UnaryTypeMismatch {
                        op,
                        value: expr_type,
                    },
                    span,
                ));
            }
        },
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
