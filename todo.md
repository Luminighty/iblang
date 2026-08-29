- [X] Handle duplicate symbols (currently we just assert on it >:( )
- [X] Add implicit casting calls (Early return if types match, unless explicit)
- [?] Start adding support for pointers
  - [X] Ref
  - [X] Deref
  - [X] Unary Not
  - [?] Lvalues/Rvalues
  - [ ] Auto-ref???
        Maybe in case of functions it could make sense
        But lets think more about it
- [ ] Create snapshot tests for existing stuff
- [X] Null Literal typeident
- [ ] Improve Error reporting
    - [ ] Maybe support multiple spans
    - [ ] Custom messages based on context
        Turn enums into functions to with context args
- [ ] Replace recursive Typechecking
    - [ ] Use the original method, in order to ensure we typecheck unused code
        - [ ] Start with Struct/Unions (have to use recursive for that to know sizes)
        - [ ] Move onto Prototypes + Extern fn/globals
        - [ ] Globals
        - [ ] Function bodies
    - [ ] Mark symbols as used during "Body" checking
    - [ ] Report unused Symbols as warnings (Skip underscore and add flag to error or disable warnings)
    NOTE: It's important to typecheck unused code, otherwise dead code might be completely invalid, without it getting reported.

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
    - [ ] Auto-deref
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
