use std::{
    fs::{File, OpenOptions},
    os::unix::process::CommandExt,
    process::Command,
};

use compiler::CompilerContext;
use error::CompilerError;
use func::{compile_func, compile_proto};
use qbe::Qbe;
use strcts::compile_struct_def;

use crate::{
    args::{CompilerArgs, RunMode},
    typecheck::module::Module,
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
mod literal;
mod qbe;
mod statement;
mod strcts;
mod unary;

fn compile_module(
    context: &mut CompilerContext,
    module: &Module,
) -> Result<(), Vec<CompilerError>> {
    let mut errors = Vec::new();
    for strct in &module.struct_defs {
        match compile_struct_def(context, module, strct) {
            Ok(_) => {}
            Err(err) => {
                errors.push(err);
            }
        }
    }
    for extrn in &module.externs {
        compile_proto(context, &extrn.prototype);
    }
    for func in &module.functions {
        compile_proto(context, &func.prototype);
    }
    for func in &module.functions {
        match compile_func(context, module, func) {
            Ok(_) => {}
            Err(err) => {
                errors.push(err);
            }
        }
    }
    if errors.len() > 0 {
        Err(errors)
    } else {
        Ok(())
    }
}

pub fn run_codegen(module: &Module, meta: &FileMeta, args: CompilerArgs) {
    let _ = std::fs::create_dir_all("./build");
    let filename = format!("./build/{}.ssa", module.name);

    let _ = std::fs::remove_file(&filename);
    let file = OpenOptions::new()
        .write(true)
        .create(true)
        .open(&filename)
        .unwrap();
    let qbe = Qbe::new(file);
    let mut context = CompilerContext::new(qbe, true);

    compile_module(&mut context, module).unwrap();

    if args.print_codegen {
        print_module(&filename);
    }
    if args.mode == RunMode::Run {
        execute(&filename);
    }
}

fn print_module(filename: &str) {
    let content = std::fs::read_to_string(filename).unwrap();
    println!("{content}");
}

fn execute(filename: &str) {
    println!("Exec: {filename}");
    let qbe = Command::new("qbe")
        .arg(format!("{filename}"))
        .arg("-o")
        .arg("./build/out.s")
        .output()
        .expect("QBE compilation failed");
    print!("{}", String::from_utf8_lossy(&qbe.stdout));
    if !qbe.status.success() {
        eprintln!("qbe error: {}", String::from_utf8_lossy(&qbe.stderr))
    }
    let cc = Command::new("cc")
        .arg("./build/out.s")
        .arg("-o")
        .arg("./build/a.out")
        .output()
        .expect("cc failed.");
    print!("{}", String::from_utf8_lossy(&cc.stdout));
    if !cc.status.success() {
        eprintln!("cc error: {}", String::from_utf8_lossy(&cc.stderr))
    }
    let res = Command::new("./build/a.out")
        .output()
        .expect("Execution failed");
    print!("{}", String::from_utf8_lossy(&res.stdout));
    if !res.status.success() {
        eprintln!("Execution error: {}", String::from_utf8_lossy(&res.stderr))
    }
}
