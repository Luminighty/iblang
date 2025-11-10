use crate::{
    codegenqbe::{
        bindings::VariableBinding,
        error::CompilerError,
        expr::typeident_into_abity,
        qbe::FunctionBuilder,
        statement::{CompiledStatement, compile_statement},
    },
    typecheck::{FlowType, TypeIdent, module::Module, prelude::Function},
};

use super::{CompilerResult, compiler::CompilerContext, statement::alloc_type};

pub fn compile_func(
    context: &mut CompilerContext,
    module: &Module,
    func: &Function,
) -> CompilerResult<()> {
    let fn_name = context.get_function(&func.prototype.symbol)?;

    let mut builder = FunctionBuilder::new(fn_name);
    if func.is_public {
        builder.export();
    }
    context.return_alloca = None;
    match &func.prototype.return_type {
        // NOTE: For structs, we alloc space for it before the call
        //  And then assume that the FIRST argument is the return_value
        FlowType::Some(ty) if ty.is_object() => {
            let temp = context.qbe.create_temp("return_alloca");
            let ty = typeident_into_abity(context, ty);
            context.return_alloca = Some(temp);
            builder.arg(ty, &temp);
        }
        FlowType::Some(ty) => {
            let ty = typeident_into_abity(context, &ty);
            builder.return_value(ty);
        }
        _ => {}
    }
    let mut temps = Vec::with_capacity(func.prototype.args.len());
    context.bindings.start_block();
    for (arg_name, arg_ty) in func.prototype.args.iter() {
        let temp = context.qbe.create_temp(arg_name);
        let ty = typeident_into_abity(context, arg_ty);
        builder.arg(ty, &temp);
        temps.push((arg_name, temp, arg_ty));
    }
    builder.start(&mut context.qbe)?;
    for (arg_name, temp, arg_ty) in temps {
        match arg_ty {
            // NOTE: For atomic values and refs, we need to alloc some space in order to modify them when
            // passing as value
            TypeIdent::Ref(_)
            | TypeIdent::Fn { .. }
            | TypeIdent::Atomic(_)
            | TypeIdent::Enum(_) => {
                let alloca = alloc_type(context, module, arg_ty, &arg_name)?;
                context.qbe.store(arg_ty, &temp, &alloca)?;
                context.bindings.insert(
                    arg_name.to_string(),
                    VariableBinding::new(alloca, arg_ty.clone()),
                );
            }
            // TODO: Do the same with small structs
            TypeIdent::Union(_) | TypeIdent::Array(_, _) | TypeIdent::Struct(_) => {
                context.bindings.insert(
                    arg_name.to_string(),
                    VariableBinding::new(temp, arg_ty.clone()),
                );
            }
        }
    }

    let res = compile_statement(context, module, &func.body)?;
    match res {
        CompiledStatement::Some => {
            context.qbe.ret()?;
        }
        _ => {}
    }
    match (&res, &func.prototype.return_type) {
        (CompiledStatement::Some, FlowType::Void) => {}
        (CompiledStatement::Return, _) => {}
        (CompiledStatement::Never, FlowType::Never) => {}
        (_, expected) => {
            return Err(CompilerError::InvalidReturnStatement {
                flow: res.clone(),
                expected: expected.clone(),
                got: FlowType::Void,
            });
        }
    }
    context.bindings.end_block();
    context.qbe.function_end()?;

    Ok(())
}
