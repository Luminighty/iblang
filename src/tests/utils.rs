use crate::{ast, codegenqbe, lexer, typecheck};

pub fn run_compiler(file: &str) -> Result<String, ()> {
    let lxr = lexer::from_file(file).unwrap();
    let (tokens, meta) = lexer::run(lxr).unwrap();
    let module = ast::run(tokens, &meta).unwrap();
    let module = typecheck::run(&module).unwrap();

    codegenqbe::run(&module);
    codegenqbe::exec_qbe(&module.name).unwrap();
    codegenqbe::exec_cc(&module.name).unwrap();
    let res = codegenqbe::exec_file(&module.name).unwrap();

    Ok(res)
}
