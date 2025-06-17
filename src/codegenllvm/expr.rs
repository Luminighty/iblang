use std::ops::Deref;

use inkwell::values::BasicMetadataValueEnum;

use crate::ast::Identifier;
use crate::log;
use crate::typecheck::prelude::*;
use crate::utils::Span;

use super::error::CompilerErrorKind;
use super::statement::CompiledStatement;
use super::typedvalue::TypedValue;
use super::{CompileResult, compiler::Compiler};

#[derive(Debug)]
pub enum CompiledExpr<'a> {
    Value(TypedValue<'a>),
    Void,
    Never,
}

pub type CompileExprResult<'a> = CompileResult<CompiledExpr<'a>>;

#[allow(unused_variables, dead_code)]
impl<'ctx> Compiler<'ctx> {
    pub fn load_value(
        &self,
        expr: CompiledExpr<'ctx>,
        kind: CompilerErrorKind,
        span: Span,
        name: &str,
    ) -> CompileResult<TypedValue<'ctx>> {
        match expr {
            CompiledExpr::Value(val) => Ok(val),
            _ => self.error(kind, span),
        }
    }

    pub fn compile_expr(&mut self, module: &Module, expr: &Expr) -> CompileExprResult<'ctx> {
        match &expr.kind {
            ExprKind::Literal(literal, ty) => self.compile_literal(module, &literal),
            ExprKind::Variable(ident, ty) => self.compile_var(module, ident, &expr.span),
            ExprKind::Unary { op, expr, ty } => self.compile_unary(module, op, expr, ty, expr.span),
            ExprKind::Call { callee, args, ty } => {
                self.compile_call(module, callee, args, ty, expr.span)
            }
            ExprKind::Assign { lhs, rhs, ty } => self.compile_assign(module, lhs, rhs, expr.span),
            ExprKind::BinaryPred {
                op,
                lhs,
                rhs,
                shared,
            } => self.compile_pred(module, op, lhs, rhs, shared, expr.span),
            ExprKind::BinaryArith { op, lhs, rhs, ty } => {
                self.compile_arith(module, op, lhs, rhs, ty, expr.span)
            }
            ExprKind::Cast {
                expr,
                target,
                method,
            } => self.compile_cast(module, expr, target, method, expr.span),
            ExprKind::Array { values, ty } => self.compile_array(module, values, ty, expr.span),
            ExprKind::Index { index, expr, ty } => {
                self.compile_arr_index(module, expr, index, expr.span)
            }
            ExprKind::Deref { expr, ty } => self.compile_deref(module, expr, ty, expr.span),
            ExprKind::Ref { expr, ty } => self.compile_ref(module, expr, ty, expr.span),
            ExprKind::StructInit { values, ty } => {
                self.compile_struct_init(module, values, ty, expr.span)
            }
            ExprKind::FieldLookup { obj, field, ty } => {
                self.compile_field_lookup(module, obj, field, ty, expr.span)
            }
        }
    }

    pub fn compile_deref(
        &mut self,
        module: &Module,
        expr: &Expr,
        ty: &TypeIdent,
        span: Span,
    ) -> CompileExprResult<'ctx> {
        let expr_span = expr.span;
        let expr = self.compile_expr(module, expr)?;
        let expr = self.load_value(expr, CompilerErrorKind::ValueExpected, expr_span, "deref")?;
        log!(self, "deref from {:?}", expr.typeident);
        let expr_ty = match expr.typeident {
            TypeIdent::Ref(ty) => ty,
            _ => todo!("{expr:?} {ty:?}"),
        };
        log!(self, "deref into {expr_ty:?}");
        let ty = self.inkwell_type(&expr_ty);
        let alloca = self
            .builder
            .build_load(ty, expr.value.into_pointer_value(), &format!("deref"))
            .unwrap();
        Ok(TypedValue::new(alloca, *expr_ty).into())
    }

    fn compile_ref(
        &mut self,
        module: &Module,
        expr: &Expr,
        ty: &TypeIdent,
        span: Span,
    ) -> CompileExprResult<'ctx> {
        let expr_span = expr.span;
        let expr = self.compile_expr(module, expr)?;
        let expr = self.load_value(expr, CompilerErrorKind::ValueExpected, expr_span, "ref")?;
        Ok(TypedValue::new(expr.value.into(), ty.clone()).into())
    }

    fn compile_arr_index(
        &mut self,
        module: &Module,
        expr: &Expr,
        index: &Expr,
        span: Span,
    ) -> CompileExprResult<'ctx> {
        let expr_span = expr.span;
        let expr = self.compile_expr(module, expr)?;
        let expr = self.load_value(expr, CompilerErrorKind::ValueExpected, expr_span, "arr")?;

        let index_span = index.span;
        let index = self.compile_expr(module, index)?;
        let index =
            self.load_value(index, CompilerErrorKind::ValueExpected, index_span, "index")?;
        let index = index.value.into_int_value();

        let (arr_ty, elem_ty, gep_index) = match expr.typeident {
            TypeIdent::Ref(ty) => {
                let arr_ty = ty.clone();
                match *ty {
                    TypeIdent::Array(elem_ty, _) => (
                        arr_ty,
                        elem_ty,
                        vec![self.context.i64_type().const_zero(), index],
                    ),
                    elem_ty => (Box::new(elem_ty.clone()), Box::new(elem_ty), vec![index]),
                }
            }
            // TypeIdent::Array(ty, _) => (ty, vec![self.context.i64_type().const_zero(), index]),
            other => {
                return self.error(
                    CompilerErrorKind::InvalidArrayType { ty: other.clone() },
                    span,
                );
            }
        };

        let arr = expr.value.into_pointer_value();

        let arr_ty = self.inkwell_type(&arr_ty);
        let element_ptr = unsafe {
            self.builder
                .build_gep(arr_ty, arr, &gep_index, "elem")
                .unwrap()
        };
        //let element = self.builder.build_load(arr_ty, element_ptr, "elem_load").unwrap();
        Ok(TypedValue::new(element_ptr.into(), TypeIdent::Ref(elem_ty)).into())
    }

    fn compile_array(
        &mut self,
        module: &Module,
        values: &Vec<Expr>,
        ty: &TypeIdent,
        span: Span,
    ) -> CompileExprResult<'ctx> {
        log!(self, "compile_array: {ty:?}");
        let (ty, len) = match ty {
            TypeIdent::Ref(ty) => match ty.deref() {
                TypeIdent::Array(ty, len) => (ty, len),
                other => {
                    return self.error(
                        CompilerErrorKind::InvalidArrayType { ty: other.clone() },
                        span,
                    );
                }
            },
            other => {
                return self.error(
                    CompilerErrorKind::InvalidArrayType { ty: other.clone() },
                    span,
                );
            }
        };

        let mut compiled = Vec::with_capacity(values.len());
        for value in values {
            let span = value.span;
            let value = self.compile_expr(module, value)?;
            let value = self.load_value(value, CompilerErrorKind::ValueExpected, span, "elem")?;
            compiled.push(value.value);
        }

        let arr_ty = TypeIdent::Array(ty.clone(), *len);
        let inkwell_arr_ty = self.inkwell_type(&arr_ty);

        let (alloca, align) =
            self.create_entry_block_alloca(module, "array", &TypeIdent::Array(ty.clone(), *len));

        for (i, value) in compiled.into_iter().enumerate() {
            let gep = unsafe {
                self.builder
                    .build_in_bounds_gep(
                        inkwell_arr_ty,
                        alloca,
                        &[
                            self.context.i64_type().const_zero(),
                            self.context.i64_type().const_int(i as u64, false),
                        ],
                        &format!("array_elem_ptr_{}", i),
                    )
                    .unwrap()
            };
            self.builder.build_store(gep, value).unwrap();
        }

        Ok(TypedValue::new(alloca.into(), arr_ty).into())
    }

    fn compile_var(
        &mut self,
        module: &Module,
        ident: &Identifier,
        span: &Span,
    ) -> CompileExprResult<'ctx> {
        if let Some(binding) = self.bindings.get(ident) {
            log!(self, "var {ident} -> {binding:?}");
            Ok(binding.clone().into())
        } else {
            self.error(
                CompilerErrorKind::UndeclaredVariable(ident.to_owned()),
                *span,
            )
        }
    }

    fn compile_call(
        &mut self,
        module: &Module,
        callee: &Identifier,
        args: &Vec<(Expr, TypeIdent)>,
        ty: &FlowType,
        span: Span,
    ) -> CompileExprResult<'ctx> {
        let func = self.get_function(&callee).unwrap();

        let mut compiled_args = Vec::with_capacity(args.len());
        for (i, (arg, ty)) in args.iter().enumerate() {
            let arg_span = arg.span;
            let compiled_arg = self.compile_expr(module, arg)?;
            let name = format!("arg_{}_{}", ty, i);

            let value = self.load_value(
                compiled_arg,
                CompilerErrorKind::ValueExpected,
                arg_span,
                &name,
            )?;
            // TODO: Validate type cast
            compiled_args.push(value);
        }
        let argsv: Vec<BasicMetadataValueEnum> = compiled_args
            .iter()
            .by_ref()
            .map(|val| val.value.into())
            .collect();

        let build_result = self
            .builder
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
}

impl<'a> Into<CompiledStatement> for CompiledExpr<'a> {
    fn into(self) -> CompiledStatement {
        match self {
            CompiledExpr::Never => CompiledStatement::Never,
            CompiledExpr::Void => CompiledStatement::Some,
            CompiledExpr::Value(_) => CompiledStatement::Some,
        }
    }
}
