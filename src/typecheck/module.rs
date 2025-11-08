use std::collections::HashSet;

use crate::{
    ast::prelude::*,
    symbol_resolver::{ModuleUID, SymbolTable, SymbolUID},
    typecheck::{const_eval::ConstExpr, type_enum::EnumDef, type_union::UnionDef},
    utils::Span,
};

use super::{TypeIdent, expr::Expr, function::*, type_struct::StructDef};
use std::rc::Rc;

#[derive(Debug)]
#[allow(unused)]
pub struct ExternGlobal {
    pub name: Identifier,
    pub symbol: SymbolUID,
    pub ty: TypeIdent,
    #[allow(dead_code)]
    pub span: Span,
}

impl ExternGlobal {
    pub fn new(name: Identifier, symbol: SymbolUID, ty: TypeIdent, span: Span) -> Self {
        Self {
            name,
            ty,
            symbol,
            span,
        }
    }
}

#[derive(Debug)]
#[allow(unused)]
pub struct Global {
    pub name: Identifier,
    pub symbol: SymbolUID,
    pub mutable: bool,
    pub value: ConstExpr,
    pub ty: TypeIdent,
    #[allow(dead_code)]
    pub span: Span,
    pub is_public: bool,
}

impl Global {
    pub fn new(
        name: Identifier,
        symbol: SymbolUID,
        value: ConstExpr,
        ty: TypeIdent,
        is_public: bool,
        mutable: bool,
        span: Span,
    ) -> Self {
        Self {
            name,
            symbol,
            value,
            ty,
            mutable,
            is_public,
            span,
        }
    }
}

#[derive(Debug)]
pub struct Module {
    pub name: String,
    pub id: ModuleUID,
    pub externs: Vec<Rc<Extern>>,
    pub extern_globals: Vec<ExternGlobal>,
    pub functions: Vec<Rc<Function>>,
    #[allow(unused)]
    pub globals: Vec<Global>,
    pub struct_defs: Vec<Rc<StructDef>>,
    pub union_defs: Vec<Rc<UnionDef>>,
    pub enum_defs: Vec<Rc<EnumDef>>,
    pub types: HashSet<String>,
}

impl Module {
    pub fn new(name: String, id: ModuleUID) -> Self {
        Self {
            name,
            id,
            externs: vec![],
            extern_globals: vec![],
            functions: vec![],
            globals: vec![],
            types: HashSet::new(),
            struct_defs: vec![],
            union_defs: vec![],
            enum_defs: vec![],
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
}

// NOTE: Arrays return the element size, due to array decay/easy indexing semantics
pub fn type_size_and_align(ty: &TypeIdent, symbol_table: &SymbolTable) -> (usize, u32) {
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
        TypeIdent::Enum(s) => {
            let _enum = symbol_table.get_symbol(s).unwrap();
            match _enum.deep_enum() {
                Ok(s) => (s.size, s.align),
                Err(err) => panic!("Enum was not typechecked {err:?}"),
            }
        }
        TypeIdent::Union(s) => {
            let union = symbol_table.get_symbol(s).unwrap();
            match union.deep_union() {
                Ok(s) => (s.size, s.align),
                Err(err) => panic!("Union was not typechecked {err:?}"),
            }
        }
        TypeIdent::Array(type_ident, len) => {
            let (size, align) = type_size_and_align(type_ident, symbol_table);
            (size * len, align)
        }
        TypeIdent::Ref(_) => (8, 8),
    }
}
