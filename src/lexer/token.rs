use crate::utils::Span;

#[derive(Clone, Debug)]
#[allow(dead_code)]
pub struct Token {
    pub token: TokenKind,
    pub span: Span,
}

#[derive(Debug, Clone, PartialEq, Eq, Hash)]
#[allow(dead_code)]
pub enum TokenKind {
    ParenL,
    ParenR,
    BraceL,
    BraceR,
    BracketL,
    BracketR,

    Comma,
    Colon,
    ColonColon,
    Dot,
    DotDotDot,
    SemiColon,

    Minus,
    Plus,
    PlusEq,
    MinusEq,
    SlashEq,
    PercentEq,
    StarEq,
    Percent,
    Slash,
    Star,

    Pipe,
    Amp,
    And,
    Or,
    Equal,
    EqEq,
    Bang,
    BangEqual,

    LT,
    LE,
    GT,
    GE,
    FatArrow,

    Let,
    Const,
    True,
    Null,
    False,
    If,
    Else,
    While,
    Loop,
    For,
    Match,
    Return,
    Break,
    Continue,
    Fn,
    Import,
    Pub,
    Extern,

    SizeOf,

    Number(i64),
    Float(i64, u64),
    Ident(String),
    String(String),
    Char(char),

    Struct,
    Union,
    Enum,
    TypeIdent(TypeIdentToken),
    Void,
    Any,
    As,
    EOF,
}

#[derive(Debug, Clone, PartialEq, Eq, Hash)]
pub enum TypeIdentToken {
    Int,
    String,
    Char,
    Bool,
    Float,
}

impl Token {
    pub fn new(token: TokenKind, start: usize, end: usize) -> Self {
        Self {
            token,
            span: Span::new(start, end),
        }
    }
}

impl PartialEq<TokenKind> for Token {
    fn eq(&self, other: &TokenKind) -> bool {
        &self.token == other
    }
}

impl From<Token> for TokenKind {
    fn from(token: Token) -> Self {
        token.token
    }
}

impl From<&Token> for TokenKind {
    fn from(token: &Token) -> Self {
        token.token.clone()
    }
}

impl std::fmt::Display for Token {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{:?}", self.token)
    }
}
