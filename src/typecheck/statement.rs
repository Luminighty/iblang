use crate::{
    ast::prelude::*,
    symbol_resolver::{ModuleUID, Symbol, SymbolKind, SymbolStage, SymbolUID},
    typecheck::{
        VarBinding,
        checker::{TypecheckContext, resolve_identifier},
        const_eval::ConstExpr,
        type_struct::typecheck_structdef,
        type_union::typecheck_uniondef,
    },
    utils::Span,
};

use super::{
    FlowType, TypeIdent, TypeResult,
    atomic::Atomic,
    checker::{TypecheckFuncContext, TypecheckMode},
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
    Break,
    Continue,
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
    For {
        init: Box<Statement>,
        acc: Expr,
        cond: Expr,
        body: Box<Statement>,
    },
    Continue,
    Break,
}

pub fn typecheck_statement(
    global_context: &mut TypecheckContext,
    context: &mut TypecheckFuncContext,
    statement: &AstStatement,
) -> TypeResult<Statement> {
    match &statement.kind {
        AstStatementKind::VarDeclaration {
            mutable,
            ty,
            ident,
            value,
        } => local_var_declaration(
            global_context,
            context,
            value,
            ident,
            ty,
            *mutable,
            statement.span,
        ),
        AstStatementKind::Block(b) => block(global_context, context, b, statement.span),
        AstStatementKind::Expr(expr) => {
            let expr = typecheck_expr(global_context, context, &expr, &TypecheckMode::rvalue())?;
            let flow = expr_type(&expr).into();
            Ok(Statement {
                span: statement.span,
                flow,
                kind: StatementKind::Expr(expr),
            })
        }
        AstStatementKind::Break => typecheck_break(context, statement.span),
        AstStatementKind::Continue => typecheck_continue(context, statement.span),
        AstStatementKind::Return { value } => ret(global_context, context, value, statement.span),
        AstStatementKind::If {
            cond,
            then,
            otherwise,
        } => typecheck_if(
            global_context,
            context,
            cond,
            then,
            otherwise,
            statement.span,
        ),
        AstStatementKind::Loop { cond, body } => {
            typecheck_loop(global_context, context, cond, body, statement.span)
        }
        AstStatementKind::For {
            init,
            cond,
            acc,
            body,
        } => typecheck_for(
            global_context,
            context,
            init,
            cond,
            acc,
            body,
            statement.span,
        ),
    }
}

fn local_var_declaration(
    global_context: &mut TypecheckContext,
    context: &mut TypecheckFuncContext,
    value: &AstExpr,
    ident: &Identifier,
    ty: &Option<AstTypeIdent>,
    mutable: bool,
    span: Span,
) -> TypeResult<Statement> {
    let (value_type, value) =
        var_declaration(global_context, context, value, ident, ty, mutable, span)?;
    context.bindings.insert(
        ident.to_string(),
        VarBinding::new(value_type.clone(), mutable),
    );
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

pub fn var_declaration(
    global_context: &mut TypecheckContext,
    context: &mut TypecheckFuncContext,
    value: &AstExpr,
    ident: &Identifier,
    ty: &Option<AstTypeIdent>,
    mutable: bool,
    span: Span,
) -> TypeResult<(TypeIdent, Expr)> {
    context.target_type = match ty {
        Some(ty) => Some(typecheck_expr_typeident(global_context, context, ty, span)?),
        _ => None,
    };
    let mut value = typecheck_expr(global_context, context, value, &TypecheckMode::rvalue())?;
    let mut value_type = unwrap_typeident(context.module_id, expr_type(&value), value.span)?;

    let is_array_init = match value.kind {
        ExprKind::Array { .. } => true,
        _ => false,
    };
    let is_array_value_type = match value_type {
        TypeIdent::Array(_, _) => true,
        _ => false,
    };

    match context.target_type.take() {
        Some(ty) => {
            match (ty.clone(), is_array_init) {
                (TypeIdent::Array(_, _), false) => {
                    // NOTE: We are trying to make a new array without an initializer
                    //  That's not very C of you :(
                    //  Later maybe we should allow this though..
                    return Err(TypecheckError::new(
                        TypecheckErrorKind::InvalidArrayInitialization,
                        context.module_id,
                        span,
                    ));
                }
                _ => {}
            }
            value = try_cast(context, value, value_type, ty.clone())?;
            value_type = ty;
        }
        None => {
            match (value_type.clone(), is_array_init) {
                (TypeIdent::Array(elem_ty, _), false) => {
                    // NOTE: We are forcing a pointer if the rhs is an array, but not an
                    // array initializer
                    value_type = TypeIdent::Ref(elem_ty.clone());
                }
                _ => {}
            }
        }
    }
    Ok((value_type, value))
}

// TODO: span is always passed wrongly to this function. Need to store it within AstTypeIdent!
pub fn typecheck_typeident(
    context: &mut TypecheckContext,
    module_id: &ModuleUID,
    ty: &AstTypeIdent,
    span: Span,
    is_reference: bool,
    cycle: &mut Vec<SymbolUID>,
) -> TypeResult<TypeIdent> {
    match ty {
        AstTypeIdent::Atomic(atomic) => Ok((*atomic).into()),
        AstTypeIdent::Array(ty, ast_expr) => {
            let ty = typecheck_typeident(context, module_id, ty, span, is_reference, cycle)?;
            let len = {
                let mut expr_context = TypecheckFuncContext::new(*module_id);
                let len = typecheck_expr(
                    context,
                    &mut expr_context,
                    ast_expr,
                    &TypecheckMode::rvalue(),
                )?;
                match const_eval_expr(&expr_context, &len) {
                    Ok(ConstExpr::Literal(l)) => l.as_i64(),
                    _ => {
                        return Err(TypecheckError::new(
                            TypecheckErrorKind::InvalidConst,
                            *module_id,
                            ast_expr.span,
                        ));
                    }
                }
            };
            if len < 0 {
                Err(TypecheckError::new(
                    TypecheckErrorKind::InvalidArrayLength(len),
                    *module_id,
                    ast_expr.span,
                ))
            } else {
                Ok(TypeIdent::Array(Box::new(ty), len as usize))
            }
        }
        AstTypeIdent::Ref(ty) => {
            let ty = typecheck_typeident(context, module_id, ty, span, true, cycle)?;
            Ok(TypeIdent::Ref(Box::new(ty)))
        }
        AstTypeIdent::Compound(ident) if is_reference => {
            let type_id = resolve_identifier(context, module_id, ident, &span)?;
            let kind = context.symbol_table.get_symbol(&type_id).unwrap().kind;
            Ok(TypeIdent::from_symbol(type_id, kind))
        }
        AstTypeIdent::Compound(ident) => {
            let type_id = resolve_identifier(context, module_id, ident, &span)?;
            let symbol = context.symbol_table.get_symbol(&type_id).unwrap();
            match symbol.stage {
                SymbolStage::Typechecked => Ok(TypeIdent::from_symbol(type_id, symbol.kind)),
                SymbolStage::TypecheckInProgress => Err(TypecheckError::new(
                    TypecheckErrorKind::CircularTypeDependency {
                        cycle: cycle.clone(),
                    },
                    *module_id,
                    span,
                )),
                SymbolStage::SymbolResolved => {
                    let mut errors = Vec::new();
                    let module_uid = symbol.module_uid;
                    let kind = symbol.kind;
                    typecheck_typeident_symbol(
                        context,
                        module_id,
                        type_id,
                        kind,
                        span,
                        cycle,
                        &mut errors,
                    );
                    match errors.len() {
                        0 => Ok(TypeIdent::from_symbol(type_id, kind)),
                        1 => Err(errors[0].clone()),
                        _ => Err(TypecheckError::new(
                            TypecheckErrorKind::BlockErrors(errors),
                            *module_id,
                            span,
                        )),
                    }
                }
                _ => Err(TypecheckError::new(
                    TypecheckErrorKind::UndefinedTypeIdent,
                    *module_id,
                    span,
                )),
            }
        }
    }
}

pub fn typecheck_typeident_symbol(
    context: &mut TypecheckContext,
    module_uid: &ModuleUID,
    type_id: SymbolUID,
    kind: SymbolKind,
    span: Span,
    cycle: &mut Vec<SymbolUID>,
    errors: &mut Vec<TypecheckError>,
) {
    match kind {
        SymbolKind::Struct => {
            let symbol = context.symbol_table.get_symbol(&type_id).unwrap();
            let shallow_struct = symbol.shallow_struct().unwrap();
            typecheck_structdef(context, module_uid, &shallow_struct, type_id, errors, cycle);
        }
        SymbolKind::Union => {
            let symbol = context.symbol_table.get_symbol(&type_id).unwrap();
            let shallow_union = symbol.shallow_union().unwrap();
            typecheck_uniondef(context, module_uid, &shallow_union, type_id, errors, cycle);
        }
        SymbolKind::Global | SymbolKind::Function => {
            panic!("Typeident Symbol expected {type_id:?}")
        }
    }
}

pub fn typecheck_expr_typeident(
    global_context: &mut TypecheckContext,
    context: &mut TypecheckFuncContext,
    ty: &AstTypeIdent,
    span: Span,
) -> TypeResult<TypeIdent> {
    let module_id = context.module_id;
    let mut cycle = Vec::new();
    typecheck_typeident(global_context, &module_id, ty, span, false, &mut cycle)
}

fn block(
    global_context: &mut TypecheckContext,
    context: &mut TypecheckFuncContext,
    block: &Vec<AstStatement>,
    span: Span,
) -> TypeResult<Statement> {
    let mut errors = Vec::with_capacity(block.len());
    let mut stmnts = Vec::with_capacity(block.len());
    context.bindings.start_block();
    let mut returned = false;
    let mut nevered = false;
    let mut breaked = false;
    let mut continued = false;
    for statement in block {
        match typecheck_statement(global_context, context, statement) {
            Ok(stmnt) => {
                match &stmnt.flow {
                    StatementFlow::Some => {}
                    StatementFlow::Never => nevered = true,
                    StatementFlow::Return => returned = true,
                    StatementFlow::Break => breaked = true,
                    StatementFlow::Continue => continued = true,
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
            context.module_id,
            span,
        ));
    }
    let flow = if nevered {
        StatementFlow::Never
    } else if returned {
        StatementFlow::Return
    } else if breaked {
        StatementFlow::Break
    } else if continued {
        StatementFlow::Continue
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
    global_context: &mut TypecheckContext,
    context: &mut TypecheckFuncContext,
    value: &Option<AstExpr>,
    span: Span,
) -> TypeResult<Statement> {
    let expected = match context.return_type() {
        Ok(ret) => ret,
        _ => {
            return Err(TypecheckError::new(
                TypecheckErrorKind::ReturnInGlobalContext,
                context.module_id,
                span,
            ));
        }
    };
    let value = if let Some(value) = value {
        let span = value.span;
        let value = typecheck_expr(global_context, context, value, &TypecheckMode::rvalue())?;
        let value_type = unwrap_typeident(context.module_id, expr_type(&value), span)?;

        match expected {
            FlowType::Some(expected) => {
                let value = try_cast(context, value, value_type, expected)?;
                Some(value)
            }
            _ => {
                return Err(TypecheckError::new(
                    TypecheckErrorKind::InvalidReturnStatement {
                        expected,
                        got: FlowType::Some(value_type),
                    },
                    context.module_id,
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
                    context.module_id,
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
    global_context: &mut TypecheckContext,
    context: &mut TypecheckFuncContext,
    cond: &AstExpr,
    then: &AstStatement,
    otherwise: &Option<Box<AstStatement>>,
    span: Span,
) -> TypeResult<Statement> {
    let cond = typecheck_expr(global_context, context, cond, &TypecheckMode::rvalue())?;
    let cond_type = unwrap_typeident(context.module_id, expr_type(&cond), cond.span)?;
    let cond = try_cast(context, cond, cond_type, TypeIdent::Atomic(Atomic::bool()))?;

    let then = typecheck_statement(global_context, context, then)?;
    let then = Box::new(then);

    let otherwise = if let Some(otherwise) = otherwise {
        let otherwise = typecheck_statement(global_context, context, otherwise)?;
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
    global_context: &mut TypecheckContext,
    context: &mut TypecheckFuncContext,
    cond: &Option<AstExpr>,
    body: &AstStatement,
    span: Span,
) -> TypeResult<Statement> {
    context.loop_depth += 1;

    let cond = if let Some(cond) = cond {
        let cond = typecheck_expr(global_context, context, cond, &TypecheckMode::rvalue())?;
        let cond_type = unwrap_typeident(context.module_id, expr_type(&cond), cond.span)?;
        Some(try_cast(
            context,
            cond,
            cond_type,
            TypeIdent::Atomic(Atomic::bool()),
        )?)
    } else {
        None
    };
    let body = typecheck_statement(global_context, context, body)?;
    let body = Box::new(body);

    context.loop_depth -= 1;
    Ok(Statement {
        span,
        flow: StatementFlow::Some,
        kind: StatementKind::Loop { cond, body },
    })
}

fn typecheck_for(
    global_context: &mut TypecheckContext,
    context: &mut TypecheckFuncContext,
    init: &AstStatement,
    cond: &AstExpr,
    acc: &AstExpr,
    body: &AstStatement,
    span: Span,
) -> TypeResult<Statement> {
    context.loop_depth += 1;
    context.bindings.start_block();

    let init = typecheck_statement(global_context, context, init)?;
    let init = Box::new(init);

    let cond = typecheck_expr(global_context, context, cond, &TypecheckMode::rvalue())?;
    let cond_type = unwrap_typeident(context.module_id, expr_type(&cond), cond.span)?;
    let cond = try_cast(context, cond, cond_type, TypeIdent::Atomic(Atomic::bool()))?;

    let acc = typecheck_expr(global_context, context, acc, &TypecheckMode::rvalue())?;

    let body = typecheck_statement(global_context, context, body)?;
    let body = Box::new(body);

    context.bindings.end_block();
    context.loop_depth -= 1;
    Ok(Statement {
        span,
        flow: StatementFlow::Some,
        kind: StatementKind::For {
            init,
            acc,
            cond,
            body,
        },
    })
}

fn typecheck_break(context: &mut TypecheckFuncContext, span: Span) -> TypeResult<Statement> {
    if context.is_inside_loop() {
        Ok(Statement {
            span,
            flow: StatementFlow::Break,
            kind: StatementKind::Break,
        })
    } else {
        Err(TypecheckError::new(
            TypecheckErrorKind::BreakOutsideLoop,
            context.module_id,
            span,
        ))
    }
}

fn typecheck_continue(context: &mut TypecheckFuncContext, span: Span) -> TypeResult<Statement> {
    if context.is_inside_loop() {
        Ok(Statement {
            span,
            flow: StatementFlow::Continue,
            kind: StatementKind::Continue,
        })
    } else {
        Err(TypecheckError::new(
            TypecheckErrorKind::ContinueOutsideLoop,
            context.module_id,
            span,
        ))
    }
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
            StatementKind::For {
                init,
                acc,
                cond,
                body,
            } => {
                writeln!(f, "{pad}for")?;
                init.write(f, depth)?;
                cond.write(f, depth)?;
                acc.write(f, depth)?;
                body.write(f, depth)
            }
            StatementKind::Continue => writeln!(f, "{pad}continue;"),
            StatementKind::Break => writeln!(f, "{pad}break;"),
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
            StatementKind::For {
                init,
                acc,
                cond,
                body,
            } => {
                writeln!(f, "for {init} {cond} {acc} {body}")
            }
            StatementKind::Continue => write!(f, "continue"),
            StatementKind::Break => write!(f, "break"),
        }
    }
}
