pub mod atomic;
mod types;

use checker::TypecheckContext;
use declaration::{typecheck_extern, typecheck_func, typecheck_proto};
use error::TypecheckError;
use module::Module;
use std::collections::VecDeque;
pub use types::*;

use crate::{ast::AstModule, utils::{Bindings, FileMeta}};

mod expr;
mod module;
mod statement;
mod error;
mod checker;
mod binary;
mod unary;
mod function;
mod const_eval;
mod declaration;

pub type TypeResult<T> = Result<T, TypecheckError>;
pub type TypeBinding = Bindings<TypeIdent>;


pub fn run_typechecker(ast_module: &AstModule, meta: &FileMeta) -> TypeResult<Module> {
    let mut context = TypecheckContext::new(ast_module);
    let mut module = Module::new(ast_module.name.to_string());

    for extrn in &ast_module.externs {
        let proto = typecheck_proto(&context, &extrn.prototype)?;
        context.prototypes.insert(proto.identifier.to_string(), proto.clone());

        let extrn = typecheck_extern(&context, proto, extrn)?;
        module.externs.push(extrn);
    }

    // TODO: Typecheck global

    let mut prototypes = VecDeque::with_capacity(ast_module.functions.len());
    for func in &ast_module.functions {
        let proto = typecheck_proto(&context, &func.prototype)?;
        context.prototypes.insert(proto.identifier.to_string(), proto.clone());
        prototypes.push_back(proto);
    }

    for func in ast_module.functions.iter() {
        let func = typecheck_func(&mut context, prototypes.pop_front().unwrap(), &func)?;
        module.functions.push(func);
    }

    Ok(module)
}

