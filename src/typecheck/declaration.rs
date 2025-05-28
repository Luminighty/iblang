use crate::{ast::{AstExtern, AstFlowType, AstFunction, AstGlobal, AstPrototype}, typecheck::{statement::{typecheck_statement, typecheck_typeident}, FlowType}};

use super::{checker::TypecheckContext, function::{Extern, Function, Prototype}, TypeResult};



pub fn typecheck_proto(context: &TypecheckContext, proto: &AstPrototype) -> TypeResult<Prototype> {
    let mut args = Vec::with_capacity(proto.args.len());
    for (ident, ty) in &proto.args {
        args.push((ident.to_string(), typecheck_typeident(context, ty)?));
    }
    let return_type = match &proto.return_type {
        AstFlowType::Some(ty) => FlowType::Some(typecheck_typeident(context, ty)?),
        AstFlowType::Void => FlowType::Void,
        AstFlowType::Never => FlowType::Never,
    };

    Ok(Prototype::new(proto.identifier.to_string(), args, return_type))
}

pub fn typecheck_func(context: &mut TypecheckContext, proto: Prototype, func: &AstFunction) -> TypeResult<Function> {
    context.bindings.start_block();
    for (ident, ty) in &proto.args {
        context.bindings.insert(ident.clone(), ty.clone());
    }
    let body = typecheck_statement(context, &func.body)?;
    context.bindings.end_block();

    Ok(Function::new(proto, body, func.span))
}

pub fn typecheck_extern(context: &TypecheckContext, proto: Prototype, ext: &AstExtern) -> TypeResult<Extern> {
    Ok(Extern::new(proto, ext.span))
}

pub fn typecheck_global(context: &TypecheckContext, func: &AstGlobal) -> TypeResult<()> {
    Ok(())
}
