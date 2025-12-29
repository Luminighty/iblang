use crate::codegenqbe::qbe::{BaseTy, ExtTy, Global, Qbe, QbeResult};
use std::io::Write;

#[derive(Debug)]
pub enum QbeDataField {
    Global(Global),
    ExtTy(ExtTy, i64),
    ExtTyF(ExtTy, f64),
    ExtTyArr(ExtTy, Vec<i64>),
    Str(String),
    Zero(usize),
}

impl QbeDataField {
    pub fn bytes(&self) -> usize {
        match self {
            QbeDataField::Global(_) => BaseTy::L.bytes(),
            QbeDataField::ExtTy(ext_ty, _) => ext_ty.bytes(),
            QbeDataField::ExtTyF(ext_ty, _) => ext_ty.bytes(),
            QbeDataField::ExtTyArr(ext_ty, vals) => ext_ty.bytes() * vals.len(),
            QbeDataField::Str(s) => s.len(),
            QbeDataField::Zero(c) => *c,
        }
    }
}

#[derive(Debug)]
pub struct DataBuilder {
    name: Global,
    data: Vec<QbeDataField>,
    is_public: bool,
    pub offset: Vec<usize>,
}

impl DataBuilder {
    pub fn new(name: Global) -> Self {
        Self {
            name,
            is_public: false,
            data: Vec::new(),
            offset: vec![0],
        }
    }

    pub fn set_public(&mut self, is_public: bool) {
        self.is_public = is_public;
    }

    pub fn start_block(&mut self) {
        self.offset.push(0);
    }

    pub fn end_block(&mut self) {
        *self.offset.last_mut().unwrap() += self.offset.pop().unwrap();
    }

    pub fn current_offset(&self) -> usize {
        *self.offset.last().unwrap()
    }

    pub fn push<D: Into<QbeDataField>>(&mut self, data: D) {
        let data = data.into();
        *self.offset.last_mut().unwrap() += data.bytes();
        self.data.push(data);
    }

    pub fn build<W: Write>(self, qbe: &mut Qbe<W>) -> QbeResult<Global> {
        let mut fields = Vec::with_capacity(self.data.len());
        for data in self.data {
            let s = match data {
                QbeDataField::Global(g) => qbe.global(&g)?,
                QbeDataField::ExtTy(ext_ty, val) => format!("{ext_ty} {val}"),
                QbeDataField::Str(s) => format!("b \"{s}\""),
                QbeDataField::ExtTyF(ext_ty, val) => format!("{ext_ty} {val}"),
                QbeDataField::ExtTyArr(ext_ty, items) => format!(
                    "{ext_ty} {}",
                    items
                        .iter()
                        .map(i64::to_string)
                        .collect::<Vec<_>>()
                        .join(" ")
                ),
                QbeDataField::Zero(len) => format!("z {len}"),
            };
            fields.push(s);
        }
        let global_str = qbe.global(&self.name)?;
        let data = format!("data {global_str} = {{ {} }}", fields.join(", "));
        if self.is_public {
            write!(qbe.out, "export ")?;
        }
        writeln!(qbe.out, "{data}")?;

        Ok(self.name)
    }
}

pub struct ZeroInit(pub usize);

impl Into<QbeDataField> for &str {
    fn into(self) -> QbeDataField {
        QbeDataField::Str(self.to_string())
    }
}

impl Into<QbeDataField> for (BaseTy, i64) {
    fn into(self) -> QbeDataField {
        QbeDataField::ExtTy(ExtTy::BASE(self.0), self.1)
    }
}

impl Into<QbeDataField> for (BaseTy, f64) {
    fn into(self) -> QbeDataField {
        QbeDataField::ExtTyF(ExtTy::BASE(self.0), self.1)
    }
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

impl Into<QbeDataField> for (ExtTy, f64) {
    fn into(self) -> QbeDataField {
        QbeDataField::ExtTyF(self.0, self.1)
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
