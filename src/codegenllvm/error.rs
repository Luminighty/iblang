use crate::ast::Identifier;

pub struct CompilerError {
    kind: CompilerErrorKind

}

pub enum CompilerErrorKind {
    UndeclaredVariable(Identifier),
    IdentifierExpected,
    UndefinedFunction(Identifier),
    InvalidCall,
}

impl CompilerError {
    pub fn new(kind: CompilerErrorKind) -> Self {
        Self {
            kind
        }
    }
}
