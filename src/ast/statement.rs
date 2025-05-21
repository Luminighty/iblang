use crate::utils::Span;

use super::{expr::Expr, Identifier};

pub struct Statement {
    pub span: Span,
    pub kind: StatementKind,
}

pub enum StatementKind {
    VarDeclaration {
        mutable: bool,
        ident: Identifier,
        value: Expr,
    },
    Block(Vec<Statement>),
    Expr(Expr),
    Return {
        value: Option<Expr>,
    },
    If {
        cond: Expr,
        then: Box<Statement>,
        otherwise: Option<Box<Statement>>,
    },
    Loop {
        cond: Option<Expr>,
        body: Box<Statement>,
    },
}


impl Statement {
    pub fn new_return(value: Option<Expr>, span: Span) -> Self {
        Self {
            span,
            kind: StatementKind::Return { value }
        }
    }

    pub fn new_loop(cond: Option<Expr>, body: Box<Statement>, span: Span) -> Self {
        Self {
            span,
            kind: StatementKind::Loop { cond, body }
        }
    }

    pub fn new_if(cond: Expr, then: Box<Statement>, otherwise: Option<Box<Statement>>, span: Span) -> Self {
        Self {
            span,
            kind: StatementKind::If { cond, then, otherwise }
        }
    }

    pub fn expr(expr: Expr) -> Self {
        let span = expr.span.clone();
        Self {
            kind: StatementKind::Expr(expr),
            span
        }
    }

    pub fn block(statements: Vec<Statement>, span: Span) -> Self {
        Self {
            kind: StatementKind::Block(statements),
            span,
        }
    }

    pub fn var_declaration(ident: String, value: Expr, mutable: bool, span: Span) -> Self {
        Self {
            span,
            kind: StatementKind::VarDeclaration { mutable, ident, value }
        }
    }
}

