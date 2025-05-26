use inkwell::{types::BasicType, values::FunctionValue};

use crate::{ast::{Extern, Function, Global, Module, Prototype}, types::ExprTypeIdent};
use super::{compiler::Compiler, error::CompilerErrorKind, statement::CompiledStatement, CompileResult};


#[allow(unused_variables, dead_code)]
impl<'ctx> Compiler<'ctx> {

    pub fn compile_proto(&mut self, module: &Module, proto: &Prototype) -> CompileResult<FunctionValue<'ctx>> {
        let mut args_types = Vec::with_capacity(proto.args.len());
        for (_, ty) in &proto.args {
            args_types.push(Compiler::inkwell_type(&self.context, &ty).into());
        }
        let args_types = args_types.as_slice();

        let fn_type = match &proto.return_type {
            ExprTypeIdent::Some(ty) => Compiler::inkwell_type(self.context, ty).fn_type(args_types, false),
            _ => self.context.void_type().fn_type(args_types, false),
        };
        let fn_val = self.module.add_function(proto.identifier.as_str(), fn_type, None);

        for (i, arg) in fn_val.get_param_iter().enumerate() {
            arg.set_name(proto.args[i].0.as_str());
        }
        Ok(fn_val)
    }

    pub fn compile_func(&mut self, module: &Module, func: &Function) -> CompileResult<FunctionValue<'ctx>> {
        let proto = &func.prototype;
        let fn_val = self.get_function(&func.prototype.identifier).unwrap();

        let entry = self.context.append_basic_block(fn_val, "entry");
        self.builder.position_at_end(entry);
        self.fn_value_opt = Some(fn_val);
        self.return_type_opt = Some(proto.return_type);

        self.bindings.start_block();
        for (i, arg) in fn_val.get_param_iter().enumerate() {
            let arg_name = proto.args[i].0.as_str();
            let arg_ty = proto.args[i].1;
            let alloca = self.create_entry_block_alloca(arg_name, &arg_ty);

            self.builder.build_store(alloca, arg).unwrap();

            self.bindings.insert(proto.args[i].0.clone(), alloca, arg_ty);
        }
        let res = self.compile_statement(module, &func.body);
        match res {
            Ok(CompiledStatement::Some) => {
                self.builder.build_return(None).unwrap();
            },
            _ => {},
        }
        self.bindings.end_block();
        self.fn_value_opt = None;
        self.return_type_opt = None;

        match (&res, proto.return_type) {
            (Ok(CompiledStatement::Some), ExprTypeIdent::Void) => {},
            (Ok(CompiledStatement::Return), _) => {},
            (Ok(CompiledStatement::Never), ExprTypeIdent::Never) => {},
            (Ok(got), expected) => {
                return self.error(
                    CompilerErrorKind::InvalidReturnStatement { expected, got: ExprTypeIdent::Void },
                    func.span,
                )
            },
            _ => {},
        }

        match res {
            Ok(_) => Ok(fn_val),
            Err(err) => Err(err),
        }
    }

    pub fn compile_extern(&mut self, module: &Module, func: &Extern) -> CompileResult<FunctionValue<'ctx>> {
        let proto = &func.prototype;
        let fn_val = self.compile_proto(module, proto)?;
        return Ok(fn_val)
    }

    pub fn compile_global(&mut self, module: &Module, func: &Global) -> CompileResult<()> {
        Ok(())
    }
}

