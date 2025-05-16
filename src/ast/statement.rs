use crate::Span;

use super::{expr::Expr, Identifier};

pub enum Statement {
    VarDeclaration {
        mutable: bool,
        ident: Identifier,
        value: Expr,
        span: Span,
    },
    Block {
        statements: Vec<Statement>,
        span: Span,
    },
    Expr(Expr),
    Return {
        value: Option<Expr>,
        span: Span,
    },
    If {
        cond: Expr,
        then: Box<Statement>,
        otherwise: Box<Statement>,
        span: Span,
    },
    Loop {
        cond: Option<Expr>,
        body: Box<Statement>,
        span: Span,
    },
}
