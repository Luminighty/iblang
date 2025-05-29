use crate::{ast::prelude::*, typecheck::{atomic::Atomic, TypeIdent}, utils::Span};
use crate::typecheck::prelude::*;

use super::{compiler::Compiler, error::CompilerErrorKind, expr::CompileExprResult, typedvalue::TypedValue};

#[allow(unused_variables, dead_code)]
impl<'ctx> Compiler<'ctx> {
    pub fn compile_unary(&mut self, module: &Module, op: &UnaryOp, expr: &Expr, ty: &TypeIdent, span: Span) -> CompileExprResult<'ctx> {
        let expr_span = expr.span;
        let expr = self.compile_expr(module, expr)?;
        let expr = self.load_value(expr, CompilerErrorKind::ValueExpected, expr_span, "unary")?;

        match ty {
            TypeIdent::Atomic(Atomic::Float) => self.unary_float(op, expr, ty.clone(), span),
            TypeIdent::Atomic(_) => self.unary_int(op, expr, ty.clone()),
            _ => todo!(),
        }
    }

    fn unary_int(&mut self, op: &UnaryOp, expr: TypedValue<'ctx>, new_type: TypeIdent) -> CompileExprResult<'ctx> {
        Ok(match op {
            UnaryOp::GROUP => expr,
            UnaryOp::POS => expr,
            UnaryOp::NOT => {
                TypedValue::new(
                    self.builder.build_not(expr.value.into_int_value(), "tmpnot").unwrap().into(),
                    new_type,
                )
            }
            UnaryOp::NEG => {
                TypedValue::new(
                    self.builder.build_int_neg(expr.value.into_int_value(), "tmpneg").unwrap().into(), 
                    new_type,
                )
            }
        }.into())
    }

    fn unary_float(&mut self, op: &UnaryOp, expr: TypedValue<'ctx>, new_type: TypeIdent, span: Span) -> CompileExprResult<'ctx> {
        Ok(match op {
            UnaryOp::GROUP => expr,
            UnaryOp::POS => expr,
            UnaryOp::NOT => {
                return self.error(CompilerErrorKind::UnaryTypeMismatch { op: *op, value: expr.typeident }, span);
            }
            UnaryOp::NEG => {
                TypedValue::new(
                    self.builder.build_float_neg(expr.value.into_float_value(), "tmpneg").unwrap().into(), 
                    new_type,
                )
            }
        }.into())
    }
}

