use inkwell::values::BasicMetadataValueEnum;

use crate::ast::Identifier;
use crate::typecheck::{prelude::*, FlowType, TypeIdent};
use crate::utils::Span;

use super::bindings::VariableBinding;
use super::error::CompilerErrorKind;
use super::statement::CompiledStatement;
use super::typedvalue::TypedValue;
use super::{compiler::Compiler, CompileResult};

pub enum CompiledExpr<'a> {
    Value(TypedValue<'a>),
    Variable(VariableBinding<'a>),
    Void,
    Never,
}

pub type CompileExprResult<'a> = CompileResult<CompiledExpr<'a>>;

#[allow(unused_variables, dead_code)]
impl<'ctx> Compiler<'ctx> {
    pub fn load_value(&self, expr: CompiledExpr<'ctx>, kind: CompilerErrorKind, span: Span, name: &str) -> CompileResult<TypedValue<'ctx>> {
        match expr {
            CompiledExpr::Value(val) => Ok(val),
            CompiledExpr::Variable(var) => {
                let ty = Compiler::inkwell_type(self.context, &var.typeident);
                let alloca = self.builder.build_load(ty, var.alloca, name).unwrap();
                Ok(TypedValue::new(alloca, var.typeident))
            },
            _ => self.error(kind, span)
        }
    }


    pub fn compile_expr(&mut self, module: &Module, expr: &Expr) -> CompileExprResult<'ctx> {
        match &expr.kind {
            ExprKind::Literal(literal, ty) => self.compile_literal(module, &literal),
            ExprKind::Ident(ident, ty) => self.compile_ident(module, ident, &expr.span),
            ExprKind::Unary { op, expr, ty } => self.compile_unary(module, op, expr, ty, expr.span),
            ExprKind::Call { callee, args, ty } => self.compile_call(module, callee, args, ty, expr.span),
            ExprKind::Assign { lhs, rhs, ty } => self.compile_assign(module, lhs, rhs, expr.span),
            ExprKind::BinaryPred { op, lhs, rhs, shared } => self.compile_pred(module, op, lhs, rhs, shared, expr.span),
            ExprKind::BinaryArith { op, lhs, rhs, ty } => self.compile_arith(module, op, lhs, rhs, ty, expr.span),
            ExprKind::Cast { expr, target, method } => self.compile_cast(module, expr, target, method, expr.span)
        }
    }


    fn compile_ident(&mut self, module: &Module, ident: &Identifier, span: &Span) -> CompileExprResult<'ctx> {
        if let Some(binding) = self.bindings.get(ident) {
            Ok(binding.clone().into())
        } else {
            self.error(
                CompilerErrorKind::UndeclaredVariable(ident.to_owned()),
                *span
            )
        }
    }


    fn compile_call(&mut self, module: &Module, callee: &Identifier, args: &Vec<(Expr, TypeIdent)>, ty: &FlowType, span: Span) -> CompileExprResult<'ctx> {
        let func = self.get_function(&callee).unwrap();

        let mut compiled_args = Vec::with_capacity(args.len());
        for (i, (arg, ty)) in args.iter().enumerate() {
            let arg_span = arg.span;
            let compiled_arg = self.compile_expr(module, arg)?;
            let name = format!("arg_{}_{}", ty, i);

            let value = self.load_value(compiled_arg, CompilerErrorKind::ValueExpected, arg_span, &name)?;
            // TODO: Validate type cast
            compiled_args.push(value);
        }
        let argsv: Vec<BasicMetadataValueEnum> = compiled_args
            .iter()
            .by_ref()
            .map(|val| val.value.into())
            .collect();

        let build_result = self.builder
            .build_call(func, argsv.as_slice(), "tmp")
            .unwrap()
            .try_as_basic_value()
            .left();

        match (build_result, ty) {
            (Some(value), FlowType::Some(ty)) => Ok(TypedValue::new(value, ty.clone()).into()),
            (_, FlowType::Never) => Ok(CompiledExpr::Never),
            _ => Ok(CompiledExpr::Void),
        }
    }


    pub fn as_identifier(&mut self, expr: &Expr) -> CompileResult<Identifier> {
        match &expr.kind {
            ExprKind::Ident(ident, _) => Ok(ident.to_owned()),
            _ => return self.error(CompilerErrorKind::IdentifierExpected, expr.span)
        }
    }
}


impl<'a> Into<CompiledStatement> for CompiledExpr<'a> {
    fn into(self) -> CompiledStatement {
        match self {
            CompiledExpr::Never => CompiledStatement::Never,
            CompiledExpr::Void => CompiledStatement::Some,
            CompiledExpr::Value(_) => CompiledStatement::Some,
            CompiledExpr::Variable(_) => CompiledStatement::Some,
        }
    }
}

