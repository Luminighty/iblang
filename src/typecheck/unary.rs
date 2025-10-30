use crate::{ast::prelude::*, typecheck::checker::TypecheckContext, utils::Span};

use super::{
    CastMethod, TypeIdent, TypeResult,
    atomic::Atomic,
    checker::{TypecheckFuncContext, TypecheckMode},
    error::*,
    expr::*,
};

pub fn typecheck_unary(
    global_context: &mut TypecheckContext,
    context: &TypecheckFuncContext,
    op: UnaryOp,
    expr: &AstExpr,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    match op {
        UnaryOp::REF => into_ref(global_context, context, expr, span, mode),
        UnaryOp::DEREF => into_deref(global_context, context, expr, span, mode),
        UnaryOp::GROUP => typecheck_expr(global_context, context, expr, mode),
        UnaryOp::Arith(op) => {
            let expr = typecheck_expr(global_context, context, expr, mode)?;
            let expr_ty = unwrap_typeident(context.module_id, expr_type(&expr), span)?;
            match expr_ty {
                TypeIdent::Atomic(atom) => atomic(context, atom, op, expr, expr_ty, span),
                _ => {
                    return Err(TypecheckError::new(
                        TypecheckErrorKind::UnaryTypeMismatch { op, value: expr_ty },
                        context.module_id,
                        span,
                    ));
                }
            }
        }
    }
}

fn into_ref(
    global_context: &mut TypecheckContext,
    context: &TypecheckFuncContext,
    expr: &AstExpr,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let expr = typecheck_expr(global_context, context, expr, &TypecheckMode::lvalue())?;
    let expr_ty = unwrap_typeident(context.module_id, expr_type(&expr), span)?;
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
    global_context: &mut TypecheckContext,
    context: &TypecheckFuncContext,
    expr: &AstExpr,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let expr = typecheck_expr(global_context, context, expr, mode)?;
    let expr_ty = unwrap_typeident(context.module_id, expr_type(&expr), span)?;
    match (mode.value_kind, expr_ty) {
        // (ValueKind::LValue, TypeIdent::Ref(inner)) => Ok(Expr {
        //     span,
        //     value_kind: ValueKind::LValue,
        //     kind: ExprKind::Cast {
        //         expr: Box::new(expr),
        //         target: *inner,
        //         method: CastMethod::Keep,
        //     },
        // }),
        (ValueKind::RValue, TypeIdent::Ref(r)) if r.is_struct() => Ok(Expr {
            span,
            value_kind: mode.value_kind,
            kind: ExprKind::StructCopy {
                expr: Box::new(expr),
                ty: *r,
            },
        }),
        (_, TypeIdent::Ref(r)) => Ok(Expr {
            span,
            value_kind: mode.value_kind,
            kind: ExprKind::Deref {
                expr: Box::new(expr),
                ty: *r,
            },
        }),
        _ => Err(TypecheckError::new(
            TypecheckErrorKind::DereffedAtomic,
            context.module_id,
            span,
        )),
    }
}

fn atomic(
    context: &TypecheckFuncContext,
    atom: Atomic,
    op: UnaryArith,
    expr: Expr,
    expr_type: TypeIdent,
    span: Span,
) -> TypeResult<Expr> {
    match atom.unary_result(op) {
        Ok(new_type) => {
            let expr = try_cast(
                context,
                expr,
                expr_type,
                TypeIdent::Atomic(new_type.clone()),
            )?;
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
                context.module_id,
                span,
            ));
        }
    }
}
