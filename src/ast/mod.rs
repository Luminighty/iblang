use std::process::exit;

mod module;
mod declaration;
mod expr;
mod literal;
mod ast;
mod error;
mod function;
mod statement;
mod binary;
mod unary;
mod precedence;
mod types;

pub type Identifier = String;
pub type ParserResult = Result<AstModule, Vec<error::AstError>>;

use declaration::Declaration;
use error::AstError;

pub use module::AstModule;

pub mod prelude;

use crate::{lexer, utils::FileMeta};


pub fn run(tokens: Vec<lexer::Token>, meta: &FileMeta) -> ParserResult {
    let mut parser = ast::Ast::new(tokens);
    if let Some(file) = &meta.file {
        parser = parser.with_file(file.to_owned());
    }
    let mut module = AstModule::new("main".to_owned());
    let mut errors = Vec::new();

    loop {
        let decl = parser.next();

        match decl {
            Ok(Declaration::None) => break,
            Ok(Declaration::Function(function)) => module.push_function(function),
            Ok(Declaration::Extern(ext)) => module.push_extern(ext),
            Ok(Declaration::Global(global)) => module.push_global(global),
            Err(err) => errors.push(err),
        }
    }
    if errors.len() > 0 {
        Err(errors)
    } else {
        Ok(module)
    }
}


pub fn print_errors(errors: &Vec<AstError>, meta: &FileMeta) {
    let mut errlock = std::io::stderr();
    for error in errors {
        error.write(&mut errlock, meta).expect("Uh oh.");
    }
}


pub fn print_module(module: &AstModule) {
    print!("{}", module);
}


pub fn run_parser(tokens: Vec<lexer::Token>, meta: &FileMeta) -> AstModule {
    match run(tokens, meta) {
        Ok(module) => module,
        Err(errors) => {
            print_errors(&errors, meta);
            exit(1);
        }
    }
}

