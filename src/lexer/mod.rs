pub mod lexer;
pub mod error;
pub mod token;

pub use token::Token;
pub use error::LexerError;
pub use lexer::Lexer;
use token::TokenKind;

pub fn from_file(file: &str) -> Option<Lexer> {
    let content = std::fs::read_to_string(file).ok()?;
    Some(Lexer::new(content, Some(file.to_owned())))
}


pub fn run(mut lexer: Lexer) -> Result<Vec<Token>, Vec<LexerError>> {
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
        Err(errors)
    } else {
        Ok(tokens)
    }
}


pub fn print_errors(errors: &Vec<LexerError>) {
    for error in errors {
        eprintln!("{}", error)
    }
}
