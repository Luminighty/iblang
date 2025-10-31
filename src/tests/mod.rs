use crate::tests::utils::RunCompileError;

mod utils;

#[test]
fn pointers() {
    let res = utils::run_compiler("src/tests/pointers.ib").unwrap();
    let mut l = res.lines();
    assert_eq!(Some("aabb"), l.next());
    assert_eq!(Some("xx"), l.next());
    assert_eq!(Some("643"), l.next());
    assert_eq!(Some("58"), l.next());
    assert_eq!(Some("abGGaAA"), l.next());
    assert_eq!(Some("01301c"), l.next());
    assert_eq!(None, l.next());
}

#[test]
fn basic() {
    let res = utils::run_compiler("src/tests/basic.ib").unwrap();
    let mut l = res.lines();
    assert_eq!(Some("ac3"), l.next());
    assert_eq!(Some("57="), l.next());
    assert_eq!(Some("fedcb"), l.next());
    assert_eq!(Some("Xb5ab"), l.next());
    assert_eq!(Some("01234012345"), l.next());
    assert_eq!(None, l.next());
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
    assert_eq!(Some("(4,3)(2,1)(8,9)(6,4)(6,4)(1,1)4(3,3)(5,6)"), l.next());
    assert_eq!(Some("(5,3)(2,1)(9,8)(1,4)"), l.next());
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

#[test]
fn globals() {
    let res = utils::run_compiler("src/tests/global.ib").unwrap();
    let mut l = res.lines();

    assert_eq!(Some("a042x"), l.next());
    assert_eq!(
        Some("this is a really long message with multiple parts."),
        l.next()
    );
    assert_eq!(
        Some("This Is A Really Long Message With Multiple Parts."),
        l.next()
    );
    assert_eq!(Some("this is another message"), l.next());
    assert_eq!(Some("This Is Another Message"), l.next());
    assert_eq!(Some("(o):5,3;col:2"), l.next());
    assert_eq!(Some("(b):2,8;"), l.next());
    assert_eq!(Some("(p):13,25;"), l.next());
    assert_eq!(Some("(c):2,8;"), l.next());
    assert_eq!(Some("(G):120,532;col:6"), l.next());
    assert_eq!(Some("(@):30,35;"), l.next());
    assert_eq!(Some("(G):120,532;col:6"), l.next());
    assert_eq!(None, l.next());
}

#[test]
fn modules_basic() {
    let res = utils::run_compiler("src/tests/modules_basic/main.ib").unwrap();
    let mut l = res.lines();

    assert_eq!(Some("Hello Modules!"), l.next());
    assert_eq!(Some("10 13 12 15 53"), l.next());
    assert_eq!(Some("Vec2{x:5;y:3}"), l.next());
    assert_eq!(Some("Vec2{x:2;y:18}"), l.next());
    assert_eq!(Some("10 8 6 4 2 "), l.next());
    assert_eq!(Some("4 2 "), l.next());
    assert_eq!(None, l.next());
}

#[test]
fn modules_alias() {
    let res = utils::run_compiler("src/tests/modules_alias/main.ib").unwrap();
    let mut l = res.lines();

    assert_eq!(Some("Hello Modules!"), l.next());
    assert_eq!(Some("10 20"), l.next());
    assert_eq!(Some("Vec2{x:5;y:10}"), l.next());
    assert_eq!(Some("Vec2{x:3;y:5}"), l.next());
    assert_eq!(Some("Vec2{x:8;y:15}"), l.next());
    assert_eq!(Some("420 69 321"), l.next());
    assert_eq!(None, l.next());
}
