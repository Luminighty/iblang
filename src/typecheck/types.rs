use crate::lexer::token::TypeIdentToken;
use super::atomic::Atomic;


#[derive(Debug, Clone, PartialEq, Eq)]
pub enum TypeIdent {
    Atomic(Atomic),
    Array(Box<TypeIdent>, usize),
}

#[derive(Debug, Clone)]
pub enum FlowType {
    Some(TypeIdent),
    Void,
    Never,
}

impl From<&TypeIdent> for FlowType {
    fn from(ty: &TypeIdent) -> Self {
        Self::Some(ty.clone())
    }
}

#[derive(Debug, Clone)]
pub enum CastMethod {
    Keep,
    Truncate,
    Extend,
    FloatToInt,
    IntToFloat,
}

impl TypeIdent {
    pub fn try_cast_into(from: &Self, into: &Self) -> Result<CastMethod, ()> {
        match (from, into) {
            (TypeIdent::Atomic(from), TypeIdent::Atomic(into)) => Atomic::try_cast_into(from, into),
            _ => Err(()),
        }
    }

    pub fn shared_type(lhs: &Self, rhs: &Self) -> Result<TypeIdent, ()> {
        match (lhs, rhs) {
            (TypeIdent::Atomic(lhs), TypeIdent::Atomic(rhs)) =>
                Ok(Atomic::shared_type(lhs, rhs)?.into()),
            _ => Err(()),
        }
    }
}

impl From<&TypeIdentToken> for TypeIdent {
    fn from(ty: &TypeIdentToken) -> Self {
        match ty {
            TypeIdentToken::Int => TypeIdent::Atomic(Atomic::int()),
            TypeIdentToken::String => todo!(),
            TypeIdentToken::Char => TypeIdent::Atomic(Atomic::char()),
            TypeIdentToken::Bool => TypeIdent::Atomic(Atomic::bool()),
            TypeIdentToken::Float => TypeIdent::Atomic(Atomic::Float),
        }
    }
}


impl std::fmt::Display for TypeIdent {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            TypeIdent::Atomic(atomic) => write!(f, "{}", atomic),
            TypeIdent::Array(ty, len) => write!(f, "{ty}[{}]", len),
        }
    }
}

impl std::fmt::Display for FlowType {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            FlowType::Some(type_ident) => write!(f, "{}", type_ident),
            FlowType::Void => write!(f, "void"),
            FlowType::Never => write!(f, "!"),
        }
    }
}

