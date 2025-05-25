use crate::{ast::{BinaryOp, Identifier}, types::TypeIdent, utils::{FileMeta, Span}};


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
    BlockErrors(Vec<CompilerError>),
    BinaryTypeMismatch(BinaryOp, TypeIdent, TypeIdent),
}

impl CompilerError {
    pub fn new(kind: CompilerErrorKind, span: Span) -> Self {
        Self {
            kind,
            span,
        }
    }

    pub fn write(&self, f: &mut dyn std::io::Write, meta: &FileMeta) -> std::io::Result<()> {
        if let CompilerErrorKind::BlockErrors(errors) = &self.kind {
            for error in errors {
                error.write(f, meta)?;
            }
            return Ok(());
        }

        let position = meta.span_meta(&self.span);
        writeln!(f, "Compiler Error: {:?}", self.kind)?;
        write!(f, " ---> ")?;
        if let Some(file) = &meta.file {
            write!(f, "{}:", file)?;
        }
        writeln!(f, "{}:{}", position.line + 1, position.column + 1)?;
        if let Some(content) = meta.file.as_ref().map(|file| std::fs::read_to_string(file).ok()).flatten() {
            position.write_line_pointer(f, &content)?;
        }
        writeln!(f)
    }
}

/* Rust error for reference
error[E0425]: cannot find value `asdf` in this scope
  --> src/codegenllvm/error.rs:47:9
   |
47 |         asdf;
   |         ^^^^ not found in this scope


warning: unused import: `lexer`
 --> src/codegenllvm/mod.rs:4:26
  |
4 | use crate::{ast::Module, lexer, utils::FileMeta};
  |                          ^^^^^
  |
  = note: `#[warn(unused_imports)]` on by default
*/
