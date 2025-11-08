use crate::utils::colors;

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
        const RED: &str = colors::RED;
        const BLUE: &str = colors::BLUE;
        const RESET: &str = colors::RESET;
        const BOLD: &str = colors::BOLD;
        write!(f, "{RED}Syntax Error:{RESET}{BOLD} ",)?;
        writeln!(f, "{:?}{RESET}", self.kind)?;
        if let Some(file) = &self.file {
            write!(f, "   ---> {}:", file)?;
        }
        writeln!(f, "{}:{}", self.line, self.column)?;
        let padleft_len = ((self.line + 1).checked_ilog10().unwrap_or(0) + 2) as usize;
        let padleft = " ".repeat(padleft_len);
        let tabs = self.content.chars().filter(|c| *c == '\t').count();
        let width = self.column + (tabs * 3);
        writeln!(f, "{padleft}{BLUE}|{RESET} ")?;
        write!(
            f,
            "{BLUE}{} |{RESET} {}",
            self.line,
            self.content.replace("\t", "    ")
        )?;
        write!(f, "{padleft}{BLUE}|{RESET} {:>width$}", '^', width = width)?;
        writeln!(f)
    }
}
