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

pub struct TypecheckContext<'a, 'b: 'a> {
    pub symbol_table: &'b mut SymbolTable,
    pub ast_module: &'b AstModule,
    pub module: &'a mut Module,
    pub module_id: ModuleUID,
    pub bindings: TypeBinding,
    pub prototypes: HashMap<String, Rc<Prototype>>,
    pub prototype_opt: Option<Rc<Prototype>>,
    pub target_type: Option<TypeIdent>,
    pub is_logging: bool,
    pub loop_depth: usize,
}

impl<'a, 'b: 'a> TypecheckContext<'a, 'b> {
    pub fn new(
        symbol_table: &'b mut SymbolTable,
        module_id: ModuleUID,
        ast_module: &'b AstModule,
        module: &'a mut Module,
    ) -> Self {
        Self {
            is_logging: false,
            ast_module,
            module,
            module_id,
            symbol_table,
            bindings: TypeBinding::new(),
            prototypes: HashMap::new(),
            prototype_opt: None,
            target_type: None,
            loop_depth: 0,
        }
    }

    pub fn is_inside_loop(&self) -> bool {
        self.loop_depth > 0
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

pub fn resolve_identifier(
    context: &TypecheckContext,
    identifier: &Identifier,
    span: &Span,
) -> TypeResult<SymbolUID> {
    match context
        .symbol_table
        .resolve_identifier(context.module_id, identifier)
    {
        Ok(id) => Ok(id),
        Err(err) => Err(TypecheckError::new(
            TypecheckErrorKind::SymbolError(err),
            span.clone(),
        )),
    }
}
