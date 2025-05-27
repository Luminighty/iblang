use inkwell::values::PointerValue;

use crate::utils::Bindings;

use super::expr::CompiledExpr;

#[derive(Debug, Copy, Clone)]
pub struct VariableBinding<'ctx> {
    pub alloca: PointerValue<'ctx>,
}

impl<'ctx> From<VariableBinding<'ctx>> for CompiledExpr<'ctx> {
    fn from(value: VariableBinding<'ctx>) -> Self {
        CompiledExpr::Variable(value)
    }
}

pub type VariableBindings<'ctx> = Bindings<VariableBinding<'ctx>>;

