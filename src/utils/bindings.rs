use std::collections::HashMap;


pub struct Bindings<Bind> {
    variables: Vec<HashMap<String, Bind>>,
}

impl<Bind> Bindings<Bind> {
    pub fn new() -> Self {
        Self { variables: vec![] }
    }

    pub fn start_block(&mut self) {
        self.variables.push(HashMap::new());
    }

    pub fn end_block(&mut self) {
        self.variables.pop();
    }

    pub fn insert(&mut self, key: String, bind: Bind) {
        self.head_mut().insert(key, bind);
    }

    pub fn get(&self, key: &str) -> Option<&Bind> {
        for var in self.variables.iter().rev() {
            if let Some(var) = var.get(key) {
                return Some(var)
            }
        }
        None
    }

    #[inline]
    fn head_mut(&mut self) -> &mut HashMap<String, Bind> {
        self.variables.last_mut().unwrap()
    }
}

