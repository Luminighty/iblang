#[derive(Default, PartialEq, Eq)]
pub enum RunMode {
    Help,
    Repl,
    #[default]
    Compile,
    Run,
}

#[derive(Default)]
pub struct CompilerArgs {
    pub mode: RunMode,
    pub print_lexer: bool,
    pub print_ast: bool,
    pub print_codegen: bool,
    pub print_typecheck: bool,
}

impl CompilerArgs {
    pub fn should_run_jit(&self) -> bool {
        self.mode == RunMode::Run
    }
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
        "--print-lexer" | "-pl" => {
            compiler_args.print_lexer = true;
        }
        "--print-ast" | "-pa" => {
            compiler_args.print_ast = true;
        }
        "--print-codegen" | "-pc" => {
            compiler_args.print_codegen = true;
        }
        "--print-typecheck" | "-pt" => {
            compiler_args.print_typecheck = true;
        }
        _ => {}
    }
}

impl RunMode {
    fn from_str(s: &str) -> Option<Self> {
        match s {
            "--help" | "-h" => Some(RunMode::Help),
            "--repl" | "-r" => Some(RunMode::Repl),
            "--exec" | "-e" => Some(RunMode::Run),
            _ => None,
        }
    }
}

pub fn print_help() {
    println!("Usage: ib {{source.ib}}");
    println!("  -h  | --help         \tShow this help menu.");
    println!("  -r  | --repl         \tRead, Evaluate, Print and Loop mode");
    println!("  -e  | --exec         \tCompile and Execute JIT");
    println!("  -pl | --print-lexer  \tPrint tokenizer result to stdout.");
    println!("  -pa | --print-ast    \tPrint AST modules to stdout.");
    println!("  -pc | --print-codegen\tPrint Codegen result to stderr.");
    println!("  -pt | --print-typecheck\tPrint Codegen result to stderr.");
    println!();
}
