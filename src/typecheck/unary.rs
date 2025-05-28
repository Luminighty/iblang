use crate::{ast::{AstExpr, UnaryOp}, utils::Span};

use super::{atomic::Atomic, checker::TypecheckContext, error::{TypecheckError, TypecheckErrorKind}, expr::{self, expr_type, try_cast, typecheck_expr, unwrap_typeident, Expr}, TypeIdent, TypeResult};


pub fn typecheck_unary(module: &TypecheckContext, op: UnaryOp, expr: &AstExpr, span: Span) -> TypeResult<Expr> {
    let expr = typecheck_expr(module, expr)?;
    let expr_type = unwrap_typeident(expr_type(&expr), span)?;

    match expr_type {
        TypeIdent::Atomic(atom) => atomic(atom, op, expr, expr_type, span),
        _ => return Err(TypecheckError::new(
            TypecheckErrorKind::UnaryTypeMismatch { op, value: expr_type },
            span,
        ))
    }
}


fn atomic(atom: Atomic, op: UnaryOp, expr: Expr, expr_type: TypeIdent, span: Span) -> TypeResult<Expr> {
    match atom.unary_result(op) {
        Ok(new_type) => {
            let expr = try_cast(expr, expr_type, TypeIdent::Atomic(new_type))?;
            Ok(Expr {
                span,
                kind: expr::ExprKind::Unary { 
                    op,
                    expr: Box::new(expr), 
                    ty: new_type.into()
                }
            })
        },
        _ => return Err(TypecheckError::new(
            TypecheckErrorKind::UnaryTypeMismatch { op, value: expr_type },
            span,
        ))
    }
}
