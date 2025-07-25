use crate::ast::AstModule;
use std::collections::HashMap;

use super::{
    FlowType, TypeBinding, TypeIdent, expr::ValueKind, function::Prototype, module::Module,
};

pub struct TypecheckContext<'a> {
    pub ast_module: &'a AstModule,
    pub module: &'a mut Module,
    pub bindings: TypeBinding,
    pub prototypes: HashMap<String, Prototype>,
    pub prototype_opt: Option<Prototype>,
    pub target_type: Option<TypeIdent>,
    pub is_logging: bool,
}

impl<'a> TypecheckContext<'a> {
    pub fn new(ast_module: &'a AstModule, module: &'a mut Module) -> Self {
        Self {
            is_logging: false,
            ast_module,
            module,
            bindings: TypeBinding::new(),
            prototypes: HashMap::new(),
            prototype_opt: None,
            target_type: None,
        }
    }

    pub fn enable_logging(&mut self) {
        self.is_logging = true;
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
    pub value_kind: ValueKind,
}

impl TypecheckMode {
    pub fn lvalue() -> Self {
        Self {
            value_kind: ValueKind::LValue,
        }
    }
    pub fn rvalue() -> Self {
        Self {
            value_kind: ValueKind::RValue,
        }
    }
}
