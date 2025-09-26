use crate::{
    ast::{AstModule, Identifier, prelude::AstStructDef},
    utils::Span,
};

use super::{
    TypeIdent,
    checker::TypecheckContext,
    error::{TypecheckError, TypecheckErrorKind},
    statement::typecheck_typeident,
};

#[derive(Debug)]
#[allow(dead_code)]
pub struct StructDef {
    pub identifier: Identifier,
    pub fields: Vec<(String, TypeIdent)>,
    pub span: Span,
    pub align: u32,
    pub size: usize,
    pub field_offsets: Vec<usize>,
}

impl StructDef {
    pub fn typeident(&self) -> TypeIdent {
        TypeIdent::Struct(self.identifier.clone())
    }

    pub fn get_field_idx(&self, field: &str) -> Option<usize> {
        for (i, (key, _)) in self.fields.iter().enumerate() {
            if key == field {
                return Some(i);
            }
        }
        None
    }

    pub fn get_field_type(&self, field: &str) -> Option<&TypeIdent> {
        for (key, ty) in &self.fields {
            if key == field {
                return Some(ty);
            }
        }
        None
    }
}

pub fn typecheck_structdefs(
    context: &mut TypecheckContext,
    ast_module: &AstModule,
    errors: &mut Vec<TypecheckError>,
) {
    // NOTE: We also need to topologically sort all typedefs based on what fields they use
    for s in &ast_module.structs {
        if !context.module.types.insert(s.identifier.to_string()) {
            errors.push(TypecheckError::new(
                TypecheckErrorKind::DuplicateTypeDef,
                s.span,
            ));
        }
    }

    for s in &ast_module.structs {
        typecheck_structdef(context, s, errors);
    }
    // for s in &context.module.struct_defs {
    //     println!("{:?}", s);
    // }
}

fn get_aligned_offset(offset: usize, align: usize) -> usize {
    let padding = offset % align;
    if padding == 0 {
        offset
    } else {
        offset + align - padding
    }
}

fn typecheck_structdef(
    context: &mut TypecheckContext,
    strct: &AstStructDef,
    errors: &mut Vec<TypecheckError>,
) {
    let mut is_ok = true;
    let mut fields = Vec::new();
    let mut max_align = 1;
    let mut field_offsets = Vec::new();
    let mut offset = 0;
    for field in &strct.fields {
        let (size, align) = match typecheck_typeident(context, &field.1, strct.span) {
            Ok(ty) => {
                let size_align = context.module.type_size_and_align(&ty);
                fields.push((field.0.to_string(), ty));
                size_align
            }
            Err(err) => {
                is_ok = false;
                errors.push(err);
                continue;
            }
        };
        // NOTE: Numbers will become invalid if a typeident is invalid, but we don't really care
        //  for those structs
        max_align = usize::max(max_align, align as usize);
        offset = get_aligned_offset(offset, align as usize);
        field_offsets.push(offset);
        offset += size;
    }
    let size = get_aligned_offset(offset, max_align).max(1);
    if is_ok {
        context.module.struct_defs.push(StructDef {
            identifier: strct.identifier.to_string(),
            fields,
            span: strct.span,
            size,
            align: max_align as u32,
            field_offsets,
        });
    }
}
