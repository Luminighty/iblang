use std::collections::VecDeque;

mod symbol;
mod table;

pub use symbol::{DeepInfo, ShallowInfo, Symbol, SymbolKind, SymbolStage, SymbolUID};
pub use table::{ModuleUID, SymbolTable};

use crate::ast::AstModule;

pub fn symbol_table<'a>() -> SymbolTable<'a> {
    return SymbolTable::new();
}

pub fn resolve_module<'a>(symbols: &mut SymbolTable<'a>, ast: &'a AstModule) {
    let module_id = symbols.insert_module(ast.name.clone());

    for value in &ast.externs {
        let uid = symbols.insert(
            module_id,
            value.prototype.identifier.clone(),
            SymbolKind::Function,
        );
        symbols.attach_shallow(&uid, ShallowInfo::Function(&value.prototype))
    }

    for value in &ast.functions {
        let uid = symbols.insert(
            module_id,
            value.prototype.identifier.clone(),
            SymbolKind::Function,
        );
        symbols.attach_shallow(&uid, ShallowInfo::Function(&value.prototype))
    }

    for value in &ast.globals {
        let uid = symbols.insert(module_id, value.name.clone(), SymbolKind::Global);
        symbols.attach_shallow(&uid, ShallowInfo::Global(value))
    }

    for value in &ast.extern_globals {
        let uid = symbols.insert(module_id, value.name.clone(), SymbolKind::Global);
        symbols.attach_shallow(&uid, ShallowInfo::ExternGlobal(value))
    }

    for value in &ast.structs {
        let uid = symbols.insert(module_id, value.identifier.clone(), SymbolKind::Struct);
        symbols.attach_shallow(&uid, ShallowInfo::Struct(value))
    }
}
