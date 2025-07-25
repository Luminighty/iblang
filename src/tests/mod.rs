mod utils;

#[test]
fn pointers() {
    let res = utils::run_compiler("src/tests/pointers.ib").unwrap();
    assert_eq!("aabb xx 643 58", res)
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
