use std::collections::HashMap;
use crate::lexer::token::TokenKind;

use super::{binary::BinaryOp, error::AstErrorKind, unary::UnaryOp};


pub type InfixMap = HashMap<TokenKind, InfixPrecedence>;
pub type PrefixMap = HashMap<TokenKind, PrefixPrecedence>;

pub fn prefix(op: TokenKind) -> Option<((), u8, UnaryOp)> {
    match op {
        TokenKind::Minus => Some(((), 5, UnaryOp::NEG)),
        TokenKind::Bang => Some(((), 5, UnaryOp::NOT)),
        _ => None,
    }
}

#[derive(Debug, Clone)]
pub struct PrefixPrecedence {
    pub new_prec: u8,
    pub op: UnaryOp,
    pub suffix: Option<(TokenKind, AstErrorKind)>,
}

#[derive(Debug, Clone)]
pub struct InfixPrecedence {
    pub prec: u8,
    pub new_prec: u8,
    pub op: BinaryOp,
    pub suffix: Option<(TokenKind, AstErrorKind)>,
}

impl PrefixPrecedence {
    pub fn new(new_prec: u8, op: UnaryOp) -> Self {
        Self { new_prec, op, suffix: None }
    }
    pub fn with_suffix(mut self, suffix: TokenKind, error: AstErrorKind) -> Self {
        self.suffix = Some((suffix, error));
        self
    }

    pub fn default() -> HashMap<TokenKind, Self> {
        use UnaryOp::*;
        HashMap::from([
            (TokenKind::Minus, Self::new(5, NEG)),
            (TokenKind::Bang, Self::new(5, NOT)),
            (TokenKind::ParenL, Self::new(100, GROUP).with_suffix(TokenKind::ParenR, AstErrorKind::UnterminatedParen)),
            (TokenKind::Plus, Self::new(5, POS)),
        ])
    }
}


impl InfixPrecedence {
    pub fn new(prec: u8, new_prec: u8, op: BinaryOp) -> Self {
        Self { prec, new_prec, op, suffix: None }
    }
    pub fn with_suffix(mut self, suffix: TokenKind, error: AstErrorKind) -> Self {
        self.suffix = Some((suffix, error));
        self
    }

    pub fn default() -> HashMap<TokenKind, Self> {
        use BinaryOp::*;
        HashMap::from([
            (TokenKind::Plus, Self::new(1, 2, Add)),
            (TokenKind::Minus, Self::new(1, 2, Sub)),
            (TokenKind::Star, Self::new(3, 4, Mul)),
            (TokenKind::Slash, Self::new(3, 4, Div)),
            (TokenKind::BracketL, Self::new(3, 4, Index)
                .with_suffix(
                    TokenKind::BracketR, 
                    AstErrorKind::UnterminatedBracket
                )
            ),
        ])
    }
}

