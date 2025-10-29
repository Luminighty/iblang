use std::{any::Any, ops::Deref};

use crate::{
    codegenqbe::{
        expr::{compile_expr, unwrap_value},
        statement::alloc_type_n,
    },
    typecheck::{
        TypeIdent,
        expr::{Expr, expr_type, unwrap_typeident},
        module::Module,
    },
};

use super::{
    compiler::CompilerContext,
    expr::CompileExprResult,
    qbe::BaseTy,
    statement::{alloc_type, is_type_uses_target_alloca},
};

pub fn compile_array_init(
    context: &mut CompilerContext,
    module: &Module,
    exprs: &Vec<Expr>,
    ty: &TypeIdent,
) -> CompileExprResult {
    let alloca = if let Some(alloca) = context.target_alloca() {
        alloca.clone()
    } else {
        alloc_type(context, module, ty, "array")?.into()
    };

    let elem_ty = match ty.clone() {
        TypeIdent::Array(ty, _len) => ty,
        TypeIdent::Ref(ty) => match *ty {
            TypeIdent::Array(ty, _) => ty,
            _ => ty,
        },
        TypeIdent::Atomic(_) | TypeIdent::Struct(_) => {
            panic!("initializing array, but type was not array!")
        }
    };
    let (elem_size, _) = module.type_size_and_align(&elem_ty, context.symbol_table);

    for (i, expr) in exprs.iter().enumerate() {
        let offset = elem_size * i;
        let memory = context
            .qbe
            .binary(BaseTy::L, "add", &alloca, offset, &format!("arr_{i}"))?;

        let expr_span = expr.span;
        let ty = unwrap_typeident(expr_type(&expr), expr_span).unwrap();
        if is_type_uses_target_alloca(&elem_ty) {
            context.target_alloca_push(memory.into());
            let expr = compile_expr(context, module, expr)?;
            let expr = unwrap_value(expr, expr_span)?;
            context.target_alloca_pop();
        } else {
            let expr = compile_expr(context, module, expr)?;
            let expr = unwrap_value(expr, expr_span)?;

            context.qbe.store(elem_ty.deref(), &expr, &memory)?;
        }
    }

    Ok(alloca.into())
}

pub fn compile_array_index(
    context: &mut CompilerContext,
    module: &Module,
    expr: &Expr,
    index: &Expr,
    ty: &TypeIdent,
) -> CompileExprResult {
    let (size, _) = module.type_size_and_align(&ty, context.symbol_table);

    let expr_span = expr.span;
    let expr = compile_expr(context, module, expr)?;
    let expr = unwrap_value(expr, expr_span)?;

    let index_span = index.span;
    let index = compile_expr(context, module, index)?;
    let index = unwrap_value(index, index_span)?;

    let ptr = BaseTy::L;

    let offset = context.qbe.binary(ptr, "mul", &index, size, "arr_offset")?;
    let res = context
        .qbe
        .binary(ptr, "add", &expr, &offset, "arr_index")?;
    Ok(res.into())
}
