use inkwell::context::Context;

mod args;
mod utils;
mod lexer;
mod ast;
mod types;
mod codegenllvm;

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
    let should_run_jit = args.mode == args::RunMode::Run;

    let (tokens, meta) = lexer::run_lexer(SOURCE);
    if args.print_lexer { lexer::print_tokens(&tokens); }

    let module = ast::run_parser(tokens, &meta);
    if args.print_ast { ast::print_module(&module); }

    let context = Context::create();
    codegenllvm::run_codegen(&module, &context, &meta, &args);
}

#[allow(dead_code)]
fn mode_repl(args: args::CompilerArgs) {

}
