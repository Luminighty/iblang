use crate::ast::UnaryOp;

use super::TypeIdent;

#[derive(Debug, Copy, Clone, PartialEq, Eq)]
pub enum Atomic {
    Number,
    String,
    Char,
    Bool,
}

impl std::fmt::Display for Atomic {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", match self {
            Atomic::Number => "int",
            Atomic::String => "str",
            Atomic::Char => "char",
            Atomic::Bool => "bool",
        })
    }
}

impl Atomic {
    pub fn arith_result(lhs: Atomic, rhs: Atomic) -> Result<Atomic, ()> {
        match (lhs, rhs) {
            (Atomic::String, _) => Err(()),
            (_, Atomic::String) => Err(()),
            (Atomic::Bool, _) => Err(()),
            (_, Atomic::Bool) => Err(()),
            (Atomic::Number, Atomic::Number) => Ok(Atomic::Number),
            (Atomic::Number, Atomic::Char) => Ok(Atomic::Char),
            (Atomic::Char, Atomic::Number) => Ok(Atomic::Char),
            (Atomic::Char, Atomic::Char) => Ok(Atomic::Char),
        }
    }

    pub fn unary_result(self, unary: UnaryOp) -> Result<Atomic, ()> {
        match (unary, self) {
            (UnaryOp::GROUP, x) => Ok(x),

            (UnaryOp::POS, Atomic::String) => Err(()),
            (UnaryOp::POS, Atomic::Bool) => Err(()),
            (UnaryOp::POS, x) => Ok(x),

            (UnaryOp::NEG, Atomic::Number) => Ok(Atomic::Number),
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
