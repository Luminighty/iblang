use std::collections::HashMap;
use crate::lexer::token::TokenKind;

use super::{binary::BinaryOp, error::AstErrorKind, unary::UnaryOp};


pub type InfixMap = HashMap<TokenKind, InfixPrecedence>;
pub type PrefixMap = HashMap<TokenKind, PrefixPrecedence>;


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

// TODO: Think about a good default precedence for prefix + infix
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
            (TokenKind::Minus, Self::new(50, NEG)),
            (TokenKind::Bang,  Self::new(50, NOT)),
            (TokenKind::Plus,  Self::new(50, POS)),
            (TokenKind::ParenL, Self::new(0, GROUP)
                .with_suffix(TokenKind::ParenR, AstErrorKind::UnterminatedParen)
            ),
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
            (TokenKind::Equal,      Self::new(2, 0, Assign)),
            (TokenKind::EqEq,      Self::new(10, 11, EQ)),
            (TokenKind::BangEqual, Self::new(10, 11, NE)),
            (TokenKind::GT,  Self::new(12, 13, GT)),
            (TokenKind::GE,  Self::new(12, 13, GE)),
            (TokenKind::LT,  Self::new(12, 13, LT)),
            (TokenKind::LE,  Self::new(12, 13, LE)),

            (TokenKind::Plus,  Self::new(20, 21, Add)),
            (TokenKind::Minus, Self::new(20, 21, Sub)),
            (TokenKind::Star,  Self::new(30, 31, Mul)),
            (TokenKind::Slash, Self::new(32, 33, Div)),
            (TokenKind::Percent,  Self::new(34, 35, Rem)), // TODO: Check in other langs
            (TokenKind::BracketL, Self::new(100, 0, Index)
                .with_suffix(
                    TokenKind::BracketR, 
                    AstErrorKind::UnterminatedBracket
                )
            ),
        ])
    }
}

