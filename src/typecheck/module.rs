use std::collections::HashSet;

use crate::{ast::prelude::*, utils::Span};

use super::{TypeIdent, expr::Expr, function::*, type_struct::StructDef};

#[derive(Debug)]
#[allow(unused)]
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
    #[allow(unused)]
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

    pub fn get_struct(&self, ident: &Identifier) -> Option<&StructDef> {
        for s in &self.struct_defs {
            if s.identifier == *ident {
                return Some(s);
            }
        }
        None
    }

    pub fn type_size_and_align(&self, ty: &TypeIdent) -> (usize, u32) {
        match ty {
            TypeIdent::Atomic(atomic) => {
                let s = atomic.size();
                (s, s as u32)
            }
            TypeIdent::Struct(s) => {
                if let Some(s) = self.get_struct(s) {
                    (s.size, s.align)
                } else {
                    panic!("Struct '{s}' not found! Are they sorted properly?")
                }
            }
            #[allow(unused)]
            TypeIdent::Array(type_ident, len) => {
                let (size, align) = self.type_size_and_align(type_ident);
                (size * len, align)
            }
            TypeIdent::Ref(_) => (4, 4),
        }
    }
}
