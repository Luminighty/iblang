use crate::{ast::prelude::*, utils::Span};

use super::{atomic::Atomic, checker::TypecheckContext, const_eval::const_eval_expr, error::*, expr::*, FlowType, TypeIdent, TypeResult};

#[derive(Debug)]
pub struct Statement {
    pub span: Span,
    pub kind: StatementKind,
    pub flow: StatementFlow,
}


#[derive(Debug)]
pub enum StatementFlow {
    Some,
    Never,
    Return,
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


pub fn typecheck_statement(context: &mut TypecheckContext, statement: &AstStatement) -> TypeResult<Statement> {
    match &statement.kind {
        AstStatementKind::VarDeclaration { mutable, ty, ident, value } => var_declaration(context, value, ident, ty, *mutable, statement.span),
        AstStatementKind::Block(b) => block(context, b, statement.span),
        AstStatementKind::Expr(expr) => {
            let expr = typecheck_expr(context, &expr)?;
            let flow = expr_type(&expr).into();
            Ok(Statement {
                span: statement.span, flow,
                kind: StatementKind::Expr(expr)
            })
        },
        AstStatementKind::Return { value } => ret(context, value, statement.span),
        AstStatementKind::If { cond, then, otherwise } => typecheck_if(context, cond, then, otherwise, statement.span),
        AstStatementKind::Loop { cond, body } => typecheck_loop(context, cond, body, statement.span),
    }
}


fn var_declaration(
    context: &mut TypecheckContext, 
    value: &AstExpr, 
    ident: &Identifier, 
    ty: &Option<AstTypeIdent>, 
    mutable: bool,
    span: Span,
) -> TypeResult<Statement> {
    let mut value = typecheck_expr(context, value)?;
    let mut value_type = unwrap_typeident(expr_type(&value), value.span)?;
    match ty {
        Some(ty) => {
            let ty = typecheck_typeident(context, ty)?;
            value = try_cast(value, value_type, ty.clone())?;
            value_type = ty;
        },
        _ => {},
    }
    context.bindings.insert(ident.to_string(), value_type.clone());
    Ok(Statement {
        span,
        flow: StatementFlow::Some,
        kind: StatementKind::VarDeclaration {
            mutable,
            ident: ident.to_string(),
            ty: value_type,
            value 
        }
    })
}

pub fn typecheck_typeident(context: &TypecheckContext, ty: &AstTypeIdent) -> TypeResult<TypeIdent> {
    match ty {
        AstTypeIdent::Atomic(atomic) => Ok((*atomic).into()),
        AstTypeIdent::Array(ty, ast_expr) => {
            let ty = typecheck_typeident(context, ty)?;
            let len = match const_eval_expr(&ast_expr) {
                Ok(l) => l.as_i64(),
                _ => return Err(TypecheckError::new(
                    TypecheckErrorKind::InvalidConst, ast_expr.span
                ))
            };
            if len < 0 {
                Err(TypecheckError::new(
                    TypecheckErrorKind::InvalidArrayLength(len), ast_expr.span
                ))
            } else {
                Ok(TypeIdent::Array(Box::new(ty), len as usize))
            }
        }
    }
}


fn block(context: &mut TypecheckContext, block: &Vec<AstStatement>, span: Span) -> TypeResult<Statement> {
    let mut errors = Vec::with_capacity(block.len());
    let mut stmnts = Vec::with_capacity(block.len());
    context.bindings.start_block();
    let mut returned = false;
    let mut nevered = false;
    for statement in block {
        match typecheck_statement(context, statement) {
            Ok(stmnt) => {
                match &stmnt.flow {
                    StatementFlow::Never => nevered = true,
                    StatementFlow::Return => returned = true,
                    StatementFlow::Some => {},
                }
                stmnts.push(stmnt);
            },
            Err(err) => errors.push(err)
        }
    }
    context.bindings.end_block();

    if errors.len() > 0 {
        return Err(TypecheckError::new(
            TypecheckErrorKind::BlockErrors(errors),
            span
        ))
    }
    let flow = if nevered { 
        StatementFlow::Never
    } else if returned { 
        StatementFlow::Return
    } else {
        StatementFlow::Some
    };
    Ok(Statement {
        flow,
        span,
        kind: StatementKind::Block(stmnts)
    })
}


fn ret(context: &mut TypecheckContext, value: &Option<AstExpr>, span: Span) -> TypeResult<Statement> {
    let expected = match context.return_type() {
        Ok(ret) => ret,
        _ => return Err(TypecheckError::new(TypecheckErrorKind::ReturnInGlobalContext, span)),
    };
    let value = if let Some(value) = value {
        let span = value.span;
        let value = typecheck_expr(context, value)?;
        let value_type = unwrap_typeident(expr_type(&value), span)?;
        match expected {
            FlowType::Some(expected) => {
                let value = try_cast(value, value_type, expected)?;
                Some(value)
            },
            _ => return Err(TypecheckError::new(TypecheckErrorKind::ReturnInGlobalContext, span)),
        }
    } else {
        match expected {
            FlowType::Void => None,
            got => return Err(TypecheckError::new(TypecheckErrorKind::InvalidReturnStatement { expected: FlowType::Void, got }, span)),
        }
    };
    Ok(Statement {
        span,
        flow: StatementFlow::Return,
        kind: StatementKind::Return { value }
    })
}


fn typecheck_if(context: &mut TypecheckContext, cond: &AstExpr, then: &AstStatement, otherwise: &Option<Box<AstStatement>>, span: Span) -> TypeResult<Statement> {
    let cond = typecheck_expr(context, cond)?;
    let cond_type = unwrap_typeident(expr_type(&cond), cond.span)?;
    let cond = try_cast(cond, cond_type, TypeIdent::Atomic(Atomic::bool()))?;

    let then = typecheck_statement(context, then)?;
    let then = Box::new(then);

    let otherwise = if let Some(otherwise) = otherwise {
        let otherwise = typecheck_statement(context, otherwise)?;
        Some(Box::new(otherwise))
    } else {
        None
    };
    Ok(Statement {
        span,
        flow: StatementFlow::Some,
        kind: StatementKind::If { cond, then, otherwise }
    })
}


fn typecheck_loop(context: &mut TypecheckContext, cond: &Option<AstExpr>, body: &AstStatement, span: Span) -> TypeResult<Statement> {
    let cond = if let Some(cond) = cond {
        let cond = typecheck_expr(context, cond)?;
        let cond_type = unwrap_typeident(expr_type(&cond), cond.span)?;
        Some(try_cast(cond, cond_type, TypeIdent::Atomic(Atomic::bool()))?)
    } else {
        None
    };
    let body = typecheck_statement(context, body)?;
    let body = Box::new(body);

    Ok(Statement {
        span,
        flow: StatementFlow::Some,
        kind: StatementKind::Loop { cond, body }
    })
}


impl From<FlowType> for StatementFlow {
    fn from(flow: FlowType) -> Self {
        match flow {
            FlowType::Some(_) => Self::Some,
            FlowType::Void => Self::Some,
            FlowType::Never => Self::Never,
        }
    }
}

