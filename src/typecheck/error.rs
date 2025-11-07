use crate::{
    ast::prelude::*,
    symbol_resolver::{ModuleUID, SymbolError, SymbolTable, SymbolUID},
    typecheck::{
        FlowType, TypeIdent,
        const_eval::{ConstEvalError, ConstExpr},
    },
    utils::{FileMeta, Span},
};

#[derive(Debug, Clone)]
pub struct TypecheckError {
    kind: TypecheckErrorKind,
    pub module: ModuleUID,
    span: Span,
}

impl TypecheckError {
    pub fn unwrap_symbol_error(&self) -> &SymbolError {
        match &self.kind {
            TypecheckErrorKind::SymbolError(err) => err,
            _ => panic!("Expected SymbolError, got {:?}", self.kind),
        }
    }
}

#[derive(Debug, Clone)]
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
    InvalidPathElement,
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
    TypeCannotBeIndexed {
        ty: TypeIdent,
    },
    DereffedAtomic,
    InvalidFunctionArgCount,
    BreakOutsideLoop,
    ContinueOutsideLoop,
    DuplicateEnumVariant {
        variant: String,
    },
    InvalidEnumValue {
        variant: String,
        value: ConstExpr,
    },
    EnumVariantNotFound {
        variant: String,
    },
    DereffedNonReference,
    UndefinedTypeIdent,
    AssignmentToArray,
    AssignmentToConst,
    InvalidArrayInitialization,
    AssignmentWithArrayInitializer,
    InvalidPath,
    CircularTypeDependency {
        cycle: Vec<SymbolUID>,
    },
    UndefinedStruct {
        ty: String,
    },
    DuplicateStructField {
        field: String,
    },
    MissingStructField {
        field: String,
    },
    MultipleFieldForUnionInit,
    UnknownUnionField {
        field: String,
    },
    UnknownStructField {
        field: String,
    },
    ObjectExpected {
        got: TypeIdent,
    },
    EnumSymbolExpected {
        got: SymbolUID,
    },
    InvalidMatchValue {
        got: TypeIdent,
    },
    MissingDefaultCase,
    MultipleDefaultCase,
    DuplicatedCase {
        prev: Literal,
        next: Literal,
    },
    UnionInvalidField {
        union: TypeIdent,
        field: Identifier,
    },
    StructInvalidField {
        strct: TypeIdent,
        field: Identifier,
    },
    DuplicateTypeDef,
    RValueUsedInLValueContext,
}

impl TypecheckError {
    pub fn new(kind: TypecheckErrorKind, module: ModuleUID, span: Span) -> Self {
        Self { kind, span, module }
    }

    pub fn write(
        &self,
        f: &mut dyn std::io::Write,
        symbols: &SymbolTable,
        meta: &FileMeta,
    ) -> std::io::Result<()> {
        if let TypecheckErrorKind::BlockErrors(errors) = &self.kind {
            for error in errors {
                error.write(f, symbols, meta)?;
            }
            return Ok(());
        }

        let position = meta.span_meta(&self.span);

        write!(f, "Compiler Error: ")?;
        self.kind.write_head(f, symbols, meta)?;
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
    pub fn write_head(
        &self,
        f: &mut dyn std::io::Write,
        symbols: &SymbolTable,
        _meta: &FileMeta,
    ) -> std::io::Result<()> {
        match self {
            TypecheckErrorKind::SymbolError(SymbolError::SymbolKindNotMatched {
                expected,
                got,
                symbol,
            }) => {
                let name = &symbols.get_symbol(symbol).unwrap().name;
                writeln!(
                    f,
                    "SymbolKind of \"{name}\" does not match expected {expected:?}, but got {got:?}."
                )
            }
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
