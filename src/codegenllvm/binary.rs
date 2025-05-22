use inkwell::IntPredicate;

use crate::ast::{BinaryOp, Expr, Module};

use super::{compiler::Compiler, expr::CompileExprResult, typedvalue::TypedValue};

#[allow(unused_variables, dead_code)]
impl<'ctx> Compiler<'ctx> {
    pub fn compile_binary(&mut self, module: &Module, op: &BinaryOp, lhs: &Expr, rhs: &Expr) -> CompileExprResult<'ctx> {
        let lhs = self.compile_expr(module, lhs)?;
        let rhs = self.compile_expr(module, rhs)?;

        // TODO: Infer correct type and typecheck
        let new_type = lhs.typeident;

        let lhs = lhs.value.into_int_value();
        let rhs = rhs.value.into_int_value();
        // TODO: Support for floats
        let res = match op {
            BinaryOp::Add => self.builder.build_int_add(lhs, rhs, "addtmp"),
            BinaryOp::Sub => self.builder.build_int_sub(lhs, rhs, "subtmp"),
            BinaryOp::Mul => self.builder.build_int_mul(lhs, rhs, "multmp"),
            BinaryOp::Div => self.builder.build_int_signed_div(lhs, rhs, "divtmp"),
            BinaryOp::Rem => self.builder.build_int_signed_rem(lhs, rhs, "remtmp"),
            BinaryOp::EQ  => self.builder.build_int_compare(IntPredicate::EQ, lhs, rhs, "eqtmp"),
            BinaryOp::NE  => self.builder.build_int_compare(IntPredicate::NE, lhs, rhs, "netmp"),
            BinaryOp::GT  => self.builder.build_int_compare(IntPredicate::SGT, lhs, rhs, "gttmp"),
            BinaryOp::GE  => self.builder.build_int_compare(IntPredicate::SGE, lhs, rhs, "getmp"),
            BinaryOp::LT  => self.builder.build_int_compare(IntPredicate::SLT, lhs, rhs, "lttmp"),
            BinaryOp::LE  => self.builder.build_int_compare(IntPredicate::SLE, lhs, rhs, "letmp"),
            BinaryOp::Index => todo!(),
            BinaryOp::Assign => todo!(),
        };
        Ok(TypedValue::new(res.unwrap().into(), new_type))
    }
}
