use crate::{
    ast::{
        Identifier,
        prelude::{
            AstEnumDef, AstExternGlobal, AstGlobal, AstPrototype, AstStructDef, AstUnionDef,
        },
    },
    symbol_resolver::{ModuleUID, SymbolError},
    typecheck::{
        TypeIdent,
        module::{ExternGlobal, Global},
        prelude::Prototype,
        type_enum::EnumDef,
        type_struct::StructDef,
        type_union::UnionDef,
    },
};
use std::rc::Rc;

pub type SymbolUID = usize;

#[derive(Debug)]
pub struct Symbol {
    pub uid: SymbolUID,
    pub is_public: bool,
    pub module_uid: ModuleUID,
    pub name: Identifier,
    pub kind: SymbolKind,
    pub stage: SymbolStage,
    pub is_extern: bool,
    pub shallow: ShallowInfo,
    pub deep: DeepInfo,
}

#[derive(Debug, Clone)]
pub struct SymbolIdentifier(Identifier, SymbolUID);

#[derive(Debug, Copy, Clone, PartialEq, Eq)]
pub enum SymbolStage {
    Declared,
    SymbolResolved,
    TypecheckInProgress,
    Typechecked,
}

#[derive(Debug, Eq, PartialEq, Clone, Copy)]
pub enum SymbolKind {
    Struct,
    Union,
    Enum,
    Global,
    Function,
}

#[derive(Debug)]
pub enum ShallowInfo {
    None,
    Struct(Rc<AstStructDef>),
    Union(Rc<AstUnionDef>),
    Global(Rc<AstGlobal>),
    Enum(Rc<AstEnumDef>),
    ExternGlobal(Rc<AstExternGlobal>),
    Function(Rc<AstPrototype>),
}

#[derive(Debug)]
pub enum DeepInfo {
    None,
    Struct(Rc<StructDef>),
    Union(Rc<UnionDef>),
    Global(Rc<TypeIdent>),
    Enum(Rc<EnumDef>),
    ExternGlobal(Rc<TypeIdent>),
    ExternFunction(Rc<Prototype>),
    Function(Rc<Prototype>),
}

macro_rules! assert_kind {
    ($kind: expr, $expected: expr, $uid: expr) => {
        if $kind != $expected {
            return Err(SymbolError::SymbolKindNotMatched {
                symbol: $uid,
                expected: $expected,
                got: $kind,
            });
        }
    };
}

impl Symbol {
    pub fn new(
        uid: SymbolUID,
        module: ModuleUID,
        name: Identifier,
        is_public: bool,
        kind: SymbolKind,
    ) -> Self {
        Self {
            uid,
            module_uid: module,
            is_public,
            name,
            kind,
            is_extern: false,
            stage: SymbolStage::Declared,
            shallow: ShallowInfo::None,
            deep: DeepInfo::None,
        }
    }

    pub fn shallow_function(&self) -> Result<Rc<AstPrototype>, SymbolError> {
        assert_kind!(self.kind, SymbolKind::Function, self.uid);
        match &self.shallow {
            ShallowInfo::Function(f) => Ok(f.clone()),
            _ => Err(SymbolError::ShallowInfoMissing),
        }
    }

    pub fn deep_function(&self) -> Result<Rc<Prototype>, SymbolError> {
        assert_kind!(self.kind, SymbolKind::Function, self.uid);
        match &self.deep {
            DeepInfo::Function(f) => Ok(f.clone()),
            _ => Err(SymbolError::DeepInfoMissing),
        }
    }

    pub fn deep_proto(&self) -> Result<Rc<Prototype>, SymbolError> {
        assert_kind!(self.kind, SymbolKind::Function, self.uid);
        match &self.deep {
            DeepInfo::Function(f) => Ok(f.clone()),
            DeepInfo::ExternFunction(f) => Ok(f.clone()),
            _ => Err(SymbolError::DeepInfoMissing),
        }
    }

    pub fn shallow_union(&self) -> Result<Rc<AstUnionDef>, SymbolError> {
        assert_kind!(self.kind, SymbolKind::Union, self.uid);
        match &self.shallow {
            ShallowInfo::Union(f) => Ok(f.clone()),
            _ => Err(SymbolError::ShallowInfoMissing),
        }
    }

    pub fn shallow_enum(&self) -> Result<Rc<AstEnumDef>, SymbolError> {
        assert_kind!(self.kind, SymbolKind::Enum, self.uid);
        match &self.shallow {
            ShallowInfo::Enum(f) => Ok(f.clone()),
            _ => Err(SymbolError::ShallowInfoMissing),
        }
    }

    pub fn shallow_struct(&self) -> Result<Rc<AstStructDef>, SymbolError> {
        assert_kind!(self.kind, SymbolKind::Struct, self.uid);
        match &self.shallow {
            ShallowInfo::Struct(f) => Ok(f.clone()),
            _ => Err(SymbolError::ShallowInfoMissing),
        }
    }

    pub fn deep_union(&self) -> Result<Rc<UnionDef>, SymbolError> {
        assert_kind!(self.kind, SymbolKind::Union, self.uid);
        match &self.deep {
            DeepInfo::Union(f) => Ok(f.clone()),
            _ => Err(SymbolError::DeepInfoMissing),
        }
    }

    pub fn deep_enum(&self) -> Result<Rc<EnumDef>, SymbolError> {
        assert_kind!(self.kind, SymbolKind::Enum, self.uid);
        match &self.deep {
            DeepInfo::Enum(f) => Ok(f.clone()),
            _ => Err(SymbolError::DeepInfoMissing),
        }
    }

    pub fn deep_struct(&self) -> Result<Rc<StructDef>, SymbolError> {
        assert_kind!(self.kind, SymbolKind::Struct, self.uid);
        match &self.deep {
            DeepInfo::Struct(f) => Ok(f.clone()),
            _ => Err(SymbolError::DeepInfoMissing),
        }
    }

    pub fn deep_global(&self) -> Result<Rc<TypeIdent>, SymbolError> {
        assert_kind!(self.kind, SymbolKind::Global, self.uid);
        match &self.deep {
            DeepInfo::ExternGlobal(ty) => Ok(ty.clone()),
            DeepInfo::Global(ty) => Ok(ty.clone()),
            _ => Err(SymbolError::DeepInfoMissing),
        }
    }
}
