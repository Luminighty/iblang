use std::{collections::HashMap, fs::File};

use crate::{
    ast::Identifier,
    codegenqbe::{expr::QbeValue, qbe::Block},
    typecheck::FlowType,
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

pub struct CompilerContext {
    pub log_enabled: bool,
    pub qbe: Qbe<File>,
    pub bindings: VariableBindings,
    pub globals: HashMap<Identifier, Global>,
    pub return_type_opt: Option<FlowType>,
    pub struct_types: HashMap<String, TyIdent>,
    pub functions: HashMap<Identifier, Global>,
    pub target_allocas: Vec<QbeValue>,
    pub return_alloca: Option<Temp>,
    pub loop_contextes: Vec<LoopContext>,
}

impl CompilerContext {
    pub fn new(qbe: Qbe<File>, log_enabled: bool) -> Self {
        let bindings = VariableBindings::new();
        Self {
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
