use std::collections::HashMap;

use inkwell::{
    builder::Builder,
    context::Context,
    module::Module as InkModule,
    types::StructType,
    values::{FunctionValue, PointerValue},
};

use crate::{
    log,
    typecheck::{FlowType, TypeIdent, module::Module},
    utils::Span,
};

use super::{
    CompileResult,
    bindings::VariableBindings,
    error::{CompilerError, CompilerErrorKind},
};

pub struct Compiler<'ctx> {
    pub log_enabled: bool,
    pub context: &'ctx Context,
    pub module: InkModule<'ctx>,
    pub builder: Builder<'ctx>,
    pub bindings: VariableBindings<'ctx>,
    pub fn_value_opt: Option<FunctionValue<'ctx>>,
    pub return_type_opt: Option<FlowType>,
    pub struct_types: HashMap<TypeIdent, StructType<'ctx>>,
}

impl<'ctx> Compiler<'ctx> {
    pub fn new(name: &str, context: &'ctx Context, log_enabled: bool) -> Self {
        let module = context.create_module(name);
        let builder = context.create_builder();
        let bindings = VariableBindings::new();
        Self {
            log_enabled,
            context,
            module,
            builder,
            bindings,
            fn_value_opt: None,
            return_type_opt: None,
            struct_types: HashMap::new(),
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
        Err(CompilerError::new(kind, span))
    }

    pub fn create_entry_block_alloca(
        &self,
        module: &Module,
        name: &str,
        ty: &TypeIdent,
    ) -> (PointerValue<'ctx>, u32) {
        let builder = self.context.create_builder();
        let entry = self.fn_value().get_first_basic_block().unwrap();

        match entry.get_first_instruction() {
            Some(first_instr) => builder.position_before(&first_instr),
            None => builder.position_at_end(entry),
        }
        let (_size, align) = module.type_size_and_align(ty);
        let ty = self.inkwell_type(ty);
        log!(self, "{ty:?} {align}");
        let alloca = self.builder.build_alloca(ty, name).unwrap();
        alloca
            .as_instruction()
            .unwrap()
            .set_alignment(align as u32)
            .expect("Failed to set alignment");
        (alloca, align)
    }
}
