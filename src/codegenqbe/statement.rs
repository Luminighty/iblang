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
    expr::{CompiledExpr, compile_expr, unwrap_value},
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
    let block_then = context.qbe.create_block("then");
    let block_end = context.qbe.create_block("end");

    let cond_span = cond.span;
    let cond = compile_expr(context, module, cond)?;
    let cond = unwrap_value(cond, cond_span)?;
    context.qbe.jnz(&cond, &block_then, &block_end)?;

    context.qbe.write_block(&block_then)?;
    compile_statement(context, module, then)?;
    context.qbe.jmp(&block_end)?;

    context.qbe.write_block(&block_end)?;

    Ok(CompiledStatement::Some)
}

fn compile_if_full(
    context: &mut CompilerContext,
    module: &Module,
    cond: &Expr,
    then: &Statement,
    otherwise: &Statement,
) -> CompileStatementResult {
    let block_then = context.qbe.create_block("ifthen");
    let block_else = context.qbe.create_block("ifelse");
    let block_end = context.qbe.create_block("ifend");

    // COND
    let cond_span = cond.span;
    let cond = compile_expr(context, module, cond)?;
    let cond = unwrap_value(cond, cond_span)?;
    context.qbe.jnz(&cond, &block_then, &block_else)?;

    // THEN
    context.qbe.write_block(&block_then)?;
    let then_flow = compile_statement(context, module, then)?;
    context.qbe.jmp(&block_end)?;

    // ELSE
    context.qbe.write_block(&block_else)?;
    let otherwise_flow = compile_statement(context, module, otherwise)?;
    context.qbe.jmp(&block_end)?;

    context.qbe.write_block(&block_end)?;

    let flow = match (then_flow, otherwise_flow) {
        (CompiledStatement::Some, _) => CompiledStatement::Some,
        (_, CompiledStatement::Some) => CompiledStatement::Some,
        (CompiledStatement::Return, _) => CompiledStatement::Return,
        (_, CompiledStatement::Return) => CompiledStatement::Return,
        (CompiledStatement::Never, CompiledStatement::Never) => CompiledStatement::Never,
    };

    Ok(flow)
}

fn compile_loop_cond(
    context: &mut CompilerContext,
    module: &Module,
    cond: &Expr,
    body: &Statement,
) -> CompileStatementResult {
    let block_cond = context.qbe.create_block("loopcond");
    let block_body = context.qbe.create_block("loopbody");
    let block_end = context.qbe.create_block("loopend");

    // COND
    context.qbe.write_block(&block_cond)?;
    let cond_span = cond.span;
    let cond = compile_expr(context, module, cond)?;
    let cond = unwrap_value(cond, cond_span)?;
    context.qbe.jnz(&cond, &block_body, &block_end)?;

    // LOOP BODY
    context.qbe.write_block(&block_body)?;
    compile_statement(context, module, body)?;
    context.qbe.jmp(&block_end)?;

    Ok(CompiledStatement::Some)
}

fn compile_loop(
    context: &mut CompilerContext,
    module: &Module,
    body: &Statement,
) -> CompileStatementResult {
    let block_body = context.qbe.create_block("loop");

    context.qbe.write_block(&block_body)?;
    let flow = compile_statement(context, module, body)?;
    context.qbe.jmp(&block_body)?;

    // TODO: Check for break and continue
    let flow = match flow {
        CompiledStatement::Return => CompiledStatement::Return,
        _ => CompiledStatement::Never,
    };
    Ok(flow)
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
