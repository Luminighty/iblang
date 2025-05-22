use inkwell::values::BasicMetadataValueEnum;

use crate::ast::{Expr, ExprKind, Identifier, Module};

use super::error::CompilerErrorKind;
use super::typedvalue::TypedValue;
use super::{compiler::Compiler, CompileResult};

pub type CompileExprResult<'a> = CompileResult<TypedValue<'a>>;

#[allow(unused_variables, dead_code)]
impl<'ctx> Compiler<'ctx> {
    pub fn compile_expr(&mut self, module: &Module, expr: &Expr) -> CompileExprResult<'ctx> {
        match &expr.kind {
            ExprKind::Literal(literal) => self.compile_literal(module, &literal),
            ExprKind::Ident(ident) => self.compile_ident(module, ident),
            ExprKind::Binary { op, lhs, rhs } => self.compile_binary(module, op, &lhs, &rhs),
            ExprKind::Unary { op, expr } => self.compile_unary(module, op, expr),
            ExprKind::Call { callee, args } => self.compile_call(module, callee, args),
        }
    }

    fn compile_ident(&mut self, module: &Module, ident: &Identifier) -> CompileExprResult<'ctx> {
        if let Some(binding) = self.bindings.get(ident) {
            Ok(*binding)
        } else {
            self.error(CompilerErrorKind::UndeclaredVariable(ident.to_owned()))
        }
    }

    fn compile_call(&mut self, module: &Module, callee: &Expr, args: &Vec<Expr>) -> CompileExprResult<'ctx> {
        let ident = self.as_identifier(callee)?;
        let proto = module.get_prototype(&ident);
        let func = self.get_function(&ident);
        let (proto, func) = match (proto, func) {
            (Some(proto), Some(func)) => (proto, func),
            _ => return self.error(CompilerErrorKind::UndefinedFunction(ident.to_owned()))
        };
        let mut compiled_args = Vec::with_capacity(args.len());
        for arg in args {
            let compiled_arg = self.compile_expr(module, arg)?;
            // TODO: Validate type
            compiled_args.push(compiled_arg.value);
        }
        let argsv: Vec<BasicMetadataValueEnum> = compiled_args.iter().by_ref().map(|&val| val.into()).collect();

        let build_result = self.builder
            .build_call(func, argsv.as_slice(), "tmp")
            .unwrap()
            .try_as_basic_value()
            .left();

        match build_result {
            Some(value) => Ok(TypedValue::new(value, proto.return_type)),
            None => self.error(CompilerErrorKind::InvalidCall)
        }
    }

    fn as_identifier(&mut self, expr: &Expr) -> CompileResult<Identifier> {
        match &expr.kind {
            ExprKind::Ident(ident) => Ok(ident.to_owned()),
            _ => return self.error(CompilerErrorKind::IdentifierExpected)
        }
    }
}

