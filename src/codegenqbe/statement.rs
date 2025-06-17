use crate::typecheck::{
    TypeIdent,
    expr::Expr,
    module::Module,
    prelude::{Statement, StatementKind},
};

use super::{
    CompileResult,
    compiler::CompilerContext,
    error::CompilerError,
    expr::{CompiledExpr, compile_expr},
};

pub type CompileStatementResult = CompileResult<CompiledStatement>;

pub enum CompiledStatement {
    Some,
    Never,
    Return,
}

pub fn compile_statement(
    context: &mut CompilerContext,
    module: &Module,
    statement: &Statement,
) -> CompileStatementResult {
    match &statement.kind {
        StatementKind::VarDeclaration {
            mutable,
            ident,
            ty,
            value,
        } => var_declaration(context, module, *mutable, ident, ty, value),
        StatementKind::Block(b) => block(context, module, b),
        StatementKind::Expr(expr) => Ok(compile_expr(context, module, expr)?.into()),
        StatementKind::Return { value } => compile_return(context, module, value),
        StatementKind::If {
            cond,
            then,
            otherwise,
        } => {
            if let Some(otherwise) = otherwise {
                compile_if_full(context, module, cond, then, otherwise)
            } else {
                compile_if_partial(context, module, cond, then)
            }
        }
        StatementKind::Loop { cond, body } => {
            if let Some(cond) = cond {
                compile_loop_cond(context, module, cond, body)
            } else {
                compile_loop(context, module, body)
            }
        }
    }
}

fn var_declaration(
    context: &mut CompilerContext,
    module: &Module,
    mutable: bool,
    ident: &str,
    ty: &TypeIdent,
    value: &Expr,
) -> CompileStatementResult {
    todo!()
}

fn block(
    context: &mut CompilerContext,
    module: &Module,
    block: &Vec<Statement>,
) -> CompileStatementResult {
    let mut errors = Vec::with_capacity(block.len());
    let mut result = CompiledStatement::Some;
    context.bindings.start_block();
    for statement in block {
        match compile_statement(context, module, statement) {
            Ok(CompiledStatement::Never) => {
                result = CompiledStatement::Never;
                break;
            }
            Ok(CompiledStatement::Return) => {
                result = CompiledStatement::Return;
                break;
            }
            Ok(CompiledStatement::Some) => {}
            Err(err) => errors.push(err),
        }
    }
    context.bindings.end_block();
    if errors.len() > 0 {
        return Err(CompilerError::Block(errors));
    } else {
        return Ok(result);
    }
}

fn compile_return(
    context: &mut CompilerContext,
    module: &Module,
    value: &Option<Expr>,
) -> CompileStatementResult {
    todo!()
}

fn compile_if_partial(
    context: &mut CompilerContext,
    module: &Module,
    cond: &Expr,
    then: &Statement,
) -> CompileStatementResult {
    todo!()
}

fn compile_if_full(
    context: &mut CompilerContext,
    module: &Module,
    cond: &Expr,
    then: &Statement,
    otherwise: &Statement,
) -> CompileStatementResult {
    todo!()
}

fn compile_loop_cond(
    context: &mut CompilerContext,
    module: &Module,
    cond: &Expr,
    body: &Statement,
) -> CompileStatementResult {
    todo!()
}

fn compile_loop(
    context: &mut CompilerContext,
    module: &Module,
    body: &Statement,
) -> CompileStatementResult {
    todo!()
}

impl Into<CompiledStatement> for CompiledExpr {
    fn into(self) -> CompiledStatement {
        match self {
            CompiledExpr::Never => CompiledStatement::Never,
            CompiledExpr::Void => CompiledStatement::Some,
            CompiledExpr::Temp(_) => CompiledStatement::Some,
        }
    }
}
