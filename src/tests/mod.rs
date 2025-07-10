mod utils;

#[test]
fn reftest() {
    let res = utils::run_compiler("src/tests/reftest.ib").unwrap();
    assert_eq!("9", res)
}
