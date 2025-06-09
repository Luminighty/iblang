use crate::utils::Span;

use super::{
    Identifier,
    expr::AstExpr,
    function::{AstExtern, AstFunction},
    types::AstStructDef,
};

pub enum Declaration {
    Function(AstFunction),
    Extern(AstExtern),
    Global(AstGlobal),
    Struct(AstStructDef),
    None,
}

impl std::fmt::Display for Declaration {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Declaration::None => Ok(()),
            Declaration::Extern(e) => write!(f, "{}", e),
            Declaration::Struct(s) => write!(f, "{}", s),
            Declaration::Global(g) => write!(f, "{}", g),
            Declaration::Function(func) => write!(f, "{}", func),
        }
    }
}

pub struct AstGlobal {
    pub name: Identifier,
    pub mutable: bool,
    pub value: AstExpr,
    #[allow(dead_code)]
    pub span: Span,
}

impl AstGlobal {
    pub fn new(name: Identifier, value: AstExpr, mutable: bool, span: Span) -> Self {
        Self {
            name,
            value,
            mutable,
            span,
        }
    }
}

impl std::fmt::Display for AstGlobal {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        if self.mutable {
            write!(f, "let {} = {}", self.name, self.value)
        } else {
            write!(f, "const {} = {}", self.name, self.value)
        }
    }
}
