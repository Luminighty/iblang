use crate::lexer::token::TokenKind;

#[derive(Debug, Clone, Copy)]
pub enum UnaryOp {
    GROUP,
    POS,
    NOT,
    NEG,
}

impl UnaryOp {
    pub fn from_token(token: &TokenKind) -> Option<Self> {
        use TokenKind::*;
        match token {
            Bang => Some(UnaryOp::NOT),
            Minus => Some(UnaryOp::NEG),
            _ => None,
        }
    }
}

