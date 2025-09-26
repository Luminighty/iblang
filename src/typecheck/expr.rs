use std::collections::HashMap;

use super::{
    CastMethod, FlowType, TypeIdent, TypeResult,
    binary::typecheck_binary,
    checker::{TypecheckContext, TypecheckMode},
    error::{TypecheckError, TypecheckErrorKind},
    expr_array::array,
    unary::typecheck_unary,
};
use crate::{ast::prelude::*, typecheck::expr_struct::struct_init, utils::Span};

#[derive(Debug, Copy, Clone)]
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
    Assign {
        lhs: Box<Expr>,
        rhs: Box<Expr>,
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
        callee: Identifier,
        args: Vec<(Expr, TypeIdent)>,
        ty: FlowType,
    },
    Cast {
        expr: Box<Expr>,
        target: TypeIdent,
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
    Index {
        index: Box<Expr>,
        expr: Box<Expr>,
        ty: TypeIdent,
    },
    FieldLookup {
        obj: Box<Expr>,
        field: Identifier,
        struct_ty: TypeIdent,
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
    context: &TypecheckContext,
    expr: &AstExpr,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    match &expr.kind {
        AstExprKind::Literal(l) => literal(l, expr.span, mode),
        AstExprKind::Ident(i) => ident(context, i.to_string(), expr.span, mode),
        AstExprKind::Binary { op, lhs, rhs } => {
            typecheck_binary(context, *op, &lhs, &rhs, expr.span, mode)
        }
        AstExprKind::Unary { op, expr } => typecheck_unary(context, *op, expr, expr.span, mode),
        AstExprKind::Call { callee, args } => call(context, callee, args, expr.span, mode),
        AstExprKind::Array { values } => array(context, values, expr.span, mode),
        AstExprKind::StructInit { identifier, fields } => {
            struct_init(context, identifier, fields, expr.span, mode)
        }
    }
}

fn literal(l: &Literal, span: Span, mode: &TypecheckMode) -> TypeResult<Expr> {
    Ok(Expr {
        value_kind: ValueKind::RValue,
        span,
        kind: ExprKind::Literal(l.clone(), l.into()),
    })
}

pub fn as_identifier(expr: &AstExpr, span: Span) -> TypeResult<Identifier> {
    match &expr.kind {
        AstExprKind::Ident(i) => Ok(i.to_string()),
        _ => Err(TypecheckError::new(
            TypecheckErrorKind::IdentifierExpected,
            span,
        )),
    }
}

pub fn load_expr(expr: Expr, ty: &TypeIdent) -> Expr {
    Expr {
        value_kind: ValueKind::RValue,
        span: expr.span,
        kind: ExprKind::Load {
            expr: Box::new(expr),
            ty: ty.clone(),
        },
    }
}

pub fn ident(
    module: &TypecheckContext,
    identifier: Identifier,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    if let Some(ty) = module.bindings.get(&identifier) {
        let expr = Expr {
            value_kind: ValueKind::LValue,
            span,
            kind: ExprKind::Variable(identifier, ty.clone()),
        };
        let expr = match (mode.value_kind, ty) {
            (ValueKind::LValue, _) => expr,
            (_, TypeIdent::Array(_, _)) => expr,
            // (_, TypeIdent::Ref(_)) => expr,
            _ => load_expr(expr, ty),
        };
        Ok(expr)
    } else {
        Err(TypecheckError::new(
            TypecheckErrorKind::UndeclaredVariable(identifier),
            span,
        ))
    }
}

fn call(
    module: &TypecheckContext,
    callee: &AstExpr,
    args: &Vec<AstExpr>,
    span: Span,
    mode: &TypecheckMode,
) -> TypeResult<Expr> {
    let callee = as_identifier(callee, span)?;
    let prototype = match module.prototypes.get(&callee) {
        Some(p) => p,
        None => {
            return Err(TypecheckError::new(
                TypecheckErrorKind::UndefinedFunction(callee),
                span,
            ));
        }
    };

    if prototype.args.len() != args.len() {
        return Err(TypecheckError::new(
            TypecheckErrorKind::InvalidFunctionArgCount,
            span,
        ));
    }

    let mut checked_args = Vec::new();
    for (i, arg) in args.iter().enumerate() {
        let arg = typecheck_expr(module, arg, &TypecheckMode::rvalue())?;
        let arg_type = unwrap_typeident(expr_type(&arg), arg.span)?;
        // let arg = arg.auto_deref(arg_type);
        // let arg_type = unwrap_typeident(expr_type(&arg), arg.span)?;

        let arg = try_cast(arg, arg_type, prototype.args[i].1.clone())?;
        checked_args.push((arg, prototype.args[i].1.clone()))
    }
    // TODO: Check argument amount, and collect all the invalid args

    Ok(Expr {
        span,
        value_kind: ValueKind::LValue,
        kind: ExprKind::Call {
            callee,
            args: checked_args,
            ty: prototype.return_type.clone(),
        },
    })
}

pub fn try_cast(e: Expr, from: TypeIdent, into: TypeIdent) -> TypeResult<Expr> {
    match TypeIdent::try_cast_into(&from, &into) {
        Ok(CastMethod::Keep) => Ok(e),
        Ok(x) => Ok(Expr {
            span: e.span,
            value_kind: e.value_kind,
            kind: ExprKind::Cast {
                expr: Box::new(e),
                target: into,
                method: x,
            },
        }),
        Err(_) => Err(TypecheckError::new(
            TypecheckErrorKind::InvalidCast { from, into },
            e.span,
        )),
    }
}

pub fn expr_type(expr: &Expr) -> FlowType {
    match &expr.kind {
        ExprKind::Literal(_, ty) => ty.into(),
        ExprKind::Variable(_, ty) => ty.into(),
        ExprKind::BinaryArith { ty, .. } => ty.into(),
        ExprKind::BinaryPred { shared, .. } => shared.into(),
        ExprKind::Unary { ty, .. } => ty.into(),
        ExprKind::Call { ty, .. } => ty.clone(),
        ExprKind::Cast { target, .. } => target.into(),
        ExprKind::Assign { ty, .. } => ty.into(),
        ExprKind::Load { ty, .. } => ty.into(),
        ExprKind::Ref { ty, .. } => ty.into(),
        ExprKind::Deref { ty, .. } => ty.into(),
        ExprKind::Array { ty, .. } => ty.into(),
        ExprKind::Index { ty, .. } => ty.into(),
        ExprKind::StructInit { ty, .. } => ty.into(),
        ExprKind::FieldLookup { ty, .. } => ty.into(),
    }
}

pub fn unwrap_ref(ty: TypeIdent, span: Span) -> TypeResult<TypeIdent> {
    match ty {
        TypeIdent::Ref(ty) => Ok(*ty),
        _ => Err(TypecheckError::new(
            TypecheckErrorKind::ReferenceExpected,
            span,
        )),
    }
}

pub fn unwrap_typeident(flow: FlowType, span: Span) -> TypeResult<TypeIdent> {
    match flow {
        FlowType::Some(ty) => Ok(ty),
        _ => Err(TypecheckError::new(TypecheckErrorKind::ValueExpected, span)),
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
            ExprKind::BinaryArith { op, lhs, rhs, .. } => {
                lhs.kind.write(f, depth + 1)?;
                writeln!(f, "{pad}{}", op)?;
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
            ExprKind::StructInit { values, ty } => {
                writeln!(f, "{pad}{ty} {{")?;
                for (key, val) in values.iter() {
                    write!(f, "{pad}{key}: ")?;
                    val.kind.write(f, depth + 1)?;
                }
                writeln!(f, "{pad}}}")
            }
            ExprKind::FieldLookup { obj, field, .. } => {
                obj.kind.write(f, depth)?;
                write!(f, ".{field}")
            }
        }
    }
}
//
// impl std::fmt::Debug for Expr {
//     fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
//         match &self.kind {
//             ExprKind::Literal(l, _) => write!(f, "{l:?}"),
//             _ => write!(f, "{:#?}", self.kind),
//         }
//     }
// }
