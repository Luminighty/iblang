use inkwell::values::BasicMetadataValueEnum;

use crate::ast::Identifier;
use crate::typecheck::atomic::Atomic;
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
                let alloca = self.builder.build_load(ty, var.alloca, &format!("load_{}", name)).unwrap();
                Ok(TypedValue::new(alloca, var.typeident))
            },
            _ => self.error(kind, span)
        }
    }

    pub fn ptr_value(&self, expr: CompiledExpr<'ctx>, kind: CompilerErrorKind, span: Span, name: &str) -> CompileResult<TypedValue<'ctx>> {
        match expr {
            CompiledExpr::Value(val) => {
                let ptr = self.builder.build_alloca(val.value.get_type(), name).unwrap();
                self.builder.build_store(ptr, val.value).unwrap();
                Ok(TypedValue::new(ptr.into(), val.typeident))
            }
            CompiledExpr::Variable(var) => {
                let ty = Compiler::inkwell_type(self.context, &var.typeident);
                Ok(TypedValue::new(var.alloca.into(), var.typeident))
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
            ExprKind::Cast { expr, target, method } => self.compile_cast(module, expr, target, method, expr.span),
            ExprKind::Array { values, ty } => self.compile_array(module, values, ty, expr.span),
            ExprKind::Index { index, expr, ty } => self.compile_arr_index(module, expr, index, expr.span),
            ExprKind::Deref { expr, ty } => self.compile_deref(module, expr, ty, expr.span),
            ExprKind::Ref { expr, ty } => self.compile_ref(module, expr, ty, expr.span),
        }
    }


    fn compile_deref(&mut self, module: &Module, expr: &Expr, ty: &TypeIdent, span: Span) -> CompileExprResult<'ctx> {
        let expr_span = expr.span;
        let expr = self.compile_expr(module, expr)?;
        let expr = self.load_value(expr, CompilerErrorKind::ValueExpected, expr_span, "deref")?;
        Ok(TypedValue::new(expr.value.into(), ty.clone()).into())
    }

    fn compile_ref(&mut self, module: &Module, expr: &Expr, ty: &TypeIdent, span: Span) -> CompileExprResult<'ctx> {
        let expr_span = expr.span;
        let expr = self.compile_expr(module, expr)?;
        let expr = self.ptr_value(expr, CompilerErrorKind::ValueExpected, expr_span, "ref")?;
        Ok(TypedValue::new(expr.value.into(), ty.clone()).into())
    }


    fn compile_arr_index(&mut self, module: &Module, expr: &Expr, index: &Expr, span: Span) -> CompileExprResult<'ctx> {
        let expr_span = expr.span;
        let expr = self.compile_expr(module, expr)?;
        let expr = self.ptr_value(expr, CompilerErrorKind::ValueExpected, expr_span, "arr")?;

        let index_span = index.span;
        let index = self.compile_expr(module, index)?;
        let index = self.load_value(index, CompilerErrorKind::ValueExpected, index_span, "index")?;
        let index = index.value.into_int_value();

        let ty = match expr.typeident {
            TypeIdent::Array(ty, len) => ty,
            other => return self.error(CompilerErrorKind::InvalidArrayType { ty: other.clone() }, span)
        };

        let arr = expr.value.into_pointer_value();

        let arr_ty = Compiler::inkwell_type(self.context, &ty);
        let element_ptr = unsafe {
            self.builder.build_gep(arr_ty, arr, &[index], "elem").unwrap()
        };
        let element = self.builder.build_load(arr_ty, element_ptr, "elem_load").unwrap();
        Ok(TypedValue::new(element.into(), *ty.clone()).into())
    }


    fn compile_array(&mut self, module: &Module, values: &Vec<Expr>, ty: &TypeIdent, span: Span) -> CompileExprResult<'ctx> {
        let ty = match ty {
            TypeIdent::Array(ty, len) => ty,
            other => return self.error(CompilerErrorKind::InvalidArrayType { ty: other.clone() }, span)
        };

        let mut compiled = Vec::with_capacity(values.len());
        for value in values {
            let span = value.span;
            let value = self.compile_expr(module, value)?;
            let value = self.load_value(value, CompilerErrorKind::ValueExpected, span, "elem")?;
            compiled.push(value.value);
        }


        match **ty {
            TypeIdent::Atomic(Atomic::Float) => {
                let arr = Compiler::float_type(self.context, ty).unwrap();
                let float_values: Vec<_> = compiled
                    .iter()
                    .map(|value| value.into_float_value())
                    .collect();
                let arr = arr.const_array(float_values.as_slice());
                Ok(TypedValue::new(arr.into(), *ty.clone()).into())
            },
            TypeIdent::Atomic(Atomic::Number(_)) => {
                let arr = Compiler::int_type(self.context, ty).unwrap();
                let int_values: Vec<_> = compiled
                    .iter()
                    .map(|value| value.into_int_value())
                    .collect();
                let arr = arr.const_array(int_values.as_slice());
                Ok(TypedValue::new(arr.into(), *ty.clone()).into())
            },
            _ => todo!(),
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

