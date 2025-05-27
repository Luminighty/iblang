use crate::{lexer::token::TypeIdentToken, typecheck::atomic::Atomic, utils::Span};

use super::AstExpr;

#[derive(Debug)]
pub enum AstTypeIdent {
    Atomic(Atomic),
    Array(Box<AstTypeIdent>, AstExpr),
}

#[derive(Debug)]
pub enum AstFlowType {
    Some(AstTypeIdent),
    Void,
    Never,
}

impl From<&TypeIdentToken> for AstTypeIdent {
    fn from(ty: &TypeIdentToken) -> Self {
        match ty {
            TypeIdentToken::Int => AstTypeIdent::Atomic(Atomic::Number),
            TypeIdentToken::String => AstTypeIdent::Array(Box::new(Atomic::Char.into()), AstExpr::number(256, Span::none())),
            TypeIdentToken::Char => AstTypeIdent::Atomic(Atomic::Char),
            TypeIdentToken::Bool => AstTypeIdent::Atomic(Atomic::Bool),
            TypeIdentToken::Float => AstTypeIdent::Atomic(Atomic::Float),
        }
    }
}

impl From<Atomic> for AstTypeIdent {
    fn from(ty: Atomic) -> Self {
        Self::Atomic(ty)
    }
}


impl std::fmt::Display for AstTypeIdent {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            AstTypeIdent::Atomic(atomic) => write!(f, "{}", atomic),
            AstTypeIdent::Array(ty, len) => write!(f, "{ty}[{}]", len),
        }
    }
}

impl std::fmt::Display for AstFlowType {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            AstFlowType::Some(type_ident) => write!(f, "{}", type_ident),
            AstFlowType::Void => write!(f, "void"),
            AstFlowType::Never => write!(f, "!"),
        }
    }
}

