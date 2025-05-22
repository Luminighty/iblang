use crate::utils::Span;

use super::{expr::Expr, Identifier};

#[derive(Debug)]
pub struct Statement {
    pub span: Span,
    pub kind: StatementKind,
}

#[derive(Debug)]
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

impl std::fmt::Display for Statement {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let depth = f.width().unwrap_or(0);
        write!(f, "{:width$}", "", width = depth)?;
        match &self.kind {
            StatementKind::VarDeclaration { mutable, ident, value } => {
                write!(f, 
                    "{} {} = {};",
                    if *mutable { "let" } else { "const" },
                    ident,
                    value
                )
            }
            StatementKind::Block(block) => {
                writeln!(f, "{{")?;
                for s in block {
                    writeln!(f, "{:width$}{s}", "", width = depth + 2)?;
                }
                writeln!(f, "{:width$}}}", "", width = depth)
            }
            StatementKind::Expr(expr) => write!(f, "{};", expr),
            StatementKind::Return { value } => {
                write!(f, "return")?;
                if let Some(value) = value {
                    write!(f, " {}", value)?;
                }
                write!(f, ";")
            }
            StatementKind::If { cond, then, otherwise } => {
                if let Some(otherwise) = otherwise {
                    write!(f, "if {} {} else {}", cond, then, otherwise)
                } else {
                    write!(f, "if {} {}", cond, then)
                }
            }
            StatementKind::Loop { cond, body } => {
                if let Some(cond) = cond {
                    write!(f, "while {} ", cond)?;
                } else {
                    write!(f, "loop ")?;
                }
                write!(f, "{}", body)
            }
        }
    }
}
