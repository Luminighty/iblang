use std::io::Write;
use std::{
    fs::{File, OpenOptions},
    os::unix::process::CommandExt,
    path::PathBuf,
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

pub fn run(module: &Module) -> PathBuf {
    let (filename, file) = open_ssa_file(&module.name);
    let qbe = Qbe::new(file);
    let mut context = CompilerContext::new(qbe, true);

    compile_module(&mut context, module).unwrap();
    filename
}

pub fn run_codegen(module: &Module, meta: &FileMeta, args: &CompilerArgs) -> PathBuf {
    let filename = run(module);

    if args.print_codegen {
        print_module(&filename);
    }
    return filename;
}

fn print_module(filename: &PathBuf) {
    let content = std::fs::read_to_string(filename).unwrap();
    println!("{content}");
}

pub fn exec_qbe(filename: &PathBuf) -> Result<(), String> {
    println!("qbe {}", filename.display());
    let qbe = Command::new("qbe")
        .arg(format!("{}", filename.with_extension("ssa").display()))
        .arg("-o")
        .arg(format!("{}", filename.with_extension("s").display()))
        .output()
        .expect("QBE compilation failed");
    if !qbe.status.success() {
        Err(String::from_utf8_lossy(&qbe.stderr).to_string())
    } else {
        Ok(())
    }
}

pub fn exec_cc_comp(filename: &PathBuf) -> Result<(), String> {
    let s_file = filename.with_extension("s");
    let s_file = s_file.display();
    let o_file = filename.with_extension("o");
    let o_file = o_file.display();
    println!("gcc {s_file} -o {o_file}");
    let cc = Command::new("gcc")
        .arg(format!("{s_file}"))
        .arg("-g")
        .arg("-c")
        .arg("-o")
        .arg(format!("{o_file}"))
        .output()
        .expect("cc failed.");
    if !cc.status.success() {
        Err(String::from_utf8_lossy(&cc.stderr).to_string())
    } else {
        Ok(())
    }
}

pub fn exec_cc(filename: &PathBuf) -> Result<(), String> {
    let cc = Command::new("gcc")
        .arg("-g")
        .arg("-o")
        .arg(format!("{}", filename.with_extension("o").display()))
        .arg(format!("{}", filename.with_extension("s").display()))
        .output()
        .expect("cc failed.");
    if !cc.status.success() {
        Err(String::from_utf8_lossy(&cc.stderr).to_string())
    } else {
        Ok(())
    }
}

pub fn exec_cc_link(executable: &str, obj_files: Vec<PathBuf>) -> Result<(), String> {
    let obj_files = obj_files
        .into_iter()
        .map(|file| format!("{}", file.with_extension("o").display()))
        .collect::<Vec<String>>();
    println!("gcc -o {executable} {}", obj_files.join(" "));
    let cc = Command::new("gcc")
        .args(obj_files)
        .arg("-o")
        .arg(format!("{executable}"))
        .output()
        .expect("cc failed.");
    if !cc.status.success() {
        Err(String::from_utf8_lossy(&cc.stderr).to_string())
    } else {
        Ok(())
    }
}

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

pub fn compile_modules(executable: &str, filenames: Vec<PathBuf>) {
    for filename in &filenames {
        match exec_qbe(&filename) {
            Err(err) => eprintln!("qbe error: {err}"),
            _ => {}
        }
        match exec_cc_comp(&filename) {
            Err(err) => eprintln!("cc error: {err}"),
            _ => {}
        }
    }
    exec_cc_link(executable, filenames).unwrap();
}
