NOTE: I made the deepinfo to only contain the typeident/ect.
#[derive(Debug)]
pub enum DeepInfo {
    None,
    Struct(Rc<StructDef>),
    Global(Rc<TypeIdent>),
    ExternGlobal(Rc<TypeIdent>),
    Function(Rc<Prototype>),
}

This should let us typecheck in 2 pass.
1. pass: is for "header" values (structs, global types, function prototypes)
2. pass: global values, function bodies

## Todo
 - [X] Arrays/Pointers
   - [X] Array indexing
   - [X] Array init
   - [X] Array decay
   - [X] Pointer indexing
   - [X] Array Deref
   - [X] Pointer deref
 - [X] Array Return value -> Probably skip for now, since it's not in C
 - [X] Structs
   - [X] Initialization
   - [X] field lookup
   - [X] Pass by Reference
   - [X] Pass by value
   - [X] Return
   - [X] Structs of Structs
   - [X] Arrays of Structs
   - [X] Structs of Arrays
   - [X] Typecheck invalid/missing fields
   - [X] Vec2 { x, y } syntax
 - [X] Globals
   - [X] Global Declaration
   - [X] Global Lookup
   - [X] Full Const Eval
     - [X] Literal
     - [X] Binary
     - [X] Unary
     - [X] Struct
     - [X] Array
     - [X] Globals
   - [X] Extern Globals (STDIN, STDOUT, STDERR)
 - [X] For-loop
 - [X] Break/Continue
 - [X] Nullptr
 - [ ] Modules
   - [X] Find modules
   - [?] Import namespace
   - [?] Import module
   - [X] pub keyword
   - [X] Resolve prototypes
   - [X] Resolve Globals
   - [X] Resolve Externs?
   - [ ] Path operator
   - [ ] Reexports with alias
   - [ ] Convert Identifiers to symbols
     - [ ] Struct init
     - [ ] What else?
 - [ ] Unions
   - [ ] Initialization
   - [ ] field lookup
   - [ ] Pass by Reference
   - [ ] Pass by value
   - [ ] Return
   - [ ] Union of Structs
   - [ ] Struct of Unions
   - [ ] Arrays of Unions
   - [ ] Unions of Arrays
 - [ ] Enums -> Typechecked numbers with certain amount of bits?
 - [ ] Fn Pointers
 - [ ] stdlib
   - [ ] IO: Read, Write, printf, putchar, getchar, puts,
   - [ ] File: Open, Read, Seek, Close, ect.
   - [ ] Cmd: Parse
   - [ ] Memory: malloc, free, calloc, memcpy, memset, memcmp
   - [ ] String: strcpy, strcmp, strncmp, push, slice, concat, ect.
   - [ ] Math: sin, cos, sqrt, floor, ceil, pow
   - [ ] Exit, Assert, Unit tests

## Optional, but really sweet sounding syntactic sugars

###  Tagged Enum (Variants)

```rs
variant Foo {
  Bar(Bar),
  Baz(Baz),
}

fn assert_foo(foo: Foo, tag: Foo::Tag) {
  if foo != tag {
    panic(...)
  }
}

let foo = Foo::Bar(Bar { ... });
assert_foo(foo, Foo::Bar);
```

### CompTime Generics
Ideally, it's just gathered into a Set, compiled 
  and typechecked as if they are normal types

```rs
variant Result<T, V> {
  Ok(T)
  Err(V)
}
let res = fallible();
match res {
  Ok(res) => {},
  Err(err) => {},
}
// This is kinda cool, we technically 
// shouldn't need to know T or V here
if res == Result::Ok {}
```

### Flags
```rs
flag EntityFlag {
  Player // 1 << 0
  Dead, // 1 << 1
  Ally, // 1 << 2
  Enemy, // 1 << 3
}
let entity_flag: EntityFlag = EntityFlag::Player | EntityFlag::Dead | EntityFlag::Ally
```
