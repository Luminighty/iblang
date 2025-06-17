use super::uid::UId;

#[derive(Debug)]
pub enum QbeError {
    IOError(std::io::Error),
    FmtError(std::fmt::Error),
    UnknownUid(UId),
}

impl From<std::fmt::Error> for QbeError {
    fn from(value: std::fmt::Error) -> Self {
        QbeError::FmtError(value)
    }
}
impl From<std::io::Error> for QbeError {
    fn from(value: std::io::Error) -> Self {
        QbeError::IOError(value)
    }
}
