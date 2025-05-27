use crate::utils::Span;

use super::{expr::AstExpr, function::{Extern, Function}, Identifier};

pub enum Declaration {
    Function(Function),
    Extern(Extern),
    Global(Global),
    None,
}

impl std::fmt::Display for Declaration {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Declaration::None => Ok(()),
            Declaration::Extern(e) => write!(f, "{}", e),
            Declaration::Global(g) => write!(f, "{}", g),
            Declaration::Function(func) => write!(f, "{}", func),
        }
    }
}

pub struct Global {
    name: Identifier,
    mutable: bool,
    value: AstExpr,
    #[allow(dead_code)]
    span: Span,
}


impl Global {
    pub fn new(name: Identifier, value: AstExpr, mutable: bool, span: Span) -> Self {
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
            write!(f, "let {} = {}", self.name, self.value)
        } else {
            write!(f, "const {} = {}", self.name, self.value)
        }
    }
}

