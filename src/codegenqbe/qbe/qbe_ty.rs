use super::{
    Global, TyIdent,
    qbe::{Qbe, QbeResult},
};
use std::io::Write;

pub enum BaseTy {
    W,
    L,
    S,
    D,
}

pub enum SubWTy {
    SB,
    UB,
    SH,
    UH,
}

pub struct ZeroInit(usize);

pub enum ExtTy {
    BASE(BaseTy),
    B,
    H,
}

pub enum QbeTypeField {
    TyIdent(TyIdent),
    TyIdentArr(TyIdent, usize),
    ExtTy(ExtTy),
    ExtTyArr(ExtTy, usize),
}

pub enum QbeDataField {
    Global(Global),
    ExtTy(ExtTy, i64),
    ExtTyArr(ExtTy, Vec<i64>),
    Zero(usize),
}

impl Into<QbeDataField> for ZeroInit {
    fn into(self) -> QbeDataField {
        QbeDataField::Zero(self.0)
    }
}

impl Into<QbeDataField> for (ExtTy, i64) {
    fn into(self) -> QbeDataField {
        QbeDataField::ExtTy(self.0, self.1)
    }
}

impl Into<QbeDataField> for (ExtTy, Vec<i64>) {
    fn into(self) -> QbeDataField {
        QbeDataField::ExtTyArr(self.0, self.1)
    }
}

impl Into<QbeDataField> for Global {
    fn into(self) -> QbeDataField {
        QbeDataField::Global(self)
    }
}

impl Into<ExtTy> for BaseTy {
    fn into(self) -> ExtTy {
        ExtTy::BASE(self)
    }
}

impl Into<QbeTypeField> for TyIdent {
    fn into(self) -> QbeTypeField {
        QbeTypeField::TyIdent(self)
    }
}
impl Into<QbeTypeField> for (TyIdent, usize) {
    fn into(self) -> QbeTypeField {
        QbeTypeField::TyIdentArr(self.0, self.1)
    }
}

impl Into<QbeTypeField> for BaseTy {
    fn into(self) -> QbeTypeField {
        QbeTypeField::ExtTy(self.into())
    }
}

impl Into<QbeTypeField> for (BaseTy, usize) {
    fn into(self) -> QbeTypeField {
        QbeTypeField::ExtTyArr(self.0.into(), self.1)
    }
}

impl Into<QbeTypeField> for ExtTy {
    fn into(self) -> QbeTypeField {
        QbeTypeField::ExtTy(self)
    }
}

impl Into<QbeTypeField> for (ExtTy, usize) {
    fn into(self) -> QbeTypeField {
        QbeTypeField::ExtTyArr(self.0, self.1)
    }
}

impl<W: Write> Qbe<W> {
    pub fn tyident(&mut self, ident: TyIdent) -> QbeResult<String> {
        let ident = self.idents.get(&ident.0)?;
        Ok(format!(":{ident}"))
    }

    pub fn create_type<T>(&mut self, ident: &str, fields: Vec<T>) -> QbeResult<TyIdent>
    where
        T: Into<QbeTypeField>,
    {
        let ident = self.idents.create(ident);
        let ident_str = self.idents.get(&ident)?;
        write!(self.out, "type :{ident_str} = {{ ")?;
        for field in fields {
            match field.into() {
                QbeTypeField::TyIdent(ident) => {
                    let ident = self.idents.get(&ident.0)?;
                    write!(self.out, "{ident}, ")?;
                }
                QbeTypeField::TyIdentArr(ident, len) => {
                    let ident = self.idents.get(&ident.0)?;
                    write!(self.out, "{ident} {len}, ")?;
                }
                QbeTypeField::ExtTy(ext_ty) => {
                    write!(self.out, "{ext_ty}, ")?;
                }
                QbeTypeField::ExtTyArr(ext_ty, len) => {
                    write!(self.out, "{ext_ty} {len}, ")?;
                }
            }
            write!(self.out, "type :{ident_str} = {{")?;
        }
        writeln!(self.out, "}}")?;
        Ok(TyIdent(ident))
    }
}

impl std::fmt::Display for SubWTy {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "{}",
            match self {
                SubWTy::SB => "sb",
                SubWTy::UB => "ub",
                SubWTy::SH => "sh",
                SubWTy::UH => "uh",
            }
        )
    }
}
impl std::fmt::Display for BaseTy {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "{}",
            match self {
                BaseTy::W => "w",
                BaseTy::L => "l",
                BaseTy::S => "s",
                BaseTy::D => "d",
            }
        )
    }
}
impl std::fmt::Display for ExtTy {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            ExtTy::BASE(base_ty) => write!(f, "{base_ty}"),
            ExtTy::B => write!(f, "b"),
            ExtTy::H => write!(f, "h"),
        }
    }
}
