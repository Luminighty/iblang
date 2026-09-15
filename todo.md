## TODO
- [ ] BUG: Pointer error
    - [ ] Prevent &/* unary ops with literals(non-addressable things)
          This can be fixed with L/RValues I think?
    - [?] Lvalues/Rvalues
- [ ] Arrays
    - [ ] Array Decay
    - [ ] Tests
- [ ] Globals
    - [ ] Tests
- [ ] Clean up all TODO items
- [ ] Add support for binary/hexa numbers
- [ ] Auto-deref Tests
- [ ] ""Apply Default Promotions""
    - used for varargs casts
- [ ] Test Coverage for AssignBit ops
- [ ] Fix Sourcemap issue on selfhosted version

## Improvements
- [ ] Symbol aliasing/reexporting <3
    (Rust version does not have it, but would be SO nice (symbol::symbol::Symbol vs symbols::add|symbol::Symbol ))
    Also `pub const NodeIdx = int;`
    Maybe `pub use NodeIdx = int;` would be easier to parse though? It's hard to say
- [ ] keyword as identifier
    - [ ] allows for things like let if = abc;
    - [ ] Update consume_ident to convert keywords into their identifiers 
- [ ] consume varargs
    - [ ] I can pass varargs to extern fns (`printf`), but I cannot read it from my own code
- [ ] Improve Error reporting
    - [ ] Maybe support multiple spans
    - [ ] Custom messages based on context
        Turn enums into functions to with context args
- [ ] Report unused Symbols as warnings (Skip underscore and add flag to error or disable warnings)
    - [ ] Recursive unused checking?
- [ ] ConstExpr init
    - [ ] This could wait until JIT execution in place
    - [ ] Binary
    - [ ] Array
    - [ ] ObjectInit

## Low prio
- [ ] TreeSitter Fixes
    - [ ] Object Init with path
    - [ ] Object Zero Init
    - [ ] Object init with only keys `Foo { bar }` form over `Foo { bar: 123 }`
    - [ ] Path types err::Errors
    - [ ] pub const BLUE = "\x1b[1m\x1b[34m";
    - [ ] Enum variants col;
    - [ ] CONSTANTS


