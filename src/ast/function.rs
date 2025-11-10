use crate::utils::Span;

use super::{
    Identifier,
    statement::AstStatement,
    types::{AstFlowType, AstTypeIdent},
};
use std::rc::Rc;

#[derive(Debug)]
pub struct AstPrototype {
    pub identifier: String,
    pub args: Vec<(Identifier, AstTypeIdent, Span)>,
    pub return_type: AstFlowType,
    pub return_type_span: Span,
    pub has_varargs: bool,
}

#[derive(Debug)]
pub struct AstExternFunction {
    pub is_public: bool,
    pub prototype: Rc<AstPrototype>,
    #[allow(dead_code)]
    pub span: Span,
}

#[derive(Debug)]
pub struct AstFunction {
    pub is_public: bool,
    pub prototype: Rc<AstPrototype>,
    pub body: AstStatement,
    #[allow(dead_code)]
    pub span: Span,
}

impl AstPrototype {
    pub fn new(
        identifier: String,
        args: Vec<(Identifier, AstTypeIdent, Span)>,
        return_type: AstFlowType,
        return_type_span: Span,
        has_varargs: bool,
    ) -> Self {
        Self {
            identifier,
            args,
            return_type,
            return_type_span,
            has_varargs,
        }
    }
}

impl AstFunction {
    pub fn new(prototype: AstPrototype, body: AstStatement, span: Span, is_public: bool) -> Self {
        Self {
            prototype: Rc::new(prototype),
            body,
            span,
            is_public,
        }
    }
}

impl AstExternFunction {
    pub fn new(prototype: AstPrototype, span: Span, is_public: bool) -> Self {
        Self {
            prototype: Rc::new(prototype),
            span,
            is_public,
        }
    }
}

impl std::fmt::Display for AstFunction {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let depth = f.width().unwrap_or(0);
        write!(f, "{:width$}", "", width = depth)?;
        if self.is_public {
            write!(f, "pub ")?;
        }
        write!(f, "{} ", self.prototype)?;
        write!(f, "{}", self.body)
    }
}

impl std::fmt::Display for AstExternFunction {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        if self.is_public {
            write!(f, "pub ")?;
        }
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
