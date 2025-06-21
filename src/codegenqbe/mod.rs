use std::fs::File;

use compiler::CompilerContext;
use func::{compile_func, compile_proto};
use qbe::Qbe;
use strcts::compile_struct_def;

use crate::{
    args::CompilerArgs,
    typecheck::{
        module::{self, Module},
        prelude::Extern,
    },
    utils::FileMeta,
};

pub type CompileResult<T> = Result<T, error::CompilerError>;

mod array;
mod binary;
mod bindings;
mod compiler;
mod error;
mod expr;
mod func;
mod literal;
mod qbe;
mod statement;
mod strcts;
mod unary;

fn compile_module(context: &mut CompilerContext, module: &Module) -> CompileResult<()> {
    for strct in &module.struct_defs {
        compile_struct_def(context, module, strct)?;
    }
    for extrn in &module.externs {
        compile_proto(context, &extrn.prototype);
    }
    for func in &module.functions {
        compile_proto(context, &func.prototype);
    }
    for func in &module.functions {
        compile_func(context, module, func);
    }
    Ok(())
}

pub fn run_codegen(module: &Module, meta: &FileMeta, args: CompilerArgs) {
    let file = File::create(format!("./build/{}.ssa", module.name)).unwrap();
    let mut qbe = Qbe::new(file);
    let mut context = CompilerContext::new(qbe, true);

    compile_module(&mut context, module);
}
