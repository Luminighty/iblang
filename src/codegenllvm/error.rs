use crate::{ast::prelude::*, typecheck::{FlowType, TypeIdent}, utils::{FileMeta, Span}};


#[derive(Debug)]
pub struct CompilerError {
    kind: CompilerErrorKind,
    span: Span,
}


#[derive(Debug)]
pub enum CompilerErrorKind {
    BlockErrors(Vec<CompilerError>),
    ValueExpected,
    IdentifierExpected,
    UndeclaredVariable(Identifier),
    UndefinedFunction(Identifier),
    BinaryTypeMismatch {
        op: BinaryOp, lhs: TypeIdent, rhs: TypeIdent
    },
    UnaryTypeMismatch { op: UnaryOp, value: TypeIdent},
    AssignmentTypeMismatch { target: TypeIdent, value: TypeIdent },
    InvalidReturnStatement { expected: FlowType, got: FlowType },
    InvalidCast { from: TypeIdent, into: TypeIdent},
}

impl CompilerError {
    pub fn new(kind: CompilerErrorKind, span: Span) -> Self {
        Self { kind, span, }
    }

    pub fn write(&self, f: &mut dyn std::io::Write, meta: &FileMeta) -> std::io::Result<()> {
        if let CompilerErrorKind::BlockErrors(errors) = &self.kind {
            for error in errors {
                error.write(f, meta)?;
            }
            return Ok(());
        }

        let position = meta.span_meta(&self.span);

        write!(f, "Compiler Error: ")?;
        self.kind.write_head(f, meta)?;
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

impl CompilerErrorKind {
    pub fn write_head(&self, f: &mut dyn std::io::Write, _meta: &FileMeta) -> std::io::Result<()> {
        match self {
            CompilerErrorKind::BinaryTypeMismatch{op, lhs, rhs} =>
                writeln!(f, "Operation \"{lhs} {op} {rhs}\" is not defined."),
            CompilerErrorKind::UnaryTypeMismatch{op, value} =>
                writeln!(f, "Operation \"{op}{value}\" is not defined."),
            CompilerErrorKind::AssignmentTypeMismatch{target, value} =>
                writeln!(f, "Mismatched types. Expected \"{target}\", got \"{value}\"."),
            CompilerErrorKind::UndeclaredVariable(var) =>
                writeln!(f, "Undeclared variable \"{var}\"."),
            CompilerErrorKind::UndefinedFunction(func) =>
                writeln!(f, "Undeclared function \"{func}\"."),
            CompilerErrorKind::ValueExpected =>
                writeln!(f, "Expression did not return a value."),
            CompilerErrorKind::InvalidReturnStatement { expected, got } =>
                writeln!(f, "Invalid return statement. Expected \"{expected}\", but got \"{got}\"."),
            _ => writeln!(f, "{:?}", self),
        }
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

