use crate::{ast::prelude::*, typecheck::expr::as_identifier, utils::Span};

use super::{
    TypeIdent, TypeResult,
    atomic::Atomic,
    checker::{TypecheckContext, TypecheckMode},
    error::{TypecheckError, TypecheckErrorKind},
    expr::{
        Expr, ExprKind, ValueKind, expr_type, try_cast, typecheck_expr, unwrap_ref,
        unwrap_typeident,
    },
    expr_array::*,
    expr_struct::*,
};

pub fn typecheck_binary(
    module: &TypecheckContext,
    op: BinaryOp,
    lhs: &AstExpr,
    rhs: &AstExpr,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    match op {
        BinaryOp::Index => index(module, lhs, rhs, span, mode),
        BinaryOp::Assign => assign(module, lhs, rhs, mode),
        BinaryOp::Arith(op) => arith(module, op, lhs, rhs, span, mode),
        BinaryOp::Pred(op) => pred(module, op, lhs, rhs, span, mode),
        BinaryOp::FieldLookup => field_lookup(module, lhs, rhs, span, mode),
    }
}

fn assign(
    module: &TypecheckContext,
    target: &AstExpr,
    rhs: &AstExpr,
    _mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let lhs = typecheck_expr(module, target, &TypecheckMode::lvalue())?;
    let lhs_type = unwrap_typeident(expr_type(&lhs), target.span)?;
    // let lhs_type = unwrap_ref(lhs_type, target.span)?;

    let rhs_expr = typecheck_expr(module, rhs, &TypecheckMode::rvalue())?;
    let rhs_type = unwrap_typeident(expr_type(&rhs_expr), rhs.span)?;

    let mut rhs = try_cast(rhs_expr, rhs_type, lhs_type.clone())?;
    rhs.value_kind = ValueKind::RValue;

    Ok(Expr {
        span: target.span,
        value_kind: ValueKind::LValue,
        kind: ExprKind::Assign {
            lhs: Box::new(lhs),
            rhs: Box::new(rhs),
            ty: lhs_type,
        },
    })
}

fn pred(
    module: &TypecheckContext,
    op: BinaryPred,
    lhs: &AstExpr,
    rhs: &AstExpr,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let (lhs, rhs, shared) = basic(module, &BinaryOp::Pred(op), lhs, rhs, span, mode)?;
    Ok(Expr {
        span,
        value_kind: ValueKind::LValue,
        kind: ExprKind::BinaryPred {
            op,
            lhs: Box::new(lhs),
            rhs: Box::new(rhs),
            shared,
        },
    })
}

fn arith(
    module: &TypecheckContext,
    op: BinaryArith,
    lhs: &AstExpr,
    rhs: &AstExpr,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let (lhs, rhs, ty) = basic(module, &BinaryOp::Arith(op), lhs, rhs, span, mode)?;
    Ok(Expr {
        span,
        value_kind: ValueKind::LValue,
        kind: ExprKind::BinaryArith {
            op,
            lhs: Box::new(lhs),
            rhs: Box::new(rhs),
            ty,
        },
    })
}

fn basic(
    module: &TypecheckContext,
    op: &BinaryOp,
    lhs: &AstExpr,
    rhs: &AstExpr,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<(Expr, Expr, TypeIdent)> {
    let lhs_span = lhs.span;
    let rhs_span = rhs.span;

    let lhs = typecheck_expr(module, lhs, mode)?;
    let lhs_type = unwrap_typeident(expr_type(&lhs), lhs_span)?;

    let rhs = typecheck_expr(module, rhs, mode)?;
    let rhs_type = unwrap_typeident(expr_type(&rhs), rhs_span)?;

    let common_type = match TypeIdent::shared_type(&lhs_type, &rhs_type) {
        Ok(ty) => ty,
        Err(_) => {
            return Err(TypecheckError::new(
                TypecheckErrorKind::BinaryTypeMismatch {
                    op: *op,
                    lhs: lhs_type,
                    rhs: rhs_type,
                },
                span,
            ));
        }
    };

    let mut lhs = try_cast(lhs, lhs_type, common_type.clone())?;
    let mut rhs = try_cast(rhs, rhs_type, common_type.clone())?;
    lhs.value_kind = ValueKind::RValue;
    rhs.value_kind = ValueKind::RValue;

    Ok((lhs, rhs, common_type))
}
