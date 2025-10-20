use crate::{
    ast::{
        Identifier,
        prelude::{AstExternGlobal, AstGlobal, AstPrototype, AstStructDef},
    },
    symbol_resolver::SymbolError,
    typecheck::{
        TypeIdent,
        module::{ExternGlobal, Global},
        prelude::Prototype,
        type_struct::StructDef,
    },
};
use std::rc::Rc;

pub type SymbolUID = usize;

#[derive(Debug)]
pub struct Symbol {
    pub uid: SymbolUID,
    pub name: Identifier,
    pub kind: SymbolKind,
    pub stage: SymbolStage,
    pub is_extern: bool,
    pub shallow: ShallowInfo,
    pub deep: DeepInfo,
}

#[derive(Debug, Clone)]
pub struct SymbolIdentifier(Identifier, SymbolUID);

#[derive(Debug)]
pub enum SymbolStage {
    Declared,
    SymbolResolved,
    TypecheckInProgress,
    Typechecked,
}

#[derive(Debug, Eq, PartialEq, Clone, Copy)]
pub enum SymbolKind {
    Struct,
    Global,
    Function,
}

#[derive(Debug)]
pub enum ShallowInfo {
    None,
    Struct(Rc<AstStructDef>),
    Global(Rc<AstGlobal>),
    ExternGlobal(Rc<AstExternGlobal>),
    Function(Rc<AstPrototype>),
}

#[derive(Debug)]
pub enum DeepInfo {
    None,
    Struct(Rc<StructDef>),
    Global(Rc<TypeIdent>),
    ExternGlobal(Rc<TypeIdent>),
    Function(Rc<Prototype>),
}

macro_rules! assert_kind {
    ($kind: expr, $expected: expr) => {
        if $kind != $expected {
            return Err(SymbolError::SymbolKindNotMatched {
                expected: $expected,
                got: $kind,
            });
        }
    };
}

impl Symbol {
    pub fn new(uid: SymbolUID, name: Identifier, kind: SymbolKind) -> Self {
        Self {
            uid,
            name,
            kind,
            is_extern: false,
            stage: SymbolStage::Declared,
            shallow: ShallowInfo::None,
            deep: DeepInfo::None,
        }
    }

    pub fn shallow_function(&self) -> Result<Rc<AstPrototype>, SymbolError> {
        assert_kind!(self.kind, SymbolKind::Function);
        match &self.shallow {
            ShallowInfo::Function(f) => Ok(f.clone()),
            _ => Err(SymbolError::ShallowInfoMissing),
        }
    }

    pub fn deep_function(&self) -> Result<Rc<Prototype>, SymbolError> {
        assert_kind!(self.kind, SymbolKind::Function);
        match &self.deep {
            DeepInfo::Function(f) => Ok(f.clone()),
            _ => Err(SymbolError::DeepInfoMissing),
        }
    }

    pub fn shallow_struct(&self) -> Result<Rc<AstStructDef>, SymbolError> {
        assert_kind!(self.kind, SymbolKind::Struct);
        match &self.shallow {
            ShallowInfo::Struct(f) => Ok(f.clone()),
            _ => Err(SymbolError::ShallowInfoMissing),
        }
    }

    pub fn deep_struct(&self) -> Result<Rc<StructDef>, SymbolError> {
        assert_kind!(self.kind, SymbolKind::Struct);
        match &self.deep {
            DeepInfo::Struct(f) => Ok(f.clone()),
            _ => Err(SymbolError::DeepInfoMissing),
        }
    }
}
