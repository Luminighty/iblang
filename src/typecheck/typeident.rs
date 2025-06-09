use super::atomic::Atomic;
use crate::{ast::Identifier, lexer::token::TypeIdentToken};

#[derive(Debug, Clone, PartialEq, Eq)]
pub enum TypeIdent {
    Atomic(Atomic),
    Struct(Identifier),
    Array(Box<TypeIdent>, usize),
    Ref(Box<TypeIdent>),
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
    ArrayDecay,
}

impl TypeIdent {
    pub fn try_cast_into(from: &Self, into: &Self) -> Result<CastMethod, ()> {
        match (from, into) {
            (TypeIdent::Ref(from_ty), TypeIdent::Ref(into_ty)) => {
                match &**from_ty {
                    TypeIdent::Array(_, _) => return Ok(CastMethod::ArrayDecay),
                    _ => {}
                }
                Ok(CastMethod::Keep)
            }
            (TypeIdent::Atomic(from), TypeIdent::Atomic(into)) => Atomic::try_cast_into(from, into),
            (TypeIdent::Array(from_ty, from_len), TypeIdent::Array(into_ty, into_len)) => {
                if from_ty == into_ty && into_len == from_len {
                    return Ok(CastMethod::Keep);
                }
                Err(())
            }
            (TypeIdent::Array(_from_ty, _len), TypeIdent::Ref(_into_ty)) => {
                // NOTE: Consider whenever we need to do something when converting int[] -> *char
                return Ok(CastMethod::ArrayDecay);
            }
            _ => Err(()),
        }
    }

    pub fn shared_type(lhs: &Self, rhs: &Self) -> Result<TypeIdent, ()> {
        match (lhs, rhs) {
            (TypeIdent::Atomic(lhs), TypeIdent::Atomic(rhs)) => {
                Ok(Atomic::shared_type(lhs, rhs)?.into())
            }
            _ => Err(()),
        }
    }

    pub fn into_ref(self) -> Self {
        TypeIdent::Ref(Box::new(self))
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
            TypeIdent::Ref(ty) => write!(f, "*{ty}"),
            TypeIdent::Struct(i) => write!(f, "{i}"),
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
