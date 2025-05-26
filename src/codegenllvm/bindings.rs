use std::collections::HashMap;
use inkwell::values::PointerValue;

use crate::types::TypeIdent;

use super::expr::CompiledExpr;

#[derive(Debug, Copy, Clone)]
pub struct VariableBinding<'ctx> {
    pub alloca: PointerValue<'ctx>,
    pub typeident: TypeIdent,
}

impl<'ctx> From<VariableBinding<'ctx>> for CompiledExpr<'ctx> {
    fn from(value: VariableBinding<'ctx>) -> Self {
        CompiledExpr::Variable(value)
    }
}


pub struct VariableBindings<'ctx> {
    variables: Vec<HashMap<String, VariableBinding<'ctx>>>,
}

impl<'ctx> VariableBindings<'ctx> {
    pub fn new() -> Self {
        Self { variables: vec![] }
    }

    pub fn start_block(&mut self) {
        self.variables.push(HashMap::new());
    }

    pub fn end_block(&mut self) {
        self.variables.pop();
    }

    pub fn insert(&mut self, key: String, alloca: PointerValue<'ctx>, typeident: TypeIdent) {
        let binding = VariableBinding { alloca, typeident };
        self.head_mut().insert(key, binding);
    }

    pub fn get(&self, key: &str) -> Option<&VariableBinding<'ctx>> {
        for var in self.variables.iter().rev() {
            if let Some(var) = var.get(key) {
                return Some(var)
            }
        }
        None
    }

    #[inline]
    fn head_mut(&mut self) -> &mut HashMap<String, VariableBinding<'ctx>> {
        self.variables.last_mut().unwrap()
    }
}
