use crate::utils::Span;

use super::{statement::AstStatement, types::{AstFlowType, AstTypeIdent}, Identifier};


#[derive(Debug)]
pub struct Prototype {
    pub identifier: String,
    pub args: Vec<(Identifier, AstTypeIdent)>,
    pub return_type: AstFlowType,
}


pub struct Extern {
    pub prototype: Prototype,
    #[allow(dead_code)]
    pub span: Span,
}


pub struct Function {
    pub prototype: Prototype,
    pub body: AstStatement,
    #[allow(dead_code)]
    pub span: Span,
}


impl Prototype {
    pub fn new(identifier: String, args: Vec<(Identifier, AstTypeIdent)>, return_type: AstFlowType) -> Self {
        Self { identifier, args, return_type }
    }
}

impl Function {
    pub fn new(prototype: Prototype, body: AstStatement, span: Span) -> Self {
        Self { prototype, body, span }
    }
}

impl Extern {
    pub fn new(prototype: Prototype, span: Span) -> Self {
        Self { prototype, span }
    }
}

impl std::fmt::Display for Function {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let depth = f.width().unwrap_or(0);
        write!(f, "{:width$}", "", width = depth)?;
        write!(f, "{} ", self.prototype)?;
        write!(f, "{}", self.body)
    }
}

impl std::fmt::Display for Extern {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "extern {}", self.prototype)
    }
}

impl std::fmt::Display for Prototype {
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

