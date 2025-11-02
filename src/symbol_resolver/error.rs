use crate::ast::Identifier;
use crate::symbol_resolver::{ModuleUID, SymbolKind, SymbolUID};

#[derive(Debug, Clone)]
pub enum SymbolError {
    SymbolNotFound(Identifier),
    SymbolIsPrivate(Identifier),
    MultipleSymbolFound(Identifier, Vec<ModuleUID>),
    SymbolKindNotMatched {
        expected: SymbolKind,
        got: SymbolKind,
        symbol: SymbolUID,
    },
    ShallowInfoMissing,
    ModuleNotFoundWithPath(Vec<Identifier>),
    DeepInfoMissing,
}
