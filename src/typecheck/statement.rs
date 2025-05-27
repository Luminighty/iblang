use crate::{ast::{AstModule, AstStatement, AstStatementKind, Identifier}, utils::Span};

use super::{expr::Expr, TypeIdent, TypeResult};

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
        ty: TypeIdent,
        value: Expr,
    },
    Block(Vec<Statement>),
    Expr(Expr),
    Return { value: Option<Expr> },
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

pub fn typecheck_statement(module: &AstModule, statement: AstStatement) -> TypeResult<Statement> {
    match statement.kind {
        AstStatementKind::VarDeclaration { mutable, ty, ident, value } => todo!(),
        AstStatementKind::Block(_) => todo!(),
        AstStatementKind::Expr(ast_expr) => todo!(),
        AstStatementKind::Return { value } => todo!(),
        AstStatementKind::If { cond, then, otherwise } => todo!(),
        AstStatementKind::Loop { cond, body } => todo!(),
    }
}
