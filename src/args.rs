#[derive(Default)]
pub enum RunMode {
    Help,
    Repl,
    #[default]
    Compile,
}

impl RunMode {
    fn from_str(s: &str) -> Option<Self> {
        match s {
            "--help" | "-h" => Some(RunMode::Help),
            "--repl" | "-r" => Some(RunMode::Repl),
            _ => None,
        }
    }
}

#[derive(Default)]
pub struct CompilerArgs {
    pub mode: RunMode,
    pub print_lexer: bool,
    pub print_ast: bool,
}


pub fn parse_args() -> CompilerArgs {
    let mut compiler_args = CompilerArgs::default();

    for arg in std::env::args() {
        let arg = arg.to_lowercase();
        let arg: &str = arg.as_str();
        if let Some(mode) = RunMode::from_str(arg) {
            compiler_args.mode = mode;
            continue;
        }

        parse_flags(&mut compiler_args, arg);
    }

    compiler_args
}

fn parse_flags(compiler_args: &mut CompilerArgs, arg: &str) {
    match arg {
        "--debug-lexer" | "-dl" => { compiler_args.print_lexer = true; }
        "--debug-ast" | "-da" => { compiler_args.print_ast = true; }
        _ => {}
    }
}


pub fn print_help() {
    println!("Usage: ib {{source.ib}}");
    println!("  -h  | --help       \tShow this help menu.");
    println!("  -r  | --repl       \tRead, Evaluate, Print and Loop mode");
    println!("  -dl | --debug-lexer\tPrint tokenizer result to stdout.");
    println!("  -da | --debug-ast  \tPrint AST modules to stdout.");
    println!();
}
