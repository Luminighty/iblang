use crate::utils::colors;

#[derive(Default, PartialEq, Eq, Debug)]
pub enum RunMode {
    Help,
    Repl,
    #[default]
    Compile,
    Run,
}

#[derive(Debug)]
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
    pub output: Option<String>,
    pub entry: Option<String>,
}

impl Default for CompilerArgs {
    fn default() -> Self {
        Self {
            mode: RunMode::Compile,
            print_lexer: false,
            print_ast: false,
            print_codegen: false,
            print_typecheck: false,
            verbose: false,
            gcc: String::from("gcc"),
            gcc_args: String::default(),
            config: String::default(),
            output: None,
            entry: None,
        }
    }
}

impl CompilerArgs {
    pub fn should_run_jit(&self) -> bool {
        self.mode == RunMode::Run
    }

    pub fn print(&self) {
        println!("  {}Mode:{} {:?}", colors::GREEN, colors::RESET, self.mode);
        let mut debug_list = Vec::with_capacity(4);
        if self.print_lexer {
            debug_list.push("lexer");
        }
        if self.print_ast {
            debug_list.push("ast");
        }
        if self.print_codegen {
            debug_list.push("codegen");
        }
        if self.print_typecheck {
            debug_list.push("typecheck");
        }
        if debug_list.len() > 0 {
            println!(
                "  {}Debug:{} {}",
                colors::GREEN,
                colors::RESET,
                debug_list.join(",")
            );
        }
        println!("  {}CC:{} {}", colors::GREEN, colors::RESET, self.gcc);
        if self.gcc_args.len() > 0 {
            println!(
                "  {}CCFLAGS:{} {}",
                colors::GREEN,
                colors::RESET,
                self.gcc_args
            );
        }
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
        "--out" => compiler_args.output = Some(value.to_owned()),
        "--entry" => compiler_args.entry = Some(value.to_owned()),
        "-cc_flags" => {
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
    println!("Usage: ib");
    println!("  -h  | --help           \tShow this help menu.");
    println!("  -e  | --exec           \tCompile and Execute.");
    println!("  -v  | --verbose        \tVerbose compilation logging");
    println!("  -pl | --print-lexer    \tPrint tokenizer result to stdout.");
    println!("  -pa | --print-ast      \tPrint AST modules to stdout.");
    println!("  -pt | --print-typecheck\tPrint Typechecker logs to stdout.");
    println!("  -pc | --print-codegen  \tPrint Codegen result to stderr.");
    println!("  -cc=gcc             \tC compiler to use when linking.");
    println!("  -cc_flags=-lraylib  \tFlags to pass to compiler when linking");
    println!("  -out=./bin/main     \tExecutable file");
    println!("  -entry=./src/main   \tEntry file");
    println!();
}
