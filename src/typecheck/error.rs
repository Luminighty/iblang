use crate::{
    ast::prelude::*,
    symbol_resolver::{SymbolError, SymbolUID},
    typecheck::{FlowType, TypeIdent, const_eval::ConstEvalError},
    utils::{FileMeta, Span},
};

#[derive(Debug)]
pub struct TypecheckError {
    kind: TypecheckErrorKind,
    span: Span,
}

#[derive(Debug)]
#[allow(dead_code)]
pub enum TypecheckErrorKind {
    BlockErrors(Vec<TypecheckError>),
    ValueExpected,
    ReferenceExpected,
    IdentifierExpected,
    ConstEvalError(ConstEvalError),
    UndeclaredVariable(Identifier),
    UndefinedFunction(Identifier),
    SymbolError(SymbolError),
    BinaryTypeMismatch {
        op: BinaryOp,
        lhs: TypeIdent,
        rhs: TypeIdent,
    },
    UnaryTypeMismatch {
        op: UnaryArith,
        value: TypeIdent,
    },
    InvalidCast {
        into: TypeIdent,
        from: TypeIdent,
    },
    InvalidReturnStatement {
        expected: FlowType,
        got: FlowType,
    },
    InvalidReturnTypeArray,
    InvalidConst,
    InvalidArrayLength(i64),
    ReturnInGlobalContext,
    InvalidArrayElementType {
        expected: TypeIdent,
        got: TypeIdent,
    },
    EmptyArrayWithoutType,
    GotArrayElementWithoutValue {
        got: FlowType,
    },
    TargetTypeWasNotArray,
    InvalidIndex,
    DereffedAtomic,
    InvalidFunctionArgCount,
    BreakOutsideLoop,
    ContinueOutsideLoop,
    DereffedNonReference,
    UndefinedTypeIdent,
    AssignmentToArray,
    InvalidArrayInitialization,
    AssignmentWithArrayInitializer,
    CircularTypeDependency {
        cycle: Vec<SymbolUID>,
    },
    UndefinedStruct {
        ty: String,
    },
    MissingStructField {
        field: String,
    },
    UnknownStructField {
        field: String,
    },
    StructExpected {
        got: TypeIdent,
    },
    StructInvalidField {
        strct: TypeIdent,
        field: Identifier,
    },
    DuplicateTypeDef,
    RValueUsedInLValueContext,
}

impl TypecheckError {
    pub fn new(kind: TypecheckErrorKind, span: Span) -> Self {
        Self { kind, span }
    }

    pub fn write(&self, f: &mut dyn std::io::Write, meta: &FileMeta) -> std::io::Result<()> {
        if let TypecheckErrorKind::BlockErrors(errors) = &self.kind {
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
        if let Some(content) = meta
            .file
            .as_ref()
            .map(|file| std::fs::read_to_string(file).ok())
            .flatten()
        {
            position.write_line_pointer(f, &content)?;
        }
        writeln!(f)
    }
}

impl TypecheckErrorKind {
    pub fn write_head(&self, f: &mut dyn std::io::Write, _meta: &FileMeta) -> std::io::Result<()> {
        match self {
            TypecheckErrorKind::BinaryTypeMismatch { op, lhs, rhs } => {
                writeln!(f, "Operation \"{lhs} {op} {rhs}\" is not defined.")
            }
            TypecheckErrorKind::UnaryTypeMismatch { op, value } => {
                writeln!(f, "Operation \"{op}{value}\" is not defined.")
            }
            TypecheckErrorKind::InvalidCast {
                into: target,
                from: value,
            } => writeln!(
                f,
                "Mismatched types. Expected \"{target}\", got \"{value}\"."
            ),
            TypecheckErrorKind::UndeclaredVariable(var) => {
                writeln!(f, "Undeclared variable \"{var}\".")
            }
            TypecheckErrorKind::UndefinedFunction(func) => {
                writeln!(f, "Undeclared function \"{func}\".")
            }
            TypecheckErrorKind::ValueExpected => writeln!(f, "Expression did not return a value."),
            TypecheckErrorKind::InvalidReturnStatement { expected, got } => writeln!(
                f,
                "Invalid return statement. Expected \"{expected}\", but got \"{got}\"."
            ),
            _ => writeln!(f, "{:?}", self),
        }
    }
}
