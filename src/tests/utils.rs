use crate::{
    ast, codegenqbe, lexer, run_recurive_parsing, symbol_resolver, typecheck, utils::FileMeta,
};

pub fn run_compiler(file: &str) -> Result<String, RunCompileError> {
    let mut symbol_table = symbol_resolver::symbol_table();
    let args = crate::args::CompilerArgs::default();
    let (main, ast_modules, metas) = run_recurive_parsing(file, &args, &mut symbol_table);
    let main_filename = format!("./build/{}", ast_modules.get(&main).unwrap().module_name());
    let modules = typecheck::run_typechecker(
        &mut symbol_table,
        &ast_modules,
        &metas,
        args.print_typecheck,
    );
    let mut filenames = codegenqbe::run_codegen_all(&symbol_table, modules, metas, &args);
    codegenqbe::compile_modules(&main_filename, filenames);
    let res = codegenqbe::exec_file(&main_filename)
        .map_err(|(out, err)| RunCompileError::ExecError(out, err))?;

    Ok(res)
}

pub enum RunCompileError {
    FileNotFound(String),
    LexerError(Vec<lexer::LexerError>),
    AstError(Vec<ast::AstError>),
    Typecheck(Vec<typecheck::TypecheckError>, FileMeta),
    QbeError(String),
    CCError(String),
    ExecError(String, String),
}

impl std::fmt::Debug for RunCompileError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            RunCompileError::FileNotFound(file) => writeln!(f, "File not found {file}"),
            RunCompileError::LexerError(errors) => {
                for err in errors {
                    writeln!(f, "{err}")?;
                }
                Ok(())
            }
            RunCompileError::AstError(errors) => {
                for err in errors {
                    writeln!(f, "{err:?}")?;
                }
                Ok(())
            }
            RunCompileError::Typecheck(errors, meta) => {
                // typecheck::print_errors(errors, meta);
                Ok(())
            }
            RunCompileError::QbeError(err) => writeln!(f, "QBE Error: {err}"),
            RunCompileError::CCError(err) => writeln!(f, "CC Error: {err}"),
            RunCompileError::ExecError(out, err) => {
                writeln!(f)?;
                writeln!(f, "STDOUT: {out:?}")?;
                writeln!(f, "Exec Error: {err:?}")
            }
        }
    }
}

impl From<Vec<ast::AstError>> for RunCompileError {
    fn from(value: Vec<ast::AstError>) -> Self {
        RunCompileError::AstError(value)
    }
}

impl From<Vec<lexer::LexerError>> for RunCompileError {
    fn from(value: Vec<lexer::LexerError>) -> Self {
        RunCompileError::LexerError(value)
    }
}
