use std::{fmt::format, ops::Deref};

use crate::{
    codegenqbe::expr::{QbeValue, compile_assign},
    typecheck::{
        TypeIdent,
        expr::{Expr, expr_type, unwrap_typeident},
        module::Module,
        prelude::{Statement, StatementKind},
    },
};

use super::{
    CompilerResult,
    bindings::VariableBinding,
    compiler::CompilerContext,
    error::CompilerError,
    expr::{CompiledExpr, compile_expr, unwrap_value},
    qbe::{QbeResult, Temp},
};

pub type CompileStatementResult = CompilerResult<CompiledStatement>;

#[derive(PartialEq, Eq)]
pub enum CompiledStatement {
    Some,
    Never,
    Return,
    Continue,
    Break,
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
        StatementKind::Expr(expr) => {
            context.qbe.comment(&format!("{expr}"))?;
            Ok(compile_expr(context, module, expr)?.into())
        }
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
        StatementKind::For {
            init,
            acc,
            cond,
            body,
        } => compile_for(context, module, init, cond, acc, body),
        StatementKind::Continue => compile_continue(context, module),
        StatementKind::Break => compile_break(context, module),
    }
}

pub fn alloc_type(
    context: &mut CompilerContext,
    module: &Module,
    ty: &TypeIdent,
    alloca_str: &str,
) -> QbeResult<Temp> {
    alloc_type_n(context, module, ty, 1, alloca_str)
}

pub fn alloc_type_n(
    context: &mut CompilerContext,
    module: &Module,
    ty: &TypeIdent,
    amount: usize,
    alloca_str: &str,
) -> QbeResult<Temp> {
    let (size, align) = module.type_size_and_align(ty, context.symbol_table);

    context
        .qbe
        .comment(&format!("alloc {ty} {size} * {amount}"));
    if align <= 4 {
        context.qbe.alloc4(size * amount, &alloca_str)
    } else if align <= 8 {
        context.qbe.alloc8(size * amount, &alloca_str)
    } else {
        context.qbe.alloc16(size * amount, &alloca_str)
    }
}

// NOTE: A type uses the target_alloca, if it should rely on the target_alloca context when
// initializing. These are generally the compound types
// (not something that may get stored using a single "store" command)
pub fn is_type_uses_target_alloca(ty: &TypeIdent) -> bool {
    match ty {
        TypeIdent::Struct(_) => true,
        TypeIdent::Array(_, _) => true,
        _ => false,
    }
}

fn var_declaration(
    context: &mut CompilerContext,
    module: &Module,
    _mutable: bool,
    ident: &str,
    ty: &TypeIdent,
    value: &Expr,
) -> CompileStatementResult {
    context
        .qbe
        .comment(&format!("let {ident}: {ty} = {value}"))?;

    let alloca_str = format!("var_{ident}");
    let alloca = alloc_type(context, module, ty, &alloca_str)?;

    let value_span = value.span;
    let alloca = if is_type_uses_target_alloca(ty) {
        context.target_alloca_push(alloca.into());
        let value = compile_expr(context, module, value)?;
        let value = unwrap_value(value, value_span)?;
        context.target_alloca_pop().unwrap_term()
    } else {
        let value = compile_expr(context, module, value)?;
        let value = unwrap_value(value, value_span)?;
        context.qbe.store(ty, &value, &alloca)?;
        alloca
    };

    let bind = VariableBinding::new(alloca, ty.clone());
    context.bindings.insert(ident.to_owned(), bind);
    Ok(CompiledStatement::Some)
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
            Ok(CompiledStatement::Some) => {}
            Ok(flow) => {
                result = flow;
                break;
            }
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
    match (value, context.return_alloca) {
        (Some(value), Some(alloca)) => {
            context.qbe.comment(&format!("return {}", value))?;
            let value_span = value.span;
            let ty = unwrap_typeident(module.id, expr_type(value), value_span).unwrap();
            let value = compile_expr(context, module, value)?;
            let value = unwrap_value(value, value_span)?;

            let (size, _) = module.type_size_and_align(&ty, context.symbol_table);
            // NOTE: We might need to call memcpy if the struct is large!
            context.qbe.blit(&value, &alloca, size)?;

            context.qbe.ret()?;
        }
        (Some(value), None) => {
            context.qbe.comment(&format!("return {}", value))?;
            let value_span = value.span;
            let value = compile_expr(context, module, value)?;
            let value = unwrap_value(value, value_span)?;
            context.qbe.retv(&value)?;
        }
        (None, _) => {
            context.qbe.comment(&format!("return"))?;
            context.qbe.ret()?;
        }
    }
    Ok(CompiledStatement::Return)
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
    context.qbe.comment(&format!("if {}", cond))?;
    let cond = compile_expr(context, module, cond)?;
    let cond = unwrap_value(cond, cond_span)?;
    context.qbe.jnz(&cond, &block_then, &block_end)?;

    context.qbe.write_block(&block_then)?;
    let flow = compile_statement(context, module, then)?;

    match flow {
        CompiledStatement::Some => {
            context.qbe.jmp(&block_end)?;
        }
        _ => {}
    }
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

    context.qbe.comment(&format!("if {}", cond))?;
    // COND
    let cond_span = cond.span;
    let cond = compile_expr(context, module, cond)?;
    let cond = unwrap_value(cond, cond_span)?;
    context.qbe.jnz(&cond, &block_then, &block_else)?;

    // THEN
    context.qbe.write_block(&block_then)?;
    let then_flow = compile_statement(context, module, then)?;
    if then_flow == CompiledStatement::Some {
        context.qbe.jmp(&block_end)?;
    }

    // ELSE
    context.qbe.write_block(&block_else)?;
    let otherwise_flow = compile_statement(context, module, otherwise)?;
    if otherwise_flow == CompiledStatement::Some {
        context.qbe.jmp(&block_end)?;
    }

    let flow = match (then_flow, otherwise_flow) {
        (CompiledStatement::Some, _) => CompiledStatement::Some,
        (_, CompiledStatement::Some) => CompiledStatement::Some,
        (CompiledStatement::Continue, _) => CompiledStatement::Continue,
        (_, CompiledStatement::Continue) => CompiledStatement::Continue,
        (CompiledStatement::Break, _) => CompiledStatement::Break,
        (_, CompiledStatement::Break) => CompiledStatement::Break,
        (CompiledStatement::Return, _) => CompiledStatement::Return,
        (_, CompiledStatement::Return) => CompiledStatement::Return,
        (CompiledStatement::Never, CompiledStatement::Never) => CompiledStatement::Never,
    };
    if flow == CompiledStatement::Some {
        context.qbe.write_block(&block_end)?;
    }

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
    context.qbe.jmp(&block_cond)?;
    context.qbe.write_block(&block_cond)?;
    context.qbe.comment(&format!("while {}", cond))?;
    let cond_span = cond.span;
    let cond = compile_expr(context, module, cond)?;
    let cond = unwrap_value(cond, cond_span)?;
    context.qbe.jnz(&cond, &block_body, &block_end)?;

    // LOOP BODY
    context.qbe.write_block(&block_body)?;
    context.loop_push(block_cond, block_end);
    let flow = compile_statement(context, module, body)?;
    context.loop_pop();
    match flow {
        CompiledStatement::Some => context.qbe.jmp(&block_cond)?,
        _ => {}
    }

    context.qbe.write_block(&block_end)?;

    Ok(CompiledStatement::Some)
}

fn compile_loop(
    context: &mut CompilerContext,
    module: &Module,
    body: &Statement,
) -> CompileStatementResult {
    let block_body = context.qbe.create_block("loopbody");
    let block_end = context.qbe.create_block("loopend");

    context.qbe.jmp(&block_body)?;
    context.qbe.write_block(&block_body)?;
    context.loop_push(block_body, block_end);
    let flow = compile_statement(context, module, body)?;
    let loop_context = context.loop_pop().unwrap();
    match flow {
        CompiledStatement::Some => context.qbe.jmp(&block_body)?,
        _ => {}
    }
    context.qbe.write_block(&block_end)?;

    if loop_context.has_break {
        return Ok(CompiledStatement::Some);
    }

    let flow = match flow {
        CompiledStatement::Return => CompiledStatement::Return,
        _ => CompiledStatement::Never,
    };
    Ok(flow)
}

fn compile_for(
    context: &mut CompilerContext,
    module: &Module,
    init: &Statement,
    cond: &Expr,
    acc: &Expr,
    body: &Statement,
) -> CompileStatementResult {
    context.bindings.start_block();

    let block_acc = context.qbe.create_block("foracc");
    let block_cond = context.qbe.create_block("forcond");
    let block_body = context.qbe.create_block("forbody");
    let block_end = context.qbe.create_block("forend");

    // INIT
    context.qbe.comment(&format!("forinit {}", init))?;
    compile_statement(context, module, init)?;
    context.qbe.jmp(&block_cond)?;

    // LOOP COND
    context.qbe.write_block(&block_cond)?;
    context.qbe.comment(&format!("{}", cond))?;
    let cond_span = cond.span;
    let cond = compile_expr(context, module, cond)?;
    let cond = unwrap_value(cond, cond_span)?;
    context.qbe.jnz(&cond, &block_body, &block_end)?;

    // LOOP BODY
    context.qbe.write_block(&block_body)?;
    context.loop_push(block_acc, block_end);
    let flow = compile_statement(context, module, body)?;
    context.loop_pop();
    match flow {
        CompiledStatement::Some => context.qbe.jmp(&block_acc)?,
        _ => {}
    }

    // LOOP ACC
    context.qbe.write_block(&block_acc)?;
    compile_expr(context, module, acc)?;
    context.qbe.jmp(&block_cond)?;

    context.qbe.write_block(&block_end)?;

    context.bindings.end_block();

    Ok(CompiledStatement::Some)
}

fn compile_continue(context: &mut CompilerContext, module: &Module) -> CompileStatementResult {
    let block_continue = context.loop_context().unwrap().block_continue.clone();
    context.qbe.jmp(&block_continue)?;
    Ok(CompiledStatement::Continue)
}
fn compile_break(context: &mut CompilerContext, module: &Module) -> CompileStatementResult {
    let block_break = context.loop_context().unwrap().block_break.clone();
    context.loop_break();
    context.qbe.jmp(&block_break)?;
    Ok(CompiledStatement::Break)
}

impl Into<CompiledStatement> for CompiledExpr {
    fn into(self) -> CompiledStatement {
        match self {
            CompiledExpr::Never => CompiledStatement::Never,
            CompiledExpr::Void => CompiledStatement::Some,
            CompiledExpr::Temp(_) => CompiledStatement::Some,
            CompiledExpr::Global(global) => CompiledStatement::Some,
        }
    }
}
