use crate::{
    ast::Identifier,
    codegenllvm::error::CompilerErrorKind,
    log,
    typecheck::{prelude::*, type_struct::StructDef},
    utils::Span,
};

use super::{compiler::Compiler, expr::CompileExprResult, typedvalue::TypedValue};

impl<'ctx> Compiler<'ctx> {
    pub fn compile_struct_def(&mut self, struct_def: &StructDef) {
        let field_types: Vec<_> = struct_def
            .fields
            .iter()
            .map(|(_, ty)| self.inkwell_type(ty))
            .collect();
        let ty = self.context.struct_type(&field_types, false);
        self.struct_types.insert(struct_def.typeident(), ty);
    }

    pub fn compile_struct_init(
        &mut self,
        module: &Module,
        values: &Vec<(String, Expr)>,
        ty: &TypeIdent,
        _span: Span,
    ) -> CompileExprResult<'ctx> {
        let mut vals = Vec::with_capacity(values.len());
        for (_, v) in values {
            let value = self.compile_expr(module, v)?;
            let val = self.load_value(value, CompilerErrorKind::ValueExpected, v.span, "field")?;
            vals.push(val);
        }
        let struct_ty = self.struct_types.get(ty).unwrap().clone();
        let (alloca, align) = self.create_entry_block_alloca(module, "struct", ty);
        for (i, val) in vals.into_iter().enumerate() {
            let gep = unsafe {
                self.builder
                    .build_in_bounds_gep(
                        struct_ty,
                        alloca,
                        &[
                            self.context.i64_type().const_zero(),
                            self.context.i64_type().const_int(i as u64, false),
                        ],
                        &format!("struct_elem_ptr_{}", i),
                    )
                    .unwrap()
            };
            log!(self, "STRUCT INIT {val:?}");
            if val.is_array() || val.is_struct() {
                let pointee_ty = self.inkwell_type(&val.typeident);
                let value = self
                    .builder
                    .build_load(
                        pointee_ty,
                        val.value.into_pointer_value(),
                        "struct_field_load",
                    )
                    .unwrap();
                self.builder.build_store(gep, value).unwrap();
            } else {
                self.builder.build_store(gep, val.value).unwrap();
            }
        }

        Ok(TypedValue::new(alloca.into(), ty.clone()).into())
    }

    pub fn compile_field_lookup(
        &mut self,
        module: &Module,
        obj: &Expr,
        field: &Identifier,
        _ty: &TypeIdent,
        span: Span,
    ) -> CompileExprResult<'ctx> {
        let obj_span = obj.span;
        let obj = self.compile_expr(module, obj)?;
        let obj = self.load_value(obj, CompilerErrorKind::ValueExpected, obj_span, "object")?;

        log!(self, "field lookup '{field}' {obj:?}");

        let (struct_ty, field_ty, index) = match obj.typeident {
            TypeIdent::Ref(ty) => {
                let struct_ty = ty.clone();
                match *ty {
                    TypeIdent::Struct(ident) => {
                        let struct_def = module.get_struct(&ident).unwrap();
                        let idx = struct_def.get_field_idx(field).unwrap();
                        let field_ty = Box::new(struct_def.fields[idx].1.clone());
                        (struct_ty, field_ty, idx)
                    }
                    other => {
                        return self.error(
                            CompilerErrorKind::InvalidStructType { ty: other.clone() },
                            span,
                        );
                    }
                }
            }
            TypeIdent::Struct(ref ident) => {
                let struct_def = module.get_struct(&ident).unwrap();
                let idx = struct_def.get_field_idx(field).unwrap();
                let field_ty = Box::new(struct_def.fields[idx].1.clone());
                (Box::new(obj.typeident.clone()), field_ty, idx)
            }
            other => {
                return self.error(
                    CompilerErrorKind::InvalidStructType { ty: other.clone() },
                    span,
                );
            }
        };

        let struct_ty = self.inkwell_type(&struct_ty);
        let obj = obj.value.into_pointer_value();
        let field_ptr = self
            .builder
            .build_struct_gep(struct_ty, obj, index as u32, "field_lookup")
            .unwrap();
        Ok(TypedValue::new(field_ptr.into(), TypeIdent::Ref(field_ty)).into())
    }
}
