use crate::utils::Span;

#[derive(Clone)]
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
    SemiColon,

    Minus,
    Plus,
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

    Let, Const,
    True, False,
    If, Else,
    While, Loop,
    Match,
    Return, Break, Continue,
    Fn, Import, Extern,

    Number(i64),
    Float(i64, i64),
    Ident(String),
    String(String),
    Char(char),

    Struct, Enum,

    EOF,
}

impl Token {
    pub fn new(token: TokenKind, start: usize, end: usize) -> Self {
        Self { token, span: Span::new(start, end) }
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

impl std::fmt::Debug for Token {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{:?}", self.token)
    }
}
