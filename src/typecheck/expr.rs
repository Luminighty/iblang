use crate::{ast::{AstExpr, AstExprKind, AstStatement, AstStatementKind, BinaryArith, BinaryOp, BinaryPred, Identifier, Literal, TypecheckContext, UnaryOp}, utils::Span};

use super::{atomic::Atomic, binary::typecheck_binary, error::{TypecheckError, TypecheckErrorKind}, CastMethod, FlowType, TypeIdent, TypeResult};

#[derive(Debug)]
pub struct Expr {
    pub span: Span,
    pub kind: ExprKind,
}

#[derive(Debug)]
pub enum ExprKind {
    Literal(Literal, TypeIdent),
    Ident(Identifier, TypeIdent),
    Assign {
        lhs: Box<Expr>,
        rhs: Box<Expr>,
        ty: TypeIdent,
    },
    BinaryPred {
        op: BinaryPred,
        lhs: Box<Expr>,
        rhs: Box<Expr>,
        shared: TypeIdent,
    },
    BinaryArith {
        op: BinaryArith,
        lhs: Box<Expr>,
        rhs: Box<Expr>,
        ty: TypeIdent,
    },
    Unary {
        op: UnaryOp,
        expr: Box<Expr>,
        ty: TypeIdent,
    },
    Call {
        callee: Identifier,
        args: Vec<(Expr, TypeIdent)>,
        ty: FlowType,
    },
    Cast {
        expr: Box<Expr>,
        target: TypeIdent,
        method: CastMethod,
    }
}

pub fn expr_type(expr: &Expr) -> FlowType {
    match &expr.kind {
        ExprKind::Literal(_, ty) => ty.into(),
        ExprKind::Ident(_, ty) => ty.into(),
        ExprKind::BinaryArith { ty, .. } => ty.into(),
        ExprKind::BinaryPred { shared, .. } => shared.into(),
        ExprKind::Unary { ty, .. } => ty.into(),
        ExprKind::Call { ty, .. } => ty.clone(),
        ExprKind::Cast { target, .. } => target.into(),
        ExprKind::Assign { ty, .. } => ty.into(),
    }
}

pub fn typecheck_expr(module: &TypecheckContext, expr: &AstExpr) -> TypeResult<Expr> {
    match expr.kind {
        AstExprKind::Literal(l) => literal(l, expr.span),
        AstExprKind::Ident(i) => ident(module, i, expr.span),
        AstExprKind::Binary { op, lhs, rhs } => typecheck_binary(module, op, &lhs, &rhs, expr.span),
        AstExprKind::Unary { op, expr } => todo!(),
        AstExprKind::Call { callee, args } => todo!(),
    }
}

fn literal(l: Literal, span: Span) -> TypeResult<Expr> {
    let ty = match l {
        Literal::Number(_) => Atomic::Number,
        Literal::Bool(_) => Atomic::Bool,
        Literal::Char(_) => Atomic::Char,
        Literal::Float(_) => Atomic::Float,
    };
    Ok(Expr {
        span,
        kind: ExprKind::Literal(l, ty.into()),
    })
}

pub fn as_identifier(expr: AstExpr, span: Span) -> TypeResult<Identifier> {
    match expr.kind {
        AstExprKind::Ident(i) => Ok(i),
        _ => Err(TypecheckError::new(TypecheckErrorKind::IdentifierExpected, span))
    }
}

pub fn ident(module: &TypecheckContext, identifier: Identifier, span: Span) -> TypeResult<Expr> {
    if let Some(ty) = module.bindings.get(identifier) {
        Ok(ty)
    } else {
        Err(TypecheckError::new(TypecheckErrorKind::UndeclaredVariable(identifier), span))
    }
}

fn unary(module: &TypecheckContext, identifier: Identifier, span: Span) -> TypeResult<Expr> {

}

fn call(module: &TypecheckContext, identifier: Identifier, span: Span) -> TypeResult<Expr> {

}

pub fn lvalue(module: &TypecheckContext, e: &AstExpr) -> TypeResult<Expr> {
    // TODO: Restrict typechecker to only allow LVALUEs
    typecheck_expr(module, e)
}

pub fn try_cast(e: Expr, from: TypeIdent, into: TypeIdent) -> TypeResult<Expr> {
    match TypeIdent::try_cast_into(&from, &into) {
        Ok(CastMethod::Keep) => Ok(e),
        Ok(x) => Ok(Expr {
            span: e.span,
            kind: ExprKind::Cast { expr: Box::new(e), target: into, method: x }
        }),
        Err(_) => Err(TypecheckError::new(TypecheckErrorKind::InvalidCast { from, into }, e.span))
    }
}

pub fn unwrap_typeident(flow: FlowType, span: Span) -> TypeResult<TypeIdent> {
    match flow {
        FlowType::Some(ty) => Ok(ty),
        _ => Err(TypecheckError::new(TypecheckErrorKind::ValueExpected, span))
    }
}
