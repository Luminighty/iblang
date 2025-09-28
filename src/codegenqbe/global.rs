use crate::{
    ast::prelude::Literal,
    codegenqbe::{
        bindings::VariableBinding,
        error::CompilerError,
        expr::{CompileExprResult, CompiledExpr, typeident_into_abity},
        qbe::{BaseTy, DataBuilder, FunctionBuilder, QbeDataField},
        statement::{CompiledStatement, compile_statement},
    },
    typecheck::{
        FlowType, TypeIdent,
        const_eval::ConstExpr,
        module::{Global, Module},
        prelude::{Function, Prototype},
    },
};

use super::{CompilerResult, compiler::CompilerContext, statement::alloc_type};

fn compile_const_expr_data(builder: &mut DataBuilder, e: &ConstExpr) {
    use BaseTy::*;
    match e {
        ConstExpr::Literal(literal) => match literal {
            Literal::Number(v) => builder.push((W, *v)),
            Literal::Bool(v) => builder.push((W, *v as i64)),
            Literal::Char(v) => builder.push((W, *v as i64)),
            Literal::Float(v) => builder.push((W, *v)),
        },
    }
}

pub fn compile_global(context: &mut CompilerContext, global: &Global) -> CompilerResult<()> {
    let mut builder = DataBuilder::new(context.qbe.create_global(&global.name));
    compile_const_expr_data(&mut builder, &global.value);

    let qbe_global = builder.build(&mut context.qbe)?;

    context.globals.insert(global.name.to_string(), qbe_global);

    Ok(())
}

pub fn compile_global_lookup(
    context: &mut CompilerContext,
    _module: &Module,
    var: &str,
    _ty: &TypeIdent,
) -> CompileExprResult {
    if let Some(b) = context.globals.get(var) {
        Ok(CompiledExpr::Global(b.clone()))
    } else {
        Err(CompilerError::UndefinedVariable {
            var: var.to_owned(),
        })
    }
}
