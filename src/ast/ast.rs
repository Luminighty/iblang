use crate::{ast::declaration::Global, lexer::{token::TokenKind, Token}, types::{ExprTypeIdent, TypeIdent}, utils::Span};

use super::Identifier;
use super::statement::Statement;
use super::precedence;
use super::function::{Extern, Function, Prototype};
use super::expr::Expr;
use super::error::{AstError, AstErrorKind};
use super::declaration::Declaration;

pub struct Ast {
    file: Option<String>,
    tokens: Vec<Token>,
    infix: precedence::InfixMap,
    prefix: precedence::PrefixMap,
    current: usize,
}

type AstResult<T> = Result<T, AstError>;

impl Ast {
    pub fn new(tokens: Vec<Token>) -> Self {
        Self { 
            file: None, 
            tokens, 
            current: 0,
            infix: precedence::InfixPrecedence::default(),
            prefix: precedence::PrefixPrecedence::default(),
        }
    }

    pub fn with_file(mut self, file: String) -> Self {
        self.file = Some(file);
        self
    }

    pub fn next(&mut self) -> AstResult<Declaration> {
        self.declaration()
    }

    fn declaration(&mut self) -> AstResult<Declaration> {
        match self.curr() {
            TokenKind::EOF => Ok(Declaration::None),
            TokenKind::Fn => self.parse_function(),
            TokenKind::Extern => self.parse_extern(),
            TokenKind::Let => self.parse_global(true),
            TokenKind::Const => self.parse_global(false),
            _ => self.error(AstErrorKind::UnknownDeclaration),
        }
    }
    fn parse_extern(&mut self) -> AstResult<Declaration> {
        let start = self.span_start();

        self.step();
        let proto = self.parse_prototype()?;

        let span = self.span_end(start);
        Ok(Declaration::Extern(Extern::new(proto, span)))
    }

    fn parse_function(&mut self) -> AstResult<Declaration> {
        let start = self.span_start();
        self.step();

        let proto = self.parse_prototype()?;
        let body = self.parse_block()?;

        let span = self.span_end(start);
        Ok(Declaration::Function(Function::new(proto, body, span)))
    }

    fn parse_prototype(&mut self) -> AstResult<Prototype> {
        let ident = self.identifier(AstErrorKind::InvalidPrototype)?;
        self.consume(TokenKind::ParenL, AstErrorKind::InvalidPrototype)?;
        let mut args = Vec::new();
        loop {
            if *self.curr() == TokenKind::ParenR { self.step(); break; }

            let ident =  self.identifier(AstErrorKind::InvalidPrototype)?;
            self.consume(TokenKind::Colon, AstErrorKind::TypeIdentExpected)?;
            let typeident = self.parse_type_ident()?;
            args.push((ident, typeident));
            
            if *self.curr() == TokenKind::Comma {
                self.step();
            } else {
                self.consume(TokenKind::ParenR, AstErrorKind::InvalidPrototype)?;
                break;
            }
        }

        let ret_type = if *self.curr() == TokenKind::Colon {
            self.step();
            self.parse_expr_type_ident()?
        } else {
            ExprTypeIdent::Void
        };
        Ok(Prototype::new(ident, args, ret_type))
    }

    fn identifier(&mut self, error: AstErrorKind) -> AstResult<Identifier> {
        let ident = match self.curr() {
            TokenKind::Ident(ident) => ident.to_owned(),
            _ => return self.error(error),
        };
        self.step();
        Ok(ident)
    }

    fn parse_global(&mut self, mutable: bool) -> AstResult<Declaration> {
        let start = self.span_start();

        self.step();
        let ident = self.identifier(AstErrorKind::InvalidVarDeclaration)?;
        self.consume(TokenKind::Equal, AstErrorKind::InvalidVarDeclaration)?;
        let value = self.parse_expr()?;
        self.consume(TokenKind::SemiColon, AstErrorKind::InvalidVarDeclaration)?;

        let span = self.span_end(start);
        Ok(Declaration::Global(Global::new(ident, value, mutable, span)))
    }

    fn parse_statement(&mut self) -> AstResult<Statement> {
        match self.curr() {
            TokenKind::Let => self.parse_var_dec(true),
            TokenKind::Const => self.parse_var_dec(false),
            TokenKind::BraceL => self.parse_block(),
            TokenKind::Return => self.parse_return(),
            TokenKind::If => self.parse_if(),
            TokenKind::Loop => self.parse_loop(),
            TokenKind::While => self.parse_while(),
            _ => {
                let expr = self.parse_expr()?;
                self.consume(TokenKind::SemiColon, AstErrorKind::SemicolonExpected)?;
                Ok(Statement::expr(expr))
            }
        }
    }

    fn parse_while(&mut self) -> AstResult<Statement> {
        let start = self.span_start();
        self.step();
        let cond = self.parse_expr()?;
        let body = self.parse_block()?;
        let span = self.span_end(start);
        Ok(Statement::new_loop(Some(cond), Box::new(body), span))
    }

    fn parse_loop(&mut self) -> AstResult<Statement> {
        let start = self.span_start();
        self.step();
        let body = self.parse_block()?;
        let span = self.span_end(start);
        Ok(Statement::new_loop(None, Box::new(body), span))
    }

    fn parse_if(&mut self) -> AstResult<Statement> {
        let start = self.span_start();
        self.step();
        let cond = self.parse_expr()?;
        let then = self.parse_block()?;
        let otherwise = if *self.curr() == TokenKind::Else {
            self.step();
            Some(Box::new(self.parse_block()?))
        } else {
            None
        };
        let span = self.span_end(start);
        Ok(Statement::new_if(cond, Box::new(then), otherwise, span))
    }

    fn parse_return(&mut self) -> AstResult<Statement> {
        let start = self.span_start();
        self.step();
        let value = if *self.curr() != TokenKind::SemiColon {
            Some(self.parse_expr()?)
        } else {
            None
        };
        self.consume(TokenKind::SemiColon, AstErrorKind::SemicolonExpected)?;
        let span = self.span_end(start);
        Ok(Statement::new_return(value, span))
    }

    fn parse_var_dec(&mut self, mutable: bool) -> AstResult<Statement> {
        let start = self.span_start();

        self.step();
        let ident = self.identifier(AstErrorKind::InvalidVarDeclaration)?;
        self.consume(TokenKind::Equal, AstErrorKind::InvalidVarDeclaration)?;
        let value = self.parse_expr()?;
        self.consume(TokenKind::SemiColon, AstErrorKind::InvalidVarDeclaration)?;

        let span = self.span_end(start);
        Ok(Statement::var_declaration(ident, value, mutable, span))
    }

    fn parse_block(&mut self) -> AstResult<Statement> {
        let start = self.span_start();

        self.consume(TokenKind::BraceL, AstErrorKind::BlockExpected)?;
        let mut block = Vec::new();
        loop {
            match self.curr() {
                TokenKind::EOF => return self.error(AstErrorKind::UnterminatedBlock),
                TokenKind::BraceR => break,
                _ => block.push(self.parse_statement()?)
            }
        }
        let span = self.span_end(start);
        self.step();
        Ok(Statement::block(block, span))
    }

    fn parse_expr(&mut self) -> AstResult<Expr> {
        self.parse_expr_prec(0)
    }

    fn parse_expr_prec(&mut self, min_prec: u8) -> AstResult<Expr> {
        let mut lhs = self.primary()?; 
        loop {
            let op = match self.curr() {
                TokenKind::EOF | TokenKind::SemiColon => break,
                op => op.clone(),
            };
            if op == TokenKind::ParenL {
                lhs = self.parse_call(lhs)?;
                continue;
            }

            if let Some(infix) = self.infix.get(&op).cloned() {
                if infix.prec < min_prec {
                    break;
                }
                self.step(); // Consume the operator
                let rhs = self.parse_expr_prec(infix.new_prec)?;
                if let Some((token, error)) = &infix.suffix {
                        self.consume(token.clone(), error.clone())?;
                }
                lhs = Expr::binary(infix.op, Box::new(lhs), Box::new(rhs));
            } else {
                break;
            }
        }
        Ok(lhs)
    }

    fn primary(&mut self) -> AstResult<Expr> {
        let start = self.span_start();
        let span = self.span_curr();
        let expr = match self.curr() {
            TokenKind::Number(n) => Expr::number(*n, span),
            TokenKind::String(s) => Expr::string(s.to_owned(), span),
            TokenKind::True => Expr::bool(true, span),
            TokenKind::False => Expr::bool(false, span),
            TokenKind::Char(c) => Expr::char(*c, span),
            TokenKind::Ident(ident) => Expr::ident(ident.clone(), span),
            token => {
                if let Some(prec) = self.prefix.get(token).cloned() {
                    let start = self.span_start();
                    self.step();
                    let expr = self.parse_expr_prec(prec.new_prec)?;

                    if let Some((token, error)) = &prec.suffix {
                        self.consume(token.clone(), error.clone())?;
                    }
                    let span = self.span_end(start);
                    return Ok(Expr::unary(prec.op.clone(), Box::new(expr), span))
                } else {
                    return self.error(AstErrorKind::UnknownPrimary);
                }
            },
        };
        self.step();
        Ok(expr)
    }

    fn parse_expr_type_ident(&mut self) -> AstResult<ExprTypeIdent> {
        match self.curr() {
            TokenKind::Void => Ok(ExprTypeIdent::Void),
            TokenKind::Bang => Ok(ExprTypeIdent::Never),
            _ => Ok(ExprTypeIdent::Some(self.parse_type_ident()?)),
        }
    }

    fn parse_type_ident(&mut self) -> AstResult<TypeIdent> {
        let res = match self.curr() {
            TokenKind::TypeIdent(ty) => ty.into(),
            _ => self.error(AstErrorKind::TypeIdentExpected)?,
        };
        self.step();
        Ok(res)
    }

    fn parse_call(&mut self, callee: Expr) -> AstResult<Expr> {
        let start = self.span_start();
        self.step();
        let mut args = Vec::new();
        loop {
            match self.curr() {
                TokenKind::EOF => self.error(AstErrorKind::UnterminatedParen)?,
                TokenKind::ParenR => {
                    self.step();
                    break;
                },
                _ => {
                    let arg = self.parse_expr()?;
                    args.push(arg);
                    // NOTE: Optional leading comma
                    if *self.curr() == TokenKind::Comma {
                        self.step();
                    } else {
                        self.consume(TokenKind::ParenR, AstErrorKind::CommaExpected)?;
                        break;
                    }
                }
            }
        }
        let span = self.span_end(start);
        Ok(Expr::call(callee, args, span))
    }


    // ====================
    // = HELPER FUNCTIONS =
    // ====================

    fn consume(&mut self, token: TokenKind, error: AstErrorKind) -> AstResult<()> {
        if self.curr() == &token {
            self.step();
            Ok(())
        } else {
            self.error(error)
        }
    }

    fn curr_clone(&self) -> Token {
        self.tokens[self.current].clone()
    }

    fn curr(&self) -> &TokenKind {
        if let Some(token) = self.tokens.get(self.current) {
            &token.token
        } else {
            &TokenKind::EOF
        }
    }

    fn span_curr(&self) -> Span {
        self.tokens[self.current].span
    }

    fn span_start(&self) -> usize {
        self.tokens[self.current].span.start
    }

    fn span_end(&self, start: usize) -> Span {
        assert!(self.current > 0, "span_end called before consuming tokens!");
        Span::new(start, self.tokens[self.current - 1].span.end)
    }

    fn step(&mut self) {
        self.current += 1;
    }

    fn error<T>(&mut self, kind: AstErrorKind) -> AstResult<T> {
        let position = match self.tokens.get(self.current) {
            Some(token) => token.span.start,
            _ => self.tokens[self.tokens.len() - 1].span.end,
        };
        self.skip_until_semicolon();
        Err(AstError::new(
            self.file.clone(), 
            kind,
            position
        ))
    }

    fn skip_until_semicolon(&mut self) {
        loop {
            match self.curr() {
                TokenKind::SemiColon => {
                    self.step();
                    return;
                },
                TokenKind::EOF => return,
                _ => { self.step(); }
            }
        }
    }
}
