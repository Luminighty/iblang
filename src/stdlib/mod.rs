const STDLIB: &str = include_str!("./stdlib.ib");

pub fn read_stdlib(file: &str) -> Option<&str> {
    match file {
        "stdlib.ib" => Some(STDLIB),
        _ => None,
    }
}
