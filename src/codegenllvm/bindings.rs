use inkwell::values::PointerValue;

use crate::{typecheck::TypeIdent, utils::Bindings};

use super::expr::CompiledExpr;

#[derive(Debug, Clone)]
pub struct VariableBinding<'ctx> {
    pub alloca: PointerValue<'ctx>,
    pub typeident: TypeIdent,
}

impl<'ctx> VariableBinding<'ctx> {
    pub fn new(alloca: PointerValue<'ctx>, typeident: TypeIdent) -> Self {
        Self { alloca, typeident }
    }
}

impl<'ctx> From<VariableBinding<'ctx>> for CompiledExpr<'ctx> {
    fn from(value: VariableBinding<'ctx>) -> Self {
        CompiledExpr::Variable(value)
    }
}

pub type VariableBindings<'ctx> = Bindings<VariableBinding<'ctx>>;

