use crate::ast::AstModule;
use std::collections::HashMap;

use super::{function::Prototype, FlowType, TypeBinding};

pub struct TypecheckContext<'a> {
    pub module: &'a AstModule,
    pub bindings: TypeBinding,
    pub prototypes: HashMap<String, Prototype>,
    pub prototype_opt: Option<Prototype>,
}

impl<'a> TypecheckContext<'a> {
    pub fn new(module: &'a AstModule) -> Self {
        Self {
            module,
            bindings: TypeBinding::new(),
            prototypes: HashMap::new(),
            prototype_opt: None,
        }
    }

    pub fn return_type(&self) -> Result<FlowType, ()> {
        match &self.prototype_opt {
            Some(proto) => Ok(proto.return_type.clone()),
            _ => Err(()),
        }
    }
}

