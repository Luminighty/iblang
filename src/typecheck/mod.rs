use std::process::exit;

pub mod atomic;
mod typeident;

pub use error::TypecheckError;
use function::typecheck_functions;
use module::Module;
use std::collections::HashMap;
use type_struct::typecheck_structdefs;
pub use typeident::*;

use crate::{
    ast::prelude::*,
    symbol_resolver::{ModuleUID, SymbolTable},
    typecheck::{
        checker::TypecheckContext, function::typecheck_prototypes, type_enum::typecheck_enumdefs,
        type_union::typecheck_uniondefs,
    },
    utils::{Bindings, FileMeta},
};

pub mod binary;
pub mod checker;
pub mod const_eval;
pub mod error;
pub mod expr;
pub mod expr_array;
pub mod expr_object;
pub mod expr_struct;
pub mod expr_union;
pub mod extrn;
pub mod function;
pub mod global;
pub mod module;
pub mod prelude;
pub mod statement;
pub mod type_enum;
pub mod type_struct;
pub mod type_union;
pub mod unary;

#[derive(Debug)]
pub struct VarBinding {
    pub ty: TypeIdent,
    pub mutable: bool,
}
impl VarBinding {
    pub fn new(ty: TypeIdent, mutable: bool) -> Self {
        Self { ty, mutable }
    }
}

pub type TypeResult<T> = Result<T, TypecheckError>;
pub type TypeBinding = Bindings<VarBinding>;

pub fn print_errors(
    symbol_table: &SymbolTable,
    errors: &Vec<TypecheckError>,
    metas: &HashMap<ModuleUID, FileMeta>,
) {
    let mut errlock = std::io::stderr();
    for error in errors {
        error
            .write(
                &mut errlock,
                symbol_table,
                metas.get(&error.module).unwrap(),
            )
            .expect("Uh oh.");
    }
}

pub fn run_typechecker(
    symbol_table: &mut SymbolTable,
    ast_modules: &HashMap<ModuleUID, AstModule>,
    metas: &HashMap<ModuleUID, FileMeta>,
    print_typecheck: bool,
) -> HashMap<ModuleUID, Module> {
    let mut modules = HashMap::with_capacity(ast_modules.len());
    for (module_id, ast_module) in ast_modules {
        modules.insert(*module_id, Module::new(ast_module.name.clone(), *module_id));
    }

    let mut errors = Vec::new();

    let mut context =
        TypecheckContext::new(symbol_table, &mut modules).with_logging(print_typecheck);

    extrn::typecheck_externs(&mut context, ast_modules, &mut errors);
    typecheck_structdefs(&mut context, ast_modules, &mut errors);
    typecheck_uniondefs(&mut context, ast_modules, &mut errors);
    typecheck_enumdefs(&mut context, ast_modules, &mut errors);
    typecheck_prototypes(&mut context, ast_modules, &mut errors);

    global::typecheck_globals(&mut context, ast_modules, &mut errors);

    if errors.len() > 0 {
        print_errors(symbol_table, &errors, metas);
        exit(1);
    }

    typecheck_functions(&mut context, ast_modules, &mut errors);

    if errors.len() > 0 {
        print_errors(symbol_table, &errors, metas);
        exit(1);
    }

    modules
}
