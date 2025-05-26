use crate::ast::UnaryOp;

use super::TypeIdent;

#[derive(Debug, Copy, Clone, PartialEq, Eq)]
pub enum Atomic {
    Number,
    Float,
    Char,
    Bool,
}

impl std::fmt::Display for Atomic {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", match self {
            Atomic::Float => "float",
            Atomic::Number => "int",
            Atomic::Char => "char",
            Atomic::Bool => "bool",
        })
    }
}

impl Atomic {
    pub fn bit_width(&self) -> u8 {
        match self {
            Atomic::Float => 64,
            Atomic::Number => 64,
            Atomic::Char => 8,
            Atomic::Bool => 1,
        }
    }

    pub fn arith_result(lhs: Atomic, rhs: Atomic) -> Result<Atomic, ()> {
        match (lhs, rhs) {
            (Atomic::Bool, _) => Err(()),
            (_, Atomic::Bool) => Err(()),
            (Atomic::Float, Atomic::Float) => Ok(Atomic::Number),
            (Atomic::Float, other) => Ok(other),
            (other, Atomic::Float) => Ok(other),

            (Atomic::Number, Atomic::Number) => Ok(Atomic::Number),
            (Atomic::Number, Atomic::Char) => Ok(Atomic::Char),
            (Atomic::Char, Atomic::Number) => Ok(Atomic::Char),
            (Atomic::Char, Atomic::Char) => Ok(Atomic::Char),
        }
    }

    pub fn unary_result(self, unary: UnaryOp) -> Result<Atomic, ()> {
        match (unary, self) {
            (UnaryOp::GROUP, x) => Ok(x),

            (UnaryOp::POS, Atomic::Bool) => Err(()),
            (UnaryOp::POS, x) => Ok(x),

            (UnaryOp::NEG, Atomic::Number) => Ok(Atomic::Number),
            (UnaryOp::NEG, Atomic::Float) => Ok(Atomic::Float),
            (UnaryOp::NEG, _) => Err(()),

            (UnaryOp::NOT, Atomic::Bool) => Ok(Atomic::Bool),
            (UnaryOp::NOT, _) => Err(()),
        }
    }
}

impl Into<TypeIdent> for Atomic {
    fn into(self) -> TypeIdent {
        TypeIdent::Atomic(self)
    }
}
