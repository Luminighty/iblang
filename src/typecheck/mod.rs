use std::process::exit;

pub mod atomic;
mod types;

use checker::TypecheckContext;
use declaration::{typecheck_extern, typecheck_func, typecheck_proto};
use error::TypecheckError;
use module::Module;
use std::collections::VecDeque;
pub use types::*;

use crate::{ast::prelude::*, utils::{Bindings, FileMeta}};

pub mod expr;
pub mod module;
pub mod statement;
pub mod error;
pub mod checker;
pub mod binary;
pub mod unary;
pub mod function;
pub mod const_eval;
pub mod declaration;
pub mod prelude;

pub type TypeResult<T> = Result<T, TypecheckError>;
pub type TypeBinding = Bindings<TypeIdent>;

fn run(ast_module: &AstModule) -> Result<Module, Vec<TypecheckError>> {
    let mut errors = Vec::new();
    macro_rules! unwrap {
        ($value: expr) => {
            match $value {
                Ok(val) => val,
                Err(err) => { errors.push(err); continue; }
           }
        };
    }

    let mut context = TypecheckContext::new(ast_module);
    let mut module = Module::new(ast_module.name.to_string());

    for extrn in &ast_module.externs {
        let proto = unwrap!(typecheck_proto(&context, &extrn.prototype));
        context.prototypes.insert(proto.identifier.to_string(), proto.clone());

        let extrn = unwrap!(typecheck_extern(&context, proto, extrn));
        module.externs.push(extrn);
    }

    // TODO: Typecheck global

    let mut prototypes = VecDeque::with_capacity(ast_module.functions.len());
    for func in &ast_module.functions {
        let proto = unwrap!(typecheck_proto(&context, &func.prototype));
        context.prototypes.insert(proto.identifier.to_string(), proto.clone());
        prototypes.push_back(proto);
    }

    for func in ast_module.functions.iter() {
        let func = unwrap!(typecheck_func(&mut context, prototypes.pop_front().unwrap(), &func));
        module.functions.push(func);
    }

    Ok(module)
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
