use crate::lexer::token::TokenKind;

#[derive(Debug, Clone, Copy)]
pub enum BinaryOp {
    Add,
    Sub,
    Mul,
    Div,
    Rem,
    EQ,
    NE,
    GT,
    GE,
    LT,
    LE,
    Index,
}

