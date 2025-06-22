use std::io::Write;

use super::{
    BaseTy, Block, ExtTy, Global, Qbe, QbeResult, Temp,
    qbe_instr::{ABITy, Value},
};

pub struct FunctionBuilder {
    name: Global,
    args: Vec<(ABITy, Temp)>,
    is_export: bool,
    return_value: Option<ABITy>,
}

impl FunctionBuilder {
    pub fn new(name: Global) -> Self {
        Self {
            name,
            args: Vec::new(),
            is_export: false,
            return_value: None,
        }
    }

    pub fn return_value<T>(&mut self, ret: T)
    where
        T: Into<ABITy>,
    {
        self.return_value = Some(ret.into());
    }

    pub fn arg<T>(&mut self, ty: T, arg: &Temp)
    where
        T: Into<ABITy>,
    {
        self.args.push((ty.into(), arg.clone()));
    }

    pub fn export(&mut self) {
        self.is_export = true;
    }

    pub fn start<W: Write>(self, qbe: &mut Qbe<W>) -> QbeResult<Block> {
        if self.is_export {
            write!(qbe.out, "export ")?;
        }
        write!(qbe.out, "function ")?;
        if let Some(ret) = self.return_value {
            let ret = qbe.abity(ret)?;
            write!(qbe.out, "{ret} ")?;
        }
        let name = qbe.global(&self.name)?;
        write!(qbe.out, "{name}(")?;
        for (ty, name) in self.args {
            let ty = match ty {
                ABITy::BaseTy(base_ty) => format!("{base_ty}"),
                ABITy::SubWTy(sub_wty) => format!("{sub_wty}"),
                ABITy::TyIdent(ty_ident) => qbe.tyident(ty_ident)?,
            };
            let name = qbe.temp(&name)?;
            write!(qbe.out, "{ty} {name}, ")?;
        }
        writeln!(qbe.out, ") {{")?;
        let start = qbe.create_block("start");
        let block = qbe.block(&start)?;
        writeln!(qbe.out, "{block}")?;

        Ok(start)
    }
}

pub struct CallBuilder {
    fn_name: Global,
    args: Vec<(ABITy, Value)>,
    return_value: Option<(ExtTy, Temp)>,
}

impl CallBuilder {
    pub fn new(fn_name: &Global) -> Self {
        Self {
            fn_name: fn_name.clone(),
            args: Vec::new(),
            return_value: None,
        }
    }

    pub fn arg<T: Into<ABITy>, V: Into<Value>>(&mut self, ty: T, arg: V) {
        self.args.push((ty.into(), arg.into()));
    }

    pub fn _build<W: Write>(self, qbe: &mut Qbe<W>) -> QbeResult<()> {
        let func = qbe.global(&self.fn_name)?;
        write!(qbe.out, "call {func}(")?;
        for (arg_ty, arg_val) in self.args {
            let arg_ty = qbe.abity(arg_ty)?;
            let arg_val = qbe.value(arg_val)?;
            write!(qbe.out, "{arg_ty} {arg_val}, ")?;
        }
        writeln!(qbe.out, ")")?;
        Ok(())
    }

    pub fn call_res<T: Into<ABITy>, W: Write>(
        self,
        qbe: &mut Qbe<W>,
        ty: T,
        name: &str,
    ) -> QbeResult<Temp> {
        let ty = ty.into();
        let ty = qbe.abity(ty)?;
        let temp = qbe.create_temp(name);
        let temp_str = qbe.temp(&temp)?;
        write!(qbe.out, "\t{temp_str} ={ty} ")?;
        self._build(qbe)?;
        Ok(temp)
    }

    pub fn call<W: Write>(self, qbe: &mut Qbe<W>) -> QbeResult<()> {
        write!(qbe.out, "\t")?;
        self._build(qbe)
    }
}
