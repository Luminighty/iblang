use super::{
    TypeIdent,
    atomic::{Atomic, Numeric},
};
use crate::{
    ast::prelude::*,
    symbol_resolver::ModuleUID,
    typecheck::{
        CastMethod, TypeResult, TypecheckError,
        checker::TypecheckFuncContext,
        error::TypecheckErrorKind,
        expr::{Expr, ExprKind},
    },
    utils::Span,
};

#[derive(Debug)]
pub enum ConstExpr {
    Literal(Literal),
    Array(Vec<ConstExpr>),
    Struct(Vec<(String, ConstExpr)>, TypeIdent),
    Union(String, Box<ConstExpr>, TypeIdent),
}

pub type EvalResult = TypeResult<ConstExpr>;

#[derive(Debug, Clone)]
pub enum ConstEvalError {
    CallNotSupported,
    VariableNotSupported,
    OperatorNotSupported,
    CastNotSupported,
}

impl ConstEvalError {
    fn err(self, module: ModuleUID, span: &Span) -> TypecheckError {
        TypecheckError::new(TypecheckErrorKind::ConstEvalError(self), module, *span)
    }
}

pub fn const_eval_expr(context: &TypecheckFuncContext, e: &Expr) -> EvalResult {
    match &e.kind {
        ExprKind::Literal(literal, _) => Ok(ConstExpr::Literal(*literal)),
        ExprKind::Global(ident, _) => todo!(),
        ExprKind::BinaryPred {
            op,
            lhs,
            rhs,
            shared,
        } => eval_binarypred(context, *op, lhs, rhs, shared, &e.span),
        ExprKind::BinaryArith { op, lhs, rhs, ty } => {
            eval_binaryarith(context, *op, lhs, rhs, ty, &e.span)
        }
        ExprKind::Unary { op, expr, ty } => eval_unary(context, *op, expr, ty, &e.span),
        ExprKind::Call { callee, args, ty } => {
            Err(ConstEvalError::CallNotSupported.err(context.module_id, &e.span))
        }
        ExprKind::Array { values, ty } => eval_array(context, values, ty, &e.span),
        ExprKind::StructInit { values, ty } => eval_struct(context, values, ty, &e.span),
        ExprKind::UnionInit { value, field, ty } => eval_union(context, field, value, ty, &e.span),
        ExprKind::Variable(_, type_ident) => {
            Err(ConstEvalError::VariableNotSupported.err(context.module_id, &e.span))
        }
        ExprKind::Assign { lhs, rhs, ty } => todo!(),
        ExprKind::Cast {
            expr,
            target,
            method,
        } => eval_cast(context, expr, target, method, &e.span),
        ExprKind::Index { index, expr, ty } => todo!(),
        ExprKind::UnionFieldLookup {
            obj,
            field,
            union_ty,
            ty,
        } => todo!(),
        ExprKind::StructFieldLookup {
            obj,
            field,
            struct_ty,
            ty,
        } => todo!(),
        ExprKind::ObjectCopy { expr, ty } => todo!(),
        ExprKind::Deref { expr, ty } => todo!(),
        ExprKind::Ref { expr, ty } => todo!(),
        ExprKind::Load { expr, ty } => todo!(),
    }
}

fn eval_binaryarith(
    context: &TypecheckFuncContext,
    op: BinaryArith,
    lhs: &Expr,
    rhs: &Expr,
    shared: &TypeIdent,
    span: &Span,
) -> EvalResult {
    let lhs = const_eval_expr(context, lhs)?;
    let rhs = const_eval_expr(context, rhs)?;

    macro_rules! arith {
        ($lhs: expr, $rhs: expr, $op: tt) => {
            match ($lhs, $rhs) {
                (ConstExpr::Literal(lhs), ConstExpr::Literal(rhs)) => match (lhs, rhs) {
                    (Literal::Number(lhs), Literal::Number(rhs)) => Literal::Number(lhs $op rhs),
                    (Literal::Float(lhs), Literal::Float(rhs)) => Literal::Float(lhs $op rhs),
                    (Literal::Char(lhs), Literal::Char(rhs)) => Literal::Char((lhs as u8 $op rhs as u8) as char),
                    (_, _) => return Err(ConstEvalError::OperatorNotSupported.err(context.module_id, span)),
                },
                _ => return Err(ConstEvalError::OperatorNotSupported.err(context.module_id, span)),
            }
        };
    }

    let res = match op {
        BinaryArith::Add => arith!(lhs, rhs, +),
        BinaryArith::Sub => arith!(lhs, rhs, -),
        BinaryArith::Mul => arith!(lhs, rhs, *),
        BinaryArith::Div => arith!(lhs, rhs, /),
        BinaryArith::Rem => arith!(lhs, rhs, %),
    };
    Ok(res.into())
}

fn eval_binarypred(
    context: &TypecheckFuncContext,
    op: BinaryPred,
    lhs: &Expr,
    rhs: &Expr,
    shared: &TypeIdent,
    span: &Span,
) -> EvalResult {
    let lhs = const_eval_expr(context, lhs)?;
    let rhs = const_eval_expr(context, rhs)?;

    macro_rules! pred {
        ($lhs: expr, $rhs: expr, $op: tt) => {
            match ($lhs, $rhs) {
                (ConstExpr::Literal(lhs), ConstExpr::Literal(rhs)) => match (lhs, rhs) {
                    (Literal::Number(lhs), Literal::Number(rhs)) => lhs $op rhs,
                    (Literal::Bool(lhs), Literal::Bool(rhs)) => lhs $op rhs,
                    (Literal::Float(lhs), Literal::Float(rhs)) => lhs $op rhs,
                    (Literal::Char(lhs), Literal::Char(rhs)) => lhs $op rhs,
                    (_, _) => return Err(ConstEvalError::OperatorNotSupported.err(context.module_id, span)),
                }
                (_, _) => return Err(ConstEvalError::OperatorNotSupported.err(context.module_id, span)),
            }
        };
    }

    let res = match op {
        BinaryPred::EQ => pred!(lhs, rhs, ==),
        BinaryPred::NE => pred!(lhs, rhs, !=),
        BinaryPred::GT => pred!(lhs, rhs, >),
        BinaryPred::GE => pred!(lhs, rhs, >=),
        BinaryPred::LT => pred!(lhs, rhs, <),
        BinaryPred::LE => pred!(lhs, rhs, <=),
        BinaryPred::And => match (lhs, rhs) {
            (ConstExpr::Literal(lhs), ConstExpr::Literal(rhs)) => match (lhs, rhs) {
                (Literal::Bool(lhs), Literal::Bool(rhs)) => lhs && rhs,
                (_, _) => {
                    return Err(ConstEvalError::OperatorNotSupported.err(context.module_id, span));
                }
            },
            (_, _) => return Err(ConstEvalError::OperatorNotSupported.err(context.module_id, span)),
        },
        BinaryPred::Or => match (lhs, rhs) {
            (ConstExpr::Literal(lhs), ConstExpr::Literal(rhs)) => match (lhs, rhs) {
                (Literal::Bool(lhs), Literal::Bool(rhs)) => lhs || rhs,
                (_, _) => {
                    return Err(ConstEvalError::OperatorNotSupported.err(context.module_id, span));
                }
            },
            (_, _) => return Err(ConstEvalError::OperatorNotSupported.err(context.module_id, span)),
        },
    };
    Ok(Literal::Bool(res).into())
}

fn eval_unary(
    context: &TypecheckFuncContext,
    op: UnaryArith,
    expr: &Expr,
    ty: &TypeIdent,
    span: &Span,
) -> EvalResult {
    let val = const_eval_expr(context, expr)?;
    Ok(match val {
        ConstExpr::Literal(val) => match op {
            UnaryArith::POS => val,
            UnaryArith::NOT => match val {
                Literal::Bool(b) => Literal::Bool(!b),
                _ => return Err(ConstEvalError::OperatorNotSupported.err(context.module_id, span)),
            },
            UnaryArith::NEG => match val {
                Literal::Number(n) => Literal::Number(-n),
                Literal::Char(n) => Literal::Number(n as i64),
                Literal::Float(n) => Literal::Float(-n),
                _ => return Err(ConstEvalError::OperatorNotSupported.err(context.module_id, span)),
            },
        }
        .into(),
        ConstExpr::Array(_) => todo!(),
        ConstExpr::Struct(_, _) => todo!(),
        ConstExpr::Union(_, _, _) => todo!(),
    })
}
fn eval_cast(
    context: &TypecheckFuncContext,
    expr: &Expr,
    target: &TypeIdent,
    method: &CastMethod,
    span: &Span,
) -> EvalResult {
    match method {
        CastMethod::Keep => const_eval_expr(context, expr),
        CastMethod::ArrayDecay => const_eval_expr(context, expr),
        CastMethod::Truncate
        | CastMethod::Extend
        | CastMethod::FloatToInt
        | CastMethod::IntToFloat => {
            let expr_span = expr.span;
            let value = const_eval_expr(context, expr)?;
            let value = match (value, target) {
                (ConstExpr::Literal(value), TypeIdent::Atomic(atomic)) => match atomic {
                    Atomic::Number(Numeric::Int) => value.to_int().unwrap(),
                    Atomic::Number(Numeric::Bool) => value.to_bool().unwrap(),
                    Atomic::Number(Numeric::Char) => value.to_char().unwrap(),
                    Atomic::Float => value.to_float().unwrap(),
                },
                _ => return Err(ConstEvalError::CastNotSupported.err(context.module_id, span)),
            };
            Ok(value.into())
        }
        CastMethod::Deref => todo!(),
    }
}

fn eval_array(
    context: &TypecheckFuncContext,
    values: &Vec<Expr>,
    ty: &TypeIdent,
    span: &Span,
) -> EvalResult {
    let mut const_exprs = Vec::with_capacity(values.len());
    for value in values {
        let const_expr = const_eval_expr(context, value)?;
        const_exprs.push(const_expr)
    }
    Ok(ConstExpr::Array(const_exprs))
}

fn eval_union(
    context: &TypecheckFuncContext,
    field: &String,
    value: &Expr,
    ty: &TypeIdent,
    span: &Span,
) -> EvalResult {
    let mut const_expr = const_eval_expr(context, value)?;
    Ok(ConstExpr::Union(
        field.to_owned(),
        Box::new(const_expr),
        ty.clone(),
    ))
}

fn eval_struct(
    context: &TypecheckFuncContext,
    values: &Vec<(String, Expr)>,
    ty: &TypeIdent,
    span: &Span,
) -> EvalResult {
    let mut const_exprs = Vec::with_capacity(values.len());
    for (field, value) in values {
        let const_expr = const_eval_expr(context, value)?;
        const_exprs.push((field.clone(), const_expr))
    }
    Ok(ConstExpr::Struct(const_exprs, ty.clone()))
}

impl From<Literal> for ConstExpr {
    fn from(l: Literal) -> Self {
        Self::Literal(l)
    }
}
