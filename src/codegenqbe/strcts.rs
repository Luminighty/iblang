use crate::typecheck::{TypeIdent, expr::Expr, module::Module, type_struct::StructDef};

use super::{CompileResult, compiler::CompilerContext, expr::CompileExprResult};

pub fn compile_struct_def(
    context: &mut CompilerContext,
    module: &Module,
    strct: &StructDef,
) -> CompileResult<()> {
    //todo!()
    Ok(())
}

pub fn compile_struct_init(
    context: &mut CompilerContext,
    module: &Module,
    values: &Vec<(String, Expr)>,
    ty: &TypeIdent,
) -> CompileExprResult {
    todo!()
}

pub fn compile_field_lookup(
    context: &mut CompilerContext,
    module: &Module,
    obj: &Expr,
    field: &String,
    ty: &TypeIdent,
) -> CompileExprResult {
    todo!()
}
