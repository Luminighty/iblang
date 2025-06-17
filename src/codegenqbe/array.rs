use crate::typecheck::{TypeIdent, expr::Expr, module::Module};

use super::{compiler::CompilerContext, expr::CompileExprResult};

pub fn compile_array_init(
    context: &mut CompilerContext,
    module: &Module,
    values: &Vec<Expr>,
    ty: &TypeIdent,
) -> CompileExprResult {
    todo!()
}

pub fn compile_array_index(
    context: &mut CompilerContext,
    module: &Module,
    expr: &Expr,
    index: &Expr,
    ty: &TypeIdent,
) -> CompileExprResult {
    todo!()
}
