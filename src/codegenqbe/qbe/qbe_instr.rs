use super::{
    Block, Global, Temp, TyIdent,
    qbe::{Qbe, QbeResult},
    qbe_ty::{BaseTy, ExtTy, SubWTy},
};
use std::io::Write;

pub enum Value {
    Imm(i64),
    ImmF(f64),
    Temp(Temp),
}

pub enum ABITy {
    BaseTy(BaseTy),
    SubWTy(SubWTy),
    TyIdent(TyIdent),
}

impl<W: Write> Qbe<W> {
    pub fn value<T>(&mut self, val: T) -> QbeResult<String>
    where
        T: Into<Value>,
    {
        match val.into() {
            Value::Imm(val) => Ok(format!("{val}")),
            Value::ImmF(val) => Ok(format!("{val}")),
            Value::Temp(temp) => self.temp(&temp),
        }
    }
    pub fn abity<T>(&mut self, ty: T) -> QbeResult<String>
    where
        T: Into<ABITy>,
    {
        match ty.into() {
            ABITy::BaseTy(ty) => Ok(format!("{ty}")),
            ABITy::SubWTy(ty) => Ok(format!("{ty}")),
            ABITy::TyIdent(ident) => self.tyident(ident),
        }
    }

    pub fn binary<Lhs, Rhs>(
        &mut self,
        res_ty: BaseTy,
        op: &str,
        lhs: Lhs,
        rhs: Rhs,
        name: &str,
    ) -> QbeResult<Temp>
    where
        Lhs: Into<Value>,
        Rhs: Into<Value>,
    {
        let name = self.create_temp(name);
        let name_str = self.temp(&name)?;

        let lhs = self.value(lhs)?;
        let rhs = self.value(rhs)?;
        self.instr(format!("{name_str} ={res_ty} {op} {lhs}, {rhs}"))?;
        Ok(name)
    }

    pub fn unary<T>(&mut self, res_ty: BaseTy, op: &str, value: T, name: &str) -> QbeResult<Temp>
    where
        T: Into<Value>,
    {
        let name = self.create_temp(name);
        let name_str = self.temp(&name)?;

        let value = self.value(value)?;
        self.instr(format!("{name_str} ={res_ty} {op} {value}"))?;
        Ok(name)
    }

    pub fn store<T: Into<ExtTy>, V: Into<Value>, M: Into<Value>>(
        &mut self,
        ty: T,
        value: V,
        memory: M,
    ) -> QbeResult<()> {
        let val = self.value(value.into())?;
        let target = self.value(memory.into())?;
        let ty = ty.into();
        self.instr(format!("store{ty} {val}, {target}"))
    }

    pub fn load<M: Into<Value>>(&mut self, ty: BaseTy, mem: M, name: &str) -> QbeResult<Temp> {
        let name = self.create_temp(name);
        let name_str = self.temp(&name)?;
        let mem = self.value(mem.into())?;
        self.instr(format!("{name_str} ={ty} load{ty} {mem}"))?;
        Ok(name)
    }

    fn _load_ext<M: Into<Value>>(
        &mut self,
        signed: bool,
        ty: char,
        mem: M,
        name: &str,
    ) -> QbeResult<Temp> {
        let name = self.create_temp(name);
        let name_str = self.temp(&name)?;
        let mem = self.value(mem.into())?;
        let s = if signed { 's' } else { 'u' };
        self.instr(format!("{name_str} ={ty} load{s}{ty} {mem}"))?;
        Ok(name)
    }

    pub fn loadb<M: Into<Value>>(&mut self, signed: bool, mem: M, name: &str) -> QbeResult<Temp> {
        self._load_ext(signed, 'b', mem, name)
    }

    pub fn loadh<M: Into<Value>>(&mut self, signed: bool, mem: M, name: &str) -> QbeResult<Temp> {
        self._load_ext(signed, 'h', mem, name)
    }

    pub fn loadw<M: Into<Value>>(&mut self, signed: bool, mem: M, name: &str) -> QbeResult<Temp> {
        self._load_ext(signed, 'w', mem, name)
    }

    fn alloc_n(&mut self, n: u8, bytes: usize, name: &str) -> QbeResult<Temp> {
        let temp = self.create_temp(name);
        let name = self.temp(&temp)?;
        self.instr(format!("{name} =l alloc{n} {bytes}"));
        Ok(temp)
    }

    pub fn alloc4(&mut self, bytes: usize, name: &str) -> QbeResult<Temp> {
        self.alloc_n(4, bytes, name)
    }
    pub fn alloc8(&mut self, bytes: usize, name: &str) -> QbeResult<Temp> {
        self.alloc_n(8, bytes, name)
    }
    pub fn alloc16(&mut self, bytes: usize, name: &str) -> QbeResult<Temp> {
        self.alloc_n(16, bytes, name)
    }

    pub fn blit<MFrom, MInto, MBytes>(
        &mut self,
        from: MFrom,
        into: MInto,
        bytes: MBytes,
    ) -> QbeResult<()>
    where
        MFrom: Into<Value>,
        MInto: Into<Value>,
        MBytes: Into<Value>,
    {
        let from = self.value(from)?;
        let into = self.value(into)?;
        let bytes = self.value(bytes)?;
        self.instr(format!("blit {from}, {into}, {bytes}"))
    }

    pub fn ret(&mut self) -> QbeResult<()> {
        self.instr(format!("ret"))
    }

    pub fn retv<V: Into<Value>>(&mut self, value: V) -> QbeResult<()> {
        let value = self.value(value)?;
        self.instr(format!("ret {value}"))
    }

    pub fn jmp(&mut self, block: &Block) -> QbeResult<()> {
        let block = self.block(block)?;
        self.instr(format!("jmp {block}"))
    }

    pub fn jnz<V: Into<Value>>(
        &mut self,
        value: V,
        if_non_zero: &Block,
        if_zero: &Block,
    ) -> QbeResult<()> {
        let value = self.value(value.into())?;
        let if_non_zero = self.block(if_non_zero)?;
        let if_zero = self.block(if_zero)?;
        self.instr(format!("jnz {value}, {if_non_zero}, {if_zero}"))
    }

    pub fn hlt(&mut self) -> QbeResult<()> {
        self.instr(format!("hlt"))
    }
}

impl Into<ABITy> for BaseTy {
    fn into(self) -> ABITy {
        ABITy::BaseTy(self)
    }
}

impl Into<ABITy> for SubWTy {
    fn into(self) -> ABITy {
        ABITy::SubWTy(self)
    }
}

impl Into<ABITy> for TyIdent {
    fn into(self) -> ABITy {
        ABITy::TyIdent(self)
    }
}
impl Into<Value> for f64 {
    fn into(self) -> Value {
        Value::ImmF(self)
    }
}

impl Into<Value> for i64 {
    fn into(self) -> Value {
        Value::Imm(self)
    }
}

impl Into<Value> for i32 {
    fn into(self) -> Value {
        Value::Imm(self as i64)
    }
}

impl Into<Value> for usize {
    fn into(self) -> Value {
        Value::Imm(self as i64)
    }
}

impl Into<Value> for &Temp {
    fn into(self) -> Value {
        Value::Temp(self.clone())
    }
}
