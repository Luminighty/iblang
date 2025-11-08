use crate::{
    ast::prelude::*,
    symbol_resolver::ModuleUID,
    typecheck::{checker::TypecheckContext, expr::as_identifier, expr_object},
    utils::Span,
};

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
    global_context: &mut TypecheckContext,
    context: &TypecheckFuncContext,
    op: BinaryOp,
    lhs: &AstExpr,
    rhs: &AstExpr,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    match op {
        BinaryOp::Index => index(global_context, context, lhs, rhs, span, mode),
        BinaryOp::Assign => assign(global_context, context, lhs, rhs, span, mode),
        BinaryOp::Arith(op) => arith(global_context, context, op, lhs, rhs, span, mode),
        BinaryOp::ArithAssign(op) => {
            assign_arith(global_context, context, op, lhs, rhs, span, mode)
        }
        BinaryOp::Pred(op) => pred(global_context, context, op, lhs, rhs, span, mode),
        BinaryOp::FieldLookup => {
            expr_object::field_lookup(global_context, context, lhs, rhs, span, mode)
        }
        BinaryOp::Path => path(global_context, context, lhs, rhs, span, mode),
    }
}

fn path(
    global_context: &mut TypecheckContext,
    context: &TypecheckFuncContext,
    lhs: &AstExpr,
    rhs: &AstExpr,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let lhs = path_unit(global_context, context, lhs, lhs.span, mode)?;
    let rhs_span = rhs.span;
    let rhs = typecheck_expr(global_context, context, rhs, mode)?;
    if global_context.path_stack.len() != 0 {
        return Err(TypecheckError::new(
            TypecheckErrorKind::InvalidPath,
            context.module_id,
            rhs_span,
        ));
    }
    Ok(rhs)
}

fn path_unit(
    global_context: &mut TypecheckContext,
    context: &TypecheckFuncContext,
    node: &AstExpr,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<()> {
    match &node.kind {
        AstExprKind::Ident(ident) => {
            global_context.path_stack.push(ident.to_string());
            Ok(())
        }
        AstExprKind::Binary { op, lhs, rhs } if *op == BinaryOp::Path => {
            path_unit(global_context, context, &lhs, lhs.span, mode)?;
            if let AstExprKind::Ident(path_element) = &rhs.kind {
                global_context.path_stack.push(path_element.to_string());
                Ok(())
            } else {
                Err(TypecheckError::new(
                    TypecheckErrorKind::InvalidPathElement,
                    context.module_id,
                    rhs.span,
                ))
            }
        }
        _ => Err(TypecheckError::new(
            TypecheckErrorKind::InvalidPathElement,
            context.module_id,
            span,
        )),
    }
}

fn assign_arith(
    global_context: &mut TypecheckContext,
    context: &TypecheckFuncContext,
    arith: BinaryArith,
    target: &AstExpr,
    rhs: &AstExpr,
    span: Span,
    _mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let lhs_span = target.span;
    let rhs_span = rhs.span;

    let lhs = typecheck_expr(global_context, context, target, &TypecheckMode::lvalue())?;
    let lhs_type = unwrap_typeident(context.module_id, expr_type(&lhs), target.span)?;

    assert_assign(&context.module_id, &lhs, &lhs_type, span)?;

    let rhs = typecheck_expr(global_context, context, rhs, &TypecheckMode::rvalue())?;
    let rhs_type = unwrap_typeident(context.module_id, expr_type(&rhs), rhs_span)?;
    let mut rhs = try_cast(context, rhs, rhs_type, lhs_type.clone())?;
    rhs.value_kind = ValueKind::RValue;

    Ok(Expr {
        span: target.span,
        value_kind: ValueKind::RValue,
        kind: ExprKind::ArithAssign {
            lhs: Box::new(lhs),
            rhs: Box::new(rhs),
            op: arith,
            ty: lhs_type,
        },
    })
}

fn assert_assign(
    module_id: &ModuleUID,
    lhs: &Expr,
    lhs_ty: &TypeIdent,
    span: Span,
) -> TypeResult<()> {
    // NOTE: value = other_array is not valid in C, but consider it for rewrite
    match lhs_ty {
        TypeIdent::Array(_, _) => {
            return Err(TypecheckError::new(
                TypecheckErrorKind::AssignmentToArray,
                *module_id,
                span,
            ));
        }
        _ => {}
    }

    // NOTE: array = [1, 2, 3] is not valid in C, but consider it for rewrite
    match lhs.kind {
        ExprKind::Array { .. } => {
            return Err(TypecheckError::new(
                TypecheckErrorKind::AssignmentWithArrayInitializer,
                *module_id,
                span,
            ));
        }
        _ => {}
    };
    Ok(())
}

fn assign(
    global_context: &mut TypecheckContext,
    context: &TypecheckFuncContext,
    target: &AstExpr,
    rhs: &AstExpr,
    span: Span,
    _mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let lhs = typecheck_expr(global_context, context, target, &TypecheckMode::lvalue())?;
    let lhs_type = unwrap_typeident(context.module_id, expr_type(&lhs), target.span)?;

    assert_assign(&context.module_id, &lhs, &lhs_type, span)?;

    let rhs_expr = typecheck_expr(global_context, context, rhs, &TypecheckMode::rvalue())?;
    let rhs_type = unwrap_typeident(context.module_id, expr_type(&rhs_expr), rhs.span)?;
    let mut rhs = try_cast(context, rhs_expr, rhs_type, lhs_type.clone())?;
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
    global_context: &mut TypecheckContext,
    context: &TypecheckFuncContext,
    op: BinaryPred,
    lhs: &AstExpr,
    rhs: &AstExpr,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let (lhs, rhs, shared) = basic(
        global_context,
        context,
        &BinaryOp::Pred(op),
        lhs,
        rhs,
        span,
        mode,
    )?;
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
    global_context: &mut TypecheckContext,
    context: &TypecheckFuncContext,
    op: BinaryArith,
    lhs: &AstExpr,
    rhs: &AstExpr,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let (lhs, rhs, ty) = basic(
        global_context,
        context,
        &BinaryOp::Arith(op),
        lhs,
        rhs,
        span,
        mode,
    )?;
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
    global_context: &mut TypecheckContext,
    context: &TypecheckFuncContext,
    op: &BinaryOp,
    lhs: &AstExpr,
    rhs: &AstExpr,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<(Expr, Expr, TypeIdent)> {
    let lhs_span = lhs.span;
    let rhs_span = rhs.span;

    let lhs = typecheck_expr(global_context, context, lhs, mode)?;
    let lhs_type = unwrap_typeident(context.module_id, expr_type(&lhs), lhs_span)?;

    let rhs = typecheck_expr(global_context, context, rhs, mode)?;
    let rhs_type = unwrap_typeident(context.module_id, expr_type(&rhs), rhs_span)?;

    let common_type = match TypeIdent::shared_type(&lhs_type, &rhs_type) {
        Ok(ty) => ty,
        Err(_) => {
            return Err(TypecheckError::new(
                TypecheckErrorKind::BinaryTypeMismatch {
                    op: *op,
                    lhs: lhs_type,
                    rhs: rhs_type,
                },
                context.module_id,
                span,
            ));
        }
    };

    let mut lhs = try_cast(context, lhs, lhs_type, common_type.clone())?;
    let mut rhs = try_cast(context, rhs, rhs_type, common_type.clone())?;
    lhs.value_kind = ValueKind::RValue;
    rhs.value_kind = ValueKind::RValue;

    Ok((lhs, rhs, common_type))
}
