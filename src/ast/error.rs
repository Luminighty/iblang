use crate::lexer::Token;

pub struct AstError {
    kind: AstErrorKind
}

pub enum AstErrorKind {
    UnknownDeclaration(Token),
    InvalidPrototype,
    InvalidVarDeclaration,
    IdentifierExpected,
}

impl AstError {
    pub fn new(kind: AstErrorKind) -> Self {
        Self { kind }

    }
}
