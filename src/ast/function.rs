use crate::Span;

use super::statement::Statement;


pub struct Prototype {
    pub identifier: String,
}


pub struct Extern {
    pub prototype: Prototype,
    pub span: Span,
}


pub struct Function {
    pub prototype: Prototype,
    pub body: Statement,
    pub span: Span,
}


impl Prototype {
    pub fn new(identifier: String) -> Self {
        Self { identifier }
    }
}

impl Function {
    pub fn new(prototype: Prototype, body: Statement, span: Span) -> Self {
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
        write!(f, "{}", self.prototype)
    }
}

impl std::fmt::Display for Extern {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "extern {}", self.prototype)
    }
}

impl std::fmt::Display for Prototype {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "fn {}()", self.identifier)
    }
}


