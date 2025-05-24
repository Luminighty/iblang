use crate::{ast::Identifier, utils::{FileMeta, Span}};


#[derive(Debug)]
pub struct CompilerError {
    kind: CompilerErrorKind,
    span: Span,
}


#[derive(Debug)]
pub enum CompilerErrorKind {
    ValueExpected,
    UndeclaredVariable(Identifier),
    IdentifierExpected,
    UndefinedFunction(Identifier),
    InvalidCall,
}

impl CompilerError {
    pub fn new(kind: CompilerErrorKind, span: Span) -> Self {
        Self {
            kind,
            span,
        }
    }

    pub fn write(&self, f: &mut dyn std::io::Write, meta: &FileMeta) -> std::io::Result<()> {
        write!(f, "Compiler Error: ")?;
        if let Some(file) = &meta.file {
            write!(f, "{}:", file)?;
        }
        let position = meta.span_meta(&self.span);
        writeln!(f, "{}:{} {:?}", position.line + 1, position.column + 1, self.kind)?;
        if let Some(content) = meta.file.as_ref().map(|file| std::fs::read_to_string(file).ok()).flatten() {
            position.write_line_pointer(f, &content)?;
        }
        Ok(())
    }
}
