use crate::ast::{Expr, Module, UnaryOp};

use super::{compiler::Compiler, error::CompilerErrorKind, expr::CompileExprResult, typedvalue::TypedValue};

#[allow(unused_variables, dead_code)]
impl<'ctx> Compiler<'ctx> {
    pub fn compile_unary(&mut self, module: &Module, op: &UnaryOp, expr: &Expr) -> CompileExprResult<'ctx> {
        let expr_span = expr.span;
        let expr = self.compile_expr(module, expr)?;
        let expr = self.load_value(expr, CompilerErrorKind::ValueExpected, expr_span, "unary")?;
        let val = match op {
             // TODO: Typecheck values
            UnaryOp::GROUP => expr,
            UnaryOp::POS => expr,
            UnaryOp::NOT => {
                TypedValue::new(
                    self.builder.build_not(expr.value.into_int_value(), "tmpnot").unwrap().into(), 
                    expr.typeident
                )
            }
            UnaryOp::NEG => {
                TypedValue::new(
                    self.builder.build_int_neg(expr.value.into_int_value(), "tmpneg").unwrap().into(), 
                    expr.typeident
                )
            }
        };
        Ok(val.into())
    }
}
