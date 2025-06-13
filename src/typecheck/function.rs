use std::collections::VecDeque;

use crate::{
    ast::prelude::*,
    typecheck::declaration::{typecheck_extern, typecheck_func, typecheck_proto},
    utils::Span,
};

use super::{
    checker::TypecheckContext,
    error::TypecheckError,
    statement::Statement,
    typeident::{FlowType, TypeIdent},
};

#[derive(Debug, Clone)]
pub struct Prototype {
    pub identifier: String,
    pub args: Vec<(Identifier, TypeIdent)>,
    pub return_type: FlowType,
}

#[derive(Debug)]
pub struct Extern {
    pub prototype: Prototype,
    #[allow(dead_code)]
    pub span: Span,
}

#[derive(Debug)]
pub struct Function {
    pub prototype: Prototype,
    pub body: Statement,
    #[allow(dead_code)]
    pub span: Span,
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
    pub fn new(prototype: Prototype, body: Statement, span: Span) -> Self {
        Self {
            prototype,
            body,
            span,
        }
    }
}

impl Extern {
    pub fn new(prototype: Prototype, span: Span) -> Self {
        Self { prototype, span }
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
        let proto = unwrap!(typecheck_proto(&context, &extrn.prototype));
        context
            .prototypes
            .insert(proto.identifier.to_string(), proto.clone());

        let extrn = unwrap!(typecheck_extern(&context, proto, extrn));
        context.module.externs.push(extrn);
    }
}

pub fn typecheck_functions(
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
    let mut prototypes = VecDeque::with_capacity(ast_module.functions.len());
    for func in &ast_module.functions {
        let proto = unwrap!(typecheck_proto(&context, &func.prototype));
        context
            .prototypes
            .insert(proto.identifier.to_string(), proto.clone());
        prototypes.push_back(proto);
    }

    for func in ast_module.functions.iter() {
        let func = unwrap!(typecheck_func(
            context,
            prototypes.pop_front().unwrap(),
            &func
        ));
        context.module.functions.push(func);
    }
}
