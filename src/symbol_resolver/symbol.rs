use crate::{
    ast::{
        Identifier,
        prelude::{AstExternGlobal, AstGlobal, AstPrototype, AstStructDef},
    },
    typecheck::{
        module::{ExternGlobal, Global},
        prelude::Prototype,
        type_struct::StructDef,
    },
};

pub type SymbolUID = usize;

#[derive(Debug)]
pub struct Symbol<'a> {
    pub uid: SymbolUID,
    pub name: Identifier,
    pub kind: SymbolKind,
    pub stage: SymbolStage,
    pub shallow: ShallowInfo<'a>,
    pub deep: DeepInfo<'a>,
}

#[derive(Debug)]
pub enum SymbolStage {
    Declared,
    SymbolResolved,
    TypecheckInProgress,
    Typechecked,
}

#[derive(Debug)]
pub enum SymbolKind {
    Struct,
    Global,
    Function,
}

#[derive(Debug)]
pub enum ShallowInfo<'a> {
    None,
    Struct(&'a AstStructDef),
    Global(&'a AstGlobal),
    ExternGlobal(&'a AstExternGlobal),
    Function(&'a AstPrototype),
}

#[derive(Debug)]
pub enum DeepInfo<'a> {
    None,
    Struct(&'a StructDef),
    Global(&'a Global),
    ExternGlobal(&'a ExternGlobal),
    Function(&'a Prototype),
}

impl<'a> Symbol<'a> {
    pub fn new(uid: SymbolUID, name: Identifier, kind: SymbolKind) -> Self {
        Self {
            uid,
            name,
            kind,
            stage: SymbolStage::Declared,
            shallow: ShallowInfo::None,
            deep: DeepInfo::None,
        }
    }
}
