#[derive(Debug, Clone, Copy)]
pub enum BinaryOp {
    Arith(BinaryArith),
    Pred(BinaryPred),
    Index,
    Assign,
}

#[derive(Debug, Clone, Copy)]
pub enum BinaryPred {
    EQ,
    NE,
    GT,
    GE,
    LT,
    LE,
    And,
    Or,
}


#[derive(Debug, Clone, Copy)]
pub enum BinaryArith {
    Add,
    Sub,
    Mul,
    Div,
    Rem,
}

impl std::fmt::Display for BinaryPred {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        use BinaryPred::*;
        write!(f, "{}", match self {
            And => "&&",
            Or => "||",
            EQ => "==",
            NE => "!=",
            GT => ">",
            GE => ">=",
            LT => "<",
            LE => "<=",
        })
    }
}

impl std::fmt::Display for BinaryArith {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        use BinaryArith::*;
        write!(f, "{}", match self {
            Add => "+",
            Sub => "-",
            Mul => "*",
            Div => "/",
            Rem => "%",
        })
    }
}

impl std::fmt::Display for BinaryOp {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        use BinaryOp::*;
        match self {
            Arith(arith) => write!(f, "{}", arith),
            Pred(pred) => write!(f, "{}", pred),
            Index => write!(f, "[]"),
            Assign => write!(f, "="), 
        }
    }
}


impl Into<BinaryOp> for &BinaryPred {
    fn into(self) -> BinaryOp { (*self).into() }
}

impl Into<BinaryOp> for &BinaryArith { 
    fn into(self) -> BinaryOp { (*self).into() }
}

impl Into<BinaryOp> for BinaryPred {
    fn into(self) -> BinaryOp {
        BinaryOp::Pred(self)
    }
}

impl Into<BinaryOp> for BinaryArith {
    fn into(self) -> BinaryOp {
        BinaryOp::Arith(self)
    }
}
