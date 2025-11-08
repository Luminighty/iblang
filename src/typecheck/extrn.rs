use crate::{
    ast::{
        AstModule,
        prelude::{AstExternFunction, AstExternGlobal},
    },
    symbol_resolver::{DeepInfo, ModuleUID},
    typecheck::{
        TypeResult, TypecheckError,
        checker::TypecheckContext,
        function::typecheck_proto,
        module::{ExternGlobal, Module},
        prelude::{Extern, Prototype},
        statement::typecheck_typeident,
    },
};
use std::collections::HashMap;
use std::rc::Rc;

fn typecheck_extern_global(
    context: &mut TypecheckContext,
    module_id: &ModuleUID,
    ext: &AstExternGlobal,
    errors: &mut Vec<TypecheckError>,
) {
    let mut cycle = Vec::new();
    let ty_res = typecheck_typeident(context, module_id, &ext.ty, ext.span, false, &mut cycle);
    match ty_res {
        Ok(ty) => {
            let ext_id = context
                .symbol_table
                .get_symbol_uid(&module_id, &ext.name)
                .unwrap();
            context
                .symbol_table
                .attach_deep(&ext_id, DeepInfo::ExternGlobal(Rc::new(ty.clone())));
            let global = ExternGlobal::new(ext.name.clone(), ext_id, ty, ext.span);
            let module: &mut Module = context.modules.get_mut(module_id).unwrap();
            module.extern_globals.push(global);
        }
        Err(err) => errors.push(err),
    }
}

fn typecheck_extern(
    context: &mut TypecheckContext,
    module_id: &ModuleUID,
    ext: &AstExternFunction,
    errors: &mut Vec<TypecheckError>,
) {
    let ext_id = context
        .symbol_table
        .get_symbol_uid(&module_id, &ext.prototype.identifier)
        .unwrap();
    match typecheck_proto(context, module_id, ext_id, &ext.prototype, &ext.span) {
        Ok(proto) => {
            let proto = Rc::new(proto);
            context
                .symbol_table
                .attach_deep(&ext_id, DeepInfo::extern_fn(proto.clone()));
            let extrn = Rc::new(Extern::new(proto, ext.span));
            let module = context
                .modules
                .get_mut(module_id)
                .expect(&format!("Module not found! {module_id}"));
            module.externs.push(extrn);
        }
        Err(err) => errors.push(err),
    }
}

pub fn typecheck_externs(
    context: &mut TypecheckContext,
    ast_modules: &HashMap<ModuleUID, AstModule>,
    errors: &mut Vec<TypecheckError>,
) {
    for (module_id, ast_module) in ast_modules {
        for ext in &ast_module.externs {
            typecheck_extern(context, module_id, ext, errors);
        }
        for ext in &ast_module.extern_globals {
            typecheck_extern_global(context, module_id, ext, errors);
        }
    }
}
