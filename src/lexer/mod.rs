pub mod lexer;
pub mod error;
pub mod token;

pub use token::Token;
pub use error::LexerError;
pub use lexer::Lexer;
use token::TokenKind;

use crate::span::FileMeta;


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
