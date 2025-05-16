use crate::Span;

use super::{expr::Expr, function::{Extern, Function}, Identifier};

pub enum Declaration {
    Function {
        function: Function,
        span: Span,
    },
    Extern {
        ext: Extern,
        span: Span,
    },
    Global {
        name: Identifier,
        value: Expr,
        span: Span,
    },
    None,
}

