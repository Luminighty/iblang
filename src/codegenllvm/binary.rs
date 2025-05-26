use inkwell::{values::{FloatValue, IntValue}, FloatPredicate, IntPredicate};
use crate::{ast::{BinaryArith, BinaryOp, BinaryPred, Expr, Module}, codegenllvm::bindings::VariableBinding, types::{atomic::Atomic, TypeIdent}, utils::Span};
use super::{compiler::Compiler, error::CompilerErrorKind, expr::CompileExprResult, typedvalue::TypedValue, CompileResult};


#[allow(unused_variables, dead_code)]
impl<'ctx> Compiler<'ctx> {
    pub fn compile_binary(&mut self, module: &Module, op: &BinaryOp, lhs: &Expr, rhs: &Expr, span: Span) -> CompileExprResult<'ctx> {
        match op {
            BinaryOp::Index => self.compile_index(module, lhs, rhs),
            BinaryOp::Assign => self.compile_assign(module, lhs, rhs, span),
            BinaryOp::Arith(arith) => self.compile_arith(module, arith, lhs, rhs, span),
            BinaryOp::Pred(pred) => self.compile_pred(module, pred, lhs, rhs, span),
        }
    }

    pub fn compile_index(&mut self, module: &Module, lhs: &Expr, rhs: &Expr) -> CompileExprResult<'ctx> {
        todo!()
    }

    pub fn compile_assign(&mut self, module: &Module, lhs: &Expr, rhs: &Expr, span: Span) -> CompileExprResult<'ctx> {
        let ident = self.as_identifier(lhs)?;
        let value: VariableBinding = match self.bindings.get(&ident) {
            Some(value) => *value,
            None => return self.error(CompilerErrorKind::UndeclaredVariable(ident), lhs.span),
        };

        let rhs_span = rhs.span;
        let rhs = self.compile_expr(module, rhs)?;
        let rhs = self.load_value(rhs, CompilerErrorKind::ValueExpected, rhs_span, "assign")?;
        // NOTE: Using arith_result to check whenever we can assign var := rhs
        self.unwrap_arith_result(
            value.typeident, rhs.typeident, span,
            CompilerErrorKind::AssignmentTypeMismatch{target: value.typeident, value: rhs.typeident}
        )?;

        let target_type = value.typeident;
        let rhs_val = self.cast_to_type(rhs, target_type, "trunc_assign");

        self.builder.build_store(value.alloca, rhs_val).unwrap();
        Ok(value.into())
    }


    /// ================================================
    /// ================== PREDICATE ==================
    /// ================================================

    fn compile_pred(&mut self, module: &Module, op: &BinaryPred, lhs: &Expr, rhs: &Expr, span: Span) -> CompileExprResult<'ctx> {
        let lhs_span = lhs.span;
        let rhs_span = rhs.span;
        let lhs = self.compile_expr(module, lhs)?;
        let lhs = self.load_value(lhs, CompilerErrorKind::ValueExpected, lhs_span, "pred_lhs")?;

        let rhs = self.compile_expr(module, rhs)?;
        let rhs = self.load_value(rhs, CompilerErrorKind::ValueExpected, rhs_span, "pred_rhs")?;

        let common_type = self.unwrap_arith_result(
            lhs.typeident, rhs.typeident, span,
            CompilerErrorKind::BinaryTypeMismatch{op: op.into(), lhs: lhs.typeident, rhs: rhs.typeident}
        )?;

        let lhs = self.cast_to_type(lhs, common_type, "lhs_cast");
        let rhs = self.cast_to_type(rhs, common_type, "rhs_cast");

        match common_type {
            TypeIdent::Atomic(Atomic::Float) => self.compile_float_pred(op, lhs.into_float_value(), rhs.into_float_value(), span),
            TypeIdent::Atomic(_) => self.compile_int_pred(op, lhs.into_int_value(), rhs.into_int_value()),
        }
    }

    fn compile_int_pred(&mut self, op: &BinaryPred, lhs: IntValue<'ctx>, rhs: IntValue<'ctx>) -> CompileExprResult<'ctx> {
        let new_type = TypeIdent::Atomic(Atomic::Bool);
        macro_rules! unwrap {
            ($result: expr) => { Ok(TypedValue::new($result.unwrap().into(), new_type).into()) }
        }
        macro_rules! comp_int {
            ($pred: expr, $name: expr) => { 
                unwrap!(self.builder.build_int_compare($pred, lhs, rhs, $name))
            }
        }

        match op {
            BinaryPred::And => unwrap!(self.builder.build_and(lhs, rhs, "and_tmp")),
            BinaryPred::Or  => unwrap!(self.builder.build_or( lhs, rhs, "or_tmp")),
            BinaryPred::EQ => comp_int!(IntPredicate::EQ, "eq_tmp"),
            BinaryPred::NE => comp_int!(IntPredicate::NE, "ne_tmp"),
            BinaryPred::GT => comp_int!(IntPredicate::SGT, "gt_tmp"),
            BinaryPred::GE => comp_int!(IntPredicate::SGE, "ge_tmp"),
            BinaryPred::LT => comp_int!(IntPredicate::SLT, "lt_tmp"),
            BinaryPred::LE => comp_int!(IntPredicate::SLE, "le_tmp"),
        }
    }

    fn compile_float_pred(&mut self, op: &BinaryPred, lhs: FloatValue<'ctx>, rhs: FloatValue<'ctx>, span: Span) -> CompileExprResult<'ctx> {
        let new_type = TypeIdent::Atomic(Atomic::Bool);
        macro_rules! unwrap {
            ($result: expr) => { Ok(TypedValue::new($result.unwrap().into(), new_type).into()) }
        }
        macro_rules! comp_float {
            ($pred: expr, $name: expr) => { 
                unwrap!(self.builder.build_float_compare($pred, lhs, rhs, $name))
            }
        }

        match op {
            BinaryPred::And => self.error(
                CompilerErrorKind::BinaryTypeMismatch {
                    lhs: TypeIdent::Atomic(Atomic::Float), 
                    rhs: TypeIdent::Atomic(Atomic::Float), 
                    op: BinaryPred::And.into() 
                }, span),
            BinaryPred::Or => self.error(
                CompilerErrorKind::BinaryTypeMismatch { 
                    lhs: TypeIdent::Atomic(Atomic::Float), 
                    rhs: TypeIdent::Atomic(Atomic::Float), 
                    op: BinaryPred::Or.into() 
                }, span),
            BinaryPred::EQ => comp_float!(FloatPredicate::OEQ, "eq_tmp"),
            BinaryPred::NE => comp_float!(FloatPredicate::ONE, "ne_tmp"),
            BinaryPred::GT => comp_float!(FloatPredicate::OGT, "gt_tmp"),
            BinaryPred::GE => comp_float!(FloatPredicate::OGE, "ge_tmp"),
            BinaryPred::LT => comp_float!(FloatPredicate::OLT, "lt_tmp"),
            BinaryPred::LE => comp_float!(FloatPredicate::OLE, "le_tmp"),
        }
    }


    /// ================================================
    /// ================== ARITHMETIC ==================
    /// ================================================

    fn compile_arith(&mut self, module: &Module, op: &BinaryArith, lhs: &Expr, rhs: &Expr, span: Span) -> CompileExprResult<'ctx> {
        let lhs_span = lhs.span;
        let rhs_span = rhs.span;
        let lhs = self.compile_expr(module, lhs)?;
        let lhs = self.load_value(lhs, CompilerErrorKind::ValueExpected, lhs_span, "arith_lhs")?;
        let rhs = self.compile_expr(module, rhs)?;
        let rhs = self.load_value(rhs, CompilerErrorKind::ValueExpected, rhs_span, "arith_rhs")?;

        let new_type = self.unwrap_arith_result(
            lhs.typeident, rhs.typeident, span,
            CompilerErrorKind::BinaryTypeMismatch{op: op.into(), lhs: lhs.typeident, rhs: rhs.typeident}
        )?;

        let lhs = self.cast_to_type(lhs, new_type, "lhs_cast");
        let rhs = self.cast_to_type(rhs, new_type, "rhs_cast");

        match new_type {
            TypeIdent::Atomic(Atomic::Float) => self.compile_float_arith(op, lhs.into_float_value(), rhs.into_float_value(), new_type),
            TypeIdent::Atomic(_) => self.compile_int_arith(op, lhs.into_int_value(), rhs.into_int_value(), new_type),
        }
    }

    fn compile_int_arith(&mut self, op: &BinaryArith, lhs: IntValue<'ctx>, rhs: IntValue<'ctx>, new_type: TypeIdent) -> CompileExprResult<'ctx> {
        let res = match op {
            BinaryArith::Add => self.builder.build_int_add(lhs, rhs, "addtmp"),
            BinaryArith::Sub => self.builder.build_int_sub(lhs, rhs, "subtmp"),
            BinaryArith::Mul => self.builder.build_int_mul(lhs, rhs, "multmp"),
            BinaryArith::Div => self.builder.build_int_signed_div(lhs, rhs, "divtmp"),
            BinaryArith::Rem => self.builder.build_int_signed_rem(lhs, rhs, "remtmp"),
        };
        Ok(TypedValue::new(res.unwrap().into(), new_type).into())
    }

    fn compile_float_arith(&mut self, op: &BinaryArith, lhs: FloatValue<'ctx>, rhs: FloatValue<'ctx>, new_type: TypeIdent) -> CompileExprResult<'ctx> {
        let res = match op {
            BinaryArith::Add => self.builder.build_float_add(lhs, rhs, "addtmp"),
            BinaryArith::Sub => self.builder.build_float_sub(lhs, rhs, "subtmp"),
            BinaryArith::Mul => self.builder.build_float_mul(lhs, rhs, "multmp"),
            BinaryArith::Div => self.builder.build_float_div(lhs, rhs, "divtmp"),
            BinaryArith::Rem => self.builder.build_float_rem(lhs, rhs, "remtmp"),
        };
        Ok(TypedValue::new(res.unwrap().into(), new_type).into())
    }

    /// ===========================================
    /// ================== UTILS ==================
    /// ===========================================

    fn unwrap_arith_result(&self, lhs: TypeIdent, rhs: TypeIdent, span: Span, error_kind: CompilerErrorKind) -> CompileResult<TypeIdent> {
        match TypeIdent::arith_result(lhs, rhs) {
            Ok(new_type) => Ok(new_type),
            Err(_) => self.error(error_kind, span)
        }
    }
}

