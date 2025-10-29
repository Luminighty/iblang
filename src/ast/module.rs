use crate::ast::declaration::{AstExternGlobal, AstImport};

use super::prelude::*;
use std::rc::Rc;

#[allow(dead_code)]
#[derive(Debug)]
pub struct AstModule {
    pub name: String,
    pub externs: Vec<Rc<AstExternFunction>>,
    pub extern_globals: Vec<Rc<AstExternGlobal>>,
    pub functions: Vec<Rc<AstFunction>>,
    pub globals: Vec<Rc<AstGlobal>>,
    pub structs: Vec<Rc<AstStructDef>>,
    pub imports: Vec<Rc<AstImport>>,
}

impl AstModule {
    pub fn new(name: String) -> Self {
        Self {
            name,
            functions: Vec::new(),
            externs: Vec::new(),
            extern_globals: Vec::new(),
            globals: Vec::new(),
            structs: Vec::new(),
            imports: Vec::new(),
        }
    }

    pub fn push_function(&mut self, function: AstFunction) {
        self.functions.push(Rc::new(function));
    }

    pub fn push_extern(&mut self, extrn: AstExternFunction) {
        self.externs.push(Rc::new(extrn));
    }
    pub fn push_extern_global(&mut self, extrn: AstExternGlobal) {
        self.extern_globals.push(Rc::new(extrn));
    }

    pub fn push_struct(&mut self, strct: AstStructDef) {
        self.structs.push(Rc::new(strct));
    }
    pub fn push_import(&mut self, import: AstImport) {
        self.imports.push(Rc::new(import));
    }

    pub fn push_global(&mut self, global: AstGlobal) {
        self.globals.push(Rc::new(global));
    }

    #[allow(unused)]
    pub fn get_prototype(&self, ident: &str) -> Option<&AstPrototype> {
        for f in &self.functions {
            if f.prototype.identifier == ident {
                return Some(&f.prototype);
            }
        }
        for e in &self.externs {
            if e.prototype.identifier == ident {
                return Some(&e.prototype);
            }
        }
        None
    }

    pub fn get_struct(&self, ident: &str) -> Option<&AstStructDef> {
        for s in &self.structs {
            if s.identifier == ident {
                return Some(&s);
            }
        }
        None
    }
}

impl std::fmt::Display for AstModule {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        writeln!(f, "Module {}: ", self.name)?;
        if self.externs.len() > 0 {
            for e in &self.externs {
                writeln!(f, "{:width$}{}", "", e, width = 0)?;
            }
            writeln!(f)?;
        }
        if self.structs.len() > 0 {
            for s in &self.structs {
                writeln!(f, "{:width$}{}", "", s, width = 0)?;
            }
            writeln!(f)?;
        }
        if self.globals.len() > 0 {
            for g in &self.globals {
                writeln!(f, "{:width$}{}", "", g, width = 0)?;
            }
            writeln!(f)?;
        }
        if self.functions.len() > 0 {
            for func in &self.functions {
                writeln!(f, "{:width$}{}", "", func, width = 0)?;
            }
            writeln!(f)?;
        }
        Ok(())
    }
}
