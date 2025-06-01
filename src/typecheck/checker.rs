use crate::ast::AstModule;
use std::collections::HashMap;

use super::{function::Prototype, FlowType, TypeBinding, TypeIdent};

pub struct TypecheckContext<'a> {
    pub module: &'a AstModule,
    pub bindings: TypeBinding,
    pub prototypes: HashMap<String, Prototype>,
    pub prototype_opt: Option<Prototype>,
    pub target_type: Option<TypeIdent>,
}

impl<'a> TypecheckContext<'a> {
    pub fn new(module: &'a AstModule) -> Self {
        Self {
            module,
            bindings: TypeBinding::new(),
            prototypes: HashMap::new(),
            prototype_opt: None,
            target_type: None,
        }
    }

    pub fn return_type(&self) -> Result<FlowType, ()> {
        match &self.prototype_opt {
            Some(proto) => Ok(proto.return_type.clone()),
            _ => Err(()),
        }
    }
}


#[derive(Debug, Copy, Clone)]
pub struct TypecheckMode {
    pub lvalue: bool,
}

impl TypecheckMode {
    pub fn new() -> Self {
        Self { lvalue: false }
    }

    pub fn with_lvalue(&self) -> Self {
        let mut v = self.clone();
        v.lvalue = true;
        v
    }
}

