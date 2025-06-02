#[derive(Debug, Clone, Copy, PartialEq)]
pub enum UnaryOp {
    Arith(UnaryArith),
    GROUP,
    REF,
    DEREF,
}

#[derive(Debug, Clone, Copy, PartialEq)]
pub enum UnaryArith {
    POS,
    NEG,
    NOT,
}


impl Into<UnaryOp> for UnaryArith {
    fn into(self) -> UnaryOp {
        UnaryOp::Arith(self)
    }
}


impl std::fmt::Display for UnaryArith {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        use UnaryArith::*;
        write!(f, "{}", match self {
            POS => "+",
            NOT => "!",
            NEG => "-",
        })
    }
}

impl std::fmt::Display for UnaryOp {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        use UnaryOp::*;
        match self {
            Arith(arith) => write!(f, "{arith}"),
            DEREF => write!(f, "*"),
            GROUP => write!(f, "()"),
            REF => write!(f, "&"),
        }
    }
}
