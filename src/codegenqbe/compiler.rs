use std::{collections::HashMap, fs::File};

use crate::{
    codegenqbe::{
        CompilerResult,
        expr::QbeValue,
        global::{BUILT_IN_GLOBALS, BuiltInGlobal},
        qbe::{Block, DataBuilder, ExtTy},
    },
    symbol_resolver::{SymbolKind, SymbolTable, SymbolUID},
};

use super::{
    bindings::VariableBindings,
    qbe::{Global, Qbe, Temp},
};

pub struct LoopContext {
    pub block_continue: Block,
    pub block_break: Block,
    pub has_break: bool,
    pub has_return: bool,
}

pub struct CompilerContext<'a> {
    #[allow(dead_code)]
    pub log_enabled: bool,
    pub qbe: Qbe<File>,
    pub symbol_table: &'a SymbolTable,
    pub bindings: VariableBindings,
    pub globals: HashMap<SymbolUID, Global>,
    pub functions: HashMap<SymbolUID, Global>,
    pub target_allocas: Vec<QbeValue>,
    pub return_alloca: Option<Temp>,
    pub loop_contextes: Vec<LoopContext>,
    pub built_in_globals: HashMap<BuiltInGlobal, Global>,
}

impl<'a> CompilerContext<'a> {
    pub fn new(qbe: Qbe<File>, symbol_table: &'a SymbolTable, log_enabled: bool) -> Self {
        let bindings = VariableBindings::new();
        let mut context = Self {
            symbol_table,
            log_enabled,
            qbe,
            bindings,
            functions: HashMap::new(),
            globals: HashMap::new(),
            target_allocas: Vec::new(),
            return_alloca: None,
            loop_contextes: Vec::new(),
            built_in_globals: HashMap::new(),
        };
        context.generate_built_in_globals();
        context
    }

    fn generate_built_in_globals(&mut self) {
        for built_in in BUILT_IN_GLOBALS {
            let global = self.qbe.create_global(&"built_in_global", false).unwrap();
            let mut builder = DataBuilder::new(global);
            builder.push(built_in.to_str());
            builder.push((ExtTy::B, 0));
            let global = builder.build(&mut self.qbe).unwrap();
            self.built_in_globals.insert(built_in, global);
        }
    }

    pub fn get_global_or_fn(&mut self, symbol_id: &SymbolUID) -> CompilerResult<Global> {
        let symbol = self
            .symbol_table
            .get_symbol(symbol_id)
            .expect("Symbol not found");
        match symbol.kind {
            SymbolKind::Function => self.get_function(symbol_id),
            SymbolKind::Global => self.get_global(symbol_id),
            other => panic!("Expected function or global, but got {other:?}"),
        }
    }

    pub fn get_global(&mut self, symbol: &SymbolUID) -> CompilerResult<Global> {
        if let Some(global) = self.globals.get(symbol) {
            return Ok(*global);
        }
        let global_symbol = self
            .symbol_table
            .get_symbol(symbol)
            .expect("Symbol not found");
        let name = if global_symbol.is_extern {
            global_symbol.name.clone()
        } else {
            format!("s{symbol}_{}", global_symbol.name)
        };
        // NOTE: Setting "is_extern" true, to enforce unique ids now that we have
        // symbolUIDs. This keeps the identifiers unique
        let ptr = self.qbe.create_global(&name, true).unwrap();
        self.globals.insert(*symbol, ptr.clone());
        Ok(ptr)
    }

    pub fn get_function(&mut self, symbol: &SymbolUID) -> CompilerResult<Global> {
        if let Some(global) = self.functions.get(symbol) {
            return Ok(*global);
        }
        let fn_symbol = self
            .symbol_table
            .get_symbol(symbol)
            .expect("Symbol not found");
        let name = if fn_symbol.is_extern {
            fn_symbol.name.clone()
        } else {
            format!("s{symbol}_{}", fn_symbol.name)
        };
        let _proto = fn_symbol.deep_proto()?;
        // NOTE: Setting "is_extern" true, to enforce unique ids now that we have
        // symbolUIDs. This keeps the identifiers unique
        let ptr = self.qbe.create_global(&name, true).unwrap();
        self.functions.insert(*symbol, ptr.clone());
        Ok(ptr)
    }

    pub fn loop_push(&mut self, block_continue: Block, block_break: Block) {
        self.loop_contextes.push(LoopContext {
            block_continue,
            block_break,
            has_break: false,
            has_return: false,
        })
    }
    pub fn loop_return(&mut self) {
        if let Some(context) = self.loop_contextes.last_mut() {
            context.has_return = true;
        }
    }
    pub fn loop_break(&mut self) {
        if let Some(context) = self.loop_contextes.last_mut() {
            context.has_break = true;
        }
    }

    pub fn loop_pop(&mut self) -> Option<LoopContext> {
        self.loop_contextes.pop()
    }

    pub fn loop_context(&self) -> Option<&LoopContext> {
        self.loop_contextes.last()
    }

    pub fn target_alloca_push(&mut self, alloca: QbeValue) {
        self.target_allocas.push(alloca);
    }

    pub fn target_alloca_pop(&mut self) -> QbeValue {
        self.target_allocas.pop().unwrap()
    }

    pub fn target_alloca(&self) -> Option<&QbeValue> {
        self.target_allocas.last()
    }
}
