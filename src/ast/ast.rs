use crate::{lexer::{token::TokenKind, Token}, Span};

use super::{declaration::Declaration, error::{AstError, AstErrorKind}, expr::Expr, function::{Extern, Function, Prototype}, statement::Statement, Identifier};

pub struct Ast {
    tokens: Vec<Token>,
    current: usize,
}

type AstResult<T> = Result<T, AstError>;

impl Ast {
    pub fn new(tokens: Vec<Token>) -> Self {
        Self { tokens, current: 0 }
    }

    pub fn next(&mut self) -> AstResult<Declaration> {
        self.declaration()
    }

    fn declaration(&mut self) -> AstResult<Declaration> {
        match self.curr() {
            TokenKind::Fn => self.parse_function(),
            TokenKind::Extern => self.parse_extern(),
            TokenKind::EOF => Ok(Declaration::None),
            _ => self.error(AstErrorKind::UnknownDeclaration(self.curr_clone())),
        }
    }

    fn parse_extern(&mut self) -> AstResult<Declaration> {
        let start = self.span_start();

        let proto = self.parse_prototype()?;

        let span = self.span_end(start);
        Ok(Declaration::Extern {
            ext: Extern::new(proto),
            span,
        })
    }

    fn parse_function(&mut self) -> AstResult<Declaration> {
        let start = self.span_start();

        let proto = self.parse_prototype()?;
        let body = self.parse_block()?;

        let span = self.span_end(start);
        Ok(Declaration::Function {
            function: Function::new(proto, body),
            span,
        })
    }

    fn parse_prototype(&mut self) -> AstResult<Prototype> {
        let ident = self.identifier(AstErrorKind::InvalidPrototype)?;
        self.consume(TokenKind::ParenL, AstErrorKind::InvalidPrototype)?;
        // Parse args
        self.consume(TokenKind::ParenR, AstErrorKind::InvalidPrototype)?;
        Ok(Prototype::new(ident))
    }

    fn identifier(&mut self, error: AstErrorKind) -> AstResult<Identifier> {
        match self.curr() {
            TokenKind::Ident(ident) => Ok(ident.to_owned()),
            _ => self.error(error),
        }
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
            _ => Ok(Statement::Expr(self.parse_expr()?)),
        }
    }

    fn parse_while(&mut self) -> AstResult<Statement> {
        todo!();
    }

    fn parse_loop(&mut self) -> AstResult<Statement> {
        todo!();
    }

    fn parse_if(&mut self) -> AstResult<Statement> {
        todo!();
    }

    fn parse_return(&mut self) -> AstResult<Statement> {
        todo!();
    }

    fn parse_var_dec(&mut self, mutable: bool) -> AstResult<Statement> {
        let start = self.span_start();
        
        self.step();
        let ident = self.identifier(AstErrorKind::InvalidVarDeclaration)?;
        self.consume(TokenKind::Equal, AstErrorKind::InvalidVarDeclaration)?;
        let value = self.parse_expr()?;
        self.consume(TokenKind::SemiColon, AstErrorKind::InvalidVarDeclaration)?;

        let span = self.span_end(start);
        Ok(Statement::VarDeclaration { mutable, ident, value, span })
    }

    fn parse_block(&mut self) -> AstResult<Statement> {

    }

    fn parse_expr(&mut self) -> AstResult<Expr> {

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

    fn error<T>(&self, kind: AstErrorKind) -> AstResult<T> {
        Err(AstError::new(kind))
    }
}
