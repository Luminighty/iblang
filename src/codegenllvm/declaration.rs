use inkwell::{types::BasicType, values::FunctionValue};

use crate::{ast::{Extern, Function, Global, Module, Prototype}, types::ExprTypeIdent};

use super::{compiler::Compiler, typedvalue::TypedValue, CompileResult};


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

        self.bindings.start_block();
        for (i, arg) in fn_val.get_param_iter().enumerate() {
            let arg_name = proto.args[i].0.as_str();
            let arg_ty = proto.args[i].1;
            let alloca = self.create_entry_block_alloca(arg_name, &arg_ty);

            self.builder.build_store(alloca, arg).unwrap();

            self.bindings.insert(proto.args[i].0.clone(), alloca, arg_ty);
        }
        self.compile_statement(module, &func.body)?;
        self.bindings.end_block();
        Ok(fn_val)
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

