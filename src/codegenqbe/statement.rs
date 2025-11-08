use std::{fmt::format, ops::Deref};

use crate::{
    ast::prelude::Literal,
    codegenqbe::{
        expr::{CompileExprResult, QbeValue, compile_assign},
        literal::compile_literal,
        qbe::{BaseTy, Block},
    },
    typecheck::{
        TypeIdent,
        expr::{Expr, expr_type, unwrap_typeident},
        module::{Module, type_size_and_align},
        prelude::{Statement, StatementKind},
        statement::{MatchArm, MatchArmComponent},
    },
    utils::Span,
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
        StatementKind::Match { cond, cases } => {
            compile_match(context, module, cond, cases, statement.span)
        }
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
    let (size, align) = type_size_and_align(ty, context.symbol_table);

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
        TypeIdent::Union(_) => true,
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

            let (size, _) = type_size_and_align(&ty, context.symbol_table);
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

// NOTE: Returns expected flow based on two branches. For example, in if/else, if both branches
//  return, then we returned from the parent branch
fn branch_flow_result(left: CompiledStatement, right: CompiledStatement) -> CompiledStatement {
    match (left, right) {
        (CompiledStatement::Some, _) => CompiledStatement::Some,
        (_, CompiledStatement::Some) => CompiledStatement::Some,
        (CompiledStatement::Continue, _) => CompiledStatement::Continue,
        (_, CompiledStatement::Continue) => CompiledStatement::Continue,
        (CompiledStatement::Break, _) => CompiledStatement::Break,
        (_, CompiledStatement::Break) => CompiledStatement::Break,
        (CompiledStatement::Return, _) => CompiledStatement::Return,
        (_, CompiledStatement::Return) => CompiledStatement::Return,
        (CompiledStatement::Never, CompiledStatement::Never) => CompiledStatement::Never,
    }
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

    let flow = branch_flow_result(then_flow, otherwise_flow);
    if flow == CompiledStatement::Some {
        context.qbe.write_block(&block_end)?;
    }

    Ok(flow)
}

fn compile_match(
    context: &mut CompilerContext,
    module: &Module,
    value: &Expr,
    cases: &Vec<MatchArm>,
    span: Span,
) -> CompileStatementResult {
    context.qbe.comment(&format!("match {}", value))?;
    let value_ty = unwrap_typeident(module.id, expr_type(value), span)
        .expect("did not get a typeident when compiling match");
    // COND
    let value_span = value.span;
    let value = compile_expr(context, module, value)?;
    let value = unwrap_value(value, value_span)?;

    struct CaseBlock {
        cond: Block,
        body: Block,
    };

    let mut blocks = Vec::with_capacity(cases.len());
    for i in 0..cases.len() {
        blocks.push(CaseBlock {
            cond: context.qbe.create_block(&format!("case_{i}_cond")),
            body: context.qbe.create_block(&format!("case_{i}_body")),
        });
    }
    let mut block_default = None;

    let block_end = context.qbe.create_block(&format!("match_end"));
    let mut final_flow = None;

    context.qbe.jmp(&blocks[0].cond);
    for (i, case) in cases.iter().enumerate() {
        context.qbe.write_block(&blocks[i].cond);
        let mut matches = None;
        for comp in &case.comps {
            match (matches, comp) {
                (_, MatchArmComponent::Default) => {
                    block_default = Some(blocks[i].body);
                }
                (None, MatchArmComponent::Expr(l)) => {
                    let value = compile_match_case_cond(
                        context,
                        module,
                        &value,
                        &l,
                        &value_ty,
                        "match_cond",
                    )?;
                    let value = unwrap_value(value, span)?;
                    matches = Some(value);
                }
                (Some(prev), MatchArmComponent::Expr(l)) => {
                    let value = compile_match_case_cond(
                        context,
                        module,
                        &value,
                        &l,
                        &value_ty,
                        "match_cond",
                    )?;
                    let value = unwrap_value(value, span)?;
                    let res =
                        context
                            .qbe
                            .binary(BaseTy::W, "or", &prev, &value, "match_cond_or")?;
                    matches = Some(QbeValue::Temp(res));
                }
            }
        }

        let not_match = if let Some(next_block) = blocks.get(i + 1) {
            &next_block.cond
        } else if let Some(def) = &block_default {
            // NOTE: If no default case exist, we assume that the value is invalid,
            //  While we used a single enums variant. Therefore we skip the match
            def
        } else {
            &block_end
        };
        if let Some(matches) = matches {
            context.qbe.jnz(&matches, &blocks[i].body, not_match)?;
        } else {
            // NOTE: If matches is None, we assume that it's the default case and we jump into the next block
            context.qbe.jmp(not_match)?;
        }
        context.qbe.write_block(&blocks[i].body)?;
        let flow = compile_statement(context, module, &case.statement)?;
        if flow == CompiledStatement::Some {
            context.qbe.jmp(&block_end);
        }
        if let Some(final_flow_val) = final_flow {
            final_flow = Some(branch_flow_result(final_flow_val, flow));
        } else {
            final_flow = Some(flow);
        }
    }

    let final_flow = final_flow.expect("Final flow not found. Were there no match cases?");
    if final_flow == CompiledStatement::Some {
        context.qbe.write_block(&block_end)?;
    }
    Ok(final_flow)
}

fn compile_match_case_cond(
    context: &mut CompilerContext,
    module: &Module,
    value: &QbeValue,
    case: &Expr,
    ty: &TypeIdent,
    name: &str,
) -> CompileExprResult {
    let ty: BaseTy = ty.try_into()?;
    let l = compile_expr(context, module, case)?;
    let l = unwrap_value(l, Span::new(0, 0))?;
    let res = context
        .qbe
        .binary(BaseTy::W, &format!("ceq{ty}"), value, &l, &name)?;
    Ok(res.into())
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
