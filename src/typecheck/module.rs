use crate::{ast::prelude::*, utils::Span};

use super::{expr::Expr, function::*, TypeIdent};


pub struct Global {
    name: Identifier,
    mutable: bool,
    value: Expr,
    ty: TypeIdent,
    #[allow(dead_code)]
    span: Span,
}


pub struct Module {
    pub name: String,
    pub externs: Vec<Extern>,
    pub functions: Vec<Function>,
    pub globals: Vec<Global>,
}


impl Module {
    pub fn new(name: String) -> Self {
        Self {
            name,
            externs: vec![],
            functions: vec![],
            globals: vec![],
        }
    }
}
