use std::path::{Path, PathBuf};

pub fn join_relative(base: &str, rel: &str) -> PathBuf {
    let base = Path::new(base);
    let rel = Path::new(rel);

    let mut result = PathBuf::new();

    result.push(base.parent().unwrap());

    result.push(rel);

    let mut normalized = PathBuf::new();
    for comp in result.components() {
        use std::path::Component::*;
        match comp {
            CurDir => {}
            ParentDir => {
                normalized.pop();
            }
            Normal(c) => normalized.push(c),
            RootDir => normalized.push(comp.as_os_str()),
            Prefix(_) => normalized.push(comp.as_os_str()),
        }
    }

    normalized
}
