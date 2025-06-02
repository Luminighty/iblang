use std::collections::HashMap;
use crate::{ast::prelude::*, lexer::token::TokenKind};

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
        use UnaryArith::*;
        HashMap::from([
            (TokenKind::Star, Self::new(70, DEREF)),
            (TokenKind::Amp, Self::new(70, REF)),
            (TokenKind::Minus, Self::new(50, NEG.into())),
            (TokenKind::Bang,  Self::new(50, NOT.into())),
            (TokenKind::Plus,  Self::new(50, POS.into())),
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
        use BinaryArith::*;
        use BinaryPred::*;
        use BinaryOp::*;
        HashMap::from([
            (TokenKind::Equal,      Self::new(2, 0, Assign)),
            (TokenKind::EqEq,      Self::new(10, 11, EQ.into())),
            (TokenKind::BangEqual, Self::new(10, 11, NE.into())),
            (TokenKind::GT,  Self::new(12, 13, GT.into())),
            (TokenKind::GE,  Self::new(12, 13, GE.into())),
            (TokenKind::LT,  Self::new(12, 13, LT.into())),
            (TokenKind::LE,  Self::new(12, 13, LE.into())),

            (TokenKind::Plus,  Self::new(20, 21, Add.into())),
            (TokenKind::Minus, Self::new(20, 21, Sub.into())),
            (TokenKind::Star,  Self::new(30, 31, Mul.into())),
            (TokenKind::Slash, Self::new(32, 33, Div.into())),
            (TokenKind::Percent,  Self::new(34, 35, Rem.into())), // TODO: Check in other langs
            (TokenKind::BracketL, Self::new(100, 0, Index)
                .with_suffix(
                    TokenKind::BracketR, 
                    AstErrorKind::UnterminatedBracket
                )
            ),
        ])
    }
}

