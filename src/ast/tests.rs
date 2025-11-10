use super::*;
use crate::{ast::prelude::*, lexer::Lexer, typecheck::atomic::Atomic};

fn create_ast(code: &str) -> ast::Ast {
    let lexer = Lexer::new(code.to_string(), None);
    let (tokens, _) = lexer::run(lexer).unwrap();
    ast::Ast::new(tokens)
}

macro_rules! assert_next_global {
    ($parser: expr, $name: expr, $value: expr, $mutable: expr) => {
        match $parser.next() {
            Ok(Declaration::Global(g)) => {
                assert_eq!(g.name, $name.to_string());
                assert_eq!(g.value.kind, $value);
                assert_eq!(g.mutable, $mutable);
            }
            Ok(other) => panic!("Expected global, got {other}"),
            Err(err) => panic!("Expected global, got {:?}", err),
        }
    };
}

macro_rules! assert_next_function {
    ($parser: expr, $name: expr) => {
        match $parser.next() {
            Ok(Declaration::Function(f)) => {
                assert_eq!(f.prototype.identifier, $name.to_string());
                f
            }
            Ok(other) => panic!("Expected function, got {other}"),
            Err(err) => panic!("Expected function, got {:?}", err),
        }
    };
}

macro_rules! assert_next_extern_fn {
    ($parser: expr, $name: expr) => {
        match $parser.next() {
            Ok(Declaration::ExternFn(e)) => {
                assert_eq!(e.prototype.identifier, $name.to_string());
                e
            }
            Ok(other) => panic!("Expected extern, got {other}"),
            Err(err) => panic!("Expected extern, got {:?}", err),
        }
    };
}

#[test]
fn test_declaration() {
    let mut parser = create_ast("let abc = 123;");
    assert_next_global!(
        parser,
        "abc",
        AstExprKind::Literal(Literal::Number(123)),
        true
    );

    let mut parser = create_ast("const abc = 'a';");
    assert_next_global!(
        parser,
        "abc",
        AstExprKind::Literal(Literal::Char('a')),
        false
    );

    let mut parser = create_ast("fn main() {}");
    let f = assert_next_function!(parser, "main");
    assert_eq!(f.prototype.args.len(), 0);
    assert_eq!(f.prototype.return_type, AstFlowType::Void);

    let mut parser = create_ast("extern putchar();");
    let f = assert_next_extern_fn!(parser, "putchar");
    assert_eq!(f.prototype.args.len(), 0);
    assert_eq!(f.prototype.return_type, AstFlowType::Void);
}

#[test]
fn test_prototype() {
    let mut parser =
        create_ast("extern foo(bar: int, baz: char, other: float, is_good: bool): int");
    let e = assert_next_extern_fn!(parser, "foo");
    assert_eq!(e.prototype.args.len(), 4);
    assert_eq!(e.prototype.args[0].0, "bar".to_string());
    assert_eq!(e.prototype.args[0].1, AstTypeIdent::Atomic(Atomic::int()));
    assert_eq!(e.prototype.args[1].0, "baz".to_string());
    assert_eq!(e.prototype.args[1].1, AstTypeIdent::Atomic(Atomic::char()));
    assert_eq!(e.prototype.args[2].0, "other".to_string());
    assert_eq!(e.prototype.args[2].1, AstTypeIdent::Atomic(Atomic::Float));
    assert_eq!(e.prototype.args[3].0, "is_good".to_string());
    assert_eq!(e.prototype.args[3].1, AstTypeIdent::Atomic(Atomic::bool()));
    assert_eq!(
        e.prototype.return_type,
        AstFlowType::Some(AstTypeIdent::Atomic(Atomic::int()))
    );
}
