use crate::{
    ast::prelude::Literal,
    codegenqbe::{
        bindings::VariableBinding,
        error::CompilerError,
        expr::{CompileExprResult, CompiledExpr, typeident_into_abity},
        qbe::{BaseTy, DataBuilder, ExtTy, FunctionBuilder, QbeDataField, ZeroInit},
        statement::{CompiledStatement, compile_statement},
    },
    typecheck::{
        FlowType, TypeIdent,
        const_eval::ConstExpr,
        module::{ExternGlobal, Global, Module},
        prelude::{Function, Prototype},
    },
};

use super::{CompilerResult, compiler::CompilerContext, statement::alloc_type};

fn compile_const_expr_data(module: &Module, builder: &mut DataBuilder, e: &ConstExpr) {
    use BaseTy::*;
    match e {
        ConstExpr::Literal(literal) => match literal {
            Literal::Number(v) => builder.push((L, *v)),
            Literal::Bool(v) => builder.push((W, *v as i64)),
            Literal::Char(v) => builder.push((W, *v as i64)),
            Literal::Float(v) => builder.push((D, *v)),
        },
        ConstExpr::Array(values) => {
            for value in values {
                compile_const_expr_data(module, builder, value);
            }
        }
        ConstExpr::Struct(values, ty) => {
            let struct_def = match ty {
                TypeIdent::Struct(ident) => module.get_struct(ident).expect("Struct not found"),
                _ => panic!("Non struct type was passed to struct_init"),
            };
            // println!("{:?}", struct_def);
            // println!("{:?}", values);
            for (i, (field, _)) in struct_def.fields.iter().enumerate() {
                builder.start_block();
                for (other, value) in values {
                    if field == other {
                        compile_const_expr_data(module, builder, value);
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
}

pub fn compile_global(
    context: &mut CompilerContext,
    module: &Module,
    global: &Global,
) -> CompilerResult<()> {
    let mut builder = DataBuilder::new(context.qbe.create_global(&global.name, false)?);
    compile_const_expr_data(module, &mut builder, &global.value);

    let qbe_global = builder.build(&mut context.qbe)?;

    context.globals.insert(global.name.to_string(), qbe_global);

    Ok(())
}

pub fn compile_global_lookup(
    context: &mut CompilerContext,
    _module: &Module,
    var: &str,
    _ty: &TypeIdent,
) -> CompileExprResult {
    if let Some(b) = context.globals.get(var) {
        Ok(CompiledExpr::Global(b.clone()))
    } else {
        Err(CompilerError::UndefinedVariable {
            var: var.to_owned(),
        })
    }
}

pub fn compile_extern_global(
    context: &mut CompilerContext,
    global: &ExternGlobal,
) -> CompilerResult<()> {
    let g = context.qbe.create_global(&global.name, true)?;
    // context.qbe.write_external_global(&g)?;
    context.globals.insert(global.name.to_string(), g);
    Ok(())
}
