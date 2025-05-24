#[derive(Debug, Copy, Clone)]
pub enum Atomic {
    Number,
    String,
    Char,
    Bool,
}

impl std::fmt::Display for Atomic {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", match self {
            Atomic::Number => "int",
            Atomic::String => "str",
            Atomic::Char => "char",
            Atomic::Bool => "bool",
        })
    }
}
