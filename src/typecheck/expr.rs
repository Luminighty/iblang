use crate::{ast::prelude::*, utils::Span};
use super::{binary::typecheck_binary, checker::TypecheckContext, error::{TypecheckError, TypecheckErrorKind}, unary::typecheck_unary, CastMethod, FlowType, TypeIdent, TypeResult};

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


pub fn typecheck_expr(context: &TypecheckContext, expr: &AstExpr) -> TypeResult<Expr> {
    match &expr.kind {
        AstExprKind::Literal(l) => literal(l, expr.span),
        AstExprKind::Ident(i) => ident(context, i.to_string(), expr.span),
        AstExprKind::Binary { op, lhs, rhs } => typecheck_binary(context, *op, &lhs, &rhs, expr.span),
        AstExprKind::Unary { op, expr } => typecheck_unary(context, *op, expr, expr.span),
        AstExprKind::Call { callee, args } => call(context, callee, args, expr.span),
    }
}


fn literal(l: &Literal, span: Span) -> TypeResult<Expr> {
    Ok(Expr {
        span,
        kind: ExprKind::Literal(l.clone(), l.into()),
    })
}


pub fn as_identifier(expr: &AstExpr, span: Span) -> TypeResult<Identifier> {
    match &expr.kind {
        AstExprKind::Ident(i) => Ok(i.to_string()),
        _ => Err(TypecheckError::new(TypecheckErrorKind::IdentifierExpected, span))
    }
}


pub fn ident(module: &TypecheckContext, identifier: Identifier, span: Span) -> TypeResult<Expr> {
    if let Some(ty) = module.bindings.get(&identifier) {
        Ok(Expr {
            span,
            kind: ExprKind::Ident(identifier, ty.clone())
        })
    } else {
        Err(TypecheckError::new(TypecheckErrorKind::UndeclaredVariable(identifier), span))
    }
}


fn call(module: &TypecheckContext, callee: &AstExpr, args: &Vec<AstExpr>, span: Span) -> TypeResult<Expr> {
    let callee = as_identifier(callee, span)?;
    let prototype = match module.prototypes.get(&callee) {
        Some(p) => p,
        None => return Err(TypecheckError::new(
            TypecheckErrorKind::UndefinedFunction(callee), 
            span)
        )
    };

    let mut checked_args = Vec::new();
    for (i, arg) in args.iter().enumerate() {
        let arg = typecheck_expr(module, arg)?;
        let arg_type = unwrap_typeident(expr_type(&arg), arg.span)?;

        let arg = try_cast(arg, arg_type, prototype.args[i].1.clone())?;
        checked_args.push((arg, prototype.args[i].1.clone()))
    }
    // TODO: Check argument amount, and collect all the invalid args

    Ok(Expr {
        span,
        kind: ExprKind::Call {
            callee,
            args: checked_args,
            ty: prototype.return_type.clone()
        }
    })
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

