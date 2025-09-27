use crate::tests::utils::RunCompileError;

mod utils;

#[test]
fn pointers() {
    let res = utils::run_compiler("src/tests/pointers.ib").unwrap();
    assert_eq!("aabb xx 643 58 abGGaAA", res)
}

#[test]
fn basic() {
    let res = utils::run_compiler("src/tests/basic.ib").unwrap();
    assert_eq!("ac3 57= fedcb Xb5ab", res)
}

#[test]
fn literal() {
    let res = utils::run_compiler("src/tests/literal.ib").unwrap();
    assert_eq!("abc\n1AE", res)
}

#[test]
fn variable() {
    let res = utils::run_compiler("src/tests/variable.ib").unwrap();
    assert_eq!("agagxxd", res)
}

#[test]
fn operator() {
    let res = utils::run_compiler("src/tests/operator.ib").unwrap();
    assert_eq!("82621!>>|+-b-BbAO", res)
}

#[test]
fn function() {
    let res = utils::run_compiler("src/tests/function.ib").unwrap();
    assert_eq!("hello76(112358)hello", res)
}

#[test]
fn array() {
    let res = utils::run_compiler("src/tests/array.ib").unwrap();
    let mut l = res.lines();

    assert_eq!(Some("Hello World!"), l.next());
    assert_eq!(Some("28elo"), l.next());
    assert_eq!(Some("12395"), l.next());
    assert_eq!(Some("012345"), l.next());
    assert_eq!(Some("testTest"), l.next());
}

#[test]
fn array_pointer() {
    let res = utils::run_compiler("src/tests/array_pointer.ib").unwrap();
    let mut l = res.lines();

    assert_eq!(Some("adadcc"), l.next());
    assert_eq!(Some("abcaabcbc zzbcbc zyxzzyxyx"), l.next());
    assert_eq!(None, l.next());
}

#[test]
fn structs() {
    let res = utils::run_compiler("src/tests/struct.ib").unwrap();
    let mut l = res.lines();

    assert_eq!(Some("y"), l.next());
    assert_eq!(Some("49"), l.next());
    assert_eq!(Some("736"), l.next());
    assert_eq!(Some("B1Z"), l.next());
    assert_eq!(Some("Q8"), l.next());
    assert_eq!(Some("pq"), l.next());
    assert_eq!(Some("Q2B8"), l.next());
    assert_eq!(Some("B3F5ccxxx"), l.next());
    assert_eq!(None, l.next());
}

#[test]
fn arr_struct() {
    let res = utils::run_compiler("src/tests/arr_struct.ib").unwrap();
    let mut l = res.lines();

    assert_eq!(Some("a2ib4jc6ka5j"), l.next());
    assert_eq!(Some("8.3.3.1: What the dog doin?"), l.next());
    assert_eq!(None, l.next());
}

#[test]
fn struct_autoderef() {
    let res = utils::run_compiler("src/tests/struct_autoderef.ib").unwrap();
    let mut l = res.lines();

    assert_eq!(Some("(2;5)"), l.next());
    assert_eq!(Some("(3;3)"), l.next());
    assert_eq!(Some("(6;9)"), l.next());
    assert_eq!(None, l.next());
}

#[test]
fn struct_deref() {
    let res = utils::run_compiler("src/tests/struct_deref.ib").unwrap();
    let mut l = res.lines();

    assert_eq!(Some("7Z"), l.next());
    assert_eq!(Some("1A"), l.next());
    assert_eq!(Some("7Z"), l.next());
    assert_eq!(None, l.next());
}
