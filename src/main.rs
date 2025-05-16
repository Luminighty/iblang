use std::process::exit;

pub mod span;
pub use span::Span;

mod lexer;
mod ast;

const SOURCE: &'static str = "main.ib";

fn main() {
    let tokens = run_lexer();
    for token in &tokens {
        println!("{:?}", token);
    }
}


fn run_lexer() -> Vec<lexer::Token> {
    let lexer = lexer::from_file(SOURCE).unwrap();
    match lexer::run(lexer) {
        Ok(tokens) => tokens,
        Err(errors) => {
            lexer::print_errors(&errors);
            exit(1);
        }
    }
}
