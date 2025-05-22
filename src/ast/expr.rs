use crate::utils::Span;

use super::{binary::BinaryOp, literal::Literal, unary::UnaryOp, Identifier};

#[derive(Debug)]
pub struct Expr {
    pub kind: ExprKind,
    pub span: Span,
}

#[derive(Debug)]
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

impl std::fmt::Display for Expr {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", self.kind)
    }
}

impl Expr {
    pub fn call(callee: Expr, args: Vec<Expr>, span: Span) -> Self {
        Self {
            kind: ExprKind::Call { callee: Box::new(callee), args },
            span,
        }
    }
    fn literal(literal: Literal, span_start: usize) -> Self {
        Self {
            kind: ExprKind::Literal(literal),
            span: Span::new(span_start, span_start + 1) 
        }
    }

    pub fn number(n: i64, span_start: usize) -> Self {
        Expr::literal(Literal::Number(n), span_start)
    }
    pub fn string(string: String, span_start: usize) -> Self {
        Expr::literal(Literal::String(string), span_start)
    }
    pub fn bool(val: bool, span_start: usize) -> Self {
        Expr::literal(Literal::Bool(val), span_start)
    }
    pub fn char(c: char, span_start: usize) -> Self {
        Expr::literal(Literal::Char(c), span_start)
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

impl std::fmt::Display for ExprKind {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            ExprKind::Literal(literal) => write!(f, "{}", literal),
            ExprKind::Ident(ident) => write!(f, "{}", ident),
            ExprKind::Binary { op, lhs, rhs } => {
                match op {
                    BinaryOp::Index => write!(f, "{}[{}]", lhs, rhs),
                    _ => write!(f, "({} {} {})", lhs, op, rhs),
                }
            }
            ExprKind::Unary { op, expr } => {
                match op {
                    UnaryOp::GROUP => write!(f, "({})", expr),
                    _ => write!(f, "({}{})", op, expr),
                }
            }
            ExprKind::Call { callee, args } => {
                write!(f, "{}(", callee)?;
                for arg in args {
                    write!(f, "{}, ", arg)?;
                }
                write!(f, ")")
            }
        }
    }
}
