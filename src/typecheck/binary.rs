use crate::{ast::prelude::*, typecheck::expr::as_identifier, utils::Span};

use super::{
    TypeIdent, TypeResult,
    atomic::Atomic,
    checker::{TypecheckContext, TypecheckMode},
    error::{TypecheckError, TypecheckErrorKind},
    expr::{
        Expr, ExprKind, expr_type, lvalue, try_cast, typecheck_expr, unwrap_ref, unwrap_typeident,
    },
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

fn field_lookup(
    context: &TypecheckContext,
    lhs: &AstExpr,
    rhs: &AstExpr,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let obj_span = lhs.span;
    let obj = typecheck_expr(context, lhs, mode)?;
    let field = as_identifier(rhs, rhs.span)?;
    let obj_ty = unwrap_typeident(expr_type(&obj), obj.span)?;

    macro_rules! unwrap_struct_def {
        ($ty: expr) => {
            match $ty {
                TypeIdent::Ref(ty) => match *ty {
                    TypeIdent::Struct(ty) => context.module.get_struct(&ty),
                    _ => None,
                },
                TypeIdent::Struct(ty) => context.module.get_struct(&ty),
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
                    strct: struct_def.typeident(),
                    field: field.to_string(),
                },
                span,
            ));
        }
    };

    println!("FIELD LOOKUP {field_ty:?}");
    let expr = Expr {
        span,
        kind: ExprKind::FieldLookup {
            obj: Box::new(obj),
            field,
            ty: TypeIdent::Ref(Box::new(field_ty.clone())),
        },
    };
    if mode.lvalue {
        Ok(expr)
    } else {
        let expr = expr.into_deref(field_ty);
        Ok(expr)
    }
}

fn index(
    module: &TypecheckContext,
    lhs: &AstExpr,
    rhs: &AstExpr,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let lhs_span = lhs.span;
    let lhs = typecheck_expr(module, lhs, mode)?;
    let lhs_type = unwrap_typeident(expr_type(&lhs), lhs.span)?;

    let elem_ty = match lhs_type {
        TypeIdent::Array(ty, _len) => ty,
        TypeIdent::Atomic(_) | TypeIdent::Struct(_) => {
            return Err(TypecheckError::new(
                TypecheckErrorKind::InvalidIndex,
                lhs_span,
            ));
        }
        TypeIdent::Ref(ty) => match *ty {
            TypeIdent::Array(ty, _) => ty,
            _ => ty,
        },
    };

    let rhs = typecheck_expr(module, rhs, mode)?;
    let rhs_type = unwrap_typeident(expr_type(&rhs), rhs.span)?;

    let rhs = try_cast(rhs, rhs_type, TypeIdent::Atomic(Atomic::int()))?;

    let expr = Expr {
        span,
        kind: ExprKind::Index {
            expr: Box::new(lhs),
            index: Box::new(rhs),
            ty: TypeIdent::Ref(elem_ty.clone()),
        },
    };
    if mode.lvalue {
        Ok(expr)
    } else {
        let expr = expr.into_deref(*elem_ty);
        Ok(expr)
    }
}

fn assign(
    module: &TypecheckContext,
    target: &AstExpr,
    rhs: &AstExpr,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let lhs = lvalue(module, target, mode)?;
    let lhs_type = unwrap_typeident(expr_type(&lhs), target.span)?;
    let lhs_type = unwrap_ref(lhs_type, target.span)?;

    let rhs_expr = typecheck_expr(module, rhs, mode)?;
    let rhs_type = unwrap_typeident(expr_type(&rhs_expr), rhs.span)?;

    let rhs = try_cast(rhs_expr, rhs_type, lhs_type.clone())?;

    Ok(Expr {
        span: target.span,
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

    let lhs = try_cast(lhs, lhs_type, common_type.clone())?;
    let rhs = try_cast(rhs, rhs_type, common_type.clone())?;

    Ok((lhs, rhs, common_type))
}
