use super::{
    compiler::Compiler, error::CompilerErrorKind, expr::CompileExprResult, typedvalue::TypedValue,
};
use crate::typecheck::prelude::*;
use crate::{
    ast::prelude::*,
    typecheck::{CastMethod, TypeIdent, atomic::Atomic},
    utils::Span,
};
use inkwell::{
    FloatPredicate, IntPredicate,
    values::{FloatValue, IntValue},
};

#[allow(unused_variables, dead_code)]
impl<'ctx> Compiler<'ctx> {
    pub fn compile_assign(
        &mut self,
        module: &Module,
        lhs: &Expr,
        rhs: &Expr,
        span: Span,
    ) -> CompileExprResult<'ctx> {
        let ident_span = lhs.span;
        let ident = self.compile_expr(module, lhs)?;
        let value = self.load_value(
            ident,
            CompilerErrorKind::IdentifierExpected,
            ident_span,
            "assignee",
        )?;

        let rhs_span = rhs.span;
        let rhs = self.compile_expr(module, rhs)?;
        let rhs = self.load_value(rhs, CompilerErrorKind::ValueExpected, rhs_span, "assign")?;

        self.builder
            .build_store(value.value.into_pointer_value(), rhs.value)
            .unwrap();
        Ok(value.into())
    }

    /// ================================================
    /// ================== PREDICATE ==================
    /// ================================================
    pub fn compile_pred(
        &mut self,
        module: &Module,
        op: &BinaryPred,
        lhs: &Expr,
        rhs: &Expr,
        shared: &TypeIdent,
        span: Span,
    ) -> CompileExprResult<'ctx> {
        let lhs_span = lhs.span;
        let rhs_span = rhs.span;
        let lhs = self.compile_expr(module, lhs)?;
        let lhs = self.load_value(lhs, CompilerErrorKind::ValueExpected, lhs_span, "pred_lhs")?;

        let rhs = self.compile_expr(module, rhs)?;
        let rhs = self.load_value(rhs, CompilerErrorKind::ValueExpected, rhs_span, "pred_rhs")?;

        match shared {
            TypeIdent::Atomic(Atomic::Float) => self.compile_float_pred(
                op,
                lhs.value.into_float_value(),
                rhs.value.into_float_value(),
                span,
            ),
            TypeIdent::Atomic(_) => {
                self.compile_int_pred(op, lhs.value.into_int_value(), rhs.value.into_int_value())
            }
            _ => todo!(),
        }
    }

    fn compile_int_pred(
        &mut self,
        op: &BinaryPred,
        lhs: IntValue<'ctx>,
        rhs: IntValue<'ctx>,
    ) -> CompileExprResult<'ctx> {
        let new_type = TypeIdent::Atomic(Atomic::bool());
        macro_rules! unwrap {
            ($result: expr) => {
                Ok(TypedValue::new($result.unwrap().into(), new_type).into())
            };
        }
        macro_rules! comp_int {
            ($pred: expr, $name: expr) => {
                unwrap!(self.builder.build_int_compare($pred, lhs, rhs, $name))
            };
        }

        match op {
            BinaryPred::And => unwrap!(self.builder.build_and(lhs, rhs, "and_tmp")),
            BinaryPred::Or => unwrap!(self.builder.build_or(lhs, rhs, "or_tmp")),
            BinaryPred::EQ => comp_int!(IntPredicate::EQ, "eq_tmp"),
            BinaryPred::NE => comp_int!(IntPredicate::NE, "ne_tmp"),
            BinaryPred::GT => comp_int!(IntPredicate::SGT, "gt_tmp"),
            BinaryPred::GE => comp_int!(IntPredicate::SGE, "ge_tmp"),
            BinaryPred::LT => comp_int!(IntPredicate::SLT, "lt_tmp"),
            BinaryPred::LE => comp_int!(IntPredicate::SLE, "le_tmp"),
        }
    }

    fn compile_float_pred(
        &mut self,
        op: &BinaryPred,
        lhs: FloatValue<'ctx>,
        rhs: FloatValue<'ctx>,
        span: Span,
    ) -> CompileExprResult<'ctx> {
        let new_type = TypeIdent::Atomic(Atomic::bool());
        macro_rules! unwrap {
            ($result: expr) => {
                Ok(TypedValue::new($result.unwrap().into(), new_type).into())
            };
        }
        macro_rules! comp_float {
            ($pred: expr, $name: expr) => {
                unwrap!(self.builder.build_float_compare($pred, lhs, rhs, $name))
            };
        }

        match op {
            BinaryPred::And => self.error(
                CompilerErrorKind::BinaryTypeMismatch {
                    lhs: TypeIdent::Atomic(Atomic::Float),
                    rhs: TypeIdent::Atomic(Atomic::Float),
                    op: BinaryPred::And.into(),
                },
                span,
            ),
            BinaryPred::Or => self.error(
                CompilerErrorKind::BinaryTypeMismatch {
                    lhs: TypeIdent::Atomic(Atomic::Float),
                    rhs: TypeIdent::Atomic(Atomic::Float),
                    op: BinaryPred::Or.into(),
                },
                span,
            ),
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

    pub fn compile_arith(
        &mut self,
        module: &Module,
        op: &BinaryArith,
        lhs: &Expr,
        rhs: &Expr,
        ty: &TypeIdent,
        span: Span,
    ) -> CompileExprResult<'ctx> {
        let lhs_span = lhs.span;
        let rhs_span = rhs.span;
        let lhs = self.compile_expr(module, lhs)?;
        let lhs = self.load_value(lhs, CompilerErrorKind::ValueExpected, lhs_span, "arith_lhs")?;
        let rhs = self.compile_expr(module, rhs)?;
        let rhs = self.load_value(rhs, CompilerErrorKind::ValueExpected, rhs_span, "arith_rhs")?;

        match ty {
            TypeIdent::Atomic(Atomic::Float) => self.compile_float_arith(
                op,
                lhs.value.into_float_value(),
                rhs.value.into_float_value(),
                ty,
            ),
            TypeIdent::Atomic(_) => self.compile_int_arith(
                op,
                lhs.value.into_int_value(),
                rhs.value.into_int_value(),
                ty,
            ),
            _ => todo!(),
        }
    }

    fn compile_int_arith(
        &mut self,
        op: &BinaryArith,
        lhs: IntValue<'ctx>,
        rhs: IntValue<'ctx>,
        new_type: &TypeIdent,
    ) -> CompileExprResult<'ctx> {
        let res = match op {
            BinaryArith::Add => self.builder.build_int_add(lhs, rhs, "addtmp"),
            BinaryArith::Sub => self.builder.build_int_sub(lhs, rhs, "subtmp"),
            BinaryArith::Mul => self.builder.build_int_mul(lhs, rhs, "multmp"),
            BinaryArith::Div => self.builder.build_int_signed_div(lhs, rhs, "divtmp"),
            BinaryArith::Rem => self.builder.build_int_signed_rem(lhs, rhs, "remtmp"),
        };
        Ok(TypedValue::new(res.unwrap().into(), new_type.clone()).into())
    }

    fn compile_float_arith(
        &mut self,
        op: &BinaryArith,
        lhs: FloatValue<'ctx>,
        rhs: FloatValue<'ctx>,
        new_type: &TypeIdent,
    ) -> CompileExprResult<'ctx> {
        let res = match op {
            BinaryArith::Add => self.builder.build_float_add(lhs, rhs, "addtmp"),
            BinaryArith::Sub => self.builder.build_float_sub(lhs, rhs, "subtmp"),
            BinaryArith::Mul => self.builder.build_float_mul(lhs, rhs, "multmp"),
            BinaryArith::Div => self.builder.build_float_div(lhs, rhs, "divtmp"),
            BinaryArith::Rem => self.builder.build_float_rem(lhs, rhs, "remtmp"),
        };
        Ok(TypedValue::new(res.unwrap().into(), new_type.clone()).into())
    }

    pub fn compile_cast(
        &mut self,
        module: &Module,
        expr: &Expr,
        new_type: &TypeIdent,
        method: &CastMethod,
        span: Span,
    ) -> CompileExprResult<'ctx> {
        let expr = self.compile_expr(module, expr)?;

        match method {
            CastMethod::Keep => Ok(expr),
            CastMethod::Truncate => {
                let value =
                    self.load_value(expr, CompilerErrorKind::ValueExpected, span, "castee")?;
                let target_type = Compiler::int_type(self.context, &new_type).unwrap();
                let value = self
                    .builder
                    .build_int_truncate(value.value.into_int_value(), target_type, "cast_trunc")
                    .unwrap()
                    .into();
                Ok(TypedValue::new(value, new_type.clone()).into())
            }
            CastMethod::Extend => {
                let value =
                    self.load_value(expr, CompilerErrorKind::ValueExpected, span, "castee")?;
                let target_type = Compiler::int_type(self.context, &new_type).unwrap();
                let value = self
                    .builder
                    .build_int_z_extend(value.value.into_int_value(), target_type, "cast_extend")
                    .unwrap()
                    .into();
                Ok(TypedValue::new(value, new_type.clone()).into())
            }
            CastMethod::IntToFloat => {
                let value =
                    self.load_value(expr, CompilerErrorKind::ValueExpected, span, "castee")?;
                let target_type = Compiler::float_type(self.context, &new_type).unwrap();
                let value = self
                    .builder
                    .build_signed_int_to_float(
                        value.value.into_int_value(),
                        target_type,
                        "cast_int_to_float",
                    )
                    .unwrap()
                    .into();
                Ok(TypedValue::new(value, new_type.clone()).into())
            }
            CastMethod::FloatToInt => {
                let value =
                    self.load_value(expr, CompilerErrorKind::ValueExpected, span, "castee")?;
                let target_type = Compiler::int_type(self.context, &new_type).unwrap();
                let value = self
                    .builder
                    .build_float_to_signed_int(
                        value.value.into_float_value(),
                        target_type,
                        "cast_float_to_int",
                    )
                    .unwrap()
                    .into();
                Ok(TypedValue::new(value, new_type.clone()).into())
            }
        }
    }
}
