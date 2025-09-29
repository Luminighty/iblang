use crate::{ast::types::AstTypeIdent, utils::Span};

use super::{
    Identifier,
    expr::AstExpr,
    function::{AstExternFunction, AstFunction},
    types::AstStructDef,
};

pub enum Declaration {
    Function(AstFunction),
    ExternFn(AstExternFunction),
    ExternGlobal(AstExternGlobal),
    Global(AstGlobal),
    Struct(AstStructDef),
    None,
}

impl std::fmt::Display for Declaration {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Declaration::None => Ok(()),
            Declaration::ExternFn(e) => write!(f, "{}", e),
            Declaration::Struct(s) => write!(f, "{}", s),
            Declaration::Global(g) => write!(f, "{}", g),
            Declaration::Function(func) => write!(f, "{}", func),
            Declaration::ExternGlobal(g) => write!(f, "{}", g),
        }
    }
}

pub struct AstExternGlobal {
    pub name: Identifier,
    pub ty: AstTypeIdent,
    #[allow(dead_code)]
    pub span: Span,
}

impl AstExternGlobal {
    pub fn new(name: Identifier, ty: AstTypeIdent, span: Span) -> Self {
        Self { name, ty, span }
    }
}

pub struct AstGlobal {
    pub name: Identifier,
    pub mutable: bool,
    pub value: AstExpr,
    pub ty: Option<AstTypeIdent>,
    #[allow(dead_code)]
    pub span: Span,
}

impl AstGlobal {
    pub fn new(
        name: Identifier,
        value: AstExpr,
        ty: Option<AstTypeIdent>,
        mutable: bool,
        span: Span,
    ) -> Self {
        Self {
            name,
            value,
            mutable,
            ty,
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
impl std::fmt::Display for AstExternGlobal {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "extern {}: {}", self.name, self.ty)
    }
}
