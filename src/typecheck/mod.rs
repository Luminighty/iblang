pub mod atomic;
mod types;

use error::TypecheckError;
pub use types::*;

use crate::utils::Bindings;

mod expr;
mod module;
mod statement;
mod error;
mod checker;
mod binary;

pub type TypeResult<T> = Result<T, TypecheckError>;
pub type TypeBinding = Bindings<TypeIdent>;

