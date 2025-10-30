use std::process::exit;

pub mod error;
pub mod lexer;
pub mod token;

pub use error::LexerError;
pub use lexer::Lexer;
pub use token::Token;
use token::TokenKind;

use crate::utils::{self, FileMeta};

#[cfg(test)]
mod tests;

pub fn from_file(file: &str) -> Option<Lexer> {
    let content = std::fs::read_to_string(file).ok()?;
    Some(Lexer::new(content, Some(file.to_owned())))
}

pub fn run(mut lexer: Lexer) -> Result<(Vec<Token>, FileMeta), Vec<LexerError>> {
    let mut errors = vec![];
    let mut tokens = vec![];

    loop {
        match lexer.next_token() {
            Ok(token) if token == TokenKind::EOF => break,
            Ok(token) => tokens.push(token),
            Err(err) => errors.push(err),
        }
    }
    if errors.len() > 0 {
        return Err(errors);
    }
    let meta = FileMeta::new(lexer.file, lexer.line_starts.clone());
    Ok((tokens, meta))
}

pub fn print_errors(errors: &Vec<LexerError>) {
    for error in errors {
        eprintln!("{}", error)
    }
}

pub fn print_tokens(tokens: &Vec<Token>) {
    println!("Tokens:");
    for token in tokens {
        println!("  {}", token);
    }
    println!();
}

pub fn run_lexer(file: &str) -> (Vec<Token>, utils::FileMeta) {
    let lexer = from_file(file).expect(&format!("File {file} not found."));
    match run(lexer) {
        Ok((tokens, meta)) => (tokens, meta),
        Err(errors) => {
            print_errors(&errors);
            exit(1);
        }
    }
}
