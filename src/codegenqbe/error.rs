use crate::{
    codegenqbe::statement::CompiledStatement,
    symbol_resolver::{SymbolError, SymbolUID},
    typecheck::{FlowType, TypeIdent},
    utils::Span,
};

use super::qbe::QbeError;

#[derive(Debug)]
pub enum CompilerError {
    QbeError(QbeError),
    ValueExpected(Span),
    InvalidBaseTyCast(TypeIdent),
    Block(Vec<CompilerError>),
    InvalidReturnStatement {
        expected: FlowType,
        got: FlowType,
        flow: CompiledStatement,
    },
    UndefinedVariable {
        var: String,
    },
    UndefinedGlobal {
        symbol: SymbolUID,
    },
    SymbolError(SymbolError),
}

impl From<QbeError> for CompilerError {
    fn from(value: QbeError) -> Self {
        Self::QbeError(value)
    }
}

impl From<SymbolError> for CompilerError {
    fn from(value: SymbolError) -> Self {
        Self::SymbolError(value)
    }
}
