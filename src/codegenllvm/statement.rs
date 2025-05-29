use inkwell::IntPredicate;

use crate::{ast::Identifier, typecheck::{FlowType, TypeIdent}, utils::Span};
use crate::typecheck::prelude::*;

use super::{bindings::VariableBinding, compiler::Compiler, error::CompilerErrorKind, CompileResult};

pub enum CompiledStatement {
    Some,
    Never,
    Return,
}

pub type CompileStatementResult<'a> = CompileResult<CompiledStatement>;

#[allow(unused_variables, dead_code)]
impl<'ctx> Compiler<'ctx> {
    pub fn compile_statement(&mut self, module: &Module, statement: &Statement) -> CompileStatementResult<'ctx> {
        match &statement.kind {
            StatementKind::VarDeclaration { mutable, ident, value, ty } => self.var_declaration(module, ident, value, *mutable, ty),
            StatementKind::Block(block) => self.block(module, block, statement.span),
            StatementKind::Expr(expr) => self.expr(module, expr),
            StatementKind::Return { value } => self.ret(module, value, statement.span),
            StatementKind::If { cond, then, otherwise } => {
                if let Some(otherwise) = otherwise {
                    self.comp_if_full(module, cond, then, otherwise)
                } else {
                    self.comp_if_partial(module, cond, then)
                }
            }
            StatementKind::Loop { cond, body } => {
                if let Some(cond) = cond {
                    self.comp_loop_cond(module, cond, body)
                } else {
                    self.comp_loop(module, body)
                }
            }
        }
    }

    fn var_declaration(&mut self, module: &Module, ident: &Identifier, value: &Expr, mutable: bool, ty: &TypeIdent) -> CompileStatementResult<'ctx> {
        let value_span = value.span;
        let value = self.compile_expr(module, value)?;
        let value = self.load_value(value, CompilerErrorKind::ValueExpected, value_span, "var_dec")?;

        let alloca = self.create_entry_block_alloca(ident, &ty);
        self.builder.build_store(alloca, value.value).unwrap();
        self.bindings.insert(ident.to_owned(), VariableBinding::new(alloca, ty.clone()));
        Ok(CompiledStatement::Some)
    }

    fn block(&mut self, module: &Module, block: &Vec<Statement>, span: Span) -> CompileStatementResult<'ctx> {
        let mut errors = Vec::with_capacity(block.len());
        self.bindings.start_block();
        let mut result = CompiledStatement::Some;
        for statement in block {
            match self.compile_statement(module, statement) {
                Ok(CompiledStatement::Never) => { result = CompiledStatement::Never; break; },
                Ok(CompiledStatement::Return) => { result = CompiledStatement::Return; break; },
                Ok(CompiledStatement::Some) => {},
                Err(err) => errors.push(err),
            }
        }
        self.bindings.end_block();

        if errors.len() > 0 {
            return self.error(CompilerErrorKind::BlockErrors(errors), span)
        } else {
            return Ok(result);
        }
    }

    fn expr(&mut self, module: &Module, expr: &Expr) -> CompileStatementResult<'ctx> {
        Ok(self.compile_expr(module, expr)?.into())
    }

    fn ret(&mut self, module: &Module, value: &Option<Expr>, span: Span) -> CompileStatementResult<'ctx> {
        let expected = self.return_type();
        if let Some(value) = value {
            let value_span = value.span;
            let value = self.compile_expr(module, value)?;
            let value = self.load_value(value, CompilerErrorKind::ValueExpected, value_span, "ret")?;
            match expected {
                FlowType::Some(expected) => {
                    let value = self.cast_to_type(value, expected, "return_cast");
                    self.builder.build_return(Some(&value)).unwrap();
                },
                _ => {
                    return self.error(CompilerErrorKind::InvalidReturnStatement {
                        expected,
                        got: FlowType::Some(value.typeident),
                    }, span)
                }
            }
        } else {
            match expected {
                FlowType::Void => { self.builder.build_return(None).unwrap(); },
                _ => {
                    return self.error(CompilerErrorKind::InvalidReturnStatement {
                        expected,
                        got: FlowType::Void,
                    }, span)
                }
            }
        }
        Ok(CompiledStatement::Return)
    }

    fn comp_if_partial(&mut self, module: &Module, cond: &Expr, then: &Statement) -> CompileStatementResult<'ctx> {
        let parent = self.fn_value();
        let cond_span = cond.span;
        let cond = self.compile_expr(module, cond)?;
        let cond = self.load_value(cond, CompilerErrorKind::ValueExpected, cond_span, "ifcondval")?;

        let zero_const = self.context.bool_type().const_zero();
        let cond = self.builder.build_int_compare(IntPredicate::NE, cond.value.try_into().unwrap(), zero_const, "ifcond").unwrap();

        let then_bb = self.context.append_basic_block(parent, "then");
        let cont_bb = self.context.append_basic_block(parent, "ifcont");

        self.builder.build_conditional_branch(cond, then_bb, cont_bb).unwrap();

        self.builder.position_at_end(then_bb);
        match self.compile_statement(module, then)? {
            CompiledStatement::Some => {
                self.builder.build_unconditional_branch(cont_bb).unwrap();
            }
            _ => {},
        }

        self.builder.position_at_end(cont_bb);
        Ok(CompiledStatement::Some)
    }

    fn comp_if_full(&mut self, module: &Module, cond: &Expr, then: &Statement, otherwise: &Statement) -> CompileStatementResult<'ctx> {
        let parent = self.fn_value();
        let cond_span = cond.span;
        let cond = self.compile_expr(module, cond)?;
        let cond = self.load_value(cond, CompilerErrorKind::ValueExpected, cond_span, "ifcondval")?;
        let zero_const = self.context.bool_type().const_zero();
        let cond = self.builder.build_int_compare(IntPredicate::NE, cond.value.try_into().unwrap(), zero_const, "ifcond").unwrap();

        let then_bb = self.context.append_basic_block(parent, "then");
        let else_bb = self.context.append_basic_block(parent, "else");
        let cont_bb = self.context.append_basic_block(parent, "ifcont");

        self.builder.build_conditional_branch(cond, then_bb, else_bb).unwrap();

        self.builder.position_at_end(then_bb);
        let lhs_res = self.compile_statement(module, then)?;
        match lhs_res {
            CompiledStatement::Some => {
                self.builder.build_unconditional_branch(cont_bb).unwrap();
            },
            _ => {},
        }

        self.builder.position_at_end(else_bb);
        let rhs_res = self.compile_statement(module, otherwise)?;
        match rhs_res {
            CompiledStatement::Some => {
                self.builder.build_unconditional_branch(cont_bb).unwrap();
            },
            _ => {},
        }

        self.builder.position_at_end(cont_bb);
        let res = match (lhs_res, rhs_res) {
            (CompiledStatement::Some, _) => CompiledStatement::Some,
            (_, CompiledStatement::Some) => CompiledStatement::Some,
            (CompiledStatement::Return, _) => CompiledStatement::Return,
            (_, CompiledStatement::Return) => CompiledStatement::Return,
            (CompiledStatement::Never, CompiledStatement::Never) => CompiledStatement::Never,
        };
        Ok(res)
    }

    fn comp_loop_cond(&mut self, module: &Module, cond: &Expr, body: &Statement) -> CompileStatementResult<'ctx> {
        let parent = self.fn_value();

        let cond_bb = self.context.append_basic_block(parent, "cond");
        let body_bb = self.context.append_basic_block(parent, "body");
        let end_bb = self.context.append_basic_block(parent, "loopcont");
        self.builder.build_unconditional_branch(cond_bb).unwrap();

        self.builder.position_at_end(cond_bb);
        let cond_span = cond.span;
        let cond = self.compile_expr(module, cond)?;
        let cond = self.load_value(cond, CompilerErrorKind::ValueExpected, cond_span, "loopcondval")?;
        let zero_const = self.context.bool_type().const_zero();
        let cond = self.builder.build_int_compare(IntPredicate::NE, cond.value.try_into().unwrap(), zero_const, "loopcond").unwrap();

        self.builder.build_conditional_branch(cond, body_bb, end_bb).unwrap();
        self.builder.position_at_end(body_bb);
        self.compile_statement(module, body)?;
        self.builder.build_unconditional_branch(cond_bb).unwrap();

        self.builder.position_at_end(end_bb);
        Ok(CompiledStatement::Some)
    }

    fn comp_loop(&mut self, module: &Module, body: &Statement) -> CompileStatementResult<'ctx> {
        let parent = self.fn_value();

        let body_bb = self.context.append_basic_block(parent, "loopbody");
        // let end_bb = self.context.append_basic_block(parent, "loopcont");
        self.builder.build_unconditional_branch(body_bb).unwrap();

        self.builder.position_at_end(body_bb);
        self.compile_statement(module, body)?;
        self.builder.build_unconditional_branch(body_bb).unwrap();

        // self.builder.position_at_end(end_bb);
        // TODO: When adding break, make sure to update this value
        Ok(CompiledStatement::Never)
    }
}

