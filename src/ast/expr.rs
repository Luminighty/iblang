use crate::utils::Span;

use super::{binary::BinaryOp, literal::Literal, unary::UnaryOp, Identifier};

#[derive(Debug)]
pub struct AstExpr {
    pub kind: AstExprKind,
    pub span: Span,
}

#[derive(Debug)]
pub enum AstExprKind {
    Literal(Literal),
    Ident(Identifier),
    Binary {
        op: BinaryOp,
        lhs: Box<AstExpr>,
        rhs: Box<AstExpr>,
    },
    Array {
        values: Vec<AstExpr>,
    },
    Unary {
        op: UnaryOp,
        expr: Box<AstExpr>,
    },
    Call {
        callee: Box<AstExpr>,
        args: Vec<AstExpr>,
    }
}

impl std::fmt::Display for AstExpr {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", self.kind)
    }
}

impl AstExpr {
    pub fn call(callee: AstExpr, args: Vec<AstExpr>, span: Span) -> Self {
        Self {
            kind: AstExprKind::Call { callee: Box::new(callee), args },
            span,
        }
    }
    fn literal(literal: Literal, span: Span) -> Self {
        Self {
            kind: AstExprKind::Literal(literal),
            span,
        }
    }

    pub fn float(int: i64, frac: u64, span: Span) -> Self {
        let digits = frac.to_string().len();
        let frac = frac as f64 / 10f64.powi(digits as i32);
        let f = if int > 0 {
            int as f64 + frac
        } else {
            int as f64 - frac
        };
        AstExpr::literal(Literal::Float(f), span)
    }
    pub fn number(n: i64, span: Span) -> Self {
        AstExpr::literal(Literal::Number(n), span)
    }
    pub fn string(_string: String, _span: Span) -> Self {
        todo!()
    }
    pub fn bool(val: bool, span: Span) -> Self {
        AstExpr::literal(Literal::Bool(val), span)
    }
    pub fn char(c: char, span: Span) -> Self {
        AstExpr::literal(Literal::Char(c), span)
    }

    pub fn ident(ident: Identifier, span: Span) -> Self {
        Self {
            kind: AstExprKind::Ident(ident),
            span,
        }
    }

    pub fn binary(op: BinaryOp, lhs: Box<AstExpr>, rhs: Box<AstExpr>) -> Self {
        let span = lhs.span.to(&rhs.span);
        Self {
            kind: AstExprKind::Binary { op, lhs, rhs },
            span
        }
    }

    pub fn unary(op: UnaryOp, expr: Box<AstExpr>, span: Span) -> Self {
        Self {
            kind: AstExprKind::Unary { op, expr },
            span
        }
    }

    pub fn array(values: Vec<AstExpr>, span: Span) -> Self {
        Self {
            kind: AstExprKind::Array { values },
            span
        }
    }
}

impl std::fmt::Display for AstExprKind {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            AstExprKind::Literal(literal) => write!(f, "{}", literal),
            AstExprKind::Ident(ident) => write!(f, "{}", ident),
            AstExprKind::Binary { op, lhs, rhs } => {
                match op {
                    BinaryOp::Index => write!(f, "{}[{}]", lhs, rhs),
                    _ => write!(f, "({} {} {})", lhs, op, rhs),
                }
            },
            AstExprKind::Unary { op, expr } => {
                match op {
                    UnaryOp::GROUP => write!(f, "({})", expr),
                    _ => write!(f, "({}{})", op, expr),
                }
            },
            AstExprKind::Call { callee, args } => {
                write!(f, "{}(", callee)?;
                for (i, arg) in args.iter().enumerate() {
                    write!(f, "{}", arg)?;
                    if args.len() > i + 1 {
                        write!(f, ", ")?;
                    }
                }
                write!(f, ")")
            },
            AstExprKind::Array { values } => {
                write!(f, "[")?;
                for (i, arg) in values.iter().enumerate() {
                    write!(f, "{}", arg)?;
                    if values.len() > i + 1 {
                        write!(f, ", ")?;
                    }
                }
                write!(f, "]")
            }
        }
    }
}

