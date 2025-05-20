use crate::lexer::error::LexerErrorKind;

use super::{token::TokenKind, LexerError, Token};

pub type LexerResult<T> = Result<T, LexerError>;


pub struct Lexer {
    content: Vec<char>,
    current: usize,
    pub file: Option<String>,
    pub line_starts: Vec<usize>,
    line: usize,
    column: usize,
    start: usize,
    line_start: usize,
}


impl Lexer {
    pub fn new(content: String, file: Option<String>) -> Self {
        Self {
            content: content.chars().collect(),
            line_starts: Vec::new(),
            current: 0,
            file,
            line: 1,
            column: 1,
            start: 0,
            line_start: 0,
        }
    }

    pub fn next_token(&mut self) -> LexerResult<Token> {
        match self.match_token() {
            Ok(token) => Ok(Token::new(token, self.start, self.current)),
            Err(err) => Err(err)
        }
    }

    fn match_token(&mut self) -> LexerResult<TokenKind> {
        if self.is_end() {
            return self.token(TokenKind::EOF);
        }
        self.comment();
        self.whitespace();

        self.start = self.current;
        use TokenKind::*;
        match self.curr() {
            '\0' => self.token(EOF),
            '(' => self.token(ParenL),
            ')' => self.token(ParenR),
            '{' => self.token(BraceL),
            '}' => self.token(BraceR),
            '[' => self.token(BracketL),
            ']' => self.token(BracketR),
            ',' => self.token(Comma),
            '.' => self.token(Dot),
            '>' => self.if_next('=', GE, GT),
            '<' => self.if_next('=', LE, LT),
            '=' => self.if_next('=', EqEq, Equal),
            '!' => self.if_next('=', BangEqual, Bang),
            ':' => self.if_next(':', ColonColon, Colon),
            '+' => self.token(Plus),
            '-' => self.token(Minus),
            '*' => self.token(Star),
            '/' => self.token(Slash),
            '%' => self.token(Percent),
            '|' => self.if_next('|', Or, Pipe),
            '&' => self.if_next('&', And, Amp),
            ';' => self.token(SemiColon),
            '\'' => self.char(),
            '\"' => self.string(),
            '0'..='9' => self.number(),
            'a'..='z' | 'A'..='Z' | '_' => {
                if let Some(k) = self.keyword() {
                    Ok(k)
                } else {
                    self.identifier()
                }
            }
            _ => Err(self.error(LexerErrorKind::UnexpectedToken))
        }
    }

    fn char(&mut self) -> LexerResult<TokenKind> {
        self.step();
        let c = self.escape_char()?;
        self.consume('\'', LexerErrorKind::UnterminatedChar)?;
        Ok(TokenKind::Char(c))
    }

    fn string(&mut self) -> LexerResult<TokenKind> {
        self.step();
        let mut string = String::new();
        while !['\"', '\0', '\n'].contains(&self.curr()) {
            string.push(self.escape_char()?);
        }
        self.consume('\"', LexerErrorKind::UnterminatedString)?;
        Ok(TokenKind::String(string))
    }

    fn identifier(&mut self) -> LexerResult<TokenKind> {
        loop {
            match self.curr() {
                'a'..='z' | 'A'..='Z' | '0'..='9' | '_' => self.step(),
                _ => break,
            }
        }
        Ok(TokenKind::Ident(self.slice(self.start, self.current)))
    }
    
    fn keyword(&mut self) -> Option<TokenKind> {
        match self.curr() {
            'l' if self.match_str("et") => Some(TokenKind::Let),
            'c' if self.match_str("onst") => Some(TokenKind::Const),
            't' if self.match_str("rue") => Some(TokenKind::True),
            'f' if self.match_str("alse") => Some(TokenKind::False),
            'i' if self.match_str("f") => Some(TokenKind::If),
            'e' if self.match_str("lse") => Some(TokenKind::Else),
            'w' if self.match_str("hile") => Some(TokenKind::While),
            'l' if self.match_str("oop") => Some(TokenKind::Loop),
            'm' if self.match_str("atch") => Some(TokenKind::Match),
            'r' if self.match_str("eturn") => Some(TokenKind::Return),
            'b' if self.match_str("reak") => Some(TokenKind::Break),
            'c' if self.match_str("ontinue") => Some(TokenKind::Continue),
            'f' if self.match_str("n") => Some(TokenKind::Fn),
            'i' if self.match_str("mport") => Some(TokenKind::Import),
            'e' if self.match_str("xtern") => Some(TokenKind::Extern),
            's' if self.match_str("truct") => Some(TokenKind::Struct),
            'e' if self.match_str("num") => Some(TokenKind::Enum),
            _ => None,
        }
    }

    fn match_str(&mut self, rest: &str) -> bool {
        let str = self.slice(self.start + 1, self.current + rest.len() + 1);
        if str == rest {
            self.current += rest.len() + 1;
            true
        } else {
            false
        }
    }

    fn number(&mut self) -> LexerResult<TokenKind> {
        let num = self.decimal_number();
        if self.curr() == '.' {
            self.step();
            let fraction = self.decimal_number();
            return Ok(TokenKind::Float(num, fraction));
        }
        Ok(TokenKind::Number(num))
    }

    fn decimal_number(&mut self) -> i64 {
        let mut num = 0;
        loop {
            let val = match self.curr() {
                '0' => 0,
                '1' => 1,
                '2' => 2,
                '3' => 3,
                '4' => 4,
                '5' => 5,
                '6' => 6,
                '7' => 7,
                '8' => 8,
                '9' => 9,
                _ => break,
            };
            self.step();
            num = num * 10 + val;
        }
        num
    }


    fn escape_char(&mut self) -> LexerResult<char> {
        if self.curr() != '\\' {
            let c = self.curr();
            self.step();
            return Ok(c);
        }
        self.step();
        let c = match self.curr() {
            'n' => '\n',
            't' => '\t',
            'r' => '\r',
            '0' => '\0',
            _ => return Err(self.error(LexerErrorKind::UnknownCharacterEscape)),
        };
        self.step();
        Ok(c)
    }

    fn consume(&mut self, c: char, error: LexerErrorKind) -> LexerResult<()> {
        if self.curr() == c {
            self.step();
            Ok(())
        } else {
            Err(self.error(error))
        }
    }

    fn slice(&mut self, from: usize, to: usize) -> String {
        self.content[from..to.min(self.content.len())]
            .iter().collect()
    }

    fn token(&mut self, token: TokenKind) -> LexerResult<TokenKind> {
        self.step();
        Ok(token)
    }

    fn curr(&self) -> char {
        self.peek(0)
    }

    fn if_next(&mut self, c: char, on_true: TokenKind, on_false: TokenKind) -> LexerResult<TokenKind> {
        self.step();
        if self.curr() == c {
            self.step();
            Ok(on_true)
        } else {
            Ok(on_false)
        }
    }

    fn peek(&self, offset: usize) -> char {
        if let Some(c) = self.content.get(self.current + offset) {
            *c
        } else {
            '\0'
        }
    }

    fn step(&mut self) {
        self.current += 1;
        self.column += 1;
    }

    fn is_end(&mut self) -> bool {
        self.current >= self.content.len()
    }

    fn next_line(&mut self) {
        loop {
            match self.curr() {
                '\0' => { return; }
                '\n' => {
                    self.step();
                    self.line_start = self.current;
                    self.line_starts.push(self.line_start);
                    self.line += 1;
                    self.column = 1;
                    return;
                }
                _ => { self.step(); }
            }
        }
    }

    fn comment(&mut self) {
        loop {
            self.whitespace();
            match self.curr() {
                '/' if self.peek(1) == '/' => self.next_line(),
                '/' if self.peek(1) == '*' => self.block_comment(),
                _ => return
            }
        }
    }

    fn block_comment(&mut self) {
        self.step();
        self.step();
        loop {
            match self.curr() {
                '\0' => return,
                '*' if self.peek(1) == '/' => {
                    self.step();
                    self.step();
                    return
                }
                _ => self.step(),
            }
        }
    }

    fn whitespace(&mut self) {
        loop {
            match self.curr() {
                ' ' | '\t' | '\r' => self.step(),
                '\n' => self.next_line(),
                _ => { return; }
            }
        }
    }

    fn error(&mut self, kind: LexerErrorKind) -> LexerError {
        let from = self.line_start;
        let line = self.line;
        let column = self.column;
        self.next_line();
        let content = self.slice(from, self.current);
        LexerError::new(
            kind,
            line,
            column,
            content,
            self.file.clone()
        )
    }
}
