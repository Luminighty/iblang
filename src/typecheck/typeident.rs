use super::atomic::Atomic;
use crate::{
    ast::Identifier,
    lexer::token::TypeIdentToken,
    symbol_resolver::{SymbolKind, SymbolTable, SymbolUID},
    typecheck::atomic::Numeric,
};

#[derive(Debug, Clone, PartialEq, Eq, Hash)]
pub enum TypeIdent {
    Atomic(Atomic),
    Struct(SymbolUID),
    Union(SymbolUID),
    Enum(SymbolUID),
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
    Deref,
}

impl TypeIdent {
    pub fn name(&self, symbol_table: &SymbolTable) -> String {
        match self {
            TypeIdent::Atomic(atomic) => format!("{atomic}"),
            TypeIdent::Struct(id) => format!("{}", symbol_table.symbol_name(id)),
            TypeIdent::Union(id) => format!("{}", symbol_table.symbol_name(id)),
            TypeIdent::Enum(id) => format!("{}", symbol_table.symbol_name(id)),
            TypeIdent::Array(ty, len) => format!("{}[{len}]", ty.name(symbol_table)),
            TypeIdent::Ref(ty) => format!("*{}", ty.name(symbol_table)),
        }
    }
    pub fn debug(&self, symbol_table: &SymbolTable) -> String {
        match self {
            TypeIdent::Atomic(atomic) => format!("{atomic}"),
            TypeIdent::Struct(id) => format!("{:?}", symbol_table.get_symbol(id)),
            TypeIdent::Union(id) => format!("{:?}", symbol_table.get_symbol(id)),
            TypeIdent::Enum(id) => format!("{:?}", symbol_table.get_symbol(id)),
            TypeIdent::Array(ty, len) => format!("{}[{len}]", ty.debug(symbol_table)),
            TypeIdent::Ref(ty) => format!("*{}", ty.debug(symbol_table)),
        }
    }

    pub fn from_symbol(symbol: SymbolUID, kind: SymbolKind) -> TypeIdent {
        match kind {
            SymbolKind::Struct => TypeIdent::Struct(symbol),
            SymbolKind::Union => TypeIdent::Union(symbol),
            SymbolKind::Enum => TypeIdent::Enum(symbol),
            SymbolKind::Global | SymbolKind::Function => {
                panic!("Non type symbol kind passed {symbol} {kind:?}")
            }
        }
    }

    pub fn try_cast_into(from: &Self, into: &Self) -> Result<CastMethod, ()> {
        match (from, into) {
            (lhs, rhs) if lhs == rhs => Ok(CastMethod::Keep),
            //(TypeIdent::Ref(from_ty), into_ty) if **from_ty == *into_ty => Ok(CastMethod::Deref),
            (TypeIdent::Enum(_), TypeIdent::Atomic(into)) => {
                Atomic::try_cast_into(&Atomic::Number(Numeric::Int), into)
            }
            (TypeIdent::Atomic(from), TypeIdent::Enum(into)) => {
                Atomic::try_cast_into(from, &Atomic::Number(Numeric::Int))
            }
            #[allow(unused)]
            (TypeIdent::Ref(from_ty), TypeIdent::Ref(into_ty)) => {
                match &**from_ty {
                    TypeIdent::Array(_, _) => return Ok(CastMethod::ArrayDecay),
                    _ => {}
                }
                Ok(CastMethod::Keep)
            }
            (TypeIdent::Ref(from_ty), TypeIdent::Array(into_ty, _)) => match **from_ty {
                TypeIdent::Array(ref from_arr, _) if *from_arr == *into_ty => Ok(CastMethod::Keep),
                _ => Err(()),
            },
            (TypeIdent::Atomic(from), TypeIdent::Atomic(into)) => Atomic::try_cast_into(from, into),
            (TypeIdent::Array(from_ty, from_len), TypeIdent::Array(into_ty, into_len)) => {
                if from_ty == into_ty && into_len == from_len {
                    return Ok(CastMethod::Keep);
                }
                Err(())
            }
            (TypeIdent::Array(_from_ty, _len), TypeIdent::Ref(_into_ty)) => {
                // NOTE: Consider whenever we need to do something when converting int[] -> *char,
                return Ok(CastMethod::ArrayDecay);
            }
            _ => Err(()),
        }
    }

    pub fn shared_type(lhs: &Self, rhs: &Self) -> Result<TypeIdent, ()> {
        match (lhs, rhs) {
            (lhs, rhs) if lhs == rhs => Ok(lhs.clone()),
            (TypeIdent::Ref(_), TypeIdent::Ref(_)) => Ok(lhs.clone()),
            (TypeIdent::Atomic(lhs), TypeIdent::Atomic(rhs)) => {
                Ok(Atomic::shared_type(lhs, rhs)?.into())
            }
            _ => Err(()),
        }
    }

    pub fn into_ref(self) -> Self {
        TypeIdent::Ref(Box::new(self))
    }

    pub fn is_array(&self) -> bool {
        match self {
            TypeIdent::Array(_, _) => true,
            _ => false,
        }
    }

    pub fn is_object(&self) -> bool {
        match self {
            TypeIdent::Struct(_) => true,
            TypeIdent::Union(_) => true,
            _ => false,
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
            // NOTE: This currently swaps multi-dimensional arrays
            // int[2][3] is actually int[3][2]
            TypeIdent::Array(ty, len) => write!(f, "{ty}[{}]", len),
            TypeIdent::Ref(ty) => write!(f, "*{ty}"),
            TypeIdent::Struct(i) => write!(f, "Struct({i})"),
            TypeIdent::Union(i) => write!(f, "Union({i})"),
            TypeIdent::Enum(e) => write!(f, "Enum({e})"),
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
