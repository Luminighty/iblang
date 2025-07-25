use crate::{
    ast::prelude::*,
    typecheck::{
        FlowType,
        statement::{typecheck_statement, typecheck_typeident},
    },
    utils::Span,
};

use super::{
    TypeResult,
    checker::TypecheckContext,
    function::{Extern, Function, Prototype},
};

pub fn typecheck_proto(context: &TypecheckContext, proto: &AstPrototype) -> TypeResult<Prototype> {
    let mut args = Vec::with_capacity(proto.args.len());
    for (ident, ty) in &proto.args {
        let arg_type = typecheck_typeident(context, ty, Span::new(0, 0))?;
        args.push((ident.to_string(), arg_type));
    }
    let return_type = match &proto.return_type {
        AstFlowType::Some(ty) => FlowType::Some(typecheck_typeident(context, ty, Span::new(0, 0))?),
        AstFlowType::Void => FlowType::Void,
        AstFlowType::Never => FlowType::Never,
    };

    Ok(Prototype::new(
        proto.identifier.to_string(),
        args,
        return_type,
    ))
}

pub fn typecheck_func(
    context: &mut TypecheckContext,
    proto: Prototype,
    func: &AstFunction,
) -> TypeResult<Function> {
    context.bindings.start_block();
    for (ident, ty) in &proto.args {
        context.bindings.insert(ident.clone(), ty.clone());
    }
    context.prototype_opt = Some(proto.clone());
    let body = typecheck_statement(context, &func.body)?;
    context.bindings.end_block();
    context.prototype_opt = None;

    if context.is_logging {
        println!("{body:#?}");
    }

    Ok(Function::new(proto, body, func.span))
}

pub fn typecheck_extern(
    _context: &TypecheckContext,
    proto: Prototype,
    ext: &AstExtern,
) -> TypeResult<Extern> {
    Ok(Extern::new(proto, ext.span))
}

#[allow(unused)]
pub fn typecheck_global(context: &TypecheckContext, func: &AstGlobal) -> TypeResult<()> {
    Ok(())
}
