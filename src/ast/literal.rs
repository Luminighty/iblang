use crate::typecheck::{TypeIdent, atomic::Atomic};

#[derive(Debug, Clone, Copy, PartialEq)]
pub enum Literal {
    Number(i64),
    Bool(bool),
    Char(char),
    Float(f64),
    Null,
}

impl std::fmt::Display for Literal {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        use Literal::*;
        match self {
            Number(n) => write!(f, "{}", n),
            Float(n) => write!(f, "{}", n),
            Bool(true) => write!(f, "true"),
            Bool(false) => write!(f, "false"),
            Char('\n') => write!(f, "'\\n'"),
            Char('\t') => write!(f, "'\\t'"),
            Char('\r') => write!(f, "'\\r'"),
            Char('\0') => write!(f, "'\\0'"),
            Char(c) => write!(f, "'{}'", c),
            Null => write!(f, "null"),
        }
    }
}

impl Literal {
    pub fn as_i64(self) -> i64 {
        match self {
            Literal::Number(n) => n,
            Literal::Bool(b) => {
                if b {
                    1
                } else {
                    0
                }
            }
            Literal::Char(c) => c as i64,
            Literal::Float(f) => f as i64,
            Literal::Null => 0,
        }
    }

    pub fn to_int(self) -> Result<Self, ()> {
        Ok(Literal::Number(match self {
            Literal::Number(v) => v,
            Literal::Bool(v) => v as i64,
            Literal::Char(v) => v as i64,
            Literal::Float(v) => v as i64,
            Literal::Null => 0,
        }))
    }

    pub fn to_char(self) -> Result<Self, ()> {
        Ok(Literal::Char(match self {
            Literal::Number(v) => char::from_u32(v as u32).unwrap(),
            Literal::Bool(b) => b as u8 as char,
            Literal::Char(v) => v,
            Literal::Float(v) => v as u8 as char,
            Literal::Null => 0 as char,
        }))
    }

    pub fn to_bool(self) -> Result<Self, ()> {
        Ok(Literal::Bool(match self {
            Literal::Number(v) => v != 0,
            Literal::Bool(v) => v,
            Literal::Char(v) => v as u8 != 0,
            Literal::Float(v) => v != 0.0,
            Literal::Null => false,
        }))
    }

    pub fn to_float(self) -> Result<Self, ()> {
        Ok(Literal::Float(match self {
            Literal::Number(v) => v as f64,
            Literal::Bool(v) => v as i64 as f64,
            Literal::Char(v) => v as i64 as f64,
            Literal::Float(v) => v,
            Literal::Null => 0 as f64,
        }))
    }
}

impl Into<TypeIdent> for &Literal {
    fn into(self) -> TypeIdent {
        let ty = match self {
            Literal::Number(_) => Atomic::int(),
            Literal::Bool(_) => Atomic::bool(),
            Literal::Char(_) => Atomic::char(),
            Literal::Float(_) => Atomic::Float,
            Literal::Null => return TypeIdent::Ref(None),
        };
        ty.into()
    }
}
