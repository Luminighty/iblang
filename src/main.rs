#![allow(warnings)]
mod args;
mod ast;
//mod codegenllvm;
mod codegenqbe;
mod lexer;
mod typecheck;
mod utils;

#[cfg(test)]
mod tests;

const SOURCE: &'static str = "main.ib";

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
    let (tokens, meta) = lexer::run_lexer(SOURCE);
    if args.print_lexer {
        lexer::print_tokens(&tokens);
    }

    let module = ast::run_parser(tokens, &meta);
    if args.print_ast {
        ast::print_module(&module);
    }

    let module = typecheck::run_typechecker(&module, &meta);

    // let context = Context::create();
    // codegenllvm::run_codegen(&module, &context, &meta, args);
    codegenqbe::run_codegen(&module, &meta, args);
}

#[allow(dead_code)]
fn mode_repl(_args: args::CompilerArgs) {}
