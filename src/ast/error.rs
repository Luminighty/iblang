use crate::{lexer::Token, span::FileMeta};

pub struct AstError {
    file: Option<String>,
    kind: AstErrorKind,
    position: usize,
}

#[derive(Debug)]
pub enum AstErrorKind {
    UnknownDeclaration(Token),
    InvalidPrototype,
    InvalidVarDeclaration,
    IdentifierExpected,
}

impl AstError {
    pub fn new(file: Option<String>, kind: AstErrorKind, position: usize) -> Self {
        Self { file, kind, position }
    }

    pub fn write(&self, f: &mut std::fmt::Formatter<'_>, meta: &FileMeta) -> std::fmt::Result {
        write!(f, "Parser Error: ")?;
        if let Some(file) = &self.file {
            write!(f, "{}:", file)?;
        }
        let line = meta.find_line(self.position);
        let column = meta.find_column(line, self.position);
        writeln!(f, "{}:{} {:?}", line + 1, column + 1, self.kind);
        if let Some(file) = &self.file {
            self.write_content(f, file, column + 1)?;
        }
        Ok(())
    }

    fn write_content(&self, f: &mut std::fmt::Formatter<'_>, file: &str, column: usize) -> std::fmt::Result {
        if let Ok(content) = std::fs::read_to_string(file) {
            let tabs = content.chars().filter(|c| *c == '\t').count();
            let width = column + (tabs * 3);
            write!(f, "{}", content.replace("\t", "    "))?;
            writeln!(f, "{:>width$}", '^', width = width)
        } else {
            Ok(())
        }
    }

}

