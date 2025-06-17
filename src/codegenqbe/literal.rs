use crate::{ast::prelude::Literal, codegenqbe::expr::CompiledExpr};

use super::{compiler::CompilerContext, expr::CompileExprResult, qbe::BaseTy};

pub fn compile_literal(context: &mut CompilerContext, literal: &Literal) -> CompileExprResult {
    use BaseTy::*;
    let literal = match literal {
        Literal::Number(v) => context.qbe.unary(L, "copy", *v, "literal")?,
        Literal::Bool(v) => context.qbe.unary(W, "copy", *v as i64, "literal")?,
        Literal::Char(v) => context.qbe.unary(W, "copy", *v as i64, "literal")?,
        Literal::Float(v) => context.qbe.unary(W, "copy", *v, "literal")?,
    };
    Ok(CompiledExpr::Temp(literal))
}
