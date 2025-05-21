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

pub type Identifier = String;
pub type ParserResult = Result<Module, Vec<error::AstError>>;

use declaration::Declaration;
use error::AstError;
pub use module::Module;

use crate::{lexer, utils::FileMeta};


pub fn run(tokens: Vec<lexer::Token>) -> ParserResult {
    let mut parser = ast::Ast::new(tokens);
    let mut module = Module::new("main".to_owned());
    let mut errors = Vec::new();

    loop {
        match parser.next() {
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

