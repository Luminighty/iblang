use std::rc::Rc;

use crate::{
    codegenqbe::{
        expr::{compile_expr, unwrap_value},
        statement::{alloc_type, is_type_uses_target_alloca},
    },
    symbol_resolver::Symbol,
    typecheck::{
        TypeIdent, expr::Expr, module::Module, type_struct::StructDef, type_union::UnionDef,
    },
};

use super::{CompilerResult, compiler::CompilerContext, expr::CompileExprResult};

#[allow(unused)]
pub fn compile_union_def(
    context: &mut CompilerContext,
    module: &Module,
    strct: &StructDef,
) -> CompilerResult<()> {
    //todo!()
    Ok(())
}

pub fn compile_union_init(
    context: &mut CompilerContext,
    module: &Module,
    field_key: &String,
    value: &Expr,
    ty: &TypeIdent,
) -> CompileExprResult {
    let alloca = if let Some(alloca) = context.target_alloca() {
        alloca.clone()
    } else {
        alloc_type(context, module, ty, "union")?.into()
    };

    let union_symbol: &Symbol = match ty {
        TypeIdent::Union(uid) => context
            .symbol_table
            .get_symbol(uid)
            .expect("Symbol not found"),
        _ => panic!("Non union type was passed to union_init {ty}"),
    };
    let union_def: Rc<UnionDef> = union_symbol.deep_union()?;
    let expr_span = value.span;
    let elem_ty = union_def.get_field_type(field_key).unwrap();
    // let ty = unwrap_typeident(module.id, expr_type(value), expr_span).unwrap();

    if is_type_uses_target_alloca(&elem_ty) {
        context.target_alloca_push(alloca.into());
        compile_expr(context, module, value)?;
        context.target_alloca_pop();
    } else {
        let expr = compile_expr(context, module, value)?;
        let expr = unwrap_value(expr, expr_span)?;

        context.qbe.store(elem_ty, &expr, &alloca)?;
    }

    Ok(alloca.into())
}

pub fn compile_field_lookup(
    context: &mut CompilerContext,
    module: &Module,
    obj: &Expr,
    _field: &String,
    _ty: &TypeIdent,
    _union_ty: &TypeIdent,
) -> CompileExprResult {
    let obj_span = obj.span;
    let obj = compile_expr(context, module, obj)?;
    let obj = unwrap_value(obj, obj_span)?;
    Ok(obj.into())
}
