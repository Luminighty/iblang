use crate::{
    ast::prelude::Literal,
    codegenqbe::{
        expr::{CompileExprResult, CompiledExpr},
        qbe::{BaseTy, DataBuilder, ExtTy, ZeroInit},
    },
    symbol_resolver::{Symbol, SymbolUID},
    typecheck::{
        TypeIdent,
        const_eval::ConstExpr,
        module::{ExternGlobal, Global, Module},
    },
};

use super::{CompilerResult, compiler::CompilerContext};

fn compile_const_expr_data(
    context: &CompilerContext,
    module: &Module,
    builder: &mut DataBuilder,
    e: &ConstExpr,
) -> CompilerResult<()> {
    use BaseTy::*;
    match e {
        ConstExpr::Literal(literal) => match literal {
            Literal::Number(v) => builder.push((L, *v)),
            Literal::Bool(v) => builder.push((ExtTy::B, *v as i64)),
            Literal::Char(v) => builder.push((ExtTy::B, *v as i64)),
            Literal::Float(v) => builder.push((D, *v)),
            Literal::Null => builder.push((L, 0)),
        },
        ConstExpr::Array(values) => {
            for value in values {
                compile_const_expr_data(context, module, builder, value)?;
            }
        }
        ConstExpr::Union(field_name, value, ty) => {
            let union_symbol: &Symbol = match ty {
                TypeIdent::Union(uid) => context
                    .symbol_table
                    .get_symbol(uid)
                    .expect("Union not found"),
                _ => panic!("Non union type was passed to union_init"),
            };
            let union_def = union_symbol.deep_union()?;
            for (_i, (field, _)) in union_def.fields.iter().enumerate() {
                if field_name != field {
                    continue;
                }
                builder.start_block();
                compile_const_expr_data(context, module, builder, value)?;
                builder.end_block();
            }
        }
        ConstExpr::Struct(values, ty) => {
            let struct_symbol: &Symbol = match ty {
                TypeIdent::Struct(uid) => context
                    .symbol_table
                    .get_symbol(uid)
                    .expect("Struct not found"),
                _ => panic!("Non struct type was passed to struct_init"),
            };
            let struct_def = struct_symbol.deep_struct()?;
            let is_zero_init = values.len() == 0;
            if is_zero_init {
                builder.push(ZeroInit(struct_def.size));
                return Ok(());
            }
            for (i, (field, _)) in struct_def.fields.iter().enumerate() {
                builder.start_block();
                for (other, value) in values {
                    if field == other {
                        compile_const_expr_data(context, module, builder, value)?;
                    }
                }
                builder.end_block();
                if let Some(offset) = struct_def.field_offsets.get(i + 1) {
                    let builder_offset = builder.current_offset();
                    if builder_offset < *offset {
                        let diff = offset - builder_offset;
                        builder.push(ZeroInit(diff));
                    } else if builder_offset > *offset {
                        panic!(
                            "Struct field was larger than expected\n{struct_def:?}\n{builder:?}"
                        );
                    }
                }
            }
        }
    }
    Ok(())
}

pub fn compile_global(
    context: &mut CompilerContext,
    module: &Module,
    global: &Global,
) -> CompilerResult<()> {
    let qbe_global = context.get_global(&global.symbol).unwrap();
    let mut builder = DataBuilder::new(qbe_global);
    builder.set_public(global.is_public);
    compile_const_expr_data(context, module, &mut builder, &global.value)?;

    let qbe_global = builder.build(&mut context.qbe)?;
    context.globals.insert(global.symbol, qbe_global);

    Ok(())
}

pub fn compile_global_lookup(
    context: &mut CompilerContext,
    _module: &Module,
    symbol: SymbolUID,
    _ty: &TypeIdent,
) -> CompileExprResult {
    Ok(CompiledExpr::Global(context.get_global_or_fn(&symbol)?))
}

#[allow(unused)]
pub fn compile_extern_global(
    context: &mut CompilerContext,
    global: &ExternGlobal,
) -> CompilerResult<()> {
    let _ = context.qbe.create_global(&global.name, true)?;
    // context.qbe.write_external_global(&g)?;
    // context.globals.insert(global.name.to_string(), g);
    Ok(())
}

#[derive(PartialEq, Eq, Hash)]
pub enum BuiltInGlobal {
    PanicMatchArmValue,
}

impl BuiltInGlobal {
    pub fn to_str(&self) -> &'static str {
        match self {
            BuiltInGlobal::PanicMatchArmValue => {
                "Assertion error! Exhaustive enum pattern used, but non-enum value was passed.\n"
            }
        }
    }
}

pub const BUILT_IN_GLOBALS: [BuiltInGlobal; 1] = [BuiltInGlobal::PanicMatchArmValue];
