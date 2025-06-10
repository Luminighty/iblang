use inkwell::{
    AddressSpace,
    context::Context,
    types::{BasicType, BasicTypeEnum, FloatType, IntType},
    values::BasicValueEnum,
};

use crate::typecheck::{
    TypeIdent,
    atomic::{Atomic, Numeric},
};

use super::{compiler::Compiler, expr::CompiledExpr};

#[derive(Debug, Clone)]
pub struct TypedValue<'ctx> {
    pub typeident: TypeIdent,
    pub value: BasicValueEnum<'ctx>,
}

impl<'ctx> TypedValue<'ctx> {
    pub fn new(value: BasicValueEnum<'ctx>, typeident: TypeIdent) -> Self {
        Self { value, typeident }
    }

    pub fn num(value: BasicValueEnum<'ctx>) -> Self {
        Self::new(value, TypeIdent::Atomic(Atomic::int()))
    }
    pub fn bool(value: BasicValueEnum<'ctx>) -> Self {
        Self::new(value, TypeIdent::Atomic(Atomic::bool()))
    }
    pub fn char(value: BasicValueEnum<'ctx>) -> Self {
        Self::new(value, TypeIdent::Atomic(Atomic::char()))
    }
    pub fn float(value: BasicValueEnum<'ctx>) -> Self {
        Self::new(value, TypeIdent::Atomic(Atomic::Float))
    }
}

impl<'ctx> Compiler<'ctx> {
    pub fn inkwell_type(context: &'ctx Context, from: &TypeIdent) -> BasicTypeEnum<'ctx> {
        match from {
            TypeIdent::Atomic(Atomic::Number(n)) => match n {
                Numeric::Int => context.i64_type().into(),
                Numeric::Char => context.i8_type().into(),
                Numeric::Bool => context.bool_type().into(),
            },
            TypeIdent::Ref(_r) => context.ptr_type(AddressSpace::default()).into(),
            TypeIdent::Atomic(Atomic::Float) => context.f64_type().into(),
            TypeIdent::Array(ty, len) => Compiler::inkwell_type(context, ty)
                .array_type(*len as u32)
                .into(),
            TypeIdent::Struct(_) => todo!(),
        }
    }

    pub fn int_type(context: &'ctx Context, from: &TypeIdent) -> Result<IntType<'ctx>, ()> {
        match from {
            TypeIdent::Atomic(Atomic::Number(n)) => match n {
                Numeric::Int => Ok(context.i64_type()),
                Numeric::Char => Ok(context.i8_type()),
                Numeric::Bool => Ok(context.bool_type()),
            },
            TypeIdent::Ref(_r) => panic!("Tried to get IntType out of a float"),
            TypeIdent::Atomic(Atomic::Float) => panic!("Tried to get IntType out of a float"),
            TypeIdent::Array(_, _) => panic!("Tried to get IntType out of a Array"),
            TypeIdent::Struct(_) => panic!("Tried to get IntType out of a struct"),
        }
    }

    pub fn float_type(context: &'ctx Context, from: &TypeIdent) -> Result<FloatType<'ctx>, ()> {
        match from {
            TypeIdent::Atomic(Atomic::Float) => Ok(context.f64_type()),
            _ => panic!("Tried to get IntType out of a float"),
        }
    }
}

impl<'ctx> From<TypedValue<'ctx>> for CompiledExpr<'ctx> {
    fn from(value: TypedValue<'ctx>) -> Self {
        CompiledExpr::Value(value)
    }
}
