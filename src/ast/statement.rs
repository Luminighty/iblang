use crate::utils::Span;

use super::{Identifier, expr::AstExpr, types::AstTypeIdent};

#[derive(Debug)]
pub struct AstStatement {
    pub span: Span,
    pub kind: AstStatementKind,
}

#[derive(Debug)]
pub enum AstStatementKind {
    VarDeclaration {
        mutable: bool,
        ty: Option<AstTypeIdent>,
        ident: Identifier,
        value: AstExpr,
    },
    Block(Vec<AstStatement>),
    Expr(AstExpr),
    Break,
    Continue,
    Return {
        value: Option<AstExpr>,
    },
    If {
        cond: AstExpr,
        then: Box<AstStatement>,
        otherwise: Option<Box<AstStatement>>,
    },
    Loop {
        cond: Option<AstExpr>,
        body: Box<AstStatement>,
    },
    For {
        init: Box<AstStatement>,
        cond: AstExpr,
        acc: AstExpr,
        body: Box<AstStatement>,
    },
}

impl AstStatement {
    pub fn new(kind: AstStatementKind, span: Span) -> Self {
        Self { kind, span }
    }

    pub fn new_for(
        init: Box<AstStatement>,
        cond: AstExpr,
        acc: AstExpr,
        body: Box<AstStatement>,
        span: Span,
    ) -> Self {
        Self {
            span,
            kind: AstStatementKind::For {
                init,
                cond,
                acc,
                body,
            },
        }
    }

    pub fn new_return(value: Option<AstExpr>, span: Span) -> Self {
        Self {
            span,
            kind: AstStatementKind::Return { value },
        }
    }

    pub fn new_loop(cond: Option<AstExpr>, body: Box<AstStatement>, span: Span) -> Self {
        Self {
            span,
            kind: AstStatementKind::Loop { cond, body },
        }
    }

    pub fn new_if(
        cond: AstExpr,
        then: Box<AstStatement>,
        otherwise: Option<Box<AstStatement>>,
        span: Span,
    ) -> Self {
        Self {
            span,
            kind: AstStatementKind::If {
                cond,
                then,
                otherwise,
            },
        }
    }

    pub fn expr(expr: AstExpr) -> Self {
        let span = expr.span.clone();
        Self {
            kind: AstStatementKind::Expr(expr),
            span,
        }
    }

    pub fn block(statements: Vec<AstStatement>, span: Span) -> Self {
        Self {
            kind: AstStatementKind::Block(statements),
            span,
        }
    }

    pub fn var_declaration(
        ident: String,
        value: AstExpr,
        mutable: bool,
        ty: Option<AstTypeIdent>,
        span: Span,
    ) -> Self {
        Self {
            span,
            kind: AstStatementKind::VarDeclaration {
                mutable,
                ident,
                value,
                ty,
            },
        }
    }
}

impl std::fmt::Display for AstStatement {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let depth = f.width().unwrap_or(0);
        write!(f, "{:width$}", "", width = depth)?;
        match &self.kind {
            AstStatementKind::VarDeclaration {
                mutable,
                ident,
                value,
                ty,
            } => {
                write!(f, "{} {}", if *mutable { "let" } else { "const" }, ident,)?;
                if let Some(ty) = ty {
                    write!(f, ": {}", ty)?;
                }
                write!(f, " = {};", value)
            }
            AstStatementKind::Block(block) => {
                writeln!(f, "{{")?;
                for s in block {
                    writeln!(f, "{:width$}{s}", "", width = depth + 2)?;
                }
                writeln!(f, "{:width$}}}", "", width = depth)
            }
            AstStatementKind::Expr(expr) => write!(f, "{};", expr),
            AstStatementKind::Return { value } => {
                write!(f, "return")?;
                if let Some(value) = value {
                    write!(f, " {}", value)?;
                }
                write!(f, ";")
            }
            AstStatementKind::If {
                cond,
                then,
                otherwise,
            } => {
                if let Some(otherwise) = otherwise {
                    write!(f, "if {} {} else {}", cond, then, otherwise)
                } else {
                    write!(f, "if {} {}", cond, then)
                }
            }
            AstStatementKind::Loop { cond, body } => {
                if let Some(cond) = cond {
                    write!(f, "while {} ", cond)?;
                } else {
                    write!(f, "loop ")?;
                }
                write!(f, "{}", body)
            }
            AstStatementKind::Break => write!(f, "break"),
            AstStatementKind::Continue => write!(f, "continue"),
            AstStatementKind::For {
                init,
                cond,
                acc,
                body,
            } => write!(f, "for {init}; {cond}; {acc} {body}"),
        }
    }
}
