use crate::{lexer::{token::TokenKind, Token}, utils::Span};

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
            _ => self.error(AstErrorKind::UnknownDeclaration(self.curr_clone())),
        }
    }

    fn parse_extern(&mut self) -> AstResult<Declaration> {
        let start = self.span_start();

        let proto = self.parse_prototype()?;

        let span = self.span_end(start);
        Ok(Declaration::Extern(Extern::new(proto, span)))
    }

    fn parse_function(&mut self) -> AstResult<Declaration> {
        let start = self.span_start();

        let proto = self.parse_prototype()?;
        let body = self.parse_block()?;

        let span = self.span_end(start);
        Ok(Declaration::Function(Function::new(proto, body, span)))
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

    fn parse_global(&mut self, mutable: bool) -> AstResult<Declaration> {
        let start = self.span_start();
        self.step();
        todo!();
        let span = self.span_end(start);
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
            _ => Ok(Statement::expr(self.parse_expr()?)),
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
                TokenKind::BracketR => break,
                _ => block.push(self.parse_statement()?)
            }
        }

        let span = self.span_end(start);
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
        match self.curr() {
            TokenKind::Number(n) => Ok(Expr::number(*n, start)),
            TokenKind::Ident(ident) => Ok(Expr::ident(ident.clone(), start)),
            token => {
                if let Some(prec) = self.prefix.get(token).cloned() {
                    let start = self.span_start();
                    self.step();
                    let expr = self.parse_expr_prec(prec.new_prec)?;

                    if let Some((token, error)) = &prec.suffix {
                        self.consume(token.clone(), error.clone())?;
                    }
                    let span = self.span_end(start);
                    Ok(Expr::unary(prec.op.clone(), Box::new(expr), span))
                } else {
                    self.error(AstErrorKind::UnknownPrimary)
                }
            },
        }
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
        let position = match self.tokens.get(self.current) {
            Some(token) => token.span.start,
            _ => self.tokens[self.tokens.len() - 1].span.end,
        };
        Err(AstError::new(
            self.file.clone(), 
            kind,
            position
        ))
    }
}
