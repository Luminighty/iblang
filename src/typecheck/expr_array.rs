use std::collections::HashMap;

use super::{
    CastMethod, FlowType, TypeIdent, TypeResult,
    binary::typecheck_binary,
    checker::{TypecheckContext, TypecheckMode},
    error::{TypecheckError, TypecheckErrorKind},
    expr::Expr,
    unary::typecheck_unary,
};
use crate::{ast::prelude::*, utils::Span};

pub fn array(
    context: &TypecheckContext,
    values: &Vec<AstExpr>,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    todo!("Arrays not supported :(")
    // lvalue_guard(mode, span)?;
    // let mut exprs = Vec::with_capacity(values.len());
    // for value in values {
    //     let expr = typecheck_expr(context, value, mode)?;
    //     exprs.push(expr);
    // }
    // macro_rules! unwrap_or_return_typeident {
    //     ($ty: expr) => {{
    //         let ty = expr_type($ty);
    //         match unwrap_typeident(ty.clone(), $ty.span) {
    //             Ok(ty) => ty,
    //             _ => {
    //                 return Err(TypecheckError::new(
    //                     TypecheckErrorKind::GotArrayElementWithoutValue { got: ty },
    //                     span,
    //                 ));
    //             }
    //         }
    //     }};
    // }
    //
    // let target_type = if let Some(target_type) = &context.target_type {
    //     match target_type {
    //         TypeIdent::Array(array_type, _) => *array_type.clone(),
    //         _ => {
    //             return Err(TypecheckError::new(
    //                 TypecheckErrorKind::TargetTypeWasNotArray,
    //                 span,
    //             ));
    //         }
    //     }
    // } else {
    //     let mut shared_type = match exprs.get(0) {
    //         Some(expr) => unwrap_or_return_typeident!(expr),
    //         _ => {
    //             return Err(TypecheckError::new(
    //                 TypecheckErrorKind::EmptyArrayWithoutType,
    //                 span,
    //             ));
    //         }
    //     };
    //     for expr in &exprs {
    //         let ty = unwrap_or_return_typeident!(expr);
    //         shared_type = match TypeIdent::shared_type(&shared_type, &ty) {
    //             Ok(ty) => ty,
    //             _ => {
    //                 return Err(TypecheckError::new(
    //                     TypecheckErrorKind::InvalidArrayElementType {
    //                         expected: shared_type,
    //                         got: ty,
    //                     },
    //                     expr.span,
    //                 ));
    //             }
    //         }
    //     }
    //     shared_type.clone()
    // };
    //
    // let mut valid_expr = Vec::with_capacity(exprs.len());
    // for expr in exprs.into_iter() {
    //     let span = expr.span;
    //     let ty = unwrap_typeident(expr_type(&expr), span)?;
    //     valid_expr.push(try_cast(expr, ty, target_type.clone())?);
    // }
    //
    // let len = valid_expr.len();
    // Ok(Expr {
    //     span,
    //     kind: ExprKind::Array {
    //         values: valid_expr,
    //         ty: TypeIdent::Array(Box::new(target_type.clone()), len).into_ref(),
    //     },
    // })
}

pub fn index(
    module: &TypecheckContext,
    lhs: &AstExpr,
    rhs: &AstExpr,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    todo!("indexing not supported")
    // let lhs_span = lhs.span;
    // let lhs = typecheck_expr(module, lhs, mode)?;
    // let lhs_type = unwrap_typeident(expr_type(&lhs), lhs.span)?;
    // let lhs = lhs.auto_deref(lhs_type);
    // let lhs_type = unwrap_typeident(expr_type(&lhs), lhs.span)?;
    //
    // let elem_ty = match lhs_type {
    //     TypeIdent::Array(ty, _len) => ty,
    //     TypeIdent::Atomic(_) | TypeIdent::Struct(_) => {
    //         return Err(TypecheckError::new(
    //             TypecheckErrorKind::InvalidIndex,
    //             lhs_span,
    //         ));
    //     }
    //     TypeIdent::Ref(ty) => match *ty {
    //         TypeIdent::Array(ty, _) => ty,
    //         _ => ty,
    //     },
    // };
    //
    // let rhs = typecheck_expr(module, rhs, mode)?;
    // let rhs_type = unwrap_typeident(expr_type(&rhs), rhs.span)?;
    // let rhs = rhs.auto_deref(rhs_type);
    // let rhs_type = unwrap_typeident(expr_type(&rhs), rhs.span)?;
    //
    // let rhs = try_cast(rhs, rhs_type, TypeIdent::Atomic(Atomic::int()))?;
    //
    // let expr = Expr {
    //     span,
    //     kind: ExprKind::Index {
    //         expr: Box::new(lhs),
    //         index: Box::new(rhs),
    //         ty: TypeIdent::Ref(elem_ty.clone()),
    //     },
    // };
    // Ok(expr)
}
