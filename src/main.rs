use std::process::exit;

use utils::FileMeta;


mod utils;
mod lexer;
mod ast;

const SOURCE: &'static str = "main.ib";

fn main() {
    let (tokens, meta) = run_lexer();
    for token in &tokens {
        println!("{:?}", token);
    }
    run_parser(tokens, &meta);
}


fn run_parser(tokens: Vec<lexer::Token>, meta: &FileMeta) {
    match ast::run(tokens) {
        Ok(module) => {
            println!("{}", module);
        },
        Err(errors) => {
            ast::print_errors(&errors, meta);
            exit(1);
        }
    }
}


fn run_lexer() -> (Vec<lexer::Token>, utils::FileMeta) {
    let lexer = lexer::from_file(SOURCE).unwrap();
    match lexer::run(lexer) {
        Ok((tokens, meta)) => (tokens, meta),
        Err(errors) => {
            lexer::print_errors(&errors);
            exit(1);
        }
    }
}
