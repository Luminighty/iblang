use std::collections::HashSet;

use crate::{
    ast::prelude::*, symbol_resolver::SymbolTable, typecheck::const_eval::ConstExpr, utils::Span,
};

use super::{TypeIdent, expr::Expr, function::*, type_struct::StructDef};
use std::rc::Rc;

#[derive(Debug)]
#[allow(unused)]
pub struct ExternGlobal {
    pub name: Identifier,
    pub ty: TypeIdent,
    #[allow(dead_code)]
    pub span: Span,
}

impl ExternGlobal {
    pub fn new(name: Identifier, ty: TypeIdent, span: Span) -> Self {
        Self { name, ty, span }
    }
}

#[derive(Debug)]
#[allow(unused)]
pub struct Global {
    pub name: Identifier,
    pub mutable: bool,
    pub value: ConstExpr,
    pub ty: TypeIdent,
    #[allow(dead_code)]
    pub span: Span,
}

impl Global {
    pub fn new(
        name: Identifier,
        value: ConstExpr,
        ty: TypeIdent,
        mutable: bool,
        span: Span,
    ) -> Self {
        Self {
            name,
            value,
            ty,
            mutable,
            span,
        }
    }
}

#[derive(Debug)]
pub struct Module {
    pub name: String,
    pub externs: Vec<Rc<Extern>>,
    pub extern_globals: Vec<Rc<ExternGlobal>>,
    pub functions: Vec<Rc<Function>>,
    #[allow(unused)]
    pub globals: Vec<Rc<Global>>,
    pub struct_defs: Vec<Rc<StructDef>>,
    pub types: HashSet<String>,
}

impl Module {
    pub fn new(name: String) -> Self {
        Self {
            name,
            externs: vec![],
            extern_globals: vec![],
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

    pub fn get_extern_global(&self, ident: &Identifier) -> Option<&ExternGlobal> {
        for g in &self.extern_globals {
            if g.name == *ident {
                return Some(g);
            }
        }
        None
    }

    pub fn get_global(&self, ident: &Identifier) -> Option<&Global> {
        for g in &self.globals {
            if g.name == *ident {
                return Some(g);
            }
        }
        None
    }

    // NOTE: Arrays return the element size, due to array decay/easy indexing semantics
    pub fn type_size_and_align(&self, ty: &TypeIdent, symbol_table: &SymbolTable) -> (usize, u32) {
        match ty {
            TypeIdent::Atomic(atomic) => {
                let s = atomic.size();
                (s, s as u32)
            }
            TypeIdent::Struct(s) => {
                let strct = symbol_table.get_symbol(s).unwrap();
                match strct.deep_struct() {
                    Ok(s) => (s.size, s.align),
                    Err(err) => panic!("Struct was not typechecked {err:?}"),
                }
            }
            TypeIdent::Array(type_ident, len) => {
                let (size, align) = self.type_size_and_align(type_ident, symbol_table);
                (size * len, align)
            }
            TypeIdent::Ref(_) => (8, 8),
        }
    }
}
