use crate::{
    ast::prelude::{BinaryArith, BinaryPred},
    codegenqbe::{
        expr::{self, compile_expr},
        qbe::{ExtTy, Temp},
    },
    typecheck::{TypeIdent, expr::Expr, module::Module},
};

use super::{
    compiler::CompilerContext,
    expr::{CompileExprResult, unwrap_value},
    qbe::BaseTy,
};

pub fn compile_binary_arith(
    context: &mut CompilerContext,
    module: &Module,
    lhs: &Expr,
    rhs: &Expr,
    op: &BinaryArith,
    ty: &TypeIdent,
) -> CompileExprResult {
    let lhs_span = lhs.span;
    let lhs = compile_expr(context, module, lhs)?;
    let lhs = unwrap_value(lhs, lhs_span)?;

    let rhs_span = rhs.span;
    let rhs = compile_expr(context, module, rhs)?;
    let rhs = unwrap_value(rhs, rhs_span)?;
    compile_binary_arith_temp(context, module, lhs, rhs, op, ty)
}

pub fn compile_binary_arith_temp(
    context: &mut CompilerContext,
    module: &Module,
    lhs: expr::QbeValue,
    rhs: expr::QbeValue,
    op: &BinaryArith,
    ty: &TypeIdent,
) -> CompileExprResult {
    let op = match op {
        BinaryArith::Add => "add",
        BinaryArith::Sub => "sub",
        BinaryArith::Mul => "mul",
        BinaryArith::Div => "div",
        BinaryArith::Rem => "rem",
    };
    let name = format!("temp{op}");

    let ty: BaseTy = ty.try_into()?;
    let res = context.qbe.binary(ty, op, &lhs, &rhs, &name)?;
    Ok(res.into())
}

pub fn compile_binary_pred(
    context: &mut CompilerContext,
    module: &Module,
    lhs: &Expr,
    rhs: &Expr,
    op: &BinaryPred,
    shared: &TypeIdent,
) -> CompileExprResult {
    let lhs_span = lhs.span;
    let rhs_span = rhs.span;
    let lhs = compile_expr(context, module, lhs)?;
    let lhs = unwrap_value(lhs, lhs_span)?;
    let rhs = compile_expr(context, module, rhs)?;
    let rhs = unwrap_value(rhs, rhs_span)?;

    let ty: BaseTy = shared.try_into()?;
    let op = match op {
        BinaryPred::EQ => format!("ceq{ty}"),
        BinaryPred::NE => format!("cne{ty}"),
        BinaryPred::GT => format!("csgt{ty}"),
        BinaryPred::GE => format!("csge{ty}"),
        BinaryPred::LT => format!("cslt{ty}"),
        BinaryPred::LE => format!("csle{ty}"),
        BinaryPred::And => format!("and"),
        BinaryPred::Or => format!("or"),
    };
    let name = format!("temp_{op}");

    let res = context.qbe.binary(BaseTy::W, &op, &lhs, &rhs, &name)?;
    Ok(res.into())
}
