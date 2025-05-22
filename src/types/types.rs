use crate::lexer::token::TypeIdentToken;

use super::atomic::Atomic;

#[derive(Debug, Copy, Clone)]
pub enum TypeIdent {
    Atomic(Atomic),
    Void,
    Never,
}


impl From<&TypeIdentToken> for TypeIdent {
    fn from(ty: &TypeIdentToken) -> Self {
        match ty {
            TypeIdentToken::Num => TypeIdent::Atomic(Atomic::Number),
            TypeIdentToken::String => TypeIdent::Atomic(Atomic::String),
            TypeIdentToken::Char => TypeIdent::Atomic(Atomic::Char),
            TypeIdentToken::Bool => TypeIdent::Atomic(Atomic::Bool),
            TypeIdentToken::Void => TypeIdent::Void,
        }
    }
}

