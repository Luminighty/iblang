use crate::{ast::prelude::*, utils::Span};

use super::{atomic::Atomic, checker::{TypecheckContext, TypecheckMode}, error::{TypecheckError, TypecheckErrorKind}, expr::{expr_type, lvalue, try_cast, typecheck_expr, unwrap_typeident, Expr, ExprKind}, TypeIdent, TypeResult};


pub fn typecheck_binary(module: &TypecheckContext, op: BinaryOp, lhs: &AstExpr, rhs: &AstExpr, span: Span, mode: &TypecheckMode) -> TypeResult<Expr> {
    match op {
        BinaryOp::Index => index(module, lhs, rhs, span, mode),
        BinaryOp::Assign => assign(module, lhs, rhs, mode),
        BinaryOp::Arith(op) => arith(module, op, lhs, rhs, span, mode),
        BinaryOp::Pred(op) => pred(module, op, lhs, rhs, span, mode),
    }
}


fn index(module: &TypecheckContext, lhs: &AstExpr, rhs: &AstExpr, span: Span, mode: &TypecheckMode) -> TypeResult<Expr> {
    let lhs_span = lhs.span;
    let lhs = typecheck_expr(module, lhs, mode)?;
    let lhs_type = unwrap_typeident(expr_type(&lhs), lhs.span)?;

    let arr_ty = match lhs_type {
        TypeIdent::Array(ty, len) => ty,
        TypeIdent::Atomic(_) => return Err(
            TypecheckError::new(TypecheckErrorKind::IndexedAtomic, lhs_span)
        ),
        TypeIdent::Ref(_) => todo!(),
    };

    let rhs = typecheck_expr(module, rhs, mode)?;
    let rhs_type = unwrap_typeident(expr_type(&rhs), rhs.span)?;

    let rhs = try_cast(rhs, rhs_type, TypeIdent::Atomic(Atomic::int()))?;

    Ok(Expr {
        span,
        kind: ExprKind::Index { 
            expr: Box::new(lhs),
            index: Box::new(rhs),
            ty: *arr_ty,
        }
    })
}


fn assign(module: &TypecheckContext, target: &AstExpr, rhs: &AstExpr, mode: &TypecheckMode) -> TypeResult<Expr> {
    let lhs = lvalue(module, target, mode)?;
    let lhs_type = unwrap_typeident(expr_type(&lhs), target.span)?;

    let rhs_expr = typecheck_expr(module, rhs, mode)?;
    let rhs_type = unwrap_typeident(expr_type(&rhs_expr), rhs.span)?;

    let rhs = try_cast(rhs_expr, rhs_type, lhs_type.clone())?;

    Ok(Expr {
        span: target.span,
        kind: ExprKind::Assign {
            lhs: Box::new(lhs),
            rhs: Box::new(rhs),
            ty: lhs_type 
        }
    })
}


fn pred(module: &TypecheckContext, op: BinaryPred, lhs: &AstExpr, rhs: &AstExpr, span: Span, mode: &TypecheckMode) -> TypeResult<Expr> {
    let (lhs, rhs, shared) = basic(module, &BinaryOp::Pred(op), lhs, rhs, span, mode)?;
    Ok(Expr {
        span,
        kind: ExprKind::BinaryPred { op, lhs: Box::new(lhs), rhs: Box::new(rhs), shared }
    })
}


fn arith(module: &TypecheckContext, op: BinaryArith, lhs: &AstExpr, rhs: &AstExpr, span: Span, mode: &TypecheckMode) -> TypeResult<Expr> {
    let (lhs, rhs, ty) = basic(module, &BinaryOp::Arith(op), lhs, rhs, span, mode)?;
    Ok(Expr {
        span,
        kind: ExprKind::BinaryArith { op, lhs: Box::new(lhs), rhs: Box::new(rhs), ty }
    })

}


fn basic(module: &TypecheckContext, op: &BinaryOp, lhs: &AstExpr, rhs: &AstExpr, span: Span, mode: &TypecheckMode) -> TypeResult<(Expr, Expr, TypeIdent)> {
    let lhs_span = lhs.span;
    let rhs_span = rhs.span;

    let lhs = typecheck_expr(module, lhs, mode)?;
    let lhs_type = unwrap_typeident(expr_type(&lhs), lhs_span)?;

    let rhs = typecheck_expr(module, rhs, mode)?;
    let rhs_type = unwrap_typeident(expr_type(&rhs), rhs_span)?;

    let common_type = match TypeIdent::shared_type(&lhs_type, &rhs_type) {
        Ok(ty) => ty,
        Err(_) => return Err(TypecheckError::new(
            TypecheckErrorKind::BinaryTypeMismatch { op: *op, lhs: lhs_type, rhs: rhs_type },
            span,
        ))
    };

    let lhs = try_cast(lhs, lhs_type, common_type.clone())?;
    let rhs = try_cast(rhs, rhs_type, common_type.clone())?;

    Ok((lhs, rhs, common_type))
}

