use std::{any::Any, ops::Deref};

use crate::{
    codegenqbe::{
        expr::{CompiledExpr, compile_expr, unwrap_value},
        qbe::BaseTy,
        statement::{alloc_type, is_type_uses_target_alloca},
    },
    typecheck::{
        TypeIdent,
        expr::{Expr, expr_type, unwrap_typeident},
        module::Module,
        type_struct::StructDef,
    },
};

use super::{CompilerResult, compiler::CompilerContext, expr::CompileExprResult};

pub fn compile_struct_def(
    context: &mut CompilerContext,
    module: &Module,
    strct: &StructDef,
) -> CompilerResult<()> {
    //todo!()
    Ok(())
}

pub fn compile_struct_init(
    context: &mut CompilerContext,
    module: &Module,
    values: &Vec<(String, Expr)>,
    ty: &TypeIdent,
) -> CompileExprResult {
    let alloca = if let Some(alloca) = context.target_alloca() {
        alloca.clone()
    } else {
        alloc_type(context, module, ty, "struct")?
    };

    let struct_def = match ty {
        TypeIdent::Struct(ident) => module.get_struct(ident),
        _ => panic!("Non struct type was passed to struct_init"),
    };
    let struct_def = match struct_def {
        Some(s) => s,
        _ => panic!("Struct not found!"),
    };

    for (i, (key, expr)) in values.iter().enumerate() {
        let offset = struct_def.field_offsets[i];
        let elem_ty = struct_def.get_field_type(key).unwrap();
        let memory =
            context
                .qbe
                .binary(BaseTy::L, "add", &alloca, offset, &format!("struct_{key}"))?;

        let expr_span = expr.span;
        let ty = unwrap_typeident(expr_type(&expr), expr_span).unwrap();
        if is_type_uses_target_alloca(&elem_ty) {
            context.target_alloca_push(memory);
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

pub fn compile_field_lookup(
    context: &mut CompilerContext,
    module: &Module,
    obj: &Expr,
    field: &String,
    ty: &TypeIdent,
    struct_ty: &TypeIdent,
) -> CompileExprResult {
    let obj_span = obj.span;
    let obj = compile_expr(context, module, obj)?;
    let obj = unwrap_value(obj, obj_span)?;

    let struct_def = match struct_ty {
        TypeIdent::Struct(ident) => module.get_struct(ident).unwrap(),
        _ => panic!("Non struct type was passed to struct_init {struct_ty:?} {obj:?}"),
    };
    let idx = struct_def.get_field_idx(field).unwrap();
    let offset = struct_def.field_offsets[idx];
    let ptr = BaseTy::L;
    let res = context
        .qbe
        .binary(ptr, "add", &obj, offset, &format!("struct_offset_{field}"))?;
    Ok(res.into())
}

pub fn compile_struct_copy(
    context: &mut CompilerContext,
    module: &Module,
    origin: &Expr,
    struct_ty: &TypeIdent,
    name: &str,
) -> CompileExprResult {
    let alloca = alloc_type(context, module, struct_ty, name)?;

    let origin_span = origin.span;
    let origin = compile_expr(context, module, origin)?;
    let origin = unwrap_value(origin, origin_span)?;

    let (size, _) = module.type_size_and_align(struct_ty);
    // NOTE: We might need to call memcpy if the struct is large!
    context.qbe.blit(&origin, &alloca, size)?;

    Ok(alloca.into())
}
