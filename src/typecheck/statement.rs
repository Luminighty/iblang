use crate::{ast::prelude::*, utils::Span};

use super::{
    FlowType, TypeIdent, TypeResult,
    atomic::Atomic,
    checker::{TypecheckContext, TypecheckMode},
    const_eval::const_eval_expr,
    error::*,
    expr::*,
};

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

pub fn typecheck_statement(
    context: &mut TypecheckContext,
    statement: &AstStatement,
) -> TypeResult<Statement> {
    match &statement.kind {
        AstStatementKind::VarDeclaration {
            mutable,
            ty,
            ident,
            value,
        } => var_declaration(context, value, ident, ty, *mutable, statement.span),
        AstStatementKind::Block(b) => block(context, b, statement.span),
        AstStatementKind::Expr(expr) => {
            let expr = typecheck_expr(context, &expr, &TypecheckMode::rvalue())?;
            let flow = expr_type(&expr).into();
            Ok(Statement {
                span: statement.span,
                flow,
                kind: StatementKind::Expr(expr),
            })
        }
        AstStatementKind::Return { value } => ret(context, value, statement.span),
        AstStatementKind::If {
            cond,
            then,
            otherwise,
        } => typecheck_if(context, cond, then, otherwise, statement.span),
        AstStatementKind::Loop { cond, body } => {
            typecheck_loop(context, cond, body, statement.span)
        }
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
    context.target_type = match ty {
        Some(ty) => Some(typecheck_typeident(context, ty, span)?),
        _ => None,
    };
    let mut value = typecheck_expr(context, value, &TypecheckMode::rvalue())?;
    let mut value_type = unwrap_typeident(expr_type(&value), value.span)?;
    match context.target_type.take() {
        Some(ty) => {
            value = try_cast(value, value_type, ty.clone())?;
            value_type = ty;
        }
        _ => {}
    }
    context
        .bindings
        .insert(ident.to_string(), value_type.clone());
    Ok(Statement {
        span,
        flow: StatementFlow::Some,
        kind: StatementKind::VarDeclaration {
            mutable,
            ident: ident.to_string(),
            ty: value_type,
            value,
        },
    })
}

// TODO: span is always passed wrongly to this function. Need to store it within AstTypeIdent!
pub fn typecheck_typeident(
    context: &TypecheckContext,
    ty: &AstTypeIdent,
    span: Span,
) -> TypeResult<TypeIdent> {
    match ty {
        AstTypeIdent::Atomic(atomic) => Ok((*atomic).into()),
        AstTypeIdent::Array(ty, ast_expr) => {
            let ty = typecheck_typeident(context, ty, span)?;
            let len = match const_eval_expr(&ast_expr) {
                Ok(l) => l.as_i64(),
                _ => {
                    return Err(TypecheckError::new(
                        TypecheckErrorKind::InvalidConst,
                        ast_expr.span,
                    ));
                }
            };
            if len < 0 {
                Err(TypecheckError::new(
                    TypecheckErrorKind::InvalidArrayLength(len),
                    ast_expr.span,
                ))
            } else {
                Ok(TypeIdent::Array(Box::new(ty), len as usize))
            }
        }
        AstTypeIdent::Ref(ty) => {
            let ty = typecheck_typeident(context, ty, span)?;
            Ok(TypeIdent::Ref(Box::new(ty)))
        }
        AstTypeIdent::Compound(ident) => {
            if context.ast_module.get_struct(ident).is_some() {
                return Ok(TypeIdent::Struct(ident.to_string()));
            }
            Err(TypecheckError::new(
                TypecheckErrorKind::UndefinedTypeIdent,
                span,
            ))
        }
    }
}

fn block(
    context: &mut TypecheckContext,
    block: &Vec<AstStatement>,
    span: Span,
) -> TypeResult<Statement> {
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
                    StatementFlow::Some => {}
                }
                stmnts.push(stmnt);
            }
            Err(err) => errors.push(err),
        }
    }
    context.bindings.end_block();

    if errors.len() > 0 {
        return Err(TypecheckError::new(
            TypecheckErrorKind::BlockErrors(errors),
            span,
        ));
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
        kind: StatementKind::Block(stmnts),
    })
}

fn ret(
    context: &mut TypecheckContext,
    value: &Option<AstExpr>,
    span: Span,
) -> TypeResult<Statement> {
    let expected = match context.return_type() {
        Ok(ret) => ret,
        _ => {
            return Err(TypecheckError::new(
                TypecheckErrorKind::ReturnInGlobalContext,
                span,
            ));
        }
    };
    let value = if let Some(value) = value {
        let span = value.span;
        let value = typecheck_expr(context, value, &TypecheckMode::rvalue())?;
        let value_type = unwrap_typeident(expr_type(&value), span)?;

        match expected {
            FlowType::Some(expected) => {
                let value = try_cast(value, value_type, expected)?;
                Some(value)
            }
            _ => {
                return Err(TypecheckError::new(
                    TypecheckErrorKind::InvalidReturnStatement {
                        expected,
                        got: FlowType::Some(value_type),
                    },
                    span,
                ));
            }
        }
    } else {
        match expected {
            FlowType::Void => None,
            got => {
                return Err(TypecheckError::new(
                    TypecheckErrorKind::InvalidReturnStatement {
                        expected: FlowType::Void,
                        got,
                    },
                    span,
                ));
            }
        }
    };
    Ok(Statement {
        span,
        flow: StatementFlow::Return,
        kind: StatementKind::Return { value },
    })
}

fn typecheck_if(
    context: &mut TypecheckContext,
    cond: &AstExpr,
    then: &AstStatement,
    otherwise: &Option<Box<AstStatement>>,
    span: Span,
) -> TypeResult<Statement> {
    let cond = typecheck_expr(context, cond, &TypecheckMode::rvalue())?;
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
        kind: StatementKind::If {
            cond,
            then,
            otherwise,
        },
    })
}

fn typecheck_loop(
    context: &mut TypecheckContext,
    cond: &Option<AstExpr>,
    body: &AstStatement,
    span: Span,
) -> TypeResult<Statement> {
    let cond = if let Some(cond) = cond {
        let cond = typecheck_expr(context, cond, &TypecheckMode::rvalue())?;
        let cond_type = unwrap_typeident(expr_type(&cond), cond.span)?;
        Some(try_cast(
            cond,
            cond_type,
            TypeIdent::Atomic(Atomic::bool()),
        )?)
    } else {
        None
    };
    let body = typecheck_statement(context, body)?;
    let body = Box::new(body);

    Ok(Statement {
        span,
        flow: StatementFlow::Some,
        kind: StatementKind::Loop { cond, body },
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

impl Statement {
    pub fn write(&self, f: &mut dyn std::io::Write, depth: usize) -> std::io::Result<()> {
        self.kind.write(f, depth)
    }
}

impl StatementKind {
    pub fn write(&self, f: &mut dyn std::io::Write, depth: usize) -> std::io::Result<()> {
        let pad = " ".repeat(depth);
        match self {
            #[allow(unused)]
            StatementKind::VarDeclaration {
                mutable,
                ident,
                ty,
                value,
            } => {
                writeln!(f, "{pad}{}", ident)?;
                value.write(f, depth + 1)
            }
            StatementKind::Block(b) => {
                for arg in b.iter() {
                    arg.write(f, depth + 1)?;
                }
                Ok(())
            }
            StatementKind::Expr(expr) => expr.write(f, depth),
            StatementKind::Return { value } => {
                writeln!(f, "{pad}return")?;
                if let Some(value) = value {
                    value.write(f, depth)
                } else {
                    Ok(())
                }
            }
            StatementKind::If {
                cond,
                then,
                otherwise,
            } => {
                writeln!(f, "{pad}if")?;
                cond.write(f, depth)?;
                writeln!(f, "{pad}then")?;
                then.write(f, depth)?;
                if let Some(value) = otherwise {
                    value.write(f, depth)
                } else {
                    Ok(())
                }
            }
            StatementKind::Loop { cond, body } => {
                writeln!(f, "{pad}loop")?;
                if let Some(value) = cond {
                    value.write(f, depth)?;
                }
                body.write(f, depth)
            }
        }
    }
}

impl std::fmt::Debug for Statement {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match &self.kind {
            StatementKind::Block(b) => {
                writeln!(f, "{{")?;
                for s in b {
                    writeln!(f, "{s:#?}")?;
                }
                writeln!(f, "}}")
            }
            _ => write!(f, "{:#?}", self.kind),
        }
    }
}

impl std::fmt::Display for Statement {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let depth = f.width().unwrap_or(0);
        write!(f, "{:width$}", "", width = depth)?;
        match &self.kind {
            StatementKind::VarDeclaration {
                mutable,
                ident,
                value,
                ty,
            } => {
                write!(f, "{} {}", if *mutable { "let" } else { "const" }, ident,)?;
                write!(f, ": {}", ty)?;
                write!(f, " = {};", value)
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
            StatementKind::If {
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
