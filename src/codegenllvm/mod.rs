use error::CompilerError;
use inkwell::{OptimizationLevel, context::Context, module::Module as InkwellModule};

use crate::{args::CompilerArgs, typecheck::prelude::*, utils::FileMeta};

mod binary;
mod bindings;
mod compiler;
mod declaration;
mod error;
mod expr;
mod literal;
mod statement;
mod typedvalue;
mod unary;
mod utils;

#[macro_use]
pub mod macros;

pub type CompileResult<T> = Result<T, error::CompilerError>;

pub fn compile_module<'ctx>(
    module: &Module,
    context: &'ctx Context,
) -> CompileResult<InkwellModule<'ctx>> {
    let mut comp = compiler::Compiler::new(&module.name, context);

    for ext in &module.externs {
        comp.compile_extern(module, &ext)?;
    }

    for func in &module.functions {
        comp.compile_proto(module, &func.prototype)?;
    }
    for func in &module.functions {
        comp.compile_func(module, &func)?;
    }

    Ok(comp.module)
}

pub fn run_codegen(module: &Module, context: &Context, meta: &FileMeta, args: CompilerArgs) {
    let inkwell_module = match compile_module(&module, &context) {
        Ok(module) => module,
        Err(err) => {
            print_errors(&err, meta);
            return;
        }
    };
    if args.print_codegen {
        inkwell_module.print_to_stderr();
    }
    if args.should_run_jit() {
        run_jit(&inkwell_module);
    }
}

fn print_errors(error: &CompilerError, meta: &FileMeta) {
    let mut errlock = std::io::stderr();
    //for error in errors {
    error.write(&mut errlock, meta).expect("Uh oh.");
    //}
}

fn run_jit(module: &InkwellModule) {
    let ee = module
        .create_jit_execution_engine(OptimizationLevel::None)
        .unwrap();

    let fn_name = "main";
    let maybe_fn = unsafe { ee.get_function::<unsafe extern "C" fn()>(fn_name) };
    let compiled_fn = match maybe_fn {
        Ok(f) => f,
        Err(err) => {
            println!("!> Error during execution: {:?}", err);
            return;
        }
    };
    unsafe {
        compiled_fn.call();
    }
}
