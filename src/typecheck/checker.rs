use crate::ast::AstModule;

use super::TypeBinding;

pub struct TypecheckContext<'a> {
    pub module: &'a AstModule,
    pub bindings: TypeBinding,
}

