use std::error::Error;

use crate::{
    typecheck::{
        FlowType, TypeIdent,
        atomic::{Atomic, Numeric},
        expr::{Expr, ExprKind},
        module::Module,
    },
    utils::Span,
};

use super::{
    CompileResult,
    array::{compile_array_index, compile_array_init},
    binary::{compile_binary_arith, compile_binary_pred},
    compiler::CompilerContext,
    error::CompilerError,
    literal::compile_literal,
    qbe::{ABITy, BaseTy, Temp},
    strcts::{compile_field_lookup, compile_struct_init},
    unary::{compile_cast, compile_deref, compile_ref, compile_unary},
};

#[derive(Debug)]
pub enum CompiledExpr {
    Temp(Temp),
    Void,
    Never,
}

pub type CompileExprResult = CompileResult<CompiledExpr>;

pub fn unwrap_value(expr: CompiledExpr, span: Span) -> CompileResult<Temp> {
    match expr {
        CompiledExpr::Temp(temp) => Ok(temp),
        _ => Err(CompilerError::ValueExpected(span)),
    }
}

pub fn compile_expr(
    context: &mut CompilerContext,
    module: &Module,
    expr: &Expr,
) -> CompileExprResult {
    match &expr.kind {
        ExprKind::Literal(literal, _) => compile_literal(context, literal),
        ExprKind::Variable(ident, ty) => compile_variable(context, module, ident, ty),
        ExprKind::Assign { lhs, rhs, ty } => compile_assign(context, module, lhs, rhs, ty),
        ExprKind::BinaryPred {
            op,
            lhs,
            rhs,
            shared,
        } => compile_binary_pred(context, module, lhs, rhs, op, shared),
        ExprKind::BinaryArith { op, lhs, rhs, ty } => {
            compile_binary_arith(context, module, lhs, rhs, op, ty)
        }
        ExprKind::Unary { op, expr, ty } => compile_unary(context, module, expr, op, ty),
        ExprKind::Call { callee, args, ty } => compile_call(context, module, callee, args, ty),
        ExprKind::Cast {
            expr,
            target,
            method,
        } => compile_cast(context, module, expr, method, target),
        ExprKind::Array { values, ty } => compile_array_init(context, module, values, ty),
        ExprKind::Index { index, expr, ty } => {
            compile_array_index(context, module, expr, index, ty)
        }
        ExprKind::StructInit { values, ty } => compile_struct_init(context, module, values, ty),
        ExprKind::FieldLookup { obj, field, ty } => {
            compile_field_lookup(context, module, obj, field, ty)
        }
        ExprKind::Deref { expr, ty } => compile_deref(context, module, expr, ty),
        ExprKind::Ref { expr, ty } => compile_ref(context, module, expr, ty),
    }
}

fn compile_assign(
    context: &mut CompilerContext,
    module: &Module,
    target: &Expr,
    value: &Expr,
    ty: &TypeIdent,
) -> CompileExprResult {
    todo!()
}

fn compile_variable(
    context: &mut CompilerContext,
    module: &Module,
    var: &str,
    ty: &TypeIdent,
) -> CompileExprResult {
    todo!()
}

fn compile_call(
    context: &mut CompilerContext,
    module: &Module,
    callee: &String,
    args: &Vec<(Expr, TypeIdent)>,
    ty: &FlowType,
) -> CompileExprResult {
    todo!()
}

pub fn typeident_into_abity(context: &mut CompilerContext, ty: &TypeIdent) -> ABITy {
    match ty {
        TypeIdent::Atomic(atomic) => ABITy::BaseTy((*atomic).into()),
        TypeIdent::Struct(s) => ABITy::TyIdent(*context.struct_types.get(s).unwrap()),
        TypeIdent::Array(type_ident, _) => todo!(),
        TypeIdent::Ref(type_ident) => ABITy::BaseTy(BaseTy::L),
    }
}

impl Into<BaseTy> for Atomic {
    fn into(self) -> BaseTy {
        match self {
            Atomic::Number(Numeric::Int) => BaseTy::L,
            Atomic::Number(Numeric::Char) => BaseTy::W,
            Atomic::Number(Numeric::Bool) => BaseTy::W,
            Atomic::Float => BaseTy::D,
        }
    }
}

impl TryInto<BaseTy> for &TypeIdent {
    type Error = CompilerError;

    fn try_into(self) -> Result<BaseTy, CompilerError> {
        match self {
            TypeIdent::Atomic(atomic) => Ok((*atomic).into()),
            TypeIdent::Ref(_) => Ok(BaseTy::L),
            x => Err(CompilerError::InvalidBaseTyCast(x.clone())),
        }
    }
}

impl Into<CompiledExpr> for Temp {
    fn into(self) -> CompiledExpr {
        CompiledExpr::Temp(self)
    }
}
