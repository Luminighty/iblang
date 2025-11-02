use std::collections::{HashMap, HashSet};

use crate::{
    ast::Identifier,
    symbol_resolver::{
        DeepInfo, ShallowInfo, Symbol, SymbolError, SymbolKind, SymbolStage, SymbolUID,
    },
};

pub type ModuleUID = usize;

#[derive(Debug)]
pub struct ModuleImport {
    module: ModuleUID,
    alias: Option<Identifier>,
    is_public: bool,
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

    pub fn add_imports(
        &mut self,
        module: ModuleUID,
        imports: Vec<(String, Option<Identifier>, bool)>,
    ) {
        let imports = imports
            .into_iter()
            .map(|i| {
                let id = self
                    .modules
                    .get(&i.0)
                    .expect(&format!("Module {i:?} not found! {:?}", self.modules));
                ModuleImport {
                    module: *id,
                    alias: i.1,
                    is_public: i.2,
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

    pub fn insert(
        &mut self,
        module: ModuleUID,
        name: Identifier,
        is_public: bool,
        kind: SymbolKind,
    ) -> SymbolUID {
        let uid = self.symbol_uid_next();
        let symbol = Symbol::new(uid, module, name.clone(), is_public, kind);
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

    pub fn is_public(&self, uid: &SymbolUID) -> bool {
        self.symbols.get(uid).unwrap().is_public
    }

    pub fn symbol_name(&self, uid: &SymbolUID) -> &str {
        &self.get_symbol(uid).unwrap().name
    }

    pub fn resolve_identifier_by_path(
        &self,
        module: ModuleUID,
        name: &Identifier,
        path: &Vec<Identifier>,
    ) -> Result<SymbolUID, SymbolError> {
        let mut current_module = module;
        // NOTE: The first step is allowed to use private imports
        let mut is_first = true;
        for node in path {
            let mut found = false;
            for import in self.imports.get(&current_module).unwrap() {
                if !is_first && !import.is_public {
                    continue;
                }
                match &import.alias {
                    Some(alias) if alias == node => {
                        found = true;
                        current_module = import.module;
                        break;
                    }
                    _ => {}
                }
            }
            if !found {
                return Err(SymbolError::ModuleNotFoundWithPath(path.clone()));
            }
            is_first = false;
        }
        match self.get_symbol_uid(&current_module, name) {
            Some(id) if self.is_public(&id) => Ok(id),
            Some(id) => Err(SymbolError::SymbolIsPrivate(name.to_string())),
            _ => Err(SymbolError::SymbolNotFound(name.to_string())),
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
        let mut is_private = false;
        let mut symbol = None;
        let mut symbol_origin = Vec::new();
        for import in self.imports.get(&module).unwrap() {
            // NOTE: If the import has an alias, we would only access it through a path
            if import.alias.is_some() {
                continue;
            }
            if let Some(id) = self.get_symbol_uid(&import.module, name) {
                if self.is_public(&id) {
                    is_private = false;
                    symbol = Some(id);
                    symbol_origin.push(import.module);
                } else if symbol.is_none() {
                    // NOTE: This can only find the first matching private symbol
                    // Any subsequent symbol will be counted towards public ones
                    // This will let me report a SymbolIsPrivate Error
                    is_private = true;
                    symbol = Some(id);
                }
            }
        }
        if symbol_origin.len() > 1 {
            return Err(SymbolError::MultipleSymbolFound(
                name.to_string(),
                symbol_origin,
            ));
        }
        if is_private {
            return Err(SymbolError::SymbolIsPrivate(name.to_string()));
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

    pub fn get_stage(&mut self, uid: &SymbolUID) -> SymbolStage {
        if let Some(symbol) = self.symbols.get(uid) {
            symbol.stage
        } else {
            panic!("Symbol uid {uid} does not have a symbol!")
        }
    }

    pub fn set_extern(&mut self, uid: &SymbolUID) {
        if let Some(symbol) = self.symbols.get_mut(uid) {
            symbol.is_extern = true;
        } else {
            panic!("Symbol uid {uid} does not have a symbol!")
        }
    }
    pub fn set_public(&mut self, uid: &SymbolUID) {
        if let Some(symbol) = self.symbols.get_mut(uid) {
            symbol.is_public = true;
        } else {
            panic!("Symbol uid {uid} does not have a symbol!")
        }
    }
}
