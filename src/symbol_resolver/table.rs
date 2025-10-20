use std::collections::{HashMap, HashSet};

use crate::{
    ast::Identifier,
    symbol_resolver::{
        DeepInfo, ShallowInfo, Symbol, SymbolError, SymbolKind, SymbolStage, SymbolUID,
    },
};

pub type ModuleUID = usize;

#[derive(Debug)]
struct ModuleImport {
    module: ModuleUID,
    alias: Option<Identifier>,
}

#[derive(Debug)]
pub struct SymbolTable {
    modules: HashMap<String, ModuleUID>,
    by_path: HashMap<ModuleUID, HashMap<Identifier, SymbolUID>>,
    imports: HashMap<ModuleUID, Vec<ModuleImport>>,
    symbols: HashMap<SymbolUID, Symbol>,
    symbol_uid: SymbolUID,
    module_uid: ModuleUID,
}

impl SymbolTable {
    pub fn new() -> Self {
        Self {
            modules: HashMap::new(),
            symbols: HashMap::new(),
            by_path: HashMap::new(),
            imports: HashMap::new(),
            symbol_uid: 0,
            module_uid: 0,
        }
    }

    pub fn add_imports(&mut self, module: ModuleUID, imports: Vec<(String, Option<Identifier>)>) {
        let imports = imports
            .into_iter()
            .map(|i| {
                let id = self.modules.get(&i.0).unwrap();
                ModuleImport {
                    module: *id,
                    alias: i.1,
                }
            })
            .collect();
        self.imports.insert(module, imports);
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

    pub fn get_symbol_mut(&mut self, uid: &SymbolUID) -> Option<&mut Symbol> {
        self.symbols.get_mut(uid)
    }

    pub fn get_symbol_uid(&self, module: &ModuleUID, name: &Identifier) -> Option<SymbolUID> {
        match self.by_path.get(module) {
            Some(module) => module.get(name).copied(),
            _ => None,
        }
    }

    pub fn resolve_identifier(
        &self,
        module: ModuleUID,
        name: &Identifier,
    ) -> Result<SymbolUID, SymbolError> {
        if let Some(id) = self.get_symbol_uid(&module, name) {
            return Ok(id);
        }
        let mut symbol = None;
        let mut symbol_origin = Vec::new();
        for import in self.imports.get(&module).unwrap() {
            if let Some(id) = self.get_symbol_uid(&import.module, name) {
                symbol = Some(id);
                symbol_origin.push(import.module);
            }
        }
        if symbol_origin.len() > 1 {
            return Err(SymbolError::MultipleSymbolFound(
                name.to_string(),
                symbol_origin,
            ));
        }
        match symbol {
            Some(id) => Ok(id),
            None => Err(SymbolError::SymbolNotFound(name.to_string())),
        }
    }

    pub fn attach_shallow(&mut self, uid: &SymbolUID, info: ShallowInfo) {
        if let Some(symbol) = self.symbols.get_mut(uid) {
            symbol.shallow = info;
            symbol.stage = SymbolStage::SymbolResolved;
        } else {
            panic!("Symbol uid {uid} does not have a symbol!")
        }
    }

    pub fn attach_deep(&mut self, uid: &SymbolUID, info: DeepInfo) {
        if let Some(symbol) = self.symbols.get_mut(uid) {
            symbol.deep = info;
            symbol.stage = SymbolStage::Typechecked;
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
