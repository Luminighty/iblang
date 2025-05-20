use std::process::exit;

pub mod span;
use span::FileMeta;
pub use span::Span;

mod lexer;
mod ast;

const SOURCE: &'static str = "main.ib";

fn main() {
    let (tokens, meta) = run_lexer();
    for token in &tokens {
        println!("{:?}", token);
    }
    ast::run(tokens);
}


fn run_parser(tokens: Vec<lexer::Token>) {
    match ast::run(tokens) {
        Ok(module) => {
            println!("{}", module);
        },
        Err(errors) => {
            println!("ERROR");
            exit(1);
        }
    }
}


fn run_lexer() -> (Vec<lexer::Token>, FileMeta) {
    let lexer = lexer::from_file(SOURCE).unwrap();
    match lexer::run(lexer) {
        Ok((tokens, meta)) => (tokens, meta),
        Err(errors) => {
            lexer::print_errors(&errors);
            exit(1);
        }
    }
}
