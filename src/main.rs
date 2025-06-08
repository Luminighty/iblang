use inkwell::context::Context;

mod args;
mod ast;
mod codegenllvm;
mod lexer;
mod typecheck;
mod utils;

const SOURCE: &'static str = "codegen.ib";

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

    println!("{module:#?}");
    let mut errlock = std::io::stdout();
    for f in &module.functions {
        f.write(&mut errlock, 0).expect("Uh oh.");
    }

    let context = Context::create();
    codegenllvm::run_codegen(&module, &context, &meta, args);
}

#[allow(dead_code)]
fn mode_repl(_args: args::CompilerArgs) {}
