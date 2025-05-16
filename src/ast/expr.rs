use crate::Span;

use super::{binary::BinaryOp, literal::Literal, unary::UnaryOp, Identifier};

pub enum Expr {
    Literal { 
        value: Literal,
        span: Span,
    },
    Ident {
        name: Identifier,
        span: Span,
    },
    Binary {
        op: BinaryOp,
        lhs: Box<Expr>,
        rhs: Box<Expr>,
        span: Span,
    },
    Unary {
        op: UnaryOp,
        expr: Box<Expr>,
        span: Span,
    },
    Call {
        ident: Box<Expr>,
        args: Vec<Expr>,
        span: Span,
    }
}

