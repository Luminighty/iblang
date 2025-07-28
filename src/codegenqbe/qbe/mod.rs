mod error;
mod qbe;
mod qbe_fn;
mod qbe_instr;
mod qbe_ty;
mod uid;

#[cfg(test)]
mod tests;

#[derive(Clone, Copy, Debug)]
pub struct Block(uid::UId);
#[derive(Clone, Copy, Debug)]
pub struct Temp(uid::UId);
#[derive(Clone, Copy, Debug)]
pub struct TyIdent(uid::UId);
#[derive(Clone, Copy, Debug)]
pub struct Global(uid::UId);

pub use error::QbeError;
pub use qbe::Qbe;
pub use qbe::QbeResult;
pub use qbe_fn::{CallBuilder, FunctionBuilder};
pub use qbe_instr::ABITy;
pub use qbe_ty::{BaseTy, ExtTy, LoadTy, SubWTy};
