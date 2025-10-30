use crate::{
    ast::{
        AstModule,
        prelude::{AstExternFunction, AstExternGlobal, AstGlobal},
    },
    symbol_resolver::{DeepInfo, ModuleUID},
    typecheck::{
        TypeResult, TypecheckError,
        checker::{TypecheckContext, TypecheckFuncContext},
        const_eval::const_eval_expr,
        expr::typecheck_expr,
        module::{ExternGlobal, Global},
        prelude::{Extern, Prototype},
        statement::{typecheck_typeident, var_declaration},
    },
};
use std::collections::HashMap;
use std::rc::Rc;

fn typecheck_global(
    global_context: &mut TypecheckContext,
    context: &mut TypecheckFuncContext,
    module_id: &ModuleUID,
    global: &AstGlobal,
    errors: &mut Vec<TypecheckError>,
) {
    let var_res = var_declaration(
        global_context,
        context,
        &global.value,
        &global.name,
        &global.ty,
        global.mutable,
        global.span,
    );
    let (value_type, value) = match var_res {
        Ok((value_type, value)) => (value_type, value),
        Err(err) => {
            errors.push(err);
            return;
        }
    };
    let value = match const_eval_expr(context, &value) {
        Ok(value) => value,
        Err(err) => {
            errors.push(err);
            return;
        }
    };
    let global_id = global_context
        .symbol_table
        .get_symbol_uid(&module_id, &global.name)
        .unwrap();
    global_context
        .symbol_table
        .attach_deep(&global_id, DeepInfo::Global(Rc::new(value_type.clone())));
    let global = Global::new(
        global.name.clone(),
        global_id,
        value,
        value_type,
        global.is_public,
        global.mutable,
        global.span,
    );
    let module = global_context.modules.get_mut(module_id).unwrap();
    module.globals.push(global);
}

pub fn typecheck_globals(
    global_context: &mut TypecheckContext,
    ast_modules: &HashMap<ModuleUID, AstModule>,
    errors: &mut Vec<TypecheckError>,
) {
    for (module_id, ast_module) in ast_modules {
        let mut context = TypecheckFuncContext::new(*module_id);
        for global in &ast_module.globals {
            typecheck_global(global_context, &mut context, module_id, global, errors);
        }
    }
}
