## Todo
 - [X] Arrays/Pointers
   - [X] Array indexing
   - [X] Array init
   - [X] Array decay
   - [X] Pointer indexing
   - [X] Array Deref
   - [X] Pointer deref
 - [ ] Array Return value
 - [ ] Structs
   - [X] Initialization
   - [X] field lookup
   - [X] Pass by Reference
   - [X] Pass by value
   - [ ] Return
   - [X] Structs of Structs
   - [X] Arrays of Structs
   - [X] Structs of Arrays
 - [ ] Globals
 - [ ] Extern Globals (STDIN, STDOUT, STDERR)
 - [ ] Unions
 - [ ] Enums -> Typechecked numbers with certain amount of bits?
 - [ ] Modules
 - [ ] For-loop
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
