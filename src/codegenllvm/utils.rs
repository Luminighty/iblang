use inkwell::values::BasicValueEnum;

use crate::typecheck::{atomic::Atomic, TypeIdent};

use super::{compiler::Compiler, typedvalue::TypedValue};
use std::cmp::Ordering;

enum CastMethod {
    Keep,
    Truncate,
    Extend,
    FloatToInt,
    IntToFloat,
}

impl<'ctx> Compiler<'ctx> {
    // TODO: This is no longer necessary
    pub fn cast_to_type(&mut self, value: TypedValue<'ctx>, new_type: TypeIdent, name: &str) -> BasicValueEnum<'ctx> {
        let cast_method = match (value.typeident, &new_type) {
            (TypeIdent::Atomic(lhs), TypeIdent::Atomic(rhs)) => Compiler::cast_atomic(lhs, rhs.clone()),
            (_from, _into) => todo!(),
        };

        match cast_method {
            CastMethod::Keep => value.value,
            CastMethod::Truncate => {
                let target_type = Compiler::int_type(self.context, &new_type).unwrap();
                self.builder.build_int_truncate(value.value.into_int_value(), target_type, name).unwrap().into()
            },
            CastMethod::Extend => {
                let target_type = Compiler::int_type(self.context, &new_type).unwrap();
                self.builder.build_int_z_extend(value.value.into_int_value(), target_type, name).unwrap().into()
            },
            CastMethod::IntToFloat => {
                let target_type = Compiler::float_type(self.context, &new_type).unwrap();
                self.builder.build_signed_int_to_float(value.value.into_int_value(), target_type, name).unwrap().into()
            },
            CastMethod::FloatToInt => {
                let target_type = Compiler::int_type(self.context, &new_type).unwrap();
                self.builder.build_float_to_signed_int(value.value.into_float_value(), target_type, name).unwrap().into()
            },
        }
    }

    fn cast_atomic(value: Atomic, new_type: Atomic) -> CastMethod {
        match (value, new_type) {
            (Atomic::Float, Atomic::Float) => CastMethod::Keep,
            (Atomic::Float, _) => CastMethod::FloatToInt,
            (_, Atomic::Float) => CastMethod::IntToFloat,
            (curr, new) => {
                match curr.bit_width().cmp(&new.bit_width()) {
                    Ordering::Less => CastMethod::Extend,
                    Ordering::Greater => CastMethod::Truncate,
                    Ordering::Equal => CastMethod::Keep,
                }
            }
        }
    }
}

