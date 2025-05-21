use crate::utils::Span;

use super::{binary::BinaryOp, literal::Literal, unary::UnaryOp, Identifier};

pub struct Expr {
    pub kind: ExprKind,
    pub span: Span,
}

pub enum ExprKind {
    Literal(Literal),
    Ident(Identifier),
    Binary {
        op: BinaryOp,
        lhs: Box<Expr>,
        rhs: Box<Expr>,
    },
    Unary {
        op: UnaryOp,
        expr: Box<Expr>,
    },
    Call {
        callee: Box<Expr>,
        args: Vec<Expr>,
    }
}


impl Expr {
    pub fn call(callee: Expr, args: Vec<Expr>, span: Span) -> Self {
        Self {
            kind: ExprKind::Call { callee: Box::new(callee), args },
            span,
        }
    }

    pub fn number(n: i64, span_start: usize) -> Self {
        Self {
            kind: ExprKind::Literal(Literal::Number(n)),
            span: Span::new(span_start, span_start + 1) 
        }
    }

    pub fn ident(ident: Identifier, span_start: usize) -> Self {
        Self {
            kind: ExprKind::Ident(ident),
            span: Span::new(span_start, span_start + 1),
        }
    }

    pub fn binary(op: BinaryOp, lhs: Box<Expr>, rhs: Box<Expr>) -> Self {
        let span = lhs.span.to(&rhs.span);
        Self {
            kind: ExprKind::Binary { op, lhs, rhs },
            span
        }
    }

    pub fn unary(op: UnaryOp, expr: Box<Expr>, span: Span) -> Self {
        Self {
            kind: ExprKind::Unary { op, expr },
            span
        }
    }
}
