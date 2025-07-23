mod utils;

// #[test]
// fn reftest() {
//     let res = utils::run_compiler("src/tests/reftest.ib").unwrap();
//     assert_eq!("9", res)
// }

#[test]
fn basic() {
    let res = utils::run_compiler("src/tests/basic.ib").unwrap();
    assert_eq!("ac3 57= fedcb", res)
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
    assert_eq!("82621!>>|", res)
}

#[test]
fn function() {
    let res = utils::run_compiler("src/tests/function.ib").unwrap();
    assert_eq!("hello76(112358)hello", res)
}
