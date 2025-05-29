use crate::ast::prelude::*;
use super::{atomic::{Atomic, Numeric}, TypeIdent};

pub type EvalResult = Result<Literal, ()>;

pub enum ConstEvalError {


}

pub fn const_eval_expr(e: &AstExpr) -> EvalResult {
    match &e.kind {
        AstExprKind::Literal(literal) => Ok(*literal),
        AstExprKind::Ident(ident) => eval_ident(ident),
        AstExprKind::Binary { op, lhs, rhs } => eval_binary(op, lhs, rhs),
        AstExprKind::Unary { op, expr } => eval_unary(op, expr),
        #[allow(unused)]
        AstExprKind::Call { callee, args } => Err(()),
        AstExprKind::Array { values } => todo!(),
    }
}


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
            (_, _) => return Err(())
        }
        BinaryPred::Or => match (lhs, rhs) {
            (Literal::Bool(lhs), Literal::Bool(rhs)) => lhs || rhs,
            (_, _) => return Err(())
        }
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

fn eval_unary(op: &UnaryOp, expr: &AstExpr) -> EvalResult {
    let val = const_eval_expr(expr)?;
    Ok(match op {
        UnaryOp::GROUP => val,
        UnaryOp::POS => val,
        UnaryOp::NOT => match val {
            Literal::Bool(b) => Literal::Bool(!b),
            _ => return Err(())
        }
        UnaryOp::NEG => match val {
            Literal::Number(n) => Literal::Number(-n),
            Literal::Char(n) => Literal::Number(n as i64),
            Literal::Float(n) => Literal::Float(-n),
            _ => return Err(())
        }
    })
}

