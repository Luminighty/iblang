use crate::ast::{Expr, Module, UnaryOp};

use super::{compiler::Compiler, expr::CompileExprResult, typedvalue::TypedValue};

#[allow(unused_variables, dead_code)]
impl<'ctx> Compiler<'ctx> {
    pub fn compile_unary(&mut self, module: &Module, op: &UnaryOp, expr: &Expr) -> CompileExprResult<'ctx> {
        let expr = self.compile_expr(module, expr)?;
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
        Ok(val)
    }
}
