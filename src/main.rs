#![allow(warnings)]

use crate::{
    args::RunMode,
    ast::AstModule,
    symbol_resolver::{ModuleUID, SymbolTable},
    utils::{FileMeta, join_relative},
};
mod args;
mod ast;
//mod codegenllvm;
mod codegenqbe;
mod lexer;
mod symbol_resolver;
mod typecheck;
mod utils;

#[cfg(test)]
mod tests;

use std::collections::HashMap;

const ENTRY: &'static str = "main.ib";

fn main() {
    let args = args::parse_args();

    match args.mode {
        args::RunMode::Help => args::print_help(),
        args::RunMode::Compile => mode_compile(args),
        args::RunMode::Run => mode_compile(args),
        args::RunMode::Repl => mode_repl(args),
    }
}

fn mode_compile(args: args::CompilerArgs) {
    let mut symbol_table = symbol_resolver::symbol_table();

    let (main, ast_modules, metas) = run_recurive_parsing(ENTRY, &args, &mut symbol_table);
    let main_filename = format!("./{}", ast_modules.get(&main).unwrap().module_name());

    let modules = typecheck::run_typechecker(
        &mut symbol_table,
        &ast_modules,
        &metas,
        args.print_typecheck,
    );

    let mut filenames = codegenqbe::run_codegen_all(&symbol_table, modules, metas, &args);
    codegenqbe::compile_modules(&main_filename, filenames);

    if args.mode == RunMode::Run {
        run_executable(&main_filename)
    }
}

pub fn run_recurive_parsing(
    entry: &str,
    args: &args::CompilerArgs,
    symbol_table: &mut SymbolTable,
) -> (
    ModuleUID,
    HashMap<ModuleUID, AstModule>,
    HashMap<ModuleUID, FileMeta>,
) {
    let mut ast_modules = HashMap::new();
    let mut metas = HashMap::new();
    let mut main_module = 0;

    let mut modules_to_compile = std::collections::VecDeque::from([entry.to_string()]);
    let mut module_names = std::collections::HashSet::new();
    let mut module_dependencies = std::collections::HashMap::new();

    while let Some(source) = modules_to_compile.pop_front() {
        println!("Compiling {source}...");

        let (tokens, meta) = lexer::run_lexer(&source);
        if args.print_lexer {
            lexer::print_tokens(&tokens);
        }

        let module = ast::run_parser(tokens, &meta);
        if args.print_ast {
            ast::print_module(&module);
        }
        let mut imports = Vec::with_capacity(module.imports.len());
        for import in &module.imports {
            let mut import_path = join_relative(&source, &import.module);
            import_path.set_extension("ib");
            let import_path = import_path.to_str().unwrap().to_string();

            if !module_names.contains(&import_path) && !modules_to_compile.contains(&import_path) {
                modules_to_compile.push_back(import_path.clone());
            }

            let import_path = import_path.replace("/", "_");
            imports.push((import_path, import.alias.clone()));
        }
        let module_id = symbol_resolver::resolve_module(symbol_table, &module);
        if source == entry {
            main_module = module_id;
        }
        module_dependencies.insert(module_id, imports);
        module_names.insert(source);
        ast_modules.insert(module_id, module);
        metas.insert(module_id, meta);
    }

    for (module_id, imports) in module_dependencies {
        symbol_table.add_imports(module_id, imports);
    }

    (main_module, ast_modules, metas)
}

#[allow(dead_code)]
fn mode_repl(_args: args::CompilerArgs) {}

pub fn run_executable(filename: &str) {
    use std::process::Stdio;
    let status = std::process::Command::new(format!("{filename}"))
        .stdin(Stdio::inherit())
        .stdout(Stdio::inherit())
        .stderr(Stdio::inherit())
        .status()
        .expect("Execution failed");
    if !status.success() {
        eprintln!("Process exited with {status}");
    }
}
