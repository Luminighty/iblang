use std::process::exit;

pub mod atomic;
mod typeident;

use checker::TypecheckContext;
use declaration::{typecheck_extern, typecheck_func, typecheck_proto};
use error::TypecheckError;
use function::{typecheck_externs, typecheck_functions};
use module::Module;
use std::collections::VecDeque;
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

fn run(ast_module: &AstModule) -> Result<Module, Vec<TypecheckError>> {
    let mut errors = Vec::new();
    macro_rules! unwrap {
        ($value: expr) => {
            match $value {
                Ok(val) => val,
                Err(err) => {
                    errors.push(err);
                    continue;
                }
            }
        };
    }

    let mut context = TypecheckContext::new(ast_module);
    let mut module = Module::new(ast_module.name.to_string());

    typecheck_externs(&mut context, ast_module, &mut module, &mut errors);
    typecheck_structdefs(&context, ast_module, &mut module, &mut errors);
    typecheck_functions(&mut context, ast_module, &mut module, &mut errors);

    // TODO: Typecheck global

    let mut prototypes = VecDeque::with_capacity(ast_module.functions.len());
    for func in &ast_module.functions {
        let proto = unwrap!(typecheck_proto(&context, &func.prototype));
        context
            .prototypes
            .insert(proto.identifier.to_string(), proto.clone());
        prototypes.push_back(proto);
    }

    for func in ast_module.functions.iter() {
        let func = unwrap!(typecheck_func(
            &mut context,
            prototypes.pop_front().unwrap(),
            &func
        ));
        module.functions.push(func);
    }

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
