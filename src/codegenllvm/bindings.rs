use std::collections::HashMap;
use super::typedvalue::TypedValue;

pub struct VariableBindings<'ctx> {
    variables: Vec<HashMap<String, TypedValue<'ctx>>>,
}

impl<'ctx> VariableBindings<'ctx> {
    pub fn new() -> Self {
        Self { variables: vec![] }
    }

    pub fn start_block(&mut self) {
        self.variables.push(HashMap::new());
    }

    pub fn end_block(&mut self) {
        self.variables.pop();
    }

    pub fn insert(&mut self, key: String, value: TypedValue<'ctx>) {
        self.head_mut().insert(key, value);
    }

    pub fn get(&self, key: &str) -> Option<&TypedValue<'ctx>> {
        self.head().get(key)
    }

    #[inline]
    fn head_mut(&mut self) -> &mut HashMap<String, TypedValue<'ctx>> {
        self.variables.last_mut().unwrap()
    }

    #[inline]
    fn head(&self) -> &HashMap<String, TypedValue<'ctx>> {
        self.variables.last().unwrap()
    }
}
