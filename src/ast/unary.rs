#[derive(Debug, Clone, Copy)]
pub enum UnaryOp {
    GROUP,
    POS,
    NOT,
    NEG,
}


impl std::fmt::Display for UnaryOp {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        use UnaryOp::*;
        write!(f, "{}", match self {
            GROUP => "()",
            POS => "+",
            NOT => "!",
            NEG => "-",
        })
    }
}
