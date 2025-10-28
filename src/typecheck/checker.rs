use crate::{
    ast::{AstModule, Identifier},
    symbol_resolver::{ModuleUID, SymbolTable, SymbolUID},
    typecheck::{TypeResult, TypecheckError, error::TypecheckErrorKind},
    utils::Span,
};
use std::collections::HashMap;
use std::rc::Rc;

use super::{
    FlowType, TypeBinding, TypeIdent, expr::ValueKind, function::Prototype, module::Module,
};

pub struct TypecheckContext<'a> {
    pub symbol_table: &'a mut SymbolTable,
    pub modules: &'a mut HashMap<ModuleUID, Module>,
    pub is_logging: bool,
}

impl<'a> TypecheckContext<'a> {
    pub fn new(
        symbol_table: &'a mut SymbolTable,
        modules: &'a mut HashMap<ModuleUID, Module>,
    ) -> Self {
        Self {
            symbol_table,
            modules,
            is_logging: false,
        }
    }

    pub fn with_logging(mut self, enabled: bool) -> Self {
        self.is_logging = enabled;
        self
    }
}

pub struct TypecheckFuncContext {
    pub module_id: ModuleUID,
    pub bindings: TypeBinding,
    pub prototype_opt: Option<Rc<Prototype>>,
    pub target_type: Option<TypeIdent>,
    pub is_logging: bool,
    pub loop_depth: usize,
}

impl TypecheckFuncContext {
    pub fn new(module_id: ModuleUID) -> Self {
        Self {
            is_logging: false,
            module_id,
            bindings: TypeBinding::new(),
            prototype_opt: None,
            target_type: None,
            loop_depth: 0,
        }
    }

    pub fn is_inside_loop(&self) -> bool {
        self.loop_depth > 0
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

pub fn resolve_identifier(
    symbol_table: &SymbolTable,
    module_id: &ModuleUID,
    identifier: &Identifier,
    span: &Span,
) -> TypeResult<SymbolUID> {
    match symbol_table.resolve_identifier(*module_id, identifier) {
        Ok(id) => Ok(id),
        Err(err) => Err(TypecheckError::new(
            TypecheckErrorKind::SymbolError(err),
            span.clone(),
        )),
    }
}
