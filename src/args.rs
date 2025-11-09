#[derive(Default, PartialEq, Eq, Debug)]
pub enum RunMode {
    Help,
    Repl,
    #[default]
    Compile,
    Run,
}

#[derive(Default, Debug)]
pub struct CompilerArgs {
    pub mode: RunMode,
    pub print_lexer: bool,
    pub print_ast: bool,
    pub print_codegen: bool,
    pub print_typecheck: bool,
    pub verbose: bool,
    pub gcc: String,
    pub gcc_args: String,
    pub config: String,
}

impl CompilerArgs {
    pub fn should_run_jit(&self) -> bool {
        self.mode == RunMode::Run
    }

    pub fn print(&self) {
        println!("{self:?}")
    }
}

pub fn parse_args() -> CompilerArgs {
    let mut compiler_args = CompilerArgs::default();

    for arg in std::env::args() {
        parse_arg(&mut compiler_args, &arg);
    }

    if let Ok(config) = std::fs::read_to_string("./ib.config") {
        for config in config.lines() {
            parse_arg(&mut compiler_args, config.trim());
        }
    }
    compiler_args
}

fn parse_arg(compiler_args: &mut CompilerArgs, arg: &str) {
    let lower_arg = arg.to_lowercase();
    let lower_arg: &str = lower_arg.as_str();
    if let Some(mode) = RunMode::from_str(lower_arg) {
        compiler_args.mode = mode;
        return;
    }

    parse_flags(compiler_args, lower_arg);
    if let Some((key, value)) = arg.split_once('=') {
        parse_keys(compiler_args, key, value);
    }
}

fn parse_keys(compiler_args: &mut CompilerArgs, key: &str, value: &str) {
    let key = key.to_lowercase();
    let key = key.as_str();
    match key {
        "-cc" => compiler_args.gcc = value.to_owned(),
        "-cc_flags" => {
            println!("{:?}", compiler_args.gcc_args);
            compiler_args.gcc_args.push_str(value);
            compiler_args.gcc_args.push(' ');
        }
        _ => {}
    }
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
        "--verbose" | "-v" => {
            compiler_args.verbose = true;
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
    println!("  -v  | --verbose      \tVerbose compilation logging");
    println!("  -pl | --print-lexer  \tPrint tokenizer result to stdout.");
    println!("  -pa | --print-ast    \tPrint AST modules to stdout.");
    println!("  -pc | --print-codegen\tPrint Codegen result to stderr.");
    println!("  -pt | --print-typecheck\tPrint Codegen result to stderr.");
    println!();
}
