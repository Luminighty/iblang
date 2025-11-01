use crate::utils::Span;

use super::{Identifier, binary::BinaryOp, literal::Literal, unary::UnaryOp};

#[derive(Debug)]
pub struct AstExpr {
    pub kind: AstExprKind,
    pub span: Span,
}

#[derive(Debug, PartialEq)]
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
    },
    ObjectInit {
        identifier: Identifier,
        fields: Vec<AstObjectInitField>,
    },
}

#[derive(Debug, PartialEq)]
pub enum AstObjectInitField {
    Named(String, Box<AstExpr>),
    Ident(String),
    #[allow(unused)]
    Expr(Box<AstExpr>),
}

impl std::fmt::Display for AstExpr {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", self.kind)
    }
}

impl AstExpr {
    pub fn call(callee: AstExpr, args: Vec<AstExpr>, span: Span) -> Self {
        Self {
            kind: AstExprKind::Call {
                callee: Box::new(callee),
                args,
            },
            span,
        }
    }
    fn literal(literal: Literal, span: Span) -> Self {
        Self {
            kind: AstExprKind::Literal(literal),
            span,
        }
    }

    pub fn object_init(
        identifier: Identifier,
        fields: Vec<AstObjectInitField>,
        span: Span,
    ) -> Self {
        Self {
            kind: AstExprKind::ObjectInit { identifier, fields },
            span,
        }
    }

    pub fn float(int: i64, frac: u64, span: Span) -> Self {
        let digits = frac.to_string().len();
        let frac = frac as f64 / 10f64.powi(digits as i32);
        let f = if int >= 0 {
            int as f64 + frac
        } else {
            int as f64 - frac
        };
        AstExpr::literal(Literal::Float(f), span)
    }

    pub fn number(n: i64, span: Span) -> Self {
        AstExpr::literal(Literal::Number(n), span)
    }

    pub fn null(span: Span) -> Self {
        AstExpr::literal(Literal::Null, span)
    }

    pub fn string(string: String, span: Span) -> Self {
        let mut chars: Vec<AstExpr> = string.chars().map(|c| AstExpr::char(c, span)).collect();
        chars.push(AstExpr::char('\0', span));
        AstExpr::array(chars, span)
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
            span,
        }
    }

    pub fn unary(op: UnaryOp, expr: Box<AstExpr>, span: Span) -> Self {
        Self {
            kind: AstExprKind::Unary { op, expr },
            span,
        }
    }

    pub fn array(values: Vec<AstExpr>, span: Span) -> Self {
        Self {
            kind: AstExprKind::Array { values },
            span,
        }
    }
}

impl std::cmp::PartialEq for AstExpr {
    fn eq(&self, other: &Self) -> bool {
        self.kind == other.kind
    }
}

impl std::fmt::Display for AstExprKind {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            AstExprKind::Literal(literal) => write!(f, "{}", literal),
            AstExprKind::Ident(ident) => write!(f, "{}", ident),
            AstExprKind::Binary { op, lhs, rhs } => match op {
                BinaryOp::Index => write!(f, "{}[{}]", lhs, rhs),
                BinaryOp::FieldLookup => write!(f, "{}.{}", lhs, rhs),
                _ => write!(f, "({} {} {})", lhs, op, rhs),
            },
            AstExprKind::Unary { op, expr } => match op {
                UnaryOp::GROUP => write!(f, "({})", expr),
                UnaryOp::REF => write!(f, "&({expr})"),
                UnaryOp::DEREF => write!(f, "*({expr})"),
                _ => write!(f, "({}{})", op, expr),
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
            }
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
            AstExprKind::ObjectInit { identifier, fields } => {
                writeln!(f, "struct {identifier} {{")?;
                for (i, field) in fields.iter().enumerate() {
                    match field {
                        AstObjectInitField::Named(ident, ast_expr) => {
                            writeln!(f, "{ident}: {ast_expr}")?;
                        }
                        AstObjectInitField::Expr(ast_expr) => {
                            writeln!(f, "{ast_expr}")?;
                        }
                        AstObjectInitField::Ident(ident) => {
                            writeln!(f, "{ident}")?;
                        }
                    }
                    if fields.len() > i + 1 {
                        write!(f, ", ")?;
                    }
                }
                writeln!(f, "}}")
            }
        }
    }
}
