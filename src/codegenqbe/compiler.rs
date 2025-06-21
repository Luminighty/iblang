use std::{collections::HashMap, fs::File};

use crate::{ast::Identifier, typecheck::FlowType};

use super::{
    bindings::VariableBindings,
    qbe::{Global, Qbe, TyIdent},
};

pub struct CompilerContext {
    pub log_enabled: bool,
    pub qbe: Qbe<File>,
    pub bindings: VariableBindings,
    pub return_type_opt: Option<FlowType>,
    pub struct_types: HashMap<String, TyIdent>,
    pub functions: HashMap<Identifier, Global>,
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
        }
    }
}
