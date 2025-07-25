use crate::{
    codegenqbe::{
        bindings::VariableBinding,
        error::CompilerError,
        expr::typeident_into_abity,
        qbe::FunctionBuilder,
        statement::{CompiledStatement, compile_statement},
    },
    typecheck::{
        FlowType, TypeIdent,
        module::Module,
        prelude::{Function, Prototype},
    },
};

use super::{CompilerResult, compiler::CompilerContext, statement::alloc_type};

pub fn compile_proto(context: &mut CompilerContext, proto: &Prototype) {
    let ptr = context.qbe.create_global(&proto.identifier);
    context.functions.insert(proto.identifier.clone(), ptr);
}

pub fn compile_func(
    context: &mut CompilerContext,
    module: &Module,
    func: &Function,
) -> CompilerResult<()> {
    let fn_name = context.functions.get(&func.prototype.identifier).unwrap();

    // TODO: Once we have pub functions, remove .export() and add it based on its visibility
    let mut builder = FunctionBuilder::new(*fn_name);
    builder.export();
    match &func.prototype.return_type {
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
            TypeIdent::Ref(_) | TypeIdent::Atomic(_) => {
                let alloca = alloc_type(context, module, arg_ty, &arg_name)?;
                context.qbe.store(arg_ty, &temp, &alloca)?;
                context.bindings.insert(
                    arg_name.to_string(),
                    VariableBinding::new(alloca, arg_ty.clone()),
                );
            }
            // TODO: Do the same with small structs
            _ => {
                context.bindings.insert(
                    arg_name.to_string(),
                    VariableBinding::new(temp, arg_ty.clone()),
                );
            }
        }
    }

    let res = compile_statement(context, module, &func.body);
    match res {
        Ok(CompiledStatement::Some) => {
            context.qbe.ret()?;
        }
        _ => {}
    }
    match (&res, &func.prototype.return_type) {
        (Ok(CompiledStatement::Some), FlowType::Void) => {}
        (Ok(CompiledStatement::Return), _) => {}
        (Ok(CompiledStatement::Never), FlowType::Never) => {}
        (Ok(_), expected) => {
            return Err(CompilerError::InvalidReturnStatement {
                expected: expected.clone(),
                got: FlowType::Void,
            });
        }
        _ => {}
    }
    context.bindings.end_block();
    context.qbe.function_end()?;

    Ok(())
}
