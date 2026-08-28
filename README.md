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
 - [ ] LSP (IN PROGRESS)
   - Catches AST errors
 - [ ] Snapshot testing (IN PROGRESS)
 - [ ] Typechecking
 - [ ] Stdlib include
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
- [ ] Auto-reffing?
        What if this could be called like:
        ```ib
        let v: Vec = ...
        get(v); // TODO: Think a lot about this
        fn get(v: *Vec) {}
        ```
