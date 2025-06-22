use crate::{
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
    InvalidReturnStatement { expected: FlowType, got: FlowType },
    UndefinedVariable { var: String },
}

impl From<QbeError> for CompilerError {
    fn from(value: QbeError) -> Self {
        Self::QbeError(value)
    }
}
