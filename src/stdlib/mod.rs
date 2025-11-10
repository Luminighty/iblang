const STDLIB: &str = include_str!("./stdlib.ib");

pub fn read_stdlib(file: &str) -> Option<&str> {
    if !is_lib_import(file) {
        return None;
    }
    let file = if let Some(file) = file.strip_suffix(".ib") {
        file
    } else {
        file
    };
    match file {
        "@stdlib" => Some(STDLIB),
        _ => None,
    }
}

pub fn is_lib_import(import: &str) -> bool {
    import.starts_with("@")
}
