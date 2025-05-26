use inkwell::{context::Context, types::{BasicTypeEnum, FloatType, IntType}, values::BasicValueEnum};

use crate::types::{atomic::Atomic, TypeIdent};

use super::{compiler::Compiler, expr::CompiledExpr};

 
#[derive(Debug, Copy, Clone)]
pub struct TypedValue<'ctx> {
    pub typeident: TypeIdent,
    pub value: BasicValueEnum<'ctx>,
}


impl<'ctx> TypedValue<'ctx> {
    pub fn new(value: BasicValueEnum<'ctx>, typeident: TypeIdent) -> Self {
        Self { value, typeident }
    }

    pub fn num(value: BasicValueEnum<'ctx>) -> Self { Self::new(value, TypeIdent::Atomic(Atomic::Number)) }
    pub fn bool(value: BasicValueEnum<'ctx>) -> Self { Self::new(value, TypeIdent::Atomic(Atomic::Bool)) }
    pub fn char(value: BasicValueEnum<'ctx>) -> Self { Self::new(value, TypeIdent::Atomic(Atomic::Char)) }
    pub fn float(value: BasicValueEnum<'ctx>) -> Self { Self::new(value, TypeIdent::Atomic(Atomic::Float)) }
}


impl<'ctx> Compiler<'ctx> {
    pub fn inkwell_type(context: &'ctx Context, from: &TypeIdent) -> BasicTypeEnum<'ctx> {
        match from {
            TypeIdent::Atomic(Atomic::Number) => context.i64_type().into(),
            TypeIdent::Atomic(Atomic::Char) => context.i8_type().into(),
            TypeIdent::Atomic(Atomic::Bool) => context.bool_type().into(),
            TypeIdent::Atomic(Atomic::Float) => context.f64_type().into(),
        }
    }

    pub fn int_type(context: &'ctx Context, from: &TypeIdent) -> Result<IntType<'ctx>, ()> {
        match from {
            TypeIdent::Atomic(Atomic::Number) => Ok(context.i64_type()),
            TypeIdent::Atomic(Atomic::Char) => Ok(context.i8_type()),
            TypeIdent::Atomic(Atomic::Bool) => Ok(context.bool_type()),
            TypeIdent::Atomic(Atomic::Float) => panic!("Tried to get IntType out of a float"),
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

