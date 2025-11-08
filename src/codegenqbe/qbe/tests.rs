use std::io::Cursor;

use crate::codegenqbe::{
    expr::QbeValue,
    qbe::{
        LoadTy, SubWTy,
        qbe_fn::{CallBuilder, FunctionBuilder},
    },
};

use super::{BaseTy, Qbe};

fn output_to_str(qbe: Qbe<Cursor<Vec<u8>>>) -> String {
    let out = qbe.out.into_inner();
    let output = String::from_utf8(out).unwrap();
    output
        .lines()
        .map(|l| l.replace("\t", "    "))
        .filter(|l| l.len() > 0)
        .collect::<Vec<_>>()
        .join("\n")
}

#[test]
fn test_basic() {
    let buffer = Cursor::new(Vec::new());
    let mut qbe = Qbe::new(buffer);

    use BaseTy::*;

    let fn_main = qbe.create_global("main", false).unwrap();
    let fn_add = qbe.create_global("add", false).unwrap();
    let fn_putchar = qbe.create_global("putchar", false).unwrap();

    let fn_putchar = QbeValue::Global(fn_putchar);

    let mut fn_builder = FunctionBuilder::new(fn_main);
    fn_builder.export();
    fn_builder.return_value(W);
    fn_builder.start(&mut qbe).unwrap();
    {
        let mut call = CallBuilder::new(&QbeValue::Global(fn_add));
        call.arg(W, 1);
        call.arg(W, 2);
        let res = call.call_res(&mut qbe, W, "r").unwrap();

        let chr = qbe.binary(BaseTy::W, "add", 48, &res, "tempadd").unwrap();
        let mut call = CallBuilder::new(&fn_putchar);
        call.arg(W, &chr);
        call.call(&mut qbe).unwrap();
        let mut call = CallBuilder::new(&fn_putchar);
        call.arg(W, 10);
        call.call(&mut qbe).unwrap();
        qbe.retv(0).unwrap();
    }
    qbe.function_end().unwrap();

    let a = qbe.create_temp("a");
    let b = qbe.create_temp("b");

    let mut fn_builder = FunctionBuilder::new(fn_add);
    fn_builder.arg(W, &a);
    fn_builder.arg(W, &b);
    fn_builder.return_value(W);
    fn_builder.start(&mut qbe).unwrap();
    {
        let add = qbe.binary(W, "add", &a, &b, "tempadd").unwrap();
        qbe.retv(&add).unwrap();
    }
    qbe.function_end().unwrap();

    let output = output_to_str(qbe);

    assert_eq!(
        output,
        "
export function w $main() {
@start
    %r =w call $add(w 1, w 2, )
    %tempadd =w add 48, %r
    call $putchar(w %tempadd, )
    call $putchar(w 10, )
    ret 0
}
function w $add(w %a, w %b, ) {
@start
    %tempadd =w add %a, %b
    ret %tempadd
}
"
        .trim()
    );
}

#[test]
fn test_inst() {
    let buffer = Cursor::new(Vec::new());
    let mut qbe = Qbe::new(buffer);

    use BaseTy::*;

    let block = qbe.create_block("main");
    let value = qbe.create_temp("value");
    let mem = qbe.create_temp("mem");
    let mem_target = qbe.create_temp("mem_target");
    qbe.write_block(&block).unwrap();
    qbe.jmp(&block).unwrap();
    let if_true = qbe.create_block("if_true");
    let if_false = qbe.create_block("if_false");
    qbe.jnz(123, &if_true, &if_false).unwrap();
    qbe.ret().unwrap();
    qbe.retv(&value).unwrap();
    qbe.hlt().unwrap();

    qbe.binary(W, "add", 0, &value, "x").unwrap();
    qbe.binary(W, "cgts", &value, &value, "c").unwrap();
    qbe.store(D, 63, &value).unwrap();
    qbe.load(LoadTy::BaseTy(W), &mem, "loaded").unwrap();
    qbe.load(LoadTy::BaseTy(L), &mem, "loaded_l").unwrap();
    qbe.blit(&mem, &mem_target, 502).unwrap();
    qbe.alloc8(12, "stack_var").unwrap();
    qbe.unary(S, "copy", 621.32, "set_val").unwrap();

    let output = output_to_str(qbe);
    assert_eq!(
        output,
        "
@main
    jmp @main
    jnz 123, @if_true, @if_false
    ret
    ret %value
    hlt
    %x =w add 0, %value
    %c =w cgts %value, %value
    stored 63, %value
    %loaded =w loadw %mem
    %loaded_l =l loadl %mem
    blit %mem, %mem_target, 502
    %stack_var =l alloc8 12
    %set_val =s copy d_621.32
"
        .trim()
    );
}
