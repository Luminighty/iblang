#[derive(Debug, Clone, Copy)]
pub enum BinaryOp {
    Add,
    Sub,
    Mul,
    Div,
    Rem,
    EQ,
    NE,
    GT,
    GE,
    LT,
    LE,
    Index,
    Assign,
}

impl std::fmt::Display for BinaryOp {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        use BinaryOp::*;
        write!(f, "{}", match self {
            Add => "+",
            Sub => "-",
            Mul => "*",
            Div => "/",
            Rem => "%",
            EQ => "==",
            NE => "!=",
            GT => ">",
            GE => ">=",
            LT => "<",
            LE => "<=",
            Index => "[]",
            Assign => "=",
        })
    }
}
