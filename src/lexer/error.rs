#[derive(Debug)]
pub struct LexerError {
    pub line: usize,
    pub column: usize,
    pub content: String,
    pub file: Option<String>,
    pub kind: LexerErrorKind,
}

#[derive(Debug, PartialEq, Eq)]
pub enum LexerErrorKind {
    UnexpectedToken,
    UnterminatedChar,
    UnterminatedString,
    UnknownCharacterEscape,
    UnescapedCharacter(char),
}

impl LexerError {
    pub fn new(
        kind: LexerErrorKind,
        line: usize,
        column: usize,
        content: String,
        file: Option<String>,
    ) -> Self {
        Self {
            kind,
            line,
            column,
            content,
            file,
        }
    }
}

impl std::fmt::Display for LexerError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "Syntax Error: ")?;
        if let Some(file) = &self.file {
            write!(f, "{}:", file)?;
        }
        writeln!(f, "{}:{} {:?}", self.line, self.column, self.kind)?;
        let tabs = self.content.chars().filter(|c| *c == '\t').count();
        let width = self.column + (tabs * 3);
        write!(f, "{}", self.content.replace("\t", "    "))?;
        writeln!(f, "{:>width$}", '^', width = width)
    }
}
