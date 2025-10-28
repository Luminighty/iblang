use crate::ast::Identifier;
use crate::symbol_resolver::{ModuleUID, SymbolKind};

#[derive(Debug, Clone)]
pub enum SymbolError {
    SymbolNotFound(Identifier),
    MultipleSymbolFound(Identifier, Vec<ModuleUID>),
    SymbolKindNotMatched {
        expected: SymbolKind,
        got: SymbolKind,
    },
    ShallowInfoMissing,
    DeepInfoMissing,
}
