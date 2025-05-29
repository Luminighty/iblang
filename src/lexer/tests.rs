use super::*;
use super::token::*;

fn create_lexer(content: &str) -> Lexer {
    Lexer::new(String::from(content), None)
}

macro_rules! assert_next {
    ($lexer: expr, $token: expr) => {
        assert_eq!($lexer.next_token().unwrap().token, $token)
    };
}


#[test]
fn test_blocks() {
    let mut lexer = create_lexer("() {} [] , : :: . ;");
    assert_next!(lexer, TokenKind::ParenL);
    assert_next!(lexer, TokenKind::ParenR);
    assert_next!(lexer, TokenKind::BraceL);
    assert_next!(lexer, TokenKind::BraceR);
    assert_next!(lexer, TokenKind::BracketL);
    assert_next!(lexer, TokenKind::BracketR);
    assert_next!(lexer, TokenKind::Comma);
    assert_next!(lexer, TokenKind::Colon);
    assert_next!(lexer, TokenKind::ColonColon);
    assert_next!(lexer, TokenKind::Dot);
    assert_next!(lexer, TokenKind::SemiColon);
    assert_next!(lexer, TokenKind::EOF);
}


#[test]
fn test_operators() {
    let mut lexer = create_lexer("- + % / * | & && || = == ! != < <= > >=");
    assert_next!(lexer, TokenKind::Minus);
    assert_next!(lexer, TokenKind::Plus);
    assert_next!(lexer, TokenKind::Percent);
    assert_next!(lexer, TokenKind::Slash);
    assert_next!(lexer, TokenKind::Star);
    assert_next!(lexer, TokenKind::Pipe);
    assert_next!(lexer, TokenKind::Amp);
    assert_next!(lexer, TokenKind::And);
    assert_next!(lexer, TokenKind::Or);
    assert_next!(lexer, TokenKind::Equal);
    assert_next!(lexer, TokenKind::EqEq);
    assert_next!(lexer, TokenKind::Bang);
    assert_next!(lexer, TokenKind::BangEqual);
    assert_next!(lexer, TokenKind::LT);
    assert_next!(lexer, TokenKind::LE);
    assert_next!(lexer, TokenKind::GT);
    assert_next!(lexer, TokenKind::GE);
    assert_next!(lexer, TokenKind::EOF);
}


#[test]
fn test_keywords() {
    let mut lexer = create_lexer("
        let const true false if else while 
        loop match return break continue fn 
        import extern
    ");
    assert_next!(lexer, TokenKind::Let);
    assert_next!(lexer, TokenKind::Const);
    assert_next!(lexer, TokenKind::True);
    assert_next!(lexer, TokenKind::False);
    assert_next!(lexer, TokenKind::If);
    assert_next!(lexer, TokenKind::Else);
    assert_next!(lexer, TokenKind::While);
    assert_next!(lexer, TokenKind::Loop);
    assert_next!(lexer, TokenKind::Match);
    assert_next!(lexer, TokenKind::Return);
    assert_next!(lexer, TokenKind::Break);
    assert_next!(lexer, TokenKind::Continue);
    assert_next!(lexer, TokenKind::Fn);
    assert_next!(lexer, TokenKind::Import);
    assert_next!(lexer, TokenKind::Extern);
    assert_next!(lexer, TokenKind::EOF);
}


#[test]
fn test_values() {
    let mut lexer = create_lexer("
        123 234.532 foobar \"string\" 'c'
    ");
    assert_next!(lexer, TokenKind::Number(123));
    assert_next!(lexer, TokenKind::Float(234, 532));
    assert_next!(lexer, TokenKind::Ident("foobar".to_string()));
    assert_next!(lexer, TokenKind::String("string".to_string()));
    assert_next!(lexer, TokenKind::Char('c'));
    assert_next!(lexer, TokenKind::EOF);
}


#[test]
fn test_typeident() {
    let mut lexer = create_lexer("
        int str char bool float void struct enum
    ");
    assert_next!(lexer, TokenKind::TypeIdent(TypeIdentToken::Int));
    assert_next!(lexer, TokenKind::TypeIdent(TypeIdentToken::String));
    assert_next!(lexer, TokenKind::TypeIdent(TypeIdentToken::Char));
    assert_next!(lexer, TokenKind::TypeIdent(TypeIdentToken::Bool));
    assert_next!(lexer, TokenKind::TypeIdent(TypeIdentToken::Float));
    assert_next!(lexer, TokenKind::Void);
    assert_next!(lexer, TokenKind::Struct);
    assert_next!(lexer, TokenKind::Enum);
    assert_next!(lexer, TokenKind::EOF);
}


#[test]
fn test_edgecases() {
    let mut lexer = create_lexer("
        bool_foo true_foo false_true bool123 
    ");
    assert_next!(lexer, TokenKind::Ident("bool_foo".to_string()));
    assert_next!(lexer, TokenKind::Ident("true_foo ".to_string()));
    assert_next!(lexer, TokenKind::Ident("false_true ".to_string()));
    assert_next!(lexer, TokenKind::Ident("bool123 ".to_string()));
    assert_next!(lexer, TokenKind::EOF);
}

