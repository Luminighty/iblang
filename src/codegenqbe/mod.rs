use std::{
    collections::HashMap,
    fs::{File, OpenOptions},
    path::PathBuf,
    process::Command,
};

use compiler::CompilerContext;
use error::CompilerError;
use func::compile_func;
use qbe::Qbe;
use strcts::compile_struct_def;

use crate::codegenqbe::global::compile_global;
use crate::symbol_resolver::{ModuleUID, SymbolTable};
use crate::utils::colors;
use crate::{args::CompilerArgs, typecheck::module::Module, utils::FileMeta};

pub type CompilerResult<T> = Result<T, error::CompilerError>;

mod array;
mod binary;
mod bindings;
mod compiler;
mod error;
mod expr;
mod func;
mod global;
mod literal;
mod qbe;
mod statement;
mod strcts;
mod unary;
mod unions;

pub fn compile_module(
    context: &mut CompilerContext,
    module: &Module,
) -> Result<(), Vec<CompilerError>> {
    context.bindings.start_block();
    let mut errors = Vec::new();
    for strct in &module.struct_defs {
        match compile_struct_def(context, module, strct) {
            Ok(_) => {}
            Err(err) => {
                errors.push(err);
            }
        }
    }
    // NOTE: Externs have to be first, to force the global names
    // for extrn in &module.externs {
    //     compile_proto(context, &extrn.prototype, true);
    // }
    // for extrn in &module.extern_globals {
    //     compile_extern_global(context, &extrn);
    // }
    for global in &module.globals {
        match compile_global(context, module, &global) {
            Ok(_) => {}
            Err(err) => {
                errors.push(err);
            }
        }
    }
    // for func in &module.functions {
    //     compile_proto(context, &func.prototype, false);
    // }
    for func in &module.functions {
        match compile_func(context, module, func) {
            Ok(_) => {}
            Err(err) => {
                errors.push(err);
            }
        }
    }
    context.bindings.start_block();
    if errors.len() > 0 {
        Err(errors)
    } else {
        Ok(())
    }
}

pub fn open_ssa_file(name: &str) -> (PathBuf, File) {
    let _ = std::fs::create_dir_all("./build");
    let filename = PathBuf::from(format!("./build/{name}.ssa"));

    let _ = std::fs::remove_file(&filename);
    let file = OpenOptions::new()
        .write(true)
        .create(true)
        .open(&filename)
        .unwrap();
    (filename, file)
}

pub fn run(module: &Module, symbol_table: &SymbolTable, args: &CompilerArgs) -> PathBuf {
    let (filename, file) = open_ssa_file(&module.name);
    let qbe = Qbe::new(file);
    let mut context = CompilerContext::new(qbe, symbol_table, true);
    if args.verbose {
        println!(
            "{}    QBE Codegen{} -> {}",
            colors::GREEN,
            colors::RESET,
            filename.display(),
        );
    }

    compile_module(&mut context, module).unwrap();
    filename
}

pub fn run_codegen(
    module: &Module,
    symbol_table: &SymbolTable,
    _meta: &FileMeta,
    args: &CompilerArgs,
) -> PathBuf {
    let filename = run(module, symbol_table, args);

    if args.print_codegen {
        print_module(&filename);
    }
    return filename;
}

pub fn run_codegen_all(
    symbol_table: &SymbolTable,
    modules: HashMap<ModuleUID, Module>,
    metas: HashMap<ModuleUID, FileMeta>,
    args: &CompilerArgs,
) -> Vec<PathBuf> {
    let mut filenames = Vec::with_capacity(modules.len());
    for (id, module) in &modules {
        let file = run_codegen(&module, &symbol_table, &metas[id], &args);
        filenames.push(file);
    }
    filenames
}

fn print_module(filename: &PathBuf) {
    let content = std::fs::read_to_string(filename).unwrap();
    println!("{content}");
}

fn run_command(mut command: Command, invoke_err: &str, print_cmd: bool) -> Result<(), String> {
    let command_str = format!("{:?}", command).replace("\"", "");
    if print_cmd {
        println!("{}", command_str);
    }
    let out = command.output().expect(invoke_err);
    if !out.status.success() {
        Err(String::from_utf8_lossy(&out.stderr).to_string())
    } else {
        Ok(())
    }
}

pub fn exec_qbe(filename: &PathBuf, args: &CompilerArgs) -> Result<(), String> {
    let ssa_file = filename.with_extension("ssa").display().to_string();
    let s_file = filename.with_extension("s").display().to_string();
    let mut cmd = Command::new("qbe");
    cmd.arg(ssa_file).arg("-o").arg(s_file);
    if args.verbose {
        print!("{}    QBE {}", colors::GREEN, colors::RESET);
    }
    run_command(cmd, "QBE invocation failed", args.verbose)
}

pub fn exec_cc_comp(filename: &PathBuf, args: &CompilerArgs) -> Result<(), String> {
    let s_file = filename.with_extension("s").display().to_string();
    let o_file = filename.with_extension("o").display().to_string();
    let mut cmd = Command::new("gcc");
    if args.verbose {
        print!("{}    CC  {}", colors::GREEN, colors::RESET);
    }
    cmd.arg(format!("{s_file}"))
        .arg("-g")
        .arg("-c")
        .arg("-o")
        .arg(format!("{o_file}"));
    run_command(cmd, "GCC invocation failed", args.verbose)
}

pub fn exec_cc_link(
    executable: &str,
    obj_files: Vec<PathBuf>,
    args: &CompilerArgs,
) -> Result<(), String> {
    let obj_files = obj_files
        .into_iter()
        .map(|file| file.with_extension("o").display().to_string())
        .collect::<Vec<String>>();
    let mut cmd = Command::new(&args.gcc);
    cmd.args(obj_files)
        .args(args.gcc_args.trim().split(" "))
        .arg("-o")
        .arg(executable);
    if args.verbose {
        print!("  {}Linking {}", colors::GREEN, colors::RESET);
    }
    run_command(cmd, "GCC Linker invocation failed", args.verbose)
}

#[allow(unused)]
pub fn exec_file(filename: &str) -> Result<String, (String, String)> {
    let res = Command::new(format!("./{filename}"))
        .output()
        .expect("Execution failed");
    if !res.status.success() {
        Err((
            String::from_utf8_lossy(&res.stdout).to_string(),
            String::from_utf8_lossy(&res.stderr).to_string(),
        ))
    } else {
        Ok(String::from_utf8_lossy(&res.stdout).to_string())
    }
}

pub fn compile_modules(executable: &str, filenames: Vec<PathBuf>, args: &CompilerArgs) {
    let mut had_error = false;
    for filename in &filenames {
        match exec_qbe(&filename, args) {
            Err(err) => {
                had_error = true;
                eprintln!("qbe error: {err}");
            }
            _ => {}
        }
        match exec_cc_comp(&filename, args) {
            Err(err) => {
                had_error = true;
                eprintln!("cc error: {err}");
            }
            _ => {}
        }
    }
    if had_error {
        panic!("Failed to compile modules.");
    }
    match exec_cc_link(executable, filenames, args) {
        Err(err) => {
            panic!("linker error: {err}");
        }
        _ => {}
    }
}
