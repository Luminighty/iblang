use crate::{
    ast::prelude::*,
    symbol_resolver::{DeepInfo, ModuleUID, SymbolUID},
    typecheck::{
        TypeResult, VarBinding,
        checker::TypecheckContext,
        error::TypecheckErrorKind,
        statement::{typecheck_statement, typecheck_typeident},
    },
    utils::Span,
};

use super::{
    checker::TypecheckFuncContext,
    error::TypecheckError,
    statement::Statement,
    typeident::{FlowType, TypeIdent},
};
use std::collections::HashMap;
use std::rc::Rc;

#[derive(Debug, Clone)]
pub struct Prototype {
    pub identifier: String,
    pub symbol: SymbolUID,
    pub args: Vec<(Identifier, TypeIdent)>,
    pub return_type: FlowType,
    pub has_varargs: bool,
}

#[derive(Debug)]
pub struct Extern {
    pub prototype: Rc<Prototype>,
    #[allow(dead_code)]
    pub span: Span,
}

#[derive(Debug)]
pub struct Function {
    pub prototype: Rc<Prototype>,
    pub body: Statement,
    #[allow(dead_code)]
    pub span: Span,
    pub is_public: bool,
}

impl Prototype {
    pub fn new(
        identifier: String,
        symbol: SymbolUID,
        args: Vec<(Identifier, TypeIdent)>,
        return_type: FlowType,
        has_varargs: bool,
    ) -> Self {
        Self {
            identifier,
            symbol,
            args,
            return_type,
            has_varargs,
        }
    }

    pub fn typeident(&self) -> TypeIdent {
        let mut args = Vec::with_capacity(self.args.len());
        for arg in &self.args {
            args.push(arg.1.clone())
        }
        TypeIdent::Fn {
            args,
            has_varargs: self.has_varargs,
            return_type: Box::new(self.return_type.clone()),
        }
    }
}

impl Function {
    pub fn new(prototype: Rc<Prototype>, body: Statement, span: Span, is_public: bool) -> Self {
        Self {
            prototype: prototype,
            body,
            span,
            is_public,
        }
    }
}

impl Extern {
    pub fn new(prototype: Rc<Prototype>, span: Span) -> Self {
        Self {
            prototype: prototype,
            span,
        }
    }
}

#[allow(dead_code)]
impl Function {
    pub fn write(&self, f: &mut dyn std::io::Write, depth: usize) -> std::io::Result<()> {
        writeln!(f, "{:width$}", "", width = depth)?;
        writeln!(f, "{} ", self.prototype)?;
        self.body.write(f, depth)
    }
}

impl std::fmt::Display for Function {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let depth = f.width().unwrap_or(0);
        write!(f, "{:width$}", "", width = depth)?;
        write!(f, "{} ", self.prototype)?;
        write!(f, "{:?}", self.body)
    }
}

impl std::fmt::Display for Extern {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "extern {}", self.prototype)
    }
}

impl std::fmt::Display for Prototype {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "fn {}(", self.identifier)?;
        for (i, arg) in self.args.iter().enumerate() {
            write!(f, "{}: {}", arg.0, arg.1)?;
            if self.args.len() > i + 1 {
                write!(f, ", ")?;
            }
        }
        write!(f, ")")
    }
}

pub fn typecheck_proto(
    context: &mut TypecheckContext,
    module_id: &ModuleUID,
    proto_id: SymbolUID,
    proto: &AstPrototype,
    span: &Span,
) -> TypeResult<Prototype> {
    let mut args = Vec::with_capacity(proto.args.len());
    let mut cycle = Vec::new();
    for (ident, ty) in &proto.args {
        let arg_type =
            typecheck_typeident(context, &module_id, ty, Span::new(0, 0), false, &mut cycle)?;
        args.push((ident.to_string(), arg_type));
    }

    let return_type = match &proto.return_type {
        AstFlowType::Some(ty) => FlowType::Some(typecheck_typeident(
            context,
            &module_id,
            ty,
            Span::new(0, 0),
            false,
            &mut cycle,
        )?),
        AstFlowType::Void => FlowType::Void,
        AstFlowType::Never => FlowType::Never,
    };
    match return_type {
        FlowType::Some(ty) if ty.is_array() => {
            return Err(TypecheckError::new(
                TypecheckErrorKind::InvalidReturnTypeArray,
                *module_id,
                *span,
            ));
        }
        _ => {}
    }

    Ok(Prototype::new(
        proto.identifier.to_string(),
        proto_id,
        args,
        return_type,
        proto.has_varargs,
    ))
}

pub fn typecheck_func(
    global_context: &mut TypecheckContext,
    context: &mut TypecheckFuncContext,
    func: &AstFunction,
    errors: &mut Vec<TypecheckError>,
) {
    let proto_id = global_context
        .symbol_table
        .get_symbol_uid(&context.module_id, &func.prototype.identifier)
        .unwrap();
    let proto = global_context.symbol_table.get_symbol(&proto_id).unwrap();
    let proto = match proto.deep_function() {
        Ok(proto) => proto,
        Err(err) => {
            errors.push(TypecheckError::new(
                TypecheckErrorKind::SymbolError(err),
                context.module_id,
                func.span,
            ));
            return;
        }
    };

    context.bindings.start_block();
    for (ident, ty) in &proto.args {
        context
            .bindings
            .insert(ident.clone(), VarBinding::new(ty.clone(), true));
    }
    context.prototype_opt = Some(proto.clone());
    let body = match typecheck_statement(global_context, context, &func.body) {
        Ok(body) => body,
        Err(err) => {
            errors.push(err);
            return;
        }
    };
    context.bindings.end_block();
    context.prototype_opt = None;

    if context.is_logging {
        println!("{body:#?}");
    }
    let mut is_public = func.is_public;
    // NOTE: We need main to use the canonical name
    // TODO: Only set this for the main function in from the entry module
    if proto.identifier == "main" {
        global_context.symbol_table.set_extern(&proto_id);
        global_context.symbol_table.set_public(&proto_id);
        is_public = true;
    }

    let module = global_context.modules.get_mut(&context.module_id).unwrap();
    let func = Rc::new(Function::new(proto, body, func.span, is_public));
    module.functions.push(func);
}

fn typecheck_fn_prototype(
    context: &mut TypecheckContext,
    module_id: &ModuleUID,
    func: &AstFunction,
    errors: &mut Vec<TypecheckError>,
) {
    let proto_id = context
        .symbol_table
        .get_symbol_uid(&module_id, &func.prototype.identifier)
        .unwrap();
    match typecheck_proto(context, module_id, proto_id, &func.prototype, &func.span) {
        Ok(proto) => {
            let proto = Rc::new(proto);
            context
                .symbol_table
                .attach_deep(&proto_id, DeepInfo::function(proto.clone()));
            // let _module = context.modules.get_mut(module_id).unwrap();
        }
        Err(err) => {
            errors.push(err);
        }
    }
}

pub fn typecheck_prototypes(
    global_context: &mut TypecheckContext,
    ast_modules: &HashMap<ModuleUID, AstModule>,
    errors: &mut Vec<TypecheckError>,
) {
    for (module_id, ast_module) in ast_modules {
        for func in &ast_module.functions {
            typecheck_fn_prototype(global_context, module_id, func, errors);
        }
    }
}

pub fn typecheck_functions(
    global_context: &mut TypecheckContext,
    ast_modules: &HashMap<ModuleUID, AstModule>,
    errors: &mut Vec<TypecheckError>,
) {
    for (module_id, ast_module) in ast_modules {
        let mut context = TypecheckFuncContext::new(*module_id);
        for func in &ast_module.functions {
            typecheck_func(global_context, &mut context, func, errors);
        }
    }
}
