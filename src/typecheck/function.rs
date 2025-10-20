use std::collections::VecDeque;

use crate::{
    ast::prelude::*,
    symbol_resolver::DeepInfo,
    typecheck::declaration::{
        typecheck_extern, typecheck_extern_global, typecheck_func, typecheck_proto,
    },
    utils::Span,
};

use super::{
    checker::TypecheckContext,
    error::TypecheckError,
    statement::Statement,
    typeident::{FlowType, TypeIdent},
};
use std::rc::Rc;

#[derive(Debug, Clone)]
pub struct Prototype {
    pub identifier: String,
    pub args: Vec<(Identifier, TypeIdent)>,
    pub return_type: FlowType,
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
        args: Vec<(Identifier, TypeIdent)>,
        return_type: FlowType,
    ) -> Self {
        Self {
            identifier,
            args,
            return_type,
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

pub fn typecheck_externs(
    context: &mut TypecheckContext,
    ast_module: &AstModule,
    errors: &mut Vec<TypecheckError>,
) {
    macro_rules! unwrap {
        ($value: expr) => {
            match $value {
                Ok(val) => val,
                Err(err) => {
                    errors.push(err);
                    continue;
                }
            }
        };
    }
    for extrn in &ast_module.externs {
        let proto_id = context
            .symbol_table
            .get_symbol_uid(&context.module_id, &extrn.prototype.identifier)
            .unwrap();
        let proto = Rc::new(unwrap!(typecheck_proto(
            context,
            &extrn.prototype,
            &extrn.span
        )));
        context
            .prototypes
            .insert(proto.identifier.to_string(), proto.clone());

        let extrn = unwrap!(typecheck_extern(&context, proto, extrn));
        context
            .symbol_table
            .attach_deep(&proto_id, DeepInfo::Function(extrn.prototype.clone()));
        context.module.externs.push(Rc::new(extrn));
    }
    for extrn in &ast_module.extern_globals {
        let global_id = context
            .symbol_table
            .get_symbol_uid(&context.module_id, &extrn.name)
            .unwrap();
        let extrn = unwrap!(typecheck_extern_global(context, extrn));
        context.module.extern_globals.push(Rc::new(extrn));
    }
}

pub fn typecheck_functions_definitions(
    context: &mut TypecheckContext,
    ast_module: &AstModule,
    errors: &mut Vec<TypecheckError>,
) {
    macro_rules! unwrap {
        ($value: expr) => {
            match $value {
                Ok(val) => val,
                Err(err) => {
                    errors.push(err);
                    continue;
                }
            }
        };
    }

    for func in &ast_module.functions {
        let proto_id = context
            .symbol_table
            .get_symbol_uid(&context.module_id, &func.prototype.identifier)
            .unwrap();
        let proto = Rc::new(unwrap!(typecheck_proto(
            context,
            &func.prototype,
            &func.span
        )));
        context
            .prototypes
            .insert(proto.identifier.to_string(), proto.clone());
        context
            .symbol_table
            .attach_deep(&proto_id, DeepInfo::Function(proto));
    }
}

pub fn typecheck_functions_implementations(
    context: &mut TypecheckContext,
    ast_module: &AstModule,
    errors: &mut Vec<TypecheckError>,
) {
    macro_rules! unwrap {
        ($value: expr) => {
            match $value {
                Ok(val) => val,
                Err(err) => {
                    errors.push(err);
                    continue;
                }
            }
        };
    }

    for func in ast_module.functions.iter() {
        let proto: Rc<Prototype> = context
            .prototypes
            .get(&func.prototype.identifier)
            .unwrap()
            .clone();
        let func = Rc::new(unwrap!(typecheck_func(context, proto, &func)));
        context.module.functions.push(func);
    }
}
