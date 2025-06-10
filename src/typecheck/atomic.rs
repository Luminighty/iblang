use crate::ast::prelude::*;
use std::cmp::Ordering;

use super::{CastMethod, TypeIdent};

#[derive(Debug, Copy, Clone, PartialEq, Eq)]
pub enum Numeric {
    Int,
    Char,
    Bool,
}

#[derive(Debug, Copy, Clone, PartialEq, Eq)]
pub enum Atomic {
    Number(Numeric),
    Float,
}

impl Atomic {
    pub fn char() -> Self {
        Self::Number(Numeric::Char)
    }
    pub fn int() -> Self {
        Self::Number(Numeric::Int)
    }
    pub fn bool() -> Self {
        Self::Number(Numeric::Bool)
    }
}

impl std::fmt::Display for Atomic {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "{}",
            match self {
                Atomic::Float => "float",
                Atomic::Number(Numeric::Int) => "int",
                Atomic::Number(Numeric::Char) => "char",
                Atomic::Number(Numeric::Bool) => "bool",
            }
        )
    }
}

impl From<Numeric> for Atomic {
    fn from(n: Numeric) -> Self {
        Self::Number(n)
    }
}

impl Atomic {
    pub fn size(&self) -> usize {
        match self {
            Atomic::Number(Numeric::Int) => 4,
            Atomic::Number(Numeric::Char) => 1,
            Atomic::Number(Numeric::Bool) => 1,
            Atomic::Float => 4,
        }
    }

    pub fn bit_width(&self) -> u8 {
        match self {
            Atomic::Float => 64,
            Atomic::Number(Numeric::Int) => 64,
            Atomic::Number(Numeric::Char) => 8,
            Atomic::Number(Numeric::Bool) => 1,
        }
    }

    pub fn try_cast_into(from: &Atomic, into: &Atomic) -> Result<CastMethod, ()> {
        match (from, into) {
            (Atomic::Float, Atomic::Float) => Ok(CastMethod::Keep),
            (Atomic::Float, _) => Ok(CastMethod::FloatToInt),
            (_, Atomic::Float) => Ok(CastMethod::IntToFloat),
            (curr, new) => Ok(match curr.bit_width().cmp(&new.bit_width()) {
                Ordering::Less => CastMethod::Extend,
                Ordering::Greater => CastMethod::Truncate,
                Ordering::Equal => CastMethod::Keep,
            }),
        }
    }

    pub fn shared_type(lhs: &Atomic, rhs: &Atomic) -> Result<Atomic, ()> {
        use Atomic::*;
        use Numeric::*;
        match (lhs, rhs) {
            (Number(Bool), Number(Bool)) => Ok(Number(Bool)),
            (Number(Bool), _) => Err(()),
            (_, Number(Bool)) => Err(()),
            (Float, Float) => Ok(Float),
            (Float, other) => Ok(*other),
            (other, Float) => Ok(*other),

            (Number(Int), Number(Int)) => Ok(Number(Int)),
            (Number(Int), Number(Char)) => Ok(Number(Char)),
            (Number(Char), Number(Int)) => Ok(Number(Char)),
            (Number(Char), Number(Char)) => Ok(Number(Char)),
        }
    }

    pub fn unary_result(self, unary: UnaryArith) -> Result<Atomic, ()> {
        use Atomic::*;
        use Numeric::*;
        match (unary, self) {
            (UnaryArith::POS, Number(Bool)) => Err(()),
            (UnaryArith::POS, x) => Ok(x.into()),

            (UnaryArith::NEG, Number(Int)) => Ok(Number(Int).into()),
            (UnaryArith::NEG, Float) => Ok(Float.into()),
            (UnaryArith::NEG, _) => Err(()),

            (UnaryArith::NOT, Number(Bool)) => Ok(Number(Bool).into()),
            (UnaryArith::NOT, _) => Err(()),
        }
    }
}

impl Into<TypeIdent> for Atomic {
    fn into(self) -> TypeIdent {
        TypeIdent::Atomic(self)
    }
}
