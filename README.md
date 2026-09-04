## iblang

Self Hosted version status:
 - [X] Run modes/Args
 - [X] Test Runner
 - [X] Lexer
 - [X] AST
 - [X] Recursive Parsing
 - [X] Common Error Storage
 - [X] Symbol Table
 - [X] Unit Tests
 - [O] LSP (IN PROGRESS)
   - Catches AST errors
 - [X] Snapshot testing
 - [O] Typechecking
 - [X] Stdlib include
 - [ ] Code Gen into C
 - [ ] JIT/VM Runner

### Features to add

- [ ] Symbol Reexporting
- [ ] Comptime Generics
- [ ] Fat Enums
- [ ] TypeDef
        ```ib
        const Units = vec::Vec<Unit>
        const System = fn(game: *Game): void
        ```
- [ ] Flags (bit flag enum)
- [ ] Anonymous Types (inline types)
- [ ] Include utils into separate stdlib modules
- [ ] "Methods": vec::get(&v, i) -> v.get(i)


### Ideas

#### Auto-ref
Maybe in case of functions it could make sense

I think for "lua style methods", auto-refing could make a lot of sense
```
let v = vec::new<Foo>();
v.push(foo);         // <--- would be okay
vec::push(v, foo);   // <--- I don't like this
```
But I think the rest should be explicit?

