use std::collections::HashSet;

use crate::{ast::prelude::*, utils::Span};

use super::{TypeIdent, expr::Expr, function::*, type_struct::StructDef};

#[derive(Debug)]
pub struct Global {
    name: Identifier,
    mutable: bool,
    value: Expr,
    ty: TypeIdent,
    #[allow(dead_code)]
    span: Span,
}

#[derive(Debug)]
pub struct Module {
    pub name: String,
    pub externs: Vec<Extern>,
    pub functions: Vec<Function>,
    pub globals: Vec<Global>,
    pub struct_defs: Vec<StructDef>,
    pub types: HashSet<String>,
}

impl Module {
    pub fn new(name: String) -> Self {
        Self {
            name,
            externs: vec![],
            functions: vec![],
            globals: vec![],
            types: HashSet::new(),
            struct_defs: vec![],
        }
    }
}
