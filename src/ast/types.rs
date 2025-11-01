use super::prelude::*;
use crate::{lexer::token::TypeIdentToken, typecheck::atomic::Atomic, utils::Span};

#[derive(Debug, PartialEq)]
pub enum AstTypeIdent {
    Atomic(Atomic),
    Compound(Identifier),
    Array(Box<AstTypeIdent>, AstExpr),
    Ref(Box<AstTypeIdent>),
}

#[derive(Debug, PartialEq)]
pub enum AstFlowType {
    Some(AstTypeIdent),
    Void,
    Never,
}

impl From<&TypeIdentToken> for AstTypeIdent {
    fn from(ty: &TypeIdentToken) -> Self {
        match ty {
            TypeIdentToken::Int => AstTypeIdent::Atomic(Atomic::int()),
            TypeIdentToken::String => AstTypeIdent::Array(
                Box::new(Atomic::char().into()),
                AstExpr::number(256, Span::none()),
            ),
            TypeIdentToken::Char => AstTypeIdent::Atomic(Atomic::char()),
            TypeIdentToken::Bool => AstTypeIdent::Atomic(Atomic::bool()),
            TypeIdentToken::Float => AstTypeIdent::Atomic(Atomic::Float),
        }
    }
}

impl From<Atomic> for AstTypeIdent {
    fn from(ty: Atomic) -> Self {
        Self::Atomic(ty)
    }
}

#[derive(Debug)]
pub struct AstStructDef {
    pub identifier: Identifier,
    pub is_public: bool,
    pub fields: Vec<(String, AstTypeIdent)>,
    pub span: Span,
}

impl AstStructDef {
    pub fn new(
        identifier: Identifier,
        is_public: bool,
        fields: Vec<(String, AstTypeIdent)>,
        span: Span,
    ) -> Self {
        Self {
            is_public,
            identifier,
            fields,
            span,
        }
    }
}

impl std::fmt::Display for AstStructDef {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        writeln!(f, "struct {} {{", self.identifier)?;
        for field in &self.fields {
            writeln!(f, "  {}: {}", field.0, field.1)?;
        }
        writeln!(f, "}}")
    }
}

#[derive(Debug)]
pub struct AstUnionDef {
    pub identifier: Identifier,
    pub is_public: bool,
    pub fields: Vec<(String, AstTypeIdent)>,
    pub span: Span,
}

impl AstUnionDef {
    pub fn new(
        identifier: Identifier,
        is_public: bool,
        fields: Vec<(String, AstTypeIdent)>,
        span: Span,
    ) -> Self {
        Self {
            is_public,
            identifier,
            fields,
            span,
        }
    }
}

impl std::fmt::Display for AstUnionDef {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        writeln!(f, "union {} {{", self.identifier)?;
        for field in &self.fields {
            writeln!(f, "  {}: {}", field.0, field.1)?;
        }
        writeln!(f, "}}")
    }
}

impl std::fmt::Display for AstTypeIdent {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            AstTypeIdent::Compound(ty) => write!(f, "{ty}"),
            AstTypeIdent::Atomic(atomic) => write!(f, "{}", atomic),
            AstTypeIdent::Array(ty, len) => write!(f, "{ty}[{}]", len),
            AstTypeIdent::Ref(ty) => write!(f, "*{ty}"),
        }
    }
}

impl std::fmt::Display for AstFlowType {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            AstFlowType::Some(type_ident) => write!(f, "{}", type_ident),
            AstFlowType::Void => write!(f, "void"),
            AstFlowType::Never => write!(f, "!"),
        }
    }
}
