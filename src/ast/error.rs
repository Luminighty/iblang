use crate::utils::FileMeta;

#[derive(Debug)]
pub struct AstError {
    file: Option<String>,
    pub kind: AstErrorKind,
    position: usize,
}

#[derive(Debug, Clone)]
pub enum AstErrorKind {
    UnknownDeclaration,
    InvalidPrototype,
    InvalidVarDeclaration,
    UnknownPrimary,
    BlockExpected,
    UnterminatedBlock,
    UnterminatedParen,
    UnterminatedBracket,
    CommaExpected,
    SemicolonExpected,
    TypeIdentExpected,
    InvalidStructDeclaration,
    InvalidStructInitialization,
}

impl AstError {
    pub fn new(file: Option<String>, kind: AstErrorKind, position: usize) -> Self {
        Self {
            file,
            kind,
            position,
        }
    }

    pub fn write(&self, f: &mut dyn std::io::Write, meta: &FileMeta) -> std::io::Result<()> {
        write!(f, "Parser Error: ")?;
        if let Some(file) = &self.file {
            write!(f, "{}:", file)?;
        }
        let position = meta.position_meta(self.position);
        writeln!(
            f,
            "{}:{} {:?}",
            position.line + 1,
            position.column + 1,
            self.kind
        )?;
        if let Some(content) = self
            .file
            .as_ref()
            .map(|file| std::fs::read_to_string(file).ok())
            .flatten()
        {
            position.write_line_pointer(f, &content)?;
        }
        Ok(())
    }
}
