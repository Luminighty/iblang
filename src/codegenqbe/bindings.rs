use crate::{typecheck::TypeIdent, utils::Bindings};

use super::{expr::CompiledExpr, qbe::Temp};

#[derive(Debug, Clone)]
pub struct VariableBinding {
    pub temp: Temp,
    pub typeident: TypeIdent,
}

impl<'ctx> VariableBinding {
    pub fn new(temp: Temp, typeident: TypeIdent) -> Self {
        Self { temp, typeident }
    }
}

impl<'ctx> From<VariableBinding> for CompiledExpr {
    fn from(value: VariableBinding) -> Self {
        CompiledExpr::Temp(value.temp)
    }
}

pub type VariableBindings = Bindings<VariableBinding>;
