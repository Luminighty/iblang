## TODO
- [X] Handle duplicate symbols (currently we just assert on it >:( )
- [X] Add implicit casting calls (Early return if types match, unless explicit)
- [X] Start adding support for pointers
  - [X] Ref
  - [X] Deref
  - [X] Unary Not
- [X] Create snapshot tests for existing stuff
- [X] Null Literal typeident
- [X] Replace recursive Typechecking
    NOTE: It's important to typecheck unused code, otherwise dead code might be completely invalid, without it getting reported.
    - [X] Use the original method, in order to ensure we typecheck unused code
        - [X] Struct/Unions (support recursive)
        - [X] Extern fn/globals
        - [X] Prototypes
        - [X] Globals
        - [X] Function bodies
    - [X] Mark symbols as used during "Body" checking
    - [X] Mark variables as used
- [X] BUG: Binary implicit

- [ ] BUG: Pointer error
    - [ ] Prevent &/* unary ops with literals(non-addressable things)
          This can be fixed with L/RValues I think?

- [ ] ConstExpr init
    - [X] Literals
    - [ ] Binary
    - [ ] Unary
    - [ ] Array
    - [ ] ObjectInit
- [X] Arrays
    - [X] Indexing
    - [X] Init
    - [ ] TypeIdent
    - [ ] Array Decay
    - [X] Strings
    - [ ] Tests
- [ ] Structs
    - [X] Struct Definition
    - [X] Struct Init
    - [X] Field Lookup
    - [X] TypeIdent
    - [X] Tests
    - [X] Size/metainfo (can be kept until a bit later)
    - [X] SizeOf
    - [ ] Auto-deref
- [ ] Unions
    - [X] Union Definition
    - [X] Union Init
    - [X] Field Lookup
    - [X] Tests
    - [X] Size/Metainfo
    - [ ] Auto-deref
- [ ] Enums
    - [X] Enum Definition
    - [X] Enum init
    - [X] Enum Casting
    - [X] Enum values
    - [X] Tests
- [X] Globals
    - [X] Init
    - [X] Casting
    - [ ] Tests
- [X] ExternFn
- [X] ExternGlobal
- [ ] Match
    - [ ] Validate and propagate flows correctly
            Just look through the codebase and see the unnecessary return cases
            Write unit tests for this too!
- [X] Symbol
    - [X] Path Resolver
- [ ] Clean up all TODO items
- [ ] Break up AST into multiple files
    - [ ] Similarly to how typechecker does it
- [ ] Add support for binary/hexa numbers
- [?] Lvalues/Rvalues



## Improvements
- [ ] Symbol aliasing/reexporting <3
    (Rust version does not have it, but would be SO nice (symbol::symbol::Symbol vs symbols::add|symbol::Symbol ))
    Also `pub const NodeIdx = int;`
- [ ] consume varargs
    - [ ] I can pass varargs to extern fns (`printf`), but I cannot read it from my own code
    - [ ] ALTOUGH I NEVER TRIED IT EITHER, so maybe it does work with some adjustments
- [ ] Improve Error reporting
    - [ ] Maybe support multiple spans
    - [ ] Custom messages based on context
        Turn enums into functions to with context args
- [ ] Report unused Symbols as warnings (Skip underscore and add flag to error or disable warnings)
    - [ ] Recursive unused checking?


## Low prio
- [ ] TreeSitter Fixes
    - [ ] Object Init with path
    - [ ] Object Zero Init
    - [ ] Object init with only keys `Foo { bar }` form over `Foo { bar: 123 }`
    - [ ] Path types err::Errors
    - [ ] pub const BLUE = "\x1b[1m\x1b[34m";
    - [ ] Enum variants col;
    - [ ] CONSTANTS


## Unknown at this point
- [?] For body seems to be missing
- [?] array test cuts off


