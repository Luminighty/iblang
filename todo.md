- [X] Handle duplicate symbols (currently we just assert on it >:( )
- [ ] Add implicit casting calls (Early return if types match, unless explicit)
- [ ] Start adding support for pointers
  - [ ] Ref
  - [ ] Deref
  - [ ] Unary Not
  - [ ] Lvalues/Rvalues
  - [ ] Auto-deref
  - [ ] Auto-ref???
        Maybe in case of functions it could make sense
        But lets think more about it
- [ ] Create snapshot tests for existing stuff
- [ ] Null Literal typeident Todo
- [ ] Improve Error reporting
    - [ ] Maybe support multiple spans
    - [ ] Custom messages based on context
        Turn enums into functions to with context args

- [ ] Break up AST into multiple files
    - [ ] Similarly to how typechecker does it

- [ ] Arrays
    - [ ] Indexing
    - [ ] Init
    - [ ] TypeIdent
    - [ ] Array Decay
    - [ ] Strings
    - [ ] Tests
- [ ] Structs
    - [ ] Struct Definition
    - [ ] Struct Init
    - [ ] Field Lookup
    - [ ] TypeIdent
    - [ ] Tests
    - [ ] Size/metainfo (can be kept until a bit later)
- [ ] Unions
    - [ ] Union Definition
    - [ ] Union Init
    - [ ] Field Lookup
    - [ ] Tests
    - [ ] Size/Metainfo
- [ ] Enums
    - [ ] Enum Definition
    - [ ] Enum init
    - [ ] Enum Casting
    - [ ] Enum values
    - [ ] Tests
- [ ] ExternFn
- [ ] ExternGlobal
- [ ] Match
    - [ ] Validate and propagate flows correctly
            Just look through the codebase and see the unnecessary return cases
            Write unit tests for this too!
- [ ] Globals
    - [ ] Tests
- [ ] Symbol
    - [ ] Path Resolver
    - [ ] Symbol aliasing/reexporting <3
            (Rust version does not have it, but would be SO nice (symbol::symbol::Symbol vs symbols::add|symbol::Symbol ))
- [ ] consume varargs
    - [ ] I can pass varargs to extern fns (`printf`), but I cannot read it from my own code
    - [ ] ALTOUGH I NEVER TRIED IT EITHER, so maybe it does work with some adjustments
- [ ] Clean up all TODO items

Unknown at this point
- [?] For body seems to be missing
- [?] array test cuts off
