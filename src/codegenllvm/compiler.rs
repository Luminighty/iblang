use inkwell::{
    builder::Builder, context::Context, module::Module as InkModule, values::{FunctionValue, PointerValue},
};

use crate::{typecheck::{FlowType, TypeIdent}, utils::Span};

use super::{bindings::VariableBindings, error::{CompilerError, CompilerErrorKind}, CompileResult};


pub struct Compiler<'ctx> {
    pub context: &'ctx Context,
    pub module: InkModule<'ctx>,
    pub builder: Builder<'ctx>,
    pub bindings: VariableBindings<'ctx>,
    pub fn_value_opt: Option<FunctionValue<'ctx>>,
    pub return_type_opt: Option<FlowType>,
}

impl<'ctx> Compiler<'ctx> {
    pub fn new(name: &str, context: &'ctx Context) -> Self {
        let module = context.create_module(name);
        let builder = context.create_builder();
        let bindings = VariableBindings::new();
        Self {
            context,
            module,
            builder,
            bindings,
            fn_value_opt: None,
            return_type_opt: None,
        }
    }

    pub fn fn_value(&self) -> FunctionValue<'ctx> {
        self.fn_value_opt.unwrap()
    }

    pub fn return_type(&self) -> FlowType {
        self.return_type_opt.clone().unwrap()
    }

    #[inline]
    pub fn get_function(&self, name: &str) -> Option<FunctionValue<'ctx>> {
        self.module.get_function(name)
    }


    pub fn error<T>(&self, kind: CompilerErrorKind, span: Span) -> CompileResult<T> {
        Err(CompilerError::new(
            kind,
            span,
        ))
    }

    pub fn create_entry_block_alloca(&self, name: &str, ty: &TypeIdent) -> PointerValue<'ctx> {
        let builder = self.context.create_builder();
        let entry = self.fn_value().get_first_basic_block().unwrap();

        match entry.get_first_instruction() {
            Some(first_instr) => builder.position_before(&first_instr),
            None => builder.position_at_end(entry),
        }
        let ty = Compiler::inkwell_type(self.context, ty);
        self.builder.build_alloca(ty, name).unwrap()
    }
}

#[derive(Debug, Copy, Clone)]
pub struct CContext {
    pub is_const: bool,
}

impl CContext {
    pub fn new() -> Self {
        Self { is_const: false, }
    }

    pub fn mode_const() -> Self {
        Self { is_const: true }
    }
}
