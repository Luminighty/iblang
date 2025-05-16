use super::{expr::Expr, function::{Extern, Function}};

pub struct Module {
    pub name: String,
    pub functions: Vec<Function>,
    pub externs: Vec<Extern>,
    pub globals: Vec<Expr>,
}
