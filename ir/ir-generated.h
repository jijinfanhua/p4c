#ifndef IR_GENERATED_H_
#define IR_GENERATED_H_

#include <functional>
#include <map>

// Special IR classes and types
#include "ir/dbprint.h"         // IWYU pragma: keep
#include "ir/id.h"              // IWYU pragma: keep
#include "ir/indexed_vector.h"  // IWYU pragma: keep
#include "ir/namemap.h"         // IWYU pragma: keep
#include "ir/node.h"            // IWYU pragma: keep
#include "ir/nodemap.h"         // IWYU pragma: keep
#include "ir/vector.h"          // IWYU pragma: keep

class JSONLoader;
using NodeFactoryFn = IR::Node*(*)(JSONLoader&);

namespace IR {
extern std::map<cstring, NodeFactoryFn> unpacker_table;
}

#line 16 "/home/fengyong/Desktop/p4c/ir/base.def"
#include "frontends/common/constantParsing.h"
#line 26 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
namespace IR {
/// a value that can be evaluated at compile-time
class CompileTimeValue : public virtual INode {
 public:
#line 19 "/home/fengyong/Desktop/p4c/ir/base.def"
    bool equiv(IR::CompileTimeValue const & other) const;
#line 33 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
};
}  // namespace IR
namespace IR {
/// Base class for P4 types
class Type : public Node {
 public:
    static const cstring minSizeInBits;
    static const cstring minSizeInBytes;
    static const cstring maxSizeInBits;
    static const cstring maxSizeInBytes;
#line 31 "/home/fengyong/Desktop/p4c/ir/base.def"
    typedef Type_Unknown        Unknown;
    typedef Type_Boolean        Boolean;
    typedef Type_Bits           Bits;
    typedef Type_String         String;
    typedef Type_Varbits        Varbits;
    typedef Type_Void           Void;
#line 51 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
/// Well-defined only for types with fixed width
#line 39 "/home/fengyong/Desktop/p4c/ir/base.def"
    virtual int width_bits() const;
#line 55 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
/// When possible returns the corresponding type that can be inserted
/// in a P4 program; may return a Type_Name
#line 42 "/home/fengyong/Desktop/p4c/ir/base.def"
    virtual IR::Type const * getP4Type() const = 0;
#line 60 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type"; }
    static cstring static_type_name() { return "Type"; }
    void toJSON(JSONGenerator & json) const override;
    Type(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
 protected:
    Type(Util::SourceInfo srcInfo);
    Type();
    IRNODE_ABSTRACT_SUBCLASS(Type)
};
}  // namespace IR
namespace IR {
/// Implemented by all types that may be generic:
/// Control, Extern, Method, Package, and Parser
class IMayBeGenericType : public virtual INode {
 public:
/// Allows the retrieval of type parameters
#line 49 "/home/fengyong/Desktop/p4c/ir/base.def"
    virtual IR::TypeParameters const * getTypeParameters() const = 0;
#line 82 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
};
}  // namespace IR
namespace IR {
/// Implemented by objects with an 'apply' method: Parser, Control, Table
class IApply : public virtual INode {
 public:
    static const cstring applyMethodName;
/// @returns the type signature of the apply method
#line 56 "/home/fengyong/Desktop/p4c/ir/base.def"
    virtual IR::Type_Method const * getApplyMethodType() const = 0;
#line 93 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 57 "/home/fengyong/Desktop/p4c/ir/base.def"
    virtual IR::ParameterList const * getApplyParameters() const = 0;
#line 96 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
};
}  // namespace IR
namespace IR {
/// base class for namespaces
class INamespace : public virtual INode {
 public:
#line 62 "/home/fengyong/Desktop/p4c/ir/base.def"
    virtual Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const = 0;
#line 105 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
};
}  // namespace IR
namespace IR {
/// Does not allow two declarations with the same name
class ISimpleNamespace : public virtual INode, public virtual INamespace {
 public:
#line 67 "/home/fengyong/Desktop/p4c/ir/base.def"
    virtual const IR::IDeclaration *getDeclByName(cstring name) const = 0;
#line 114 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
};
}  // namespace IR
namespace IR {
/// A general namespace can have multiple declarations with the same name
/// E.g., an extern can have multiple methods with the same name.
class IGeneralNamespace : public virtual INode, public virtual INamespace {
 public:
#line 73 "/home/fengyong/Desktop/p4c/ir/base.def"
    virtual Util::Enumerator<const IR::IDeclaration *> * getDeclsByName(cstring name) const;
#line 124 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
/// prints an error if it finds duplicate names
#line 75 "/home/fengyong/Desktop/p4c/ir/base.def"
    void checkDuplicateDeclarations() const;
#line 128 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 76 "/home/fengyong/Desktop/p4c/ir/base.def"
    void validate() const override;
#line 131 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
};
}  // namespace IR
namespace IR {

class INestedNamespace : public virtual INode, public virtual INamespace {
 public:
#line 82 "/home/fengyong/Desktop/p4c/ir/base.def"
    virtual std::vector<const IR::INamespace *> getNestedNamespaces() const = 0;
#line 140 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 83 "/home/fengyong/Desktop/p4c/ir/base.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const;
#line 143 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
};
}  // namespace IR
namespace IR {
/// Interface implemented by something that can be called
/// like a function.
class IFunctional : public virtual INode {
 public:
/// The parameters of the functional object
#line 90 "/home/fengyong/Desktop/p4c/ir/base.def"
    virtual const IR::ParameterList *getParameters() const = 0;
#line 154 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
/// Returns true if the parameters can be matched with the
/// supplied arguments.
#line 93 "/home/fengyong/Desktop/p4c/ir/base.def"
    bool callMatches(const IR::Vector<IR::Argument>* arguments) const;
#line 159 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
};
}  // namespace IR
namespace IR {
/// Implemented by things that look like type variables
class ITypeVar : public virtual INode {
 public:
#line 98 "/home/fengyong/Desktop/p4c/ir/base.def"
    virtual cstring getVarName() const = 0;
#line 168 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 99 "/home/fengyong/Desktop/p4c/ir/base.def"
    const IR::Type *asType() const { return to<Type>(); }
#line 171 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 100 "/home/fengyong/Desktop/p4c/ir/base.def"
    virtual int getDeclId() const = 0;
#line 174 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
};
}  // namespace IR
namespace IR {
/// Implemented by P4Parser, P4Control and Type_Package
class IContainer : public virtual INode, public virtual IMayBeGenericType, public virtual IDeclaration, public virtual IFunctional {
 public:
#line 105 "/home/fengyong/Desktop/p4c/ir/base.def"
    virtual const IR::Type *getType() const = 0;
#line 183 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
/// The type of the constructor as a method
#line 107 "/home/fengyong/Desktop/p4c/ir/base.def"
    virtual const IR::Type_Method *getConstructorMethodType() const = 0;
#line 187 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 108 "/home/fengyong/Desktop/p4c/ir/base.def"
    virtual const IR::ParameterList *getConstructorParameters() const = 0;
#line 190 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"

#line 110 "/home/fengyong/Desktop/p4c/ir/base.def"
    const IR::ParameterList *getParameters() const;
#line 194 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
};
}  // namespace IR
namespace IR {
/// This represents a primitive type
/// (called base type in the spec)
class Type_Base : public Type {
 public:
#line 116 "/home/fengyong/Desktop/p4c/ir/base.def"
    IR::Type const * getP4Type() const override;
#line 204 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Base const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Base"; }
    static cstring static_type_name() { return "Type_Base"; }
    void toJSON(JSONGenerator & json) const override;
    Type_Base(JSONLoader & json);
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
 protected:
    Type_Base(Util::SourceInfo srcInfo);
    Type_Base();
    IRNODE_ABSTRACT_SUBCLASS(Type_Base)
};
}  // namespace IR
namespace IR {
/// This is needed by Expression
class Type_Unknown : public Type_Base {
 public:
#line 122 "/home/fengyong/Desktop/p4c/ir/base.def"
    static const IR::Type_Unknown *get();
#line 225 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 123 "/home/fengyong/Desktop/p4c/ir/base.def"
    cstring toString() const override;
#line 228 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Unknown const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Unknown"; }
    static cstring static_type_name() { return "Type_Unknown"; }
    void toJSON(JSONGenerator & json) const override;
    Type_Unknown(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Unknown(Util::SourceInfo srcInfo);
    Type_Unknown();
    IRNODE_SUBCLASS(Type_Unknown)
};
}  // namespace IR
namespace IR {
/// A statement or a declaration
class StatOrDecl : public Node {
 public:
    bool operator==(IR::StatOrDecl const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "StatOrDecl"; }
    static cstring static_type_name() { return "StatOrDecl"; }
    void toJSON(JSONGenerator & json) const override;
    StatOrDecl(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
 protected:
    StatOrDecl(Util::SourceInfo srcInfo);
    StatOrDecl();
    IRNODE_ABSTRACT_SUBCLASS(StatOrDecl)
};
}  // namespace IR
namespace IR {
/// Two declarations with the same name are not necessarily the same declaration.
/// That's why declid is used to distinguish them.
class Declaration : public StatOrDecl, public virtual IDeclaration {
 public:
    IR::ID name;
    long declid = nextId++;
#line 134 "/home/fengyong/Desktop/p4c/ir/base.def"
    IR::ID getName() const override;
#line 270 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 135 "/home/fengyong/Desktop/p4c/ir/base.def"
    bool equiv(IR::Node const & a_) const override;
#line 273 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
 private:
    static long nextId;
 public:
#line 139 "/home/fengyong/Desktop/p4c/ir/base.def"
    cstring toString() const override;
#line 279 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Declaration const & a) const override;
    cstring node_type_name() const override { return "Declaration"; }
    static cstring static_type_name() { return "Declaration"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Declaration(JSONLoader & json);
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
 protected:
    Declaration(Util::SourceInfo srcInfo, IR::ID name);
    Declaration(IR::ID name);
    IRNODE_ABSTRACT_SUBCLASS(Declaration)
};
}  // namespace IR
namespace IR {
/// A declaration which introduces a type.
/// Two declarations with the same name are not the same declaration
/// That's why declid is used to distinguish them.
/// (We don't use multiple inheritance, so we can't
/// inherit both Type and Declaration.)
class Type_Declaration : public Type, public virtual IDeclaration {
 public:
    IR::ID name;
    long declid = nextId++;
#line 150 "/home/fengyong/Desktop/p4c/ir/base.def"
    IR::ID getName() const override;
#line 306 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 151 "/home/fengyong/Desktop/p4c/ir/base.def"
    bool equiv(IR::Node const & a_) const override;
#line 309 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
 private:
    static long nextId;
 public:
#line 155 "/home/fengyong/Desktop/p4c/ir/base.def"
    cstring toString() const override;
#line 315 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 156 "/home/fengyong/Desktop/p4c/ir/base.def"
    IR::Type const * getP4Type() const override;
#line 318 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Declaration const & a) const override;
    cstring node_type_name() const override { return "Type_Declaration"; }
    static cstring static_type_name() { return "Type_Declaration"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_Declaration(JSONLoader & json);
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
 protected:
    Type_Declaration(Util::SourceInfo srcInfo, IR::ID name);
    Type_Declaration(IR::ID name);
    IRNODE_ABSTRACT_SUBCLASS(Type_Declaration)
};
}  // namespace IR
namespace IR {
/// base class for expressions
class Expression : public Node {
 public:
/// Note that the type field is not visited.
/// Most P4_16 passes don't use this field.
/// It is a used to hold the result of TypeInferencing for the expression.
/// It is used by the P4_14 front-end and by some back-ends.
/// It is not visited by the visitors by default (can be visited explicitly in preorder)
    const IR::Type* type = Type::Unknown::get();
#line 167 "/home/fengyong/Desktop/p4c/ir/base.def"
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
#line 346 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    IRNODE_DECLARE_APPLY_OVERLOAD(Expression)
    bool operator==(IR::Expression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Expression"; }
    static cstring static_type_name() { return "Expression"; }
    void toJSON(JSONGenerator & json) const override;
    Expression(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
 protected:
    Expression(Util::SourceInfo srcInfo, const IR::Type* type);
    Expression(const IR::Type* type);
    Expression(Util::SourceInfo srcInfo);
    Expression();
    IRNODE_ABSTRACT_SUBCLASS(Expression)
};
}  // namespace IR
namespace IR {
class Operation : public Expression {
 public:
#line 172 "/home/fengyong/Desktop/p4c/ir/base.def"
    virtual int getPrecedence() const = 0;
#line 369 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 173 "/home/fengyong/Desktop/p4c/ir/base.def"
    virtual cstring getStringOp() const = 0;
#line 372 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 175 "/home/fengyong/Desktop/p4c/ir/base.def"
    typedef Operation_Unary Unary;
    typedef Operation_Binary Binary;
    typedef Operation_Relation Relation;
#line 377 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 179 "/home/fengyong/Desktop/p4c/ir/base.def"
    cstring toString() const override;
#line 380 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Operation const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Operation"; }
    static cstring static_type_name() { return "Operation"; }
    void toJSON(JSONGenerator & json) const override;
    Operation(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
 protected:
    Operation(Util::SourceInfo srcInfo, const IR::Type* type);
    Operation(const IR::Type* type);
    Operation(Util::SourceInfo srcInfo);
    Operation();
    IRNODE_ABSTRACT_SUBCLASS(Operation)
};
}  // namespace IR
namespace IR {
/// Currently paths can be absolute (starting with a dot) or relative
/// (just an identifier).  In a previous design paths could have
/// multiple components.
class Path : public Node {
 public:
    IR::ID name;
    bool absolute = false;
#line 189 "/home/fengyong/Desktop/p4c/ir/base.def"
    bool isDontCare() const;
#line 407 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 190 "/home/fengyong/Desktop/p4c/ir/base.def"
    cstring toString() const override;
#line 410 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 196 "/home/fengyong/Desktop/p4c/ir/base.def"
    cstring asString() const;
#line 413 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 202 "/home/fengyong/Desktop/p4c/ir/base.def"
    void dbprint(std::ostream & out) const override;
#line 416 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 203 "/home/fengyong/Desktop/p4c/ir/base.def"
    void validate() const override;
#line 419 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Path const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Path"; }
    static cstring static_type_name() { return "Path"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Path(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Path(Util::SourceInfo srcInfo, IR::ID name, bool absolute);
    Path(IR::ID name, bool absolute);
    Path(Util::SourceInfo srcInfo, IR::ID name);
    Path(IR::ID name);
    IRNODE_SUBCLASS(Path)
};
}  // namespace IR
namespace IR {
/// Handy class used in several NamedMaps
class NamedExpression : public Declaration {
 public:
    const IR::Expression* expression = nullptr;
    bool operator==(IR::NamedExpression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "NamedExpression"; }
    static cstring static_type_name() { return "NamedExpression"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    NamedExpression(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override { return a == *this; }
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    NamedExpression(Util::SourceInfo srcInfo, IR::ID name, const IR::Expression* expression);
    NamedExpression(IR::ID name, const IR::Expression* expression);
    IRNODE_SUBCLASS(NamedExpression)
};
}  // namespace IR
namespace IR {
/// A token in an unparsed annotation.
/// This should really be P4::P4Parser::symbol_type, but p4parser.hpp depends
/// on the IR in a way that makes it difficult to #include in this file.
class AnnotationToken : public Node {
 public:
    int token_type;

    cstring text;
    UnparsedConstant * constInfo = nullptr;
#line 218 "/home/fengyong/Desktop/p4c/ir/base.def"
    void dbprint(std::ostream & out) const override;
#line 472 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::AnnotationToken const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "AnnotationToken"; }
    static cstring static_type_name() { return "AnnotationToken"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    AnnotationToken(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    AnnotationToken(Util::SourceInfo srcInfo, int token_type, cstring text, UnparsedConstant * constInfo);
    AnnotationToken(int token_type, cstring text, UnparsedConstant * constInfo);
    AnnotationToken(Util::SourceInfo srcInfo, int token_type, cstring text);
    AnnotationToken(int token_type, cstring text);
    IRNODE_SUBCLASS(AnnotationToken)
};
}  // namespace IR
namespace IR {
/// Annotations are used to provide additional information to the compiler
/// Most P4 entities can be optionally annotated
class Annotation : public Node {
 public:
    IR::ID name;
/// An unparsed annotation body
    IR::Vector<IR::AnnotationToken> body;
/// Whether the annotation body needs to be parsed.
/// Invariant: if this is true, then expr and kv must both be empty. If the
/// annotation is compiler-generated (e.g., derived from a P4₁₄ pragma),
/// then needsParsing will be false and the body will be empty, but expr or
/// kv may be populated.
    bool needsParsing;
/// Annotations that are simple expressions
    IR::Vector<IR::Expression> expr;
/// Annotations described as key-value pairs
    IR::IndexedVector<IR::NamedExpression> kv;
/// If this is true this is a structured annotation, and there are some
/// constraints on its contents.
    bool structured;
/// For annotations parsed from P4-16 source.
#line 249 "/home/fengyong/Desktop/p4c/ir/base.def"
    Annotation(Util::SourceInfo si, IR::ID n, IR::Vector<IR::AnnotationToken> const & a);
#line 513 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"

#line 252 "/home/fengyong/Desktop/p4c/ir/base.def"
    Annotation(Util::SourceInfo si, IR::ID n, IR::Vector<IR::AnnotationToken> const & a, bool structured);
#line 517 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"

#line 256 "/home/fengyong/Desktop/p4c/ir/base.def"
    Annotation(Util::SourceInfo si, IR::ID n, std::initializer_list<IR::Expression const *> const & a, bool structured = false);
#line 521 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 259 "/home/fengyong/Desktop/p4c/ir/base.def"
    Annotation(Util::SourceInfo si, IR::ID n, IR::Vector<IR::Expression> const & a, bool structured = false);
#line 524 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 261 "/home/fengyong/Desktop/p4c/ir/base.def"
    Annotation(Util::SourceInfo si, IR::ID n, IR::IndexedVector<IR::NamedExpression> const & kv, bool structured = false);
#line 527 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 264 "/home/fengyong/Desktop/p4c/ir/base.def"
    Annotation(IR::ID n, std::initializer_list<IR::Expression const *> const & a, bool structured = false);
#line 530 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 266 "/home/fengyong/Desktop/p4c/ir/base.def"
    Annotation(IR::ID n, IR::Vector<IR::Expression> const & a, bool structured = false);
#line 533 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 268 "/home/fengyong/Desktop/p4c/ir/base.def"
    Annotation(IR::ID n, intmax_t v, bool structured = false);
#line 536 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 271 "/home/fengyong/Desktop/p4c/ir/base.def"
    Annotation(IR::ID n, cstring v, bool structured = false);
#line 539 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    static const cstring nameAnnotation;
/// Indicates the control-plane name.
    static const cstring tableOnlyAnnotation;
/// Action cannot be a default_action.
    static const cstring defaultOnlyAnnotation;
/// action can only be a default_action.
    static const cstring atomicAnnotation;
/// Code should be executed atomically.
    static const cstring hiddenAnnotation;
/// Object should not be exposed to the control-plane.
    static const cstring lengthAnnotation;
/// P4-14 annotation for varbit fields.
    static const cstring optionalAnnotation;
/// Optional parameter annotation
    static const cstring pkginfoAnnotation;
/// Package documentation annotation.
    static const cstring deprecatedAnnotation;
/// Deprecation annotation.
    static const cstring synchronousAnnotation;
/// Synchronous annotation.
    static const cstring pureAnnotation;
/// extern function/method annotation.
    static const cstring noSideEffectsAnnotation;
/// extern function/method annotation.
    static const cstring noWarnAnnotation;
/// noWarn annotation.
    static const cstring matchAnnotation;
/// Match annotation (for value sets).
    static const cstring fieldListAnnotation;
/// Used for recirculate, etc.
    static const cstring debugLoggingAnnotation;
/// Used by compiler implementer to limit debug log to the annotated IR context.
#line 291 "/home/fengyong/Desktop/p4c/ir/base.def"
    cstring toString() const override;
#line 574 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 292 "/home/fengyong/Desktop/p4c/ir/base.def"
    void validate() const override;
#line 577 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
/// Extracts name value from a name annotation
#line 301 "/home/fengyong/Desktop/p4c/ir/base.def"
    cstring getName() const;
#line 581 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
/// Extracts a single string argument; error if the argument is not a string
#line 303 "/home/fengyong/Desktop/p4c/ir/base.def"
    cstring getSingleString() const;
#line 585 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
enum class Kind
#line 306 "/home/fengyong/Desktop/p4c/ir/base.def"
{
        Unstructured,
        StructuredEmpty,
        StructuredKVList,
        StructuredExpressionList
    };
#line 594 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 312 "/home/fengyong/Desktop/p4c/ir/base.def"
    IR::Annotation::Kind annotationKind() const;
#line 597 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Annotation const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "Annotation"; }
    static cstring static_type_name() { return "Annotation"; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Annotation(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Annotation(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::AnnotationToken> body, bool needsParsing, IR::Vector<IR::Expression> expr, IR::IndexedVector<IR::NamedExpression> kv, bool structured);
    Annotation(IR::ID name, IR::Vector<IR::AnnotationToken> body, bool needsParsing, IR::Vector<IR::Expression> expr, IR::IndexedVector<IR::NamedExpression> kv, bool structured);
    IRNODE_SUBCLASS(Annotation)
};
}  // namespace IR
namespace IR {
/// There can be several annotations with the same "name", so this is a vector.
// FIXME -- get rid of this class -- classes with annotations should have an
// inline Vector<Annotation> instead (remove useless indirection)
class Annotations : public Node {
 public:
    IR::Vector<IR::Annotation> annotations;
    static IR::Annotations * empty;

#line 330 "/home/fengyong/Desktop/p4c/ir/base.def"
    size_t size() const;
#line 626 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"


#line 333 "/home/fengyong/Desktop/p4c/ir/base.def"
    const IR::Annotation *getSingle(cstring name) const;
#line 631 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 334 "/home/fengyong/Desktop/p4c/ir/base.def"
    const IR::Annotations *add(const IR::Annotation* annot);
#line 634 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 338 "/home/fengyong/Desktop/p4c/ir/base.def"
    const IR::Annotations *add(const IR::Annotation* annot) const;
#line 637 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 339 "/home/fengyong/Desktop/p4c/ir/base.def"
    const IR::Annotations *addAnnotation(cstring name, const IR::Expression* expr, bool structured = false);
#line 640 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 341 "/home/fengyong/Desktop/p4c/ir/base.def"
    const IR::Annotations *addAnnotation(cstring name, const IR::Expression* expr, bool structured = false) const;
#line 643 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"


#line 345 "/home/fengyong/Desktop/p4c/ir/base.def"
    const IR::Annotations *addAnnotationIfNew(cstring name, const IR::Expression* expr, bool structured = false) const;
#line 648 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 347 "/home/fengyong/Desktop/p4c/ir/base.def"
    const IR::Annotations *append(const IR::Annotations* other);
#line 651 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"


#line 356 "/home/fengyong/Desktop/p4c/ir/base.def"
    const IR::Annotations *addOrReplace(cstring name, const IR::Expression* expr, bool structured = false) const;
#line 656 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 362 "/home/fengyong/Desktop/p4c/ir/base.def"
    typedef std::function<bool(const IR::Annotation*)> Filter;
#line 659 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 364 "/home/fengyong/Desktop/p4c/ir/base.def"
    const IR::Annotations *where(Filter func) const;
#line 662 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 370 "/home/fengyong/Desktop/p4c/ir/base.def"
    void validate() const override;
#line 665 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 371 "/home/fengyong/Desktop/p4c/ir/base.def"
    void dbprint(std::ostream & out) const override;
#line 668 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Annotations const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "Annotations"; }
    static cstring static_type_name() { return "Annotations"; }
    void toJSON(JSONGenerator & json) const override;
    Annotations(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Annotations(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations);
    Annotations(IR::Vector<IR::Annotation> annotations);
    Annotations(Util::SourceInfo srcInfo);
    Annotations();
    IRNODE_SUBCLASS(Annotations)
};
}  // namespace IR
namespace IR {
/// Implemented by all objects that can have annotations
class IAnnotated : public virtual INode {
 public:
#line 376 "/home/fengyong/Desktop/p4c/ir/base.def"
    virtual const IR::Annotations *getAnnotations() const = 0;
#line 692 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 377 "/home/fengyong/Desktop/p4c/ir/base.def"
    const IR::Annotation *getAnnotation(cstring name) const override;
#line 695 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
};
}  // namespace IR
namespace IR {
class IInstance : public virtual INode {
 public:
#line 382 "/home/fengyong/Desktop/p4c/ir/base.def"
    virtual IR::ID Name() const = 0;
#line 703 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 383 "/home/fengyong/Desktop/p4c/ir/base.def"
    virtual const IR::Type *getType() const = 0;
#line 706 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
};
}  // namespace IR
namespace IR {
/// An argument to a function call (or constructor call)
/// Arguments may have optional names
class Argument : public Node {
 public:
/// If an argument has no name the name.name is nullptr.
    IR::ID name;
    const IR::Expression* expression = nullptr;
#line 393 "/home/fengyong/Desktop/p4c/ir/base.def"
    void dbprint(std::ostream & out) const override;
#line 719 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 394 "/home/fengyong/Desktop/p4c/ir/base.def"
    void validate() const override;
#line 722 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 395 "/home/fengyong/Desktop/p4c/ir/base.def"
    cstring toString() const override;
#line 725 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Argument const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "Argument"; }
    static cstring static_type_name() { return "Argument"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Argument(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Argument(Util::SourceInfo srcInfo, IR::ID name, const IR::Expression* expression);
    Argument(IR::ID name, const IR::Expression* expression);
    Argument(Util::SourceInfo srcInfo, const IR::Expression* expression);
    Argument(const IR::Expression* expression);
    IRNODE_SUBCLASS(Argument)
};
}  // namespace IR
/** @} */
/* end group irdefs */
/* -*-C++-*- */
/** \addtogroup irdefs
  * @{
  */
/*
   This file contains IR related to representating the type hierarchy.
   Some of these classes never appear in the IR tree, they are just
   synthesized by the type-checker.
*/
#line 12 "/home/fengyong/Desktop/p4c/ir/type.def"
namespace IR {
enum class Direction {
    None,
    In,
    Out,
    InOut
};

inline cstring directionToString(IR::Direction direction) {
    switch (direction) {
        case IR::Direction::None:
            return "<none>";
        case IR::Direction::In:
            return "in";
        case IR::Direction::Out:
            return "out";
        case IR::Direction::InOut:
            return "inout";
        default:
            BUG("Unhandled case");
    }
}
}  // namespace IR

inline std::ostream& operator<<(std::ostream &out, IR::Direction d) {
    switch (d) {
        case IR::Direction::None:
            break;
        case IR::Direction::In:
            out << "in";
            break;
        case IR::Direction::Out:
            out << "out";
            break;
        case IR::Direction::InOut:
            out << "inout";
            break;
        default:
            BUG("Unhandled case");
    }
    return out;
}

inline bool operator>>(cstring s, IR::Direction &d) {
    if (!s || s == "") d = IR::Direction::None;
    else if (s == "in") d = IR::Direction::In;
    else if (s == "out") d = IR::Direction::Out;
    else if (s == "inout") d = IR::Direction::InOut;
    else return false;
    return true;
}
#line 807 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
namespace IR {
/// This represents a type that can unify with any other type.
/// It is the original type of Dots (...) expressions.
/// There is no syntax to represent this type.
/// Treated like a type variable so that unification can assign it a value.
class Type_Any : public Type, public virtual ITypeVar {
 public:
    long declid = nextId++;
 private:
    static long nextId;
 public:
#line 74 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring getVarName() const override;
#line 821 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 75 "/home/fengyong/Desktop/p4c/ir/type.def"
    int getDeclId() const override;
#line 824 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 76 "/home/fengyong/Desktop/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 827 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 77 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 830 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 78 "/home/fengyong/Desktop/p4c/ir/type.def"
    bool operator==(IR::Type_Any const & a) const override;
#line 833 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 79 "/home/fengyong/Desktop/p4c/ir/type.def"
    static const IR::Type_Any *get();
#line 836 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 80 "/home/fengyong/Desktop/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 839 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Any"; }
    static cstring static_type_name() { return "Type_Any"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_Any(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Any(Util::SourceInfo srcInfo);
    Type_Any();
    IRNODE_SUBCLASS(Type_Any)
};
}  // namespace IR
namespace IR {
/// This type is a fragment of another type.
/// This is used in conjunction with Type_Any to typecheck
/// expressions containing ... (Dots).
/// After unification this type replaces Type_Any.
/// For example:
/// struct S { bit<32> s; bit<16> t; }
/// S s = { s = 2, ... };
/// The type assigned to 'type' by unification will be
/// Type_Fragment { type = Type_UnknownStruct { t: Type_Bits<15> } }.
/// In other words, the type of the ... expression is a
/// fragment of a struct that contains just the field t.
class Type_Fragment : public Type {
 public:
    const IR::Type* type = nullptr;
#line 96 "/home/fengyong/Desktop/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 871 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 97 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 874 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 98 "/home/fengyong/Desktop/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 877 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Fragment const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_Fragment"; }
    static cstring static_type_name() { return "Type_Fragment"; }
    void toJSON(JSONGenerator & json) const override;
    Type_Fragment(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Fragment(Util::SourceInfo srcInfo, const IR::Type* type);
    Type_Fragment(const IR::Type* type);
    IRNODE_SUBCLASS(Type_Fragment)
};
}  // namespace IR
namespace IR {
/// Represents the type of a type.
/// For example, in a declaration like
/// bit<32> x;
/// The type of x is Type_Bits(32);
/// The type of 'bit<32>' is Type_Type(Type_Bits(32))
/// TypeType should not appear in the program IR, just in the TypeMap produced
/// by type-checking.
class Type_Type : public Type {
 public:
    const IR::Type* type = nullptr;
#line 110 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 908 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 111 "/home/fengyong/Desktop/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 911 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 112 "/home/fengyong/Desktop/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 914 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 113 "/home/fengyong/Desktop/p4c/ir/type.def"
    void validate() const override;
#line 917 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Type const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "Type_Type"; }
    static cstring static_type_name() { return "Type_Type"; }
    void toJSON(JSONGenerator & json) const override;
    Type_Type(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Type(Util::SourceInfo srcInfo, const IR::Type* type);
    Type_Type(const IR::Type* type);
    IRNODE_SUBCLASS(Type_Type)
};
}  // namespace IR
namespace IR {
class Type_Boolean : public Type_Base {
 public:
#line 117 "/home/fengyong/Desktop/p4c/ir/type.def"
    static const IR::Type_Boolean *get();
#line 939 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 118 "/home/fengyong/Desktop/p4c/ir/type.def"
    int width_bits() const override;
#line 942 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 119 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 945 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 120 "/home/fengyong/Desktop/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 948 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Boolean const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Boolean"; }
    static cstring static_type_name() { return "Type_Boolean"; }
    void toJSON(JSONGenerator & json) const override;
    Type_Boolean(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Boolean(Util::SourceInfo srcInfo);
    Type_Boolean();
    IRNODE_SUBCLASS(Type_Boolean)
};
}  // namespace IR
namespace IR {
/// The type of a parser state
class Type_State : public Type_Base {
 public:
#line 125 "/home/fengyong/Desktop/p4c/ir/type.def"
    static const IR::Type_State *get();
#line 970 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 126 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 973 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 127 "/home/fengyong/Desktop/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 976 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_State const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_State"; }
    static cstring static_type_name() { return "Type_State"; }
    void toJSON(JSONGenerator & json) const override;
    Type_State(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_State(Util::SourceInfo srcInfo);
    Type_State();
    IRNODE_SUBCLASS(Type_State)
};
}  // namespace IR
namespace IR {
/// Represents both bit<> and int<> types in P4-14 and P4-16
class Type_Bits : public Type_Base {
 public:
    int size = 0;

    const IR::Expression* expression = nullptr;

    bool isSigned;
#line 135 "/home/fengyong/Desktop/p4c/ir/type.def"
    static const IR::Type_Bits *get(Util::SourceInfo si, int sz, bool isSigned = false);
#line 1003 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 136 "/home/fengyong/Desktop/p4c/ir/type.def"
    static const IR::Type_Bits *get(int sz, bool isSigned = false);
#line 1006 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 137 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring baseName() const;
#line 1009 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 138 "/home/fengyong/Desktop/p4c/ir/type.def"
    int width_bits() const override;
#line 1012 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 140 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 1015 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 141 "/home/fengyong/Desktop/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 1018 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Bits const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "Type_Bits"; }
    static cstring static_type_name() { return "Type_Bits"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_Bits(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Bits(Util::SourceInfo srcInfo, int size, const IR::Expression* expression, bool isSigned);
    Type_Bits(int size, const IR::Expression* expression, bool isSigned);
    Type_Bits(Util::SourceInfo srcInfo, const IR::Expression* expression, bool isSigned);
    Type_Bits(const IR::Expression* expression, bool isSigned);
    Type_Bits(Util::SourceInfo srcInfo, int size, bool isSigned);
    Type_Bits(int size, bool isSigned);
    Type_Bits(Util::SourceInfo srcInfo, bool isSigned);
    Type_Bits(bool isSigned);
    IRNODE_SUBCLASS(Type_Bits)
};
}  // namespace IR
namespace IR {
class Type_Varbits : public Type_Base {
 public:
    int size = 0;

    const IR::Expression* expression = nullptr;

#line 147 "/home/fengyong/Desktop/p4c/ir/type.def"
    static const IR::Type_Varbits *get(Util::SourceInfo si, int size = 0);
#line 1052 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 148 "/home/fengyong/Desktop/p4c/ir/type.def"
    static const IR::Type_Varbits *get();
#line 1055 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 149 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 1058 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 150 "/home/fengyong/Desktop/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 1061 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Varbits const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "Type_Varbits"; }
    static cstring static_type_name() { return "Type_Varbits"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_Varbits(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Varbits(Util::SourceInfo srcInfo, int size, const IR::Expression* expression);
    Type_Varbits(int size, const IR::Expression* expression);
    Type_Varbits(Util::SourceInfo srcInfo, const IR::Expression* expression);
    Type_Varbits(const IR::Expression* expression);
    Type_Varbits(Util::SourceInfo srcInfo, int size);
    Type_Varbits(int size);
    Type_Varbits(Util::SourceInfo srcInfo);
    Type_Varbits();
    IRNODE_SUBCLASS(Type_Varbits)
};
}  // namespace IR
namespace IR {
class Parameter : public Declaration, public virtual IAnnotated {
 public:
    const IR::Annotations* annotations = Annotations::empty;
    Direction direction;
    const IR::Type* type = nullptr;
    const IR::Expression* defaultValue = nullptr;
#line 158 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::Annotations *getAnnotations() const override;
#line 1095 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 159 "/home/fengyong/Desktop/p4c/ir/type.def"
    bool hasOut() const;
#line 1098 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 161 "/home/fengyong/Desktop/p4c/ir/type.def"
    bool isOptional() const;
#line 1101 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 163 "/home/fengyong/Desktop/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 1104 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Parameter const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Parameter"; }
    static cstring static_type_name() { return "Parameter"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Parameter(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override { return a == *this; }
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Parameter(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, Direction direction, const IR::Type* type, const IR::Expression* defaultValue);
    Parameter(IR::ID name, const IR::Annotations* annotations, Direction direction, const IR::Type* type, const IR::Expression* defaultValue);
    Parameter(Util::SourceInfo srcInfo, IR::ID name, Direction direction, const IR::Type* type, const IR::Expression* defaultValue);
    Parameter(IR::ID name, Direction direction, const IR::Type* type, const IR::Expression* defaultValue);
    Parameter(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, Direction direction, const IR::Type* type);
    Parameter(IR::ID name, const IR::Annotations* annotations, Direction direction, const IR::Type* type);
    Parameter(Util::SourceInfo srcInfo, IR::ID name, Direction direction, const IR::Type* type);
    Parameter(IR::ID name, Direction direction, const IR::Type* type);
    IRNODE_SUBCLASS(Parameter)
};
}  // namespace IR
namespace IR {
class ParameterList : public Node, public virtual ISimpleNamespace {
 public:
    IR::IndexedVector<IR::Parameter> parameters;
#line 169 "/home/fengyong/Desktop/p4c/ir/type.def"
    void validate() const override;
#line 1136 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 170 "/home/fengyong/Desktop/p4c/ir/type.def"
    Util::Enumerator<const IR::Parameter *> * getEnumerator() const;
#line 1139 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 172 "/home/fengyong/Desktop/p4c/ir/type.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 1142 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 174 "/home/fengyong/Desktop/p4c/ir/type.def"
    size_t size() const;
#line 1145 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 175 "/home/fengyong/Desktop/p4c/ir/type.def"
    bool empty() const;
#line 1148 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 176 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::Parameter *getParameter(cstring name) const;
#line 1151 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 178 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::Parameter *getParameter(unsigned index) const;
#line 1154 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 182 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 1157 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 183 "/home/fengyong/Desktop/p4c/ir/type.def"
    void push_back(IR::Parameter const * p);
#line 1160 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 184 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 1163 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 196 "/home/fengyong/Desktop/p4c/ir/type.def"
    auto begin() const -> decltype(parameters.begin()) { return parameters.begin(); }
    auto end() const -> decltype(parameters.end()) { return parameters.end(); }
#line 1167 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ParameterList const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "ParameterList"; }
    static cstring static_type_name() { return "ParameterList"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ParameterList(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    ParameterList(Util::SourceInfo srcInfo, IR::IndexedVector<IR::Parameter> parameters);
    ParameterList(IR::IndexedVector<IR::Parameter> parameters);
    ParameterList(Util::SourceInfo srcInfo);
    ParameterList();
    IRNODE_SUBCLASS(ParameterList)
};
}  // namespace IR
namespace IR {
/// Represents a type variable written by the user
class Type_Var : public Type_Declaration, public virtual ITypeVar {
 public:
#line 203 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring getVarName() const override;
#line 1192 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 204 "/home/fengyong/Desktop/p4c/ir/type.def"
    int getDeclId() const override;
#line 1195 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 205 "/home/fengyong/Desktop/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 1198 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 206 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 1201 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Var const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Var"; }
    static cstring static_type_name() { return "Type_Var"; }
    void toJSON(JSONGenerator & json) const override;
    Type_Var(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Declaration const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Var(Util::SourceInfo srcInfo, IR::ID name);
    Type_Var(IR::ID name);
    IRNODE_SUBCLASS(Type_Var)
};
}  // namespace IR
namespace IR {
/// Stands for the 'int' type: infinite precision constant
/// However, we represent it as a type variable, because we use
/// type unification to discover the correct type for the constants
/// in some contexts.
class Type_InfInt : public Type, public virtual ITypeVar {
 public:
    long declid = nextId++;
 private:
    static long nextId;
 public:
#line 218 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring getVarName() const override;
#line 1230 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 219 "/home/fengyong/Desktop/p4c/ir/type.def"
    int getDeclId() const override;
#line 1233 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 220 "/home/fengyong/Desktop/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 1236 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 221 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 1239 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 222 "/home/fengyong/Desktop/p4c/ir/type.def"
    bool operator==(IR::Type_InfInt const & a) const override;
#line 1242 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 223 "/home/fengyong/Desktop/p4c/ir/type.def"
    bool equiv(IR::Node const & a_) const override;
#line 1245 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 227 "/home/fengyong/Desktop/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 1248 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    cstring node_type_name() const override { return "Type_InfInt"; }
    static cstring static_type_name() { return "Type_InfInt"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_InfInt(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_InfInt(Util::SourceInfo srcInfo);
    Type_InfInt();
    IRNODE_SUBCLASS(Type_InfInt)
};
}  // namespace IR
namespace IR {
class Type_Dontcare : public Type_Base {
 public:
#line 231 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 1267 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 232 "/home/fengyong/Desktop/p4c/ir/type.def"
    static const IR::Type_Dontcare *get();
#line 1270 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 233 "/home/fengyong/Desktop/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 1273 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Dontcare const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Dontcare"; }
    static cstring static_type_name() { return "Type_Dontcare"; }
    void toJSON(JSONGenerator & json) const override;
    Type_Dontcare(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Dontcare(Util::SourceInfo srcInfo);
    Type_Dontcare();
    IRNODE_SUBCLASS(Type_Dontcare)
};
}  // namespace IR
namespace IR {
class Type_Void : public Type_Base {
 public:
#line 237 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 1294 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 238 "/home/fengyong/Desktop/p4c/ir/type.def"
    static const IR::Type_Void *get();
#line 1297 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 239 "/home/fengyong/Desktop/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 1300 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Void const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Void"; }
    static cstring static_type_name() { return "Type_Void"; }
    void toJSON(JSONGenerator & json) const override;
    Type_Void(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Void(Util::SourceInfo srcInfo);
    Type_Void();
    IRNODE_SUBCLASS(Type_Void)
};
}  // namespace IR
namespace IR {
class Type_MatchKind : public Type_Base {
 public:
#line 243 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 1321 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 244 "/home/fengyong/Desktop/p4c/ir/type.def"
    static const IR::Type_MatchKind *get();
#line 1324 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 245 "/home/fengyong/Desktop/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 1327 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_MatchKind const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_MatchKind"; }
    static cstring static_type_name() { return "Type_MatchKind"; }
    void toJSON(JSONGenerator & json) const override;
    Type_MatchKind(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_MatchKind(Util::SourceInfo srcInfo);
    Type_MatchKind();
    IRNODE_SUBCLASS(Type_MatchKind)
};
}  // namespace IR
namespace IR {
class TypeParameters : public Node, public virtual ISimpleNamespace {
 public:
    IR::IndexedVector<IR::Type_Var> parameters;
#line 250 "/home/fengyong/Desktop/p4c/ir/type.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 1349 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 252 "/home/fengyong/Desktop/p4c/ir/type.def"
    bool empty() const;
#line 1352 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 253 "/home/fengyong/Desktop/p4c/ir/type.def"
    size_t size() const;
#line 1355 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 254 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 1358 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 256 "/home/fengyong/Desktop/p4c/ir/type.def"
    void push_back(const IR::Type_Var* tv);
#line 1361 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 257 "/home/fengyong/Desktop/p4c/ir/type.def"
    void validate() const override;
#line 1364 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 258 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 1367 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::TypeParameters const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "TypeParameters"; }
    static cstring static_type_name() { return "TypeParameters"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    TypeParameters(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    TypeParameters(Util::SourceInfo srcInfo, IR::IndexedVector<IR::Type_Var> parameters);
    TypeParameters(IR::IndexedVector<IR::Type_Var> parameters);
    TypeParameters(Util::SourceInfo srcInfo);
    TypeParameters();
    IRNODE_SUBCLASS(TypeParameters)
};
}  // namespace IR
namespace IR {
class StructField : public Declaration, public virtual IAnnotated {
 public:
    const IR::Annotations* annotations = Annotations::empty;
    const IR::Type* type = nullptr;
#line 277 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::Annotations *getAnnotations() const override;
#line 1393 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::StructField const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "StructField"; }
    static cstring static_type_name() { return "StructField"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    StructField(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override { return a == *this; }
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    StructField(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type);
    StructField(IR::ID name, const IR::Annotations* annotations, const IR::Type* type);
    StructField(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type);
    StructField(IR::ID name, const IR::Type* type);
    IRNODE_SUBCLASS(StructField)
};
}  // namespace IR
namespace IR {
class Type_StructLike : public Type_Declaration, public virtual INestedNamespace, public virtual ISimpleNamespace, public virtual IAnnotated, public virtual IMayBeGenericType {
 public:
    const IR::Annotations* annotations = Annotations::empty;
    const IR::TypeParameters* typeParameters = new TypeParameters();
    IR::IndexedVector<IR::StructField> fields;
#line 284 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::TypeParameters *getTypeParameters() const override;
#line 1423 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 285 "/home/fengyong/Desktop/p4c/ir/type.def"
    std::vector<const IR::INamespace *> getNestedNamespaces() const override;
#line 1426 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 286 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::Annotations *getAnnotations() const override;
#line 1429 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 287 "/home/fengyong/Desktop/p4c/ir/type.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 1432 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 289 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::StructField *getField(cstring name) const;
#line 1435 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 291 "/home/fengyong/Desktop/p4c/ir/type.def"
    int getFieldIndex(cstring name) const;
#line 1438 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
/// This function returns start offset of the given field name in bits.
/// If the given name is not a valid field name, -1 is returned.
/// The given offset may not be correct if varbit field(s) present in between.
/// Offset for all fields will be correct if:
///  - the type has only fixed width fields
///  - the type has fixed width fields with only one varbit field as a last member.
#line 306 "/home/fengyong/Desktop/p4c/ir/type.def"
    int getFieldBitOffset(cstring name) const;
#line 1447 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 316 "/home/fengyong/Desktop/p4c/ir/type.def"
    int width_bits() const override;
#line 1450 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 322 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 1453 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 324 "/home/fengyong/Desktop/p4c/ir/type.def"
    void validate() const override;
#line 1456 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 325 "/home/fengyong/Desktop/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 1459 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    IRNODE_DECLARE_APPLY_OVERLOAD(Type_StructLike)
    bool operator==(IR::Type_StructLike const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "Type_StructLike"; }
    static cstring static_type_name() { return "Type_StructLike"; }
    void toJSON(JSONGenerator & json) const override;
    Type_StructLike(JSONLoader & json);
    bool operator==(IR::Type_Declaration const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
 protected:
    Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    Type_StructLike(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    Type_StructLike(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields);
    Type_StructLike(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields);
    Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields);
    Type_StructLike(IR::ID name, IR::IndexedVector<IR::StructField> fields);
    Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters);
    Type_StructLike(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters);
    Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters);
    Type_StructLike(IR::ID name, const IR::TypeParameters* typeParameters);
    Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations);
    Type_StructLike(IR::ID name, const IR::Annotations* annotations);
    Type_StructLike(Util::SourceInfo srcInfo, IR::ID name);
    Type_StructLike(IR::ID name);
    IRNODE_ABSTRACT_SUBCLASS(Type_StructLike)
};
}  // namespace IR
namespace IR {
class Type_Struct : public Type_StructLike {
 public:
#line 331 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 1497 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Struct const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Struct"; }
    static cstring static_type_name() { return "Type_Struct"; }
    void toJSON(JSONGenerator & json) const override;
    Type_Struct(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_StructLike const & a) const override { return a == *this; }
    bool operator==(IR::Type_Declaration const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Struct(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    Type_Struct(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    Type_Struct(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    Type_Struct(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    Type_Struct(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields);
    Type_Struct(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields);
    Type_Struct(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields);
    Type_Struct(IR::ID name, IR::IndexedVector<IR::StructField> fields);
    Type_Struct(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters);
    Type_Struct(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters);
    Type_Struct(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters);
    Type_Struct(IR::ID name, const IR::TypeParameters* typeParameters);
    Type_Struct(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations);
    Type_Struct(IR::ID name, const IR::Annotations* annotations);
    Type_Struct(Util::SourceInfo srcInfo, IR::ID name);
    Type_Struct(IR::ID name);
    IRNODE_SUBCLASS(Type_Struct)
};
}  // namespace IR
namespace IR {
/// This is the type of a struct-valued expression whose
/// exact struct type is yet unknown; we only know the field names
/// and some information about their types.
class Type_UnknownStruct : public Type_StructLike {
 public:
    bool operator==(IR::Type_UnknownStruct const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_UnknownStruct"; }
    static cstring static_type_name() { return "Type_UnknownStruct"; }
    void toJSON(JSONGenerator & json) const override;
    Type_UnknownStruct(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_StructLike const & a) const override { return a == *this; }
    bool operator==(IR::Type_Declaration const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    Type_UnknownStruct(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    Type_UnknownStruct(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields);
    Type_UnknownStruct(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields);
    Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields);
    Type_UnknownStruct(IR::ID name, IR::IndexedVector<IR::StructField> fields);
    Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters);
    Type_UnknownStruct(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters);
    Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters);
    Type_UnknownStruct(IR::ID name, const IR::TypeParameters* typeParameters);
    Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations);
    Type_UnknownStruct(IR::ID name, const IR::Annotations* annotations);
    Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name);
    Type_UnknownStruct(IR::ID name);
    IRNODE_SUBCLASS(Type_UnknownStruct)
};
}  // namespace IR
namespace IR {
class Type_HeaderUnion : public Type_StructLike {
 public:
#line 343 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 1569 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"

#line 345 "/home/fengyong/Desktop/p4c/ir/type.def"
    int width_bits() const override;
#line 1573 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
/// start offset of any field in a union is 0
#line 351 "/home/fengyong/Desktop/p4c/ir/type.def"
    int getFieldBitOffset(cstring name) const;
#line 1577 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_HeaderUnion const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_HeaderUnion"; }
    static cstring static_type_name() { return "Type_HeaderUnion"; }
    void toJSON(JSONGenerator & json) const override;
    Type_HeaderUnion(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_StructLike const & a) const override { return a == *this; }
    bool operator==(IR::Type_Declaration const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    Type_HeaderUnion(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    Type_HeaderUnion(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields);
    Type_HeaderUnion(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields);
    Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields);
    Type_HeaderUnion(IR::ID name, IR::IndexedVector<IR::StructField> fields);
    Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters);
    Type_HeaderUnion(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters);
    Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters);
    Type_HeaderUnion(IR::ID name, const IR::TypeParameters* typeParameters);
    Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations);
    Type_HeaderUnion(IR::ID name, const IR::Annotations* annotations);
    Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name);
    Type_HeaderUnion(IR::ID name);
    IRNODE_SUBCLASS(Type_HeaderUnion)
};
}  // namespace IR
namespace IR {
class Type_Header : public Type_StructLike {
 public:
    static const cstring setValid;
    static const cstring setInvalid;
    static const cstring isValid;
#line 365 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 1616 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Header const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Header"; }
    static cstring static_type_name() { return "Type_Header"; }
    void toJSON(JSONGenerator & json) const override;
    Type_Header(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_StructLike const & a) const override { return a == *this; }
    bool operator==(IR::Type_Declaration const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Header(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    Type_Header(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    Type_Header(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    Type_Header(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    Type_Header(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields);
    Type_Header(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields);
    Type_Header(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields);
    Type_Header(IR::ID name, IR::IndexedVector<IR::StructField> fields);
    Type_Header(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters);
    Type_Header(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters);
    Type_Header(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters);
    Type_Header(IR::ID name, const IR::TypeParameters* typeParameters);
    Type_Header(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations);
    Type_Header(IR::ID name, const IR::Annotations* annotations);
    Type_Header(Util::SourceInfo srcInfo, IR::ID name);
    Type_Header(IR::ID name);
    IRNODE_SUBCLASS(Type_Header)
};
}  // namespace IR
namespace IR {
class Type_Set : public Type {
 public:
    const IR::Type* elementType = nullptr;
#line 370 "/home/fengyong/Desktop/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 1653 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 371 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 1656 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 372 "/home/fengyong/Desktop/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 1659 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 373 "/home/fengyong/Desktop/p4c/ir/type.def"
    int width_bits() const override;
#line 1662 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Set const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_Set"; }
    static cstring static_type_name() { return "Type_Set"; }
    void toJSON(JSONGenerator & json) const override;
    Type_Set(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Set(Util::SourceInfo srcInfo, const IR::Type* elementType);
    Type_Set(const IR::Type* elementType);
    IRNODE_SUBCLASS(Type_Set)
};
}  // namespace IR
namespace IR {
class Type_Indexed : public virtual INode {
 public:


#line 382 "/home/fengyong/Desktop/p4c/ir/type.def"
    virtual size_t getSize() const = 0;
#line 1687 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 383 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::Type *at(size_t index) const;
#line 1690 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
};
}  // namespace IR
namespace IR {
/// Base class for Type_List, and Type_Tuple
class Type_BaseList : public Type, public virtual Type_Indexed {
 public:
    IR::Vector<IR::Type> components;
#line 389 "/home/fengyong/Desktop/p4c/ir/type.def"
    void validate() const override;
#line 1700 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 390 "/home/fengyong/Desktop/p4c/ir/type.def"
    size_t getSize() const override;
#line 1703 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 391 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::Type *at(size_t index) const;
#line 1706 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 392 "/home/fengyong/Desktop/p4c/ir/type.def"
    int width_bits() const override;
#line 1709 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 399 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring asString(char const * name) const;
#line 1712 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 411 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 1715 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_BaseList const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "Type_BaseList"; }
    static cstring static_type_name() { return "Type_BaseList"; }
    void toJSON(JSONGenerator & json) const override;
    Type_BaseList(JSONLoader & json);
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
 protected:
    Type_BaseList(Util::SourceInfo srcInfo, IR::Vector<IR::Type> components);
    Type_BaseList(IR::Vector<IR::Type> components);
    Type_BaseList(Util::SourceInfo srcInfo);
    Type_BaseList();
    IRNODE_ABSTRACT_SUBCLASS(Type_BaseList)
};
}  // namespace IR
namespace IR {
/// The type of an expressionList; can be unified with both Type_Tuple and Type_Struct
class Type_List : public Type_BaseList {
 public:
#line 418 "/home/fengyong/Desktop/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 1740 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"

#line 420 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 1744 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_List const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_List"; }
    static cstring static_type_name() { return "Type_List"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_List(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_BaseList const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_List(Util::SourceInfo srcInfo, IR::Vector<IR::Type> components);
    Type_List(IR::Vector<IR::Type> components);
    Type_List(Util::SourceInfo srcInfo);
    Type_List();
    IRNODE_SUBCLASS(Type_List)
};
}  // namespace IR
namespace IR {
/// The type of a tuple.
class Type_Tuple : public Type_BaseList {
 public:
#line 427 "/home/fengyong/Desktop/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 1769 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 428 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 1772 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Tuple const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Tuple"; }
    static cstring static_type_name() { return "Type_Tuple"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_Tuple(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_BaseList const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Tuple(Util::SourceInfo srcInfo, IR::Vector<IR::Type> components);
    Type_Tuple(IR::Vector<IR::Type> components);
    Type_Tuple(Util::SourceInfo srcInfo);
    Type_Tuple();
    IRNODE_SUBCLASS(Type_Tuple)
};
}  // namespace IR
namespace IR {
/// The type of a P4ListExpression.
class Type_P4List : public Type {
 public:
    const IR::Type* elementType = nullptr;
#line 436 "/home/fengyong/Desktop/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 1798 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 437 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 1801 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_P4List const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_P4List"; }
    static cstring static_type_name() { return "Type_P4List"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_P4List(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_P4List(Util::SourceInfo srcInfo, const IR::Type* elementType);
    Type_P4List(const IR::Type* elementType);
    IRNODE_SUBCLASS(Type_P4List)
};
}  // namespace IR
namespace IR {
/// The type of an architectural block.
/// Abstract base for Type_Control, Type_Parser and Type_Package
class Type_ArchBlock : public Type_Declaration, public virtual IMayBeGenericType, public virtual IAnnotated, public virtual ISimpleNamespace {
 public:
    const IR::Annotations* annotations = Annotations::empty;
    const IR::TypeParameters* typeParameters = new TypeParameters;
#line 448 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::Annotations *getAnnotations() const override;
#line 1829 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 449 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::TypeParameters *getTypeParameters() const override;
#line 1832 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 450 "/home/fengyong/Desktop/p4c/ir/type.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 1835 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 452 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 1838 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_ArchBlock const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_ArchBlock"; }
    static cstring static_type_name() { return "Type_ArchBlock"; }
    void toJSON(JSONGenerator & json) const override;
    Type_ArchBlock(JSONLoader & json);
    bool operator==(IR::Type_Declaration const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
 protected:
    Type_ArchBlock(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters);
    Type_ArchBlock(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters);
    Type_ArchBlock(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters);
    Type_ArchBlock(IR::ID name, const IR::TypeParameters* typeParameters);
    Type_ArchBlock(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations);
    Type_ArchBlock(IR::ID name, const IR::Annotations* annotations);
    Type_ArchBlock(Util::SourceInfo srcInfo, IR::ID name);
    Type_ArchBlock(IR::ID name);
    IRNODE_ABSTRACT_SUBCLASS(Type_ArchBlock)
};
}  // namespace IR
namespace IR {
class Type_Package : public Type_ArchBlock, public virtual IContainer, public virtual ISimpleNamespace {
 public:
#line 457 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::Type *getType() const override;
#line 1868 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    const IR::ParameterList* constructorParams = nullptr;
#line 459 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::Type_Method *getConstructorMethodType() const override;
#line 1872 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 460 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::ParameterList *getConstructorParameters() const override;
#line 1875 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 461 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 1878 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 462 "/home/fengyong/Desktop/p4c/ir/type.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 1881 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 464 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 1884 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Package const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_Package"; }
    static cstring static_type_name() { return "Type_Package"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_Package(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_ArchBlock const & a) const override { return a == *this; }
    bool operator==(IR::Type_Declaration const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Package(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, const IR::ParameterList* constructorParams);
    Type_Package(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, const IR::ParameterList* constructorParams);
    Type_Package(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, const IR::ParameterList* constructorParams);
    Type_Package(IR::ID name, const IR::TypeParameters* typeParameters, const IR::ParameterList* constructorParams);
    Type_Package(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::ParameterList* constructorParams);
    Type_Package(IR::ID name, const IR::Annotations* annotations, const IR::ParameterList* constructorParams);
    Type_Package(Util::SourceInfo srcInfo, IR::ID name, const IR::ParameterList* constructorParams);
    Type_Package(IR::ID name, const IR::ParameterList* constructorParams);
    IRNODE_SUBCLASS(Type_Package)
};
}  // namespace IR
namespace IR {
class Type_Parser : public Type_ArchBlock, public virtual IApply {
 public:
    const IR::ParameterList* applyParams = nullptr;
#line 472 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::Type_Method *getApplyMethodType() const override;
#line 1917 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 473 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::ParameterList *getApplyParameters() const override;
#line 1920 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 474 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 1923 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Parser const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_Parser"; }
    static cstring static_type_name() { return "Type_Parser"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_Parser(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_ArchBlock const & a) const override { return a == *this; }
    bool operator==(IR::Type_Declaration const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams);
    Type_Parser(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams);
    Type_Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams);
    Type_Parser(IR::ID name, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams);
    Type_Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::ParameterList* applyParams);
    Type_Parser(IR::ID name, const IR::Annotations* annotations, const IR::ParameterList* applyParams);
    Type_Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::ParameterList* applyParams);
    Type_Parser(IR::ID name, const IR::ParameterList* applyParams);
    IRNODE_SUBCLASS(Type_Parser)
};
}  // namespace IR
namespace IR {
class Type_Control : public Type_ArchBlock, public virtual IApply {
 public:
    const IR::ParameterList* applyParams = nullptr;
#line 479 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::Type_Method *getApplyMethodType() const override;
#line 1956 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 480 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::ParameterList *getApplyParameters() const override;
#line 1959 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 481 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 1962 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Control const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_Control"; }
    static cstring static_type_name() { return "Type_Control"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_Control(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_ArchBlock const & a) const override { return a == *this; }
    bool operator==(IR::Type_Declaration const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams);
    Type_Control(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams);
    Type_Control(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams);
    Type_Control(IR::ID name, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams);
    Type_Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::ParameterList* applyParams);
    Type_Control(IR::ID name, const IR::Annotations* annotations, const IR::ParameterList* applyParams);
    Type_Control(Util::SourceInfo srcInfo, IR::ID name, const IR::ParameterList* applyParams);
    Type_Control(IR::ID name, const IR::ParameterList* applyParams);
    IRNODE_SUBCLASS(Type_Control)
};
}  // namespace IR
namespace IR {
/// A type referred by name
class Type_Name : public Type {
 public:
    const IR::Path* path = nullptr;
#line 487 "/home/fengyong/Desktop/p4c/ir/type.def"
    Type_Name(IR::ID id);
#line 1996 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 488 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 1999 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 489 "/home/fengyong/Desktop/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 2002 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 490 "/home/fengyong/Desktop/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 2005 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 491 "/home/fengyong/Desktop/p4c/ir/type.def"
    int width_bits() const override;
#line 2008 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Name const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_Name"; }
    static cstring static_type_name() { return "Type_Name"; }
    void toJSON(JSONGenerator & json) const override;
    Type_Name(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Name(Util::SourceInfo srcInfo, const IR::Path* path);
    Type_Name(const IR::Path* path);
    IRNODE_SUBCLASS(Type_Name)
};
}  // namespace IR
namespace IR {
class Type_Stack : public virtual Type_Indexed, public Type {
 public:
    const IR::Type* elementType = nullptr;
    const IR::Expression* size = nullptr;
#line 500 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 2033 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 502 "/home/fengyong/Desktop/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 2036 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 503 "/home/fengyong/Desktop/p4c/ir/type.def"
    bool sizeKnown() const;
#line 2039 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 504 "/home/fengyong/Desktop/p4c/ir/type.def"
    size_t getSize() const override;
#line 2042 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 505 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::Type *at(size_t index) const;
#line 2045 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    static const cstring next;
    static const cstring last;
    static const cstring arraySize;
    static const cstring lastIndex;
    static const cstring push_front;
    static const cstring pop_front;
#line 512 "/home/fengyong/Desktop/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 2054 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Stack const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_Stack"; }
    static cstring static_type_name() { return "Type_Stack"; }
    void toJSON(JSONGenerator & json) const override;
    Type_Stack(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Stack(Util::SourceInfo srcInfo, const IR::Type* elementType, const IR::Expression* size);
    Type_Stack(const IR::Type* elementType, const IR::Expression* size);
    IRNODE_SUBCLASS(Type_Stack)
};
}  // namespace IR
namespace IR {
/** Given a declaration
   extern E<T> { ... }
   Type_Specialized represents a type such
   E<bit<32>>
   baseType is Type_Name E, arguments is a vector containing Type_Bits(32) */
class Type_Specialized : public Type {
 public:
    const IR::Type_Name* baseType = nullptr;
    const IR::Vector<IR::Type>* arguments = nullptr;
#line 524 "/home/fengyong/Desktop/p4c/ir/type.def"
    void validate() const override;
#line 2084 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 525 "/home/fengyong/Desktop/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 2087 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 526 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 2090 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 536 "/home/fengyong/Desktop/p4c/ir/type.def"
    Type_Specialized(cstring bt, std::initializer_list<const IR::Type *> args);
#line 2093 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Specialized const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "Type_Specialized"; }
    static cstring static_type_name() { return "Type_Specialized"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_Specialized(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Specialized(Util::SourceInfo srcInfo, const IR::Type_Name* baseType, const IR::Vector<IR::Type>* arguments);
    Type_Specialized(const IR::Type_Name* baseType, const IR::Vector<IR::Type>* arguments);
    IRNODE_SUBCLASS(Type_Specialized)
};
}  // namespace IR
namespace IR {
/** Canonical representation of a Type_Specialized;
   only used by the type-checker, never in the IR tree. */
class Type_SpecializedCanonical : public Type {
 public:
    const IR::Type* baseType = nullptr;
/// canonical baseType; always IMayBeGenericType
    const IR::Vector<IR::Type>* arguments = nullptr;
/// canonical type arguments
/// 'substituted' is baseType with all type
/// variables substituted with the arguments.
    const IR::Type* substituted = nullptr;

#line 549 "/home/fengyong/Desktop/p4c/ir/type.def"
    void validate() const override;
#line 2126 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 554 "/home/fengyong/Desktop/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 2129 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 555 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 2132 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_SpecializedCanonical const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "Type_SpecializedCanonical"; }
    static cstring static_type_name() { return "Type_SpecializedCanonical"; }
    void toJSON(JSONGenerator & json) const override;
    Type_SpecializedCanonical(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_SpecializedCanonical(Util::SourceInfo srcInfo, const IR::Type* baseType, const IR::Vector<IR::Type>* arguments, const IR::Type* substituted);
    Type_SpecializedCanonical(const IR::Type* baseType, const IR::Vector<IR::Type>* arguments, const IR::Type* substituted);
    IRNODE_SUBCLASS(Type_SpecializedCanonical)
};
}  // namespace IR
namespace IR {
/// A declaration that consists of just an identifier, e.g., an enum member
class Declaration_ID : public Declaration, public virtual CompileTimeValue {
 public:
    bool operator==(IR::Declaration_ID const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Declaration_ID"; }
    static cstring static_type_name() { return "Declaration_ID"; }
    void toJSON(JSONGenerator & json) const override;
    Declaration_ID(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override { return a == *this; }
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Declaration_ID(Util::SourceInfo srcInfo, IR::ID name);
    Declaration_ID(IR::ID name);
    IRNODE_SUBCLASS(Declaration_ID)
};
}  // namespace IR
namespace IR {
/// The type of a string literal
class Type_String : public Type_Base {
 public:
#line 566 "/home/fengyong/Desktop/p4c/ir/type.def"
    static const IR::Type_String *get();
#line 2174 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 567 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 2177 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_String const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_String"; }
    static cstring static_type_name() { return "Type_String"; }
    void toJSON(JSONGenerator & json) const override;
    Type_String(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_String(Util::SourceInfo srcInfo);
    Type_String();
    IRNODE_SUBCLASS(Type_String)
};
}  // namespace IR
namespace IR {
class Type_Enum : public Type_Declaration, public virtual ISimpleNamespace, public virtual IAnnotated {
 public:
    const IR::Annotations* annotations = Annotations::empty;
    IR::IndexedVector<IR::Declaration_ID> members;
#line 573 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::Annotations *getAnnotations() const override;
#line 2200 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 574 "/home/fengyong/Desktop/p4c/ir/type.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 2203 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 576 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 2206 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 579 "/home/fengyong/Desktop/p4c/ir/type.def"
    void validate() const override;
#line 2209 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Enum const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "Type_Enum"; }
    static cstring static_type_name() { return "Type_Enum"; }
    void toJSON(JSONGenerator & json) const override;
    Type_Enum(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Declaration const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Enum(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::Declaration_ID> members);
    Type_Enum(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::Declaration_ID> members);
    Type_Enum(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::Declaration_ID> members);
    Type_Enum(IR::ID name, IR::IndexedVector<IR::Declaration_ID> members);
    IRNODE_SUBCLASS(Type_Enum)
};
}  // namespace IR
namespace IR {
/// A member of a serializable enum with a backing value
class SerEnumMember : public Declaration, public virtual CompileTimeValue {
 public:
    const IR::Expression* value = nullptr;
#line 585 "/home/fengyong/Desktop/p4c/ir/type.def"
    void validate() const override;
#line 2236 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::SerEnumMember const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "SerEnumMember"; }
    static cstring static_type_name() { return "SerEnumMember"; }
    void toJSON(JSONGenerator & json) const override;
    SerEnumMember(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override { return a == *this; }
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    SerEnumMember(Util::SourceInfo srcInfo, IR::ID name, const IR::Expression* value);
    SerEnumMember(IR::ID name, const IR::Expression* value);
    IRNODE_SUBCLASS(SerEnumMember)
};
}  // namespace IR
namespace IR {
/** A serializable enumeration with a backing type */
class Type_SerEnum : public Type_Declaration, public virtual ISimpleNamespace, public virtual IAnnotated {
 public:
    const IR::Annotations* annotations = Annotations::empty;
    const IR::Type* type = nullptr;
    IR::IndexedVector<IR::SerEnumMember> members;
#line 594 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::Annotations *getAnnotations() const override;
#line 2263 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 595 "/home/fengyong/Desktop/p4c/ir/type.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 2266 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 597 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 2269 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 600 "/home/fengyong/Desktop/p4c/ir/type.def"
    void validate() const override;
#line 2272 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_SerEnum const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "Type_SerEnum"; }
    static cstring static_type_name() { return "Type_SerEnum"; }
    void toJSON(JSONGenerator & json) const override;
    Type_SerEnum(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Declaration const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_SerEnum(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type, IR::IndexedVector<IR::SerEnumMember> members);
    Type_SerEnum(IR::ID name, const IR::Annotations* annotations, const IR::Type* type, IR::IndexedVector<IR::SerEnumMember> members);
    Type_SerEnum(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type, IR::IndexedVector<IR::SerEnumMember> members);
    Type_SerEnum(IR::ID name, const IR::Type* type, IR::IndexedVector<IR::SerEnumMember> members);
    IRNODE_SUBCLASS(Type_SerEnum)
};
}  // namespace IR
namespace IR {
class Type_Table : public Type, public virtual IApply {
 public:
    const IR::P4Table* table = nullptr;
#line 605 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::Type_Method *getApplyMethodType() const override;
#line 2298 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 606 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::ParameterList *getApplyParameters() const override;
#line 2301 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
/// names for the fields of the struct returned
/// by applying a table
    static const IR::ID hit;
    static const IR::ID miss;
    static const IR::ID action_run;
#line 612 "/home/fengyong/Desktop/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 2309 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 613 "/home/fengyong/Desktop/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 2312 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Table const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_Table"; }
    static cstring static_type_name() { return "Type_Table"; }
    void toJSON(JSONGenerator & json) const override;
    Type_Table(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Table(Util::SourceInfo srcInfo, const IR::P4Table* table);
    Type_Table(const IR::P4Table* table);
    IRNODE_SUBCLASS(Type_Table)
};
}  // namespace IR
namespace IR {
/// A special enum-like anonymous type that
/// represents all actions in a table's action list.
/// Used for 'switch' statements.
class Type_ActionEnum : public Type {
 public:
    const IR::ActionList* actionList = nullptr;
#line 621 "/home/fengyong/Desktop/p4c/ir/type.def"
    bool contains(cstring name) const;
#line 2339 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 622 "/home/fengyong/Desktop/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 2342 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_ActionEnum const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_ActionEnum"; }
    static cstring static_type_name() { return "Type_ActionEnum"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_ActionEnum(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_ActionEnum(Util::SourceInfo srcInfo, const IR::ActionList* actionList);
    Type_ActionEnum(const IR::ActionList* actionList);
    IRNODE_SUBCLASS(Type_ActionEnum)
};
}  // namespace IR
namespace IR {
class Type_MethodBase : public Type, public virtual IMayBeGenericType, public virtual ISimpleNamespace {
 public:

    const IR::TypeParameters* typeParameters = new TypeParameters();
    const IR::Type* returnType = nullptr;

    const IR::ParameterList* parameters = nullptr;
#line 632 "/home/fengyong/Desktop/p4c/ir/type.def"
    size_t maxParameterCount() const;
#line 2371 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 633 "/home/fengyong/Desktop/p4c/ir/type.def"
    size_t minParameterCount() const;
#line 2374 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 634 "/home/fengyong/Desktop/p4c/ir/type.def"
    virtual const IR::TypeParameters *getTypeParameters() const override;
#line 2377 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 635 "/home/fengyong/Desktop/p4c/ir/type.def"
    void dbprint(std::ostream & out) const override;
#line 2380 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 636 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 2383 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 637 "/home/fengyong/Desktop/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 2386 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 638 "/home/fengyong/Desktop/p4c/ir/type.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 2389 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 640 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 2392 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_MethodBase const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_MethodBase"; }
    static cstring static_type_name() { return "Type_MethodBase"; }
    void toJSON(JSONGenerator & json) const override;
    Type_MethodBase(JSONLoader & json);
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
 protected:
    Type_MethodBase(Util::SourceInfo srcInfo, const IR::TypeParameters* typeParameters, const IR::Type* returnType, const IR::ParameterList* parameters);
    Type_MethodBase(const IR::TypeParameters* typeParameters, const IR::Type* returnType, const IR::ParameterList* parameters);
    Type_MethodBase(Util::SourceInfo srcInfo, const IR::Type* returnType, const IR::ParameterList* parameters);
    Type_MethodBase(const IR::Type* returnType, const IR::ParameterList* parameters);
    Type_MethodBase(Util::SourceInfo srcInfo, const IR::TypeParameters* typeParameters, const IR::ParameterList* parameters);
    Type_MethodBase(const IR::TypeParameters* typeParameters, const IR::ParameterList* parameters);
    Type_MethodBase(Util::SourceInfo srcInfo, const IR::ParameterList* parameters);
    Type_MethodBase(const IR::ParameterList* parameters);
    IRNODE_ABSTRACT_SUBCLASS(Type_MethodBase)
};
}  // namespace IR
namespace IR {
/// Type for a method or function.
class Type_Method : public Type_MethodBase {
 public:

    cstring name;
#line 651 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 2424 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Method const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Method"; }
    static cstring static_type_name() { return "Type_Method"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_Method(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_MethodBase const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Method(Util::SourceInfo srcInfo, const IR::TypeParameters* typeParameters, const IR::Type* returnType, const IR::ParameterList* parameters, cstring name);
    Type_Method(const IR::TypeParameters* typeParameters, const IR::Type* returnType, const IR::ParameterList* parameters, cstring name);
    Type_Method(Util::SourceInfo srcInfo, const IR::Type* returnType, const IR::ParameterList* parameters, cstring name);
    Type_Method(const IR::Type* returnType, const IR::ParameterList* parameters, cstring name);
    Type_Method(Util::SourceInfo srcInfo, const IR::TypeParameters* typeParameters, const IR::ParameterList* parameters, cstring name);
    Type_Method(const IR::TypeParameters* typeParameters, const IR::ParameterList* parameters, cstring name);
    Type_Method(Util::SourceInfo srcInfo, const IR::ParameterList* parameters, cstring name);
    Type_Method(const IR::ParameterList* parameters, cstring name);
    IRNODE_SUBCLASS(Type_Method)
};
}  // namespace IR
namespace IR {
/// Describes an argument of a MethodCall
/// Never used in the program IR; only used by typechecker.
class ArgumentInfo : public Node {
 public:
    bool leftValue;
    bool compileTimeConstant;
    const IR::Type* type = nullptr;
    const IR::Argument* argument = nullptr;
#line 661 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 2458 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ArgumentInfo const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "ArgumentInfo"; }
    static cstring static_type_name() { return "ArgumentInfo"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ArgumentInfo(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    ArgumentInfo(Util::SourceInfo srcInfo, bool leftValue, bool compileTimeConstant, const IR::Type* type, const IR::Argument* argument);
    ArgumentInfo(bool leftValue, bool compileTimeConstant, const IR::Type* type, const IR::Argument* argument);
    IRNODE_SUBCLASS(ArgumentInfo)
};
}  // namespace IR
namespace IR {
/// Used to represent the type of a MethodCallExpression
/// for unification.
/// Never appears in the program IR; only used by the typechecker.
class Type_MethodCall : public Type {
 public:
    const IR::Vector<IR::Type>* typeArguments = nullptr;
    const IR::Type_Var* returnType = nullptr;
    const IR::Vector<IR::ArgumentInfo>* arguments = nullptr;
#line 672 "/home/fengyong/Desktop/p4c/ir/type.def"
    void validate() const override;
#line 2487 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 673 "/home/fengyong/Desktop/p4c/ir/type.def"
    IR::Type const * getP4Type() const override;
#line 2490 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 674 "/home/fengyong/Desktop/p4c/ir/type.def"
    cstring toString() const override;
#line 2493 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_MethodCall const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "Type_MethodCall"; }
    static cstring static_type_name() { return "Type_MethodCall"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_MethodCall(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_MethodCall(Util::SourceInfo srcInfo, const IR::Vector<IR::Type>* typeArguments, const IR::Type_Var* returnType, const IR::Vector<IR::ArgumentInfo>* arguments);
    Type_MethodCall(const IR::Vector<IR::Type>* typeArguments, const IR::Type_Var* returnType, const IR::Vector<IR::ArgumentInfo>* arguments);
    IRNODE_SUBCLASS(Type_MethodCall)
};
}  // namespace IR
namespace IR {
/// Actions look a lot like methods in many respects.
/// However, invoking an action returns another action
/// Having different IR nodes allows performing different transforms in visitors
class Type_Action : public Type_MethodBase {
 public:
    bool operator==(IR::Type_Action const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Action"; }
    static cstring static_type_name() { return "Type_Action"; }
    void toJSON(JSONGenerator & json) const override;
    Type_Action(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_MethodBase const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Action(Util::SourceInfo srcInfo, const IR::TypeParameters* typeParameters, const IR::Type* returnType, const IR::ParameterList* parameters);
    Type_Action(const IR::TypeParameters* typeParameters, const IR::Type* returnType, const IR::ParameterList* parameters);
    Type_Action(Util::SourceInfo srcInfo, const IR::Type* returnType, const IR::ParameterList* parameters);
    Type_Action(const IR::Type* returnType, const IR::ParameterList* parameters);
    Type_Action(Util::SourceInfo srcInfo, const IR::TypeParameters* typeParameters, const IR::ParameterList* parameters);
    Type_Action(const IR::TypeParameters* typeParameters, const IR::ParameterList* parameters);
    Type_Action(Util::SourceInfo srcInfo, const IR::ParameterList* parameters);
    Type_Action(const IR::ParameterList* parameters);
    IRNODE_SUBCLASS(Type_Action)
};
}  // namespace IR
namespace IR {
class Method : public Declaration, public virtual IAnnotated, public virtual IFunctional, public virtual ISimpleNamespace {
 public:
    const IR::Type_Method* type = nullptr;
    bool isAbstract = false;
    const IR::Annotations* annotations = Annotations::empty;
#line 688 "/home/fengyong/Desktop/p4c/ir/type.def"
    size_t maxParameterCount() const;
#line 2546 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 689 "/home/fengyong/Desktop/p4c/ir/type.def"
    size_t minParameterCount() const;
#line 2549 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 690 "/home/fengyong/Desktop/p4c/ir/type.def"
    void setAbstract();
#line 2552 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 691 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::Annotations *getAnnotations() const override;
#line 2555 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 692 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::ParameterList *getParameters() const override;
#line 2558 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"

#line 694 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 2562 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 696 "/home/fengyong/Desktop/p4c/ir/type.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 2565 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Method const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Method"; }
    static cstring static_type_name() { return "Method"; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Method(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override { return a == *this; }
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Method(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Method* type, bool isAbstract, const IR::Annotations* annotations);
    Method(IR::ID name, const IR::Type_Method* type, bool isAbstract, const IR::Annotations* annotations);
    Method(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Method* type, const IR::Annotations* annotations);
    Method(IR::ID name, const IR::Type_Method* type, const IR::Annotations* annotations);
    Method(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Method* type, bool isAbstract);
    Method(IR::ID name, const IR::Type_Method* type, bool isAbstract);
    Method(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Method* type);
    Method(IR::ID name, const IR::Type_Method* type);
    IRNODE_SUBCLASS(Method)
};
}  // namespace IR
namespace IR {
class Type_Typedef : public Type_Declaration, public virtual IAnnotated {
 public:
    const IR::Annotations* annotations = Annotations::empty;
    const IR::Type* type = nullptr;
#line 703 "/home/fengyong/Desktop/p4c/ir/type.def"
    int width_bits() const override;
#line 2599 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 704 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::Annotations *getAnnotations() const override;
#line 2602 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Typedef const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_Typedef"; }
    static cstring static_type_name() { return "Type_Typedef"; }
    void toJSON(JSONGenerator & json) const override;
    Type_Typedef(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Declaration const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Typedef(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type);
    Type_Typedef(IR::ID name, const IR::Annotations* annotations, const IR::Type* type);
    Type_Typedef(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type);
    Type_Typedef(IR::ID name, const IR::Type* type);
    IRNODE_SUBCLASS(Type_Typedef)
};
}  // namespace IR
namespace IR {
/// A newtype is similar to typedef, but it introduces a new type; the
/// the new type does not inherit any
/// of the operations of the original type.  The new type has
/// assignment, equality, and casts to/from the original type.
/// The keyword for newtype is actually `type'.
class Type_Newtype : public Type_Declaration, public virtual IAnnotated {
 public:
    const IR::Annotations* annotations = Annotations::empty;
    const IR::Type* type = nullptr;
#line 716 "/home/fengyong/Desktop/p4c/ir/type.def"
    int width_bits() const override;
#line 2635 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 717 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::Annotations *getAnnotations() const override;
#line 2638 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Newtype const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Type_Newtype"; }
    static cstring static_type_name() { return "Type_Newtype"; }
    void toJSON(JSONGenerator & json) const override;
    Type_Newtype(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Declaration const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Newtype(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type);
    Type_Newtype(IR::ID name, const IR::Annotations* annotations, const IR::Type* type);
    Type_Newtype(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type);
    Type_Newtype(IR::ID name, const IR::Type* type);
    IRNODE_SUBCLASS(Type_Newtype)
};
}  // namespace IR
namespace IR {
/// An 'extern' black-box (not a function)
class Type_Extern : public Type_Declaration, public virtual INestedNamespace, public virtual IGeneralNamespace, public virtual IMayBeGenericType, public virtual IAnnotated {
 public:
    const IR::TypeParameters* typeParameters = new TypeParameters;
    IR::Vector<IR::Method> methods;

    IR::NameMap<IR::Attribute, ordered_map> attributes;

    const IR::Annotations* annotations = Annotations::empty;
#line 729 "/home/fengyong/Desktop/p4c/ir/type.def"
    std::vector<const IR::INamespace *> getNestedNamespaces() const override;
#line 2671 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 730 "/home/fengyong/Desktop/p4c/ir/type.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 2674 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 733 "/home/fengyong/Desktop/p4c/ir/type.def"
    virtual const IR::TypeParameters *getTypeParameters() const override;
#line 2677 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 734 "/home/fengyong/Desktop/p4c/ir/type.def"
    void validate() const override;
#line 2680 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 735 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::Annotations *getAnnotations() const override;
#line 2683 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
/// Returns the method that matches the specified arguments.
/// Returns nullptr if no method or more than one method match.
/// In the latter case it also reports an error.
#line 739 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::Method *lookupMethod(IR::ID name, const IR::Vector<IR::Argument>* arguments) const;
#line 2689 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
/// Returns the constructor that matches the specified arguments.
/// Returns nullptr if no constructor or more than one constructor matches.
/// In the latter case it also reports an error.
#line 743 "/home/fengyong/Desktop/p4c/ir/type.def"
    const IR::Method *lookupConstructor(const IR::Vector<IR::Argument>* arguments) const;
#line 2695 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Extern const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "Type_Extern"; }
    static cstring static_type_name() { return "Type_Extern"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_Extern(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Declaration const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes, const IR::Annotations* annotations);
    Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes, const IR::Annotations* annotations);
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes, const IR::Annotations* annotations);
    Type_Extern(IR::ID name, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes, const IR::Annotations* annotations);
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::NameMap<IR::Attribute, ordered_map> attributes, const IR::Annotations* annotations);
    Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, IR::NameMap<IR::Attribute, ordered_map> attributes, const IR::Annotations* annotations);
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, IR::NameMap<IR::Attribute, ordered_map> attributes, const IR::Annotations* annotations);
    Type_Extern(IR::ID name, IR::NameMap<IR::Attribute, ordered_map> attributes, const IR::Annotations* annotations);
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods, const IR::Annotations* annotations);
    Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods, const IR::Annotations* annotations);
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Method> methods, const IR::Annotations* annotations);
    Type_Extern(IR::ID name, IR::Vector<IR::Method> methods, const IR::Annotations* annotations);
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, const IR::Annotations* annotations);
    Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, const IR::Annotations* annotations);
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations);
    Type_Extern(IR::ID name, const IR::Annotations* annotations);
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes);
    Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes);
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes);
    Type_Extern(IR::ID name, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes);
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::NameMap<IR::Attribute, ordered_map> attributes);
    Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, IR::NameMap<IR::Attribute, ordered_map> attributes);
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, IR::NameMap<IR::Attribute, ordered_map> attributes);
    Type_Extern(IR::ID name, IR::NameMap<IR::Attribute, ordered_map> attributes);
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods);
    Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods);
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Method> methods);
    Type_Extern(IR::ID name, IR::Vector<IR::Method> methods);
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters);
    Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters);
    Type_Extern(Util::SourceInfo srcInfo, IR::ID name);
    Type_Extern(IR::ID name);
    IRNODE_SUBCLASS(Type_Extern)
};
}  // namespace IR
namespace IR {
/** @} */
/* end group irdefs */
/* -*-C++-*- */
/* This file contains the IR classes for all expressions.
   The base classes are in base.def */
/** \addtogroup irdefs
  * @{
  */
class Operation_Unary : public Operation {
 public:
    const IR::Expression* expr = nullptr;
    int getPrecedence() const override { return DBPrint::Prec_Prefix; }
#line 15 "/home/fengyong/Desktop/p4c/ir/expression.def"
    cstring toString() const override;
#line 2759 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Operation_Unary const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Operation_Unary"; }
    static cstring static_type_name() { return "Operation_Unary"; }
    void toJSON(JSONGenerator & json) const override;
    Operation_Unary(JSONLoader & json);
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
 protected:
    Operation_Unary(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr);
    Operation_Unary(const IR::Type* type, const IR::Expression* expr);
    Operation_Unary(Util::SourceInfo srcInfo, const IR::Expression* expr);
    Operation_Unary(const IR::Expression* expr);
    IRNODE_ABSTRACT_SUBCLASS(Operation_Unary)
};
}  // namespace IR
namespace IR {
class Neg : public Operation_Unary {
 public:
    cstring getStringOp() const override { return "-"; }
    bool operator==(IR::Neg const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Neg"; }
    static cstring static_type_name() { return "Neg"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Neg(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Unary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Neg(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr);
    Neg(const IR::Type* type, const IR::Expression* expr);
    Neg(Util::SourceInfo srcInfo, const IR::Expression* expr);
    Neg(const IR::Expression* expr);
    IRNODE_SUBCLASS(Neg)
};
}  // namespace IR
namespace IR {
class UPlus : public Operation_Unary {
 public:
    cstring getStringOp() const override { return "+"; }
    bool operator==(IR::UPlus const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "UPlus"; }
    static cstring static_type_name() { return "UPlus"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    UPlus(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Unary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    UPlus(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr);
    UPlus(const IR::Type* type, const IR::Expression* expr);
    UPlus(Util::SourceInfo srcInfo, const IR::Expression* expr);
    UPlus(const IR::Expression* expr);
    IRNODE_SUBCLASS(UPlus)
};
}  // namespace IR
namespace IR {
class Cmpl : public Operation_Unary {
 public:
    cstring getStringOp() const override { return "~"; }
    bool operator==(IR::Cmpl const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Cmpl"; }
    static cstring static_type_name() { return "Cmpl"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Cmpl(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Unary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Cmpl(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr);
    Cmpl(const IR::Type* type, const IR::Expression* expr);
    Cmpl(Util::SourceInfo srcInfo, const IR::Expression* expr);
    Cmpl(const IR::Expression* expr);
    IRNODE_SUBCLASS(Cmpl)
};
}  // namespace IR
namespace IR {
class LNot : public Operation_Unary {
 public:
    cstring getStringOp() const override { return "!"; }
    bool operator==(IR::LNot const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "LNot"; }
    static cstring static_type_name() { return "LNot"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    LNot(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Unary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    LNot(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr);
    LNot(const IR::Type* type, const IR::Expression* expr);
    LNot(Util::SourceInfo srcInfo, const IR::Expression* expr);
    LNot(const IR::Expression* expr);
    IRNODE_SUBCLASS(LNot)
};
}  // namespace IR
namespace IR {
class Operation_Binary : public Operation {
 public:
    const IR::Expression* left = nullptr;
    const IR::Expression* right = nullptr;
#line 41 "/home/fengyong/Desktop/p4c/ir/expression.def"
    cstring toString() const override;
#line 2879 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Operation_Binary const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Operation_Binary"; }
    static cstring static_type_name() { return "Operation_Binary"; }
    void toJSON(JSONGenerator & json) const override;
    Operation_Binary(JSONLoader & json);
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
 protected:
    Operation_Binary(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Operation_Binary(const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Operation_Binary(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    Operation_Binary(const IR::Expression* left, const IR::Expression* right);
    IRNODE_ABSTRACT_SUBCLASS(Operation_Binary)
};
}  // namespace IR
namespace IR {
class Operation_Ternary : public Operation {
 public:
    const IR::Expression* e0 = nullptr;
    const IR::Expression* e1 = nullptr;
    const IR::Expression* e2 = nullptr;
    bool operator==(IR::Operation_Ternary const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Operation_Ternary"; }
    static cstring static_type_name() { return "Operation_Ternary"; }
    void toJSON(JSONGenerator & json) const override;
    Operation_Ternary(JSONLoader & json);
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
 protected:
    Operation_Ternary(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2);
    Operation_Ternary(const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2);
    Operation_Ternary(Util::SourceInfo srcInfo, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2);
    Operation_Ternary(const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2);
    IRNODE_ABSTRACT_SUBCLASS(Operation_Ternary)
};
}  // namespace IR
namespace IR {
class Operation_Relation : public Operation_Binary {
 public:
    bool operator==(IR::Operation_Relation const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Operation_Relation"; }
    static cstring static_type_name() { return "Operation_Relation"; }
    void toJSON(JSONGenerator & json) const override;
    Operation_Relation(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
 protected:
    Operation_Relation(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Operation_Relation(const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Operation_Relation(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    Operation_Relation(const IR::Expression* left, const IR::Expression* right);
    IRNODE_ABSTRACT_SUBCLASS(Operation_Relation)
};
}  // namespace IR
namespace IR {
class Mul : public Operation_Binary {
 public:
    cstring getStringOp() const override { return "*"; }
    int getPrecedence() const override { return DBPrint::Prec_Mul; }
    bool operator==(IR::Mul const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Mul"; }
    static cstring static_type_name() { return "Mul"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Mul(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Mul(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Mul(const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Mul(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    Mul(const IR::Expression* left, const IR::Expression* right);
    IRNODE_SUBCLASS(Mul)
};
}  // namespace IR
namespace IR {
class Div : public Operation_Binary {
 public:
    cstring getStringOp() const override { return "/"; }
    int getPrecedence() const override { return DBPrint::Prec_Div; }
    bool operator==(IR::Div const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Div"; }
    static cstring static_type_name() { return "Div"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Div(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Div(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Div(const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Div(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    Div(const IR::Expression* left, const IR::Expression* right);
    IRNODE_SUBCLASS(Div)
};
}  // namespace IR
namespace IR {
class Mod : public Operation_Binary {
 public:
    cstring getStringOp() const override { return "%"; }
    int getPrecedence() const override { return DBPrint::Prec_Mod; }
    bool operator==(IR::Mod const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Mod"; }
    static cstring static_type_name() { return "Mod"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Mod(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Mod(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Mod(const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Mod(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    Mod(const IR::Expression* left, const IR::Expression* right);
    IRNODE_SUBCLASS(Mod)
};
}  // namespace IR
namespace IR {
class Add : public Operation_Binary {
 public:
    cstring getStringOp() const override { return "+"; }
    int getPrecedence() const override { return DBPrint::Prec_Add; }
    bool operator==(IR::Add const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Add"; }
    static cstring static_type_name() { return "Add"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Add(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Add(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Add(const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Add(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    Add(const IR::Expression* left, const IR::Expression* right);
    IRNODE_SUBCLASS(Add)
};
}  // namespace IR
namespace IR {
class Sub : public Operation_Binary {
 public:
    cstring getStringOp() const override { return "-"; }
    int getPrecedence() const override { return DBPrint::Prec_Sub; }
    bool operator==(IR::Sub const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Sub"; }
    static cstring static_type_name() { return "Sub"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Sub(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Sub(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Sub(const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Sub(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    Sub(const IR::Expression* left, const IR::Expression* right);
    IRNODE_SUBCLASS(Sub)
};
}  // namespace IR
namespace IR {
class AddSat : public Operation_Binary {
 public:
    cstring getStringOp() const override { return "|+|"; }
    int getPrecedence() const override { return DBPrint::Prec_AddSat; }
    bool operator==(IR::AddSat const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "AddSat"; }
    static cstring static_type_name() { return "AddSat"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    AddSat(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    AddSat(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    AddSat(const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    AddSat(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    AddSat(const IR::Expression* left, const IR::Expression* right);
    IRNODE_SUBCLASS(AddSat)
};
}  // namespace IR
namespace IR {
class SubSat : public Operation_Binary {
 public:
    cstring getStringOp() const override { return "|-|"; }
    int getPrecedence() const override { return DBPrint::Prec_SubSat; }
    bool operator==(IR::SubSat const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "SubSat"; }
    static cstring static_type_name() { return "SubSat"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    SubSat(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    SubSat(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    SubSat(const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    SubSat(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    SubSat(const IR::Expression* left, const IR::Expression* right);
    IRNODE_SUBCLASS(SubSat)
};
}  // namespace IR
namespace IR {
class Shl : public Operation_Binary {
 public:
    cstring getStringOp() const override { return "<<"; }
    int getPrecedence() const override { return DBPrint::Prec_Shl; }
    bool operator==(IR::Shl const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Shl"; }
    static cstring static_type_name() { return "Shl"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Shl(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Shl(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Shl(const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Shl(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    Shl(const IR::Expression* left, const IR::Expression* right);
    IRNODE_SUBCLASS(Shl)
};
}  // namespace IR
namespace IR {
class Shr : public Operation_Binary {
 public:
    cstring getStringOp() const override { return ">>"; }
    int getPrecedence() const override { return DBPrint::Prec_Shr; }
    bool operator==(IR::Shr const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Shr"; }
    static cstring static_type_name() { return "Shr"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Shr(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Shr(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Shr(const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Shr(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    Shr(const IR::Expression* left, const IR::Expression* right);
    IRNODE_SUBCLASS(Shr)
};
}  // namespace IR
namespace IR {
class Equ : public Operation_Relation {
 public:
    cstring getStringOp() const override { return "=="; }
    int getPrecedence() const override { return DBPrint::Prec_Equ; }
    bool operator==(IR::Equ const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Equ"; }
    static cstring static_type_name() { return "Equ"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Equ(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Relation const & a) const override { return a == *this; }
    bool operator==(IR::Operation_Binary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Equ(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Equ(const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Equ(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    Equ(const IR::Expression* left, const IR::Expression* right);
    IRNODE_SUBCLASS(Equ)
};
}  // namespace IR
namespace IR {
class Neq : public Operation_Relation {
 public:
    cstring getStringOp() const override { return "!="; }
    int getPrecedence() const override { return DBPrint::Prec_Neq; }
    bool operator==(IR::Neq const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Neq"; }
    static cstring static_type_name() { return "Neq"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Neq(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Relation const & a) const override { return a == *this; }
    bool operator==(IR::Operation_Binary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Neq(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Neq(const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Neq(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    Neq(const IR::Expression* left, const IR::Expression* right);
    IRNODE_SUBCLASS(Neq)
};
}  // namespace IR
namespace IR {
class Lss : public Operation_Relation {
 public:
    cstring getStringOp() const override { return "<"; }
    int getPrecedence() const override { return DBPrint::Prec_Lss; }
    bool operator==(IR::Lss const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Lss"; }
    static cstring static_type_name() { return "Lss"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Lss(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Relation const & a) const override { return a == *this; }
    bool operator==(IR::Operation_Binary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Lss(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Lss(const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Lss(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    Lss(const IR::Expression* left, const IR::Expression* right);
    IRNODE_SUBCLASS(Lss)
};
}  // namespace IR
namespace IR {
class Leq : public Operation_Relation {
 public:
    cstring getStringOp() const override { return "<="; }
    int getPrecedence() const override { return DBPrint::Prec_Leq; }
    bool operator==(IR::Leq const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Leq"; }
    static cstring static_type_name() { return "Leq"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Leq(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Relation const & a) const override { return a == *this; }
    bool operator==(IR::Operation_Binary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Leq(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Leq(const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Leq(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    Leq(const IR::Expression* left, const IR::Expression* right);
    IRNODE_SUBCLASS(Leq)
};
}  // namespace IR
namespace IR {
class Grt : public Operation_Relation {
 public:
    cstring getStringOp() const override { return ">"; }
    int getPrecedence() const override { return DBPrint::Prec_Grt; }
    bool operator==(IR::Grt const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Grt"; }
    static cstring static_type_name() { return "Grt"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Grt(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Relation const & a) const override { return a == *this; }
    bool operator==(IR::Operation_Binary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Grt(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Grt(const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Grt(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    Grt(const IR::Expression* left, const IR::Expression* right);
    IRNODE_SUBCLASS(Grt)
};
}  // namespace IR
namespace IR {
class Geq : public Operation_Relation {
 public:
    cstring getStringOp() const override { return ">="; }
    int getPrecedence() const override { return DBPrint::Prec_Geq; }
    bool operator==(IR::Geq const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Geq"; }
    static cstring static_type_name() { return "Geq"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Geq(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Relation const & a) const override { return a == *this; }
    bool operator==(IR::Operation_Binary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Geq(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Geq(const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Geq(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    Geq(const IR::Expression* left, const IR::Expression* right);
    IRNODE_SUBCLASS(Geq)
};
}  // namespace IR
namespace IR {
class BAnd : public Operation_Binary {
 public:
    cstring getStringOp() const override { return "&"; }
    int getPrecedence() const override { return DBPrint::Prec_BAnd; }
    bool operator==(IR::BAnd const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "BAnd"; }
    static cstring static_type_name() { return "BAnd"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    BAnd(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    BAnd(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    BAnd(const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    BAnd(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    BAnd(const IR::Expression* left, const IR::Expression* right);
    IRNODE_SUBCLASS(BAnd)
};
}  // namespace IR
namespace IR {
class BOr : public Operation_Binary {
 public:
    cstring getStringOp() const override { return "|"; }
    int getPrecedence() const override { return DBPrint::Prec_BOr; }
    bool operator==(IR::BOr const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "BOr"; }
    static cstring static_type_name() { return "BOr"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    BOr(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    BOr(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    BOr(const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    BOr(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    BOr(const IR::Expression* left, const IR::Expression* right);
    IRNODE_SUBCLASS(BOr)
};
}  // namespace IR
namespace IR {
class BXor : public Operation_Binary {
 public:
    cstring getStringOp() const override { return "^"; }
    int getPrecedence() const override { return DBPrint::Prec_BXor; }
    bool operator==(IR::BXor const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "BXor"; }
    static cstring static_type_name() { return "BXor"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    BXor(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    BXor(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    BXor(const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    BXor(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    BXor(const IR::Expression* left, const IR::Expression* right);
    IRNODE_SUBCLASS(BXor)
};
}  // namespace IR
namespace IR {
class LAnd : public Operation_Binary {
 public:
    cstring getStringOp() const override { return "&&"; }
    int getPrecedence() const override { return DBPrint::Prec_LAnd; }
    bool operator==(IR::LAnd const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "LAnd"; }
    static cstring static_type_name() { return "LAnd"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    LAnd(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    LAnd(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    LAnd(const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    LAnd(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    LAnd(const IR::Expression* left, const IR::Expression* right);
    IRNODE_SUBCLASS(LAnd)
};
}  // namespace IR
namespace IR {
class LOr : public Operation_Binary {
 public:
    cstring getStringOp() const override { return "||"; }
    int getPrecedence() const override { return DBPrint::Prec_LOr; }
    bool operator==(IR::LOr const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "LOr"; }
    static cstring static_type_name() { return "LOr"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    LOr(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    LOr(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    LOr(const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    LOr(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    LOr(const IR::Expression* left, const IR::Expression* right);
    IRNODE_SUBCLASS(LOr)
};
}  // namespace IR
namespace IR {
/// Represents the ... default initializer expression
class Dots : public Expression {
 public:
#line 145 "/home/fengyong/Desktop/p4c/ir/expression.def"
    void dbprint(std::ostream & out) const override;
#line 3439 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 146 "/home/fengyong/Desktop/p4c/ir/expression.def"
    cstring toString() const override;
#line 3442 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Dots const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Dots"; }
    static cstring static_type_name() { return "Dots"; }
    void toJSON(JSONGenerator & json) const override;
    Dots(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Dots(Util::SourceInfo srcInfo, const IR::Type* type);
    Dots(const IR::Type* type);
    Dots(Util::SourceInfo srcInfo);
    Dots();
    IRNODE_SUBCLASS(Dots)
};
}  // namespace IR
namespace IR {
/// Represents the ... default initializer expression
/// when used in a StructExpression.
class NamedDots : public NamedExpression {
 public:
#line 152 "/home/fengyong/Desktop/p4c/ir/expression.def"
    NamedDots();
#line 3466 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 153 "/home/fengyong/Desktop/p4c/ir/expression.def"
    NamedDots(Util::SourceInfo srcInfo, const IR::Dots* dots);
#line 3469 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 154 "/home/fengyong/Desktop/p4c/ir/expression.def"
    NamedDots(Util::SourceInfo srcInfo);
#line 3472 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 155 "/home/fengyong/Desktop/p4c/ir/expression.def"
    void dbprint(std::ostream & out) const override;
#line 3475 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 156 "/home/fengyong/Desktop/p4c/ir/expression.def"
    cstring toString() const override;
#line 3478 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::NamedDots const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "NamedDots"; }
    static cstring static_type_name() { return "NamedDots"; }
    void toJSON(JSONGenerator & json) const override;
    NamedDots(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::NamedExpression const & a) const override { return a == *this; }
    bool operator==(IR::Declaration const & a) const override { return a == *this; }
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    NamedDots(Util::SourceInfo srcInfo, IR::ID name, const IR::Expression* expression);
    NamedDots(IR::ID name, const IR::Expression* expression);
    IRNODE_SUBCLASS(NamedDots)
};
}  // namespace IR
namespace IR {
class Literal : public Expression, public virtual CompileTimeValue {
 public:
    bool operator==(IR::Literal const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Literal"; }
    static cstring static_type_name() { return "Literal"; }
    void toJSON(JSONGenerator & json) const override;
    Literal(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
 protected:
    Literal(Util::SourceInfo srcInfo, const IR::Type* type);
    Literal(const IR::Type* type);
    Literal(Util::SourceInfo srcInfo);
    Literal();
    IRNODE_ABSTRACT_SUBCLASS(Literal)
};
}  // namespace IR
namespace IR {
/// This is an integer literal on arbitrary-precision.
class Constant : public Literal {
 public:
    big_int value;
    unsigned base;
/// base used when reading/writing
/// if noWarning is true, no warning is emitted
#line 167 "/home/fengyong/Desktop/p4c/ir/expression.def"
    void handleOverflow(bool noWarning);
#line 3524 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"



#line 171 "/home/fengyong/Desktop/p4c/ir/expression.def"
    Constant(int v, unsigned base = 10);
#line 3530 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 173 "/home/fengyong/Desktop/p4c/ir/expression.def"
    Constant(unsigned v, unsigned base = 10);
#line 3533 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 176 "/home/fengyong/Desktop/p4c/ir/expression.def"
#if __WORDSIZE == 64
    Constant(intmax_t v, unsigned base = 10) :
        Literal(new Type_InfInt()), value(v), base(base) {}
#else
    Constant(long v, unsigned base = 10) :
        Literal(new Type_InfInt()), value(v), base(base) {}
    Constant(unsigned long v, unsigned base = 10) :
        Literal(new Type_InfInt()), value(v), base(base) {}
    Constant(intmax_t v, unsigned base = 10) :
        Literal(new Type_InfInt()), value(v), base(base) {}
#endif
#line 3546 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 188 "/home/fengyong/Desktop/p4c/ir/expression.def"
    Constant(uint64_t v, unsigned base = 10);
#line 3549 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 190 "/home/fengyong/Desktop/p4c/ir/expression.def"
    Constant(big_int v, unsigned base = 10);
#line 3552 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 192 "/home/fengyong/Desktop/p4c/ir/expression.def"
    Constant(Util::SourceInfo si, big_int v, unsigned base = 10);
#line 3555 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 194 "/home/fengyong/Desktop/p4c/ir/expression.def"
    Constant(IR::Type const * t, big_int v, unsigned base = 10, bool noWarning = false);
#line 3558 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 196 "/home/fengyong/Desktop/p4c/ir/expression.def"
    Constant(Util::SourceInfo si, IR::Type const * t, big_int v, unsigned base = 10, bool noWarning = false);
#line 3561 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 200 "/home/fengyong/Desktop/p4c/ir/expression.def"
    static Constant GetMask(unsigned width);
#line 3564 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 202 "/home/fengyong/Desktop/p4c/ir/expression.def"
    bool fitsInt() const;
#line 3567 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 203 "/home/fengyong/Desktop/p4c/ir/expression.def"
    bool fitsLong() const;
#line 3570 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 204 "/home/fengyong/Desktop/p4c/ir/expression.def"
    bool fitsUint() const;
#line 3573 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 205 "/home/fengyong/Desktop/p4c/ir/expression.def"
    bool fitsUint64() const;
#line 3576 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 206 "/home/fengyong/Desktop/p4c/ir/expression.def"
    bool fitsInt64() const;
#line 3579 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 207 "/home/fengyong/Desktop/p4c/ir/expression.def"
    long asLong() const;
#line 3582 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 211 "/home/fengyong/Desktop/p4c/ir/expression.def"
    int asInt() const;
#line 3585 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 215 "/home/fengyong/Desktop/p4c/ir/expression.def"
    unsigned asUnsigned() const;
#line 3588 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 220 "/home/fengyong/Desktop/p4c/ir/expression.def"
    uint64_t asUint64() const;
#line 3591 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 225 "/home/fengyong/Desktop/p4c/ir/expression.def"
    int64_t asInt64() const;
#line 3594 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"



#line 234 "/home/fengyong/Desktop/p4c/ir/expression.def"
    Constant operator<<(const unsigned &shift) const;
    Constant operator>>(const unsigned &shift) const;
    Constant operator&(const Constant &c) const;
    Constant operator|(const Constant &c) const;
    Constant operator^(const Constant &c) const;
    Constant operator-(const Constant &c) const;
    Constant operator-() const;
#line 3606 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 242 "/home/fengyong/Desktop/p4c/ir/expression.def"
    cstring toString() const override;
#line 3609 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 255 "/home/fengyong/Desktop/p4c/ir/expression.def"
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
#line 3613 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Constant const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Constant"; }
    static cstring static_type_name() { return "Constant"; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Constant(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Literal const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_SUBCLASS(Constant)
};
}  // namespace IR
namespace IR {
class BoolLiteral : public Literal {
 public:
    bool value;
#line 260 "/home/fengyong/Desktop/p4c/ir/expression.def"
    cstring toString() const override;
#line 3635 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::BoolLiteral const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "BoolLiteral"; }
    static cstring static_type_name() { return "BoolLiteral"; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    BoolLiteral(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Literal const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    BoolLiteral(Util::SourceInfo srcInfo, const IR::Type* type, bool value);
    BoolLiteral(const IR::Type* type, bool value);
    BoolLiteral(Util::SourceInfo srcInfo, bool value);
    BoolLiteral(bool value);
    IRNODE_SUBCLASS(BoolLiteral)
};
}  // namespace IR
namespace IR {
class StringLiteral : public Literal {
 public:
    cstring value;
#line 265 "/home/fengyong/Desktop/p4c/ir/expression.def"
    void validate() const override;
#line 3661 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 266 "/home/fengyong/Desktop/p4c/ir/expression.def"
    cstring toString() const override;
#line 3664 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 267 "/home/fengyong/Desktop/p4c/ir/expression.def"
    StringLiteral(IR::ID v);
#line 3667 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 269 "/home/fengyong/Desktop/p4c/ir/expression.def"
    operator IR::ID() const { return IR::ID(srcInfo, value); }
#line 3670 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::StringLiteral const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "StringLiteral"; }
    static cstring static_type_name() { return "StringLiteral"; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    StringLiteral(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Literal const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    StringLiteral(Util::SourceInfo srcInfo, const IR::Type* type, cstring value);
    StringLiteral(const IR::Type* type, cstring value);
    StringLiteral(Util::SourceInfo srcInfo, cstring value);
    StringLiteral(cstring value);
    IRNODE_SUBCLASS(StringLiteral)
};
}  // namespace IR
namespace IR {
class PathExpression : public Expression {
 public:
    const IR::Path* path = nullptr;
#line 276 "/home/fengyong/Desktop/p4c/ir/expression.def"
    PathExpression(IR::ID id);
#line 3696 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 277 "/home/fengyong/Desktop/p4c/ir/expression.def"
    cstring toString() const override;
#line 3699 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::PathExpression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "PathExpression"; }
    static cstring static_type_name() { return "PathExpression"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    PathExpression(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    PathExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Path* path);
    PathExpression(const IR::Type* type, const IR::Path* path);
    PathExpression(Util::SourceInfo srcInfo, const IR::Path* path);
    PathExpression(const IR::Path* path);
    IRNODE_SUBCLASS(PathExpression)
};
}  // namespace IR
namespace IR {

class TypeNameExpression : public Expression {
 public:
    const IR::Type* typeName = nullptr;
#line 286 "/home/fengyong/Desktop/p4c/ir/expression.def"
    TypeNameExpression(IR::ID id);
#line 3727 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 288 "/home/fengyong/Desktop/p4c/ir/expression.def"
    void dbprint(std::ostream & out) const override;
#line 3730 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 289 "/home/fengyong/Desktop/p4c/ir/expression.def"
    cstring toString() const override;
#line 3733 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 290 "/home/fengyong/Desktop/p4c/ir/expression.def"
    void validate() const override;
#line 3736 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::TypeNameExpression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "TypeNameExpression"; }
    static cstring static_type_name() { return "TypeNameExpression"; }
    void toJSON(JSONGenerator & json) const override;
    TypeNameExpression(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    TypeNameExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Type* typeName);
    TypeNameExpression(const IR::Type* type, const IR::Type* typeName);
    TypeNameExpression(Util::SourceInfo srcInfo, const IR::Type* typeName);
    TypeNameExpression(const IR::Type* typeName);
    IRNODE_SUBCLASS(TypeNameExpression)
};
}  // namespace IR
namespace IR {
class Slice : public Operation_Ternary {
 public:
    int getPrecedence() const override { return DBPrint::Prec_Postfix; }
    cstring getStringOp() const override { return "[:]"; }
#line 297 "/home/fengyong/Desktop/p4c/ir/expression.def"
    cstring toString() const override;
#line 3762 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"

#line 299 "/home/fengyong/Desktop/p4c/ir/expression.def"
    unsigned getH() const;
#line 3766 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 300 "/home/fengyong/Desktop/p4c/ir/expression.def"
    unsigned getL() const;
#line 3769 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 301 "/home/fengyong/Desktop/p4c/ir/expression.def"
    Slice(const IR::Expression* a, int hi, int lo);
#line 3772 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 303 "/home/fengyong/Desktop/p4c/ir/expression.def"
    Slice(Util::SourceInfo si, const IR::Expression* a, int hi, int lo);
#line 3775 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"

#line 309 "/home/fengyong/Desktop/p4c/ir/expression.def"
    static const IR::Expression *make(const IR::Expression* a, unsigned hi, unsigned lo);
#line 3779 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Slice const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Slice"; }
    static cstring static_type_name() { return "Slice"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Slice(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Ternary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Slice(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2);
    Slice(const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2);
    Slice(Util::SourceInfo srcInfo, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2);
    Slice(const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2);
    IRNODE_SUBCLASS(Slice)
};
}  // namespace IR
namespace IR {
class Member : public Operation_Unary {
 public:
    int getPrecedence() const override { return DBPrint::Prec_Postfix; }
    IR::ID member;
#line 315 "/home/fengyong/Desktop/p4c/ir/expression.def"
    virtual int offset_bits() const;
#line 3806 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 316 "/home/fengyong/Desktop/p4c/ir/expression.def"
    int lsb() const;
#line 3809 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 317 "/home/fengyong/Desktop/p4c/ir/expression.def"
    int msb() const;
#line 3812 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    cstring getStringOp() const override { return "."; }
#line 319 "/home/fengyong/Desktop/p4c/ir/expression.def"
    cstring toString() const override;
#line 3816 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Member const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Member"; }
    static cstring static_type_name() { return "Member"; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Member(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Unary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Member(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr, IR::ID member);
    Member(const IR::Type* type, const IR::Expression* expr, IR::ID member);
    Member(Util::SourceInfo srcInfo, const IR::Expression* expr, IR::ID member);
    Member(const IR::Expression* expr, IR::ID member);
    IRNODE_SUBCLASS(Member)
};
}  // namespace IR
namespace IR {
class Concat : public Operation_Binary {
 public:
    cstring getStringOp() const override { return "++"; }
    int getPrecedence() const override { return DBPrint::Prec_Add; }
    bool operator==(IR::Concat const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Concat"; }
    static cstring static_type_name() { return "Concat"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Concat(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Concat(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Concat(const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Concat(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    Concat(const IR::Expression* left, const IR::Expression* right);
    IRNODE_SUBCLASS(Concat)
};
}  // namespace IR
namespace IR {
class ArrayIndex : public Operation_Binary {
 public:
    cstring getStringOp() const override { return "[]"; }
    int getPrecedence() const override { return DBPrint::Prec_Postfix; }
#line 339 "/home/fengyong/Desktop/p4c/ir/expression.def"
    cstring toString() const override;
#line 3868 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ArrayIndex const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "ArrayIndex"; }
    static cstring static_type_name() { return "ArrayIndex"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ArrayIndex(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    ArrayIndex(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    ArrayIndex(const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    ArrayIndex(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    ArrayIndex(const IR::Expression* left, const IR::Expression* right);
    IRNODE_SUBCLASS(ArrayIndex)
};
}  // namespace IR
namespace IR {
class Range : public Operation_Binary {
 public:
    cstring getStringOp() const override { return ".."; }
    int getPrecedence() const override { return DBPrint::Prec_Low; }
    bool operator==(IR::Range const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Range"; }
    static cstring static_type_name() { return "Range"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Range(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Range(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Range(const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Range(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    Range(const IR::Expression* left, const IR::Expression* right);
    IRNODE_SUBCLASS(Range)
};
}  // namespace IR
namespace IR {
class Mask : public Operation_Binary {
 public:
    cstring getStringOp() const override { return "&&&"; }
    int getPrecedence() const override { return DBPrint::Prec_Low; }
    bool operator==(IR::Mask const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Mask"; }
    static cstring static_type_name() { return "Mask"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Mask(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Binary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Mask(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Mask(const IR::Type* type, const IR::Expression* left, const IR::Expression* right);
    Mask(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    Mask(const IR::Expression* left, const IR::Expression* right);
    IRNODE_SUBCLASS(Mask)
};
}  // namespace IR
namespace IR {
class Mux : public Operation_Ternary {
 public:
    cstring getStringOp() const override { return "?:"; }
    int getPrecedence() const override { return DBPrint::Prec_Low; }
#line 359 "/home/fengyong/Desktop/p4c/ir/expression.def"
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
#line 3944 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Mux const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Mux"; }
    static cstring static_type_name() { return "Mux"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Mux(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Ternary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Mux(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2);
    Mux(const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2);
    Mux(Util::SourceInfo srcInfo, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2);
    Mux(const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2);
    IRNODE_SUBCLASS(Mux)
};
}  // namespace IR
namespace IR {
class DefaultExpression : public Expression {
 public:
    bool operator==(IR::DefaultExpression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DefaultExpression"; }
    static cstring static_type_name() { return "DefaultExpression"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DefaultExpression(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DefaultExpression(Util::SourceInfo srcInfo, const IR::Type* type);
    DefaultExpression(const IR::Type* type);
    DefaultExpression(Util::SourceInfo srcInfo);
    DefaultExpression();
    IRNODE_SUBCLASS(DefaultExpression)
};
}  // namespace IR
namespace IR {

class This : public Expression {
 public:
    long id = nextId++;
#line 371 "/home/fengyong/Desktop/p4c/ir/expression.def"
    cstring toString() const override;
#line 3991 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
 private:
    static long nextId;
 public:
    bool operator==(IR::This const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "This"; }
    static cstring static_type_name() { return "This"; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    This(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    This(Util::SourceInfo srcInfo, const IR::Type* type);
    This(const IR::Type* type);
    This(Util::SourceInfo srcInfo);
    This();
    IRNODE_SUBCLASS(This)
};
}  // namespace IR
namespace IR {
class Cast : public Operation_Unary {
 public:
    const IR::Type* destType = type;
/// These will generally always be the same, except when a cast to a type argument of
/// a generic occurs.  Then at some point, the 'destType' will be specialized to a concrete
/// type, and 'type' will only be updated later when type inferencing occurs
    int getPrecedence() const override { return DBPrint::Prec_Prefix; }
    cstring getStringOp() const override { return "(cast)"; }
#line 383 "/home/fengyong/Desktop/p4c/ir/expression.def"
    cstring toString() const override;
#line 4024 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 384 "/home/fengyong/Desktop/p4c/ir/expression.def"
    void validate() const override;
#line 4027 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Cast const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "Cast"; }
    static cstring static_type_name() { return "Cast"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Cast(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Unary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Cast(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr);
    Cast(const IR::Type* type, const IR::Expression* expr);
    Cast(Util::SourceInfo srcInfo, const IR::Expression* expr);
    Cast(const IR::Expression* expr);
    IRNODE_SUBCLASS(Cast)
};
}  // namespace IR
namespace IR {
class SelectCase : public Node {
 public:
    const IR::Expression* keyset = nullptr;
    const IR::PathExpression* state = nullptr;
#line 390 "/home/fengyong/Desktop/p4c/ir/expression.def"
    void dbprint(std::ostream & out) const override;
#line 4056 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::SelectCase const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "SelectCase"; }
    static cstring static_type_name() { return "SelectCase"; }
    void toJSON(JSONGenerator & json) const override;
    SelectCase(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    SelectCase(Util::SourceInfo srcInfo, const IR::Expression* keyset, const IR::PathExpression* state);
    SelectCase(const IR::Expression* keyset, const IR::PathExpression* state);
    IRNODE_SUBCLASS(SelectCase)
};
}  // namespace IR
namespace IR {
class SelectExpression : public Expression {
 public:
    const IR::ListExpression* select = nullptr;
    IR::Vector<IR::SelectCase> selectCases;
#line 396 "/home/fengyong/Desktop/p4c/ir/expression.def"
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
#line 4081 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::SelectExpression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void validate() const override;
    cstring node_type_name() const override { return "SelectExpression"; }
    static cstring static_type_name() { return "SelectExpression"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    SelectExpression(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    SelectExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::ListExpression* select, IR::Vector<IR::SelectCase> selectCases);
    SelectExpression(const IR::Type* type, const IR::ListExpression* select, IR::Vector<IR::SelectCase> selectCases);
    SelectExpression(Util::SourceInfo srcInfo, const IR::ListExpression* select, IR::Vector<IR::SelectCase> selectCases);
    SelectExpression(const IR::ListExpression* select, IR::Vector<IR::SelectCase> selectCases);
    IRNODE_SUBCLASS(SelectExpression)
};
}  // namespace IR
namespace IR {
class MethodCallExpression : public Expression {
 public:
    const IR::Expression* method = nullptr;
    const IR::Vector<IR::Type>* typeArguments = new Vector<Type>;
    const IR::Vector<IR::Argument>* arguments = new Vector<Argument>;
#line 405 "/home/fengyong/Desktop/p4c/ir/expression.def"
    cstring toString() const override;
#line 4108 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 406 "/home/fengyong/Desktop/p4c/ir/expression.def"
    void validate() const override;
#line 4111 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 407 "/home/fengyong/Desktop/p4c/ir/expression.def"
    MethodCallExpression(Util::SourceInfo si, IR::ID m, std::initializer_list<const IR::Argument *> const & a);
#line 4114 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 409 "/home/fengyong/Desktop/p4c/ir/expression.def"
    MethodCallExpression(Util::SourceInfo si, const IR::Expression* m, std::initializer_list<const IR::Argument *> const & a);
#line 4117 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 412 "/home/fengyong/Desktop/p4c/ir/expression.def"
    MethodCallExpression(const IR::Expression* m, std::initializer_list<IR::Expression const *> const & a);
#line 4120 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::MethodCallExpression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "MethodCallExpression"; }
    static cstring static_type_name() { return "MethodCallExpression"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    MethodCallExpression(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    MethodCallExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments);
    MethodCallExpression(const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments);
    MethodCallExpression(Util::SourceInfo srcInfo, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments);
    MethodCallExpression(const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments);
    MethodCallExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Argument>* arguments);
    MethodCallExpression(const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Argument>* arguments);
    MethodCallExpression(Util::SourceInfo srcInfo, const IR::Expression* method, const IR::Vector<IR::Argument>* arguments);
    MethodCallExpression(const IR::Expression* method, const IR::Vector<IR::Argument>* arguments);
    MethodCallExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments);
    MethodCallExpression(const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments);
    MethodCallExpression(Util::SourceInfo srcInfo, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments);
    MethodCallExpression(const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments);
    MethodCallExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method);
    MethodCallExpression(const IR::Type* type, const IR::Expression* method);
    MethodCallExpression(Util::SourceInfo srcInfo, const IR::Expression* method);
    MethodCallExpression(const IR::Expression* method);
    IRNODE_SUBCLASS(MethodCallExpression)
};
}  // namespace IR
namespace IR {
class ConstructorCallExpression : public Expression {
 public:
    const IR::Type* constructedType = type;

    const IR::Vector<IR::Argument>* arguments = nullptr;
#line 422 "/home/fengyong/Desktop/p4c/ir/expression.def"
    cstring toString() const override;
#line 4160 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 423 "/home/fengyong/Desktop/p4c/ir/expression.def"
    void validate() const override;
#line 4163 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ConstructorCallExpression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "ConstructorCallExpression"; }
    static cstring static_type_name() { return "ConstructorCallExpression"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ConstructorCallExpression(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    ConstructorCallExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Vector<IR::Argument>* arguments);
    ConstructorCallExpression(const IR::Type* type, const IR::Vector<IR::Argument>* arguments);
    ConstructorCallExpression(Util::SourceInfo srcInfo, const IR::Vector<IR::Argument>* arguments);
    ConstructorCallExpression(const IR::Vector<IR::Argument>* arguments);
    IRNODE_SUBCLASS(ConstructorCallExpression)
};
}  // namespace IR
namespace IR {
class BaseListExpression : public Expression {
 public:
    IR::Vector<IR::Expression> components;
#line 431 "/home/fengyong/Desktop/p4c/ir/expression.def"
    void validate() const override;
#line 4189 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 432 "/home/fengyong/Desktop/p4c/ir/expression.def"
    size_t size() const;
#line 4192 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 433 "/home/fengyong/Desktop/p4c/ir/expression.def"
    void push_back(const IR::Expression* e);
#line 4195 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 434 "/home/fengyong/Desktop/p4c/ir/expression.def"
    bool containsDots() const;
#line 4198 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::BaseListExpression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "BaseListExpression"; }
    static cstring static_type_name() { return "BaseListExpression"; }
    void toJSON(JSONGenerator & json) const override;
    BaseListExpression(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    BaseListExpression(Util::SourceInfo srcInfo, const IR::Type* type, IR::Vector<IR::Expression> components);
    BaseListExpression(const IR::Type* type, IR::Vector<IR::Expression> components);
    BaseListExpression(Util::SourceInfo srcInfo, IR::Vector<IR::Expression> components);
    BaseListExpression(IR::Vector<IR::Expression> components);
    IRNODE_SUBCLASS(BaseListExpression)
};
}  // namespace IR
namespace IR {
/// Represents a list of expressions separated by commas
class ListExpression : public BaseListExpression {
 public:
    bool operator==(IR::ListExpression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "ListExpression"; }
    static cstring static_type_name() { return "ListExpression"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ListExpression(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::BaseListExpression const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    ListExpression(Util::SourceInfo srcInfo, const IR::Type* type, IR::Vector<IR::Expression> components);
    ListExpression(const IR::Type* type, IR::Vector<IR::Expression> components);
    ListExpression(Util::SourceInfo srcInfo, IR::Vector<IR::Expression> components);
    ListExpression(IR::Vector<IR::Expression> components);
    IRNODE_SUBCLASS(ListExpression)
};
}  // namespace IR
namespace IR {
/// Represents P4 list expression, not to be confused with
/// ListExpression from above.
class P4ListExpression : public BaseListExpression {
 public:
    const IR::Type* elementType = nullptr;
    bool operator==(IR::P4ListExpression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "P4ListExpression"; }
    static cstring static_type_name() { return "P4ListExpression"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    P4ListExpression(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::BaseListExpression const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    P4ListExpression(Util::SourceInfo srcInfo, const IR::Type* type, IR::Vector<IR::Expression> components, const IR::Type* elementType);
    P4ListExpression(const IR::Type* type, IR::Vector<IR::Expression> components, const IR::Type* elementType);
    P4ListExpression(Util::SourceInfo srcInfo, IR::Vector<IR::Expression> components, const IR::Type* elementType);
    P4ListExpression(IR::Vector<IR::Expression> components, const IR::Type* elementType);
    IRNODE_SUBCLASS(P4ListExpression)
};
}  // namespace IR
namespace IR {
/// An expression that evaluates to a struct.
class StructExpression : public Expression {
 public:
/// The struct or header type that is being intialized.
/// May only be known after type checking; so it can be nullptr.
    const IR::Type* structType = nullptr;
    IR::IndexedVector<IR::NamedExpression> components;
#line 470 "/home/fengyong/Desktop/p4c/ir/expression.def"
    void validate() const override;
#line 4276 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 476 "/home/fengyong/Desktop/p4c/ir/expression.def"
    size_t size() const;
#line 4279 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 477 "/home/fengyong/Desktop/p4c/ir/expression.def"
    const IR::NamedExpression *getField(cstring name) const;
#line 4282 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 479 "/home/fengyong/Desktop/p4c/ir/expression.def"
    bool containsDots() const;
#line 4285 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::StructExpression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "StructExpression"; }
    static cstring static_type_name() { return "StructExpression"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    StructExpression(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    StructExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Type* structType, IR::IndexedVector<IR::NamedExpression> components);
    StructExpression(const IR::Type* type, const IR::Type* structType, IR::IndexedVector<IR::NamedExpression> components);
    StructExpression(Util::SourceInfo srcInfo, const IR::Type* structType, IR::IndexedVector<IR::NamedExpression> components);
    StructExpression(const IR::Type* structType, IR::IndexedVector<IR::NamedExpression> components);
    IRNODE_SUBCLASS(StructExpression)
};
}  // namespace IR
namespace IR {
/// Can be an invalid header or header_union
class Invalid : public Expression {
 public:
    bool operator==(IR::Invalid const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Invalid"; }
    static cstring static_type_name() { return "Invalid"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Invalid(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Invalid(Util::SourceInfo srcInfo, const IR::Type* type);
    Invalid(const IR::Type* type);
    Invalid(Util::SourceInfo srcInfo);
    Invalid();
    IRNODE_SUBCLASS(Invalid)
};
}  // namespace IR
namespace IR {
/// An expression that evaluates to an invalid header with the specified type.
class InvalidHeader : public Expression {
 public:
    const IR::Type* headerType = nullptr;
    bool operator==(IR::InvalidHeader const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "InvalidHeader"; }
    static cstring static_type_name() { return "InvalidHeader"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    InvalidHeader(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    InvalidHeader(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Type* headerType);
    InvalidHeader(const IR::Type* type, const IR::Type* headerType);
    InvalidHeader(Util::SourceInfo srcInfo, const IR::Type* headerType);
    InvalidHeader(const IR::Type* headerType);
    IRNODE_SUBCLASS(InvalidHeader)
};
}  // namespace IR
namespace IR {
/// An expression that evaluates to an invalid header union with the specified type.
class InvalidHeaderUnion : public Expression {
 public:
    const IR::Type* headerUnionType = nullptr;
    bool operator==(IR::InvalidHeaderUnion const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "InvalidHeaderUnion"; }
    static cstring static_type_name() { return "InvalidHeaderUnion"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    InvalidHeaderUnion(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    InvalidHeaderUnion(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Type* headerUnionType);
    InvalidHeaderUnion(const IR::Type* type, const IR::Type* headerUnionType);
    InvalidHeaderUnion(Util::SourceInfo srcInfo, const IR::Type* headerUnionType);
    InvalidHeaderUnion(const IR::Type* headerUnionType);
    IRNODE_SUBCLASS(InvalidHeaderUnion)
};
}  // namespace IR
namespace IR {
/// An expression that evaluates to a header stack
class HeaderStackExpression : public BaseListExpression {
 public:
/// May only be known after type checking; so it can be nullptr.
    const IR::Type* headerStackType = nullptr;
#line 505 "/home/fengyong/Desktop/p4c/ir/expression.def"
    void validate() const override;
#line 4384 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::HeaderStackExpression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "HeaderStackExpression"; }
    static cstring static_type_name() { return "HeaderStackExpression"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    HeaderStackExpression(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::BaseListExpression const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    HeaderStackExpression(Util::SourceInfo srcInfo, const IR::Type* type, IR::Vector<IR::Expression> components, const IR::Type* headerStackType);
    HeaderStackExpression(const IR::Type* type, IR::Vector<IR::Expression> components, const IR::Type* headerStackType);
    HeaderStackExpression(Util::SourceInfo srcInfo, IR::Vector<IR::Expression> components, const IR::Type* headerStackType);
    HeaderStackExpression(IR::Vector<IR::Expression> components, const IR::Type* headerStackType);
    IRNODE_SUBCLASS(HeaderStackExpression)
};
}  // namespace IR
namespace IR {
/// A ListExpression where all the components are compile-time values.
/// This is used by the evaluator pass.
class ListCompileTimeValue : public Node, public virtual CompileTimeValue {
 public:
    IR::Vector<IR::Node> components;
#line 514 "/home/fengyong/Desktop/p4c/ir/expression.def"
    void validate() const override;
#line 4413 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ListCompileTimeValue const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "ListCompileTimeValue"; }
    static cstring static_type_name() { return "ListCompileTimeValue"; }
    void toJSON(JSONGenerator & json) const override;
    ListCompileTimeValue(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    ListCompileTimeValue(Util::SourceInfo srcInfo, IR::Vector<IR::Node> components);
    ListCompileTimeValue(IR::Vector<IR::Node> components);
    IRNODE_SUBCLASS(ListCompileTimeValue)
};
}  // namespace IR
namespace IR {
/// A P4ListExpression where all the components are compile-time values.
/// This is used by the evaluator pass.
class P4ListCompileTimeValue : public Node, public virtual CompileTimeValue {
 public:
    IR::Vector<IR::Node> components;
#line 524 "/home/fengyong/Desktop/p4c/ir/expression.def"
    void validate() const override;
#line 4437 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::P4ListCompileTimeValue const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "P4ListCompileTimeValue"; }
    static cstring static_type_name() { return "P4ListCompileTimeValue"; }
    void toJSON(JSONGenerator & json) const override;
    P4ListCompileTimeValue(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    P4ListCompileTimeValue(Util::SourceInfo srcInfo, IR::Vector<IR::Node> components);
    P4ListCompileTimeValue(IR::Vector<IR::Node> components);
    IRNODE_SUBCLASS(P4ListCompileTimeValue)
};
}  // namespace IR
namespace IR {
/// A StructExpression where all the components are compile-time values.
/// This is used by the evaluator pass.
class StructCompileTimeValue : public Node, public virtual CompileTimeValue {
 public:
    IR::Vector<IR::Node> components;
#line 534 "/home/fengyong/Desktop/p4c/ir/expression.def"
    void validate() const override;
#line 4461 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::StructCompileTimeValue const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "StructCompileTimeValue"; }
    static cstring static_type_name() { return "StructCompileTimeValue"; }
    void toJSON(JSONGenerator & json) const override;
    StructCompileTimeValue(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    StructCompileTimeValue(Util::SourceInfo srcInfo, IR::Vector<IR::Node> components);
    StructCompileTimeValue(IR::Vector<IR::Node> components);
    IRNODE_SUBCLASS(StructCompileTimeValue)
};
}  // namespace IR
namespace IR {
/// Experimental: an extern methond/function call with constant arguments to be
/// evaluated at compile time
class CompileTimeMethodCall : public MethodCallExpression, public virtual CompileTimeValue {
 public:
#line 543 "/home/fengyong/Desktop/p4c/ir/expression.def"
    CompileTimeMethodCall(const IR::MethodCallExpression* e);
#line 4484 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 544 "/home/fengyong/Desktop/p4c/ir/expression.def"
    void validate() const override;
#line 4487 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::CompileTimeMethodCall const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "CompileTimeMethodCall"; }
    static cstring static_type_name() { return "CompileTimeMethodCall"; }
    void toJSON(JSONGenerator & json) const override;
    CompileTimeMethodCall(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::MethodCallExpression const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments);
    CompileTimeMethodCall(const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments);
    CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments);
    CompileTimeMethodCall(const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments);
    CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Argument>* arguments);
    CompileTimeMethodCall(const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Argument>* arguments);
    CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Expression* method, const IR::Vector<IR::Argument>* arguments);
    CompileTimeMethodCall(const IR::Expression* method, const IR::Vector<IR::Argument>* arguments);
    CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments);
    CompileTimeMethodCall(const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments);
    CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments);
    CompileTimeMethodCall(const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments);
    CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method);
    CompileTimeMethodCall(const IR::Type* type, const IR::Expression* method);
    CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Expression* method);
    CompileTimeMethodCall(const IR::Expression* method);
    IRNODE_SUBCLASS(CompileTimeMethodCall)
};
}  // namespace IR
namespace IR {
/** @} */
/* end group irdefs */
/* -*-C++-*- */
/** \addtogroup irdefs
  * @{
  */
/**
  P4 compiler IR definition file.
  To understand this you really have to understand the shape of the generated IR code.

  The IR builder "knows" the following methods for a class T:

  cstring toString() const override;
  void dbprint(std::ostream &out) const override;
  bool operator==(const T &a) const;
  void validate() const;
  const char *node_type_name() const;
  void visit_children(Visitor &v);
  void dump_fields(std::ostream& out) const;

  C comments are ignored.
  C++ line comments can appear in some places and are emitted in the output.

  #emit/#end      -> copy text literally to output header file
  #emit_impl/#end -> copy text literally to output C++ file
  #noXXX          -> do not emit the specified implementation for the XXX method
                     e.g., #noconstructor, #nodbprint, #novisit_children, #nomethod_constructor
  #apply          -> generate apply overload for visitors
  method{ ... }   -> specifies an implementation for a default method
                     method can be 'operator=='

  Some assignments are turned into methods returning constant values:
  stringOp     -> cstring getStringOp() const
  precedence   -> int getPrecedence() const

  When defining fields and methods in an IR class, all fields and arguments of any IR
  class type are automatically converted into const IR::class * fields or arguments, unless
  they are identified as 'inline'.  It is not possible to create a non-const pointer to
  an IR class in any other IR class.

  There are some special keywords that can be applied (as decl modifiers) to fields that
  affect how they are created, checked, and initialized.

  inline      The field (of IR class type) should be defined directly in the object
              rather than being converted to a const T * as described above.
  NullOK      The field is a pointer and may be null (verify will check that it is not otherwise)
  optional    The field may be provided as an argument to the constructor but need not be.
              (overloaded constructors will be created as needed)

  Unless there is a '#noconstructor' tag in the class, a constructor
  will automatically be generated that takes as arguments values to
  initialize all fields of the IR class and its bases that do not have
  explicit initializers. There are some special method constructors which ignore #noconstructor, such as Class(JSONLoader &json). #nomethod_constructor will prevent these files from being generated. Fields marked 'optional' will create multiple constructors both with and without an argument for that field.
 */
class ParserState : public virtual ISimpleNamespace, public Declaration, public virtual IAnnotated {
 public:
    const IR::Annotations* annotations = Annotations::empty;
    IR::IndexedVector<IR::StatOrDecl> components;

    const IR::Expression* selectExpression = nullptr;
#line 63 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Annotations *getAnnotations() const override;
#line 4580 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 64 "/home/fengyong/Desktop/p4c/ir/ir.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 4583 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 66 "/home/fengyong/Desktop/p4c/ir/ir.def"
    IR::IDeclaration const * getDeclByName(cstring name) const override;
#line 4586 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    static const cstring accept;
    static const cstring reject;
    static const cstring start;
    static const cstring verify;
#line 73 "/home/fengyong/Desktop/p4c/ir/ir.def"
    bool isBuiltin() const;
#line 4593 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 74 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void validate() const override;
#line 4596 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ParserState const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "ParserState"; }
    static cstring static_type_name() { return "ParserState"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ParserState(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override { return a == *this; }
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    ParserState(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StatOrDecl> components, const IR::Expression* selectExpression);
    ParserState(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StatOrDecl> components, const IR::Expression* selectExpression);
    ParserState(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StatOrDecl> components, const IR::Expression* selectExpression);
    ParserState(IR::ID name, IR::IndexedVector<IR::StatOrDecl> components, const IR::Expression* selectExpression);
    ParserState(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Expression* selectExpression);
    ParserState(IR::ID name, const IR::Annotations* annotations, const IR::Expression* selectExpression);
    ParserState(Util::SourceInfo srcInfo, IR::ID name, const IR::Expression* selectExpression);
    ParserState(IR::ID name, const IR::Expression* selectExpression);
    IRNODE_SUBCLASS(ParserState)
};
}  // namespace IR
namespace IR {

class P4Parser : public Type_Declaration, public virtual INestedNamespace, public virtual ISimpleNamespace, public virtual IApply, public virtual IContainer, public virtual IAnnotated {
 public:
    const IR::Type_Parser* type = nullptr;
    const IR::ParameterList* constructorParams = new ParameterList;
    IR::IndexedVector<IR::Declaration> parserLocals;
    IR::IndexedVector<IR::ParserState> states;
#line 89 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Annotations *getAnnotations() const override;
#line 4631 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 90 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::TypeParameters *getTypeParameters() const override;
#line 4634 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 91 "/home/fengyong/Desktop/p4c/ir/ir.def"
    std::vector<const IR::INamespace *> getNestedNamespaces() const override;
#line 4637 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 93 "/home/fengyong/Desktop/p4c/ir/ir.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 4640 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 95 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 4643 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 99 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Type_Method *getApplyMethodType() const override;
#line 4646 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 100 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::ParameterList *getApplyParameters() const override;
#line 4649 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 101 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Type_Method *getConstructorMethodType() const override;
#line 4652 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 102 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::ParameterList *getConstructorParameters() const override;
#line 4655 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 103 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void checkDuplicates() const;
#line 4658 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 104 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Type *getType() const override;
#line 4661 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    IRNODE_DECLARE_APPLY_OVERLOAD(P4Parser)
#line 106 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void validate() const override;
#line 4665 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 115 "/home/fengyong/Desktop/p4c/ir/ir.def"
    cstring toString() const override;
#line 4668 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::P4Parser const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "P4Parser"; }
    static cstring static_type_name() { return "P4Parser"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    P4Parser(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Declaration const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::Declaration> parserLocals, IR::IndexedVector<IR::ParserState> states);
    P4Parser(IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::Declaration> parserLocals, IR::IndexedVector<IR::ParserState> states);
    P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, IR::IndexedVector<IR::Declaration> parserLocals, IR::IndexedVector<IR::ParserState> states);
    P4Parser(IR::ID name, const IR::Type_Parser* type, IR::IndexedVector<IR::Declaration> parserLocals, IR::IndexedVector<IR::ParserState> states);
    P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::ParserState> states);
    P4Parser(IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::ParserState> states);
    P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, IR::IndexedVector<IR::ParserState> states);
    P4Parser(IR::ID name, const IR::Type_Parser* type, IR::IndexedVector<IR::ParserState> states);
    P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::Declaration> parserLocals);
    P4Parser(IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::Declaration> parserLocals);
    P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, IR::IndexedVector<IR::Declaration> parserLocals);
    P4Parser(IR::ID name, const IR::Type_Parser* type, IR::IndexedVector<IR::Declaration> parserLocals);
    P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams);
    P4Parser(IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams);
    P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type);
    P4Parser(IR::ID name, const IR::Type_Parser* type);
    IRNODE_SUBCLASS(P4Parser)
};
}  // namespace IR
namespace IR {
class P4Control : public Type_Declaration, public virtual INestedNamespace, public virtual ISimpleNamespace, public virtual IApply, public virtual IContainer, public virtual IAnnotated {
 public:
    const IR::Type_Control* type = nullptr;
    const IR::ParameterList* constructorParams = new ParameterList;
    IR::IndexedVector<IR::Declaration> controlLocals;
    const IR::BlockStatement* body = nullptr;
#line 124 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Annotations *getAnnotations() const override;
#line 4710 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 125 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::TypeParameters *getTypeParameters() const override;
#line 4713 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 126 "/home/fengyong/Desktop/p4c/ir/ir.def"
    std::vector<const IR::INamespace *> getNestedNamespaces() const override;
#line 4716 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 128 "/home/fengyong/Desktop/p4c/ir/ir.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 4719 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 130 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Type_Method *getApplyMethodType() const override;
#line 4722 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 131 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::ParameterList *getApplyParameters() const override;
#line 4725 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 132 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Type_Method *getConstructorMethodType() const override;
#line 4728 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 133 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 4731 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 135 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::ParameterList *getConstructorParameters() const override;
#line 4734 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 136 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Type *getType() const override;
#line 4737 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    IRNODE_DECLARE_APPLY_OVERLOAD(P4Control)
#line 138 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void validate() const override;
#line 4741 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 143 "/home/fengyong/Desktop/p4c/ir/ir.def"
    cstring toString() const override;
#line 4744 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::P4Control const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "P4Control"; }
    static cstring static_type_name() { return "P4Control"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    P4Control(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Declaration const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    P4Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Control* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::Declaration> controlLocals, const IR::BlockStatement* body);
    P4Control(IR::ID name, const IR::Type_Control* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::Declaration> controlLocals, const IR::BlockStatement* body);
    P4Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Control* type, IR::IndexedVector<IR::Declaration> controlLocals, const IR::BlockStatement* body);
    P4Control(IR::ID name, const IR::Type_Control* type, IR::IndexedVector<IR::Declaration> controlLocals, const IR::BlockStatement* body);
    P4Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Control* type, const IR::ParameterList* constructorParams, const IR::BlockStatement* body);
    P4Control(IR::ID name, const IR::Type_Control* type, const IR::ParameterList* constructorParams, const IR::BlockStatement* body);
    P4Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Control* type, const IR::BlockStatement* body);
    P4Control(IR::ID name, const IR::Type_Control* type, const IR::BlockStatement* body);
    IRNODE_SUBCLASS(P4Control)
};
}  // namespace IR
namespace IR {
/// A P4-16 action
class P4Action : public Declaration, public virtual ISimpleNamespace, public virtual IAnnotated, public virtual IFunctional {
 public:
    const IR::Annotations* annotations = Annotations::empty;
    const IR::ParameterList* parameters = nullptr;
    const IR::BlockStatement* body = nullptr;
#line 151 "/home/fengyong/Desktop/p4c/ir/ir.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 4778 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 153 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 4781 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 155 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Annotations *getAnnotations() const override;
#line 4784 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 156 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::ParameterList *getParameters() const override;
#line 4787 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::P4Action const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "P4Action"; }
    static cstring static_type_name() { return "P4Action"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    P4Action(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override { return a == *this; }
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    P4Action(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::ParameterList* parameters, const IR::BlockStatement* body);
    P4Action(IR::ID name, const IR::Annotations* annotations, const IR::ParameterList* parameters, const IR::BlockStatement* body);
    P4Action(Util::SourceInfo srcInfo, IR::ID name, const IR::ParameterList* parameters, const IR::BlockStatement* body);
    P4Action(IR::ID name, const IR::ParameterList* parameters, const IR::BlockStatement* body);
    IRNODE_SUBCLASS(P4Action)
};
}  // namespace IR
namespace IR {
class Type_Error : public virtual ISimpleNamespace, public Type_Declaration {
 public:
    static const cstring error;
    IR::IndexedVector<IR::Declaration_ID> members;
#line 162 "/home/fengyong/Desktop/p4c/ir/ir.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 4816 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 164 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 4819 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 166 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void validate() const override;
#line 4822 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Error const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "Type_Error"; }
    static cstring static_type_name() { return "Type_Error"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Type_Error(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Declaration const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Error(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::Declaration_ID> members);
    Type_Error(IR::ID name, IR::IndexedVector<IR::Declaration_ID> members);
    Type_Error(Util::SourceInfo srcInfo, IR::ID name);
    Type_Error(IR::ID name);
    IRNODE_SUBCLASS(Type_Error)
};
}  // namespace IR
namespace IR {

class Declaration_MatchKind : public Node, public virtual ISimpleNamespace {
 public:
    IR::IndexedVector<IR::Declaration_ID> members;
#line 172 "/home/fengyong/Desktop/p4c/ir/ir.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 4850 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 174 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 4853 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 176 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void validate() const override;
#line 4856 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Declaration_MatchKind const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "Declaration_MatchKind"; }
    static cstring static_type_name() { return "Declaration_MatchKind"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Declaration_MatchKind(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Declaration_MatchKind(Util::SourceInfo srcInfo, IR::IndexedVector<IR::Declaration_ID> members);
    Declaration_MatchKind(IR::IndexedVector<IR::Declaration_ID> members);
    Declaration_MatchKind(Util::SourceInfo srcInfo);
    Declaration_MatchKind();
    IRNODE_SUBCLASS(Declaration_MatchKind)
};
}  // namespace IR
namespace IR {
/// Table property value abstract base class
class PropertyValue : public Node {
 public:
    bool operator==(IR::PropertyValue const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "PropertyValue"; }
    static cstring static_type_name() { return "PropertyValue"; }
    void toJSON(JSONGenerator & json) const override;
    PropertyValue(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
 protected:
    PropertyValue(Util::SourceInfo srcInfo);
    PropertyValue();
    IRNODE_ABSTRACT_SUBCLASS(PropertyValue)
};
}  // namespace IR
namespace IR {
/// A table property whose value is an expression
class ExpressionValue : public PropertyValue {
 public:
    const IR::Expression* expression = nullptr;
#line 185 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void dbprint(std::ostream & out) const override;
#line 4899 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ExpressionValue const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "ExpressionValue"; }
    static cstring static_type_name() { return "ExpressionValue"; }
    void toJSON(JSONGenerator & json) const override;
    ExpressionValue(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::PropertyValue const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    ExpressionValue(Util::SourceInfo srcInfo, const IR::Expression* expression);
    ExpressionValue(const IR::Expression* expression);
    IRNODE_SUBCLASS(ExpressionValue)
};
}  // namespace IR
namespace IR {
class ExpressionListValue : public PropertyValue {
 public:
    IR::Vector<IR::Expression> expressions;
#line 190 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void dbprint(std::ostream & out) const override;
#line 4923 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ExpressionListValue const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "ExpressionListValue"; }
    static cstring static_type_name() { return "ExpressionListValue"; }
    void toJSON(JSONGenerator & json) const override;
    ExpressionListValue(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::PropertyValue const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    ExpressionListValue(Util::SourceInfo srcInfo, IR::Vector<IR::Expression> expressions);
    ExpressionListValue(IR::Vector<IR::Expression> expressions);
    IRNODE_SUBCLASS(ExpressionListValue)
};
}  // namespace IR
namespace IR {

class ActionListElement : public Node, public virtual IAnnotated, public virtual IDeclaration {
 public:
    const IR::Annotations* annotations = Annotations::empty;
    const IR::Expression* expression = nullptr;

#line 197 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void dbprint(std::ostream & out) const override;
#line 4950 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 198 "/home/fengyong/Desktop/p4c/ir/ir.def"
    IR::ID getName() const override;
#line 4953 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 199 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Path *getPath() const;
#line 4956 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 200 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Annotations *getAnnotations() const override;
#line 4959 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 201 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void validate() const override;
#line 4962 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 206 "/home/fengyong/Desktop/p4c/ir/ir.def"
    cstring toString() const override;
#line 4965 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ActionListElement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "ActionListElement"; }
    static cstring static_type_name() { return "ActionListElement"; }
    void toJSON(JSONGenerator & json) const override;
    ActionListElement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    ActionListElement(Util::SourceInfo srcInfo, const IR::Annotations* annotations, const IR::Expression* expression);
    ActionListElement(const IR::Annotations* annotations, const IR::Expression* expression);
    ActionListElement(Util::SourceInfo srcInfo, const IR::Expression* expression);
    ActionListElement(const IR::Expression* expression);
    IRNODE_SUBCLASS(ActionListElement)
};
}  // namespace IR
namespace IR {

class ActionList : public PropertyValue {
 public:
    IR::IndexedVector<IR::ActionListElement> actionList;
#line 212 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void validate() const override;
#line 4990 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 213 "/home/fengyong/Desktop/p4c/ir/ir.def"
    size_t size() const;
#line 4993 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 214 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void push_back(const IR::ActionListElement* e);
#line 4996 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 215 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::ActionListElement *getDeclaration(cstring n) const;
#line 4999 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ActionList const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "ActionList"; }
    static cstring static_type_name() { return "ActionList"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ActionList(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::PropertyValue const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    ActionList(Util::SourceInfo srcInfo, IR::IndexedVector<IR::ActionListElement> actionList);
    ActionList(IR::IndexedVector<IR::ActionListElement> actionList);
    IRNODE_SUBCLASS(ActionList)
};
}  // namespace IR
namespace IR {
class KeyElement : public Node, public virtual IAnnotated {
 public:
    const IR::Annotations* annotations = Annotations::empty;
    const IR::Expression* expression = nullptr;
    const IR::PathExpression* matchType = nullptr;
#line 224 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Annotations *getAnnotations() const override;
#line 5025 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 225 "/home/fengyong/Desktop/p4c/ir/ir.def"
    IR::Node const * transform_visit(Transform & v);
#line 5028 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::KeyElement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "KeyElement"; }
    static cstring static_type_name() { return "KeyElement"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    KeyElement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    KeyElement(Util::SourceInfo srcInfo, const IR::Annotations* annotations, const IR::Expression* expression, const IR::PathExpression* matchType);
    KeyElement(const IR::Annotations* annotations, const IR::Expression* expression, const IR::PathExpression* matchType);
    KeyElement(Util::SourceInfo srcInfo, const IR::Expression* expression, const IR::PathExpression* matchType);
    KeyElement(const IR::Expression* expression, const IR::PathExpression* matchType);
    IRNODE_SUBCLASS(KeyElement)
};
}  // namespace IR
namespace IR {

class Key : public PropertyValue {
 public:
    IR::Vector<IR::KeyElement> keyElements;
#line 248 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void validate() const override;
#line 5055 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 249 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void push_back(const IR::KeyElement* ke);
#line 5058 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Key const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "Key"; }
    static cstring static_type_name() { return "Key"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Key(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::PropertyValue const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Key(Util::SourceInfo srcInfo, IR::Vector<IR::KeyElement> keyElements);
    Key(IR::Vector<IR::KeyElement> keyElements);
    IRNODE_SUBCLASS(Key)
};
}  // namespace IR
namespace IR {
/// Pre-defined entry in a table
class Entry : public Node, public virtual IAnnotated {
 public:
/// annotations are optional (supported annotations: @priority(value))
    const IR::Annotations* annotations = Annotations::empty;
    bool isConst;
/// optional const annotation
    const IR::Expression* priority = nullptr;
/// optional entry priority
    const IR::ListExpression* keys = nullptr;
/// must be a tuple expression
    const IR::Expression* action = nullptr;
/// typically a MethodCallExpression.
/// The action must be defined in action list
    bool singleton;
/// True if the entry is not a list.
#line 263 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Annotations *getAnnotations() const override;
#line 5095 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 264 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::ListExpression *getKeys() const;
#line 5098 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 265 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Expression *getAction() const;
#line 5101 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 266 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void dbprint(std::ostream & out) const override;
#line 5104 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Entry const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Entry"; }
    static cstring static_type_name() { return "Entry"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Entry(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Entry(Util::SourceInfo srcInfo, const IR::Annotations* annotations, bool isConst, const IR::Expression* priority, const IR::ListExpression* keys, const IR::Expression* action, bool singleton);
    Entry(const IR::Annotations* annotations, bool isConst, const IR::Expression* priority, const IR::ListExpression* keys, const IR::Expression* action, bool singleton);
    Entry(Util::SourceInfo srcInfo, bool isConst, const IR::Expression* priority, const IR::ListExpression* keys, const IR::Expression* action, bool singleton);
    Entry(bool isConst, const IR::Expression* priority, const IR::ListExpression* keys, const IR::Expression* action, bool singleton);
    IRNODE_SUBCLASS(Entry)
};
}  // namespace IR
namespace IR {
/// List of predefined entries. Part of table properties
class EntriesList : public PropertyValue {
 public:
    IR::Vector<IR::Entry> entries;
#line 272 "/home/fengyong/Desktop/p4c/ir/ir.def"
    size_t size() const;
#line 5131 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 273 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void dbprint(std::ostream & out) const override;
#line 5134 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::EntriesList const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "EntriesList"; }
    static cstring static_type_name() { return "EntriesList"; }
    void toJSON(JSONGenerator & json) const override;
    EntriesList(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::PropertyValue const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    EntriesList(Util::SourceInfo srcInfo, IR::Vector<IR::Entry> entries);
    EntriesList(IR::Vector<IR::Entry> entries);
    IRNODE_SUBCLASS(EntriesList)
};
}  // namespace IR
namespace IR {
class Property : public Declaration, public virtual IAnnotated {
 public:
    const IR::Annotations* annotations = Annotations::empty;
    const IR::PropertyValue* value = nullptr;
    bool isConstant;
#line 280 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Annotations *getAnnotations() const override;
#line 5160 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 281 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void dbprint(std::ostream & out) const override;
#line 5163 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Property const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Property"; }
    static cstring static_type_name() { return "Property"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Property(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override { return a == *this; }
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Property(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::PropertyValue* value, bool isConstant);
    Property(IR::ID name, const IR::Annotations* annotations, const IR::PropertyValue* value, bool isConstant);
    Property(Util::SourceInfo srcInfo, IR::ID name, const IR::PropertyValue* value, bool isConstant);
    Property(IR::ID name, const IR::PropertyValue* value, bool isConstant);
    IRNODE_SUBCLASS(Property)
};
}  // namespace IR
namespace IR {
class TableProperties : public Node, public virtual ISimpleNamespace {
 public:
    IR::IndexedVector<IR::Property> properties;
#line 286 "/home/fengyong/Desktop/p4c/ir/ir.def"
    cstring toString() const override;
#line 5191 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 287 "/home/fengyong/Desktop/p4c/ir/ir.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 5194 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 289 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Property *getProperty(cstring name) const;
#line 5197 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 291 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 5200 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 293 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void push_back(const IR::Property* prop);
#line 5203 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    static const cstring actionsPropertyName;
    static const cstring keyPropertyName;
    static const cstring defaultActionPropertyName;
    static const cstring entriesPropertyName;
    static const cstring sizePropertyName;
#line 301 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void validate() const override;
#line 5211 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::TableProperties const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "TableProperties"; }
    static cstring static_type_name() { return "TableProperties"; }
    void toJSON(JSONGenerator & json) const override;
    TableProperties(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    TableProperties(Util::SourceInfo srcInfo, IR::IndexedVector<IR::Property> properties);
    TableProperties(IR::IndexedVector<IR::Property> properties);
    TableProperties(Util::SourceInfo srcInfo);
    TableProperties();
    IRNODE_SUBCLASS(TableProperties)
};
}  // namespace IR
namespace IR {
class P4Table : public Declaration, public virtual IAnnotated, public virtual IApply {
 public:
    const IR::Annotations* annotations = Annotations::empty;
    const IR::TableProperties* properties = nullptr;
#line 308 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Annotations *getAnnotations() const override;
#line 5236 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 309 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Type_Method *getApplyMethodType() const override;
#line 5239 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 310 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::ParameterList *getApplyParameters() const override;
#line 5242 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 311 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::ActionList *getActionList() const;
#line 5245 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 319 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Key *getKey() const;
#line 5248 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 327 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Expression *getDefaultAction() const;
#line 5251 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 335 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Constant *getConstantProperty(cstring name) const;
#line 5254 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 342 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::BoolLiteral *getBooleanProperty(cstring name) const;
#line 5257 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 349 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Constant *getSizeProperty() const;
#line 5260 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 352 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::EntriesList *getEntries() const;
#line 5263 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::P4Table const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "P4Table"; }
    static cstring static_type_name() { return "P4Table"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    P4Table(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override { return a == *this; }
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    P4Table(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TableProperties* properties);
    P4Table(IR::ID name, const IR::Annotations* annotations, const IR::TableProperties* properties);
    P4Table(Util::SourceInfo srcInfo, IR::ID name, const IR::TableProperties* properties);
    P4Table(IR::ID name, const IR::TableProperties* properties);
    IRNODE_SUBCLASS(P4Table)
};
}  // namespace IR
namespace IR {
class P4ValueSet : public Declaration, public virtual IAnnotated {
 public:
    const IR::Annotations* annotations = Annotations::empty;
    const IR::Type* elementType = nullptr;
    const IR::Expression* size = nullptr;

#line 368 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Annotations *getAnnotations() const override;
#line 5294 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::P4ValueSet const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "P4ValueSet"; }
    static cstring static_type_name() { return "P4ValueSet"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    P4ValueSet(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override { return a == *this; }
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    P4ValueSet(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* elementType, const IR::Expression* size);
    P4ValueSet(IR::ID name, const IR::Annotations* annotations, const IR::Type* elementType, const IR::Expression* size);
    P4ValueSet(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* elementType, const IR::Expression* size);
    P4ValueSet(IR::ID name, const IR::Type* elementType, const IR::Expression* size);
    IRNODE_SUBCLASS(P4ValueSet)
};
}  // namespace IR
namespace IR {
class Declaration_Variable : public Declaration, public virtual IAnnotated {
 public:
    const IR::Annotations* annotations = Annotations::empty;
    const IR::Type* type = nullptr;
    const IR::Expression* initializer = nullptr;
#line 376 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Annotations *getAnnotations() const override;
#line 5324 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 377 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void dbprint(std::ostream & out) const override;
#line 5327 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Declaration_Variable const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Declaration_Variable"; }
    static cstring static_type_name() { return "Declaration_Variable"; }
    void toJSON(JSONGenerator & json) const override;
    Declaration_Variable(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override { return a == *this; }
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Declaration_Variable(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Expression* initializer);
    Declaration_Variable(IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Expression* initializer);
    Declaration_Variable(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type, const IR::Expression* initializer);
    Declaration_Variable(IR::ID name, const IR::Type* type, const IR::Expression* initializer);
    Declaration_Variable(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type);
    Declaration_Variable(IR::ID name, const IR::Annotations* annotations, const IR::Type* type);
    Declaration_Variable(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type);
    Declaration_Variable(IR::ID name, const IR::Type* type);
    IRNODE_SUBCLASS(Declaration_Variable)
};
}  // namespace IR
namespace IR {
class Declaration_Constant : public Declaration, public virtual IAnnotated {
 public:
    const IR::Annotations* annotations = Annotations::empty;
    const IR::Type* type = nullptr;
    const IR::Expression* initializer = nullptr;
#line 387 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Annotations *getAnnotations() const override;
#line 5360 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 388 "/home/fengyong/Desktop/p4c/ir/ir.def"
    cstring toString() const override;
#line 5363 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 389 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void dbprint(std::ostream & out) const override;
#line 5366 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Declaration_Constant const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Declaration_Constant"; }
    static cstring static_type_name() { return "Declaration_Constant"; }
    void toJSON(JSONGenerator & json) const override;
    Declaration_Constant(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override { return a == *this; }
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Declaration_Constant(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Expression* initializer);
    Declaration_Constant(IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Expression* initializer);
    Declaration_Constant(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type, const IR::Expression* initializer);
    Declaration_Constant(IR::ID name, const IR::Type* type, const IR::Expression* initializer);
    IRNODE_SUBCLASS(Declaration_Constant)
};
}  // namespace IR
namespace IR {
/// Like a variable, but for a statically allocated instance.
/// The syntax is Contructor(args) name = initializer;
/// Initializers are an experimental features, used for externs with
/// abstract methods.
class Declaration_Instance : public Declaration, public virtual IAnnotated, public virtual IInstance {
 public:
    const IR::Annotations* annotations = Annotations::empty;
    const IR::Type* type = nullptr;

    const IR::Vector<IR::Argument>* arguments = nullptr;
    IR::NameMap<IR::Property> properties = {};

    const IR::BlockStatement* initializer = nullptr;

#line 404 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Annotations *getAnnotations() const override;
#line 5404 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 405 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Type *getType() const override;
#line 5407 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 406 "/home/fengyong/Desktop/p4c/ir/ir.def"
    IR::ID Name() const override;
#line 5410 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 407 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void validate() const override;
#line 5413 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Declaration_Instance const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "Declaration_Instance"; }
    static cstring static_type_name() { return "Declaration_Instance"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Declaration_Instance(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override { return a == *this; }
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Declaration_Instance(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer);
    Declaration_Instance(IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer);
    Declaration_Instance(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer);
    Declaration_Instance(IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer);
    Declaration_Instance(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments);
    Declaration_Instance(IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments);
    Declaration_Instance(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments);
    Declaration_Instance(IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments);
    IRNODE_SUBCLASS(Declaration_Instance)
};
}  // namespace IR
namespace IR {
/// Toplevel program representation
class P4Program : public Node, public virtual IGeneralNamespace {
 public:
/// Top-level program objects.
/// This is not an IndexedVector because:
/// - we allow overloaded function-like objects.
/// - not all objects in a P4Program are declarations (e.g., match_kind is not).
    IR::Vector<IR::Node> objects;
#line 417 "/home/fengyong/Desktop/p4c/ir/ir.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 5449 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 418 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void validate() const override;
#line 5452 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    static const cstring main;
    IRNODE_DECLARE_APPLY_OVERLOAD(P4Program)
    bool operator==(IR::P4Program const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "P4Program"; }
    static cstring static_type_name() { return "P4Program"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    P4Program(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    P4Program(Util::SourceInfo srcInfo, IR::Vector<IR::Node> objects);
    P4Program(IR::Vector<IR::Node> objects);
    P4Program(Util::SourceInfo srcInfo);
    P4Program();
    IRNODE_SUBCLASS(P4Program)
};
}  // namespace IR
namespace IR {
///////////////////////////// Statements //////////////////////////
class Statement : public StatOrDecl {
 public:
    bool operator==(IR::Statement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Statement"; }
    static cstring static_type_name() { return "Statement"; }
    void toJSON(JSONGenerator & json) const override;
    Statement(JSONLoader & json);
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
 protected:
    Statement(Util::SourceInfo srcInfo);
    Statement();
    IRNODE_ABSTRACT_SUBCLASS(Statement)
};
}  // namespace IR
namespace IR {
class ExitStatement : public Statement {
 public:
#line 428 "/home/fengyong/Desktop/p4c/ir/ir.def"
    cstring toString() const override;
#line 5496 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 429 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void dbprint(std::ostream & out) const override;
#line 5499 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ExitStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "ExitStatement"; }
    static cstring static_type_name() { return "ExitStatement"; }
    void toJSON(JSONGenerator & json) const override;
    ExitStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Statement const & a) const override { return a == *this; }
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    ExitStatement(Util::SourceInfo srcInfo);
    ExitStatement();
    IRNODE_SUBCLASS(ExitStatement)
};
}  // namespace IR
namespace IR {
class ReturnStatement : public Statement {
 public:
    const IR::Expression* expression = nullptr;
#line 434 "/home/fengyong/Desktop/p4c/ir/ir.def"
    cstring toString() const override;
#line 5521 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ReturnStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "ReturnStatement"; }
    static cstring static_type_name() { return "ReturnStatement"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ReturnStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Statement const & a) const override { return a == *this; }
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    ReturnStatement(Util::SourceInfo srcInfo, const IR::Expression* expression);
    ReturnStatement(const IR::Expression* expression);
    IRNODE_SUBCLASS(ReturnStatement)
};
}  // namespace IR
namespace IR {
class EmptyStatement : public Statement {
 public:
#line 439 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void dbprint(std::ostream & out) const override;
#line 5545 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::EmptyStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "EmptyStatement"; }
    static cstring static_type_name() { return "EmptyStatement"; }
    void toJSON(JSONGenerator & json) const override;
    EmptyStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Statement const & a) const override { return a == *this; }
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    EmptyStatement(Util::SourceInfo srcInfo);
    EmptyStatement();
    IRNODE_SUBCLASS(EmptyStatement)
};
}  // namespace IR
namespace IR {
class AssignmentStatement : public Statement {
 public:
    const IR::Expression* left = nullptr;
    const IR::Expression* right = nullptr;
    bool operator==(IR::AssignmentStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "AssignmentStatement"; }
    static cstring static_type_name() { return "AssignmentStatement"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    AssignmentStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Statement const & a) const override { return a == *this; }
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    AssignmentStatement(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right);
    AssignmentStatement(const IR::Expression* left, const IR::Expression* right);
    IRNODE_SUBCLASS(AssignmentStatement)
};
}  // namespace IR
namespace IR {
class IfStatement : public Statement {
 public:
    const IR::Expression* condition = nullptr;
    const IR::Statement* ifTrue = nullptr;
    const IR::Statement* ifFalse = nullptr;
#line 451 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
#line 5594 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::IfStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void validate() const override;
    cstring node_type_name() const override { return "IfStatement"; }
    static cstring static_type_name() { return "IfStatement"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    IfStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Statement const & a) const override { return a == *this; }
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IfStatement(Util::SourceInfo srcInfo, const IR::Expression* condition, const IR::Statement* ifTrue, const IR::Statement* ifFalse);
    IfStatement(const IR::Expression* condition, const IR::Statement* ifTrue, const IR::Statement* ifFalse);
    IRNODE_SUBCLASS(IfStatement)
};
}  // namespace IR
namespace IR {
class BlockStatement : public Statement, public virtual ISimpleNamespace, public virtual IAnnotated {
 public:
    const IR::Annotations* annotations = Annotations::empty;
    IR::IndexedVector<IR::StatOrDecl> components;
#line 459 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 5619 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 461 "/home/fengyong/Desktop/p4c/ir/ir.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 5622 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 463 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void push_back(const IR::StatOrDecl* st);
#line 5625 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 464 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::Annotations *getAnnotations() const override;
#line 5628 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 465 "/home/fengyong/Desktop/p4c/ir/ir.def"
    bool empty() const;
#line 5631 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::BlockStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "BlockStatement"; }
    static cstring static_type_name() { return "BlockStatement"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    BlockStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Statement const & a) const override { return a == *this; }
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    BlockStatement(Util::SourceInfo srcInfo, const IR::Annotations* annotations, IR::IndexedVector<IR::StatOrDecl> components);
    BlockStatement(const IR::Annotations* annotations, IR::IndexedVector<IR::StatOrDecl> components);
    BlockStatement(Util::SourceInfo srcInfo, IR::IndexedVector<IR::StatOrDecl> components);
    BlockStatement(IR::IndexedVector<IR::StatOrDecl> components);
    BlockStatement(Util::SourceInfo srcInfo, const IR::Annotations* annotations);
    BlockStatement(const IR::Annotations* annotations);
    BlockStatement(Util::SourceInfo srcInfo);
    BlockStatement();
    IRNODE_SUBCLASS(BlockStatement)
};
}  // namespace IR
namespace IR {
class MethodCallStatement : public Statement {
 public:
    const IR::MethodCallExpression* methodCall = nullptr;
#line 471 "/home/fengyong/Desktop/p4c/ir/ir.def"
    MethodCallStatement(Util::SourceInfo si, IR::ID m, std::initializer_list<const IR::Argument *> const & a);
#line 5663 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 473 "/home/fengyong/Desktop/p4c/ir/ir.def"
    MethodCallStatement(Util::SourceInfo si, const IR::Expression* m, std::initializer_list<const IR::Argument *> const & a);
#line 5666 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 476 "/home/fengyong/Desktop/p4c/ir/ir.def"
    cstring toString() const override;
#line 5669 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::MethodCallStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "MethodCallStatement"; }
    static cstring static_type_name() { return "MethodCallStatement"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    MethodCallStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Statement const & a) const override { return a == *this; }
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    MethodCallStatement(Util::SourceInfo srcInfo, const IR::MethodCallExpression* methodCall);
    MethodCallStatement(const IR::MethodCallExpression* methodCall);
    IRNODE_SUBCLASS(MethodCallStatement)
};
}  // namespace IR
namespace IR {
class SwitchCase : public Node {
 public:
    const IR::Expression* label = nullptr;
    const IR::Statement* statement = nullptr;

#line 483 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void validate() const override;
#line 5697 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::SwitchCase const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "SwitchCase"; }
    static cstring static_type_name() { return "SwitchCase"; }
    void toJSON(JSONGenerator & json) const override;
    SwitchCase(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    SwitchCase(Util::SourceInfo srcInfo, const IR::Expression* label, const IR::Statement* statement);
    SwitchCase(const IR::Expression* label, const IR::Statement* statement);
    IRNODE_SUBCLASS(SwitchCase)
};
}  // namespace IR
namespace IR {

class SwitchStatement : public Statement {
 public:
    const IR::Expression* expression = nullptr;
    IR::Vector<IR::SwitchCase> cases;
#line 495 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
#line 5722 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::SwitchStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void validate() const override;
    cstring node_type_name() const override { return "SwitchStatement"; }
    static cstring static_type_name() { return "SwitchStatement"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    SwitchStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Statement const & a) const override { return a == *this; }
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    SwitchStatement(Util::SourceInfo srcInfo, const IR::Expression* expression, IR::Vector<IR::SwitchCase> cases);
    SwitchStatement(const IR::Expression* expression, IR::Vector<IR::SwitchCase> cases);
    IRNODE_SUBCLASS(SwitchStatement)
};
}  // namespace IR
namespace IR {
class Function : public Declaration, public virtual IFunctional, public virtual ISimpleNamespace, public virtual INestedNamespace {
 public:
    const IR::Type_Method* type = nullptr;
    const IR::BlockStatement* body = nullptr;
#line 505 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::ParameterList *getParameters() const override;
#line 5747 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 508 "/home/fengyong/Desktop/p4c/ir/ir.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 5750 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 510 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 5753 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 512 "/home/fengyong/Desktop/p4c/ir/ir.def"
    std::vector<const IR::INamespace *> getNestedNamespaces() const override;
#line 5756 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Function const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Function"; }
    static cstring static_type_name() { return "Function"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Function(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override { return a == *this; }
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Function(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Method* type, const IR::BlockStatement* body);
    Function(IR::ID name, const IR::Type_Method* type, const IR::BlockStatement* body);
    IRNODE_SUBCLASS(Function)
};
}  // namespace IR
namespace IR {
/////////////////////////////////////////////////////////////
/**
 * Block is the base class for IR nodes produced by the evaluator.
 * A block represents a compile-time allocated resource.
 * Blocks are not visited using visitors, so the visit_children()
 * method is empty.  Users have to write custom visitors to
 * traverse the constantValue map.
 */
class Block : public Node, public virtual CompileTimeValue {
 public:
    const IR::Node* node = nullptr;
/// Node that evaluates to this block.
/// This is either a Declaration_Instance or a ConstructorCallExpression.
/// One value for each Node inside that evaluates to a compile-time constant.
/// This includes all constructor parameters, and all inner nested blocks.
    ordered_map<const IR::Node *, const IR::CompileTimeValue *> constantValue = {};
#line 533 "/home/fengyong/Desktop/p4c/ir/ir.def"
    virtual void dbprint(std::ostream & out) const override;
#line 5795 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 534 "/home/fengyong/Desktop/p4c/ir/ir.def"
    virtual void dbprint_recursive(std::ostream & out) const;
#line 5798 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
/// value can be null for parameters which are optional
#line 536 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void setValue(const IR::Node* node, const IR::CompileTimeValue* value);
#line 5802 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 537 "/home/fengyong/Desktop/p4c/ir/ir.def"
    bool hasValue(const IR::Node* node) const;
#line 5805 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 540 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::CompileTimeValue *getValue(const IR::Node* node) const;
#line 5808 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 545 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
#line 5812 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 546 "/home/fengyong/Desktop/p4c/ir/ir.def"
    virtual IR::IDeclaration const * getContainer() const;
#line 5815 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Block const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Block"; }
    static cstring static_type_name() { return "Block"; }
    void toJSON(JSONGenerator & json) const override;
    Block(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
 protected:
    Block(Util::SourceInfo srcInfo, const IR::Node* node);
    Block(const IR::Node* node);
    IRNODE_ABSTRACT_SUBCLASS(Block)
};
}  // namespace IR
namespace IR {
class TableBlock : public Block {
 public:
    const IR::P4Table* container = nullptr;
#line 551 "/home/fengyong/Desktop/p4c/ir/ir.def"
    IR::IDeclaration const * getContainer() const override;
#line 5836 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::TableBlock const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "TableBlock"; }
    static cstring static_type_name() { return "TableBlock"; }
    void toJSON(JSONGenerator & json) const override;
    TableBlock(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Block const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    TableBlock(Util::SourceInfo srcInfo, const IR::Node* node, const IR::P4Table* container);
    TableBlock(const IR::Node* node, const IR::P4Table* container);
    IRNODE_SUBCLASS(TableBlock)
};
}  // namespace IR
namespace IR {
/// An object that has been instantiated
class InstantiatedBlock : public Block, public virtual IDeclaration {
 public:
    const IR::Type* instanceType = nullptr;

#line 559 "/home/fengyong/Desktop/p4c/ir/ir.def"
    virtual const IR::ParameterList *getConstructorParameters() const = 0;
#line 5862 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 560 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void instantiate(std::vector<const IR::CompileTimeValue *> * args);
#line 5865 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
/// @return the argument that the given parameter was instantiated with.
/// It's a fatal error if no such parameter exists.
#line 564 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::CompileTimeValue *getParameterValue(cstring paramName) const;
#line 5870 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
/// @return the argument that the given parameter was instantiated with, or
/// null if no such parameter exists.
#line 568 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::CompileTimeValue *findParameterValue(cstring paramName) const;
#line 5875 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 570 "/home/fengyong/Desktop/p4c/ir/ir.def"
    virtual void dbprint(std::ostream & out) const override;
#line 5878 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::InstantiatedBlock const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "InstantiatedBlock"; }
    static cstring static_type_name() { return "InstantiatedBlock"; }
    void toJSON(JSONGenerator & json) const override;
    InstantiatedBlock(JSONLoader & json);
    bool operator==(IR::Block const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
 protected:
    InstantiatedBlock(Util::SourceInfo srcInfo, const IR::Node* node, const IR::Type* instanceType);
    InstantiatedBlock(const IR::Node* node, const IR::Type* instanceType);
    IRNODE_ABSTRACT_SUBCLASS(InstantiatedBlock)
};
}  // namespace IR
namespace IR {
class ParserBlock : public InstantiatedBlock {
 public:
    const IR::P4Parser* container = nullptr;
#line 575 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::ParameterList *getConstructorParameters() const override;
#line 5902 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 577 "/home/fengyong/Desktop/p4c/ir/ir.def"
    cstring toString() const override;
#line 5905 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 578 "/home/fengyong/Desktop/p4c/ir/ir.def"
    IR::ID getName() const override;
#line 5908 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 579 "/home/fengyong/Desktop/p4c/ir/ir.def"
    IR::IDeclaration const * getContainer() const override;
#line 5911 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ParserBlock const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "ParserBlock"; }
    static cstring static_type_name() { return "ParserBlock"; }
    void toJSON(JSONGenerator & json) const override;
    ParserBlock(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::InstantiatedBlock const & a) const override { return a == *this; }
    bool operator==(IR::Block const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    ParserBlock(Util::SourceInfo srcInfo, const IR::Node* node, const IR::Type* instanceType, const IR::P4Parser* container);
    ParserBlock(const IR::Node* node, const IR::Type* instanceType, const IR::P4Parser* container);
    IRNODE_SUBCLASS(ParserBlock)
};
}  // namespace IR
namespace IR {
class ControlBlock : public InstantiatedBlock {
 public:
    const IR::P4Control* container = nullptr;
#line 585 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::ParameterList *getConstructorParameters() const override;
#line 5936 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 587 "/home/fengyong/Desktop/p4c/ir/ir.def"
    cstring toString() const override;
#line 5939 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 588 "/home/fengyong/Desktop/p4c/ir/ir.def"
    IR::ID getName() const override;
#line 5942 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 589 "/home/fengyong/Desktop/p4c/ir/ir.def"
    IR::IDeclaration const * getContainer() const override;
#line 5945 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ControlBlock const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "ControlBlock"; }
    static cstring static_type_name() { return "ControlBlock"; }
    void toJSON(JSONGenerator & json) const override;
    ControlBlock(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::InstantiatedBlock const & a) const override { return a == *this; }
    bool operator==(IR::Block const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    ControlBlock(Util::SourceInfo srcInfo, const IR::Node* node, const IR::Type* instanceType, const IR::P4Control* container);
    ControlBlock(const IR::Node* node, const IR::Type* instanceType, const IR::P4Control* container);
    IRNODE_SUBCLASS(ControlBlock)
};
}  // namespace IR
namespace IR {
class PackageBlock : public InstantiatedBlock {
 public:
    const IR::Type_Package* type = nullptr;
#line 595 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::ParameterList *getConstructorParameters() const override;
#line 5970 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 596 "/home/fengyong/Desktop/p4c/ir/ir.def"
    cstring toString() const override;
#line 5973 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 597 "/home/fengyong/Desktop/p4c/ir/ir.def"
    IR::ID getName() const override;
#line 5976 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::PackageBlock const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "PackageBlock"; }
    static cstring static_type_name() { return "PackageBlock"; }
    void toJSON(JSONGenerator & json) const override;
    PackageBlock(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::InstantiatedBlock const & a) const override { return a == *this; }
    bool operator==(IR::Block const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    PackageBlock(Util::SourceInfo srcInfo, const IR::Node* node, const IR::Type* instanceType, const IR::Type_Package* type);
    PackageBlock(const IR::Node* node, const IR::Type* instanceType, const IR::Type_Package* type);
    IRNODE_SUBCLASS(PackageBlock)
};
}  // namespace IR
namespace IR {
class ExternBlock : public InstantiatedBlock {
 public:
    const IR::Type_Extern* type = nullptr;
    const IR::Method* constructor = nullptr;

#line 604 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::ParameterList *getConstructorParameters() const override;
#line 6003 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 606 "/home/fengyong/Desktop/p4c/ir/ir.def"
    cstring toString() const override;
#line 6006 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 607 "/home/fengyong/Desktop/p4c/ir/ir.def"
    IR::ID getName() const override;
#line 6009 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ExternBlock const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "ExternBlock"; }
    static cstring static_type_name() { return "ExternBlock"; }
    void toJSON(JSONGenerator & json) const override;
    ExternBlock(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::InstantiatedBlock const & a) const override { return a == *this; }
    bool operator==(IR::Block const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    ExternBlock(Util::SourceInfo srcInfo, const IR::Node* node, const IR::Type* instanceType, const IR::Type_Extern* type, const IR::Method* constructor);
    ExternBlock(const IR::Node* node, const IR::Type* instanceType, const IR::Type_Extern* type, const IR::Method* constructor);
    IRNODE_SUBCLASS(ExternBlock)
};
}  // namespace IR
namespace IR {
/// Represents the program as a whole
class ToplevelBlock : public Block, public virtual IDeclaration {
 public:
#line 613 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::P4Program *getProgram() const;
#line 6034 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 614 "/home/fengyong/Desktop/p4c/ir/ir.def"
    const IR::PackageBlock *getMain() const;
#line 6037 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 615 "/home/fengyong/Desktop/p4c/ir/ir.def"
    IR::ID getName() const override;
#line 6040 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 617 "/home/fengyong/Desktop/p4c/ir/ir.def"
    void validate() const override;
#line 6043 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ToplevelBlock const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "ToplevelBlock"; }
    static cstring static_type_name() { return "ToplevelBlock"; }
    void toJSON(JSONGenerator & json) const override;
    ToplevelBlock(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Block const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    ToplevelBlock(Util::SourceInfo srcInfo, const IR::Node* node);
    ToplevelBlock(const IR::Node* node);
    IRNODE_SUBCLASS(ToplevelBlock)
};
}  // namespace IR
/** @} */
/* end group irdefs */
/* -*-C++-*- */
/*
  This file contains IR classes needed just for the P4 v1.0/v1.1 front-end.
*/
/** \addtogroup irdefs
  * @{
  */
#line 11 "/home/fengyong/Desktop/p4c/ir/v1.def"
namespace IR {
enum class CounterType { NONE, PACKETS, BYTES, BOTH };
}

inline std::ostream& operator<<(std::ostream &out, IR::CounterType d) {
    switch (d) {
        case IR::CounterType::NONE:
            out << "NONE";
            break;
        case IR::CounterType::PACKETS:
            out << "PACKETS";
            break;
        case IR::CounterType::BYTES:
            out << "BYTES";
            break;
        case IR::CounterType::BOTH:
            out << "BOTH";
            break;
        default:
            BUG("Unhandled case");
    }
    return out;
}

inline bool operator>>(cstring s, IR::CounterType &ctr) {
    if (!s || s == "" || s == "NONE") ctr = IR::CounterType::NONE;
    else if (s == "PACKETS") ctr = IR::CounterType::PACKETS;
    else if (s == "BYTES") ctr = IR::CounterType::BYTES;
    else if (s == "BOTH") ctr = IR::CounterType::BOTH;
    else return false;
    return true;
}
#line 6100 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
namespace IR {
class Type_Block : public Type_Base {
 public:
#line 46 "/home/fengyong/Desktop/p4c/ir/v1.def"
    cstring toString() const override;
#line 6106 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 47 "/home/fengyong/Desktop/p4c/ir/v1.def"
    static const IR::Type_Block *get();
#line 6109 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 48 "/home/fengyong/Desktop/p4c/ir/v1.def"
    void dbprint(std::ostream & out) const override;
#line 6112 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Block const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Block"; }
    static cstring static_type_name() { return "Type_Block"; }
    void toJSON(JSONGenerator & json) const override;
    Type_Block(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Block(Util::SourceInfo srcInfo);
    Type_Block();
    IRNODE_SUBCLASS(Type_Block)
};
}  // namespace IR
namespace IR {
class Type_Counter : public Type_Base {
 public:
#line 51 "/home/fengyong/Desktop/p4c/ir/v1.def"
    cstring toString() const override;
#line 6133 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 52 "/home/fengyong/Desktop/p4c/ir/v1.def"
    static const IR::Type_Counter *get();
#line 6136 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 53 "/home/fengyong/Desktop/p4c/ir/v1.def"
    void dbprint(std::ostream & out) const override;
#line 6139 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Counter const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Counter"; }
    static cstring static_type_name() { return "Type_Counter"; }
    void toJSON(JSONGenerator & json) const override;
    Type_Counter(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Counter(Util::SourceInfo srcInfo);
    Type_Counter();
    IRNODE_SUBCLASS(Type_Counter)
};
}  // namespace IR
namespace IR {
class Type_Expression : public Type_Base {
 public:
#line 56 "/home/fengyong/Desktop/p4c/ir/v1.def"
    cstring toString() const override;
#line 6160 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 57 "/home/fengyong/Desktop/p4c/ir/v1.def"
    static const IR::Type_Expression *get();
#line 6163 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 58 "/home/fengyong/Desktop/p4c/ir/v1.def"
    void dbprint(std::ostream & out) const override;
#line 6166 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Expression const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Expression"; }
    static cstring static_type_name() { return "Type_Expression"; }
    void toJSON(JSONGenerator & json) const override;
    Type_Expression(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Expression(Util::SourceInfo srcInfo);
    Type_Expression();
    IRNODE_SUBCLASS(Type_Expression)
};
}  // namespace IR
namespace IR {
class Type_FieldListCalculation : public Type_Base {
 public:
#line 61 "/home/fengyong/Desktop/p4c/ir/v1.def"
    cstring toString() const override;
#line 6187 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 62 "/home/fengyong/Desktop/p4c/ir/v1.def"
    static const IR::Type_FieldListCalculation *get();
#line 6190 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 63 "/home/fengyong/Desktop/p4c/ir/v1.def"
    void dbprint(std::ostream & out) const override;
#line 6193 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_FieldListCalculation const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_FieldListCalculation"; }
    static cstring static_type_name() { return "Type_FieldListCalculation"; }
    void toJSON(JSONGenerator & json) const override;
    Type_FieldListCalculation(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_FieldListCalculation(Util::SourceInfo srcInfo);
    Type_FieldListCalculation();
    IRNODE_SUBCLASS(Type_FieldListCalculation)
};
}  // namespace IR
namespace IR {
class Type_Meter : public Type_Base {
 public:
#line 66 "/home/fengyong/Desktop/p4c/ir/v1.def"
    cstring toString() const override;
#line 6214 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 67 "/home/fengyong/Desktop/p4c/ir/v1.def"
    static const IR::Type_Meter *get();
#line 6217 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 68 "/home/fengyong/Desktop/p4c/ir/v1.def"
    void dbprint(std::ostream & out) const override;
#line 6220 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Meter const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Meter"; }
    static cstring static_type_name() { return "Type_Meter"; }
    void toJSON(JSONGenerator & json) const override;
    Type_Meter(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Meter(Util::SourceInfo srcInfo);
    Type_Meter();
    IRNODE_SUBCLASS(Type_Meter)
};
}  // namespace IR
namespace IR {
class Type_Register : public Type_Base {
 public:
#line 71 "/home/fengyong/Desktop/p4c/ir/v1.def"
    cstring toString() const override;
#line 6241 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 72 "/home/fengyong/Desktop/p4c/ir/v1.def"
    static const IR::Type_Register *get();
#line 6244 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 73 "/home/fengyong/Desktop/p4c/ir/v1.def"
    void dbprint(std::ostream & out) const override;
#line 6247 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_Register const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_Register"; }
    static cstring static_type_name() { return "Type_Register"; }
    void toJSON(JSONGenerator & json) const override;
    Type_Register(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_Register(Util::SourceInfo srcInfo);
    Type_Register();
    IRNODE_SUBCLASS(Type_Register)
};
}  // namespace IR
namespace IR {
class Type_AnyTable : public Type_Base {
 public:
#line 76 "/home/fengyong/Desktop/p4c/ir/v1.def"
    cstring toString() const override;
#line 6268 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 77 "/home/fengyong/Desktop/p4c/ir/v1.def"
    static const IR::Type_AnyTable *get();
#line 6271 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 78 "/home/fengyong/Desktop/p4c/ir/v1.def"
    void dbprint(std::ostream & out) const override;
#line 6274 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Type_AnyTable const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Type_AnyTable"; }
    static cstring static_type_name() { return "Type_AnyTable"; }
    void toJSON(JSONGenerator & json) const override;
    Type_AnyTable(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Base const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Type_AnyTable(Util::SourceInfo srcInfo);
    Type_AnyTable();
    IRNODE_SUBCLASS(Type_AnyTable)
};
}  // namespace IR
namespace IR {
class HeaderOrMetadata : public Node, public virtual IAnnotated {
 public:
    IR::ID type_name;
    IR::ID name;
    const IR::Annotations* annotations = nullptr;
    const IR::Type_StructLike* type = nullptr;
#line 87 "/home/fengyong/Desktop/p4c/ir/v1.def"
    const IR::Annotations *getAnnotations() const override;
#line 6299 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 88 "/home/fengyong/Desktop/p4c/ir/v1.def"
    HeaderOrMetadata(IR::ID n, const IR::Type_StructLike* t);
#line 6302 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 90 "/home/fengyong/Desktop/p4c/ir/v1.def"
    void dbprint(std::ostream & out) const override;
#line 6305 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::HeaderOrMetadata const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "HeaderOrMetadata"; }
    static cstring static_type_name() { return "HeaderOrMetadata"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    HeaderOrMetadata(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
 protected:
    HeaderOrMetadata(Util::SourceInfo srcInfo, IR::ID type_name, IR::ID name, const IR::Annotations* annotations);
    HeaderOrMetadata(IR::ID type_name, IR::ID name, const IR::Annotations* annotations);
    IRNODE_ABSTRACT_SUBCLASS(HeaderOrMetadata)
};
}  // namespace IR
namespace IR {
class Header : public HeaderOrMetadata {
 public:
#line 94 "/home/fengyong/Desktop/p4c/ir/v1.def"
    Header(IR::ID n, const IR::Type_Header* t);
#line 6328 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Header const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Header"; }
    static cstring static_type_name() { return "Header"; }
    void toJSON(JSONGenerator & json) const override;
    Header(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::HeaderOrMetadata const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Header(Util::SourceInfo srcInfo, IR::ID type_name, IR::ID name, const IR::Annotations* annotations);
    Header(IR::ID type_name, IR::ID name, const IR::Annotations* annotations);
    IRNODE_SUBCLASS(Header)
};
}  // namespace IR
namespace IR {
class HeaderStack : public HeaderOrMetadata {
 public:
    int size;
#line 100 "/home/fengyong/Desktop/p4c/ir/v1.def"
    HeaderStack(IR::ID n, const IR::Type_Header* t, int sz);
#line 6349 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::HeaderStack const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "HeaderStack"; }
    static cstring static_type_name() { return "HeaderStack"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    HeaderStack(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::HeaderOrMetadata const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    HeaderStack(Util::SourceInfo srcInfo, IR::ID type_name, IR::ID name, const IR::Annotations* annotations, int size);
    HeaderStack(IR::ID type_name, IR::ID name, const IR::Annotations* annotations, int size);
    IRNODE_SUBCLASS(HeaderStack)
};
}  // namespace IR
namespace IR {
class Metadata : public HeaderOrMetadata {
 public:
#line 105 "/home/fengyong/Desktop/p4c/ir/v1.def"
    Metadata(IR::ID n, const IR::Type_StructLike* t);
#line 6370 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Metadata const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Metadata"; }
    static cstring static_type_name() { return "Metadata"; }
    void toJSON(JSONGenerator & json) const override;
    Metadata(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::HeaderOrMetadata const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Metadata(Util::SourceInfo srcInfo, IR::ID type_name, IR::ID name, const IR::Annotations* annotations);
    Metadata(IR::ID type_name, IR::ID name, const IR::Annotations* annotations);
    IRNODE_SUBCLASS(Metadata)
};
}  // namespace IR
namespace IR {
class HeaderRef : public Expression {
 public:
#line 110 "/home/fengyong/Desktop/p4c/ir/v1.def"
    virtual const IR::HeaderOrMetadata *baseRef() const = 0;
#line 6390 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::HeaderRef const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "HeaderRef"; }
    static cstring static_type_name() { return "HeaderRef"; }
    void toJSON(JSONGenerator & json) const override;
    HeaderRef(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
 protected:
    HeaderRef(Util::SourceInfo srcInfo, const IR::Type* type);
    HeaderRef(const IR::Type* type);
    HeaderRef(Util::SourceInfo srcInfo);
    HeaderRef();
    IRNODE_ABSTRACT_SUBCLASS(HeaderRef)
};
}  // namespace IR
namespace IR {
class ConcreteHeaderRef : public HeaderRef {
 public:
    const IR::HeaderOrMetadata* ref = nullptr;
#line 116 "/home/fengyong/Desktop/p4c/ir/v1.def"
    const IR::HeaderOrMetadata *baseRef() const override;
#line 6413 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 117 "/home/fengyong/Desktop/p4c/ir/v1.def"
    cstring toString() const override;
#line 6416 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 118 "/home/fengyong/Desktop/p4c/ir/v1.def"
    void dbprint(std::ostream & out) const override;
#line 6419 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ConcreteHeaderRef const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "ConcreteHeaderRef"; }
    static cstring static_type_name() { return "ConcreteHeaderRef"; }
    void toJSON(JSONGenerator & json) const override;
    ConcreteHeaderRef(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::HeaderRef const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    ConcreteHeaderRef(Util::SourceInfo srcInfo, const IR::Type* type, const IR::HeaderOrMetadata* ref);
    ConcreteHeaderRef(const IR::Type* type, const IR::HeaderOrMetadata* ref);
    ConcreteHeaderRef(Util::SourceInfo srcInfo, const IR::HeaderOrMetadata* ref);
    ConcreteHeaderRef(const IR::HeaderOrMetadata* ref);
    IRNODE_SUBCLASS(ConcreteHeaderRef)
};
}  // namespace IR
namespace IR {
class HeaderStackItemRef : public HeaderRef {
 public:
    const IR::Expression* base_ = nullptr;
    const IR::Expression* index_ = nullptr;
#line 128 "/home/fengyong/Desktop/p4c/ir/v1.def"
    const IR::Expression *base() const;
#line 6447 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
/// Returns `nullptr` if the base is not `HeaderOrMetadata` (e.g. when this
/// is stack ref of an expression such as `lookahead`).
#line 131 "/home/fengyong/Desktop/p4c/ir/v1.def"
    const IR::HeaderOrMetadata *baseRef() const override;
#line 6452 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 135 "/home/fengyong/Desktop/p4c/ir/v1.def"
    const IR::Expression *index() const;
#line 6455 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 136 "/home/fengyong/Desktop/p4c/ir/v1.def"
    void set_base(const IR::Expression* b);
#line 6458 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 137 "/home/fengyong/Desktop/p4c/ir/v1.def"
    cstring toString() const override;
#line 6461 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::HeaderStackItemRef const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "HeaderStackItemRef"; }
    static cstring static_type_name() { return "HeaderStackItemRef"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    HeaderStackItemRef(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::HeaderRef const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    HeaderStackItemRef(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* base_, const IR::Expression* index_);
    HeaderStackItemRef(const IR::Type* type, const IR::Expression* base_, const IR::Expression* index_);
    HeaderStackItemRef(Util::SourceInfo srcInfo, const IR::Expression* base_, const IR::Expression* index_);
    HeaderStackItemRef(const IR::Expression* base_, const IR::Expression* index_);
    IRNODE_SUBCLASS(HeaderStackItemRef)
};
}  // namespace IR
namespace IR {
class If : public Expression {
 public:
    const IR::Expression* pred = nullptr;
    const IR::Vector<IR::Expression>* ifTrue = nullptr;
    const IR::Vector<IR::Expression>* ifFalse = nullptr;
#line 144 "/home/fengyong/Desktop/p4c/ir/v1.def"
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
#line 6492 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::If const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void validate() const override;
    cstring node_type_name() const override { return "If"; }
    static cstring static_type_name() { return "If"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    If(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    If(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* pred, const IR::Vector<IR::Expression>* ifTrue, const IR::Vector<IR::Expression>* ifFalse);
    If(const IR::Type* type, const IR::Expression* pred, const IR::Vector<IR::Expression>* ifTrue, const IR::Vector<IR::Expression>* ifFalse);
    If(Util::SourceInfo srcInfo, const IR::Expression* pred, const IR::Vector<IR::Expression>* ifTrue, const IR::Vector<IR::Expression>* ifFalse);
    If(const IR::Expression* pred, const IR::Vector<IR::Expression>* ifTrue, const IR::Vector<IR::Expression>* ifFalse);
    IRNODE_SUBCLASS(If)
};
}  // namespace IR
namespace IR {

class NamedCond : public If {
 public:
    cstring name = unique_name();
#line 155 "/home/fengyong/Desktop/p4c/ir/v1.def"
    static cstring unique_name();
#line 6518 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 156 "/home/fengyong/Desktop/p4c/ir/v1.def"
    NamedCond(IR::If const & i);
#line 6521 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 157 "/home/fengyong/Desktop/p4c/ir/v1.def"
    bool operator==(IR::NamedCond const & a) const override;
#line 6524 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "NamedCond"; }
    static cstring static_type_name() { return "NamedCond"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    NamedCond(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::If const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_SUBCLASS(NamedCond)
};
}  // namespace IR
namespace IR {
class Apply : public Expression {
 public:
    IR::ID name;

    IR::NameMap<IR::Vector<IR::Expression>, ordered_map> actions = {};

    IR::NameMap<IR::Path> position = {};
    bool operator==(IR::Apply const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Apply"; }
    static cstring static_type_name() { return "Apply"; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Apply(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Apply(Util::SourceInfo srcInfo, const IR::Type* type, IR::ID name);
    Apply(const IR::Type* type, IR::ID name);
    Apply(Util::SourceInfo srcInfo, IR::ID name);
    Apply(IR::ID name);
    Apply(Util::SourceInfo srcInfo, const IR::Type* type);
    Apply(const IR::Type* type);
    Apply(Util::SourceInfo srcInfo);
    Apply();
    IRNODE_SUBCLASS(Apply)
};
}  // namespace IR
namespace IR {
class Primitive : public Operation {
 public:
    cstring name;
    IR::Vector<IR::Expression> operands = {};
#line 174 "/home/fengyong/Desktop/p4c/ir/v1.def"
    Primitive(cstring n, const IR::Vector<IR::Expression>* l);
#line 6578 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 176 "/home/fengyong/Desktop/p4c/ir/v1.def"
    Primitive(Util::SourceInfo si, cstring n, const IR::Vector<IR::Expression>* l);
#line 6581 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 178 "/home/fengyong/Desktop/p4c/ir/v1.def"
    Primitive(cstring n, const IR::Expression* a1);
#line 6584 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 180 "/home/fengyong/Desktop/p4c/ir/v1.def"
    Primitive(Util::SourceInfo si, cstring n, const IR::Expression* a1);
#line 6587 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 182 "/home/fengyong/Desktop/p4c/ir/v1.def"
    Primitive(cstring n, const IR::Expression* a1, const IR::Expression* a2);
#line 6590 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 184 "/home/fengyong/Desktop/p4c/ir/v1.def"
    Primitive(Util::SourceInfo si, cstring n, const IR::Expression* a1, const IR::Expression* a2);
#line 6593 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 187 "/home/fengyong/Desktop/p4c/ir/v1.def"
    Primitive(cstring n, const IR::Expression* a1, const IR::Vector<IR::Expression>* a2);
#line 6596 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 190 "/home/fengyong/Desktop/p4c/ir/v1.def"
    Primitive(Util::SourceInfo si, cstring n, const IR::Expression* a1, const IR::Vector<IR::Expression>* a2);
#line 6599 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 194 "/home/fengyong/Desktop/p4c/ir/v1.def"
    Primitive(cstring n, const IR::Expression* a1, const IR::Expression* a2, const IR::Expression* a3);
#line 6602 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 196 "/home/fengyong/Desktop/p4c/ir/v1.def"
    Primitive(Util::SourceInfo si, cstring n, const IR::Expression* a1, const IR::Expression* a2, const IR::Expression* a3);
#line 6605 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 199 "/home/fengyong/Desktop/p4c/ir/v1.def"
    virtual bool isOutput(int operand_index) const;
#line 6608 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 200 "/home/fengyong/Desktop/p4c/ir/v1.def"
    virtual unsigned inferOperandTypes() const;
#line 6611 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 201 "/home/fengyong/Desktop/p4c/ir/v1.def"
    virtual const IR::Type *inferOperandType(int operand) const;
#line 6614 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 202 "/home/fengyong/Desktop/p4c/ir/v1.def"
    virtual void typecheck() const;
#line 6617 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    IRNODE_DECLARE_APPLY_OVERLOAD(Primitive)
    cstring getStringOp() const override { return name; }
    int getPrecedence() const override { return DBPrint::Prec_Postfix; }
    bool operator==(IR::Primitive const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Primitive"; }
    static cstring static_type_name() { return "Primitive"; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Primitive(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Primitive(Util::SourceInfo srcInfo, const IR::Type* type, cstring name);
    Primitive(const IR::Type* type, cstring name);
    Primitive(Util::SourceInfo srcInfo, cstring name);
    Primitive(cstring name);
    IRNODE_SUBCLASS(Primitive)
};
}  // namespace IR
namespace IR {
class FieldList : public Node, public virtual IAnnotated {
 public:
    IR::ID name;
    bool payload = false;
    const IR::Annotations* annotations = Annotations::empty;
    IR::Vector<IR::Expression> fields = {};
#line 213 "/home/fengyong/Desktop/p4c/ir/v1.def"
    const IR::Annotations *getAnnotations() const override;
#line 6652 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::FieldList const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "FieldList"; }
    static cstring static_type_name() { return "FieldList"; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    FieldList(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    FieldList(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations);
    FieldList(IR::ID name, const IR::Annotations* annotations);
    FieldList(Util::SourceInfo srcInfo, const IR::Annotations* annotations);
    FieldList(const IR::Annotations* annotations);
    FieldList(Util::SourceInfo srcInfo, IR::ID name);
    FieldList(IR::ID name);
    FieldList(Util::SourceInfo srcInfo);
    FieldList();
    IRNODE_SUBCLASS(FieldList)
};
}  // namespace IR
namespace IR {
class FieldListCalculation : public Node, public virtual IAnnotated {
 public:
    IR::ID name;
    const IR::NameList* input = nullptr;
    const IR::FieldList* input_fields = nullptr;
    const IR::NameList* algorithm = nullptr;
    int output_width = 0;
    const IR::Annotations* annotations = Annotations::empty;
#line 223 "/home/fengyong/Desktop/p4c/ir/v1.def"
    const IR::Annotations *getAnnotations() const override;
#line 6688 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::FieldListCalculation const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "FieldListCalculation"; }
    static cstring static_type_name() { return "FieldListCalculation"; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    FieldListCalculation(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    FieldListCalculation(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations);
    FieldListCalculation(IR::ID name, const IR::Annotations* annotations);
    FieldListCalculation(Util::SourceInfo srcInfo, const IR::Annotations* annotations);
    FieldListCalculation(const IR::Annotations* annotations);
    FieldListCalculation(Util::SourceInfo srcInfo, IR::ID name);
    FieldListCalculation(IR::ID name);
    FieldListCalculation(Util::SourceInfo srcInfo);
    FieldListCalculation();
    IRNODE_SUBCLASS(FieldListCalculation)
};
}  // namespace IR
namespace IR {
class CalculatedField : public Node, public virtual IAnnotated {
 public:
    const IR::Expression* field = nullptr;
class update_or_verify {
 public:
    Util::SourceInfo srcInfo;
    bool update = false;
    IR::ID name;
    const IR::Expression* cond = nullptr;
#line 233 "/home/fengyong/Desktop/p4c/ir/v1.def"
    update_or_verify();
#line 6725 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"

    bool operator==(IR::CalculatedField::update_or_verify const & a) const;
    void toJSON(JSONGenerator & json) const;
    update_or_verify(JSONLoader & json);
    static IR::CalculatedField::update_or_verify * fromJSON(JSONLoader & json);
    update_or_verify(Util::SourceInfo srcInfo, bool update, IR::ID name, const IR::Expression* cond);
    update_or_verify(Util::SourceInfo srcInfo, IR::ID name, const IR::Expression* cond);
};
    safe_vector<update_or_verify> specs = {};
    const IR::Annotations* annotations = nullptr;
#line 237 "/home/fengyong/Desktop/p4c/ir/v1.def"
    const IR::Annotations *getAnnotations() const override;
#line 6738 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 238 "/home/fengyong/Desktop/p4c/ir/v1.def"
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
#line 6742 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::CalculatedField const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void validate() const override;
    cstring node_type_name() const override { return "CalculatedField"; }
    static cstring static_type_name() { return "CalculatedField"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    CalculatedField(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    CalculatedField(Util::SourceInfo srcInfo, const IR::Expression* field, const IR::Annotations* annotations);
    CalculatedField(const IR::Expression* field, const IR::Annotations* annotations);
    CalculatedField(Util::SourceInfo srcInfo, const IR::Annotations* annotations);
    CalculatedField(const IR::Annotations* annotations);
    IRNODE_SUBCLASS(CalculatedField)
};
}  // namespace IR
namespace IR {
class ParserValueSet : public Node, public virtual IAnnotated {
 public:
    IR::ID name;
    const IR::Annotations* annotations = Annotations::empty;
#line 247 "/home/fengyong/Desktop/p4c/ir/v1.def"
    const IR::Annotations *getAnnotations() const override;
#line 6767 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 248 "/home/fengyong/Desktop/p4c/ir/v1.def"
    void dbprint(std::ostream & out) const override;
#line 6770 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 249 "/home/fengyong/Desktop/p4c/ir/v1.def"
    cstring toString() const override;
#line 6773 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ParserValueSet const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "ParserValueSet"; }
    static cstring static_type_name() { return "ParserValueSet"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ParserValueSet(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    ParserValueSet(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations);
    ParserValueSet(IR::ID name, const IR::Annotations* annotations);
    ParserValueSet(Util::SourceInfo srcInfo, IR::ID name);
    ParserValueSet(IR::ID name);
    IRNODE_SUBCLASS(ParserValueSet)
};
}  // namespace IR
namespace IR {
class CaseEntry : public Node {
 public:
    safe_vector<std::pair<const IR::Expression *, const IR::Constant *>> values = {};
    IR::ID action;
    bool operator==(IR::CaseEntry const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "CaseEntry"; }
    static cstring static_type_name() { return "CaseEntry"; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    CaseEntry(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    CaseEntry(Util::SourceInfo srcInfo, IR::ID action);
    CaseEntry(IR::ID action);
    CaseEntry(Util::SourceInfo srcInfo);
    CaseEntry();
    IRNODE_SUBCLASS(CaseEntry)
};
}  // namespace IR
namespace IR {
class V1Parser : public Node, public virtual IAnnotated {
 public:
    IR::ID name;
    IR::Vector<IR::Expression> stmts = {};
    const IR::Vector<IR::Expression>* select = nullptr;
    const IR::Vector<IR::CaseEntry>* cases = nullptr;
    IR::ID default_return = {};
    IR::ID parse_error = {};
    bool drop = false;
    const IR::Annotations* annotations = nullptr;
#line 266 "/home/fengyong/Desktop/p4c/ir/v1.def"
    const IR::Annotations *getAnnotations() const override;
#line 6828 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 267 "/home/fengyong/Desktop/p4c/ir/v1.def"
    cstring toString() const override;
#line 6831 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::V1Parser const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "V1Parser"; }
    static cstring static_type_name() { return "V1Parser"; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    V1Parser(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    V1Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations);
    V1Parser(IR::ID name, const IR::Annotations* annotations);
    V1Parser(Util::SourceInfo srcInfo, const IR::Annotations* annotations);
    V1Parser(const IR::Annotations* annotations);
    IRNODE_SUBCLASS(V1Parser)
};
}  // namespace IR
namespace IR {
class ParserException : public Node {
 public:
    bool operator==(IR::ParserException const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "ParserException"; }
    static cstring static_type_name() { return "ParserException"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ParserException(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    ParserException(Util::SourceInfo srcInfo);
    ParserException();
    IRNODE_SUBCLASS(ParserException)
};
}  // namespace IR
namespace IR {
class Attached : public Node, public virtual IInstance, public virtual IAnnotated {
 public:
    IR::ID name;
    const IR::Annotations* annotations = Annotations::empty;
#line 275 "/home/fengyong/Desktop/p4c/ir/v1.def"
    IR::ID Name() const override;
#line 6876 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 276 "/home/fengyong/Desktop/p4c/ir/v1.def"
    virtual char const * kind() const = 0;
#line 6879 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 277 "/home/fengyong/Desktop/p4c/ir/v1.def"
    const IR::Type *getType() const override;
#line 6882 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 278 "/home/fengyong/Desktop/p4c/ir/v1.def"
    const IR::Annotations *getAnnotations() const override;
#line 6885 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 279 "/home/fengyong/Desktop/p4c/ir/v1.def"
    virtual bool indexed() const;
#line 6888 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 280 "/home/fengyong/Desktop/p4c/ir/v1.def"
    IR::Attached * clone_rename(char const * ext) const;
#line 6891 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 284 "/home/fengyong/Desktop/p4c/ir/v1.def"
    void dbprint(std::ostream & out) const override;
#line 6894 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 285 "/home/fengyong/Desktop/p4c/ir/v1.def"
    cstring toString() const override;
#line 6897 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Attached const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "Attached"; }
    static cstring static_type_name() { return "Attached"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Attached(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
 protected:
    Attached(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations);
    Attached(IR::ID name, const IR::Annotations* annotations);
    Attached(Util::SourceInfo srcInfo, const IR::Annotations* annotations);
    Attached(const IR::Annotations* annotations);
    Attached(Util::SourceInfo srcInfo, IR::ID name);
    Attached(IR::ID name);
    Attached(Util::SourceInfo srcInfo);
    Attached();
    IRNODE_ABSTRACT_SUBCLASS(Attached)
};
}  // namespace IR
namespace IR {
class Stateful : public Attached {
 public:
    IR::ID table = {};
    bool direct = false;
    bool saturating = false;
    int instance_count = -1;
#line 293 "/home/fengyong/Desktop/p4c/ir/v1.def"
    virtual bool indexed() const override;
#line 6930 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 294 "/home/fengyong/Desktop/p4c/ir/v1.def"
    int index_width() const;
#line 6933 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"

    bool operator==(IR::Stateful const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Stateful"; }
    static cstring static_type_name() { return "Stateful"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Stateful(JSONLoader & json);
    bool operator==(IR::Attached const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
 protected:
    Stateful(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations);
    Stateful(IR::ID name, const IR::Annotations* annotations);
    Stateful(Util::SourceInfo srcInfo, const IR::Annotations* annotations);
    Stateful(const IR::Annotations* annotations);
    Stateful(Util::SourceInfo srcInfo, IR::ID name);
    Stateful(IR::ID name);
    Stateful(Util::SourceInfo srcInfo);
    Stateful();
    IRNODE_ABSTRACT_SUBCLASS(Stateful)
};
}  // namespace IR
namespace IR {
class CounterOrMeter : public Stateful {
 public:
    CounterType type = CounterType::NONE;
#line 299 "/home/fengyong/Desktop/p4c/ir/v1.def"
    void settype(cstring t);
#line 6962 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"

    bool operator==(IR::CounterOrMeter const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "CounterOrMeter"; }
    static cstring static_type_name() { return "CounterOrMeter"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    CounterOrMeter(JSONLoader & json);
    bool operator==(IR::Stateful const & a) const override { return a == *this; }
    bool operator==(IR::Attached const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
 protected:
    CounterOrMeter(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations);
    CounterOrMeter(IR::ID name, const IR::Annotations* annotations);
    CounterOrMeter(Util::SourceInfo srcInfo, const IR::Annotations* annotations);
    CounterOrMeter(const IR::Annotations* annotations);
    CounterOrMeter(Util::SourceInfo srcInfo, IR::ID name);
    CounterOrMeter(IR::ID name);
    CounterOrMeter(Util::SourceInfo srcInfo);
    CounterOrMeter();
    IRNODE_ABSTRACT_SUBCLASS(CounterOrMeter)
};
}  // namespace IR
namespace IR {
class Counter : public CounterOrMeter {
 public:
    int max_width = -1;
    int min_width = -1;
#line 310 "/home/fengyong/Desktop/p4c/ir/v1.def"
    char const * kind() const override;
#line 6993 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 311 "/home/fengyong/Desktop/p4c/ir/v1.def"
    IR::Type const * getType() const override;
#line 6996 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Counter const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Counter"; }
    static cstring static_type_name() { return "Counter"; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Counter(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::CounterOrMeter const & a) const override { return a == *this; }
    bool operator==(IR::Stateful const & a) const override { return a == *this; }
    bool operator==(IR::Attached const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Counter(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations);
    Counter(IR::ID name, const IR::Annotations* annotations);
    Counter(Util::SourceInfo srcInfo, const IR::Annotations* annotations);
    Counter(const IR::Annotations* annotations);
    Counter(Util::SourceInfo srcInfo, IR::ID name);
    Counter(IR::ID name);
    Counter(Util::SourceInfo srcInfo);
    Counter();
    IRNODE_SUBCLASS(Counter)
};
}  // namespace IR
namespace IR {
class Meter : public CounterOrMeter {
 public:
    const IR::Expression* result = nullptr;
    const IR::Expression* pre_color = nullptr;
    IR::ID implementation = {};
#line 318 "/home/fengyong/Desktop/p4c/ir/v1.def"
    char const * kind() const override;
#line 7029 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 319 "/home/fengyong/Desktop/p4c/ir/v1.def"
    const IR::Type *getType() const override;
#line 7032 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Meter const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "Meter"; }
    static cstring static_type_name() { return "Meter"; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Meter(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::CounterOrMeter const & a) const override { return a == *this; }
    bool operator==(IR::Stateful const & a) const override { return a == *this; }
    bool operator==(IR::Attached const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Meter(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations);
    Meter(IR::ID name, const IR::Annotations* annotations);
    Meter(Util::SourceInfo srcInfo, const IR::Annotations* annotations);
    Meter(const IR::Annotations* annotations);
    Meter(Util::SourceInfo srcInfo, IR::ID name);
    Meter(IR::ID name);
    Meter(Util::SourceInfo srcInfo);
    Meter();
    IRNODE_SUBCLASS(Meter)
};
}  // namespace IR
namespace IR {
class Register : public Stateful {
 public:
    IR::ID layout = {};
    int width = -1;
    bool signed_ = false;

#line 327 "/home/fengyong/Desktop/p4c/ir/v1.def"
    char const * kind() const override;
#line 7068 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 328 "/home/fengyong/Desktop/p4c/ir/v1.def"
    const IR::Type *getType() const override;
#line 7071 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Register const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "Register"; }
    static cstring static_type_name() { return "Register"; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Register(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Stateful const & a) const override { return a == *this; }
    bool operator==(IR::Attached const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Register(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations);
    Register(IR::ID name, const IR::Annotations* annotations);
    Register(Util::SourceInfo srcInfo, const IR::Annotations* annotations);
    Register(const IR::Annotations* annotations);
    Register(Util::SourceInfo srcInfo, IR::ID name);
    Register(IR::ID name);
    Register(Util::SourceInfo srcInfo);
    Register();
    IRNODE_SUBCLASS(Register)
};
}  // namespace IR
namespace IR {
class PrimitiveAction : public Node {
 public:
    bool operator==(IR::PrimitiveAction const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "PrimitiveAction"; }
    static cstring static_type_name() { return "PrimitiveAction"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    PrimitiveAction(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    PrimitiveAction(Util::SourceInfo srcInfo);
    PrimitiveAction();
    IRNODE_SUBCLASS(PrimitiveAction)
};
}  // namespace IR
namespace IR {
class NameList : public Node {
 public:
    safe_vector<IR::ID> names = {};
#line 335 "/home/fengyong/Desktop/p4c/ir/v1.def"
    NameList(Util::SourceInfo si, cstring n);
#line 7118 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 336 "/home/fengyong/Desktop/p4c/ir/v1.def"
    NameList(Util::SourceInfo si, IR::ID n);
#line 7121 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 337 "/home/fengyong/Desktop/p4c/ir/v1.def"
    void dump_fields(std::ostream & out) const override;
#line 7124 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::NameList const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "NameList"; }
    static cstring static_type_name() { return "NameList"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    NameList(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    NameList(Util::SourceInfo srcInfo);
    NameList();
    IRNODE_SUBCLASS(NameList)
};
}  // namespace IR
namespace IR {
class ActionArg : public Expression {
 public:
    cstring action_name;
    IR::ID name;
    bool read = false;
    bool write = false;
#line 346 "/home/fengyong/Desktop/p4c/ir/v1.def"
    void dbprint(std::ostream & out) const override;
#line 7148 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 347 "/home/fengyong/Desktop/p4c/ir/v1.def"
    cstring toString() const override;
#line 7151 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ActionArg const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "ActionArg"; }
    static cstring static_type_name() { return "ActionArg"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ActionArg(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    ActionArg(Util::SourceInfo srcInfo, const IR::Type* type, cstring action_name, IR::ID name);
    ActionArg(const IR::Type* type, cstring action_name, IR::ID name);
    ActionArg(Util::SourceInfo srcInfo, cstring action_name, IR::ID name);
    ActionArg(cstring action_name, IR::ID name);
    IRNODE_SUBCLASS(ActionArg)
};
}  // namespace IR
namespace IR {

class ActionFunction : public Node, public virtual IAnnotated {
 public:
    IR::ID name;
    IR::Vector<IR::Primitive> action = {};
    safe_vector<const IR::ActionArg *> args = {};
    const IR::Annotations* annotations = Annotations::empty;
#line 357 "/home/fengyong/Desktop/p4c/ir/v1.def"
    const IR::Annotations *getAnnotations() const override;
#line 7179 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 358 "/home/fengyong/Desktop/p4c/ir/v1.def"
    const IR::ActionArg *arg(cstring n) const;
#line 7182 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 363 "/home/fengyong/Desktop/p4c/ir/v1.def"
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
#line 7186 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 370 "/home/fengyong/Desktop/p4c/ir/v1.def"
    cstring toString() const override;
#line 7189 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ActionFunction const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void validate() const override;
    cstring node_type_name() const override { return "ActionFunction"; }
    static cstring static_type_name() { return "ActionFunction"; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ActionFunction(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    ActionFunction(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations);
    ActionFunction(IR::ID name, const IR::Annotations* annotations);
    ActionFunction(Util::SourceInfo srcInfo, const IR::Annotations* annotations);
    ActionFunction(const IR::Annotations* annotations);
    ActionFunction(Util::SourceInfo srcInfo, IR::ID name);
    ActionFunction(IR::ID name);
    ActionFunction(Util::SourceInfo srcInfo);
    ActionFunction();
    IRNODE_SUBCLASS(ActionFunction)
};
}  // namespace IR
namespace IR {
class ActionProfile : public Attached {
 public:
    IR::ID selector = {};
    safe_vector<IR::ID> actions = {};
    int size = 0;
#line 380 "/home/fengyong/Desktop/p4c/ir/v1.def"
    char const * kind() const override;
#line 7220 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 381 "/home/fengyong/Desktop/p4c/ir/v1.def"
    bool indexed() const override;
#line 7223 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ActionProfile const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "ActionProfile"; }
    static cstring static_type_name() { return "ActionProfile"; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ActionProfile(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Attached const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    ActionProfile(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations);
    ActionProfile(IR::ID name, const IR::Annotations* annotations);
    ActionProfile(Util::SourceInfo srcInfo, const IR::Annotations* annotations);
    ActionProfile(const IR::Annotations* annotations);
    ActionProfile(Util::SourceInfo srcInfo, IR::ID name);
    ActionProfile(IR::ID name);
    ActionProfile(Util::SourceInfo srcInfo);
    ActionProfile();
    IRNODE_SUBCLASS(ActionProfile)
};
}  // namespace IR
namespace IR {
class ActionSelector : public Attached {
 public:
    IR::ID key = {};
    const IR::FieldListCalculation* key_fields = nullptr;
    IR::ID mode = {};
    IR::ID type = {};
#line 389 "/home/fengyong/Desktop/p4c/ir/v1.def"
    char const * kind() const override;
#line 7255 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::ActionSelector const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "ActionSelector"; }
    static cstring static_type_name() { return "ActionSelector"; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    ActionSelector(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Attached const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    ActionSelector(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations);
    ActionSelector(IR::ID name, const IR::Annotations* annotations);
    ActionSelector(Util::SourceInfo srcInfo, const IR::Annotations* annotations);
    ActionSelector(const IR::Annotations* annotations);
    ActionSelector(Util::SourceInfo srcInfo, IR::ID name);
    ActionSelector(IR::ID name);
    ActionSelector(Util::SourceInfo srcInfo);
    ActionSelector();
    IRNODE_SUBCLASS(ActionSelector)
};
}  // namespace IR
namespace IR {
class V1Table : public Node, public virtual IInstance, public virtual IAnnotated {
 public:
    IR::ID name;
    const IR::Vector<IR::Expression>* reads = 0;
    safe_vector<IR::ID> reads_types = {};
    int min_size = 0;
    int max_size = 0;
    int size = 0;
    IR::ID action_profile = {};
    safe_vector<IR::ID> actions = {};
    IR::ID default_action = {};
    bool default_action_is_const = false;
    const IR::Vector<IR::Expression>* default_action_args = 0;
    IR::TableProperties properties = {};

    const IR::Annotations* annotations = Annotations::empty;
#line 407 "/home/fengyong/Desktop/p4c/ir/v1.def"
    void addProperty(const IR::Property* prop);
#line 7299 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 408 "/home/fengyong/Desktop/p4c/ir/v1.def"
    const IR::Annotations *getAnnotations() const override;
#line 7302 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 409 "/home/fengyong/Desktop/p4c/ir/v1.def"
    cstring toString() const override;
#line 7305 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 410 "/home/fengyong/Desktop/p4c/ir/v1.def"
    IR::ID Name() const override;
#line 7308 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 411 "/home/fengyong/Desktop/p4c/ir/v1.def"
    const IR::Type *getType() const override;
#line 7311 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::V1Table const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "V1Table"; }
    static cstring static_type_name() { return "V1Table"; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    V1Table(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    V1Table(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations);
    V1Table(IR::ID name, const IR::Annotations* annotations);
    V1Table(Util::SourceInfo srcInfo, const IR::Annotations* annotations);
    V1Table(const IR::Annotations* annotations);
    V1Table(Util::SourceInfo srcInfo, IR::ID name);
    V1Table(IR::ID name);
    V1Table(Util::SourceInfo srcInfo);
    V1Table();
    IRNODE_SUBCLASS(V1Table)
};
}  // namespace IR
namespace IR {
class V1Control : public Node, public virtual IAnnotated {
 public:
    IR::ID name;
    const IR::Vector<IR::Expression>* code = nullptr;
    const IR::Annotations* annotations = nullptr;
#line 419 "/home/fengyong/Desktop/p4c/ir/v1.def"
    V1Control(IR::ID n);
#line 7344 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 420 "/home/fengyong/Desktop/p4c/ir/v1.def"
    V1Control(Util::SourceInfo si, IR::ID n);
#line 7347 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    IRNODE_DECLARE_APPLY_OVERLOAD(V1Control)
#line 422 "/home/fengyong/Desktop/p4c/ir/v1.def"
    const IR::Annotations *getAnnotations() const override;
#line 7351 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 423 "/home/fengyong/Desktop/p4c/ir/v1.def"
    cstring toString() const override;
#line 7354 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::V1Control const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "V1Control"; }
    static cstring static_type_name() { return "V1Control"; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    V1Control(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    V1Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Vector<IR::Expression>* code, const IR::Annotations* annotations);
    V1Control(IR::ID name, const IR::Vector<IR::Expression>* code, const IR::Annotations* annotations);
    IRNODE_SUBCLASS(V1Control)
};
}  // namespace IR
namespace IR {
class AttribLocal : public Expression, public virtual IDeclaration {
 public:
    IR::ID name;
#line 428 "/home/fengyong/Desktop/p4c/ir/v1.def"
    IR::ID getName() const override;
#line 7379 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 429 "/home/fengyong/Desktop/p4c/ir/v1.def"
    void dbprint(std::ostream & out) const override;
#line 7382 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::AttribLocal const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "AttribLocal"; }
    static cstring static_type_name() { return "AttribLocal"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    AttribLocal(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    AttribLocal(Util::SourceInfo srcInfo, const IR::Type* type, IR::ID name);
    AttribLocal(const IR::Type* type, IR::ID name);
    AttribLocal(Util::SourceInfo srcInfo, IR::ID name);
    AttribLocal(IR::ID name);
    IRNODE_SUBCLASS(AttribLocal)
};
}  // namespace IR
namespace IR {
class AttribLocals : public Node, public virtual ISimpleNamespace {
 public:
    IR::NameMap<IR::AttribLocal> locals = {};
#line 435 "/home/fengyong/Desktop/p4c/ir/v1.def"
    Util::Enumerator<const IR::IDeclaration *> * getDeclarations() const override;
#line 7406 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 437 "/home/fengyong/Desktop/p4c/ir/v1.def"
    const IR::IDeclaration *getDeclByName(cstring name) const override;
#line 7409 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::AttribLocals const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "AttribLocals"; }
    static cstring static_type_name() { return "AttribLocals"; }
    void toJSON(JSONGenerator & json) const override;
    AttribLocals(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    AttribLocals(Util::SourceInfo srcInfo);
    AttribLocals();
    IRNODE_SUBCLASS(AttribLocals)
};
}  // namespace IR
namespace IR {
class Attribute : public Declaration {
 public:
    const IR::Type* type = nullptr;
    const IR::AttribLocals* locals = nullptr;
    bool optional = false;
#line 444 "/home/fengyong/Desktop/p4c/ir/v1.def"
    void dbprint(std::ostream & out) const override;
#line 7434 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::Attribute const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "Attribute"; }
    static cstring static_type_name() { return "Attribute"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    Attribute(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration const & a) const override { return a == *this; }
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    Attribute(Util::SourceInfo srcInfo, IR::ID name);
    Attribute(IR::ID name);
    IRNODE_SUBCLASS(Attribute)
};
}  // namespace IR
namespace IR {
class GlobalRef : public Expression {
 public:
    const IR::Node* obj = nullptr;


#line 451 "/home/fengyong/Desktop/p4c/ir/v1.def"
    void validate() const override;
#line 7461 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 452 "/home/fengyong/Desktop/p4c/ir/v1.def"
    cstring toString() const override;
#line 7464 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 453 "/home/fengyong/Desktop/p4c/ir/v1.def"
    IR::ID Name() const;
#line 7467 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 454 "/home/fengyong/Desktop/p4c/ir/v1.def"
    void dbprint(std::ostream & out) const override;
#line 7470 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::GlobalRef const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "GlobalRef"; }
    static cstring static_type_name() { return "GlobalRef"; }
    void toJSON(JSONGenerator & json) const override;
    GlobalRef(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    GlobalRef(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Node* obj);
    GlobalRef(const IR::Type* type, const IR::Node* obj);
    GlobalRef(Util::SourceInfo srcInfo, const IR::Node* obj);
    GlobalRef(const IR::Node* obj);
    IRNODE_SUBCLASS(GlobalRef)
};
}  // namespace IR
namespace IR {
class AttributeRef : public Expression {
 public:
    cstring extern_name;
    const IR::Type_Extern* extern_type = nullptr;
    const IR::Attribute* attrib = nullptr;
#line 462 "/home/fengyong/Desktop/p4c/ir/v1.def"
    cstring toString() const override;
#line 7497 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 463 "/home/fengyong/Desktop/p4c/ir/v1.def"
    void dbprint(std::ostream & out) const override;
#line 7500 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::AttributeRef const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "AttributeRef"; }
    static cstring static_type_name() { return "AttributeRef"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    AttributeRef(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    AttributeRef(Util::SourceInfo srcInfo, const IR::Type* type, cstring extern_name, const IR::Type_Extern* extern_type, const IR::Attribute* attrib);
    AttributeRef(const IR::Type* type, cstring extern_name, const IR::Type_Extern* extern_type, const IR::Attribute* attrib);
    AttributeRef(Util::SourceInfo srcInfo, cstring extern_name, const IR::Type_Extern* extern_type, const IR::Attribute* attrib);
    AttributeRef(cstring extern_name, const IR::Type_Extern* extern_type, const IR::Attribute* attrib);
    IRNODE_SUBCLASS(AttributeRef)
};
}  // namespace IR
namespace IR {
class V1Program : public Node {
 public:
    IR::NameMap<IR::Node, std::multimap> scope;
#line 470 "/home/fengyong/Desktop/p4c/ir/v1.def"
    explicit V1Program();
#line 7527 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 472 "/home/fengyong/Desktop/p4c/ir/v1.def"
    template<class T> const T *get(cstring name) const { return scope.get<T>(name); }
#line 7530 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 474 "/home/fengyong/Desktop/p4c/ir/v1.def"
    void add(cstring name, IR::Node const * n);
#line 7533 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    IRNODE_DECLARE_APPLY_OVERLOAD(V1Program)
    bool operator==(IR::V1Program const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "V1Program"; }
    static cstring static_type_name() { return "V1Program"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    V1Program(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_SUBCLASS(V1Program)
};
}  // namespace IR
namespace IR {
/** @} */
/* end group irdefs */
class v1HeaderType : public Node {
 public:
    IR::ID name;
    const IR::Type_Struct* as_metadata = nullptr;
    const IR::Type_Header* as_header = nullptr;
#line 7 "/home/fengyong/Desktop/p4c/frontends/p4-14/ir-v1.def"
    v1HeaderType(IR::Type_Struct const * m, IR::Type_Header const * h = nullptr);
#line 7560 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 9 "/home/fengyong/Desktop/p4c/frontends/p4-14/ir-v1.def"
    void dbprint(std::ostream & out) const override;
#line 7563 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::v1HeaderType const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "v1HeaderType"; }
    static cstring static_type_name() { return "v1HeaderType"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    v1HeaderType(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    v1HeaderType(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Struct* as_metadata, const IR::Type_Header* as_header);
    v1HeaderType(IR::ID name, const IR::Type_Struct* as_metadata, const IR::Type_Header* as_header);
    IRNODE_SUBCLASS(v1HeaderType)
};
}  // namespace IR
namespace IR {

class IntMod : public Operation_Unary {
 public:
    unsigned width;
    cstring getStringOp() const override { return "><"; }
    int getPrecedence() const override { return DBPrint::Prec_Low; }
    bool operator==(IR::IntMod const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "IntMod"; }
    static cstring static_type_name() { return "IntMod"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    IntMod(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Operation_Unary const & a) const override { return a == *this; }
    bool operator==(IR::Operation const & a) const override { return a == *this; }
    bool operator==(IR::Expression const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IntMod(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr, unsigned width);
    IntMod(const IR::Type* type, const IR::Expression* expr, unsigned width);
    IntMod(Util::SourceInfo srcInfo, const IR::Expression* expr, unsigned width);
    IntMod(const IR::Expression* expr, unsigned width);
    IRNODE_SUBCLASS(IntMod)
};
}  // namespace IR
namespace IR {
class IDPDKNode : public virtual INode {
 public:
#line 2 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    virtual std::ostream & toSpec(std::ostream & out) const = 0;
#line 7612 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
};
}  // namespace IR
namespace IR {
class DpdkDeclaration : public Node, public virtual IDPDKNode {
 public:
    const IR::Declaration* global = nullptr;
#line 7 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 7621 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkDeclaration const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkDeclaration"; }
    static cstring static_type_name() { return "DpdkDeclaration"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkDeclaration(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkDeclaration(Util::SourceInfo srcInfo, const IR::Declaration* global);
    DpdkDeclaration(const IR::Declaration* global);
    IRNODE_SUBCLASS(DpdkDeclaration)
};
}  // namespace IR
namespace IR {
class DpdkExternDeclaration : public Declaration_Instance, public virtual IDPDKNode {
 public:
#line 12 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 7643 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkExternDeclaration const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkExternDeclaration"; }
    static cstring static_type_name() { return "DpdkExternDeclaration"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkExternDeclaration(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Declaration_Instance const & a) const override { return a == *this; }
    bool operator==(IR::Declaration const & a) const override { return a == *this; }
    bool operator==(IR::StatOrDecl const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkExternDeclaration(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer);
    DpdkExternDeclaration(IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer);
    DpdkExternDeclaration(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer);
    DpdkExternDeclaration(IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer);
    DpdkExternDeclaration(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments);
    DpdkExternDeclaration(IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments);
    DpdkExternDeclaration(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments);
    DpdkExternDeclaration(IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments);
    IRNODE_SUBCLASS(DpdkExternDeclaration)
};
}  // namespace IR
namespace IR {
class DpdkHeaderType : public Type_Header, public virtual IDPDKNode {
 public:
#line 17 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 7671 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkHeaderType const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkHeaderType"; }
    static cstring static_type_name() { return "DpdkHeaderType"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkHeaderType(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Header const & a) const override { return a == *this; }
    bool operator==(IR::Type_StructLike const & a) const override { return a == *this; }
    bool operator==(IR::Type_Declaration const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    DpdkHeaderType(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    DpdkHeaderType(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields);
    DpdkHeaderType(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields);
    DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields);
    DpdkHeaderType(IR::ID name, IR::IndexedVector<IR::StructField> fields);
    DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters);
    DpdkHeaderType(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters);
    DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters);
    DpdkHeaderType(IR::ID name, const IR::TypeParameters* typeParameters);
    DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations);
    DpdkHeaderType(IR::ID name, const IR::Annotations* annotations);
    DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name);
    DpdkHeaderType(IR::ID name);
    IRNODE_SUBCLASS(DpdkHeaderType)
};
}  // namespace IR
namespace IR {
class DpdkStructType : public Type_Struct, public virtual IDPDKNode {
 public:
#line 22 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 7708 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkStructType const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkStructType"; }
    static cstring static_type_name() { return "DpdkStructType"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkStructType(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Type_Struct const & a) const override { return a == *this; }
    bool operator==(IR::Type_StructLike const & a) const override { return a == *this; }
    bool operator==(IR::Type_Declaration const & a) const override { return a == *this; }
    bool operator==(IR::Type const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    DpdkStructType(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    DpdkStructType(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields);
    DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields);
    DpdkStructType(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields);
    DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields);
    DpdkStructType(IR::ID name, IR::IndexedVector<IR::StructField> fields);
    DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters);
    DpdkStructType(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters);
    DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters);
    DpdkStructType(IR::ID name, const IR::TypeParameters* typeParameters);
    DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations);
    DpdkStructType(IR::ID name, const IR::Annotations* annotations);
    DpdkStructType(Util::SourceInfo srcInfo, IR::ID name);
    DpdkStructType(IR::ID name);
    IRNODE_SUBCLASS(DpdkStructType)
};
}  // namespace IR
namespace IR {
class DpdkAsmStatement : public Node, public virtual IDPDKNode {
 public:
#line 27 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 7745 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkAsmStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkAsmStatement"; }
    static cstring static_type_name() { return "DpdkAsmStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkAsmStatement(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
 protected:
    DpdkAsmStatement(Util::SourceInfo srcInfo);
    DpdkAsmStatement();
    IRNODE_ABSTRACT_SUBCLASS(DpdkAsmStatement)
};
}  // namespace IR
namespace IR {
class DpdkAction : public Node {
 public:
    const IR::Annotations* annotations = Annotations::empty;
    IR::IndexedVector<IR::DpdkAsmStatement> statements;
    IR::ID name;
    IR::ParameterList para;
#line 35 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const;
#line 7768 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkAction const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkAction"; }
    static cstring static_type_name() { return "DpdkAction"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkAction(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkAction(Util::SourceInfo srcInfo, const IR::Annotations* annotations, IR::IndexedVector<IR::DpdkAsmStatement> statements, IR::ID name, IR::ParameterList para);
    DpdkAction(const IR::Annotations* annotations, IR::IndexedVector<IR::DpdkAsmStatement> statements, IR::ID name, IR::ParameterList para);
    DpdkAction(Util::SourceInfo srcInfo, IR::IndexedVector<IR::DpdkAsmStatement> statements, IR::ID name, IR::ParameterList para);
    DpdkAction(IR::IndexedVector<IR::DpdkAsmStatement> statements, IR::ID name, IR::ParameterList para);
    IRNODE_SUBCLASS(DpdkAction)
};
}  // namespace IR
namespace IR {
class DpdkTable : public Node {
 public:
    cstring name;
    const IR::Key* match_keys = nullptr;
    const IR::ActionList* actions = nullptr;
    const IR::Expression* default_action = nullptr;
    const IR::TableProperties* properties = nullptr;
    IR::ParameterList default_action_paraList;
#line 46 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    const IR::Key *getKey() const;
#line 7799 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 54 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    const IR::EntriesList *getEntries() const;
#line 7802 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 64 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const;
#line 7805 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkTable const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "DpdkTable"; }
    static cstring static_type_name() { return "DpdkTable"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkTable(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkTable(Util::SourceInfo srcInfo, cstring name, const IR::Key* match_keys, const IR::ActionList* actions, const IR::Expression* default_action, const IR::TableProperties* properties, IR::ParameterList default_action_paraList);
    DpdkTable(cstring name, const IR::Key* match_keys, const IR::ActionList* actions, const IR::Expression* default_action, const IR::TableProperties* properties, IR::ParameterList default_action_paraList);
    IRNODE_SUBCLASS(DpdkTable)
};
}  // namespace IR
namespace IR {
class DpdkSelector : public Node {
 public:
    cstring name;
    const IR::Expression* group_id = nullptr;
    const IR::Expression* member_id = nullptr;
    const IR::Key* selectors = nullptr;
    int n_groups_max;
    int n_members_per_group_max;
#line 77 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const;
#line 7833 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkSelector const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "DpdkSelector"; }
    static cstring static_type_name() { return "DpdkSelector"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkSelector(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkSelector(Util::SourceInfo srcInfo, cstring name, const IR::Expression* group_id, const IR::Expression* member_id, const IR::Key* selectors, int n_groups_max, int n_members_per_group_max);
    DpdkSelector(cstring name, const IR::Expression* group_id, const IR::Expression* member_id, const IR::Key* selectors, int n_groups_max, int n_members_per_group_max);
    IRNODE_SUBCLASS(DpdkSelector)
};
}  // namespace IR
namespace IR {

class DpdkLearner : public Node {
 public:
    cstring name;
    const IR::Key* match_keys = nullptr;
    const IR::ActionList* actions = nullptr;
    const IR::Expression* default_action = nullptr;
    const IR::TableProperties* properties = nullptr;
#line 93 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const;
#line 7861 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkLearner const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "DpdkLearner"; }
    static cstring static_type_name() { return "DpdkLearner"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkLearner(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkLearner(Util::SourceInfo srcInfo, cstring name, const IR::Key* match_keys, const IR::ActionList* actions, const IR::Expression* default_action, const IR::TableProperties* properties);
    DpdkLearner(cstring name, const IR::Key* match_keys, const IR::ActionList* actions, const IR::Expression* default_action, const IR::TableProperties* properties);
    IRNODE_SUBCLASS(DpdkLearner)
};
}  // namespace IR
namespace IR {

class DpdkAsmProgram : public Node {
 public:
    IR::IndexedVector<IR::DpdkHeaderType> headerType;
    IR::IndexedVector<IR::DpdkStructType> structType;
    IR::IndexedVector<IR::DpdkExternDeclaration> externDeclarations;
    IR::IndexedVector<IR::DpdkAction> actions;
    IR::IndexedVector<IR::DpdkTable> tables;
    IR::IndexedVector<IR::DpdkSelector> selectors;
    IR::IndexedVector<IR::DpdkLearner> learners;
    IR::IndexedVector<IR::DpdkAsmStatement> statements;
    IR::IndexedVector<IR::DpdkDeclaration> globals;
#line 109 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const;
#line 7893 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkAsmProgram const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkAsmProgram"; }
    static cstring static_type_name() { return "DpdkAsmProgram"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkAsmProgram(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkAsmProgram(Util::SourceInfo srcInfo, IR::IndexedVector<IR::DpdkHeaderType> headerType, IR::IndexedVector<IR::DpdkStructType> structType, IR::IndexedVector<IR::DpdkExternDeclaration> externDeclarations, IR::IndexedVector<IR::DpdkAction> actions, IR::IndexedVector<IR::DpdkTable> tables, IR::IndexedVector<IR::DpdkSelector> selectors, IR::IndexedVector<IR::DpdkLearner> learners, IR::IndexedVector<IR::DpdkAsmStatement> statements, IR::IndexedVector<IR::DpdkDeclaration> globals);
    DpdkAsmProgram(IR::IndexedVector<IR::DpdkHeaderType> headerType, IR::IndexedVector<IR::DpdkStructType> structType, IR::IndexedVector<IR::DpdkExternDeclaration> externDeclarations, IR::IndexedVector<IR::DpdkAction> actions, IR::IndexedVector<IR::DpdkTable> tables, IR::IndexedVector<IR::DpdkSelector> selectors, IR::IndexedVector<IR::DpdkLearner> learners, IR::IndexedVector<IR::DpdkAsmStatement> statements, IR::IndexedVector<IR::DpdkDeclaration> globals);
    IRNODE_SUBCLASS(DpdkAsmProgram)
};
}  // namespace IR
namespace IR {
class DpdkListStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    IR::IndexedVector<IR::DpdkAsmStatement> statements;
#line 114 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 7917 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkListStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkListStatement"; }
    static cstring static_type_name() { return "DpdkListStatement"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkListStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkListStatement(Util::SourceInfo srcInfo, IR::IndexedVector<IR::DpdkAsmStatement> statements);
    DpdkListStatement(IR::IndexedVector<IR::DpdkAsmStatement> statements);
    DpdkListStatement(Util::SourceInfo srcInfo);
    DpdkListStatement();
    IRNODE_SUBCLASS(DpdkListStatement)
};
}  // namespace IR
namespace IR {
class DpdkApplyStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    cstring table;
#line 119 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 7944 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkApplyStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkApplyStatement"; }
    static cstring static_type_name() { return "DpdkApplyStatement"; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkApplyStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkApplyStatement(Util::SourceInfo srcInfo, cstring table);
    DpdkApplyStatement(cstring table);
    IRNODE_SUBCLASS(DpdkApplyStatement)
};
}  // namespace IR
namespace IR {
class DpdkLearnStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    IR::ID action;
    const IR::Expression* timeout = nullptr;
    const IR::Expression* argument = nullptr;
#line 126 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 7969 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkLearnStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkLearnStatement"; }
    static cstring static_type_name() { return "DpdkLearnStatement"; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkLearnStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkLearnStatement(Util::SourceInfo srcInfo, IR::ID action, const IR::Expression* timeout, const IR::Expression* argument);
    DpdkLearnStatement(IR::ID action, const IR::Expression* timeout, const IR::Expression* argument);
    DpdkLearnStatement(Util::SourceInfo srcInfo, IR::ID action, const IR::Expression* timeout);
    DpdkLearnStatement(IR::ID action, const IR::Expression* timeout);
    IRNODE_SUBCLASS(DpdkLearnStatement)
};
}  // namespace IR
namespace IR {
class DpdkMirrorStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* slotId = nullptr;
    const IR::Expression* sessionId = nullptr;
#line 132 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 7998 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkMirrorStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkMirrorStatement"; }
    static cstring static_type_name() { return "DpdkMirrorStatement"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkMirrorStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkMirrorStatement(Util::SourceInfo srcInfo, const IR::Expression* slotId, const IR::Expression* sessionId);
    DpdkMirrorStatement(const IR::Expression* slotId, const IR::Expression* sessionId);
    IRNODE_SUBCLASS(DpdkMirrorStatement)
};
}  // namespace IR
namespace IR {
class DpdkEmitStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* header = nullptr;
#line 137 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 8023 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkEmitStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkEmitStatement"; }
    static cstring static_type_name() { return "DpdkEmitStatement"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkEmitStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkEmitStatement(Util::SourceInfo srcInfo, const IR::Expression* header);
    DpdkEmitStatement(const IR::Expression* header);
    IRNODE_SUBCLASS(DpdkEmitStatement)
};
}  // namespace IR
namespace IR {
class DpdkExtractStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* header = nullptr;
    const IR::Expression* length = nullptr;
#line 143 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 8049 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkExtractStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkExtractStatement"; }
    static cstring static_type_name() { return "DpdkExtractStatement"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkExtractStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkExtractStatement(Util::SourceInfo srcInfo, const IR::Expression* header, const IR::Expression* length);
    DpdkExtractStatement(const IR::Expression* header, const IR::Expression* length);
    DpdkExtractStatement(Util::SourceInfo srcInfo, const IR::Expression* header);
    DpdkExtractStatement(const IR::Expression* header);
    IRNODE_SUBCLASS(DpdkExtractStatement)
};
}  // namespace IR
namespace IR {
class DpdkLookaheadStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* header = nullptr;
#line 148 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 8076 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkLookaheadStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkLookaheadStatement"; }
    static cstring static_type_name() { return "DpdkLookaheadStatement"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkLookaheadStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkLookaheadStatement(Util::SourceInfo srcInfo, const IR::Expression* header);
    DpdkLookaheadStatement(const IR::Expression* header);
    IRNODE_SUBCLASS(DpdkLookaheadStatement)
};
}  // namespace IR
namespace IR {
class DpdkJmpStatement : public DpdkAsmStatement {
 public:
    cstring instruction;
    cstring label;
#line 154 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 8102 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 156 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkJmpStatement(cstring instruction, cstring l);
#line 8105 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpStatement"; }
    static cstring static_type_name() { return "DpdkJmpStatement"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpStatement(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_ABSTRACT_SUBCLASS(DpdkJmpStatement)
};
}  // namespace IR
namespace IR {
class DpdkJmpLabelStatement : public DpdkJmpStatement {
 public:
#line 162 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkJmpLabelStatement(cstring label);
#line 8123 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpLabelStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpLabelStatement"; }
    static cstring static_type_name() { return "DpdkJmpLabelStatement"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpLabelStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkJmpStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_SUBCLASS(DpdkJmpLabelStatement)
};
}  // namespace IR
namespace IR {
class DpdkJmpHitStatement : public DpdkJmpStatement {
 public:
#line 169 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkJmpHitStatement(cstring label);
#line 8143 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpHitStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpHitStatement"; }
    static cstring static_type_name() { return "DpdkJmpHitStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpHitStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkJmpStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_SUBCLASS(DpdkJmpHitStatement)
};
}  // namespace IR
namespace IR {
class DpdkJmpMissStatement : public DpdkJmpStatement {
 public:
#line 176 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkJmpMissStatement(cstring label);
#line 8162 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpMissStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpMissStatement"; }
    static cstring static_type_name() { return "DpdkJmpMissStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpMissStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkJmpStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_SUBCLASS(DpdkJmpMissStatement)
};
}  // namespace IR
namespace IR {
class DpdkJmpActionStatement : public DpdkJmpStatement {
 public:
    IR::ID action;
#line 182 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 8182 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 185 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkJmpActionStatement(cstring instruction, cstring label, IR::ID action);
#line 8185 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpActionStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpActionStatement"; }
    static cstring static_type_name() { return "DpdkJmpActionStatement"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpActionStatement(JSONLoader & json);
    bool operator==(IR::DpdkJmpStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_ABSTRACT_SUBCLASS(DpdkJmpActionStatement)
};
}  // namespace IR
namespace IR {
class DpdkJmpIfActionRunStatement : public DpdkJmpActionStatement {
 public:
#line 192 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkJmpIfActionRunStatement(cstring label, cstring act);
#line 8204 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpIfActionRunStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpIfActionRunStatement"; }
    static cstring static_type_name() { return "DpdkJmpIfActionRunStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpIfActionRunStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkJmpActionStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkJmpStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_SUBCLASS(DpdkJmpIfActionRunStatement)
};
}  // namespace IR
namespace IR {
class DpdkJmpIfActionNotRunStatement : public DpdkJmpActionStatement {
 public:
#line 199 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkJmpIfActionNotRunStatement(cstring label, cstring act);
#line 8224 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpIfActionNotRunStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpIfActionNotRunStatement"; }
    static cstring static_type_name() { return "DpdkJmpIfActionNotRunStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpIfActionNotRunStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkJmpActionStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkJmpStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_SUBCLASS(DpdkJmpIfActionNotRunStatement)
};
}  // namespace IR
namespace IR {
class DpdkJmpHeaderStatement : public DpdkJmpStatement {
 public:
    const IR::Expression* header = nullptr;
#line 205 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 8245 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 207 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkJmpHeaderStatement(cstring instruction, cstring label, const IR::Expression* hdr);
#line 8248 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpHeaderStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkJmpHeaderStatement"; }
    static cstring static_type_name() { return "DpdkJmpHeaderStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpHeaderStatement(JSONLoader & json);
    bool operator==(IR::DpdkJmpStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_ABSTRACT_SUBCLASS(DpdkJmpHeaderStatement)
};
}  // namespace IR
namespace IR {
class DpdkJmpIfInvalidStatement : public DpdkJmpHeaderStatement {
 public:
#line 213 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkJmpIfInvalidStatement(cstring label, const IR::Expression* hdr);
#line 8269 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpIfInvalidStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpIfInvalidStatement"; }
    static cstring static_type_name() { return "DpdkJmpIfInvalidStatement"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpIfInvalidStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkJmpHeaderStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkJmpStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_SUBCLASS(DpdkJmpIfInvalidStatement)
};
}  // namespace IR
namespace IR {
class DpdkJmpIfValidStatement : public DpdkJmpHeaderStatement {
 public:
#line 220 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkJmpIfValidStatement(cstring label, const IR::Expression* hdr);
#line 8290 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpIfValidStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpIfValidStatement"; }
    static cstring static_type_name() { return "DpdkJmpIfValidStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpIfValidStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkJmpHeaderStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkJmpStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_SUBCLASS(DpdkJmpIfValidStatement)
};
}  // namespace IR
namespace IR {
class DpdkJmpCondStatement : public DpdkJmpStatement {
 public:
    const IR::Expression* src1 = nullptr;
    const IR::Expression* src2 = nullptr;
#line 227 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 8312 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 229 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkJmpCondStatement(cstring instruction, cstring label, const IR::Expression* src1, const IR::Expression* src2);
#line 8315 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpCondStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkJmpCondStatement"; }
    static cstring static_type_name() { return "DpdkJmpCondStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpCondStatement(JSONLoader & json);
    bool operator==(IR::DpdkJmpStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_ABSTRACT_SUBCLASS(DpdkJmpCondStatement)
};
}  // namespace IR
namespace IR {
class DpdkJmpEqualStatement : public DpdkJmpCondStatement, public virtual IDPDKNode {
 public:
#line 234 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkJmpEqualStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2);
#line 8336 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpEqualStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpEqualStatement"; }
    static cstring static_type_name() { return "DpdkJmpEqualStatement"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpEqualStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkJmpCondStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkJmpStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_SUBCLASS(DpdkJmpEqualStatement)
};
}  // namespace IR
namespace IR {
class DpdkJmpNotEqualStatement : public DpdkJmpCondStatement, public virtual IDPDKNode {
 public:
#line 241 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkJmpNotEqualStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2);
#line 8357 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpNotEqualStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpNotEqualStatement"; }
    static cstring static_type_name() { return "DpdkJmpNotEqualStatement"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpNotEqualStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkJmpCondStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkJmpStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_SUBCLASS(DpdkJmpNotEqualStatement)
};
}  // namespace IR
namespace IR {
class DpdkJmpGreaterEqualStatement : public DpdkJmpCondStatement, public virtual IDPDKNode {
 public:
#line 248 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkJmpGreaterEqualStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2);
#line 8378 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpGreaterEqualStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpGreaterEqualStatement"; }
    static cstring static_type_name() { return "DpdkJmpGreaterEqualStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpGreaterEqualStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkJmpCondStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkJmpStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_SUBCLASS(DpdkJmpGreaterEqualStatement)
};
}  // namespace IR
namespace IR {
class DpdkJmpGreaterStatement : public DpdkJmpCondStatement, public virtual IDPDKNode {
 public:
#line 255 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkJmpGreaterStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2);
#line 8398 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpGreaterStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpGreaterStatement"; }
    static cstring static_type_name() { return "DpdkJmpGreaterStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpGreaterStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkJmpCondStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkJmpStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_SUBCLASS(DpdkJmpGreaterStatement)
};
}  // namespace IR
namespace IR {
class DpdkJmpLessOrEqualStatement : public DpdkJmpCondStatement, public virtual IDPDKNode {
 public:
#line 262 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkJmpLessOrEqualStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2);
#line 8418 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpLessOrEqualStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpLessOrEqualStatement"; }
    static cstring static_type_name() { return "DpdkJmpLessOrEqualStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpLessOrEqualStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkJmpCondStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkJmpStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_SUBCLASS(DpdkJmpLessOrEqualStatement)
};
}  // namespace IR
namespace IR {
class DpdkJmpLessStatement : public DpdkJmpCondStatement, public virtual IDPDKNode {
 public:
#line 269 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkJmpLessStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2);
#line 8438 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkJmpLessStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkJmpLessStatement"; }
    static cstring static_type_name() { return "DpdkJmpLessStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkJmpLessStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkJmpCondStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkJmpStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_SUBCLASS(DpdkJmpLessStatement)
};
}  // namespace IR
namespace IR {
class DpdkRxStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* port = nullptr;
#line 275 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 8459 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkRxStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkRxStatement"; }
    static cstring static_type_name() { return "DpdkRxStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkRxStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkRxStatement(Util::SourceInfo srcInfo, const IR::Expression* port);
    DpdkRxStatement(const IR::Expression* port);
    IRNODE_SUBCLASS(DpdkRxStatement)
};
}  // namespace IR
namespace IR {
class DpdkTxStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* port = nullptr;
#line 281 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 8483 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkTxStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkTxStatement"; }
    static cstring static_type_name() { return "DpdkTxStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkTxStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkTxStatement(Util::SourceInfo srcInfo, const IR::Expression* port);
    DpdkTxStatement(const IR::Expression* port);
    IRNODE_SUBCLASS(DpdkTxStatement)
};
}  // namespace IR
namespace IR {
class DpdkAssignmentStatement : public DpdkAsmStatement {
 public:
    cstring instruction;
    const IR::Expression* dst = nullptr;
#line 289 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkAssignmentStatement(cstring instruction, const IR::Expression* dst);
#line 8508 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkAssignmentStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkAssignmentStatement"; }
    static cstring static_type_name() { return "DpdkAssignmentStatement"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkAssignmentStatement(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_ABSTRACT_SUBCLASS(DpdkAssignmentStatement)
};
}  // namespace IR
namespace IR {
class DpdkUnaryStatement : public DpdkAssignmentStatement {
 public:
    const IR::Expression* src = nullptr;
#line 295 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 8530 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 297 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkUnaryStatement(cstring instruction, const IR::Expression* dst, const IR::Expression* src);
#line 8533 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkUnaryStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkUnaryStatement"; }
    static cstring static_type_name() { return "DpdkUnaryStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkUnaryStatement(JSONLoader & json);
    bool operator==(IR::DpdkAssignmentStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_ABSTRACT_SUBCLASS(DpdkUnaryStatement)
};
}  // namespace IR
namespace IR {
class DpdkMovStatement : public DpdkUnaryStatement {
 public:
#line 302 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkMovStatement(const IR::Expression* dst, const IR::Expression* src);
#line 8554 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkMovStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkMovStatement"; }
    static cstring static_type_name() { return "DpdkMovStatement"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkMovStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkUnaryStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAssignmentStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_SUBCLASS(DpdkMovStatement)
};
}  // namespace IR
namespace IR {
class DpdkBinaryStatement : public DpdkAssignmentStatement {
 public:
    const IR::Expression* src1 = nullptr;
    const IR::Expression* src2 = nullptr;
#line 310 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 8577 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 312 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkBinaryStatement(cstring instruction, const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2);
#line 8580 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkBinaryStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkBinaryStatement"; }
    static cstring static_type_name() { return "DpdkBinaryStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkBinaryStatement(JSONLoader & json);
    bool operator==(IR::DpdkAssignmentStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_ABSTRACT_SUBCLASS(DpdkBinaryStatement)
};
}  // namespace IR
namespace IR {
class DpdkAddStatement : public DpdkBinaryStatement {
 public:
#line 319 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkAddStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2);
#line 8601 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkAddStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkAddStatement"; }
    static cstring static_type_name() { return "DpdkAddStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkAddStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkBinaryStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAssignmentStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_SUBCLASS(DpdkAddStatement)
};
}  // namespace IR
namespace IR {
class DpdkAndStatement : public DpdkBinaryStatement, public virtual IDPDKNode {
 public:
#line 326 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkAndStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2);
#line 8621 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkAndStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkAndStatement"; }
    static cstring static_type_name() { return "DpdkAndStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkAndStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkBinaryStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAssignmentStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_SUBCLASS(DpdkAndStatement)
};
}  // namespace IR
namespace IR {
class DpdkShlStatement : public DpdkBinaryStatement, public virtual IDPDKNode {
 public:
#line 333 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkShlStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2);
#line 8641 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkShlStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkShlStatement"; }
    static cstring static_type_name() { return "DpdkShlStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkShlStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkBinaryStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAssignmentStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_SUBCLASS(DpdkShlStatement)
};
}  // namespace IR
namespace IR {
class DpdkShrStatement : public DpdkBinaryStatement, public virtual IDPDKNode {
 public:
#line 340 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkShrStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2);
#line 8661 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkShrStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkShrStatement"; }
    static cstring static_type_name() { return "DpdkShrStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkShrStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkBinaryStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAssignmentStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_SUBCLASS(DpdkShrStatement)
};
}  // namespace IR
namespace IR {
class DpdkSubStatement : public DpdkBinaryStatement, public virtual IDPDKNode {
 public:
#line 347 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkSubStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2);
#line 8681 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkSubStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkSubStatement"; }
    static cstring static_type_name() { return "DpdkSubStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkSubStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkBinaryStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAssignmentStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_SUBCLASS(DpdkSubStatement)
};
}  // namespace IR
namespace IR {
class DpdkOrStatement : public DpdkBinaryStatement, public virtual IDPDKNode {
 public:
#line 354 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkOrStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2);
#line 8701 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkOrStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkOrStatement"; }
    static cstring static_type_name() { return "DpdkOrStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkOrStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkBinaryStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAssignmentStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_SUBCLASS(DpdkOrStatement)
};
}  // namespace IR
namespace IR {
class DpdkXorStatement : public DpdkBinaryStatement, public virtual IDPDKNode {
 public:
#line 361 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkXorStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2);
#line 8721 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkXorStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkXorStatement"; }
    static cstring static_type_name() { return "DpdkXorStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkXorStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkBinaryStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAssignmentStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_SUBCLASS(DpdkXorStatement)
};
}  // namespace IR
namespace IR {
class DpdkRecircidStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* pass = nullptr;
#line 367 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 8742 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkRecircidStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkRecircidStatement"; }
    static cstring static_type_name() { return "DpdkRecircidStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkRecircidStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkRecircidStatement(Util::SourceInfo srcInfo, const IR::Expression* pass);
    DpdkRecircidStatement(const IR::Expression* pass);
    IRNODE_SUBCLASS(DpdkRecircidStatement)
};
}  // namespace IR
namespace IR {
class DpdkReturnStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
#line 372 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 8765 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkReturnStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkReturnStatement"; }
    static cstring static_type_name() { return "DpdkReturnStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkReturnStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkReturnStatement(Util::SourceInfo srcInfo);
    DpdkReturnStatement();
    IRNODE_SUBCLASS(DpdkReturnStatement)
};
}  // namespace IR
namespace IR {
class DpdkRearmStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* timeout = nullptr;
#line 378 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 8786 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkRearmStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    cstring node_type_name() const override { return "DpdkRearmStatement"; }
    static cstring static_type_name() { return "DpdkRearmStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkRearmStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkRearmStatement(Util::SourceInfo srcInfo, const IR::Expression* timeout);
    DpdkRearmStatement(const IR::Expression* timeout);
    DpdkRearmStatement(Util::SourceInfo srcInfo);
    DpdkRearmStatement();
    IRNODE_SUBCLASS(DpdkRearmStatement)
};
}  // namespace IR
namespace IR {
class DpdkRecirculateStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
#line 383 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 8810 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkRecirculateStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkRecirculateStatement"; }
    static cstring static_type_name() { return "DpdkRecirculateStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkRecirculateStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkRecirculateStatement(Util::SourceInfo srcInfo);
    DpdkRecirculateStatement();
    IRNODE_SUBCLASS(DpdkRecirculateStatement)
};
}  // namespace IR
namespace IR {
class DpdkLabelStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    cstring label;
#line 389 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 8831 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 391 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkLabelStatement(cstring l);
#line 8834 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkLabelStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkLabelStatement"; }
    static cstring static_type_name() { return "DpdkLabelStatement"; }
    void dbprint(std::ostream & out) const override;
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkLabelStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_SUBCLASS(DpdkLabelStatement)
};
}  // namespace IR
namespace IR {
class DpdkChecksumAddStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    cstring csum;
    cstring intermediate_value;
    const IR::Expression* field = nullptr;
#line 398 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 8857 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkChecksumAddStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkChecksumAddStatement"; }
    static cstring static_type_name() { return "DpdkChecksumAddStatement"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkChecksumAddStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkChecksumAddStatement(Util::SourceInfo srcInfo, cstring csum, cstring intermediate_value, const IR::Expression* field);
    DpdkChecksumAddStatement(cstring csum, cstring intermediate_value, const IR::Expression* field);
    IRNODE_SUBCLASS(DpdkChecksumAddStatement)
};
}  // namespace IR
namespace IR {
class DpdkChecksumSubStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    cstring csum;
    cstring intermediate_value;
    const IR::Expression* field = nullptr;
#line 406 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 8884 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkChecksumSubStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkChecksumSubStatement"; }
    static cstring static_type_name() { return "DpdkChecksumSubStatement"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkChecksumSubStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkChecksumSubStatement(Util::SourceInfo srcInfo, cstring csum, cstring intermediate_value, const IR::Expression* field);
    DpdkChecksumSubStatement(cstring csum, cstring intermediate_value, const IR::Expression* field);
    IRNODE_SUBCLASS(DpdkChecksumSubStatement)
};
}  // namespace IR
namespace IR {
class DpdkChecksumClearStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    cstring csum;
    cstring intermediate_value;
#line 413 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 8910 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkChecksumClearStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkChecksumClearStatement"; }
    static cstring static_type_name() { return "DpdkChecksumClearStatement"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkChecksumClearStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkChecksumClearStatement(Util::SourceInfo srcInfo, cstring csum, cstring intermediate_value);
    DpdkChecksumClearStatement(cstring csum, cstring intermediate_value);
    IRNODE_SUBCLASS(DpdkChecksumClearStatement)
};
}  // namespace IR
namespace IR {
class DpdkHashDeclStatement : public DpdkAsmStatement {
 public:
    cstring hash;
#line 419 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 8932 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkHashDeclStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkHashDeclStatement"; }
    static cstring static_type_name() { return "DpdkHashDeclStatement"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkHashDeclStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkHashDeclStatement(Util::SourceInfo srcInfo, cstring hash);
    DpdkHashDeclStatement(cstring hash);
    IRNODE_SUBCLASS(DpdkHashDeclStatement)
};
}  // namespace IR
namespace IR {
class DpdkGetHashStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    cstring instr;
    cstring hash;
    const IR::Expression* fields = nullptr;
    const IR::Expression* dst = nullptr;
#line 429 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 8957 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkGetHashStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkGetHashStatement"; }
    static cstring static_type_name() { return "DpdkGetHashStatement"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkGetHashStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkGetHashStatement(Util::SourceInfo srcInfo, cstring instr, cstring hash, const IR::Expression* fields, const IR::Expression* dst);
    DpdkGetHashStatement(cstring instr, cstring hash, const IR::Expression* fields, const IR::Expression* dst);
    IRNODE_SUBCLASS(DpdkGetHashStatement)
};
}  // namespace IR
namespace IR {
class DpdkGetChecksumStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* dst = nullptr;
    cstring checksum;
    cstring intermediate_value;
#line 437 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 8984 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkGetChecksumStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkGetChecksumStatement"; }
    static cstring static_type_name() { return "DpdkGetChecksumStatement"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkGetChecksumStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkGetChecksumStatement(Util::SourceInfo srcInfo, const IR::Expression* dst, cstring checksum, cstring intermediate_value);
    DpdkGetChecksumStatement(const IR::Expression* dst, cstring checksum, cstring intermediate_value);
    IRNODE_SUBCLASS(DpdkGetChecksumStatement)
};
}  // namespace IR
namespace IR {
class DpdkCastStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* dst = nullptr;
    const IR::Expression* src = nullptr;
    const IR::Type* type = nullptr;
#line 445 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 9011 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkCastStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkCastStatement"; }
    static cstring static_type_name() { return "DpdkCastStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkCastStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkCastStatement(Util::SourceInfo srcInfo, const IR::Expression* dst, const IR::Expression* src, const IR::Type* type);
    DpdkCastStatement(const IR::Expression* dst, const IR::Expression* src, const IR::Type* type);
    IRNODE_SUBCLASS(DpdkCastStatement)
};
}  // namespace IR
namespace IR {
class DpdkVerifyStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* condition = nullptr;
    const IR::Expression* error = nullptr;
#line 452 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 9036 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkVerifyStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkVerifyStatement"; }
    static cstring static_type_name() { return "DpdkVerifyStatement"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkVerifyStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkVerifyStatement(Util::SourceInfo srcInfo, const IR::Expression* condition, const IR::Expression* error);
    DpdkVerifyStatement(const IR::Expression* condition, const IR::Expression* error);
    IRNODE_SUBCLASS(DpdkVerifyStatement)
};
}  // namespace IR
namespace IR {
class DpdkMeterDeclStatement : public DpdkAsmStatement {
 public:
    cstring meter;
    const IR::Expression* size = nullptr;
#line 459 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 9061 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkMeterDeclStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkMeterDeclStatement"; }
    static cstring static_type_name() { return "DpdkMeterDeclStatement"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkMeterDeclStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkMeterDeclStatement(Util::SourceInfo srcInfo, cstring meter, const IR::Expression* size);
    DpdkMeterDeclStatement(cstring meter, const IR::Expression* size);
    IRNODE_SUBCLASS(DpdkMeterDeclStatement)
};
}  // namespace IR
namespace IR {
class DpdkMeterExecuteStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    cstring meter;
    const IR::Expression* index = nullptr;
    const IR::Expression* length = nullptr;
    const IR::Expression* color_in = nullptr;
    const IR::Expression* color_out = nullptr;
#line 469 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 9090 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkMeterExecuteStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkMeterExecuteStatement"; }
    static cstring static_type_name() { return "DpdkMeterExecuteStatement"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkMeterExecuteStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkMeterExecuteStatement(Util::SourceInfo srcInfo, cstring meter, const IR::Expression* index, const IR::Expression* length, const IR::Expression* color_in, const IR::Expression* color_out);
    DpdkMeterExecuteStatement(cstring meter, const IR::Expression* index, const IR::Expression* length, const IR::Expression* color_in, const IR::Expression* color_out);
    IRNODE_SUBCLASS(DpdkMeterExecuteStatement)
};
}  // namespace IR
namespace IR {
class DpdkGetTableEntryIndex : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* index = nullptr;
#line 475 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 9115 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkGetTableEntryIndex const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkGetTableEntryIndex"; }
    static cstring static_type_name() { return "DpdkGetTableEntryIndex"; }
    void toJSON(JSONGenerator & json) const override;
    DpdkGetTableEntryIndex(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkGetTableEntryIndex(Util::SourceInfo srcInfo, const IR::Expression* index);
    DpdkGetTableEntryIndex(const IR::Expression* index);
    IRNODE_SUBCLASS(DpdkGetTableEntryIndex)
};
}  // namespace IR
namespace IR {
class DpdkCounterCountStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    cstring counter;
    const IR::Expression* index = nullptr;
    const IR::Expression* incr = nullptr;
#line 483 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 9141 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkCounterCountStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkCounterCountStatement"; }
    static cstring static_type_name() { return "DpdkCounterCountStatement"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkCounterCountStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkCounterCountStatement(Util::SourceInfo srcInfo, cstring counter, const IR::Expression* index, const IR::Expression* incr);
    DpdkCounterCountStatement(cstring counter, const IR::Expression* index, const IR::Expression* incr);
    DpdkCounterCountStatement(Util::SourceInfo srcInfo, cstring counter, const IR::Expression* index);
    DpdkCounterCountStatement(cstring counter, const IR::Expression* index);
    IRNODE_SUBCLASS(DpdkCounterCountStatement)
};
}  // namespace IR
namespace IR {
class DpdkRegisterDeclStatement : public DpdkAsmStatement {
 public:
    cstring reg;
    const IR::Expression* size = nullptr;
    const IR::Expression* init_val = nullptr;
#line 491 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 9170 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkRegisterDeclStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkRegisterDeclStatement"; }
    static cstring static_type_name() { return "DpdkRegisterDeclStatement"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkRegisterDeclStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkRegisterDeclStatement(Util::SourceInfo srcInfo, cstring reg, const IR::Expression* size, const IR::Expression* init_val);
    DpdkRegisterDeclStatement(cstring reg, const IR::Expression* size, const IR::Expression* init_val);
    DpdkRegisterDeclStatement(Util::SourceInfo srcInfo, cstring reg, const IR::Expression* size);
    DpdkRegisterDeclStatement(cstring reg, const IR::Expression* size);
    IRNODE_SUBCLASS(DpdkRegisterDeclStatement)
};
}  // namespace IR
namespace IR {
class DpdkRegisterReadStatement : public DpdkAssignmentStatement {
 public:
    cstring reg;
    const IR::Expression* index = nullptr;
#line 498 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 9198 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 501 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    DpdkRegisterReadStatement(const IR::Expression* dst, cstring reg, const IR::Expression* index);
#line 9201 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkRegisterReadStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkRegisterReadStatement"; }
    static cstring static_type_name() { return "DpdkRegisterReadStatement"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkRegisterReadStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAssignmentStatement const & a) const override { return a == *this; }
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    IRNODE_SUBCLASS(DpdkRegisterReadStatement)
};
}  // namespace IR
namespace IR {
class DpdkRegisterWriteStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    cstring reg;
    const IR::Expression* index = nullptr;
    const IR::Expression* src = nullptr;
#line 509 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 9227 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkRegisterWriteStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkRegisterWriteStatement"; }
    static cstring static_type_name() { return "DpdkRegisterWriteStatement"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkRegisterWriteStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkRegisterWriteStatement(Util::SourceInfo srcInfo, cstring reg, const IR::Expression* index, const IR::Expression* src);
    DpdkRegisterWriteStatement(cstring reg, const IR::Expression* index, const IR::Expression* src);
    IRNODE_SUBCLASS(DpdkRegisterWriteStatement)
};
}  // namespace IR
namespace IR {
class DpdkValidateStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* header = nullptr;
#line 515 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 9252 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkValidateStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkValidateStatement"; }
    static cstring static_type_name() { return "DpdkValidateStatement"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkValidateStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkValidateStatement(Util::SourceInfo srcInfo, const IR::Expression* header);
    DpdkValidateStatement(const IR::Expression* header);
    IRNODE_SUBCLASS(DpdkValidateStatement)
};
}  // namespace IR
namespace IR {
class DpdkInvalidateStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
    const IR::Expression* header = nullptr;
#line 520 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 9277 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkInvalidateStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "DpdkInvalidateStatement"; }
    static cstring static_type_name() { return "DpdkInvalidateStatement"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkInvalidateStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkInvalidateStatement(Util::SourceInfo srcInfo, const IR::Expression* header);
    DpdkInvalidateStatement(const IR::Expression* header);
    IRNODE_SUBCLASS(DpdkInvalidateStatement)
};
}  // namespace IR
namespace IR {
class DpdkDropStatement : public DpdkAsmStatement, public virtual IDPDKNode {
 public:
#line 524 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
    std::ostream & toSpec(std::ostream & out) const override;
#line 9301 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::DpdkDropStatement const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "DpdkDropStatement"; }
    static cstring static_type_name() { return "DpdkDropStatement"; }
    void dbprint(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    DpdkDropStatement(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::DpdkAsmStatement const & a) const override { return a == *this; }
    bool operator==(IR::Node const & a) const override { return a == *this; }
    DpdkDropStatement(Util::SourceInfo srcInfo);
    DpdkDropStatement();
    IRNODE_SUBCLASS(DpdkDropStatement)
};
}  // namespace IR

#line 18 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
#include "backends/tc/tc_defines.h"
#line 9320 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
namespace IR {
class TCKernelMetadata : public Node {
 public:
    unsigned metaField;
#line 23 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    cstring toString() const override;
#line 9327 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 45 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void dbprint(std::ostream & out) const override;
#line 9330 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::TCKernelMetadata const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "TCKernelMetadata"; }
    static cstring static_type_name() { return "TCKernelMetadata"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    TCKernelMetadata(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    TCKernelMetadata(Util::SourceInfo srcInfo, unsigned metaField);
    TCKernelMetadata(unsigned metaField);
    IRNODE_SUBCLASS(TCKernelMetadata)
};
}  // namespace IR
namespace IR {
class TCActionParam : public Node {
 public:
    cstring paramName;
    unsigned dataType;
    unsigned bitSize;
#line 52 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void setParamName(cstring pN);
#line 9353 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 55 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void setBitSize(unsigned bS);
#line 9356 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 58 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void setDataType(unsigned d);
#line 9359 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 61 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    TCActionParam();
#line 9362 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 65 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    cstring getParamName() const;
#line 9365 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 68 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    cstring getName() const;
#line 9368 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 71 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    cstring toString() const override;
#line 9371 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 104 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void dbprint(std::ostream & out) const override;
#line 9374 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::TCActionParam const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "TCActionParam"; }
    static cstring static_type_name() { return "TCActionParam"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    TCActionParam(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    TCActionParam(Util::SourceInfo srcInfo, cstring paramName, unsigned dataType, unsigned bitSize);
    TCActionParam(cstring paramName, unsigned dataType, unsigned bitSize);
    IRNODE_SUBCLASS(TCActionParam)
};
}  // namespace IR
namespace IR {
class TCAction : public Node {
 public:
    cstring actionName;
    cstring pipelineName;
    unsigned actId;
    safe_vector<const IR::TCActionParam *> actionParams;
#line 112 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    cstring getName() const;
#line 9398 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 117 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void setPipelineName(cstring pN);
#line 9401 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 120 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void addActionParams(const IR::TCActionParam* tca);
#line 9404 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 123 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void setActionId(unsigned id);
#line 9407 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 126 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    TCAction(cstring aN);
#line 9410 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 131 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    cstring toString() const override;
#line 9413 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 151 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void dbprint(std::ostream & out) const override;
#line 9416 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::TCAction const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    cstring node_type_name() const override { return "TCAction"; }
    static cstring static_type_name() { return "TCAction"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    TCAction(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    TCAction(Util::SourceInfo srcInfo, cstring actionName, cstring pipelineName, unsigned actId, safe_vector<const IR::TCActionParam *> actionParams);
    TCAction(cstring actionName, cstring pipelineName, unsigned actId, safe_vector<const IR::TCActionParam *> actionParams);
    TCAction(Util::SourceInfo srcInfo, cstring actionName, cstring pipelineName, unsigned actId);
    TCAction(cstring actionName, cstring pipelineName, unsigned actId);
    IRNODE_SUBCLASS(TCAction)
};
}  // namespace IR
namespace IR {
class TCTable : public Node {
 public:
    unsigned tableID;
    cstring tableName;
    cstring controlName;
    cstring pipelineName;
    unsigned keySize;
    unsigned tableEntriesCount;
    unsigned numMask;
    unsigned matchType;
    const IR::TCAction* preaction = nullptr;
    const IR::TCAction* postaction = nullptr;
    const IR::TCAction* defaultHitAction = nullptr;
    bool isDefaultHitConst;
    const IR::TCAction* defaultMissAction = nullptr;
    bool isDefaultMissConst;
    ordered_map<const IR::TCAction *, unsigned> actionList;
#line 170 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void setKeySize(unsigned k);
#line 9453 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 173 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void setTableEntriesCount(unsigned t);
#line 9456 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 176 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void setNumMask(unsigned n);
#line 9459 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 179 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void setMatchType(unsigned m);
#line 9462 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 182 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void setPreaction(const IR::TCAction* p);
#line 9465 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 185 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void setPostaction(const IR::TCAction* p);
#line 9468 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 188 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void setDefaultHitAction(const IR::TCAction* d);
#line 9471 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 191 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void setDefaultMissAction(const IR::TCAction* d);
#line 9474 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 194 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void setDefaultHitConst(bool i);
#line 9477 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 197 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void setDefaultMissConst(bool i);
#line 9480 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 200 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void addAction(const IR::TCAction* action, unsigned flag);
#line 9483 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 203 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    cstring printMatchType(unsigned matchType) const;
#line 9486 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 218 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    TCTable(unsigned tId, cstring tN, cstring cN, cstring pN);
#line 9489 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 234 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    cstring toString() const override;
#line 9492 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 293 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void dbprint(std::ostream & out) const override;
#line 9495 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::TCTable const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "TCTable"; }
    static cstring static_type_name() { return "TCTable"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    TCTable(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    TCTable(Util::SourceInfo srcInfo, unsigned tableID, cstring tableName, cstring controlName, cstring pipelineName, unsigned keySize, unsigned tableEntriesCount, unsigned numMask, unsigned matchType, const IR::TCAction* preaction, const IR::TCAction* postaction, const IR::TCAction* defaultHitAction, bool isDefaultHitConst, const IR::TCAction* defaultMissAction, bool isDefaultMissConst, ordered_map<const IR::TCAction *, unsigned> actionList);
    TCTable(unsigned tableID, cstring tableName, cstring controlName, cstring pipelineName, unsigned keySize, unsigned tableEntriesCount, unsigned numMask, unsigned matchType, const IR::TCAction* preaction, const IR::TCAction* postaction, const IR::TCAction* defaultHitAction, bool isDefaultHitConst, const IR::TCAction* defaultMissAction, bool isDefaultMissConst, ordered_map<const IR::TCAction *, unsigned> actionList);
    IRNODE_SUBCLASS(TCTable)
};
}  // namespace IR
namespace IR {
class TCPipeline : public Node {
 public:
    cstring pipelineName;
    unsigned pipelineId;
    unsigned numTables;
    safe_vector<const IR::TCAction *> actionDefs;
    safe_vector<const IR::TCTable *> tableDefs;
    const IR::TCAction* preaction = nullptr;
    const IR::TCAction* postaction = nullptr;
#line 304 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void setPipelineName(cstring pName);
#line 9525 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 307 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void setPipelineId(unsigned p);
#line 9528 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 310 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void setNumTables(unsigned n);
#line 9531 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 313 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void addActionDefinition(const IR::TCAction* actionDef);
#line 9534 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 316 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void addTableDefinition(const IR::TCTable* tableDef);
#line 9537 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 319 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void setPipelinePreAction(const IR::TCAction* action);
#line 9540 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 322 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void setPipelinePostAction(const IR::TCAction* action);
#line 9543 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 325 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    TCPipeline();
#line 9546 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 333 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    cstring toString() const override;
#line 9549 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
#line 364 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
    void dbprint(std::ostream & out) const override;
#line 9552 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.h"
    bool operator==(IR::TCPipeline const & a) const override;
    bool equiv(IR::Node const & a_) const override;
    void visit_children(Visitor & v) override;
    void visit_children(Visitor & v) const override;
    void validate() const override;
    cstring node_type_name() const override { return "TCPipeline"; }
    static cstring static_type_name() { return "TCPipeline"; }
    void dump_fields(std::ostream & out) const override;
    void toJSON(JSONGenerator & json) const override;
    TCPipeline(JSONLoader & json);
    static IR::Node * fromJSON(JSONLoader & json);
    bool operator==(IR::Node const & a) const override { return a == *this; }
    TCPipeline(Util::SourceInfo srcInfo, cstring pipelineName, unsigned pipelineId, unsigned numTables, safe_vector<const IR::TCAction *> actionDefs, safe_vector<const IR::TCTable *> tableDefs, const IR::TCAction* preaction, const IR::TCAction* postaction);
    TCPipeline(cstring pipelineName, unsigned pipelineId, unsigned numTables, safe_vector<const IR::TCAction *> actionDefs, safe_vector<const IR::TCTable *> tableDefs, const IR::TCAction* preaction, const IR::TCAction* postaction);
    IRNODE_SUBCLASS(TCPipeline)
};
}  // namespace IR
#endif /* IR_GENERATED_H_ */
