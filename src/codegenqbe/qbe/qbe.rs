use std::fs::File;
use std::io::Write;

use crate::codegenqbe::qbe::error::QbeUidStoreKind;

use super::{Block, Global, Temp, error::QbeError, qbe_ty::ExtTy, uid::UIdStore};

pub type QbeResult<T> = Result<T, QbeError>;

pub struct Qbe<W: Write> {
    pub out: W,
    pub blocks: UIdStore,
    pub temps: UIdStore,
    pub idents: UIdStore,
    pub globals: UIdStore,
    pub datas: Vec<String>,
}

impl<W: Write> Qbe<W> {
    pub fn new(out: W) -> Self {
        Self {
            out,
            blocks: UIdStore::new(QbeUidStoreKind::Block),
            temps: UIdStore::new(QbeUidStoreKind::Temp),
            idents: UIdStore::new(QbeUidStoreKind::Ident),
            globals: UIdStore::new(QbeUidStoreKind::Global),
            datas: Vec::new(),
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
    pub fn block(&mut self, block: &Block) -> QbeResult<String> {
        let block = self.blocks.get(&block.0)?;
        Ok(format!("@{block}"))
    }

    #[inline]
    pub fn temp(&mut self, temp: &Temp) -> QbeResult<String> {
        let temp = self.temps.get(&temp.0)?;
        Ok(format!("%{temp}"))
    }

    #[inline]
    pub fn global(&mut self, global: &Global) -> QbeResult<String> {
        let global = self.globals.get(&global.0)?;
        Ok(format!("${global}"))
    }

    #[inline]
    pub fn create_global(&mut self, name: &str) -> Global {
        Global(self.globals.create(name))
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
