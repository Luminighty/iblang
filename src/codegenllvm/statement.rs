use inkwell::IntPredicate;

use crate::{ast::{Expr, Identifier, Module, Statement, StatementKind}, utils::Span};

use super::{compiler::Compiler, error::CompilerErrorKind, CompileResult};

pub type CompileStatementResult<'a> = CompileResult<()>;

#[allow(unused_variables, dead_code)]
impl<'ctx> Compiler<'ctx> {
    pub fn compile_statement(&mut self, module: &Module, statement: &Statement) -> CompileStatementResult<'ctx> {
        match &statement.kind {
            StatementKind::VarDeclaration { mutable, ident, value } => self.var_declaration(module, ident, value, *mutable),
            StatementKind::Block(block) => self.block(module, block),
            StatementKind::Expr(expr) => self.expr(module, expr),
            StatementKind::Return { value } => self.ret(module, value),
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

    fn var_declaration(&mut self, module: &Module, ident: &Identifier, value: &Expr, mutable: bool) -> CompileStatementResult<'ctx> {
        let value_span = value.span;
        let value = self.compile_expr(module, value)?;
        let value = self.load_value(value, CompilerErrorKind::ValueExpected, value_span, "var_dec")?;

        let alloca = self.create_entry_block_alloca(ident, &value.typeident);
        self.builder.build_store(alloca, value.value).unwrap();
        self.bindings.insert(ident.to_owned(), alloca, value.typeident);
        Ok(())
    }

    fn block(&mut self, module: &Module, block: &Vec<Statement>) -> CompileStatementResult<'ctx> {
        self.bindings.start_block();
        for statement in block {
            self.compile_statement(module, statement)?;
        }
        self.bindings.end_block();
        Ok(())
    }

    fn expr(&mut self, module: &Module, expr: &Expr) -> CompileStatementResult<'ctx> {
        self.compile_expr(module, expr)?;
        Ok(())
    }

    fn ret(&mut self, module: &Module, value: &Option<Expr>) -> CompileStatementResult<'ctx> {
        if let Some(value) = value {
            let value_span = value.span;
            let value = self.compile_expr(module, value)?;
            let value = self.load_value(value, CompilerErrorKind::ValueExpected, value_span, "ret")?;
            self.builder.build_return(Some(&value.value)).unwrap();
        } else {
            self.builder.build_return(None).unwrap();
        }
        Ok(())
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
        self.compile_statement(module, then)?;
        self.builder.build_unconditional_branch(cont_bb).unwrap();

        self.builder.position_at_end(cont_bb);
        Ok(())
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
        self.compile_statement(module, then)?;
        self.builder.build_unconditional_branch(cont_bb).unwrap();

        self.builder.position_at_end(else_bb);
        self.compile_statement(module, otherwise)?;
        self.builder.build_unconditional_branch(cont_bb).unwrap();

        self.builder.position_at_end(cont_bb);
        Ok(())
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
        Ok(())
    }

    fn comp_loop(&mut self, module: &Module, body: &Statement) -> CompileStatementResult<'ctx> {
        let parent = self.fn_value();

        let body_bb = self.context.append_basic_block(parent, "loopbody");
        self.builder.build_unconditional_branch(body_bb).unwrap();

        self.builder.position_at_end(body_bb);
        self.compile_statement(module, body)?;
        self.builder.build_unconditional_branch(body_bb).unwrap();
        Ok(())
    }
}
