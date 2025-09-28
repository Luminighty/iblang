use super::{
    TypeIdent,
    atomic::{Atomic, Numeric},
};
use crate::{
    ast::prelude::*,
    typecheck::{
        TypeResult,
        checker::TypecheckContext,
        expr::{Expr, ExprKind},
    },
};

#[derive(Debug)]
pub enum ConstExpr {
    Literal(Literal),
}

pub type EvalResult = TypeResult<ConstExpr>;

#[allow(unused)]
pub enum ConstEvalError {}

pub fn const_eval_expr(context: &TypecheckContext, e: &Expr) -> EvalResult {
    match &e.kind {
        ExprKind::Literal(literal, _) => Ok(ConstExpr::Literal(*literal)),
        ExprKind::Global(ident, _) => todo!(),
        ExprKind::BinaryPred {
            op,
            lhs,
            rhs,
            shared,
        } => todo!(),
        ExprKind::BinaryArith { op, lhs, rhs, ty } => todo!(),
        ExprKind::Unary { op, expr, ty } => todo!(),
        #[allow(unused)]
        ExprKind::Call { callee, args, ty } => todo!(),
        #[allow(unused)]
        ExprKind::Array { values, ty } => todo!(),
        #[allow(unused)]
        ExprKind::StructInit { values, ty } => todo!(),
        ExprKind::Variable(_, type_ident) => todo!(),
        ExprKind::Assign { lhs, rhs, ty } => todo!(),
        ExprKind::Cast {
            expr,
            target,
            method,
        } => todo!(),
        ExprKind::Index { index, expr, ty } => todo!(),
        ExprKind::FieldLookup {
            obj,
            field,
            struct_ty,
            ty,
        } => todo!(),
        ExprKind::StructCopy { expr, ty } => todo!(),
        ExprKind::Deref { expr, ty } => todo!(),
        ExprKind::Ref { expr, ty } => todo!(),
        ExprKind::Load { expr, ty } => todo!(),
    }
}

/*
#[allow(unused)]
fn eval_ident(ident: &Identifier) -> EvalResult {
    Err(())
}

fn eval_binary(op: &BinaryOp, lhs: &AstExpr, rhs: &AstExpr) -> EvalResult {
    match op {
        BinaryOp::Arith(op) => eval_arith(op, lhs, rhs),
        BinaryOp::Pred(op) => eval_pred(op, lhs, rhs),
        BinaryOp::Index => Err(()),
        BinaryOp::Assign => Err(()),
        BinaryOp::FieldLookup => todo!(),
    }
}

fn eval_arith(op: &BinaryArith, lhs: &AstExpr, rhs: &AstExpr) -> EvalResult {
    let lhs = const_eval_expr(lhs)?;
    let rhs = const_eval_expr(rhs)?;
    let lhs_type: TypeIdent = (&lhs).into();
    let rhs_type: TypeIdent = (&rhs).into();

    let shared = TypeIdent::shared_type(&lhs_type, &rhs_type)?;
    let lhs = eval_cast(lhs, lhs_type, shared.clone())?;
    let rhs = eval_cast(rhs, rhs_type, shared.clone())?;

    macro_rules! arith {
        ($lhs: expr, $rhs: expr, $op: tt) => {
            match ($lhs, $rhs) {
                (Literal::Number(lhs), Literal::Number(rhs)) => Literal::Number(lhs $op rhs),
                (Literal::Float(lhs), Literal::Float(rhs)) => Literal::Float(lhs $op rhs),
                (Literal::Char(lhs), Literal::Char(rhs)) => Literal::Char((lhs as u8 $op rhs as u8) as char),
                (_, _) => return Err(())
            }
        };
    }

    Ok(match op {
        BinaryArith::Add => arith!(lhs, rhs, +),
        BinaryArith::Sub => arith!(lhs, rhs, -),
        BinaryArith::Mul => arith!(lhs, rhs, *),
        BinaryArith::Div => arith!(lhs, rhs, /),
        BinaryArith::Rem => arith!(lhs, rhs, %),
    })
}

fn eval_pred(op: &BinaryPred, lhs: &AstExpr, rhs: &AstExpr) -> EvalResult {
    let lhs = const_eval_expr(lhs)?;
    let rhs = const_eval_expr(rhs)?;
    let lhs_type: TypeIdent = (&lhs).into();
    let rhs_type: TypeIdent = (&rhs).into();

    let shared = TypeIdent::shared_type(&lhs_type, &rhs_type)?;
    let lhs = eval_cast(lhs, lhs_type, shared.clone())?;
    let rhs = eval_cast(rhs, rhs_type, shared.clone())?;

    macro_rules! pred {
        ($lhs: expr, $rhs: expr, $op: tt) => {
            match ($lhs, $rhs) {
                (Literal::Number(lhs), Literal::Number(rhs)) => lhs $op rhs,
                (Literal::Bool(lhs), Literal::Bool(rhs)) => lhs $op rhs,
                (Literal::Float(lhs), Literal::Float(rhs)) => lhs $op rhs,
                (Literal::Char(lhs), Literal::Char(rhs)) => lhs $op rhs,
                (_, _) => return Err(())
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
            (Literal::Bool(lhs), Literal::Bool(rhs)) => lhs && rhs,
            (_, _) => return Err(()),
        },
        BinaryPred::Or => match (lhs, rhs) {
            (Literal::Bool(lhs), Literal::Bool(rhs)) => lhs || rhs,
            (_, _) => return Err(()),
        },
    };
    Ok(Literal::Bool(res))
}

fn eval_cast(l: Literal, from: TypeIdent, into: TypeIdent) -> EvalResult {
    TypeIdent::try_cast_into(&from, &into)?;
    match into {
        TypeIdent::Atomic(Atomic::Number(Numeric::Int)) => l.to_int(),
        TypeIdent::Atomic(Atomic::Number(Numeric::Char)) => l.to_char(),
        TypeIdent::Atomic(Atomic::Number(Numeric::Bool)) => l.to_bool(),
        TypeIdent::Atomic(Atomic::Float) => l.to_float(),
        _ => Err(()),
    }
}

fn eval_unary(op: &UnaryArith, expr: &AstExpr) -> EvalResult {
    let val = const_eval_expr(expr)?;
    Ok(match op {
        UnaryArith::POS => val,
        UnaryArith::NOT => match val {
            Literal::Bool(b) => Literal::Bool(!b),
            _ => return Err(()),
        },
        UnaryArith::NEG => match val {
            Literal::Number(n) => Literal::Number(-n),
            Literal::Char(n) => Literal::Number(n as i64),
            Literal::Float(n) => Literal::Float(-n),
            _ => return Err(()),
        },
    })
}

*/
