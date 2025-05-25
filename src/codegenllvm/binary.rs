use inkwell::IntPredicate;

use crate::{ast::{BinaryArith, BinaryOp, BinaryPred, Expr, Module}, codegenllvm::bindings::VariableBinding, types::{atomic::Atomic, TypeIdent}, utils::Span};

use super::{compiler::Compiler, error::CompilerErrorKind, expr::CompileExprResult, typedvalue::TypedValue};

#[allow(unused_variables, dead_code)]
impl<'ctx> Compiler<'ctx> {
    pub fn compile_binary(&mut self, module: &Module, op: &BinaryOp, lhs: &Expr, rhs: &Expr, span: Span) -> CompileExprResult<'ctx> {
        match op {
            BinaryOp::Index => self.compile_index(module, lhs, rhs),
            BinaryOp::Assign => self.compile_assign(module, lhs, rhs),
            BinaryOp::Arith(arith) => self.compile_arith(module, arith, lhs, rhs, span),
            BinaryOp::Pred(pred) => self.compile_pred(module, pred, lhs, rhs),
        }
    }

    pub fn compile_index(&mut self, module: &Module, lhs: &Expr, rhs: &Expr) -> CompileExprResult<'ctx> {
        todo!()
    }

    pub fn compile_assign(&mut self, module: &Module, lhs: &Expr, rhs: &Expr) -> CompileExprResult<'ctx> {
        let ident = self.as_identifier(lhs)?;
        let value: VariableBinding = match self.bindings.get(&ident) {
            Some(value) => *value,
            None => return self.error(CompilerErrorKind::UndeclaredVariable(ident), lhs.span),
        };

        let rhs_span = rhs.span;
        let rhs = self.compile_expr(module, rhs)?;
        let rhs = self.load_value(rhs, CompilerErrorKind::ValueExpected, rhs_span, "new_value")?;
        let rhs_val = rhs.value.into_int_value();

        self.builder.build_store(value.alloca, rhs_val).unwrap();
        Ok(rhs.into())
    }

    pub fn compile_pred(&mut self, module: &Module, op: &BinaryPred, lhs: &Expr, rhs: &Expr) -> CompileExprResult<'ctx> {
        let lhs_span = lhs.span;
        let rhs_span = rhs.span;
        let lhs = self.compile_expr(module, lhs)?;
        let lhs = self.load_value(lhs, CompilerErrorKind::ValueExpected, lhs_span, "pred_lhs")?;
        let rhs = self.compile_expr(module, rhs)?;
        let rhs = self.load_value(rhs, CompilerErrorKind::ValueExpected, rhs_span, "pred_rhs")?;

        let lhs = lhs.value.into_int_value();
        let rhs = rhs.value.into_int_value();

        let new_type = TypeIdent::Atomic(Atomic::Bool);

        let (pred, name) = match op {
            BinaryPred::And => todo!(),
            BinaryPred::Or => todo!(),
            BinaryPred::EQ => (IntPredicate::EQ, "eqtmp"),
            BinaryPred::NE  => (IntPredicate::NE, "netmp"),
            BinaryPred::GT  => (IntPredicate::SGT, "gttmp"),
            BinaryPred::GE  => (IntPredicate::SGE, "getmp"),
            BinaryPred::LT  => (IntPredicate::SLT, "lttmp"),
            BinaryPred::LE  => (IntPredicate::SLE, "letmp"),
        };
        let res = self.builder.build_int_compare(pred, lhs, rhs, name).unwrap().into();
        Ok(TypedValue::new(res, new_type).into())
    }

    pub fn compile_arith(&mut self, module: &Module, op: &BinaryArith, lhs: &Expr, rhs: &Expr, span: Span) -> CompileExprResult<'ctx> {
        let lhs_span = lhs.span;
        let rhs_span = rhs.span;
        let lhs = self.compile_expr(module, lhs)?;
        let lhs = self.load_value(lhs, CompilerErrorKind::ValueExpected, lhs_span, "arith_lhs")?;
        let rhs = self.compile_expr(module, rhs)?;
        let rhs = self.load_value(rhs, CompilerErrorKind::ValueExpected, rhs_span, "arith_rhs")?;

        // TODO: Infer correct type and typecheck
        let new_type = match TypeIdent::arith_result(lhs.typeident, rhs.typeident) {
            Ok(new_type) => new_type,
            Err(_) => {
                return self.error(
                    CompilerErrorKind::BinaryTypeMismatch(
                        (*op).into(), 
                        lhs.typeident, 
                        rhs.typeident
                    ), span);
            }
        };

        let target_type = Compiler::int_type(self.context, &new_type).unwrap();
        let lhs = if new_type != lhs.typeident {
            self.builder.build_int_truncate(lhs.value.into_int_value(), target_type, "lhs_trunc").unwrap()
        } else {
            lhs.value.into_int_value()
        };
        let rhs = if new_type != rhs.typeident {
            self.builder.build_int_truncate(rhs.value.into_int_value(), target_type, "rhs_trunc").unwrap()
        } else {
            rhs.value.into_int_value()
        };

        let res = match op {
            BinaryArith::Add => self.builder.build_int_add(lhs, rhs, "addtmp"),
            BinaryArith::Sub => self.builder.build_int_sub(lhs, rhs, "subtmp"),
            BinaryArith::Mul => self.builder.build_int_mul(lhs, rhs, "multmp"),
            BinaryArith::Div => self.builder.build_int_signed_div(lhs, rhs, "divtmp"),
            BinaryArith::Rem => self.builder.build_int_signed_rem(lhs, rhs, "remtmp"),
        };
        Ok(TypedValue::new(res.unwrap().into(), new_type).into())
    }
}

