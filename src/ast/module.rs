use super::{declaration::Global, function::{Extern, Function}};


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
}


impl std::fmt::Display for Module {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        writeln!(f, "Module {}: ", self.name)?;
        for e in &self.externs { writeln!(f, "  {}", e)?; }
        for g in &self.globals { writeln!(f, "  {}", g)?; }
        for func in &self.functions { writeln!(f, "  {}", func)?; }
        writeln!(f)
    }
}

