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
   - [X] Import aliasing ( const math = import "math" )
   - [X] Import module
   - [X] pub keyword
   - [X] Resolve prototypes
   - [X] Resolve Globals
   - [X] Resolve Externs?
   - [X] Path operator ( math::Vec2 stdio::print() )
   - [X] Reexports with alias ( pub const math = import "math" )
   - [ ] Reexport symbols ( pub const foo = inner_foo; )
   - [X] Convert Identifiers to symbols
     - [X] Struct init
     - [X] Calls
     - [X] Globals
 - [X] Unions
   - [X] Initialization
   - [X] field lookup
   - [X] Pass by Reference
   - [X] Pass by value
   - [X] Return
   - [X] Union of Structs
   - [X] Struct of Unions
   - [X] Arrays of Unions
   - [X] Unions of Arrays
 - [X] Enums -> Typechecked numbers with certain amount of bits?
   - [ ] switch/match
     - [X] Basic implementation
     - [ ] Check for duplicate cases
     - [ ] Allow skipping default case when cond is enum and all enum variants are covered
   - [X] Define value enum { ROCK = 10, }
 - [ ] Fn Pointers
 - [ ] Explicit pointer casting -> replace most of implicit (disallow *vec -> *player, but allow *vec -> *void -> *player)
 - [ ] Fn Variadic args
 - [ ] Fix char[]
   - [ ] How to store 2 chars in a single W
   - [ ] How to index even/uneven chars (str[1] = 'c' / str[2] = 'a')
 - [ ] stdlib
   - [ ] IO: Read, Write, printf, putchar, getchar, puts,
   - [ ] File: Open, Read, Seek, Close, ect.
   - [ ] Cmd: Parse
   - [ ] Memory: malloc, free, calloc, memcpy, memset, memcmp
   - [ ] String: strcpy, strcmp, strncmp, push, slice, concat, ect.
   - [ ] Math: sin, cos, sqrt, floor, ceil, pow
   - [ ] Exit, Assert, Unit tests
 - [ ] Bitwise operators/any other operators
 - [ ] Update treesitter grammar
   - [ ] support ' ' " " (strings/chars ending with space)
   - [ ] break, continue, for, null, pub
   - [ ] const/imports/alias
   - [ ] union, Enums, Fn Typeident
   - [ ] switch/case/match
   - [ ] rest of the operators


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

### Anonymous Types

```rs
union Vec2 {
  v: int[2],
  struct { x: int, y: int },
}

union Vec2 {
  v: int[2],
  u: struct { x: int, y: int },
}

struct Entity {
  id: EntityId,
  struct {
    is_alive: bool,
    is_player: bool,
    is_enemy: bool,
    on_fire: bool,
    on_poison: bool,
  }
}
```

Sort of a syntactic sugar, could either be under a field or unwrapped

