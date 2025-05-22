use inkwell::context::Context;

use crate::ast::Module;

mod compiler;
mod error;
mod expr;
mod statement;
mod binary;
mod unary;
mod call;
mod literal;
mod typedvalue;
mod bindings;
mod declaration;

pub type CompileResult<T> = Result<T, error::CompilerError>;

pub fn compile_module<'ctx>(module: &Module, context: &'ctx Context) -> CompileResult<()> {
    let mut comp = compiler::Compiler::new(&module.name, context);

    for func in &module.functions {
        comp.compile_func(module, &func)?;
    }

    Ok(())
}
