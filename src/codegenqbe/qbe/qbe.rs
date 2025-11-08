use std::io::Write;

use crate::codegenqbe::qbe::error::QbeUidStoreKind;

use super::{Block, Global, Temp, error::QbeError, uid::UIdStore};

pub type QbeResult<T> = Result<T, QbeError>;

pub struct Qbe<W: Write> {
    pub out: W,
    pub blocks: UIdStore,
    pub temps: UIdStore,
    pub idents: UIdStore,
    pub globals: UIdStore,
}

impl<W: Write> Qbe<W> {
    pub fn new(out: W) -> Self {
        Self {
            out,
            blocks: UIdStore::new(QbeUidStoreKind::Block),
            temps: UIdStore::new(QbeUidStoreKind::Temp),
            idents: UIdStore::new(QbeUidStoreKind::Ident),
            globals: UIdStore::new(QbeUidStoreKind::Global),
        }
    }

    #[inline]
    pub fn create_block(&mut self, label: &str) -> Block {
        Block(self.blocks.create(label))
    }

    #[inline]
    pub fn create_temp(&mut self, label: &str) -> Temp {
        Temp(self.temps.create(label))
    }

    #[inline]
    pub fn write_block(&mut self, block: &Block) -> QbeResult<()> {
        let block = self.block(block)?;
        writeln!(self.out, "{block}")?;
        Ok(())
    }

    #[inline]
    pub fn block(&self, block: &Block) -> QbeResult<String> {
        let block = self.blocks.get(&block.0)?;
        Ok(format!("@{block}"))
    }

    #[inline]
    pub fn temp(&self, temp: &Temp) -> QbeResult<String> {
        let temp = self.temps.get(&temp.0)?;
        Ok(format!("%{temp}"))
    }

    #[inline]
    pub fn global(&self, global: &Global) -> QbeResult<String> {
        let global = self.globals.get(&global.0)?;
        Ok(format!("${global}"))
    }

    // #[inline]
    // pub fn write_external_global(&mut self, global: &Global) -> QbeResult<()> {
    //     let global = self.global(global)?;
    //     writeln!(self.out, "globl {global}")?;
    //     Ok(())
    // }

    #[inline]
    pub fn create_global(&mut self, name: &str, is_extern: bool) -> QbeResult<Global> {
        let uid = self.globals.create(name);
        if is_extern && !uid.is_first_name() {
            Err(QbeError::ExternNotFirst(uid, name.to_owned()))
        } else {
            Ok(Global(uid))
        }
    }

    pub fn function_end(&mut self) -> QbeResult<()> {
        writeln!(self.out, "}}")?;
        writeln!(self.out)?;
        self.temps.clear();
        self.blocks.clear();
        Ok(())
    }

    #[inline]
    pub fn instr(&mut self, instr: String) -> QbeResult<()> {
        writeln!(self.out, "\t{instr}")?;
        Ok(())
    }

    #[inline]
    pub fn comment(&mut self, instr: &str) -> QbeResult<()> {
        writeln!(self.out)?;
        for line in instr.lines() {
            writeln!(self.out, "\t# {line}")?;
        }
        Ok(())
    }
}
