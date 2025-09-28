use crate::codegenqbe::qbe::{BaseTy, ExtTy, Global, Qbe, QbeResult};
use std::io::Write;

pub enum QbeDataField {
    Global(Global),
    ExtTy(ExtTy, i64),
    ExtTyF(ExtTy, f64),
    ExtTyArr(ExtTy, Vec<i64>),
    Zero(usize),
}

pub struct DataBuilder {
    name: Global,
    data: Vec<QbeDataField>,
}

impl DataBuilder {
    pub fn new(name: Global) -> Self {
        Self {
            name,
            data: Vec::new(),
        }
    }

    pub fn push<D: Into<QbeDataField>>(&mut self, data: D) {
        self.data.push(data.into());
    }

    pub fn build<W: Write>(mut self, qbe: &mut Qbe<W>) -> QbeResult<Global> {
        let mut fields = Vec::with_capacity(self.data.len());
        for data in self.data {
            let s = match data {
                QbeDataField::Global(g) => qbe.global(&g)?,
                QbeDataField::ExtTy(ext_ty, val) => format!("{ext_ty} {val}"),
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
        writeln!(qbe.out, "{data}")?;

        Ok(self.name)
    }
}

pub struct ZeroInit(usize);

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
