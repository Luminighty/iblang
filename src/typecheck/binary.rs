use crate::{ast::prelude::*, typecheck::expr::as_identifier, utils::Span};

use super::{
    TypeIdent, TypeResult,
    atomic::Atomic,
    checker::{TypecheckFuncContext, TypecheckMode},
    error::{TypecheckError, TypecheckErrorKind},
    expr::{
        Expr, ExprKind, ValueKind, expr_type, try_cast, typecheck_expr, unwrap_ref,
        unwrap_typeident,
    },
    expr_array::*,
    expr_struct::*,
};

pub fn typecheck_binary(
    context: &TypecheckFuncContext,
    op: BinaryOp,
    lhs: &AstExpr,
    rhs: &AstExpr,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    match op {
        BinaryOp::Index => index(context, lhs, rhs, span, mode),
        BinaryOp::Assign => assign(context, lhs, rhs, span, mode),
        BinaryOp::Arith(op) => arith(context, op, lhs, rhs, span, mode),
        BinaryOp::Pred(op) => pred(context, op, lhs, rhs, span, mode),
        BinaryOp::FieldLookup => field_lookup(context, lhs, rhs, span, mode),
    }
}

fn assign(
    context: &TypecheckFuncContext,
    target: &AstExpr,
    rhs: &AstExpr,
    span: Span,
    _mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let lhs = typecheck_expr(context, target, &TypecheckMode::lvalue())?;
    let lhs_type = unwrap_typeident(expr_type(&lhs), target.span)?;

    // NOTE: array = [1, 2, 3] is not valid in C, but consider it for rewrite
    match lhs_type {
        TypeIdent::Array(_, _) => {
            return Err(TypecheckError::new(
                TypecheckErrorKind::AssignmentToArray,
                span,
            ));
        }
        _ => {}
    }

    // NOTE: value = other_array is not valid in C, but consider it for rewrite
    match lhs.kind {
        ExprKind::Array { .. } => {
            return Err(TypecheckError::new(
                TypecheckErrorKind::AssignmentWithArrayInitializer,
                span,
            ));
        }
        _ => {}
    };

    let rhs_expr = typecheck_expr(context, rhs, &TypecheckMode::rvalue())?;
    let rhs_type = unwrap_typeident(expr_type(&rhs_expr), rhs.span)?;

    let mut rhs = try_cast(rhs_expr, rhs_type, lhs_type.clone())?;
    rhs.value_kind = ValueKind::RValue;

    Ok(Expr {
        span: target.span,
        value_kind: ValueKind::RValue,
        kind: ExprKind::Assign {
            lhs: Box::new(lhs),
            rhs: Box::new(rhs),
            ty: lhs_type,
        },
    })
}

fn pred(
    context: &TypecheckFuncContext,
    op: BinaryPred,
    lhs: &AstExpr,
    rhs: &AstExpr,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let (lhs, rhs, shared) = basic(context, &BinaryOp::Pred(op), lhs, rhs, span, mode)?;
    Ok(Expr {
        span,
        value_kind: ValueKind::RValue,
        kind: ExprKind::BinaryPred {
            op,
            lhs: Box::new(lhs),
            rhs: Box::new(rhs),
            shared,
        },
    })
}

fn arith(
    context: &TypecheckFuncContext,
    op: BinaryArith,
    lhs: &AstExpr,
    rhs: &AstExpr,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let (lhs, rhs, ty) = basic(context, &BinaryOp::Arith(op), lhs, rhs, span, mode)?;
    Ok(Expr {
        span,
        value_kind: ValueKind::RValue,
        kind: ExprKind::BinaryArith {
            op,
            lhs: Box::new(lhs),
            rhs: Box::new(rhs),
            ty,
        },
    })
}

fn basic(
    context: &TypecheckFuncContext,
    op: &BinaryOp,
    lhs: &AstExpr,
    rhs: &AstExpr,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<(Expr, Expr, TypeIdent)> {
    let lhs_span = lhs.span;
    let rhs_span = rhs.span;

    let lhs = typecheck_expr(context, lhs, mode)?;
    let lhs_type = unwrap_typeident(expr_type(&lhs), lhs_span)?;

    let rhs = typecheck_expr(context, rhs, mode)?;
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
