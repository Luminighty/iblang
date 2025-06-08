use inkwell::values::PointerValue;

use crate::{typecheck::TypeIdent, utils::Bindings};

use super::{expr::CompiledExpr, typedvalue::TypedValue};

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
        CompiledExpr::Value(TypedValue::new(
            value.alloca.into(),
            *Box::new(value.typeident),
        ))
    }
}

pub type VariableBindings<'ctx> = Bindings<VariableBinding<'ctx>>;
