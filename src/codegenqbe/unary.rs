use std::ops::Deref;

use crate::{
    ast::prelude::UnaryArith,
    typecheck::{
        CastMethod, TypeIdent,
        expr::{Expr, ValueKind},
        module::Module,
    },
};

use super::{
    compiler::CompilerContext,
    expr::{CompileExprResult, compile_expr, unwrap_value},
    qbe::{BaseTy, LoadTy},
};

pub fn compile_unary(
    context: &mut CompilerContext,
    module: &Module,
    expr: &Expr,
    op: &UnaryArith,
    ty: &TypeIdent,
) -> CompileExprResult {
    let expr_span = expr.span;
    let expr = compile_expr(context, module, expr)?;
    let expr = unwrap_value(expr, expr_span)?;

    let ty = ty.try_into()?;
    match op {
        UnaryArith::POS => Ok(expr.into()),
        UnaryArith::NEG => {
            let val = context.qbe.unary(ty, "neg", &expr, "tempneg")?;
            Ok(val.into())
        }
        UnaryArith::NOT => {
            let val = context.qbe.binary(ty, "xor", &expr, 1, "tempneg")?;
            Ok(val.into())
        }
    }
}

pub fn compile_deref(
    context: &mut CompilerContext,
    module: &Module,
    expr: &Expr,
    ty: &TypeIdent,
    value_kind: ValueKind,
) -> CompileExprResult {
    let expr_span = expr.span;
    let expr = compile_expr(context, module, expr)?;
    let expr = unwrap_value(expr, expr_span)?;

    context.qbe.comment(&format!("compile_deref"));
    // match value_kind {
    //     ValueKind::LValue => Ok(expr.into()),
    //     ValueKind::RValue => {
    //         let ty = ty.try_into()?;
    //         let deref = context.qbe.load(ty, &expr, "deref")?;
    //         Ok(deref.into())
    //     }
    // }
    let ty = match value_kind {
        ValueKind::RValue => ty.try_into()?,
        ValueKind::LValue => LoadTy::BaseTy(BaseTy::L),
    };
    let deref = context.qbe.load(ty, &expr, "deref")?;
    Ok(deref.into())
}

pub fn compile_ref(
    context: &mut CompilerContext,
    module: &Module,
    expr: &Expr,
    _ty: &TypeIdent,
) -> CompileExprResult {
    // context.qbe.comment("compile_ref");
    let expr_span = expr.span;
    let expr = compile_expr(context, module, expr)?;
    let expr = unwrap_value(expr, expr_span)?;

    Ok(expr.into())
}

pub fn compile_cast(
    context: &mut CompilerContext,
    module: &Module,
    expr: &Expr,
    method: &CastMethod,
    target: &TypeIdent,
) -> CompileExprResult {
    match method {
        CastMethod::Keep => compile_expr(context, module, expr),
        CastMethod::ArrayDecay => compile_expr(context, module, expr),
        CastMethod::Truncate | CastMethod::Extend => {
            let expr_span = expr.span;
            let expr = compile_expr(context, module, expr)?;
            let expr = unwrap_value(expr, expr_span)?;
            let ty = target.try_into()?;

            let value = context.qbe.unary(ty, "copy", &expr, "cast")?;

            Ok(value.into())
        }
        CastMethod::FloatToInt | CastMethod::IntToFloat => {
            let expr_span = expr.span;
            let expr = compile_expr(context, module, expr)?;
            let expr = unwrap_value(expr, expr_span)?;
            let ty = target.try_into()?;

            let value = context.qbe.unary(ty, "cast", &expr, "cast")?;

            Ok(value.into())
        }
        CastMethod::Deref => todo!(),
    }
}
