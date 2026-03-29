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
    pub function_body: Vec<u8>,
    pub allocas: Vec<u8>,
}

impl<W: Write> Qbe<W> {
    pub fn new(out: W) -> Self {
        Self {
            out,
            allocas: Vec::with_capacity(1028),
            function_body: Vec::with_capacity(1028),
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
        writeln!(self.function_body, "{block}")?;
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

    // For manually inserting globals
    pub fn find_or_create_global(&mut self, name: &str) -> Global {
        let uid = self.globals.find_first_or_create(name);
        Global(uid)
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
            // Err(QbeError::ExternNotFirst(uid, name.to_owned()))
            // NOTE: Since we are using symbols for most things, we don't need the QBe part to
            // worry for name clashes
            Ok(Global(uid.into_first()))
        } else {
            Ok(Global(uid))
        }
    }

    pub fn function_end(&mut self) -> QbeResult<()> {
        self.write_all()?;
        writeln!(self.out, "}}")?;
        writeln!(self.out)?;
        self.temps.clear();
        self.blocks.clear();
        Ok(())
    }

    pub fn write_all(&mut self) -> QbeResult<()> {
        self.out.write_all(&self.allocas)?;
        self.out.write_all(&self.function_body)?;
        self.function_body.clear();
        self.allocas.clear();
        Ok(())
    }

    #[inline]
    pub fn instr(&mut self, instr: String) -> QbeResult<()> {
        writeln!(self.function_body, "\t{instr}")?;
        Ok(())
    }

    #[inline]
    pub fn comment(&mut self, instr: &str) -> QbeResult<()> {
        writeln!(self.function_body)?;
        for line in instr.lines() {
            writeln!(self.function_body, "\t# {line}")?;
        }
        Ok(())
    }
}
