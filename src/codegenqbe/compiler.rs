use std::{collections::HashMap, fs::File};

use crate::{
    ast::Identifier,
    codegenqbe::{CompilerResult, expr::QbeValue, qbe::Block},
    symbol_resolver::{SymbolTable, SymbolUID},
    typecheck::{FlowType, prelude::Prototype},
};

use super::{
    bindings::VariableBindings,
    qbe::{Global, Qbe, Temp, TyIdent},
};

pub struct LoopContext {
    pub block_continue: Block,
    pub block_break: Block,
    pub has_break: bool,
}

pub struct CompilerContext<'a> {
    pub log_enabled: bool,
    pub qbe: Qbe<File>,
    pub symbol_table: &'a SymbolTable,
    pub bindings: VariableBindings,
    pub globals: HashMap<SymbolUID, Global>,
    pub return_type_opt: Option<FlowType>,
    pub struct_types: HashMap<String, TyIdent>,
    pub functions: HashMap<SymbolUID, Global>,
    pub target_allocas: Vec<QbeValue>,
    pub return_alloca: Option<Temp>,
    pub loop_contextes: Vec<LoopContext>,
}

impl<'a> CompilerContext<'a> {
    pub fn new(qbe: Qbe<File>, symbol_table: &'a SymbolTable, log_enabled: bool) -> Self {
        let bindings = VariableBindings::new();
        Self {
            symbol_table,
            log_enabled,
            qbe,
            bindings,
            return_type_opt: None,
            struct_types: HashMap::new(),
            functions: HashMap::new(),
            globals: HashMap::new(),
            target_allocas: Vec::new(),
            return_alloca: None,
            loop_contextes: Vec::new(),
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
        let proto = fn_symbol.deep_proto()?;
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
        })
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
