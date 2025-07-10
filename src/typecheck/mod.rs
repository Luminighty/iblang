use std::process::exit;

pub mod atomic;
mod typeident;

use checker::TypecheckContext;
use error::TypecheckError;
use function::{typecheck_externs, typecheck_functions};
use module::Module;
use type_struct::typecheck_structdefs;
pub use typeident::*;

use crate::{
    ast::prelude::*,
    utils::{Bindings, FileMeta},
};

pub mod binary;
pub mod checker;
pub mod const_eval;
pub mod declaration;
pub mod error;
pub mod expr;
pub mod function;
pub mod module;
pub mod prelude;
pub mod statement;
pub mod type_struct;
pub mod unary;

pub type TypeResult<T> = Result<T, TypecheckError>;
pub type TypeBinding = Bindings<TypeIdent>;

pub fn run(ast_module: &AstModule) -> Result<Module, Vec<TypecheckError>> {
    let mut errors = Vec::new();
    let mut module = Module::new(ast_module.name.to_string());
    let mut context = TypecheckContext::new(ast_module, &mut module);

    typecheck_externs(&mut context, ast_module, &mut errors);
    typecheck_structdefs(&mut context, ast_module, &mut errors);
    typecheck_functions(&mut context, ast_module, &mut errors);

    // TODO: Typecheck global

    if errors.len() > 0 {
        Err(errors)
    } else {
        Ok(module)
    }
}

pub fn print_errors(errors: &Vec<TypecheckError>, meta: &FileMeta) {
    let mut errlock = std::io::stderr();
    for error in errors {
        error.write(&mut errlock, meta).expect("Uh oh.");
    }
}

pub fn run_typechecker(module: &AstModule, meta: &FileMeta) -> Module {
    match run(module) {
        Ok(module) => module,
        Err(errors) => {
            print_errors(&errors, meta);
            exit(1);
        }
    }
}
