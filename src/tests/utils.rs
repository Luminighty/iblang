use crate::{ast, codegenqbe, lexer, typecheck, utils::FileMeta};

pub fn run_compiler(file: &str) -> Result<String, RunCompileError> {
    let lxr = lexer::from_file(file).ok_or(RunCompileError::FileNotFound(file.to_string()))?;
    let (tokens, meta) = lexer::run(lxr)?;
    let module = ast::run(tokens, &meta)?;
    let module =
        typecheck::run(&module, false).map_err(|errs| RunCompileError::Typecheck(errs, meta))?;

    codegenqbe::run(&module);
    codegenqbe::exec_qbe(&module.name).map_err(|err| RunCompileError::QbeError(err))?;
    codegenqbe::exec_cc(&module.name).map_err(|err| RunCompileError::CCError(err))?;
    let res = codegenqbe::exec_file(&module.name)
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
                typecheck::print_errors(errors, meta);
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
