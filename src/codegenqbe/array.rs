use std::ops::Deref;

use crate::{
    codegenqbe::{
        expr::{compile_expr, unwrap_value},
        statement::alloc_type_n,
    },
    typecheck::{TypeIdent, expr::Expr, module::Module},
};

use super::{compiler::CompilerContext, expr::CompileExprResult, qbe::BaseTy};

pub fn compile_array_init(
    context: &mut CompilerContext,
    module: &Module,
    exprs: &Vec<Expr>,
    ty: &TypeIdent,
) -> CompileExprResult {
    let alloca = alloc_type_n(context, module, ty, exprs.len(), "array")?;
    let (size, _) = module.type_size_and_align(ty);

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
    let elem_ty = *elem_ty;

    for (i, expr) in exprs.iter().enumerate() {
        let expr_span = expr.span;
        let expr = compile_expr(context, module, expr)?;
        let expr = unwrap_value(expr, expr_span)?;

        let offset = size * i;
        let memory = context
            .qbe
            .binary(BaseTy::L, "add", &alloca, offset, &format!("arr_{i}"))?;

        context.qbe.store(&elem_ty, &expr, &memory)?;
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
    // let elem_ty = match ty.clone() {
    //     TypeIdent::Array(ty, _len) => ty,
    //     TypeIdent::Ref(ty) => match *ty {
    //         TypeIdent::Array(ty, _) => ty,
    //         _ => ty,
    //     },
    //     TypeIdent::Atomic(_) | TypeIdent::Struct(_) => {
    //         panic!("indexing array, but type was not array!")
    //     }
    // };

    let (size, _) = module.type_size_and_align(&ty);

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
