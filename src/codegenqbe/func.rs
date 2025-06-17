use crate::{
    codegenqbe::{
        bindings::VariableBinding,
        error::CompilerError,
        expr::typeident_into_abity,
        qbe::{BaseTy, FunctionBuilder},
        statement::{CompiledStatement, compile_statement},
    },
    typecheck::{
        FlowType,
        module::Module,
        prelude::{Function, Prototype},
    },
};

use super::{CompileResult, compiler::CompilerContext};

pub fn compile_proto(context: &mut CompilerContext, proto: &Prototype) {
    let ptr = context.qbe.create_global(&proto.identifier);
    context.functions.insert(proto.identifier.clone(), ptr);
}

pub fn compile_func(
    context: &mut CompilerContext,
    module: &Module,
    func: &Function,
) -> CompileResult<()> {
    let fn_name = context.functions.get(&func.prototype.identifier).unwrap();

    // TODO: Once we have pub functions, remove .export() and add it based on its visibility
    let mut builder = FunctionBuilder::new(*fn_name).export();
    match &func.prototype.return_type {
        FlowType::Some(ty) => {
            let ty = typeident_into_abity(context, &ty);
            builder = builder.return_value(ty);
        }
        _ => {}
    }

    context.bindings.start_block();
    for (arg_name, arg_ty) in func.prototype.args.iter() {
        let temp = context.qbe.create_temp(arg_name);
        let ty = typeident_into_abity(context, arg_ty);
        builder = builder.arg(ty, &temp);
        context.bindings.insert(
            arg_name.to_string(),
            VariableBinding::new(temp, arg_ty.clone()),
        );
    }
    builder.start(&mut context.qbe)?;

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
