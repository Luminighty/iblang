#[derive(Debug)]
pub enum Literal {
    Number(i64),
    Bool(bool),
    String(String),
    Char(char),
}

impl std::fmt::Display for Literal {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        use Literal::*;
        match self {
            Number(n) => write!(f, "{}", n),
            Bool(true) => write!(f, "true"),
            Bool(false) => write!(f, "false"),
            String(s) => write!(f, "\"{}\"", s),
            Char(c) => write!(f, "'{}'", c),
        }
    }
}
