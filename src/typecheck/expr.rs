use crate::{ast::prelude::*, utils::Span};
use super::{binary::typecheck_binary, checker::{TypecheckContext, TypecheckMode}, error::{TypecheckError, TypecheckErrorKind}, unary::typecheck_unary, CastMethod, FlowType, TypeIdent, TypeResult};

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
        op: UnaryArith,
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
    },
    Array {
        values: Vec<Expr>,
        ty: TypeIdent,
    },
    Index {
        index: Box<Expr>,
        expr: Box<Expr>,
        ty: TypeIdent,
    },
    Deref {
        expr: Box<Expr>,
        ty: TypeIdent,
    },
    Ref {
        expr: Box<Expr>,
        ty: TypeIdent,
    }
}

pub fn typecheck_expr(context: &TypecheckContext, expr: &AstExpr, mode: &TypecheckMode) -> TypeResult<Expr> {
    match &expr.kind {
        AstExprKind::Literal(l) => literal(l, expr.span),
        AstExprKind::Ident(i) => ident(context, i.to_string(), expr.span),
        AstExprKind::Binary { op, lhs, rhs } => typecheck_binary(context, *op, &lhs, &rhs, expr.span, mode),
        AstExprKind::Unary { op, expr } => typecheck_unary(context, *op, expr, expr.span, mode),
        AstExprKind::Call { callee, args } => call(context, callee, args, expr.span, mode),
        AstExprKind::Array { values } => array(context, values, expr.span, mode),
    }
}

fn array(context: &TypecheckContext, values: &Vec<AstExpr>, span: Span, mode: &TypecheckMode) -> TypeResult<Expr> {
    let mut exprs = Vec::with_capacity(values.len());
    for value in values {
        let expr = typecheck_expr(context, value, mode)?;
        exprs.push(expr);
    }
    macro_rules! unwrap_or_return_typeident {
        ($ty: expr) => {{
            let ty = expr_type($ty);
            match unwrap_typeident(ty.clone(), $ty.span) {
                Ok(ty) => ty,
                _ => return Err(
                    TypecheckError::new(
                        TypecheckErrorKind::GotArrayElementWithoutValue {got: ty},
                        span
                    )
                )
            }}
        };
    }

    let target_type = if let Some(target_type) = &context.target_type {
        match target_type {
            TypeIdent::Array(array_type, _) => *array_type.clone(),
            _ => return Err(
                TypecheckError::new(TypecheckErrorKind::TargetTypeWasNotArray, span),
            )
        }
    } else {
        let mut shared_type = match exprs.get(0) {
            Some(expr) => unwrap_or_return_typeident!(expr),
            _ => return Err(
                TypecheckError::new(TypecheckErrorKind::EmptyArrayWithoutType, span),
            )
        };
        for expr in &exprs {
            let ty = unwrap_or_return_typeident!(expr);
            shared_type = match TypeIdent::shared_type(&shared_type, &ty) {
                Ok(ty) => ty,
                _ => return Err(
                    TypecheckError::new(
                        TypecheckErrorKind::InvalidArrayElementType { expected: shared_type, got: ty },
                        expr.span
                    )
                )
            }
        }
        shared_type.clone()
    };

    let mut valid_expr = Vec::with_capacity(exprs.len());
    for expr in exprs.into_iter() {
        let span = expr.span;
        let ty = unwrap_typeident(expr_type(&expr), span)?;
        valid_expr.push(try_cast(expr, ty,target_type.clone())?);
    }

    let len = valid_expr.len();
    Ok(Expr {
        span,
        kind: ExprKind::Array { 
            values: valid_expr,
            ty: TypeIdent::Array(Box::new(target_type.clone()), len)
        }
    })
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


fn call(module: &TypecheckContext, callee: &AstExpr, args: &Vec<AstExpr>, span: Span, mode: &TypecheckMode) -> TypeResult<Expr> {
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
        let arg = typecheck_expr(module, arg, mode)?;
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


pub fn lvalue(module: &TypecheckContext, e: &AstExpr, mode: &TypecheckMode) -> TypeResult<Expr> {
    typecheck_expr(module, e, &mode.with_lvalue())
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
        ExprKind::Array { ty, .. } => ty.into(),
        ExprKind::Index { ty, .. } => ty.into(),
        ExprKind::Deref { ty, .. } => ty.into(),
        ExprKind::Ref { ty, .. } => ty.into(),
    }
}


pub fn unwrap_typeident(flow: FlowType, span: Span) -> TypeResult<TypeIdent> {
    match flow {
        FlowType::Some(ty) => Ok(ty),
        _ => Err(TypecheckError::new(TypecheckErrorKind::ValueExpected, span))
    }
}

