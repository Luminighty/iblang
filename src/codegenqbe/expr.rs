use crate::{
    ast::prelude::UnaryArith,
    typecheck::{
        FlowType, TypeIdent,
        atomic::{Atomic, Numeric},
        expr::{Expr, ExprKind},
        module::Module,
    },
    utils::Span,
};

use super::{
    CompilerResult,
    array::{compile_array_index, compile_array_init},
    binary::{compile_binary_arith, compile_binary_pred},
    compiler::CompilerContext,
    error::CompilerError,
    literal::compile_literal,
    qbe::{ABITy, BaseTy, CallBuilder, ExtTy, LoadTy, SubWTy, Temp},
    strcts::{compile_field_lookup, compile_struct_init},
    unary::{compile_cast, compile_deref, compile_ref, compile_unary},
};

#[derive(Debug)]
pub enum CompiledExpr {
    Temp(Temp),
    Void,
    Never,
}

pub type CompileExprResult = CompilerResult<CompiledExpr>;

pub fn unwrap_value(expr: CompiledExpr, span: Span) -> CompilerResult<Temp> {
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
    let value_kind = expr.value_kind;
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
        ExprKind::Load { expr, ty } => compile_load(context, module, expr, ty),
        ExprKind::Cast {
            expr,
            target,
            method,
        } => compile_cast(context, module, expr, method, target),
        ExprKind::Array { values, ty } => compile_array_init(context, module, values, ty),
        ExprKind::Index { index, expr, ty } => {
            compile_array_index(context, module, expr, index, ty)
        }
        // ExprKind::StructInit { values, ty } => compile_struct_init(context, module, values, ty),
        // ExprKind::FieldLookup { obj, field, ty } => {
        //     compile_field_lookup(context, module, obj, field, ty)
        // }
        ExprKind::Deref { expr, ty } => compile_deref(context, module, expr, ty, value_kind),
        ExprKind::Ref { expr, ty } => compile_ref(context, module, expr, ty),
    }
}

pub fn compile_load(
    context: &mut CompilerContext,
    module: &Module,
    expr: &Expr,
    ty: &TypeIdent,
) -> CompileExprResult {
    let expr_span = expr.span;
    let expr = compile_expr(context, module, expr)?;
    let expr = unwrap_value(expr, expr_span)?;

    let ty = ty.try_into()?;
    let load = context.qbe.load(ty, &expr, "load")?;
    Ok(load.into())
}

pub fn compile_assign(
    context: &mut CompilerContext,
    module: &Module,
    target: &Expr,
    value: &Expr,
    ty: &TypeIdent,
) -> CompileExprResult {
    let value_span = value.span;
    let value = compile_expr(context, module, value)?;
    let value = unwrap_value(value, value_span)?;

    let target_span = target.span;
    let target = compile_expr(context, module, target)?;
    let target = unwrap_value(target, target_span)?;

    context.qbe.store(ty, &value, &target)?;
    Ok(value.into())
}

fn compile_variable(
    context: &mut CompilerContext,
    _module: &Module,
    var: &str,
    _ty: &TypeIdent,
) -> CompileExprResult {
    if let Some(b) = context.bindings.get(var) {
        Ok(b.into())
    } else {
        Err(CompilerError::UndefinedVariable {
            var: var.to_owned(),
        })
    }
}

fn compile_call(
    context: &mut CompilerContext,
    module: &Module,
    callee: &String,
    args: &Vec<(Expr, TypeIdent)>,
    ty: &FlowType,
) -> CompileExprResult {
    let func = context.functions.get(callee).unwrap();

    let mut call = CallBuilder::new(func);
    for (arg, arg_ty) in args.iter() {
        let arg_span = arg.span;
        let arg = compile_expr(context, module, arg)?;
        let arg = unwrap_value(arg, arg_span)?;
        let ty = typeident_into_abity(context, arg_ty);
        call.arg(ty, &arg);
    }

    match ty {
        FlowType::Some(ty) => {
            let ty = typeident_into_abity(context, ty);
            let res = call.call_res(&mut context.qbe, ty, "res")?;
            Ok(res.into())
        }
        FlowType::Void => {
            call.call(&mut context.qbe)?;
            Ok(CompiledExpr::Void)
        }
        FlowType::Never => {
            call.call(&mut context.qbe)?;
            Ok(CompiledExpr::Never)
        }
    }
}

pub fn typeident_into_abity(context: &mut CompilerContext, ty: &TypeIdent) -> ABITy {
    match ty {
        TypeIdent::Atomic(atomic) => ABITy::BaseTy((*atomic).into()),
        TypeIdent::Struct(s) => ABITy::TyIdent(*context.struct_types.get(s).unwrap()),
        TypeIdent::Array(_, _) => ABITy::BaseTy(BaseTy::L),
        TypeIdent::Ref(_) => ABITy::BaseTy(BaseTy::L),
    }
}

impl Into<LoadTy> for Atomic {
    fn into(self) -> LoadTy {
        match self {
            Atomic::Number(Numeric::Int) => LoadTy::BaseTy(BaseTy::L),
            Atomic::Number(Numeric::Char) => LoadTy::SubWTy(SubWTy::SB),
            Atomic::Number(Numeric::Bool) => LoadTy::SubWTy(SubWTy::SB),
            Atomic::Float => LoadTy::BaseTy(BaseTy::D),
        }
    }
}

impl TryInto<LoadTy> for &TypeIdent {
    type Error = CompilerError;

    fn try_into(self) -> Result<LoadTy, CompilerError> {
        match self {
            TypeIdent::Atomic(atomic) => Ok((*atomic).into()),
            TypeIdent::Ref(_) => Ok(LoadTy::BaseTy(BaseTy::L)),
            TypeIdent::Array(_, _) => Ok(LoadTy::BaseTy(BaseTy::L)),
            x => Err(CompilerError::InvalidBaseTyCast(x.clone())),
        }
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
            TypeIdent::Array(_, _) => Ok(BaseTy::L),
            x => Err(CompilerError::InvalidBaseTyCast(x.clone())),
        }
    }
}

impl Into<CompiledExpr> for Temp {
    fn into(self) -> CompiledExpr {
        CompiledExpr::Temp(self)
    }
}

impl Into<ExtTy> for &TypeIdent {
    fn into(self) -> ExtTy {
        match self {
            TypeIdent::Atomic(Atomic::Number(Numeric::Char)) => ExtTy::B,
            TypeIdent::Atomic(Atomic::Number(Numeric::Bool)) => ExtTy::B,
            TypeIdent::Atomic(Atomic::Number(Numeric::Int)) => ExtTy::BASE(BaseTy::L),
            TypeIdent::Atomic(Atomic::Float) => ExtTy::BASE(BaseTy::D),
            TypeIdent::Struct(_) => ExtTy::BASE(BaseTy::L),
            TypeIdent::Array(_, _) => ExtTy::BASE(BaseTy::L),
            TypeIdent::Ref(_) => ExtTy::BASE(BaseTy::L),
        }
    }
}

impl std::fmt::Display for Expr {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", self.kind)
    }
}

impl std::fmt::Display for ExprKind {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            ExprKind::Literal(literal, _) => write!(f, "{}", literal),
            ExprKind::Variable(ident, _) => write!(f, "{}", ident),
            ExprKind::BinaryPred { op, lhs, rhs, .. } => write!(f, "({} {} {})", lhs, op, rhs),
            ExprKind::BinaryArith { op, lhs, rhs, .. } => write!(f, "({} {} {})", lhs, op, rhs),
            ExprKind::Unary { op, expr, .. } => write!(f, "({}{})", op, expr),
            ExprKind::Call { callee, args, .. } => {
                write!(f, "{}(", callee)?;
                for (i, (arg, _)) in args.iter().enumerate() {
                    write!(f, "{}", arg)?;
                    if args.len() > i + 1 {
                        write!(f, ", ")?;
                    }
                }
                write!(f, ")")
            }
            ExprKind::Load { expr, ty } => write!(f, "Load({})", expr),
            ExprKind::Array { values, .. } => {
                write!(f, "[")?;
                for (i, arg) in values.iter().enumerate() {
                    write!(f, "{}", arg)?;
                    if values.len() > i + 1 {
                        write!(f, ", ")?;
                    }
                }
                write!(f, "]")
            }
            // ExprKind::StructInit { values, ty } => {
            //     writeln!(f, "struct {ty} {{")?;
            //     for (i, (field, val)) in values.iter().enumerate() {
            //         writeln!(f, "{field}: {val}")?;
            //         if values.len() > i + 1 {
            //             write!(f, ", ")?;
            //         }
            //     }
            //     writeln!(f, "}}")
            // }
            ExprKind::Assign { lhs, rhs, ty } => write!(f, "{lhs} = {rhs}"),
            ExprKind::Cast {
                expr,
                target,
                method,
            } => write!(f, "{expr}",),
            ExprKind::Index { index, expr, ty } => write!(f, "{expr}[{index}]"),
            // ExprKind::FieldLookup { obj, field, ty } => write!(f, "{obj}.{field}"),
            ExprKind::Deref { expr, ty } => write!(f, "*{expr}"),
            ExprKind::Ref { expr, ty } => write!(f, "&{expr}"),
        }
    }
}
