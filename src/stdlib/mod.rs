const stdlib: &str = include_str!("./stdlib.ib");

pub fn read_stdlib(file: &str) -> Option<&str> {
    match file {
        "stdlib.ib" => Some(stdlib),
        _ => None,
    }
}
