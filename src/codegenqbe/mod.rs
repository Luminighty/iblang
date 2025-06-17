use crate::{args::CompilerArgs, typecheck::module::Module, utils::FileMeta};

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

fn compile_module() {}

pub fn run_codegen(module: &Module, meta: &FileMeta, args: CompilerArgs) {}
