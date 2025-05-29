use crate::{ast::prelude::*, typecheck::prelude::*};

use super::{compiler::Compiler, expr::CompileExprResult, typedvalue::TypedValue};

pub type CompileLiteralResult<'a> = CompileExprResult<'a>;

#[allow(unused_variables, dead_code)]
impl<'ctx> Compiler<'ctx> {
    pub fn compile_literal(&mut self, module: &Module, literal: &Literal) -> CompileLiteralResult<'ctx> {
        let l = match literal {
            Literal::Number(n) => TypedValue::num(self.context.i64_type().const_int(*n as u64, true).into()),
            Literal::Char(c) => TypedValue::char(self.context.i8_type().const_int(*c as u64, false).into()),
            Literal::Bool(false) => TypedValue::bool(self.context.bool_type().const_zero().into()),
            Literal::Bool(true) => TypedValue::bool(self.context.bool_type().const_all_ones().into()),
            Literal::Float(f) => TypedValue::float(self.context.f64_type().const_float(*f).into()),
        };
        Ok(l.into())
    }
}

