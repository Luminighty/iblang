use std::collections::HashMap;
use std::rc::Rc;

use super::{
    CastMethod, FlowType, TypeIdent, TypeResult,
    binary::typecheck_binary,
    checker::{TypecheckFuncContext, TypecheckMode},
    error::{TypecheckError, TypecheckErrorKind},
    expr::Expr,
    unary::typecheck_unary,
};
use crate::{
    ast::prelude::*,
    symbol_resolver::SymbolKind,
    typecheck::{
        checker::{TypecheckContext, resolve_identifier},
        expr::{
            ExprKind, ValueKind, as_identifier, expr_type, ident, load_expr, try_cast,
            typecheck_expr, unwrap_typeident,
        },
        expr_struct::{self, struct_init},
        expr_union::{self, union_init},
        type_struct::StructDef,
    },
    utils::Span,
};

pub fn object_init(
    global_context: &mut TypecheckContext,
    context: &TypecheckFuncContext,
    ty: &Identifier,
    fields: &Vec<AstObjectInitField>,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let type_id = resolve_identifier(global_context, &context.module_id, ty, &span)?;
    let kind = global_context
        .symbol_table
        .get_symbol(&type_id)
        .unwrap()
        .kind;
    match kind {
        SymbolKind::Function | SymbolKind::Global => panic!("Invalid symbol type!"),
        SymbolKind::Union => union_init(global_context, context, type_id, fields, span, mode),
        SymbolKind::Struct => struct_init(global_context, context, type_id, fields, span, mode),
    }
}

pub fn field_lookup(
    global_context: &mut TypecheckContext,
    context: &TypecheckFuncContext,
    lhs: &AstExpr,
    rhs: &AstExpr,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let obj_span = lhs.span;
    let obj = typecheck_expr(global_context, context, lhs, &TypecheckMode::lvalue())?;
    let field = as_identifier(context.module_id, rhs, rhs.span)?;
    let mut obj_ty = unwrap_typeident(context.module_id, expr_type(&obj), obj.span)?;

    macro_rules! object_expected {
        () => {
            Err(TypecheckError::new(
                TypecheckErrorKind::ObjectExpected {
                    got: obj_ty.clone(),
                },
                context.module_id,
                obj_span,
            ));
        };
    }
    macro_rules! lookup {
        ($func: path, $ctor: path, $ty: expr, $is_ref: expr) => {{
            let obj_ty = $ctor($ty.clone());
            $func(
                global_context,
                context,
                obj,
                $ty,
                obj_ty,
                field,
                $is_ref,
                span,
                mode,
            )
        }};
    }

    match &obj_ty {
        TypeIdent::Ref(ty) => match **ty {
            TypeIdent::Struct(ty) => {
                lookup!(expr_struct::field_lookup, TypeIdent::Struct, ty, true)
            }
            TypeIdent::Union(ty) => lookup!(expr_union::field_lookup, TypeIdent::Union, ty, true),
            _ => object_expected!(),
        },
        TypeIdent::Struct(ty) => lookup!(expr_struct::field_lookup, TypeIdent::Struct, *ty, false),
        TypeIdent::Union(ty) => lookup!(expr_union::field_lookup, TypeIdent::Union, *ty, false),
        _ => object_expected!(),
    }
}
