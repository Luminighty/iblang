use std::process::exit;

pub mod atomic;
mod typeident;

use checker::TypecheckContext;
pub use error::TypecheckError;
use function::{typecheck_externs, typecheck_functions};
use module::Module;
use type_struct::typecheck_structdefs;
pub use typeident::*;

use crate::{
    ast::prelude::*,
    symbol_resolver::{ModuleUID, SymbolTable},
    typecheck::{
        declaration::{typecheck_global, typecheck_globals},
        function::typecheck_functions_definitions,
    },
    utils::{Bindings, FileMeta},
};

pub mod binary;
pub mod checker;
pub mod const_eval;
pub mod declaration;
pub mod error;
pub mod expr;
pub mod expr_array;
pub mod expr_struct;
pub mod function;
pub mod module;
pub mod prelude;
pub mod statement;
pub mod type_struct;
pub mod unary;

pub type TypeResult<T> = Result<T, TypecheckError>;
pub type TypeBinding = Bindings<TypeIdent>;

pub fn run_definitions<'a>(
    symbol_table: &'a mut SymbolTable,
    module_id: ModuleUID,
    ast_module: &'a AstModule,
    print_typecheck: bool,
) -> Result<Module, Vec<TypecheckError>> {
    let mut errors = Vec::new();
    let mut module = Module::new(ast_module.name.to_string());
    let mut context = TypecheckContext::new(symbol_table, module_id, ast_module, &mut module);
    if print_typecheck {
        context.enable_logging();
    }

    context.bindings.start_block();

    typecheck_structdefs(&mut context, ast_module, &mut errors);
    typecheck_externs(&mut context, ast_module, &mut errors);
    typecheck_globals(&mut context, ast_module, &mut errors);
    typecheck_functions_definitions(&mut context, ast_module, &mut errors);

    // TODO: Typecheck global
    context.bindings.end_block();

    if errors.len() > 0 {
        Err(errors)
    } else {
        Ok(module)
    }
}

pub fn run_implementations<'a>(
    symbol_table: &'a mut SymbolTable,
    module_id: ModuleUID,
    ast_module: &'a AstModule,
    print_typecheck: bool,
) -> Result<Module, Vec<TypecheckError>> {
    let mut errors = Vec::new();
    let mut module = Module::new(ast_module.name.to_string());
    let mut context = TypecheckContext::new(symbol_table, module_id, ast_module, &mut module);
    if print_typecheck {
        context.enable_logging();
    }

    context.bindings.start_block();

    typecheck_externs(&mut context, ast_module, &mut errors);
    typecheck_globals(&mut context, ast_module, &mut errors);
    typecheck_functions_definitions(&mut context, ast_module, &mut errors);

    // TODO: Typecheck global
    context.bindings.end_block();

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

pub fn run_typechecker_definitions<'a>(
    symbol_table: &'a mut SymbolTable,
    module_id: ModuleUID,
    module: &'a AstModule,
    meta: &FileMeta,
    print_typecheck: bool,
) -> Module {
    match run_definitions(symbol_table, module_id, module, print_typecheck) {
        Ok(module) => module,
        Err(errors) => {
            print_errors(&errors, meta);
            exit(1);
        }
    }
}
