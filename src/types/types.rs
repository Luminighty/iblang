use crate::lexer::token::TypeIdentToken;

use super::atomic::Atomic;

#[derive(Debug, Copy, Clone, PartialEq, Eq)]
pub enum TypeIdent {
    Atomic(Atomic),
}

#[derive(Debug, Copy, Clone)]
pub enum ExprTypeIdent {
    Some(TypeIdent),
    Void,
    Never,
}

impl TypeIdent {
    pub fn arith_result(lhs: Self, rhs: Self) -> Result<TypeIdent, ()> {
        match (lhs, rhs) {
            (TypeIdent::Atomic(lhs), TypeIdent::Atomic(rhs)) =>
                Ok(Atomic::arith_result(lhs, rhs)?.into()),
        }

    }
}

impl From<&TypeIdentToken> for TypeIdent {
    fn from(ty: &TypeIdentToken) -> Self {
        match ty {
            TypeIdentToken::Num => TypeIdent::Atomic(Atomic::Number),
            TypeIdentToken::String => TypeIdent::Atomic(Atomic::String),
            TypeIdentToken::Char => TypeIdent::Atomic(Atomic::Char),
            TypeIdentToken::Bool => TypeIdent::Atomic(Atomic::Bool),
        }
    }
}


impl std::fmt::Display for TypeIdent {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            TypeIdent::Atomic(atomic) => write!(f, "{}", atomic),
        }
    }
}

impl std::fmt::Display for ExprTypeIdent {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            ExprTypeIdent::Some(type_ident) => write!(f, "{}", type_ident),
            ExprTypeIdent::Void => write!(f, "void"),
            ExprTypeIdent::Never => write!(f, "!"),
        }
    }
}

