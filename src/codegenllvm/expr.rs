use inkwell::values::BasicMetadataValueEnum;

use crate::ast::{AstExpr, AstExprKind, Identifier, AstModule};
use crate::typecheck::FlowType;
use crate::utils::Span;

use super::bindings::VariableBinding;
use super::error::CompilerErrorKind;
use super::statement::CompiledStatement;
use super::typedvalue::TypedValue;
use super::{compiler::Compiler, CompileResult};

pub enum CompiledExpr<'a> {
    Value(TypedValue<'a>),
    Variable(VariableBinding<'a>),
    Void,
    Never,
}

pub type CompileExprResult<'a> = CompileResult<CompiledExpr<'a>>;

#[allow(unused_variables, dead_code)]
impl<'ctx> Compiler<'ctx> {
    pub fn load_value(&self, expr: CompiledExpr<'ctx>, kind: CompilerErrorKind, span: Span, name: &str) -> CompileResult<TypedValue<'ctx>> {
        match expr {
            CompiledExpr::Value(val) => Ok(val),
            CompiledExpr::Variable(var) => {
                let ty = Compiler::inkwell_type(self.context, &var.typeident);
                let alloca = self.builder.build_load(ty, var.alloca, name).unwrap();
                Ok(TypedValue::new(alloca, var.typeident))
            },
            _ => self.error(kind, span)
        }
    }

    pub fn compile_expr(&mut self, module: &AstModule, expr: &AstExpr, context: CContext) -> CompileExprResult<'ctx> {
        match &expr.kind {
            AstExprKind::Literal(literal) => self.compile_literal(module, &literal),
            AstExprKind::Ident(ident) => self.compile_ident(module, ident, &expr.span),
            AstExprKind::Binary { op, lhs, rhs } => self.compile_binary(module, op, &lhs, &rhs, expr.span),
            AstExprKind::Unary { op, expr } => self.compile_unary(module, op, expr, expr.span),
            AstExprKind::Call { callee, args } => self.compile_call(module, callee, args),
        }
    }

    fn compile_ident(&mut self, module: &AstModule, ident: &Identifier, span: &Span) -> CompileExprResult<'ctx> {
        if let Some(binding) = self.bindings.get(ident) {
            Ok((*binding).into())
        } else {
            self.error(
                CompilerErrorKind::UndeclaredVariable(ident.to_owned()),
                *span
            )
        }
    }

    fn compile_call(&mut self, module: &AstModule, callee: &AstExpr, args: &Vec<AstExpr>) -> CompileExprResult<'ctx> {
        let callee_span = callee.span;
        let ident = self.as_identifier(callee)?;
        let proto = module.get_prototype(&ident);
        let func = self.get_function(&ident);
        let (proto, func) = match (proto, func) {
            (Some(proto), Some(func)) => (proto, func),
            _ => return self.error(CompilerErrorKind::UndefinedFunction(ident.to_owned()), callee_span)
        };
        let mut compiled_args = Vec::with_capacity(args.len());
        let mut compiled_arg_types = Vec::with_capacity(args.len());
        for (i, arg) in args.iter().enumerate() {
            let arg_span = arg.span;
            let compiled_arg = self.compile_expr(module, arg)?;
            let arg_type = &proto.args[i];
            let name = format!("arg_{}_{}", arg_type.0, 1);

            let compiled_arg = self.load_value(compiled_arg, CompilerErrorKind::ValueExpected, arg_span, &name)?;
            let value = self.cast_to_type(compiled_arg, arg_type.1, &name);
            // TODO: Validate type cast
            compiled_args.push(value);
            compiled_arg_types.push(arg_type.1);
        }
        let argsv: Vec<BasicMetadataValueEnum> = compiled_args.iter().by_ref().map(|&val| val.into()).collect();

        let build_result = self.builder
            .build_call(func, argsv.as_slice(), "tmp")
            .unwrap()
            .try_as_basic_value()
            .left();

        match (build_result, proto.return_type) {
            (Some(value), FlowType::Some(ty)) => Ok(TypedValue::new(value, ty).into()),
            (_, FlowType::Never) => Ok(CompiledExpr::Never),
            _ => Ok(CompiledExpr::Void),
        }
    }

    pub fn as_identifier(&mut self, expr: &AstExpr) -> CompileResult<Identifier> {
        match &expr.kind {
            AstExprKind::Ident(ident) => Ok(ident.to_owned()),
            _ => return self.error(CompilerErrorKind::IdentifierExpected, expr.span)
        }
    }
}


impl<'a> Into<CompiledStatement> for CompiledExpr<'a> {
    fn into(self) -> CompiledStatement {
        match self {
            CompiledExpr::Never => CompiledStatement::Never,
            CompiledExpr::Void => CompiledStatement::Some,
            CompiledExpr::Value(_) => CompiledStatement::Some,
            CompiledExpr::Variable(_) => CompiledStatement::Some,
        }
    }
}
