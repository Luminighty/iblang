use super::{declaration::Global, function::{Extern, Function}, Prototype};


#[allow(dead_code)]
pub struct Module {
    pub name: String,
    pub externs: Vec<Extern>,
    pub functions: Vec<Function>,
    pub globals: Vec<Global>,
}


impl Module {
    pub fn new(name: String) -> Self {
        Self { 
            name, 
            functions: Vec::new(),
            externs: Vec::new(),
            globals: Vec::new()
        }
    }

    pub fn push_function(&mut self, function: Function) {
        self.functions.push(function);
    }

    pub fn push_extern(&mut self, extrn: Extern) {
        self.externs.push(extrn);
    }

    pub fn push_global(&mut self, global: Global) {
        self.globals.push(global);
    }

    pub fn get_prototype(&self, ident: &str) -> Option<&Prototype> {
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
}


impl std::fmt::Display for Module {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        writeln!(f, "Module {}: ", self.name)?;
        if self.externs.len() > 0 {
            for e in &self.externs { writeln!(f, "{:width$}{}", "", e, width=0)?; }
            writeln!(f)?;
        }
        if self.globals.len() > 0 {
            for g in &self.globals { writeln!(f, "{:width$}{}", "", g, width=0)?; }
            writeln!(f)?;
        }
        if self.functions.len() > 0 {
            for func in &self.functions { writeln!(f, "{:width$}{}", "", func, width=0)?; }
            writeln!(f)?;
        }
        Ok(())
    }
}

