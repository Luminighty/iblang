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
    pub path_stack: Vec<Identifier>,
}

impl<'a> TypecheckContext<'a> {
    pub fn new(
        symbol_table: &'a mut SymbolTable,
        modules: &'a mut HashMap<ModuleUID, Module>,
    ) -> Self {
        Self {
            symbol_table,
            modules,
            path_stack: Vec::new(),
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
    context: &mut TypecheckContext,
    module_id: &ModuleUID,
    identifier: &Identifier,
    span: &Span,
) -> TypeResult<SymbolUID> {
    if context.path_stack.len() == 0 {
        match context
            .symbol_table
            .resolve_identifier(*module_id, identifier)
        {
            Ok(id) => Ok(id),
            Err(err) => Err(TypecheckError::new(
                TypecheckErrorKind::SymbolError(err),
                *module_id,
                span.clone(),
            )),
        }
    } else {
        let res = match context.symbol_table.resolve_identifier_by_path(
            *module_id,
            identifier,
            &context.path_stack,
        ) {
            Ok(id) => Ok(id),
            Err(err) => Err(TypecheckError::new(
                TypecheckErrorKind::SymbolError(err),
                *module_id,
                span.clone(),
            )),
        };
        context.path_stack.clear();
        res
    }
}
