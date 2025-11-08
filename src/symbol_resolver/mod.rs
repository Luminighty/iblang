mod error;
mod symbol;
mod table;

pub use error::SymbolError;
pub use symbol::{DeepInfo, ShallowInfo, Symbol, SymbolKind, SymbolStage, SymbolUID};
pub use table::{ModuleUID, PathResolveResult, SymbolTable};

use crate::ast::AstModule;

pub fn symbol_table() -> SymbolTable {
    return SymbolTable::new();
}

pub fn resolve_module(symbols: &mut SymbolTable, ast: &AstModule) -> ModuleUID {
    let module_id = symbols.insert_module(ast.name.clone());

    for value in &ast.externs {
        let uid = symbols.insert(
            module_id,
            value.prototype.identifier.clone(),
            value.is_public,
            SymbolKind::Function,
        );
        symbols.attach_shallow(&uid, ShallowInfo::Function(value.prototype.clone()));
        symbols.set_extern(&uid);
    }

    for value in &ast.functions {
        let uid = symbols.insert(
            module_id,
            value.prototype.identifier.clone(),
            value.is_public,
            SymbolKind::Function,
        );
        symbols.attach_shallow(&uid, ShallowInfo::Function(value.prototype.clone()));
    }

    for value in &ast.globals {
        let uid = symbols.insert(
            module_id,
            value.name.clone(),
            value.is_public,
            SymbolKind::Global,
        );
        symbols.attach_shallow(&uid, ShallowInfo::Global(value.clone()));
    }

    for value in &ast.extern_globals {
        let uid = symbols.insert(
            module_id,
            value.name.clone(),
            value.is_public,
            SymbolKind::Global,
        );
        symbols.attach_shallow(&uid, ShallowInfo::ExternGlobal(value.clone()));
        symbols.set_extern(&uid);
    }

    for value in &ast.structs {
        let uid = symbols.insert(
            module_id,
            value.identifier.clone(),
            value.is_public,
            SymbolKind::Struct,
        );
        symbols.attach_shallow(&uid, ShallowInfo::Struct(value.clone()));
    }

    for value in &ast.unions {
        let uid = symbols.insert(
            module_id,
            value.identifier.clone(),
            value.is_public,
            SymbolKind::Union,
        );
        symbols.attach_shallow(&uid, ShallowInfo::Union(value.clone()));
    }

    for value in &ast.enums {
        let uid = symbols.insert(
            module_id,
            value.identifier.clone(),
            value.is_public,
            SymbolKind::Enum,
        );
        symbols.attach_shallow(&uid, ShallowInfo::Enum(value.clone()));
    }
    module_id
}
