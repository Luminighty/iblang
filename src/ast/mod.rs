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

pub type Identifier = String;
pub type ParserResult = Result<Module, Vec<error::AstError>>;

use crate::{lexer, span::FileMeta};

use declaration::Declaration;
pub use module::Module;


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

pub fn print_errors(errors: &Vec<LexerError>, meta: FileMeta) {
    for error in errors {
        eprintln!("{}", error)
    }
}

