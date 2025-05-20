use crate::Span;

use super::{expr::Expr, function::{Extern, Function}, Identifier};

pub enum Declaration {
    Function(Function),
    Extern(Extern),
    Global(Global),
    None,
}


pub struct Global {
    name: Identifier,
    mutable: bool,
    value: Expr,
    span: Span,
}


impl Global {
    pub fn new(name: Identifier, value: Expr, mutable: bool, span: Span) -> Self {
        Self {
            name,
            value,
            mutable,
            span
        }
    }
}

impl std::fmt::Display for Global {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        if self.mutable {
            write!(f, "let {}", self.name)
        } else {
            write!(f, "const {}", self.name)
        }
    }
}
