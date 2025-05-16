use super::statement::Statement;

pub struct Prototype {
    pub identifier: String,
}

pub struct Extern(pub Prototype);

pub struct Function {
    pub prototype: Prototype,
    pub body: Statement,
}


impl Prototype {
    pub fn new(identifier: String) -> Self {
        Self { identifier }
    }
}

impl Function {
    pub fn new(prototype: Prototype, body: Statement) -> Self {
        Self { prototype, body }
    }
}

impl Extern {
    pub fn new(prototype: Prototype) -> Self {
        Self(prototype)
    }
}
