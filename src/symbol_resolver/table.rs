use std::collections::{HashMap, HashSet};

use crate::{
    ast::Identifier,
    symbol_resolver::{DeepInfo, ShallowInfo, Symbol, SymbolKind, SymbolStage, SymbolUID},
};

pub type ModuleUID = usize;

#[derive(Debug)]
pub struct SymbolTable<'a> {
    modules: HashMap<String, ModuleUID>,
    by_path: HashMap<ModuleUID, HashMap<Identifier, SymbolUID>>,
    symbols: HashMap<SymbolUID, Symbol<'a>>,
    symbol_uid: SymbolUID,
    module_uid: ModuleUID,
}

impl<'a> SymbolTable<'a> {
    pub fn new() -> Self {
        Self {
            modules: HashMap::new(),
            symbols: HashMap::new(),
            by_path: HashMap::new(),
            symbol_uid: 0,
            module_uid: 0,
        }
    }

    pub fn insert_module(&mut self, module: String) -> ModuleUID {
        self.module_uid += 1;
        self.modules.insert(module, self.module_uid);
        self.module_uid
    }

    fn symbol_uid_next(&mut self) -> SymbolUID {
        self.symbol_uid += 1;
        self.symbol_uid
    }

    pub fn insert(&mut self, module: ModuleUID, name: Identifier, kind: SymbolKind) -> SymbolUID {
        let uid = self.symbol_uid_next();
        let symbol = Symbol::new(uid, name.clone(), kind);
        self.symbols.insert(uid, symbol);
        if let Some(symbols) = self.by_path.get_mut(&module) {
            symbols.insert(name, uid);
        } else {
            self.by_path.insert(module, HashMap::from([(name, uid)]));
        }
        uid
    }

    pub fn get_symbol(&self, uid: &SymbolUID) -> Option<&Symbol> {
        self.symbols.get(uid)
    }

    pub fn get_symbol_mut(&mut self, uid: &SymbolUID) -> Option<&'a mut Symbol> {
        self.symbols.get_mut(uid)
    }

    pub fn get_symbol_uid(&self, module: &ModuleUID, name: &Identifier) -> Option<SymbolUID> {
        match self.by_path.get(module) {
            Some(module) => module.get(name).copied(),
            _ => None,
        }
    }

    pub fn attach_shallow(&mut self, uid: &SymbolUID, info: ShallowInfo<'a>) {
        if let Some(symbol) = self.symbols.get_mut(uid) {
            symbol.shallow = info;
            symbol.stage = SymbolStage::Typechecked;
        } else {
            panic!("Symbol uid {uid} does not have a symbol!")
        }
    }

    pub fn attach_deep(&mut self, uid: &SymbolUID, info: DeepInfo<'a>) {
        if let Some(symbol) = self.symbols.get_mut(uid) {
            symbol.deep = info;
        } else {
            panic!("Symbol uid {uid} does not have a symbol!")
        }
    }

    pub fn set_stage(&mut self, uid: &SymbolUID, stage: SymbolStage) {
        if let Some(symbol) = self.symbols.get_mut(uid) {
            symbol.stage = stage;
        } else {
            panic!("Symbol uid {uid} does not have a symbol!")
        }
    }
}
