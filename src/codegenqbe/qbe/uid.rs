use std::collections::HashMap;

use crate::codegenqbe::qbe::error::QbeUidStoreKind;

use super::error::QbeError;

#[derive(Debug)]
pub struct UnwrappedUId<'a> {
    name: &'a str,
    id: Option<u32>,
}

#[derive(Debug, Clone, Copy)]
pub struct UId {
    idx: usize,
    id: Option<u32>,
}

pub struct UIdStore {
    idx: HashMap<String, usize>,
    uid: Vec<u32>,
    names: Vec<String>,
    kind: QbeUidStoreKind,
}

impl UIdStore {
    pub fn new(kind: QbeUidStoreKind) -> Self {
        Self {
            idx: HashMap::new(),
            uid: Vec::new(),
            names: Vec::new(),
            kind,
        }
    }

    pub fn clear(&mut self) {
        self.idx.clear();
        self.uid.clear();
        self.names.clear();
    }

    pub fn create(&mut self, name: &str) -> UId {
        if let Some(idx) = self.idx.get(name) {
            self.uid[*idx] += 1;
            let id = Some(self.uid[*idx]);
            UId { idx: *idx, id }
        } else {
            let idx = self.uid.len();
            self.idx.insert(name.to_owned(), idx);
            self.uid.push(0);
            self.names.push(name.to_owned());
            UId { idx, id: None }
        }
    }

    pub fn get(&self, uid: &UId) -> Result<UnwrappedUId, QbeError> {
        match self.names.get(uid.idx) {
            Some(name) => Ok(UnwrappedUId { id: uid.id, name }),
            _ => Err(QbeError::UnknownUid(uid.clone(), self.kind)),
        }
    }
}

impl std::fmt::Display for UnwrappedUId<'_> {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self.id {
            Some(id) => write!(f, "{}_{}", self.name, id),
            None => write!(f, "{}", self.name),
        }
    }
}
