use std::path::{Path, PathBuf};

pub fn join_relative(base: &str, rel: &str) -> PathBuf {
    let base = Path::new(base);
    let rel = Path::new(rel);

    let mut result = PathBuf::new();

    // start at base's parent
    result.push(base.parent().unwrap());

    // apply relative import
    result.push(rel);

    // normalize (remove `..` and `.` logically, but keep relative)
    let mut normalized = PathBuf::new();
    for comp in result.components() {
        use std::path::Component::*;
        match comp {
            CurDir => {}
            ParentDir => {
                normalized.pop();
            }
            Normal(c) => normalized.push(c),
            RootDir => normalized.push(comp.as_os_str()), // shouldn't happen in your case
            Prefix(_) => normalized.push(comp.as_os_str()), // Windows only
        }
    }

    normalized
}
