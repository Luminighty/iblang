use std::collections::HashMap;
use std::rc::Rc;

use super::{
    CastMethod, FlowType, TypeIdent, TypeResult,
    binary::typecheck_binary,
    checker::{TypecheckFuncContext, TypecheckMode},
    error::{TypecheckError, TypecheckErrorKind},
    expr_array::array,
    unary::typecheck_unary,
};
use crate::{
    ast::prelude::*,
    symbol_resolver::{ModuleUID, Symbol, SymbolError, SymbolKind, SymbolUID},
    typecheck::{
        atomic::{Atomic, Numeric},
        checker::{IdentifierResult, TypecheckContext, resolve_identifier},
        expr_object::object_init,
        expr_struct::struct_init,
        global,
        module::type_size_and_align,
        statement::typecheck_typeident,
        type_enum::EnumDef,
    },
    utils::Span,
};

#[derive(Debug, Copy, Clone, PartialEq, Eq)]
pub enum ValueKind {
    RValue,
    LValue,
}

#[derive(Debug)]
pub struct Expr {
    pub span: Span,
    pub kind: ExprKind,
    pub value_kind: ValueKind,
}

#[derive(Debug)]
pub enum ExprKind {
    Literal(Literal, TypeIdent),
    Variable(Identifier, TypeIdent),
    Global(SymbolUID, TypeIdent),
    Assign {
        lhs: Box<Expr>,
        rhs: Box<Expr>,
        ty: TypeIdent,
    },
    ArithAssign {
        lhs: Box<Expr>,
        rhs: Box<Expr>,
        op: BinaryArith,
        ty: TypeIdent,
    },
    BinaryPred {
        op: BinaryPred,
        lhs: Box<Expr>,
        rhs: Box<Expr>,
        shared: TypeIdent,
    },
    BinaryArith {
        op: BinaryArith,
        lhs: Box<Expr>,
        rhs: Box<Expr>,
        ty: TypeIdent,
    },
    Unary {
        op: UnaryArith,
        expr: Box<Expr>,
        ty: TypeIdent,
    },
    Call {
        callee: Box<Expr>,
        args: Vec<(Expr, TypeIdent)>,
        varargs: Vec<(Expr, TypeIdent)>,
        ty: FlowType,
    },
    Cast {
        expr: Box<Expr>,
        target: TypeIdent,
        origin: TypeIdent,
        method: CastMethod,
    },
    Array {
        values: Vec<Expr>,
        ty: TypeIdent,
    },
    StructInit {
        values: Vec<(String, Expr)>,
        ty: TypeIdent,
    },
    UnionInit {
        field: String,
        value: Box<Expr>,
        ty: TypeIdent,
    },
    Index {
        index: Box<Expr>,
        expr: Box<Expr>,
        ty: TypeIdent,
    },
    UnionFieldLookup {
        obj: Box<Expr>,
        field: Identifier,
        union_ty: TypeIdent,
        ty: TypeIdent,
    },
    StructFieldLookup {
        obj: Box<Expr>,
        field: Identifier,
        struct_ty: TypeIdent,
        ty: TypeIdent,
    },
    ObjectCopy {
        expr: Box<Expr>,
        ty: TypeIdent,
    },
    Deref {
        expr: Box<Expr>,
        ty: TypeIdent,
    },
    Ref {
        expr: Box<Expr>,
        ty: TypeIdent,
    },
    Load {
        expr: Box<Expr>,
        ty: TypeIdent,
    },
}

pub fn typecheck_expr(
    global_context: &mut TypecheckContext,
    context: &TypecheckFuncContext,
    expr: &AstExpr,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    match &expr.kind {
        AstExprKind::Literal(l) => literal(l, expr.span, mode),
        AstExprKind::Ident(i) => ident(global_context, context, i.to_string(), expr.span, mode),
        AstExprKind::Binary { op, lhs, rhs } => {
            typecheck_binary(global_context, context, *op, &lhs, &rhs, expr.span, mode)
        }
        AstExprKind::Unary { op, expr } => {
            typecheck_unary(global_context, context, *op, expr, expr.span, mode)
        }
        AstExprKind::Call { callee, args } => {
            call(global_context, context, callee, args, expr.span, mode)
        }
        AstExprKind::Array { values } => array(global_context, context, values, expr.span, mode),
        AstExprKind::ObjectInit { identifier, fields } => {
            object_init(global_context, context, identifier, fields, expr.span, mode)
        }
        AstExprKind::SizeOf(ty) => typecheck_sizeof(global_context, context, ty, expr.span, mode),
    }
}

fn literal(l: &Literal, span: Span, mode: &TypecheckMode) -> TypeResult<Expr> {
    Ok(Expr {
        value_kind: ValueKind::RValue,
        span,
        kind: ExprKind::Literal(l.clone(), l.into()),
    })
}

pub fn as_identifier(module: ModuleUID, expr: &AstExpr, span: Span) -> TypeResult<Identifier> {
    match &expr.kind {
        AstExprKind::Ident(i) => Ok(i.to_string()),
        _ => Err(TypecheckError::new(
            TypecheckErrorKind::IdentifierExpected,
            module,
            span,
        )),
    }
}

pub fn load_expr(expr: Expr, ty: &TypeIdent) -> Expr {
    match ty {
        TypeIdent::Union(_) | TypeIdent::Struct(_) => Expr {
            value_kind: ValueKind::RValue,
            span: expr.span,
            kind: ExprKind::ObjectCopy {
                expr: Box::new(expr),
                ty: ty.clone(),
            },
        },
        TypeIdent::Enum(_)
        | TypeIdent::Atomic(_)
        | TypeIdent::Array(_, _)
        | TypeIdent::Ref(_)
        | TypeIdent::Fn { .. } => Expr {
            value_kind: ValueKind::RValue,
            span: expr.span,
            kind: ExprKind::Load {
                expr: Box::new(expr),
                ty: ty.clone(),
            },
        },
    }
}

pub fn get_enum_literal(
    module_id: &ModuleUID,
    symbol: &Symbol,
    field: &Identifier,
    span: Span,
) -> TypeResult<Literal> {
    let ty: Rc<EnumDef> = match symbol.deep_enum() {
        Ok(ty) => ty,
        Err(err) => {
            return Err(TypecheckError::new(
                TypecheckErrorKind::SymbolError(err),
                *module_id,
                span,
            ));
        }
    };
    let value = match ty.get_field_value(&field) {
        Some(v) => v,
        None => {
            return Err(TypecheckError::new(
                TypecheckErrorKind::EnumVariantNotFound {
                    variant: field.to_string(),
                },
                *module_id,
                span,
            ));
        }
    };
    Ok(Literal::Number(value as i64))
}

pub fn ident(
    global_context: &mut TypecheckContext,
    context: &TypecheckFuncContext,
    identifier: Identifier,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let module = global_context.modules.get(&context.module_id).unwrap();
    let binding = context.bindings.get(&identifier);
    let global_symbol = resolve_identifier(global_context, &context.module_id, &identifier, &span);

    let (expr, ty) = match (global_context.path_stack.len(), binding, global_symbol) {
        (0, Some(bind), _) => {
            if !bind.mutable && mode.value_kind == ValueKind::LValue {
                return Err(TypecheckError::new(
                    TypecheckErrorKind::AssignmentToConst,
                    context.module_id,
                    span,
                ));
            }
            let expr = Expr {
                value_kind: ValueKind::LValue,
                span,
                kind: ExprKind::Variable(identifier, bind.ty.clone()),
            };
            (expr, &bind.ty)
        }
        (_, _, IdentifierResult::SubField(symbol_id, field)) => {
            let symbol: &Symbol = global_context.symbol_table.get_symbol(&symbol_id).unwrap();
            match symbol.kind {
                SymbolKind::Enum => {
                    let literal = get_enum_literal(&context.module_id, symbol, &field, span)?;
                    let ty = TypeIdent::Enum(symbol_id);
                    let expr = Expr {
                        value_kind: ValueKind::RValue,
                        span,
                        kind: ExprKind::Literal(literal, ty.clone()),
                    };
                    (expr, &ty.clone())
                }
                SymbolKind::Struct
                | SymbolKind::Union
                | SymbolKind::Global
                | SymbolKind::Function => todo!(),
            }
        }
        (_, _, IdentifierResult::Symbol(symbol)) => {
            let global: &Symbol = global_context.symbol_table.get_symbol(&symbol).unwrap();
            macro_rules! symbol_err {
                ($err: expr) => {
                    Err(TypecheckError::new(
                        TypecheckErrorKind::SymbolError($err),
                        context.module_id,
                        span,
                    ))
                };
            }
            let (ty, value_kind) = match global.kind {
                SymbolKind::Global => match global.deep_global() {
                    Ok(ty) => (ty, ValueKind::LValue),
                    Err(err) => return symbol_err!(err),
                },
                SymbolKind::Function => match global.deep_proto_typeident() {
                    Ok(proto) => (proto, ValueKind::RValue),
                    Err(err) => return symbol_err!(err),
                },
                _ => {
                    return symbol_err!(SymbolError::SymbolKindNotMatched {
                        expected: SymbolKind::Global,
                        got: global.kind,
                        symbol: symbol
                    });
                }
            };
            let expr = Expr {
                value_kind,
                span,
                kind: ExprKind::Global(symbol, (*ty).clone()),
            };
            (expr, &*ty.clone())
        }
        (0, _, IdentifierResult::Err(err)) => match err.unwrap_symbol_error() {
            SymbolError::SymbolNotFound(_) => {
                return Err(TypecheckError::new(
                    TypecheckErrorKind::UndeclaredVariable(identifier),
                    context.module_id,
                    span,
                ));
            }
            _ => return Err(err),
        },
        (_, _, IdentifierResult::Err(err)) => return Err(err),
    };
    let expr = match (mode.value_kind, ty) {
        (ValueKind::LValue, _) => expr,
        (_, TypeIdent::Array(_, _)) => expr,
        // NOTE: We don't load structs, since they are passed by value
        (ValueKind::LValue, TypeIdent::Struct(_)) => expr,
        (ValueKind::LValue, TypeIdent::Union(_)) => expr,
        // NOTE: Enums are like literals, no loading needed
        (_, TypeIdent::Enum(_)) if expr.value_kind == ValueKind::RValue => expr,
        (_, TypeIdent::Fn { .. }) if expr.value_kind == ValueKind::RValue => expr,
        _ => load_expr(expr, &ty),
    };
    Ok(expr)
}

fn call(
    global_context: &mut TypecheckContext,
    context: &TypecheckFuncContext,
    callee: &AstExpr,
    args: &Vec<AstExpr>,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let callee_span = callee.span;
    let callee = as_identifier(context.module_id, callee, span)?;
    let callee = ident(
        global_context,
        &context,
        callee,
        span,
        &TypecheckMode::rvalue(),
    )?;
    let callee_ty = unwrap_typeident(context.module_id, expr_type(&callee), span)?;

    let (proto_args, has_varargs, ret_type) = match callee_ty {
        TypeIdent::Fn {
            args,
            has_varargs,
            return_type,
        } => (args, has_varargs, return_type),
        _ => panic!("Unexpected callee kind {}", callee.kind),
    };

    if proto_args.len() != args.len() && !has_varargs {
        return Err(TypecheckError::new(
            TypecheckErrorKind::InvalidFunctionArgCount,
            context.module_id,
            span,
        ));
    }

    let mut checked_args = Vec::new();
    let mut varargs = Vec::with_capacity(args.len() - proto_args.len());
    for (i, arg) in args.iter().enumerate() {
        let arg = typecheck_expr(global_context, context, arg, &TypecheckMode::rvalue())?;
        let arg_type = unwrap_typeident(context.module_id, expr_type(&arg), arg.span)?;
        if proto_args.len() > i {
            let arg = try_cast(context, arg, arg_type, proto_args[i].clone())?;
            checked_args.push((arg, proto_args[i].clone()))
        } else {
            varargs.push((arg, arg_type))
        }
    }
    let ret_type = *ret_type.clone();
    // TODO: Check argument amount, and collect all the invalid args

    Ok(Expr {
        span,
        value_kind: ValueKind::LValue,
        kind: ExprKind::Call {
            callee: Box::new(callee),
            args: checked_args,
            varargs,
            ty: ret_type,
        },
    })
}

fn typecheck_sizeof(
    global_context: &mut TypecheckContext,
    context: &TypecheckFuncContext,
    ty: &AstTypeIdent,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let ty = typecheck_typeident(
        global_context,
        &context.module_id,
        ty,
        span,
        false,
        &mut Vec::new(),
    )?;
    let (size, align) = type_size_and_align(&ty, global_context.symbol_table);
    return Ok(Expr {
        span,
        value_kind: ValueKind::RValue,
        kind: ExprKind::Literal(
            Literal::Number(size as i64),
            TypeIdent::Atomic(Atomic::Number(Numeric::Int)),
        ),
    });
}

pub fn try_cast(
    context: &TypecheckFuncContext,
    e: Expr,
    from: TypeIdent,
    into: TypeIdent,
) -> TypeResult<Expr> {
    match TypeIdent::try_cast_into(&from, &into) {
        Ok(CastMethod::Keep) => Ok(e),
        Ok(x) => Ok(Expr {
            span: e.span,
            value_kind: e.value_kind,
            kind: ExprKind::Cast {
                expr: Box::new(e),
                target: into,
                origin: from,
                method: x,
            },
        }),
        Err(_) => Err(TypecheckError::new(
            TypecheckErrorKind::InvalidCast { from, into },
            context.module_id,
            e.span,
        )),
    }
}

pub fn expr_type(expr: &Expr) -> FlowType {
    match &expr.kind {
        ExprKind::Literal(_, ty) => ty.into(),
        ExprKind::Variable(_, ty) => ty.into(),
        ExprKind::Global(_, ty) => ty.into(),
        ExprKind::BinaryArith { ty, .. } => ty.into(),
        ExprKind::ArithAssign { ty, .. } => ty.into(),
        ExprKind::Assign { ty, .. } => ty.into(),
        ExprKind::BinaryPred { .. } => (&TypeIdent::Atomic(Atomic::bool())).into(),
        ExprKind::Unary { ty, .. } => ty.into(),
        ExprKind::Call { ty, .. } => ty.clone(),
        ExprKind::Cast { target, .. } => target.into(),
        ExprKind::Load { ty, .. } => ty.into(),
        ExprKind::Ref { ty, .. } => ty.into(),
        ExprKind::Deref { ty, .. } => ty.into(),
        ExprKind::Array { ty, .. } => ty.into(),
        ExprKind::Index { ty, .. } => ty.into(),
        ExprKind::StructInit { ty, .. } => ty.into(),
        ExprKind::UnionInit { ty, .. } => ty.into(),
        ExprKind::UnionFieldLookup { ty, .. } => ty.into(),
        ExprKind::StructFieldLookup { ty, .. } => ty.into(),
        ExprKind::ObjectCopy { expr, ty } => ty.into(),
    }
}

pub fn unwrap_ref(module: ModuleUID, ty: TypeIdent, span: Span) -> TypeResult<TypeIdent> {
    match ty {
        TypeIdent::Ref(ty) => Ok(*ty),
        _ => Err(TypecheckError::new(
            TypecheckErrorKind::ReferenceExpected,
            module,
            span,
        )),
    }
}

pub fn unwrap_typeident(module: ModuleUID, flow: FlowType, span: Span) -> TypeResult<TypeIdent> {
    match flow {
        FlowType::Some(ty) => Ok(ty),
        _ => Err(TypecheckError::new(
            TypecheckErrorKind::ValueExpected,
            module,
            span,
        )),
    }
}

impl Expr {
    pub fn write(&self, f: &mut dyn std::io::Write, depth: usize) -> std::io::Result<()> {
        self.kind.write(f, depth)
    }
}

impl ExprKind {
    pub fn write(&self, f: &mut dyn std::io::Write, depth: usize) -> std::io::Result<()> {
        let pad = " ".repeat(depth);
        match self {
            ExprKind::Literal(literal, _) => writeln!(f, "{pad}{}", literal),
            ExprKind::Variable(ident, _) => writeln!(f, "{pad}{}", ident),
            ExprKind::Global(ident, _) => writeln!(f, "{pad}{}", ident),
            ExprKind::BinaryArith { op, lhs, rhs, .. } => {
                lhs.kind.write(f, depth + 1)?;
                writeln!(f, "{pad}{}", op)?;
                rhs.kind.write(f, depth + 1)
            }
            ExprKind::ArithAssign { op, lhs, rhs, .. } => {
                lhs.kind.write(f, depth + 1)?;
                writeln!(f, "{pad}{}=", op)?;
                rhs.kind.write(f, depth + 1)
            }
            ExprKind::BinaryPred { op, lhs, rhs, .. } => {
                lhs.kind.write(f, depth + 1)?;
                writeln!(f, "{pad}{}", op)?;
                rhs.kind.write(f, depth + 1)
            }
            ExprKind::Unary { op, expr, .. } => {
                write!(f, "{pad}{}", op)?;
                expr.kind.write(f, depth + 1)
            }
            ExprKind::Call { callee, args, .. } => {
                writeln!(f, "{pad}{}(", callee)?;
                for (_, arg) in args.iter().enumerate() {
                    arg.0.kind.write(f, depth + 1)?;
                }
                writeln!(f, "{pad})")
            }
            ExprKind::Load { expr, .. } => expr.kind.write(f, depth),
            ExprKind::Array { values, .. } => {
                writeln!(f, "{pad}[")?;
                for (_, arg) in values.iter().enumerate() {
                    arg.kind.write(f, depth + 1)?;
                }
                writeln!(f, "{pad}]")
            }
            #[allow(unused)]
            ExprKind::Assign { lhs, rhs, ty } => {
                lhs.kind.write(f, depth + 1)?;
                writeln!(f, "{pad}=")?;
                rhs.kind.write(f, depth + 1)
            }
            ExprKind::Cast {
                expr,
                target,
                origin,
                method,
            } => {
                writeln!(f, "{pad}{} {method:?}", target)?;
                expr.kind.write(f, depth + 1)
            }
            #[allow(unused)]
            ExprKind::Index { index, expr, ty } => {
                expr.kind.write(f, depth + 1)?;
                writeln!(f, "{pad}[]")?;
                index.kind.write(f, depth + 1)
            }
            #[allow(unused)]
            ExprKind::Deref { expr, ty } => {
                writeln!(f, "{pad}*")?;
                expr.kind.write(f, depth + 1)
            }
            #[allow(unused)]
            ExprKind::Ref { expr, ty } => {
                writeln!(f, "{pad}&(")?;
                expr.kind.write(f, depth + 1)?;
                write!(f, ")")
            }
            ExprKind::UnionInit { field, value, ty } => {
                write!(f, "{pad}{ty} {{ {field}: ")?;
                value.kind.write(f, depth + 1)?;
                write!(f, " }}")
            }
            ExprKind::StructInit { values, ty } => {
                writeln!(f, "{pad}{ty} {{")?;
                for (key, val) in values.iter() {
                    write!(f, "{pad}{key}: ")?;
                    val.kind.write(f, depth + 1)?;
                }
                writeln!(f, "{pad}}}")
            }
            ExprKind::StructFieldLookup { obj, field, .. } => {
                obj.kind.write(f, depth)?;
                write!(f, ".{field}")
            }
            ExprKind::UnionFieldLookup { obj, field, .. } => {
                obj.kind.write(f, depth)?;
                write!(f, ".{field}")
            }
            ExprKind::ObjectCopy { expr, ty } => write!(f, "{expr}"),
        }
    }
}
