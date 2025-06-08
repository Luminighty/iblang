#[macro_export]
macro_rules! log {
    ($self: expr, $($arg:tt)*) => {
        if $self.log_enabled {
            println!($($arg)+);
        }
    };
}
