use crate::utils::Span;

use super::{statement::AstStatement, types::{AstFlowType, AstTypeIdent}, Identifier};


#[derive(Debug)]
pub struct AstPrototype {
    pub identifier: String,
    pub args: Vec<(Identifier, AstTypeIdent)>,
    pub return_type: AstFlowType,
}


pub struct AstExtern {
    pub prototype: AstPrototype,
    #[allow(dead_code)]
    pub span: Span,
}


pub struct AstFunction {
    pub prototype: AstPrototype,
    pub body: AstStatement,
    #[allow(dead_code)]
    pub span: Span,
}


impl AstPrototype {
    pub fn new(identifier: String, args: Vec<(Identifier, AstTypeIdent)>, return_type: AstFlowType) -> Self {
        Self { identifier, args, return_type }
    }
}

impl AstFunction {
    pub fn new(prototype: AstPrototype, body: AstStatement, span: Span) -> Self {
        Self { prototype, body, span }
    }
}

impl AstExtern {
    pub fn new(prototype: AstPrototype, span: Span) -> Self {
        Self { prototype, span }
    }
}

impl std::fmt::Display for AstFunction {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let depth = f.width().unwrap_or(0);
        write!(f, "{:width$}", "", width = depth)?;
        write!(f, "{} ", self.prototype)?;
        write!(f, "{}", self.body)
    }
}

impl std::fmt::Display for AstExtern {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "extern {}", self.prototype)
    }
}

impl std::fmt::Display for AstPrototype {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "fn {}(", self.identifier)?;
        for (i, arg) in self.args.iter().enumerate() {
            write!(f, "{}: {}", arg.0, arg.1)?;
            if self.args.len() > i + 1 {
                write!(f, ", ")?;
            }
        }
        write!(f, ")")
    }
}

