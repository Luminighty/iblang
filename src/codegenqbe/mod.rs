use std::io::Write;
use std::{
    fs::{File, OpenOptions},
    os::unix::process::CommandExt,
    process::Command,
};

use bindings::VariableBinding;
use compiler::CompilerContext;
use error::CompilerError;
use func::{compile_func, compile_proto};
use qbe::Qbe;
use strcts::compile_struct_def;

use crate::codegenqbe::global::{compile_extern_global, compile_global};
use crate::{
    args::{CompilerArgs, RunMode},
    typecheck::{
        TypeIdent,
        atomic::{Atomic, Numeric},
        module::Module,
    },
    utils::FileMeta,
};

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

pub fn compile_module(
    context: &mut CompilerContext,
    module: &Module,
) -> Result<(), Vec<CompilerError>> {
    context.bindings.start_block();
    let stderr = context.qbe.create_temp("stderr");

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
    for extrn in &module.externs {
        compile_proto(context, &extrn.prototype, true);
    }
    for extrn in &module.extern_globals {
        compile_extern_global(context, &extrn);
    }
    for global in &module.globals {
        compile_global(context, module, &global);
    }
    for func in &module.functions {
        compile_proto(context, &func.prototype, false);
    }
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

pub fn open_ssa_file(name: &str) -> (String, File) {
    let _ = std::fs::create_dir_all("./build");
    let filename = format!("./build/{name}.ssa");

    let _ = std::fs::remove_file(&filename);
    let file = OpenOptions::new()
        .write(true)
        .create(true)
        .open(&filename)
        .unwrap();
    (filename, file)
}

pub fn run(module: &Module) -> String {
    let (filename, file) = open_ssa_file(&module.name);
    let qbe = Qbe::new(file);
    let mut context = CompilerContext::new(qbe, true);

    compile_module(&mut context, module).unwrap();
    filename
}

pub fn run_codegen(module: &Module, meta: &FileMeta, args: CompilerArgs) {
    let filename = run(module);

    if args.print_codegen {
        print_module(&filename);
    }
    if args.mode == RunMode::Run {
        execute(&module.name);
    }
}

fn print_module(filename: &str) {
    let content = std::fs::read_to_string(filename).unwrap();
    println!("{content}");
}

pub fn exec_qbe(filename: &str) -> Result<(), String> {
    let qbe = Command::new("qbe")
        .arg(format!("./build/{filename}.ssa"))
        .arg("-o")
        .arg(format!("./build/qbe_{filename}.s"))
        .output()
        .expect("QBE compilation failed");
    if !qbe.status.success() {
        Err(String::from_utf8_lossy(&qbe.stderr).to_string())
    } else {
        Ok(())
    }
}

pub fn exec_cc(filename: &str) -> Result<(), String> {
    let cc = Command::new("cc")
        .arg(format!("./build/qbe_{filename}.s"))
        .arg("-g")
        .arg("-o")
        .arg(format!("./build/{filename}.out"))
        .output()
        .expect("cc failed.");
    if !cc.status.success() {
        Err(String::from_utf8_lossy(&cc.stderr).to_string())
    } else {
        Ok(())
    }
}

pub fn exec_file(filename: &str) -> Result<String, (String, String)> {
    let res = Command::new(format!("./build/{filename}.out"))
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

fn execute(filename: &str) {
    println!("Exec: {filename}");
    match exec_qbe(filename) {
        Err(err) => eprintln!("qbe error: {err}"),
        _ => {}
    }
    match exec_cc(filename) {
        Err(err) => eprintln!("cc error: {err}"),
        _ => {}
    }
    match exec_file(filename) {
        Err((out, err)) => {
            eprintln!("stdout: {out:?}");
            eprintln!("Execution error: {err:?}");
        }
        Ok(str) => println!("{str}"),
    }
}
