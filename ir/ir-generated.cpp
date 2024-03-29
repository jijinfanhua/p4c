#include "ir/ir-generated.h"    // IWYU pragma: keep

#include "ir/ir-inline.h"       // IWYU pragma: keep
#include "ir/json_generator.h"  // IWYU pragma: keep
#include "ir/json_loader.h"     // IWYU pragma: keep
#include "ir/visitor.h"         // IWYU pragma: keep
#include "lib/algorithm.h"      // IWYU pragma: keep
#include "lib/log.h"            // IWYU pragma: keep

std::map<cstring, NodeFactoryFn> IR::unpacker_table = {
{"Type_Unknown", NodeFactoryFn(&IR::Type_Unknown::fromJSON)},
{"Path", NodeFactoryFn(&IR::Path::fromJSON)},
{"NamedExpression", NodeFactoryFn(&IR::NamedExpression::fromJSON)},
{"AnnotationToken", NodeFactoryFn(&IR::AnnotationToken::fromJSON)},
{"Annotation", NodeFactoryFn(&IR::Annotation::fromJSON)},
{"Annotations", NodeFactoryFn(&IR::Annotations::fromJSON)},
{"Argument", NodeFactoryFn(&IR::Argument::fromJSON)},
{"Type_Any", NodeFactoryFn(&IR::Type_Any::fromJSON)},
{"Type_Fragment", NodeFactoryFn(&IR::Type_Fragment::fromJSON)},
{"Type_Type", NodeFactoryFn(&IR::Type_Type::fromJSON)},
{"Type_Boolean", NodeFactoryFn(&IR::Type_Boolean::fromJSON)},
{"Type_State", NodeFactoryFn(&IR::Type_State::fromJSON)},
{"Type_Bits", NodeFactoryFn(&IR::Type_Bits::fromJSON)},
{"Type_Varbits", NodeFactoryFn(&IR::Type_Varbits::fromJSON)},
{"Parameter", NodeFactoryFn(&IR::Parameter::fromJSON)},
{"ParameterList", NodeFactoryFn(&IR::ParameterList::fromJSON)},
{"Type_Var", NodeFactoryFn(&IR::Type_Var::fromJSON)},
{"Type_InfInt", NodeFactoryFn(&IR::Type_InfInt::fromJSON)},
{"Type_Dontcare", NodeFactoryFn(&IR::Type_Dontcare::fromJSON)},
{"Type_Void", NodeFactoryFn(&IR::Type_Void::fromJSON)},
{"Type_MatchKind", NodeFactoryFn(&IR::Type_MatchKind::fromJSON)},
{"TypeParameters", NodeFactoryFn(&IR::TypeParameters::fromJSON)},
{"StructField", NodeFactoryFn(&IR::StructField::fromJSON)},
{"Type_Struct", NodeFactoryFn(&IR::Type_Struct::fromJSON)},
{"Type_UnknownStruct", NodeFactoryFn(&IR::Type_UnknownStruct::fromJSON)},
{"Type_HeaderUnion", NodeFactoryFn(&IR::Type_HeaderUnion::fromJSON)},
{"Type_Header", NodeFactoryFn(&IR::Type_Header::fromJSON)},
{"Type_Set", NodeFactoryFn(&IR::Type_Set::fromJSON)},
{"Type_List", NodeFactoryFn(&IR::Type_List::fromJSON)},
{"Type_Tuple", NodeFactoryFn(&IR::Type_Tuple::fromJSON)},
{"Type_P4List", NodeFactoryFn(&IR::Type_P4List::fromJSON)},
{"Type_Package", NodeFactoryFn(&IR::Type_Package::fromJSON)},
{"Type_Parser", NodeFactoryFn(&IR::Type_Parser::fromJSON)},
{"Type_Control", NodeFactoryFn(&IR::Type_Control::fromJSON)},
{"Type_Name", NodeFactoryFn(&IR::Type_Name::fromJSON)},
{"Type_Stack", NodeFactoryFn(&IR::Type_Stack::fromJSON)},
{"Type_Specialized", NodeFactoryFn(&IR::Type_Specialized::fromJSON)},
{"Type_SpecializedCanonical", NodeFactoryFn(&IR::Type_SpecializedCanonical::fromJSON)},
{"Declaration_ID", NodeFactoryFn(&IR::Declaration_ID::fromJSON)},
{"Type_String", NodeFactoryFn(&IR::Type_String::fromJSON)},
{"Type_Enum", NodeFactoryFn(&IR::Type_Enum::fromJSON)},
{"SerEnumMember", NodeFactoryFn(&IR::SerEnumMember::fromJSON)},
{"Type_SerEnum", NodeFactoryFn(&IR::Type_SerEnum::fromJSON)},
{"Type_Table", NodeFactoryFn(&IR::Type_Table::fromJSON)},
{"Type_ActionEnum", NodeFactoryFn(&IR::Type_ActionEnum::fromJSON)},
{"Type_Method", NodeFactoryFn(&IR::Type_Method::fromJSON)},
{"ArgumentInfo", NodeFactoryFn(&IR::ArgumentInfo::fromJSON)},
{"Type_MethodCall", NodeFactoryFn(&IR::Type_MethodCall::fromJSON)},
{"Type_Action", NodeFactoryFn(&IR::Type_Action::fromJSON)},
{"Method", NodeFactoryFn(&IR::Method::fromJSON)},
{"Type_Typedef", NodeFactoryFn(&IR::Type_Typedef::fromJSON)},
{"Type_Newtype", NodeFactoryFn(&IR::Type_Newtype::fromJSON)},
{"Type_Extern", NodeFactoryFn(&IR::Type_Extern::fromJSON)},
{"Neg", NodeFactoryFn(&IR::Neg::fromJSON)},
{"UPlus", NodeFactoryFn(&IR::UPlus::fromJSON)},
{"Cmpl", NodeFactoryFn(&IR::Cmpl::fromJSON)},
{"LNot", NodeFactoryFn(&IR::LNot::fromJSON)},
{"Mul", NodeFactoryFn(&IR::Mul::fromJSON)},
{"Div", NodeFactoryFn(&IR::Div::fromJSON)},
{"Mod", NodeFactoryFn(&IR::Mod::fromJSON)},
{"Add", NodeFactoryFn(&IR::Add::fromJSON)},
{"Sub", NodeFactoryFn(&IR::Sub::fromJSON)},
{"AddSat", NodeFactoryFn(&IR::AddSat::fromJSON)},
{"SubSat", NodeFactoryFn(&IR::SubSat::fromJSON)},
{"Shl", NodeFactoryFn(&IR::Shl::fromJSON)},
{"Shr", NodeFactoryFn(&IR::Shr::fromJSON)},
{"Equ", NodeFactoryFn(&IR::Equ::fromJSON)},
{"Neq", NodeFactoryFn(&IR::Neq::fromJSON)},
{"Lss", NodeFactoryFn(&IR::Lss::fromJSON)},
{"Leq", NodeFactoryFn(&IR::Leq::fromJSON)},
{"Grt", NodeFactoryFn(&IR::Grt::fromJSON)},
{"Geq", NodeFactoryFn(&IR::Geq::fromJSON)},
{"BAnd", NodeFactoryFn(&IR::BAnd::fromJSON)},
{"BOr", NodeFactoryFn(&IR::BOr::fromJSON)},
{"BXor", NodeFactoryFn(&IR::BXor::fromJSON)},
{"LAnd", NodeFactoryFn(&IR::LAnd::fromJSON)},
{"LOr", NodeFactoryFn(&IR::LOr::fromJSON)},
{"Dots", NodeFactoryFn(&IR::Dots::fromJSON)},
{"NamedDots", NodeFactoryFn(&IR::NamedDots::fromJSON)},
{"Constant", NodeFactoryFn(&IR::Constant::fromJSON)},
{"BoolLiteral", NodeFactoryFn(&IR::BoolLiteral::fromJSON)},
{"StringLiteral", NodeFactoryFn(&IR::StringLiteral::fromJSON)},
{"PathExpression", NodeFactoryFn(&IR::PathExpression::fromJSON)},
{"TypeNameExpression", NodeFactoryFn(&IR::TypeNameExpression::fromJSON)},
{"Slice", NodeFactoryFn(&IR::Slice::fromJSON)},
{"Member", NodeFactoryFn(&IR::Member::fromJSON)},
{"Concat", NodeFactoryFn(&IR::Concat::fromJSON)},
{"ArrayIndex", NodeFactoryFn(&IR::ArrayIndex::fromJSON)},
{"Range", NodeFactoryFn(&IR::Range::fromJSON)},
{"Mask", NodeFactoryFn(&IR::Mask::fromJSON)},
{"Mux", NodeFactoryFn(&IR::Mux::fromJSON)},
{"DefaultExpression", NodeFactoryFn(&IR::DefaultExpression::fromJSON)},
{"This", NodeFactoryFn(&IR::This::fromJSON)},
{"Cast", NodeFactoryFn(&IR::Cast::fromJSON)},
{"SelectCase", NodeFactoryFn(&IR::SelectCase::fromJSON)},
{"SelectExpression", NodeFactoryFn(&IR::SelectExpression::fromJSON)},
{"MethodCallExpression", NodeFactoryFn(&IR::MethodCallExpression::fromJSON)},
{"ConstructorCallExpression", NodeFactoryFn(&IR::ConstructorCallExpression::fromJSON)},
{"BaseListExpression", NodeFactoryFn(&IR::BaseListExpression::fromJSON)},
{"ListExpression", NodeFactoryFn(&IR::ListExpression::fromJSON)},
{"P4ListExpression", NodeFactoryFn(&IR::P4ListExpression::fromJSON)},
{"StructExpression", NodeFactoryFn(&IR::StructExpression::fromJSON)},
{"Invalid", NodeFactoryFn(&IR::Invalid::fromJSON)},
{"InvalidHeader", NodeFactoryFn(&IR::InvalidHeader::fromJSON)},
{"InvalidHeaderUnion", NodeFactoryFn(&IR::InvalidHeaderUnion::fromJSON)},
{"HeaderStackExpression", NodeFactoryFn(&IR::HeaderStackExpression::fromJSON)},
{"ListCompileTimeValue", NodeFactoryFn(&IR::ListCompileTimeValue::fromJSON)},
{"P4ListCompileTimeValue", NodeFactoryFn(&IR::P4ListCompileTimeValue::fromJSON)},
{"StructCompileTimeValue", NodeFactoryFn(&IR::StructCompileTimeValue::fromJSON)},
{"CompileTimeMethodCall", NodeFactoryFn(&IR::CompileTimeMethodCall::fromJSON)},
{"ParserState", NodeFactoryFn(&IR::ParserState::fromJSON)},
{"P4Parser", NodeFactoryFn(&IR::P4Parser::fromJSON)},
{"P4Control", NodeFactoryFn(&IR::P4Control::fromJSON)},
{"P4Action", NodeFactoryFn(&IR::P4Action::fromJSON)},
{"Type_Error", NodeFactoryFn(&IR::Type_Error::fromJSON)},
{"Declaration_MatchKind", NodeFactoryFn(&IR::Declaration_MatchKind::fromJSON)},
{"ExpressionValue", NodeFactoryFn(&IR::ExpressionValue::fromJSON)},
{"ExpressionListValue", NodeFactoryFn(&IR::ExpressionListValue::fromJSON)},
{"ActionListElement", NodeFactoryFn(&IR::ActionListElement::fromJSON)},
{"ActionList", NodeFactoryFn(&IR::ActionList::fromJSON)},
{"KeyElement", NodeFactoryFn(&IR::KeyElement::fromJSON)},
{"Key", NodeFactoryFn(&IR::Key::fromJSON)},
{"Entry", NodeFactoryFn(&IR::Entry::fromJSON)},
{"EntriesList", NodeFactoryFn(&IR::EntriesList::fromJSON)},
{"Property", NodeFactoryFn(&IR::Property::fromJSON)},
{"TableProperties", NodeFactoryFn(&IR::TableProperties::fromJSON)},
{"P4Table", NodeFactoryFn(&IR::P4Table::fromJSON)},
{"P4ValueSet", NodeFactoryFn(&IR::P4ValueSet::fromJSON)},
{"Declaration_Variable", NodeFactoryFn(&IR::Declaration_Variable::fromJSON)},
{"Declaration_Constant", NodeFactoryFn(&IR::Declaration_Constant::fromJSON)},
{"Declaration_Instance", NodeFactoryFn(&IR::Declaration_Instance::fromJSON)},
{"P4Program", NodeFactoryFn(&IR::P4Program::fromJSON)},
{"ExitStatement", NodeFactoryFn(&IR::ExitStatement::fromJSON)},
{"ReturnStatement", NodeFactoryFn(&IR::ReturnStatement::fromJSON)},
{"EmptyStatement", NodeFactoryFn(&IR::EmptyStatement::fromJSON)},
{"AssignmentStatement", NodeFactoryFn(&IR::AssignmentStatement::fromJSON)},
{"IfStatement", NodeFactoryFn(&IR::IfStatement::fromJSON)},
{"BlockStatement", NodeFactoryFn(&IR::BlockStatement::fromJSON)},
{"MethodCallStatement", NodeFactoryFn(&IR::MethodCallStatement::fromJSON)},
{"SwitchCase", NodeFactoryFn(&IR::SwitchCase::fromJSON)},
{"SwitchStatement", NodeFactoryFn(&IR::SwitchStatement::fromJSON)},
{"Function", NodeFactoryFn(&IR::Function::fromJSON)},
{"TableBlock", NodeFactoryFn(&IR::TableBlock::fromJSON)},
{"ParserBlock", NodeFactoryFn(&IR::ParserBlock::fromJSON)},
{"ControlBlock", NodeFactoryFn(&IR::ControlBlock::fromJSON)},
{"PackageBlock", NodeFactoryFn(&IR::PackageBlock::fromJSON)},
{"ExternBlock", NodeFactoryFn(&IR::ExternBlock::fromJSON)},
{"ToplevelBlock", NodeFactoryFn(&IR::ToplevelBlock::fromJSON)},
{"Type_Block", NodeFactoryFn(&IR::Type_Block::fromJSON)},
{"Type_Counter", NodeFactoryFn(&IR::Type_Counter::fromJSON)},
{"Type_Expression", NodeFactoryFn(&IR::Type_Expression::fromJSON)},
{"Type_FieldListCalculation", NodeFactoryFn(&IR::Type_FieldListCalculation::fromJSON)},
{"Type_Meter", NodeFactoryFn(&IR::Type_Meter::fromJSON)},
{"Type_Register", NodeFactoryFn(&IR::Type_Register::fromJSON)},
{"Type_AnyTable", NodeFactoryFn(&IR::Type_AnyTable::fromJSON)},
{"Header", NodeFactoryFn(&IR::Header::fromJSON)},
{"HeaderStack", NodeFactoryFn(&IR::HeaderStack::fromJSON)},
{"Metadata", NodeFactoryFn(&IR::Metadata::fromJSON)},
{"ConcreteHeaderRef", NodeFactoryFn(&IR::ConcreteHeaderRef::fromJSON)},
{"HeaderStackItemRef", NodeFactoryFn(&IR::HeaderStackItemRef::fromJSON)},
{"If", NodeFactoryFn(&IR::If::fromJSON)},
{"NamedCond", NodeFactoryFn(&IR::NamedCond::fromJSON)},
{"Apply", NodeFactoryFn(&IR::Apply::fromJSON)},
{"Primitive", NodeFactoryFn(&IR::Primitive::fromJSON)},
{"FieldList", NodeFactoryFn(&IR::FieldList::fromJSON)},
{"FieldListCalculation", NodeFactoryFn(&IR::FieldListCalculation::fromJSON)},
{"CalculatedField", NodeFactoryFn(&IR::CalculatedField::fromJSON)},
{"ParserValueSet", NodeFactoryFn(&IR::ParserValueSet::fromJSON)},
{"CaseEntry", NodeFactoryFn(&IR::CaseEntry::fromJSON)},
{"V1Parser", NodeFactoryFn(&IR::V1Parser::fromJSON)},
{"ParserException", NodeFactoryFn(&IR::ParserException::fromJSON)},
{"Counter", NodeFactoryFn(&IR::Counter::fromJSON)},
{"Meter", NodeFactoryFn(&IR::Meter::fromJSON)},
{"Register", NodeFactoryFn(&IR::Register::fromJSON)},
{"PrimitiveAction", NodeFactoryFn(&IR::PrimitiveAction::fromJSON)},
{"NameList", NodeFactoryFn(&IR::NameList::fromJSON)},
{"ActionArg", NodeFactoryFn(&IR::ActionArg::fromJSON)},
{"ActionFunction", NodeFactoryFn(&IR::ActionFunction::fromJSON)},
{"ActionProfile", NodeFactoryFn(&IR::ActionProfile::fromJSON)},
{"ActionSelector", NodeFactoryFn(&IR::ActionSelector::fromJSON)},
{"V1Table", NodeFactoryFn(&IR::V1Table::fromJSON)},
{"V1Control", NodeFactoryFn(&IR::V1Control::fromJSON)},
{"AttribLocal", NodeFactoryFn(&IR::AttribLocal::fromJSON)},
{"AttribLocals", NodeFactoryFn(&IR::AttribLocals::fromJSON)},
{"Attribute", NodeFactoryFn(&IR::Attribute::fromJSON)},
{"GlobalRef", NodeFactoryFn(&IR::GlobalRef::fromJSON)},
{"AttributeRef", NodeFactoryFn(&IR::AttributeRef::fromJSON)},
{"V1Program", NodeFactoryFn(&IR::V1Program::fromJSON)},
{"v1HeaderType", NodeFactoryFn(&IR::v1HeaderType::fromJSON)},
{"IntMod", NodeFactoryFn(&IR::IntMod::fromJSON)},
{"DpdkDeclaration", NodeFactoryFn(&IR::DpdkDeclaration::fromJSON)},
{"DpdkExternDeclaration", NodeFactoryFn(&IR::DpdkExternDeclaration::fromJSON)},
{"DpdkHeaderType", NodeFactoryFn(&IR::DpdkHeaderType::fromJSON)},
{"DpdkStructType", NodeFactoryFn(&IR::DpdkStructType::fromJSON)},
{"DpdkAction", NodeFactoryFn(&IR::DpdkAction::fromJSON)},
{"DpdkTable", NodeFactoryFn(&IR::DpdkTable::fromJSON)},
{"DpdkSelector", NodeFactoryFn(&IR::DpdkSelector::fromJSON)},
{"DpdkLearner", NodeFactoryFn(&IR::DpdkLearner::fromJSON)},
{"DpdkAsmProgram", NodeFactoryFn(&IR::DpdkAsmProgram::fromJSON)},
{"DpdkListStatement", NodeFactoryFn(&IR::DpdkListStatement::fromJSON)},
{"DpdkApplyStatement", NodeFactoryFn(&IR::DpdkApplyStatement::fromJSON)},
{"DpdkLearnStatement", NodeFactoryFn(&IR::DpdkLearnStatement::fromJSON)},
{"DpdkMirrorStatement", NodeFactoryFn(&IR::DpdkMirrorStatement::fromJSON)},
{"DpdkEmitStatement", NodeFactoryFn(&IR::DpdkEmitStatement::fromJSON)},
{"DpdkExtractStatement", NodeFactoryFn(&IR::DpdkExtractStatement::fromJSON)},
{"DpdkLookaheadStatement", NodeFactoryFn(&IR::DpdkLookaheadStatement::fromJSON)},
{"DpdkJmpLabelStatement", NodeFactoryFn(&IR::DpdkJmpLabelStatement::fromJSON)},
{"DpdkJmpHitStatement", NodeFactoryFn(&IR::DpdkJmpHitStatement::fromJSON)},
{"DpdkJmpMissStatement", NodeFactoryFn(&IR::DpdkJmpMissStatement::fromJSON)},
{"DpdkJmpIfActionRunStatement", NodeFactoryFn(&IR::DpdkJmpIfActionRunStatement::fromJSON)},
{"DpdkJmpIfActionNotRunStatement", NodeFactoryFn(&IR::DpdkJmpIfActionNotRunStatement::fromJSON)},
{"DpdkJmpIfInvalidStatement", NodeFactoryFn(&IR::DpdkJmpIfInvalidStatement::fromJSON)},
{"DpdkJmpIfValidStatement", NodeFactoryFn(&IR::DpdkJmpIfValidStatement::fromJSON)},
{"DpdkJmpEqualStatement", NodeFactoryFn(&IR::DpdkJmpEqualStatement::fromJSON)},
{"DpdkJmpNotEqualStatement", NodeFactoryFn(&IR::DpdkJmpNotEqualStatement::fromJSON)},
{"DpdkJmpGreaterEqualStatement", NodeFactoryFn(&IR::DpdkJmpGreaterEqualStatement::fromJSON)},
{"DpdkJmpGreaterStatement", NodeFactoryFn(&IR::DpdkJmpGreaterStatement::fromJSON)},
{"DpdkJmpLessOrEqualStatement", NodeFactoryFn(&IR::DpdkJmpLessOrEqualStatement::fromJSON)},
{"DpdkJmpLessStatement", NodeFactoryFn(&IR::DpdkJmpLessStatement::fromJSON)},
{"DpdkRxStatement", NodeFactoryFn(&IR::DpdkRxStatement::fromJSON)},
{"DpdkTxStatement", NodeFactoryFn(&IR::DpdkTxStatement::fromJSON)},
{"DpdkMovStatement", NodeFactoryFn(&IR::DpdkMovStatement::fromJSON)},
{"DpdkAddStatement", NodeFactoryFn(&IR::DpdkAddStatement::fromJSON)},
{"DpdkAndStatement", NodeFactoryFn(&IR::DpdkAndStatement::fromJSON)},
{"DpdkShlStatement", NodeFactoryFn(&IR::DpdkShlStatement::fromJSON)},
{"DpdkShrStatement", NodeFactoryFn(&IR::DpdkShrStatement::fromJSON)},
{"DpdkSubStatement", NodeFactoryFn(&IR::DpdkSubStatement::fromJSON)},
{"DpdkOrStatement", NodeFactoryFn(&IR::DpdkOrStatement::fromJSON)},
{"DpdkXorStatement", NodeFactoryFn(&IR::DpdkXorStatement::fromJSON)},
{"DpdkRecircidStatement", NodeFactoryFn(&IR::DpdkRecircidStatement::fromJSON)},
{"DpdkReturnStatement", NodeFactoryFn(&IR::DpdkReturnStatement::fromJSON)},
{"DpdkRearmStatement", NodeFactoryFn(&IR::DpdkRearmStatement::fromJSON)},
{"DpdkRecirculateStatement", NodeFactoryFn(&IR::DpdkRecirculateStatement::fromJSON)},
{"DpdkLabelStatement", NodeFactoryFn(&IR::DpdkLabelStatement::fromJSON)},
{"DpdkChecksumAddStatement", NodeFactoryFn(&IR::DpdkChecksumAddStatement::fromJSON)},
{"DpdkChecksumSubStatement", NodeFactoryFn(&IR::DpdkChecksumSubStatement::fromJSON)},
{"DpdkChecksumClearStatement", NodeFactoryFn(&IR::DpdkChecksumClearStatement::fromJSON)},
{"DpdkHashDeclStatement", NodeFactoryFn(&IR::DpdkHashDeclStatement::fromJSON)},
{"DpdkGetHashStatement", NodeFactoryFn(&IR::DpdkGetHashStatement::fromJSON)},
{"DpdkGetChecksumStatement", NodeFactoryFn(&IR::DpdkGetChecksumStatement::fromJSON)},
{"DpdkCastStatement", NodeFactoryFn(&IR::DpdkCastStatement::fromJSON)},
{"DpdkVerifyStatement", NodeFactoryFn(&IR::DpdkVerifyStatement::fromJSON)},
{"DpdkMeterDeclStatement", NodeFactoryFn(&IR::DpdkMeterDeclStatement::fromJSON)},
{"DpdkMeterExecuteStatement", NodeFactoryFn(&IR::DpdkMeterExecuteStatement::fromJSON)},
{"DpdkGetTableEntryIndex", NodeFactoryFn(&IR::DpdkGetTableEntryIndex::fromJSON)},
{"DpdkCounterCountStatement", NodeFactoryFn(&IR::DpdkCounterCountStatement::fromJSON)},
{"DpdkRegisterDeclStatement", NodeFactoryFn(&IR::DpdkRegisterDeclStatement::fromJSON)},
{"DpdkRegisterReadStatement", NodeFactoryFn(&IR::DpdkRegisterReadStatement::fromJSON)},
{"DpdkRegisterWriteStatement", NodeFactoryFn(&IR::DpdkRegisterWriteStatement::fromJSON)},
{"DpdkValidateStatement", NodeFactoryFn(&IR::DpdkValidateStatement::fromJSON)},
{"DpdkInvalidateStatement", NodeFactoryFn(&IR::DpdkInvalidateStatement::fromJSON)},
{"DpdkDropStatement", NodeFactoryFn(&IR::DpdkDropStatement::fromJSON)},
{"TCKernelMetadata", NodeFactoryFn(&IR::TCKernelMetadata::fromJSON)},
{"TCActionParam", NodeFactoryFn(&IR::TCActionParam::fromJSON)},
{"TCAction", NodeFactoryFn(&IR::TCAction::fromJSON)},
{"TCTable", NodeFactoryFn(&IR::TCTable::fromJSON)},
{"TCPipeline", NodeFactoryFn(&IR::TCPipeline::fromJSON)} };


#line 19 "/home/fengyong/Desktop/p4c/ir/base.def"
bool IR::CompileTimeValue::equiv(IR::CompileTimeValue const & other) const {
        return this->getNode()->equiv(*other.getNode());
    }
#line 275 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
/// Well-defined only for types with fixed width
#line 39 "/home/fengyong/Desktop/p4c/ir/base.def"
int IR::Type::width_bits() const { return 0; }
#line 279 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
/// When possible returns the corresponding type that can be inserted
/// in a P4 program; may return a Type_Name
bool IR::Type::operator==(IR::Type const & a) const {
        return typeid(*this) == typeid(a);
    }
bool IR::Type::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        return true;
    }
void IR::Type::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
}
IR::Type::Type(JSONLoader & json) : Node(json) {
}
IR::Type::Type(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::Type::Type() 
    { validate(); }
/// Allows the retrieval of type parameters
/// @returns the type signature of the apply method
/// prints an error if it finds duplicate names
#line 76 "/home/fengyong/Desktop/p4c/ir/base.def"
void IR::IGeneralNamespace::validate() const { checkDuplicateDeclarations(); }
#line 305 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
/// The parameters of the functional object
/// Returns true if the parameters can be matched with the
/// supplied arguments.
/// The type of the constructor as a method

#line 110 "/home/fengyong/Desktop/p4c/ir/base.def"
const IR::ParameterList *IR::IContainer::getParameters() const { return getConstructorParameters(); }
#line 313 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 116 "/home/fengyong/Desktop/p4c/ir/base.def"
IR::Type const * IR::Type_Base::getP4Type() const { return this; }
#line 316 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Base::operator==(IR::Type_Base const & a) const {
        return Type::operator==(static_cast<const Type &>(a));
    }
bool IR::Type_Base::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        return true;
    }
void IR::Type_Base::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
}
IR::Type_Base::Type_Base(JSONLoader & json) : Type(json) {
}
IR::Type_Base::Type_Base(Util::SourceInfo srcInfo) :
    Type(srcInfo)
    { validate(); }
IR::Type_Base::Type_Base() 
    { validate(); }
#line 123 "/home/fengyong/Desktop/p4c/ir/base.def"
cstring IR::Type_Unknown::toString() const { return "Unknown type"; }
#line 337 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Unknown::operator==(IR::Type_Unknown const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Unknown::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Unknown::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Unknown::Type_Unknown(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Unknown::fromJSON(JSONLoader & json) { return new Type_Unknown(json); }
IR::Type_Unknown::Type_Unknown(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_Unknown::Type_Unknown() 
    { validate(); }
bool IR::StatOrDecl::operator==(IR::StatOrDecl const & a) const {
        return typeid(*this) == typeid(a);
    }
bool IR::StatOrDecl::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        return true;
    }
void IR::StatOrDecl::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
}
IR::StatOrDecl::StatOrDecl(JSONLoader & json) : Node(json) {
}
IR::StatOrDecl::StatOrDecl(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::StatOrDecl::StatOrDecl() 
    { validate(); }
#line 134 "/home/fengyong/Desktop/p4c/ir/base.def"
IR::ID IR::Declaration::getName() const { return name; }
#line 377 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 135 "/home/fengyong/Desktop/p4c/ir/base.def"
bool IR::Declaration::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!StatOrDecl::equiv(a_)) return false;
        auto &a = static_cast<const Declaration &>(a_);

#line 135 "/home/fengyong/Desktop/p4c/ir/base.def"
{ return name == a.name; /* ignore declid */ }    }
#line 386 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 139 "/home/fengyong/Desktop/p4c/ir/base.def"
cstring IR::Declaration::toString() const { return externalName(); }
#line 389 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Declaration::operator==(IR::Declaration const & a) const {
        return StatOrDecl::operator==(static_cast<const StatOrDecl &>(a))
        && name == a.name
        && declid == a.declid;
    }
void IR::Declaration::dump_fields(std::ostream & out) const {
    StatOrDecl::dump_fields(out);
        out << " name=" << name;
        out << " declid=" << declid;
}
void IR::Declaration::toJSON(JSONGenerator & json) const {
    StatOrDecl::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"declid\" : " << this->declid;
}
IR::Declaration::Declaration(JSONLoader & json) : StatOrDecl(json) {
    json.load("name", name);
    json.load("declid", declid);
}
IR::Declaration::Declaration(Util::SourceInfo srcInfo, IR::ID name) :
    StatOrDecl(srcInfo), name(name)
    { validate(); }
IR::Declaration::Declaration(IR::ID name) :
    name(name)
    { validate(); }
#line 150 "/home/fengyong/Desktop/p4c/ir/base.def"
IR::ID IR::Type_Declaration::getName() const { return name; }
#line 417 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 151 "/home/fengyong/Desktop/p4c/ir/base.def"
bool IR::Type_Declaration::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_Declaration &>(a_);

#line 151 "/home/fengyong/Desktop/p4c/ir/base.def"
{ return name == a.name; /* ignore declid */ }    }
#line 426 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 155 "/home/fengyong/Desktop/p4c/ir/base.def"
cstring IR::Type_Declaration::toString() const { return externalName(); }
#line 429 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 156 "/home/fengyong/Desktop/p4c/ir/base.def"
IR::Type const * IR::Type_Declaration::getP4Type() const { return new Type_Name(name); }
#line 432 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Declaration::operator==(IR::Type_Declaration const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && name == a.name
        && declid == a.declid;
    }
void IR::Type_Declaration::dump_fields(std::ostream & out) const {
    Type::dump_fields(out);
        out << " name=" << name;
        out << " declid=" << declid;
}
void IR::Type_Declaration::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"declid\" : " << this->declid;
}
IR::Type_Declaration::Type_Declaration(JSONLoader & json) : Type(json) {
    json.load("name", name);
    json.load("declid", declid);
}
IR::Type_Declaration::Type_Declaration(Util::SourceInfo srcInfo, IR::ID name) :
    Type(srcInfo), name(name)
    { validate(); }
IR::Type_Declaration::Type_Declaration(IR::ID name) :
    name(name)
    { validate(); }
/// Note that the type field is not visited.
/// Most P4_16 passes don't use this field.
/// It is a used to hold the result of TypeInferencing for the expression.
/// It is used by the P4_14 front-end and by some back-ends.
/// It is not visited by the visitors by default (can be visited explicitly in preorder)
#line 167 "/home/fengyong/Desktop/p4c/ir/base.def"
void IR::Expression::visit_children(Visitor & v) { (void)v; }
#line 167 "/home/fengyong/Desktop/p4c/ir/base.def"
void IR::Expression::visit_children(Visitor & v) const { (void)v; }
#line 467 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
IRNODE_DEFINE_APPLY_OVERLOAD(Expression, , )
bool IR::Expression::operator==(IR::Expression const & a) const {
        return typeid(*this) == typeid(a)
        && type == a.type;
    }
bool IR::Expression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const Expression &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr);
    }
void IR::Expression::validate() const {
#line 480 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(type); }
void IR::Expression::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
}
IR::Expression::Expression(JSONLoader & json) : Node(json) {
    json.load("type", type);
}
IR::Expression::Expression(Util::SourceInfo srcInfo, const IR::Type* type) :
    Node(srcInfo), type(type)
    { validate(); }
IR::Expression::Expression(const IR::Type* type) :
    type(type)
    { validate(); }
IR::Expression::Expression(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::Expression::Expression() 
    { validate(); }
#line 179 "/home/fengyong/Desktop/p4c/ir/base.def"
cstring IR::Operation::toString() const { return getStringOp(); }
#line 503 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Operation::operator==(IR::Operation const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a));
    }
bool IR::Operation::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        return true;
    }
void IR::Operation::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
}
IR::Operation::Operation(JSONLoader & json) : Expression(json) {
}
IR::Operation::Operation(Util::SourceInfo srcInfo, const IR::Type* type) :
    Expression(srcInfo, type)
    { validate(); }
IR::Operation::Operation(const IR::Type* type) :
    Expression(type)
    { validate(); }
IR::Operation::Operation(Util::SourceInfo srcInfo) :
    Expression(srcInfo)
    { validate(); }
IR::Operation::Operation() 
    { validate(); }
#line 189 "/home/fengyong/Desktop/p4c/ir/base.def"
bool IR::Path::isDontCare() const { return name.isDontCare(); }
#line 530 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 190 "/home/fengyong/Desktop/p4c/ir/base.def"
cstring IR::Path::toString() const {
        // This is the ORIGINAL name the user used
        if (absolute)
            return cstring(".") + name.toString();
        return name.toString();
    }
#line 538 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 196 "/home/fengyong/Desktop/p4c/ir/base.def"
cstring IR::Path::asString() const {
        // The CURRENT internal name
        if (absolute)
            return cstring(".") + name;
        return name;
    }
#line 546 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 202 "/home/fengyong/Desktop/p4c/ir/base.def"
void IR::Path::dbprint(std::ostream & out) const { out << name; }
#line 549 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 203 "/home/fengyong/Desktop/p4c/ir/base.def"
void IR::Path::validate() const {
#line 552 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

#line 203 "/home/fengyong/Desktop/p4c/ir/base.def"
{ BUG_CHECK(!name.name.isNullOrEmpty(), "Empty path"); } }
#line 556 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Path::operator==(IR::Path const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && absolute == a.absolute;
    }
bool IR::Path::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const Path &>(a_);
        return name == a.name
        && absolute == a.absolute;
    }
void IR::Path::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
        out << " absolute=" << absolute;
}
void IR::Path::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"absolute\" : " << this->absolute;
}
IR::Path::Path(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("absolute", absolute);
}
IR::Node * IR::Path::fromJSON(JSONLoader & json) { return new Path(json); }
IR::Path::Path(Util::SourceInfo srcInfo, IR::ID name, bool absolute) :
    Node(srcInfo), name(name), absolute(absolute)
    {
#line 188 "/home/fengyong/Desktop/p4c/ir/base.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 589 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Path::Path(IR::ID name, bool absolute) :
    name(name), absolute(absolute)
    {
#line 188 "/home/fengyong/Desktop/p4c/ir/base.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 596 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Path::Path(Util::SourceInfo srcInfo, IR::ID name) :
    Node(srcInfo), name(name)
    {
#line 188 "/home/fengyong/Desktop/p4c/ir/base.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 603 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Path::Path(IR::ID name) :
    name(name)
    {
#line 188 "/home/fengyong/Desktop/p4c/ir/base.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 610 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
bool IR::NamedExpression::operator==(IR::NamedExpression const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && expression == a.expression;
    }
bool IR::NamedExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const NamedExpression &>(a_);
        return (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr);
    }
void IR::NamedExpression::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(expression, "expression");
}
void IR::NamedExpression::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(expression, "expression");
}
void IR::NamedExpression::validate() const {
#line 631 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(expression); }
void IR::NamedExpression::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"expression\" : " << this->expression;
}
IR::NamedExpression::NamedExpression(JSONLoader & json) : Declaration(json) {
    json.load("expression", expression);
}
IR::Node * IR::NamedExpression::fromJSON(JSONLoader & json) { return new NamedExpression(json); }
IR::NamedExpression::NamedExpression(Util::SourceInfo srcInfo, IR::ID name, const IR::Expression* expression) :
    Declaration(srcInfo, name), expression(expression)
    { validate(); }
IR::NamedExpression::NamedExpression(IR::ID name, const IR::Expression* expression) :
    Declaration(name), expression(expression)
    { validate(); }

#line 218 "/home/fengyong/Desktop/p4c/ir/base.def"
void IR::AnnotationToken::dbprint(std::ostream & out) const { out << text; }
#line 651 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::AnnotationToken::operator==(IR::AnnotationToken const & a) const {
        return typeid(*this) == typeid(a)
        && token_type == a.token_type
        && text == a.text
        && constInfo == a.constInfo;
    }
bool IR::AnnotationToken::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const AnnotationToken &>(a_);
        return token_type == a.token_type
        && text == a.text
        && constInfo == a.constInfo;
    }
void IR::AnnotationToken::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " token_type=" << token_type;
        out << " text=" << text;
        out << " constInfo=" << constInfo;
}
void IR::AnnotationToken::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"token_type\" : " << this->token_type;
    json << "," << std::endl << json.indent << "\"text\" : " << this->text;
    if (constInfo != nullptr)     json << "," << std::endl << json.indent << "\"constInfo\" : " << this->constInfo;
}
IR::AnnotationToken::AnnotationToken(JSONLoader & json) : Node(json) {
    json.load("token_type", token_type);
    json.load("text", text);
    json.load("constInfo", constInfo);
}
IR::Node * IR::AnnotationToken::fromJSON(JSONLoader & json) { return new AnnotationToken(json); }
IR::AnnotationToken::AnnotationToken(Util::SourceInfo srcInfo, int token_type, cstring text, UnparsedConstant * constInfo) :
    Node(srcInfo), token_type(token_type), text(text), constInfo(constInfo)
    { validate(); }
IR::AnnotationToken::AnnotationToken(int token_type, cstring text, UnparsedConstant * constInfo) :
    token_type(token_type), text(text), constInfo(constInfo)
    { validate(); }
IR::AnnotationToken::AnnotationToken(Util::SourceInfo srcInfo, int token_type, cstring text) :
    Node(srcInfo), token_type(token_type), text(text)
    { validate(); }
IR::AnnotationToken::AnnotationToken(int token_type, cstring text) :
    token_type(token_type), text(text)
    { validate(); }
/// An unparsed annotation body
/// Whether the annotation body needs to be parsed.
/// Invariant: if this is true, then expr and kv must both be empty. If the
/// annotation is compiler-generated (e.g., derived from a P4₁₄ pragma),
/// then needsParsing will be false and the body will be empty, but expr or
/// kv may be populated.
/// Annotations that are simple expressions
/// Annotations described as key-value pairs
/// If this is true this is a structured annotation, and there are some
/// constraints on its contents.
/// For annotations parsed from P4-16 source.
#line 249 "/home/fengyong/Desktop/p4c/ir/base.def"
IR::Annotation::Annotation(Util::SourceInfo si, IR::ID n, IR::Vector<IR::AnnotationToken> const & a) : Node(si), name(n), body(a), needsParsing(true), structured(false) {}
#line 709 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

#line 252 "/home/fengyong/Desktop/p4c/ir/base.def"
IR::Annotation::Annotation(Util::SourceInfo si, IR::ID n, IR::Vector<IR::AnnotationToken> const & a, bool structured) : Node(si), name(n), body(a), needsParsing(true), structured(structured) {}
#line 713 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

#line 256 "/home/fengyong/Desktop/p4c/ir/base.def"
IR::Annotation::Annotation(Util::SourceInfo si, IR::ID n, std::initializer_list<IR::Expression const *> const & a, bool structured) : Node(si), name(n), needsParsing(false), expr(a), structured(structured) {}
#line 717 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 259 "/home/fengyong/Desktop/p4c/ir/base.def"
IR::Annotation::Annotation(Util::SourceInfo si, IR::ID n, IR::Vector<IR::Expression> const & a, bool structured) : Node(si), name(n), needsParsing(false), expr(a), structured(structured) {}
#line 720 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 261 "/home/fengyong/Desktop/p4c/ir/base.def"
IR::Annotation::Annotation(Util::SourceInfo si, IR::ID n, IR::IndexedVector<IR::NamedExpression> const & kv, bool structured) : Node(si), name(n), needsParsing(false), kv(kv), structured(structured) {}
#line 723 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 264 "/home/fengyong/Desktop/p4c/ir/base.def"
IR::Annotation::Annotation(IR::ID n, std::initializer_list<IR::Expression const *> const & a, bool structured) : name(n), needsParsing(false), expr(a), structured(structured) {}
#line 726 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 266 "/home/fengyong/Desktop/p4c/ir/base.def"
IR::Annotation::Annotation(IR::ID n, IR::Vector<IR::Expression> const & a, bool structured) : name(n), needsParsing(false), expr(a), structured(structured) {}
#line 729 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 268 "/home/fengyong/Desktop/p4c/ir/base.def"
IR::Annotation::Annotation(IR::ID n, intmax_t v, bool structured) : name(n), needsParsing(false), structured(structured) {
        expr.push_back(new Constant(v)); }
#line 733 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 271 "/home/fengyong/Desktop/p4c/ir/base.def"
IR::Annotation::Annotation(IR::ID n, cstring v, bool structured) : name(n), needsParsing(false), structured(structured) {
        expr.push_back(new StringLiteral(v)); }
#line 737 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
/// Indicates the control-plane name.
/// Action cannot be a default_action.
/// action can only be a default_action.
/// Code should be executed atomically.
/// Object should not be exposed to the control-plane.
/// P4-14 annotation for varbit fields.
/// Optional parameter annotation
/// Package documentation annotation.
/// Deprecation annotation.
/// Synchronous annotation.
/// extern function/method annotation.
/// extern function/method annotation.
/// noWarn annotation.
/// Match annotation (for value sets).
/// Used for recirculate, etc.
/// Used by compiler implementer to limit debug log to the annotated IR context.
#line 291 "/home/fengyong/Desktop/p4c/ir/base.def"
cstring IR::Annotation::toString() const { return cstring("@") + name; }
#line 756 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 292 "/home/fengyong/Desktop/p4c/ir/base.def"
void IR::Annotation::validate() const {
#line 759 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        body.validate();
        expr.validate();
        kv.validate();
#line 292 "/home/fengyong/Desktop/p4c/ir/base.def"
{
        BUG_CHECK(!name.name.isNullOrEmpty(), "empty annotation name");
        BUG_CHECK(!(needsParsing && !expr.empty()),
            "unparsed annotation body with non-empty expr");
        BUG_CHECK(!(needsParsing && !kv.empty()),
            "unparsed annotation body with non-empty kv");
    } }
#line 772 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
/// Extracts name value from a name annotation
/// Extracts a single string argument; error if the argument is not a string
#line 312 "/home/fengyong/Desktop/p4c/ir/base.def"
IR::Annotation::Kind IR::Annotation::annotationKind() const {
        if (!structured)
            return Kind::Unstructured;
        if (expr.size())
            return Kind::StructuredExpressionList;
        if (kv.size())
            return Kind::StructuredKVList;
        return Kind::StructuredEmpty;
    }
#line 785 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Annotation::operator==(IR::Annotation const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && body == a.body
        && needsParsing == a.needsParsing
        && expr == a.expr
        && kv == a.kv
        && structured == a.structured;
    }
bool IR::Annotation::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const Annotation &>(a_);
        return name == a.name
        && body.equiv(a.body)
        && needsParsing == a.needsParsing
        && expr.equiv(a.expr)
        && kv.equiv(a.kv)
        && structured == a.structured;
    }
void IR::Annotation::visit_children(Visitor & v) {
    Node::visit_children(v);
    body.visit_children(v);
    expr.visit_children(v);
    kv.visit_children(v);
}
void IR::Annotation::visit_children(Visitor & v) const {
    Node::visit_children(v);
    body.visit_children(v);
    expr.visit_children(v);
    kv.visit_children(v);
}
void IR::Annotation::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
        out << " needsParsing=" << needsParsing;
        out << " structured=" << structured;
}
void IR::Annotation::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"body\" : " << this->body;
    json << "," << std::endl << json.indent << "\"needsParsing\" : " << this->needsParsing;
    json << "," << std::endl << json.indent << "\"expr\" : " << this->expr;
    json << "," << std::endl << json.indent << "\"kv\" : " << this->kv;
    json << "," << std::endl << json.indent << "\"structured\" : " << this->structured;
}
IR::Annotation::Annotation(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("body", body);
    json.load("needsParsing", needsParsing);
    json.load("expr", expr);
    json.load("kv", kv);
    json.load("structured", structured);
}
IR::Node * IR::Annotation::fromJSON(JSONLoader & json) { return new Annotation(json); }
IR::Annotation::Annotation(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::AnnotationToken> body, bool needsParsing, IR::Vector<IR::Expression> expr, IR::IndexedVector<IR::NamedExpression> kv, bool structured) :
    Node(srcInfo), name(name), body(body), needsParsing(needsParsing), expr(expr), kv(kv), structured(structured)
    {
#line 246 "/home/fengyong/Desktop/p4c/ir/base.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 847 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Annotation::Annotation(IR::ID name, IR::Vector<IR::AnnotationToken> body, bool needsParsing, IR::Vector<IR::Expression> expr, IR::IndexedVector<IR::NamedExpression> kv, bool structured) :
    name(name), body(body), needsParsing(needsParsing), expr(expr), kv(kv), structured(structured)
    {
#line 246 "/home/fengyong/Desktop/p4c/ir/base.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 854 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }

#line 330 "/home/fengyong/Desktop/p4c/ir/base.def"
size_t IR::Annotations::size() const { return annotations.size(); }
#line 859 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"


#line 333 "/home/fengyong/Desktop/p4c/ir/base.def"
const IR::Annotation *IR::Annotations::getSingle(cstring name) const { return get(annotations, name); }
#line 864 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 334 "/home/fengyong/Desktop/p4c/ir/base.def"
const IR::Annotations *IR::Annotations::add(const IR::Annotation* annot) {
        if (annot->srcInfo) srcInfo += annot->srcInfo;
        annotations.push_back(annot);
        return this; }
#line 870 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 338 "/home/fengyong/Desktop/p4c/ir/base.def"
const IR::Annotations *IR::Annotations::add(const IR::Annotation* annot) const { return clone()->add(annot); }
#line 873 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 339 "/home/fengyong/Desktop/p4c/ir/base.def"
const IR::Annotations *IR::Annotations::addAnnotation(cstring name, const IR::Expression* expr, bool structured) {
        return add(new Annotation(name, Vector<Expression>(expr), structured)); }
#line 877 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 341 "/home/fengyong/Desktop/p4c/ir/base.def"
const IR::Annotations *IR::Annotations::addAnnotation(cstring name, const IR::Expression* expr, bool structured) const {
        return add(new Annotation(name, Vector<Expression>(expr), structured)); }
#line 881 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"


#line 345 "/home/fengyong/Desktop/p4c/ir/base.def"
const IR::Annotations *IR::Annotations::addAnnotationIfNew(cstring name, const IR::Expression* expr, bool structured) const {
        return getSingle(name) ? this : addAnnotation(name, expr, structured); }
#line 887 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 347 "/home/fengyong/Desktop/p4c/ir/base.def"
const IR::Annotations *IR::Annotations::append(const IR::Annotations* other) {
        if (other == nullptr)
            return this;
        for (auto a : other->annotations)
            add(a);
        return this;
    }
#line 896 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"


#line 356 "/home/fengyong/Desktop/p4c/ir/base.def"
const IR::Annotations *IR::Annotations::addOrReplace(cstring name, const IR::Expression* expr, bool structured) const {
        auto rv = clone();
        remove_if(rv->annotations, [name](const Annotation *a)->bool { return a->name == name; });
        rv->annotations.push_back(new Annotation(name, Vector<Expression>(expr), structured));
        return rv; }
#line 905 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 364 "/home/fengyong/Desktop/p4c/ir/base.def"
const IR::Annotations *IR::Annotations::where(Filter func) const {
        auto rv = empty->clone();
        std::copy_if(annotations.begin(), annotations.end(),
                     std::back_insert_iterator<Vector<Annotation>>(rv->annotations), func);
        if (rv->annotations.size() == annotations.size()) return this;
        return rv; }
#line 913 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 370 "/home/fengyong/Desktop/p4c/ir/base.def"
void IR::Annotations::validate() const {
#line 916 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        annotations.validate();
#line 370 "/home/fengyong/Desktop/p4c/ir/base.def"
{ annotations.check_null(); } }
#line 921 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 371 "/home/fengyong/Desktop/p4c/ir/base.def"
void IR::Annotations::dbprint(std::ostream & out) const { for (auto a : annotations) out << a << ' '; }
#line 924 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Annotations::operator==(IR::Annotations const & a) const {
        return typeid(*this) == typeid(a)
        && annotations == a.annotations;
    }
bool IR::Annotations::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const Annotations &>(a_);
        return annotations.equiv(a.annotations);
    }
void IR::Annotations::visit_children(Visitor & v) {
    Node::visit_children(v);
    annotations.visit_children(v);
}
void IR::Annotations::visit_children(Visitor & v) const {
    Node::visit_children(v);
    annotations.visit_children(v);
}
void IR::Annotations::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
}
IR::Annotations::Annotations(JSONLoader & json) : Node(json) {
    json.load("annotations", annotations);
}
IR::Node * IR::Annotations::fromJSON(JSONLoader & json) { return new Annotations(json); }
IR::Annotations::Annotations(Util::SourceInfo srcInfo, IR::Vector<IR::Annotation> annotations) :
    Node(srcInfo), annotations(annotations)
    {
#line 328 "/home/fengyong/Desktop/p4c/ir/base.def"
{ if (!srcInfo && !annotations.empty()) srcInfo = annotations[0]->srcInfo; }
#line 956 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Annotations::Annotations(IR::Vector<IR::Annotation> annotations) :
    annotations(annotations)
    {
#line 328 "/home/fengyong/Desktop/p4c/ir/base.def"
{ if (!srcInfo && !annotations.empty()) srcInfo = annotations[0]->srcInfo; }
#line 963 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Annotations::Annotations(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    {
#line 328 "/home/fengyong/Desktop/p4c/ir/base.def"
{ if (!srcInfo && !annotations.empty()) srcInfo = annotations[0]->srcInfo; }
#line 970 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Annotations::Annotations() 
    {
#line 328 "/home/fengyong/Desktop/p4c/ir/base.def"
{ if (!srcInfo && !annotations.empty()) srcInfo = annotations[0]->srcInfo; }
#line 976 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
#line 377 "/home/fengyong/Desktop/p4c/ir/base.def"
const IR::Annotation *IR::IAnnotated::getAnnotation(cstring name) const {
        return getAnnotations()->getSingle(name); }
#line 981 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
/// If an argument has no name the name.name is nullptr.
#line 393 "/home/fengyong/Desktop/p4c/ir/base.def"
void IR::Argument::dbprint(std::ostream & out) const { out << (name.name.isNullOrEmpty() ? "" : name.name + " = ") << expression; }
#line 985 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 394 "/home/fengyong/Desktop/p4c/ir/base.def"
void IR::Argument::validate() const {
#line 988 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(expression);
#line 394 "/home/fengyong/Desktop/p4c/ir/base.def"
{ CHECK_NULL(expression); } }
#line 993 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 395 "/home/fengyong/Desktop/p4c/ir/base.def"
cstring IR::Argument::toString() const {
        cstring result = "";
        if (!name.name.isNullOrEmpty())
            result = name.toString() + " = ";
        return result + expression->toString();
    }
#line 1001 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Argument::operator==(IR::Argument const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && expression == a.expression;
    }
bool IR::Argument::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const Argument &>(a_);
        return name == a.name
        && (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr);
    }
void IR::Argument::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(expression, "expression");
}
void IR::Argument::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(expression, "expression");
}
void IR::Argument::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
}
void IR::Argument::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"expression\" : " << this->expression;
}
IR::Argument::Argument(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("expression", expression);
}
IR::Node * IR::Argument::fromJSON(JSONLoader & json) { return new Argument(json); }
IR::Argument::Argument(Util::SourceInfo srcInfo, IR::ID name, const IR::Expression* expression) :
    Node(srcInfo), name(name), expression(expression)
    {
#line 392 "/home/fengyong/Desktop/p4c/ir/base.def"
{ if (!srcInfo && expression) srcInfo = expression->srcInfo; }
#line 1041 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Argument::Argument(IR::ID name, const IR::Expression* expression) :
    name(name), expression(expression)
    {
#line 392 "/home/fengyong/Desktop/p4c/ir/base.def"
{ if (!srcInfo && expression) srcInfo = expression->srcInfo; }
#line 1048 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Argument::Argument(Util::SourceInfo srcInfo, const IR::Expression* expression) :
    Node(srcInfo), expression(expression)
    {
#line 392 "/home/fengyong/Desktop/p4c/ir/base.def"
{ if (!srcInfo && expression) srcInfo = expression->srcInfo; }
#line 1055 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Argument::Argument(const IR::Expression* expression) :
    expression(expression)
    {
#line 392 "/home/fengyong/Desktop/p4c/ir/base.def"
{ if (!srcInfo && expression) srcInfo = expression->srcInfo; }
#line 1062 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
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
#line 74 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_Any::getVarName() const { return "int_" + Util::toString(declid); }
#line 1077 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 75 "/home/fengyong/Desktop/p4c/ir/type.def"
int IR::Type_Any::getDeclId() const { return declid; }
#line 1080 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 76 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Type_Any::dbprint(std::ostream & out) const { out << "ANYTYPE/" << declid; }
#line 1083 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 77 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_Any::toString() const { return "ANYTYPE"; }
#line 1086 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 78 "/home/fengyong/Desktop/p4c/ir/type.def"
bool IR::Type_Any::operator==(IR::Type_Any const & a) const { return declid == a.declid; }
#line 1089 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 80 "/home/fengyong/Desktop/p4c/ir/type.def"
IR::Type const * IR::Type_Any::getP4Type() const { return nullptr; }
#line 1092 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Any::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_Any &>(a_);
        return declid == a.declid;
    }
void IR::Type_Any::dump_fields(std::ostream & out) const {
    Type::dump_fields(out);
        out << " declid=" << declid;
}
void IR::Type_Any::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"declid\" : " << this->declid;
}
IR::Type_Any::Type_Any(JSONLoader & json) : Type(json) {
    json.load("declid", declid);
}
IR::Node * IR::Type_Any::fromJSON(JSONLoader & json) { return new Type_Any(json); }
IR::Type_Any::Type_Any(Util::SourceInfo srcInfo) :
    Type(srcInfo)
    { validate(); }
IR::Type_Any::Type_Any() 
    { validate(); }
#line 96 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Type_Fragment::dbprint(std::ostream & out) const { out << "FRAGMENT(" << type << ")"; }
#line 1118 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 97 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_Fragment::toString() const { return "FRAGMENT(" + type->toString() + ")"; }
#line 1121 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 98 "/home/fengyong/Desktop/p4c/ir/type.def"
IR::Type const * IR::Type_Fragment::getP4Type() const { return nullptr; }
#line 1124 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Fragment::operator==(IR::Type_Fragment const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && type == a.type;
    }
bool IR::Type_Fragment::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_Fragment &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr);
    }
void IR::Type_Fragment::visit_children(Visitor & v) {
    Type::visit_children(v);
    v.visit(type, "type");
}
void IR::Type_Fragment::visit_children(Visitor & v) const {
    Type::visit_children(v);
    v.visit(type, "type");
}
void IR::Type_Fragment::validate() const {
#line 1144 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(type); }
void IR::Type_Fragment::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
}
IR::Type_Fragment::Type_Fragment(JSONLoader & json) : Type(json) {
    json.load("type", type);
}
IR::Node * IR::Type_Fragment::fromJSON(JSONLoader & json) { return new Type_Fragment(json); }
IR::Type_Fragment::Type_Fragment(Util::SourceInfo srcInfo, const IR::Type* type) :
    Type(srcInfo), type(type)
    { validate(); }
IR::Type_Fragment::Type_Fragment(const IR::Type* type) :
    type(type)
    { validate(); }
#line 110 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_Type::toString() const { return "Type(" + type->toString() + ")"; }
#line 1163 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 111 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Type_Type::dbprint(std::ostream & out) const { out << "Type(" << type << ")"; }
#line 1166 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 112 "/home/fengyong/Desktop/p4c/ir/type.def"
IR::Type const * IR::Type_Type::getP4Type() const { return type; }
#line 1169 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 113 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Type_Type::validate() const {
#line 1172 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(type);
#line 113 "/home/fengyong/Desktop/p4c/ir/type.def"
{ BUG_CHECK(!type->is<IR::Type_Type>(), "%1%: nested Type_Type", type); } }
#line 1177 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Type::operator==(IR::Type_Type const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && type == a.type;
    }
bool IR::Type_Type::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_Type &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr);
    }
void IR::Type_Type::visit_children(Visitor & v) {
    Type::visit_children(v);
    v.visit(type, "type");
}
void IR::Type_Type::visit_children(Visitor & v) const {
    Type::visit_children(v);
    v.visit(type, "type");
}
void IR::Type_Type::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
}
IR::Type_Type::Type_Type(JSONLoader & json) : Type(json) {
    json.load("type", type);
}
IR::Node * IR::Type_Type::fromJSON(JSONLoader & json) { return new Type_Type(json); }
IR::Type_Type::Type_Type(Util::SourceInfo srcInfo, const IR::Type* type) :
    Type(srcInfo), type(type)
    { validate(); }
IR::Type_Type::Type_Type(const IR::Type* type) :
    type(type)
    { validate(); }
#line 118 "/home/fengyong/Desktop/p4c/ir/type.def"
int IR::Type_Boolean::width_bits() const { return 1; }
#line 1212 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 119 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_Boolean::toString() const { return "bool"; }
#line 1215 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 120 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Type_Boolean::dbprint(std::ostream & out) const { out << "bool"; }
#line 1218 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Boolean::operator==(IR::Type_Boolean const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Boolean::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Boolean::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Boolean::Type_Boolean(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Boolean::fromJSON(JSONLoader & json) { return new Type_Boolean(json); }
IR::Type_Boolean::Type_Boolean(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_Boolean::Type_Boolean() 
    { validate(); }
#line 126 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_State::toString() const { return "state"; }
#line 1240 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 127 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Type_State::dbprint(std::ostream & out) const { out << "state"; }
#line 1243 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_State::operator==(IR::Type_State const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_State::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_State::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_State::Type_State(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_State::fromJSON(JSONLoader & json) { return new Type_State(json); }
IR::Type_State::Type_State(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_State::Type_State() 
    { validate(); }


#line 137 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_Bits::baseName() const { return isSigned ? "int" : "bit"; }
#line 1267 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 138 "/home/fengyong/Desktop/p4c/ir/type.def"
int IR::Type_Bits::width_bits() const { return size; }
#line 1270 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 140 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_Bits::toString() const { return baseName() + "<" + Util::toString(size) + ">"; }
#line 1273 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 141 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Type_Bits::dbprint(std::ostream & out) const { out << toString(); }
#line 1276 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Bits::operator==(IR::Type_Bits const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a))
        && size == a.size
        && expression == a.expression
        && isSigned == a.isSigned;
    }
bool IR::Type_Bits::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        auto &a = static_cast<const Type_Bits &>(a_);
        return size == a.size
        && (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr)
        && isSigned == a.isSigned;
    }
void IR::Type_Bits::visit_children(Visitor & v) {
    Type_Base::visit_children(v);
    v.visit(expression, "expression");
}
void IR::Type_Bits::visit_children(Visitor & v) const {
    Type_Base::visit_children(v);
    v.visit(expression, "expression");
}
void IR::Type_Bits::dump_fields(std::ostream & out) const {
    Type_Base::dump_fields(out);
        out << " size=" << size;
        out << " isSigned=" << isSigned;
}
void IR::Type_Bits::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
    json << "," << std::endl << json.indent << "\"size\" : " << this->size;
    if (expression != nullptr)     json << "," << std::endl << json.indent << "\"expression\" : " << this->expression;
    json << "," << std::endl << json.indent << "\"isSigned\" : " << this->isSigned;
}
IR::Type_Bits::Type_Bits(JSONLoader & json) : Type_Base(json) {
    json.load("size", size);
    json.load("expression", expression);
    json.load("isSigned", isSigned);
}
IR::Node * IR::Type_Bits::fromJSON(JSONLoader & json) { return new Type_Bits(json); }
IR::Type_Bits::Type_Bits(Util::SourceInfo srcInfo, int size, const IR::Expression* expression, bool isSigned) :
    Type_Base(srcInfo), size(size), expression(expression), isSigned(isSigned)
    { validate(); }
IR::Type_Bits::Type_Bits(int size, const IR::Expression* expression, bool isSigned) :
    size(size), expression(expression), isSigned(isSigned)
    { validate(); }
IR::Type_Bits::Type_Bits(Util::SourceInfo srcInfo, const IR::Expression* expression, bool isSigned) :
    Type_Base(srcInfo), expression(expression), isSigned(isSigned)
    { validate(); }
IR::Type_Bits::Type_Bits(const IR::Expression* expression, bool isSigned) :
    expression(expression), isSigned(isSigned)
    { validate(); }
IR::Type_Bits::Type_Bits(Util::SourceInfo srcInfo, int size, bool isSigned) :
    Type_Base(srcInfo), size(size), isSigned(isSigned)
    { validate(); }
IR::Type_Bits::Type_Bits(int size, bool isSigned) :
    size(size), isSigned(isSigned)
    { validate(); }
IR::Type_Bits::Type_Bits(Util::SourceInfo srcInfo, bool isSigned) :
    Type_Base(srcInfo), isSigned(isSigned)
    { validate(); }
IR::Type_Bits::Type_Bits(bool isSigned) :
    isSigned(isSigned)
    { validate(); }


#line 149 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_Varbits::toString() const { return cstring("varbit<") + Util::toString(size) + ">"; }
#line 1344 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 150 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Type_Varbits::dbprint(std::ostream & out) const { out << "varbit<" << size << ">"; }
#line 1347 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Varbits::operator==(IR::Type_Varbits const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a))
        && size == a.size
        && expression == a.expression;
    }
bool IR::Type_Varbits::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        auto &a = static_cast<const Type_Varbits &>(a_);
        return size == a.size
        && (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr);
    }
void IR::Type_Varbits::visit_children(Visitor & v) {
    Type_Base::visit_children(v);
    v.visit(expression, "expression");
}
void IR::Type_Varbits::visit_children(Visitor & v) const {
    Type_Base::visit_children(v);
    v.visit(expression, "expression");
}
void IR::Type_Varbits::dump_fields(std::ostream & out) const {
    Type_Base::dump_fields(out);
        out << " size=" << size;
}
void IR::Type_Varbits::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
    json << "," << std::endl << json.indent << "\"size\" : " << this->size;
    if (expression != nullptr)     json << "," << std::endl << json.indent << "\"expression\" : " << this->expression;
}
IR::Type_Varbits::Type_Varbits(JSONLoader & json) : Type_Base(json) {
    json.load("size", size);
    json.load("expression", expression);
}
IR::Node * IR::Type_Varbits::fromJSON(JSONLoader & json) { return new Type_Varbits(json); }
IR::Type_Varbits::Type_Varbits(Util::SourceInfo srcInfo, int size, const IR::Expression* expression) :
    Type_Base(srcInfo), size(size), expression(expression)
    { validate(); }
IR::Type_Varbits::Type_Varbits(int size, const IR::Expression* expression) :
    size(size), expression(expression)
    { validate(); }
IR::Type_Varbits::Type_Varbits(Util::SourceInfo srcInfo, const IR::Expression* expression) :
    Type_Base(srcInfo), expression(expression)
    { validate(); }
IR::Type_Varbits::Type_Varbits(const IR::Expression* expression) :
    expression(expression)
    { validate(); }
IR::Type_Varbits::Type_Varbits(Util::SourceInfo srcInfo, int size) :
    Type_Base(srcInfo), size(size)
    { validate(); }
IR::Type_Varbits::Type_Varbits(int size) :
    size(size)
    { validate(); }
IR::Type_Varbits::Type_Varbits(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_Varbits::Type_Varbits() 
    { validate(); }
#line 158 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::Annotations *IR::Parameter::getAnnotations() const { return annotations; }
#line 1407 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 159 "/home/fengyong/Desktop/p4c/ir/type.def"
bool IR::Parameter::hasOut() const { return direction == IR::Direction::Out || direction == IR::Direction::InOut; }
#line 1410 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 161 "/home/fengyong/Desktop/p4c/ir/type.def"
bool IR::Parameter::isOptional() const {
        return getAnnotation(Annotation::optionalAnnotation) != nullptr; }
#line 1414 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 163 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Parameter::dbprint(std::ostream & out) const { out << annotations << direction << (direction != IR::Direction::None ? " " : "")
                  << type << ' ' << name; }
#line 1418 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Parameter::operator==(IR::Parameter const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && direction == a.direction
        && type == a.type
        && defaultValue == a.defaultValue;
    }
bool IR::Parameter::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Parameter &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && direction == a.direction
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (defaultValue ? a.defaultValue ? defaultValue->equiv(*a.defaultValue) : false : a.defaultValue == nullptr);
    }
void IR::Parameter::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
    v.visit(defaultValue, "defaultValue");
}
void IR::Parameter::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
    v.visit(defaultValue, "defaultValue");
}
void IR::Parameter::validate() const {
#line 1448 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(type); }
void IR::Parameter::dump_fields(std::ostream & out) const {
    Declaration::dump_fields(out);
        out << " direction=" << direction;
}
void IR::Parameter::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"direction\" : " << this->direction;
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
    if (defaultValue != nullptr)     json << "," << std::endl << json.indent << "\"defaultValue\" : " << this->defaultValue;
}
IR::Parameter::Parameter(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("direction", direction);
    json.load("type", type);
    json.load("defaultValue", defaultValue);
}
IR::Node * IR::Parameter::fromJSON(JSONLoader & json) { return new Parameter(json); }
IR::Parameter::Parameter(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, Direction direction, const IR::Type* type, const IR::Expression* defaultValue) :
    Declaration(srcInfo, name), annotations(annotations), direction(direction), type(type), defaultValue(defaultValue)
    { validate(); }
IR::Parameter::Parameter(IR::ID name, const IR::Annotations* annotations, Direction direction, const IR::Type* type, const IR::Expression* defaultValue) :
    Declaration(name), annotations(annotations), direction(direction), type(type), defaultValue(defaultValue)
    { validate(); }
IR::Parameter::Parameter(Util::SourceInfo srcInfo, IR::ID name, Direction direction, const IR::Type* type, const IR::Expression* defaultValue) :
    Declaration(srcInfo, name), direction(direction), type(type), defaultValue(defaultValue)
    { validate(); }
IR::Parameter::Parameter(IR::ID name, Direction direction, const IR::Type* type, const IR::Expression* defaultValue) :
    Declaration(name), direction(direction), type(type), defaultValue(defaultValue)
    { validate(); }
IR::Parameter::Parameter(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, Direction direction, const IR::Type* type) :
    Declaration(srcInfo, name), annotations(annotations), direction(direction), type(type)
    { validate(); }
IR::Parameter::Parameter(IR::ID name, const IR::Annotations* annotations, Direction direction, const IR::Type* type) :
    Declaration(name), annotations(annotations), direction(direction), type(type)
    { validate(); }
IR::Parameter::Parameter(Util::SourceInfo srcInfo, IR::ID name, Direction direction, const IR::Type* type) :
    Declaration(srcInfo, name), direction(direction), type(type)
    { validate(); }
IR::Parameter::Parameter(IR::ID name, Direction direction, const IR::Type* type) :
    Declaration(name), direction(direction), type(type)
    { validate(); }
#line 169 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::ParameterList::validate() const {
#line 1496 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        parameters.validate();
#line 169 "/home/fengyong/Desktop/p4c/ir/type.def"
{ parameters.check_null(); } }
#line 1501 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 170 "/home/fengyong/Desktop/p4c/ir/type.def"
Util::Enumerator<const IR::Parameter *> * IR::ParameterList::getEnumerator() const {
        return parameters.getEnumerator(); }
#line 1505 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 172 "/home/fengyong/Desktop/p4c/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::ParameterList::getDeclarations() const {
        return parameters.getDeclarations(); }
#line 1509 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 174 "/home/fengyong/Desktop/p4c/ir/type.def"
size_t IR::ParameterList::size() const { return parameters.size(); }
#line 1512 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 175 "/home/fengyong/Desktop/p4c/ir/type.def"
bool IR::ParameterList::empty() const { return size() == 0; }
#line 1515 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 176 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::Parameter *IR::ParameterList::getParameter(cstring name) const {
        return parameters.getDeclaration<Parameter>(name); }
#line 1519 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 178 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::Parameter *IR::ParameterList::getParameter(unsigned index) const {
        for (auto &param : parameters)
            if (0 == index--) return param;
        BUG("Only %1% parameters; index #%2% requested", size(), size()+index); }
#line 1525 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 182 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::IDeclaration *IR::ParameterList::getDeclByName(cstring name) const { return getParameter(name); }
#line 1528 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 183 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::ParameterList::push_back(IR::Parameter const * p) { parameters.push_back(p); }
#line 1531 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 184 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::ParameterList::toString() const {
        cstring result = "";
        bool first = true;
        for (auto p : parameters) {
            if (!first)
                result += ", ";
            first = false;
            result += p->toString();
        }
        return result;
    }
#line 1544 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::ParameterList::operator==(IR::ParameterList const & a) const {
        return typeid(*this) == typeid(a)
        && parameters == a.parameters;
    }
bool IR::ParameterList::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const ParameterList &>(a_);
        return parameters.equiv(a.parameters);
    }
void IR::ParameterList::visit_children(Visitor & v) {
    Node::visit_children(v);
    parameters.visit_children(v);
}
void IR::ParameterList::visit_children(Visitor & v) const {
    Node::visit_children(v);
    parameters.visit_children(v);
}
void IR::ParameterList::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"parameters\" : " << this->parameters;
}
IR::ParameterList::ParameterList(JSONLoader & json) : Node(json) {
    json.load("parameters", parameters);
}
IR::Node * IR::ParameterList::fromJSON(JSONLoader & json) { return new ParameterList(json); }
IR::ParameterList::ParameterList(Util::SourceInfo srcInfo, IR::IndexedVector<IR::Parameter> parameters) :
    Node(srcInfo), parameters(parameters)
    { validate(); }
IR::ParameterList::ParameterList(IR::IndexedVector<IR::Parameter> parameters) :
    parameters(parameters)
    { validate(); }
IR::ParameterList::ParameterList(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::ParameterList::ParameterList() 
    { validate(); }
#line 203 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_Var::getVarName() const { return getName(); }
#line 1584 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 204 "/home/fengyong/Desktop/p4c/ir/type.def"
int IR::Type_Var::getDeclId() const { return declid; }
#line 1587 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 205 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Type_Var::dbprint(std::ostream & out) const { out << name << "/" << getDeclId(); }
#line 1590 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 206 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_Var::toString() const { return getName().toString(); }
#line 1593 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Var::operator==(IR::Type_Var const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a));
    }
bool IR::Type_Var::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        return true;
    }
void IR::Type_Var::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
}
IR::Type_Var::Type_Var(JSONLoader & json) : Type_Declaration(json) {
}
IR::Node * IR::Type_Var::fromJSON(JSONLoader & json) { return new Type_Var(json); }
IR::Type_Var::Type_Var(Util::SourceInfo srcInfo, IR::ID name) :
    Type_Declaration(srcInfo, name)
    { validate(); }
IR::Type_Var::Type_Var(IR::ID name) :
    Type_Declaration(name)
    { validate(); }
#line 218 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_InfInt::getVarName() const { return "int_" + Util::toString(declid); }
#line 1616 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 219 "/home/fengyong/Desktop/p4c/ir/type.def"
int IR::Type_InfInt::getDeclId() const { return declid; }
#line 1619 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 220 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Type_InfInt::dbprint(std::ostream & out) const { out << "int/" << declid; }
#line 1622 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 221 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_InfInt::toString() const { return "int"; }
#line 1625 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 222 "/home/fengyong/Desktop/p4c/ir/type.def"
bool IR::Type_InfInt::operator==(IR::Type_InfInt const & a) const { return declid == a.declid; }
#line 1628 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 223 "/home/fengyong/Desktop/p4c/ir/type.def"
bool IR::Type_InfInt::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_InfInt &>(a_);

#line 223 "/home/fengyong/Desktop/p4c/ir/type.def"
{
        (void)a;  // silence unused warning
        return true; /* ignore declid */
    }    }
#line 1640 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 227 "/home/fengyong/Desktop/p4c/ir/type.def"
IR::Type const * IR::Type_InfInt::getP4Type() const { return this; }
#line 1643 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
void IR::Type_InfInt::dump_fields(std::ostream & out) const {
    Type::dump_fields(out);
        out << " declid=" << declid;
}
void IR::Type_InfInt::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"declid\" : " << this->declid;
}
IR::Type_InfInt::Type_InfInt(JSONLoader & json) : Type(json) {
    json.load("declid", declid);
}
IR::Node * IR::Type_InfInt::fromJSON(JSONLoader & json) { return new Type_InfInt(json); }
IR::Type_InfInt::Type_InfInt(Util::SourceInfo srcInfo) :
    Type(srcInfo)
    { validate(); }
IR::Type_InfInt::Type_InfInt() 
    { validate(); }
#line 231 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_Dontcare::toString() const { return "_"; }
#line 1663 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 233 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Type_Dontcare::dbprint(std::ostream & out) const { out << "_"; }
#line 1666 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Dontcare::operator==(IR::Type_Dontcare const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Dontcare::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Dontcare::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Dontcare::Type_Dontcare(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Dontcare::fromJSON(JSONLoader & json) { return new Type_Dontcare(json); }
IR::Type_Dontcare::Type_Dontcare(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_Dontcare::Type_Dontcare() 
    { validate(); }
#line 237 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_Void::toString() const { return "void"; }
#line 1688 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 239 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Type_Void::dbprint(std::ostream & out) const { out << "void"; }
#line 1691 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Void::operator==(IR::Type_Void const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Void::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Void::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Void::Type_Void(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Void::fromJSON(JSONLoader & json) { return new Type_Void(json); }
IR::Type_Void::Type_Void(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_Void::Type_Void() 
    { validate(); }
#line 243 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_MatchKind::toString() const { return "match_kind"; }
#line 1713 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 245 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Type_MatchKind::dbprint(std::ostream & out) const { out << "match_kind"; }
#line 1716 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_MatchKind::operator==(IR::Type_MatchKind const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_MatchKind::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_MatchKind::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_MatchKind::Type_MatchKind(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_MatchKind::fromJSON(JSONLoader & json) { return new Type_MatchKind(json); }
IR::Type_MatchKind::Type_MatchKind(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_MatchKind::Type_MatchKind() 
    { validate(); }
#line 250 "/home/fengyong/Desktop/p4c/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::TypeParameters::getDeclarations() const {
        return parameters.getDeclarations(); }
#line 1739 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 252 "/home/fengyong/Desktop/p4c/ir/type.def"
bool IR::TypeParameters::empty() const { return parameters.empty(); }
#line 1742 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 253 "/home/fengyong/Desktop/p4c/ir/type.def"
size_t IR::TypeParameters::size() const { return parameters.size(); }
#line 1745 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 254 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::IDeclaration *IR::TypeParameters::getDeclByName(cstring name) const {
        return parameters.getDeclaration(name); }
#line 1749 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 256 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::TypeParameters::push_back(const IR::Type_Var* tv) { parameters.push_back(tv); }
#line 1752 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 257 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::TypeParameters::validate() const {
#line 1755 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        parameters.validate();
#line 257 "/home/fengyong/Desktop/p4c/ir/type.def"
{ parameters.check_null(); } }
#line 1760 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 258 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::TypeParameters::toString() const {
        if (parameters.size() == 0)
            return "";
        cstring result = "<";
        bool first = true;
        for (auto p : parameters) {
            if (!first)
                result += ", ";
            first = false;
            result += p->toString();
        }
        result += ">";
        return result;
    }
#line 1776 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::TypeParameters::operator==(IR::TypeParameters const & a) const {
        return typeid(*this) == typeid(a)
        && parameters == a.parameters;
    }
bool IR::TypeParameters::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const TypeParameters &>(a_);
        return parameters.equiv(a.parameters);
    }
void IR::TypeParameters::visit_children(Visitor & v) {
    Node::visit_children(v);
    parameters.visit_children(v);
}
void IR::TypeParameters::visit_children(Visitor & v) const {
    Node::visit_children(v);
    parameters.visit_children(v);
}
void IR::TypeParameters::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"parameters\" : " << this->parameters;
}
IR::TypeParameters::TypeParameters(JSONLoader & json) : Node(json) {
    json.load("parameters", parameters);
}
IR::Node * IR::TypeParameters::fromJSON(JSONLoader & json) { return new TypeParameters(json); }
IR::TypeParameters::TypeParameters(Util::SourceInfo srcInfo, IR::IndexedVector<IR::Type_Var> parameters) :
    Node(srcInfo), parameters(parameters)
    { validate(); }
IR::TypeParameters::TypeParameters(IR::IndexedVector<IR::Type_Var> parameters) :
    parameters(parameters)
    { validate(); }
IR::TypeParameters::TypeParameters(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::TypeParameters::TypeParameters() 
    { validate(); }
#line 277 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::Annotations *IR::StructField::getAnnotations() const { return annotations; }
#line 1816 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::StructField::operator==(IR::StructField const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && type == a.type;
    }
bool IR::StructField::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const StructField &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr);
    }
void IR::StructField::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
}
void IR::StructField::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
}
void IR::StructField::validate() const {
#line 1840 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(type); }
void IR::StructField::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
}
IR::StructField::StructField(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("type", type);
}
IR::Node * IR::StructField::fromJSON(JSONLoader & json) { return new StructField(json); }
IR::StructField::StructField(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type) :
    Declaration(srcInfo, name), annotations(annotations), type(type)
    { validate(); }
IR::StructField::StructField(IR::ID name, const IR::Annotations* annotations, const IR::Type* type) :
    Declaration(name), annotations(annotations), type(type)
    { validate(); }
IR::StructField::StructField(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type) :
    Declaration(srcInfo, name), type(type)
    { validate(); }
IR::StructField::StructField(IR::ID name, const IR::Type* type) :
    Declaration(name), type(type)
    { validate(); }
#line 284 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::TypeParameters *IR::Type_StructLike::getTypeParameters() const { return typeParameters; }
#line 1868 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 285 "/home/fengyong/Desktop/p4c/ir/type.def"
std::vector<const IR::INamespace *> IR::Type_StructLike::getNestedNamespaces() const { return { typeParameters }; }
#line 1871 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 286 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::Annotations *IR::Type_StructLike::getAnnotations() const { return annotations; }
#line 1874 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 287 "/home/fengyong/Desktop/p4c/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Type_StructLike::getDeclarations() const {
        return fields.getDeclarations(); }
#line 1878 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 289 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::StructField *IR::Type_StructLike::getField(cstring name) const {
        return fields.getDeclaration<StructField>(name); }
#line 1882 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 291 "/home/fengyong/Desktop/p4c/ir/type.def"
int IR::Type_StructLike::getFieldIndex(cstring name) const {
        int index_pos = 0;
        for (auto f : fields) {
            if (f->name == name)
                return index_pos;
	    index_pos++;
        }
        return -1;
    }
#line 1893 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
/// This function returns start offset of the given field name in bits.
/// If the given name is not a valid field name, -1 is returned.
/// The given offset may not be correct if varbit field(s) present in between.
/// Offset for all fields will be correct if:
///  - the type has only fixed width fields
///  - the type has fixed width fields with only one varbit field as a last member.
#line 306 "/home/fengyong/Desktop/p4c/ir/type.def"
int IR::Type_StructLike::getFieldBitOffset(cstring name) const {
        int offset = 0;
        for (auto f : fields) {
            if (f->name == name) {
                return offset;
            }
            offset += f->type->width_bits();
        }
        return -1;
    }
#line 1911 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 316 "/home/fengyong/Desktop/p4c/ir/type.def"
int IR::Type_StructLike::width_bits() const {
        int rv = 0;
        for (auto f : fields) {
            rv += f->type->width_bits();
        }
        return rv; }
#line 1919 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 322 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::IDeclaration *IR::Type_StructLike::getDeclByName(cstring name) const {
        return fields.getDeclaration(name); }
#line 1923 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 324 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Type_StructLike::validate() const {
#line 1926 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(typeParameters);
        fields.validate();
#line 324 "/home/fengyong/Desktop/p4c/ir/type.def"
{ fields.check_null(); } }
#line 1933 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
IRNODE_DEFINE_APPLY_OVERLOAD(Type_StructLike, , )
bool IR::Type_StructLike::operator==(IR::Type_StructLike const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && annotations == a.annotations
        && typeParameters == a.typeParameters
        && fields == a.fields;
    }
bool IR::Type_StructLike::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Type_StructLike &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (typeParameters ? a.typeParameters ? typeParameters->equiv(*a.typeParameters) : false : a.typeParameters == nullptr)
        && fields.equiv(a.fields);
    }
void IR::Type_StructLike::visit_children(Visitor & v) {
    Type_Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(typeParameters, "typeParameters");
    fields.visit_children(v);
}
void IR::Type_StructLike::visit_children(Visitor & v) const {
    Type_Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(typeParameters, "typeParameters");
    fields.visit_children(v);
}
void IR::Type_StructLike::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"typeParameters\" : " << this->typeParameters;
    json << "," << std::endl << json.indent << "\"fields\" : " << this->fields;
}
IR::Type_StructLike::Type_StructLike(JSONLoader & json) : Type_Declaration(json) {
    json.load("annotations", annotations);
    json.load("typeParameters", typeParameters);
    json.load("fields", fields);
}
IR::Type_StructLike::Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Declaration(srcInfo, name), annotations(annotations), typeParameters(typeParameters), fields(fields)
    { validate(); }
IR::Type_StructLike::Type_StructLike(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Declaration(name), annotations(annotations), typeParameters(typeParameters), fields(fields)
    { validate(); }
IR::Type_StructLike::Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters), fields(fields)
    { validate(); }
IR::Type_StructLike::Type_StructLike(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Declaration(name), typeParameters(typeParameters), fields(fields)
    { validate(); }
IR::Type_StructLike::Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_Declaration(srcInfo, name), annotations(annotations), fields(fields)
    { validate(); }
IR::Type_StructLike::Type_StructLike(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_Declaration(name), annotations(annotations), fields(fields)
    { validate(); }
IR::Type_StructLike::Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_Declaration(srcInfo, name), fields(fields)
    { validate(); }
IR::Type_StructLike::Type_StructLike(IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_Declaration(name), fields(fields)
    { validate(); }
IR::Type_StructLike::Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_Declaration(srcInfo, name), annotations(annotations), typeParameters(typeParameters)
    { validate(); }
IR::Type_StructLike::Type_StructLike(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_Declaration(name), annotations(annotations), typeParameters(typeParameters)
    { validate(); }
IR::Type_StructLike::Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters)
    { validate(); }
IR::Type_StructLike::Type_StructLike(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Declaration(name), typeParameters(typeParameters)
    { validate(); }
IR::Type_StructLike::Type_StructLike(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Type_Declaration(srcInfo, name), annotations(annotations)
    { validate(); }
IR::Type_StructLike::Type_StructLike(IR::ID name, const IR::Annotations* annotations) :
    Type_Declaration(name), annotations(annotations)
    { validate(); }
IR::Type_StructLike::Type_StructLike(Util::SourceInfo srcInfo, IR::ID name) :
    Type_Declaration(srcInfo, name)
    { validate(); }
IR::Type_StructLike::Type_StructLike(IR::ID name) :
    Type_Declaration(name)
    { validate(); }
#line 331 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_Struct::toString() const { return cstring("struct ") + externalName(); }
#line 2022 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Struct::operator==(IR::Type_Struct const & a) const {
        return Type_StructLike::operator==(static_cast<const Type_StructLike &>(a));
    }
bool IR::Type_Struct::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_StructLike::equiv(a_)) return false;
        return true;
    }
void IR::Type_Struct::toJSON(JSONGenerator & json) const {
    Type_StructLike::toJSON(json);
}
IR::Type_Struct::Type_Struct(JSONLoader & json) : Type_StructLike(json) {
}
IR::Node * IR::Type_Struct::fromJSON(JSONLoader & json) { return new Type_Struct(json); }
IR::Type_Struct::Type_Struct(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, annotations, typeParameters, fields)
    { validate(); }
IR::Type_Struct::Type_Struct(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, annotations, typeParameters, fields)
    { validate(); }
IR::Type_Struct::Type_Struct(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, typeParameters, fields)
    { validate(); }
IR::Type_Struct::Type_Struct(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, typeParameters, fields)
    { validate(); }
IR::Type_Struct::Type_Struct(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, annotations, fields)
    { validate(); }
IR::Type_Struct::Type_Struct(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, annotations, fields)
    { validate(); }
IR::Type_Struct::Type_Struct(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, fields)
    { validate(); }
IR::Type_Struct::Type_Struct(IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, fields)
    { validate(); }
IR::Type_Struct::Type_Struct(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_StructLike(srcInfo, name, annotations, typeParameters)
    { validate(); }
IR::Type_Struct::Type_Struct(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_StructLike(name, annotations, typeParameters)
    { validate(); }
IR::Type_Struct::Type_Struct(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_StructLike(srcInfo, name, typeParameters)
    { validate(); }
IR::Type_Struct::Type_Struct(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_StructLike(name, typeParameters)
    { validate(); }
IR::Type_Struct::Type_Struct(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Type_StructLike(srcInfo, name, annotations)
    { validate(); }
IR::Type_Struct::Type_Struct(IR::ID name, const IR::Annotations* annotations) :
    Type_StructLike(name, annotations)
    { validate(); }
IR::Type_Struct::Type_Struct(Util::SourceInfo srcInfo, IR::ID name) :
    Type_StructLike(srcInfo, name)
    { validate(); }
IR::Type_Struct::Type_Struct(IR::ID name) :
    Type_StructLike(name)
    { validate(); }
bool IR::Type_UnknownStruct::operator==(IR::Type_UnknownStruct const & a) const {
        return Type_StructLike::operator==(static_cast<const Type_StructLike &>(a));
    }
bool IR::Type_UnknownStruct::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_StructLike::equiv(a_)) return false;
        return true;
    }
void IR::Type_UnknownStruct::toJSON(JSONGenerator & json) const {
    Type_StructLike::toJSON(json);
}
IR::Type_UnknownStruct::Type_UnknownStruct(JSONLoader & json) : Type_StructLike(json) {
}
IR::Node * IR::Type_UnknownStruct::fromJSON(JSONLoader & json) { return new Type_UnknownStruct(json); }
IR::Type_UnknownStruct::Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, annotations, typeParameters, fields)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, annotations, typeParameters, fields)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, typeParameters, fields)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, typeParameters, fields)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, annotations, fields)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, annotations, fields)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, fields)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, fields)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_StructLike(srcInfo, name, annotations, typeParameters)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_StructLike(name, annotations, typeParameters)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_StructLike(srcInfo, name, typeParameters)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_StructLike(name, typeParameters)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Type_StructLike(srcInfo, name, annotations)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(IR::ID name, const IR::Annotations* annotations) :
    Type_StructLike(name, annotations)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(Util::SourceInfo srcInfo, IR::ID name) :
    Type_StructLike(srcInfo, name)
    { validate(); }
IR::Type_UnknownStruct::Type_UnknownStruct(IR::ID name) :
    Type_StructLike(name)
    { validate(); }
#line 343 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_HeaderUnion::toString() const { return cstring("header_union ") + externalName(); }
#line 2149 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

#line 345 "/home/fengyong/Desktop/p4c/ir/type.def"
int IR::Type_HeaderUnion::width_bits() const {
        int rv = 0;
        for (auto f : fields)
            rv = std::max(rv, f->type->width_bits());
        return rv; }
#line 2157 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
/// start offset of any field in a union is 0
#line 351 "/home/fengyong/Desktop/p4c/ir/type.def"
int IR::Type_HeaderUnion::getFieldBitOffset(cstring name) const {
        for (auto f : fields) {
            if (f->name == name) {
                return 0;
            }
        }
        return -1; }
#line 2167 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_HeaderUnion::operator==(IR::Type_HeaderUnion const & a) const {
        return Type_StructLike::operator==(static_cast<const Type_StructLike &>(a));
    }
bool IR::Type_HeaderUnion::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_StructLike::equiv(a_)) return false;
        return true;
    }
void IR::Type_HeaderUnion::toJSON(JSONGenerator & json) const {
    Type_StructLike::toJSON(json);
}
IR::Type_HeaderUnion::Type_HeaderUnion(JSONLoader & json) : Type_StructLike(json) {
}
IR::Node * IR::Type_HeaderUnion::fromJSON(JSONLoader & json) { return new Type_HeaderUnion(json); }
IR::Type_HeaderUnion::Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, annotations, typeParameters, fields)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, annotations, typeParameters, fields)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, typeParameters, fields)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, typeParameters, fields)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, annotations, fields)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, annotations, fields)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, fields)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, fields)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_StructLike(srcInfo, name, annotations, typeParameters)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_StructLike(name, annotations, typeParameters)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_StructLike(srcInfo, name, typeParameters)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_StructLike(name, typeParameters)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Type_StructLike(srcInfo, name, annotations)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(IR::ID name, const IR::Annotations* annotations) :
    Type_StructLike(name, annotations)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(Util::SourceInfo srcInfo, IR::ID name) :
    Type_StructLike(srcInfo, name)
    { validate(); }
IR::Type_HeaderUnion::Type_HeaderUnion(IR::ID name) :
    Type_StructLike(name)
    { validate(); }
#line 365 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_Header::toString() const { return cstring("header ") + externalName(); }
#line 2232 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Header::operator==(IR::Type_Header const & a) const {
        return Type_StructLike::operator==(static_cast<const Type_StructLike &>(a));
    }
bool IR::Type_Header::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_StructLike::equiv(a_)) return false;
        return true;
    }
void IR::Type_Header::toJSON(JSONGenerator & json) const {
    Type_StructLike::toJSON(json);
}
IR::Type_Header::Type_Header(JSONLoader & json) : Type_StructLike(json) {
}
IR::Node * IR::Type_Header::fromJSON(JSONLoader & json) { return new Type_Header(json); }
IR::Type_Header::Type_Header(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, annotations, typeParameters, fields)
    { validate(); }
IR::Type_Header::Type_Header(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, annotations, typeParameters, fields)
    { validate(); }
IR::Type_Header::Type_Header(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, typeParameters, fields)
    { validate(); }
IR::Type_Header::Type_Header(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, typeParameters, fields)
    { validate(); }
IR::Type_Header::Type_Header(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, annotations, fields)
    { validate(); }
IR::Type_Header::Type_Header(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, annotations, fields)
    { validate(); }
IR::Type_Header::Type_Header(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(srcInfo, name, fields)
    { validate(); }
IR::Type_Header::Type_Header(IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_StructLike(name, fields)
    { validate(); }
IR::Type_Header::Type_Header(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_StructLike(srcInfo, name, annotations, typeParameters)
    { validate(); }
IR::Type_Header::Type_Header(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_StructLike(name, annotations, typeParameters)
    { validate(); }
IR::Type_Header::Type_Header(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_StructLike(srcInfo, name, typeParameters)
    { validate(); }
IR::Type_Header::Type_Header(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_StructLike(name, typeParameters)
    { validate(); }
IR::Type_Header::Type_Header(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Type_StructLike(srcInfo, name, annotations)
    { validate(); }
IR::Type_Header::Type_Header(IR::ID name, const IR::Annotations* annotations) :
    Type_StructLike(name, annotations)
    { validate(); }
IR::Type_Header::Type_Header(Util::SourceInfo srcInfo, IR::ID name) :
    Type_StructLike(srcInfo, name)
    { validate(); }
IR::Type_Header::Type_Header(IR::ID name) :
    Type_StructLike(name)
    { validate(); }
#line 370 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Type_Set::dbprint(std::ostream & out) const { Node::dbprint(out); out << "<" << elementType << ">"; }
#line 2297 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 371 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_Set::toString() const { return cstring("set<") + elementType->toString() + ">"; }
#line 2300 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 372 "/home/fengyong/Desktop/p4c/ir/type.def"
IR::Type const * IR::Type_Set::getP4Type() const { return nullptr; }
#line 2303 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 373 "/home/fengyong/Desktop/p4c/ir/type.def"
int IR::Type_Set::width_bits() const {
        /// returning the width of the set elements, not the set itself, which doesn't
        /// really have a sensible size
        return elementType->width_bits(); }
#line 2309 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Set::operator==(IR::Type_Set const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && elementType == a.elementType;
    }
bool IR::Type_Set::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_Set &>(a_);
        return (elementType ? a.elementType ? elementType->equiv(*a.elementType) : false : a.elementType == nullptr);
    }
void IR::Type_Set::visit_children(Visitor & v) {
    Type::visit_children(v);
    v.visit(elementType, "elementType");
}
void IR::Type_Set::visit_children(Visitor & v) const {
    Type::visit_children(v);
    v.visit(elementType, "elementType");
}
void IR::Type_Set::validate() const {
#line 2329 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(elementType); }
void IR::Type_Set::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"elementType\" : " << this->elementType;
}
IR::Type_Set::Type_Set(JSONLoader & json) : Type(json) {
    json.load("elementType", elementType);
}
IR::Node * IR::Type_Set::fromJSON(JSONLoader & json) { return new Type_Set(json); }
IR::Type_Set::Type_Set(Util::SourceInfo srcInfo, const IR::Type* elementType) :
    Type(srcInfo), elementType(elementType)
    { validate(); }
IR::Type_Set::Type_Set(const IR::Type* elementType) :
    elementType(elementType)
    { validate(); }


#line 389 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Type_BaseList::validate() const {
#line 2350 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        components.validate();
#line 389 "/home/fengyong/Desktop/p4c/ir/type.def"
{ components.check_null(); } }
#line 2355 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 390 "/home/fengyong/Desktop/p4c/ir/type.def"
size_t IR::Type_BaseList::getSize() const { return components.size(); }
#line 2358 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 391 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::Type *IR::Type_BaseList::at(size_t index) const { return components.at(index); }
#line 2361 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 392 "/home/fengyong/Desktop/p4c/ir/type.def"
int IR::Type_BaseList::width_bits() const {
        /// returning sum of the width of the elements
        int rv = 0;
        for (auto f : components) {
            rv += f->width_bits();
        }
        return rv; }
#line 2370 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 399 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_BaseList::asString(char const * name) const {
        std::string result = name;
        result += "<";
        bool first = true;
        for (auto t : components) {
            if (!first)
                result += ", ";
            first = false;
            result += t->toString();
        }
        return result + ">";
    }
#line 2384 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 411 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_BaseList::toString() const {
        return asString("baselist");
    }
#line 2389 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_BaseList::operator==(IR::Type_BaseList const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && components == a.components;
    }
bool IR::Type_BaseList::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_BaseList &>(a_);
        return components.equiv(a.components);
    }
void IR::Type_BaseList::visit_children(Visitor & v) {
    Type::visit_children(v);
    components.visit_children(v);
}
void IR::Type_BaseList::visit_children(Visitor & v) const {
    Type::visit_children(v);
    components.visit_children(v);
}
void IR::Type_BaseList::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"components\" : " << this->components;
}
IR::Type_BaseList::Type_BaseList(JSONLoader & json) : Type(json) {
    json.load("components", components);
}
IR::Type_BaseList::Type_BaseList(Util::SourceInfo srcInfo, IR::Vector<IR::Type> components) :
    Type(srcInfo), components(components)
    { validate(); }
IR::Type_BaseList::Type_BaseList(IR::Vector<IR::Type> components) :
    components(components)
    { validate(); }
IR::Type_BaseList::Type_BaseList(Util::SourceInfo srcInfo) :
    Type(srcInfo)
    { validate(); }
IR::Type_BaseList::Type_BaseList() 
    { validate(); }

#line 420 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_List::toString() const {
        return asString("tuple");
    }
#line 2431 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_List::operator==(IR::Type_List const & a) const {
        return Type_BaseList::operator==(static_cast<const Type_BaseList &>(a));
    }
bool IR::Type_List::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_BaseList::equiv(a_)) return false;
        return true;
    }
void IR::Type_List::toJSON(JSONGenerator & json) const {
    Type_BaseList::toJSON(json);
}
IR::Type_List::Type_List(JSONLoader & json) : Type_BaseList(json) {
}
IR::Node * IR::Type_List::fromJSON(JSONLoader & json) { return new Type_List(json); }
IR::Type_List::Type_List(Util::SourceInfo srcInfo, IR::Vector<IR::Type> components) :
    Type_BaseList(srcInfo, components)
    { validate(); }
IR::Type_List::Type_List(IR::Vector<IR::Type> components) :
    Type_BaseList(components)
    { validate(); }
IR::Type_List::Type_List(Util::SourceInfo srcInfo) :
    Type_BaseList(srcInfo)
    { validate(); }
IR::Type_List::Type_List() 
    { validate(); }
#line 428 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_Tuple::toString() const {
        return asString("tuple");
    }
#line 2461 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Tuple::operator==(IR::Type_Tuple const & a) const {
        return Type_BaseList::operator==(static_cast<const Type_BaseList &>(a));
    }
bool IR::Type_Tuple::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_BaseList::equiv(a_)) return false;
        return true;
    }
void IR::Type_Tuple::toJSON(JSONGenerator & json) const {
    Type_BaseList::toJSON(json);
}
IR::Type_Tuple::Type_Tuple(JSONLoader & json) : Type_BaseList(json) {
}
IR::Node * IR::Type_Tuple::fromJSON(JSONLoader & json) { return new Type_Tuple(json); }
IR::Type_Tuple::Type_Tuple(Util::SourceInfo srcInfo, IR::Vector<IR::Type> components) :
    Type_BaseList(srcInfo, components)
    { validate(); }
IR::Type_Tuple::Type_Tuple(IR::Vector<IR::Type> components) :
    Type_BaseList(components)
    { validate(); }
IR::Type_Tuple::Type_Tuple(Util::SourceInfo srcInfo) :
    Type_BaseList(srcInfo)
    { validate(); }
IR::Type_Tuple::Type_Tuple() 
    { validate(); }
#line 437 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_P4List::toString() const {
        std::string result = "list<" + elementType->toString() + ">";
        return result;
    }
#line 2492 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_P4List::operator==(IR::Type_P4List const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && elementType == a.elementType;
    }
bool IR::Type_P4List::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_P4List &>(a_);
        return (elementType ? a.elementType ? elementType->equiv(*a.elementType) : false : a.elementType == nullptr);
    }
void IR::Type_P4List::visit_children(Visitor & v) {
    Type::visit_children(v);
    v.visit(elementType, "elementType");
}
void IR::Type_P4List::visit_children(Visitor & v) const {
    Type::visit_children(v);
    v.visit(elementType, "elementType");
}
void IR::Type_P4List::validate() const {
#line 2512 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(elementType); }
void IR::Type_P4List::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"elementType\" : " << this->elementType;
}
IR::Type_P4List::Type_P4List(JSONLoader & json) : Type(json) {
    json.load("elementType", elementType);
}
IR::Node * IR::Type_P4List::fromJSON(JSONLoader & json) { return new Type_P4List(json); }
IR::Type_P4List::Type_P4List(Util::SourceInfo srcInfo, const IR::Type* elementType) :
    Type(srcInfo), elementType(elementType)
    { validate(); }
IR::Type_P4List::Type_P4List(const IR::Type* elementType) :
    elementType(elementType)
    { validate(); }
#line 448 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::Annotations *IR::Type_ArchBlock::getAnnotations() const { return annotations; }
#line 2531 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 449 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::TypeParameters *IR::Type_ArchBlock::getTypeParameters() const { return typeParameters; }
#line 2534 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 450 "/home/fengyong/Desktop/p4c/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Type_ArchBlock::getDeclarations() const {
        return typeParameters->getDeclarations(); }
#line 2538 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 452 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::IDeclaration *IR::Type_ArchBlock::getDeclByName(cstring name) const {
        return typeParameters->getDeclByName(name); }
#line 2542 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_ArchBlock::operator==(IR::Type_ArchBlock const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && annotations == a.annotations
        && typeParameters == a.typeParameters;
    }
bool IR::Type_ArchBlock::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Type_ArchBlock &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (typeParameters ? a.typeParameters ? typeParameters->equiv(*a.typeParameters) : false : a.typeParameters == nullptr);
    }
void IR::Type_ArchBlock::visit_children(Visitor & v) {
    Type_Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(typeParameters, "typeParameters");
}
void IR::Type_ArchBlock::visit_children(Visitor & v) const {
    Type_Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(typeParameters, "typeParameters");
}
void IR::Type_ArchBlock::validate() const {
#line 2566 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(typeParameters); }
void IR::Type_ArchBlock::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"typeParameters\" : " << this->typeParameters;
}
IR::Type_ArchBlock::Type_ArchBlock(JSONLoader & json) : Type_Declaration(json) {
    json.load("annotations", annotations);
    json.load("typeParameters", typeParameters);
}
IR::Type_ArchBlock::Type_ArchBlock(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_Declaration(srcInfo, name), annotations(annotations), typeParameters(typeParameters)
    { validate(); }
IR::Type_ArchBlock::Type_ArchBlock(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_Declaration(name), annotations(annotations), typeParameters(typeParameters)
    { validate(); }
IR::Type_ArchBlock::Type_ArchBlock(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters)
    { validate(); }
IR::Type_ArchBlock::Type_ArchBlock(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Declaration(name), typeParameters(typeParameters)
    { validate(); }
IR::Type_ArchBlock::Type_ArchBlock(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Type_Declaration(srcInfo, name), annotations(annotations)
    { validate(); }
IR::Type_ArchBlock::Type_ArchBlock(IR::ID name, const IR::Annotations* annotations) :
    Type_Declaration(name), annotations(annotations)
    { validate(); }
IR::Type_ArchBlock::Type_ArchBlock(Util::SourceInfo srcInfo, IR::ID name) :
    Type_Declaration(srcInfo, name)
    { validate(); }
IR::Type_ArchBlock::Type_ArchBlock(IR::ID name) :
    Type_Declaration(name)
    { validate(); }
#line 457 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::Type *IR::Type_Package::getType() const { return this; }
#line 2605 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 460 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::ParameterList *IR::Type_Package::getConstructorParameters() const { return constructorParams; }
#line 2608 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 461 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_Package::toString() const { return cstring("package ") + externalName(); }
#line 2611 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 462 "/home/fengyong/Desktop/p4c/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Type_Package::getDeclarations() const {
        return typeParameters->getDeclarations()->concat(constructorParams->getDeclarations()); }
#line 2615 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 464 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::IDeclaration *IR::Type_Package::getDeclByName(cstring name) const {
        auto decl = constructorParams->getDeclByName(name);
        if (!decl) decl = typeParameters->getDeclByName(name);
        return decl; }
#line 2621 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Package::operator==(IR::Type_Package const & a) const {
        return Type_ArchBlock::operator==(static_cast<const Type_ArchBlock &>(a))
        && constructorParams == a.constructorParams;
    }
bool IR::Type_Package::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_ArchBlock::equiv(a_)) return false;
        auto &a = static_cast<const Type_Package &>(a_);
        return (constructorParams ? a.constructorParams ? constructorParams->equiv(*a.constructorParams) : false : a.constructorParams == nullptr);
    }
void IR::Type_Package::visit_children(Visitor & v) {
    Type_ArchBlock::visit_children(v);
    v.visit(constructorParams, "constructorParams");
}
void IR::Type_Package::visit_children(Visitor & v) const {
    Type_ArchBlock::visit_children(v);
    v.visit(constructorParams, "constructorParams");
}
void IR::Type_Package::validate() const {
#line 2641 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(constructorParams); }
void IR::Type_Package::toJSON(JSONGenerator & json) const {
    Type_ArchBlock::toJSON(json);
    json << "," << std::endl << json.indent << "\"constructorParams\" : " << this->constructorParams;
}
IR::Type_Package::Type_Package(JSONLoader & json) : Type_ArchBlock(json) {
    json.load("constructorParams", constructorParams);
}
IR::Node * IR::Type_Package::fromJSON(JSONLoader & json) { return new Type_Package(json); }
IR::Type_Package::Type_Package(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, const IR::ParameterList* constructorParams) :
    Type_ArchBlock(srcInfo, name, annotations, typeParameters), constructorParams(constructorParams)
    { validate(); }
IR::Type_Package::Type_Package(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, const IR::ParameterList* constructorParams) :
    Type_ArchBlock(name, annotations, typeParameters), constructorParams(constructorParams)
    { validate(); }
IR::Type_Package::Type_Package(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, const IR::ParameterList* constructorParams) :
    Type_ArchBlock(srcInfo, name, typeParameters), constructorParams(constructorParams)
    { validate(); }
IR::Type_Package::Type_Package(IR::ID name, const IR::TypeParameters* typeParameters, const IR::ParameterList* constructorParams) :
    Type_ArchBlock(name, typeParameters), constructorParams(constructorParams)
    { validate(); }
IR::Type_Package::Type_Package(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::ParameterList* constructorParams) :
    Type_ArchBlock(srcInfo, name, annotations), constructorParams(constructorParams)
    { validate(); }
IR::Type_Package::Type_Package(IR::ID name, const IR::Annotations* annotations, const IR::ParameterList* constructorParams) :
    Type_ArchBlock(name, annotations), constructorParams(constructorParams)
    { validate(); }
IR::Type_Package::Type_Package(Util::SourceInfo srcInfo, IR::ID name, const IR::ParameterList* constructorParams) :
    Type_ArchBlock(srcInfo, name), constructorParams(constructorParams)
    { validate(); }
IR::Type_Package::Type_Package(IR::ID name, const IR::ParameterList* constructorParams) :
    Type_ArchBlock(name), constructorParams(constructorParams)
    { validate(); }
#line 473 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::ParameterList *IR::Type_Parser::getApplyParameters() const { return applyParams; }
#line 2678 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 474 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_Parser::toString() const { return cstring("parser ") + externalName(); }
#line 2681 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Parser::operator==(IR::Type_Parser const & a) const {
        return Type_ArchBlock::operator==(static_cast<const Type_ArchBlock &>(a))
        && applyParams == a.applyParams;
    }
bool IR::Type_Parser::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_ArchBlock::equiv(a_)) return false;
        auto &a = static_cast<const Type_Parser &>(a_);
        return (applyParams ? a.applyParams ? applyParams->equiv(*a.applyParams) : false : a.applyParams == nullptr);
    }
void IR::Type_Parser::visit_children(Visitor & v) {
    Type_ArchBlock::visit_children(v);
    v.visit(applyParams, "applyParams");
}
void IR::Type_Parser::visit_children(Visitor & v) const {
    Type_ArchBlock::visit_children(v);
    v.visit(applyParams, "applyParams");
}
void IR::Type_Parser::validate() const {
#line 2701 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(applyParams); }
void IR::Type_Parser::toJSON(JSONGenerator & json) const {
    Type_ArchBlock::toJSON(json);
    json << "," << std::endl << json.indent << "\"applyParams\" : " << this->applyParams;
}
IR::Type_Parser::Type_Parser(JSONLoader & json) : Type_ArchBlock(json) {
    json.load("applyParams", applyParams);
}
IR::Node * IR::Type_Parser::fromJSON(JSONLoader & json) { return new Type_Parser(json); }
IR::Type_Parser::Type_Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams) :
    Type_ArchBlock(srcInfo, name, annotations, typeParameters), applyParams(applyParams)
    { validate(); }
IR::Type_Parser::Type_Parser(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams) :
    Type_ArchBlock(name, annotations, typeParameters), applyParams(applyParams)
    { validate(); }
IR::Type_Parser::Type_Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams) :
    Type_ArchBlock(srcInfo, name, typeParameters), applyParams(applyParams)
    { validate(); }
IR::Type_Parser::Type_Parser(IR::ID name, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams) :
    Type_ArchBlock(name, typeParameters), applyParams(applyParams)
    { validate(); }
IR::Type_Parser::Type_Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::ParameterList* applyParams) :
    Type_ArchBlock(srcInfo, name, annotations), applyParams(applyParams)
    { validate(); }
IR::Type_Parser::Type_Parser(IR::ID name, const IR::Annotations* annotations, const IR::ParameterList* applyParams) :
    Type_ArchBlock(name, annotations), applyParams(applyParams)
    { validate(); }
IR::Type_Parser::Type_Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::ParameterList* applyParams) :
    Type_ArchBlock(srcInfo, name), applyParams(applyParams)
    { validate(); }
IR::Type_Parser::Type_Parser(IR::ID name, const IR::ParameterList* applyParams) :
    Type_ArchBlock(name), applyParams(applyParams)
    { validate(); }
#line 480 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::ParameterList *IR::Type_Control::getApplyParameters() const { return applyParams; }
#line 2738 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 481 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_Control::toString() const { return cstring("control ") + externalName(); }
#line 2741 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Control::operator==(IR::Type_Control const & a) const {
        return Type_ArchBlock::operator==(static_cast<const Type_ArchBlock &>(a))
        && applyParams == a.applyParams;
    }
bool IR::Type_Control::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_ArchBlock::equiv(a_)) return false;
        auto &a = static_cast<const Type_Control &>(a_);
        return (applyParams ? a.applyParams ? applyParams->equiv(*a.applyParams) : false : a.applyParams == nullptr);
    }
void IR::Type_Control::visit_children(Visitor & v) {
    Type_ArchBlock::visit_children(v);
    v.visit(applyParams, "applyParams");
}
void IR::Type_Control::visit_children(Visitor & v) const {
    Type_ArchBlock::visit_children(v);
    v.visit(applyParams, "applyParams");
}
void IR::Type_Control::validate() const {
#line 2761 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(applyParams); }
void IR::Type_Control::toJSON(JSONGenerator & json) const {
    Type_ArchBlock::toJSON(json);
    json << "," << std::endl << json.indent << "\"applyParams\" : " << this->applyParams;
}
IR::Type_Control::Type_Control(JSONLoader & json) : Type_ArchBlock(json) {
    json.load("applyParams", applyParams);
}
IR::Node * IR::Type_Control::fromJSON(JSONLoader & json) { return new Type_Control(json); }
IR::Type_Control::Type_Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams) :
    Type_ArchBlock(srcInfo, name, annotations, typeParameters), applyParams(applyParams)
    { validate(); }
IR::Type_Control::Type_Control(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams) :
    Type_ArchBlock(name, annotations, typeParameters), applyParams(applyParams)
    { validate(); }
IR::Type_Control::Type_Control(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams) :
    Type_ArchBlock(srcInfo, name, typeParameters), applyParams(applyParams)
    { validate(); }
IR::Type_Control::Type_Control(IR::ID name, const IR::TypeParameters* typeParameters, const IR::ParameterList* applyParams) :
    Type_ArchBlock(name, typeParameters), applyParams(applyParams)
    { validate(); }
IR::Type_Control::Type_Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::ParameterList* applyParams) :
    Type_ArchBlock(srcInfo, name, annotations), applyParams(applyParams)
    { validate(); }
IR::Type_Control::Type_Control(IR::ID name, const IR::Annotations* annotations, const IR::ParameterList* applyParams) :
    Type_ArchBlock(name, annotations), applyParams(applyParams)
    { validate(); }
IR::Type_Control::Type_Control(Util::SourceInfo srcInfo, IR::ID name, const IR::ParameterList* applyParams) :
    Type_ArchBlock(srcInfo, name), applyParams(applyParams)
    { validate(); }
IR::Type_Control::Type_Control(IR::ID name, const IR::ParameterList* applyParams) :
    Type_ArchBlock(name), applyParams(applyParams)
    { validate(); }
#line 487 "/home/fengyong/Desktop/p4c/ir/type.def"
IR::Type_Name::Type_Name(IR::ID id) : Type(id.srcInfo), path(new IR::Path(id)) {}
#line 2798 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 488 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_Name::toString() const { return path->name; }
#line 2801 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 489 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Type_Name::dbprint(std::ostream & out) const { out << path->toString(); }
#line 2804 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 490 "/home/fengyong/Desktop/p4c/ir/type.def"
IR::Type const * IR::Type_Name::getP4Type() const { return this; }
#line 2807 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 491 "/home/fengyong/Desktop/p4c/ir/type.def"
int IR::Type_Name::width_bits() const {
        BUG("Type_Name is not a canonical type, use getTypeType()?");
        return 0;
    }
#line 2813 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Name::operator==(IR::Type_Name const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && path == a.path;
    }
bool IR::Type_Name::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_Name &>(a_);
        return (path ? a.path ? path->equiv(*a.path) : false : a.path == nullptr);
    }
void IR::Type_Name::visit_children(Visitor & v) {
    Type::visit_children(v);
    v.visit(path, "path");
}
void IR::Type_Name::visit_children(Visitor & v) const {
    Type::visit_children(v);
    v.visit(path, "path");
}
void IR::Type_Name::validate() const {
#line 2833 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(path); }
void IR::Type_Name::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"path\" : " << this->path;
}
IR::Type_Name::Type_Name(JSONLoader & json) : Type(json) {
    json.load("path", path);
}
IR::Node * IR::Type_Name::fromJSON(JSONLoader & json) { return new Type_Name(json); }
IR::Type_Name::Type_Name(Util::SourceInfo srcInfo, const IR::Path* path) :
    Type(srcInfo), path(path)
    { validate(); }
IR::Type_Name::Type_Name(const IR::Path* path) :
    path(path)
    { validate(); }
#line 500 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_Stack::toString() const { return elementType->toString() + "[" +
                (sizeKnown() ? Util::toString(getSize()) : "?") + "]"; }
#line 2853 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 502 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Type_Stack::dbprint(std::ostream & out) const { out << elementType << "[" << size << "]"; }
#line 2856 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 512 "/home/fengyong/Desktop/p4c/ir/type.def"
IR::Type const * IR::Type_Stack::getP4Type() const { return new IR::Type_Stack(srcInfo, elementType->getP4Type(), size); }
#line 2859 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Stack::operator==(IR::Type_Stack const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && elementType == a.elementType
        && size == a.size;
    }
bool IR::Type_Stack::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_Stack &>(a_);
        return (elementType ? a.elementType ? elementType->equiv(*a.elementType) : false : a.elementType == nullptr)
        && (size ? a.size ? size->equiv(*a.size) : false : a.size == nullptr);
    }
void IR::Type_Stack::visit_children(Visitor & v) {
    Type::visit_children(v);
    v.visit(elementType, "elementType");
    v.visit(size, "size");
}
void IR::Type_Stack::visit_children(Visitor & v) const {
    Type::visit_children(v);
    v.visit(elementType, "elementType");
    v.visit(size, "size");
}
void IR::Type_Stack::validate() const {
#line 2883 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(elementType);
        CHECK_NULL(size); }
void IR::Type_Stack::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"elementType\" : " << this->elementType;
    json << "," << std::endl << json.indent << "\"size\" : " << this->size;
}
IR::Type_Stack::Type_Stack(JSONLoader & json) : Type(json) {
    json.load("elementType", elementType);
    json.load("size", size);
}
IR::Node * IR::Type_Stack::fromJSON(JSONLoader & json) { return new Type_Stack(json); }
IR::Type_Stack::Type_Stack(Util::SourceInfo srcInfo, const IR::Type* elementType, const IR::Expression* size) :
    Type(srcInfo), elementType(elementType), size(size)
    { validate(); }
IR::Type_Stack::Type_Stack(const IR::Type* elementType, const IR::Expression* size) :
    elementType(elementType), size(size)
    { validate(); }
#line 524 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Type_Specialized::validate() const {
#line 2905 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(baseType);
        CHECK_NULL(arguments);
#line 524 "/home/fengyong/Desktop/p4c/ir/type.def"
{ arguments->check_null(); } }
#line 2911 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 526 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_Specialized::toString() const {
        cstring result = baseType->toString() + "<";
        cstring sep = "";
        for (auto t : *arguments) {
            result += sep + t->toString();
            sep = ", ";
        }
        result += ">";
        return result;
    }
#line 2923 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 536 "/home/fengyong/Desktop/p4c/ir/type.def"
IR::Type_Specialized::Type_Specialized(cstring bt, std::initializer_list<const IR::Type *> args) : baseType(new Type_Name(bt)), arguments(new Vector<Type>(args)) {}
#line 2926 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Specialized::operator==(IR::Type_Specialized const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && baseType == a.baseType
        && arguments == a.arguments;
    }
bool IR::Type_Specialized::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_Specialized &>(a_);
        return (baseType ? a.baseType ? baseType->equiv(*a.baseType) : false : a.baseType == nullptr)
        && (arguments ? a.arguments ? arguments->equiv(*a.arguments) : false : a.arguments == nullptr);
    }
void IR::Type_Specialized::visit_children(Visitor & v) {
    Type::visit_children(v);
    v.visit(baseType, "baseType");
    v.visit(arguments, "arguments");
}
void IR::Type_Specialized::visit_children(Visitor & v) const {
    Type::visit_children(v);
    v.visit(baseType, "baseType");
    v.visit(arguments, "arguments");
}
void IR::Type_Specialized::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"baseType\" : " << this->baseType;
    json << "," << std::endl << json.indent << "\"arguments\" : " << this->arguments;
}
IR::Type_Specialized::Type_Specialized(JSONLoader & json) : Type(json) {
    json.load("baseType", baseType);
    json.load("arguments", arguments);
}
IR::Node * IR::Type_Specialized::fromJSON(JSONLoader & json) { return new Type_Specialized(json); }
IR::Type_Specialized::Type_Specialized(Util::SourceInfo srcInfo, const IR::Type_Name* baseType, const IR::Vector<IR::Type>* arguments) :
    Type(srcInfo), baseType(baseType), arguments(arguments)
    { validate(); }
IR::Type_Specialized::Type_Specialized(const IR::Type_Name* baseType, const IR::Vector<IR::Type>* arguments) :
    baseType(baseType), arguments(arguments)
    { validate(); }
/// canonical baseType; always IMayBeGenericType
/// canonical type arguments
/// 'substituted' is baseType with all type
/// variables substituted with the arguments.

#line 549 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Type_SpecializedCanonical::validate() const {
#line 2972 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(baseType);
        CHECK_NULL(arguments);
        CHECK_NULL(substituted);
#line 549 "/home/fengyong/Desktop/p4c/ir/type.def"
{
        arguments->check_null();
        BUG_CHECK(baseType->is<IMayBeGenericType>(), "base type %1% is not generic", baseType);
        BUG_CHECK(substituted->is<IMayBeGenericType>(), "substituted %1% is not generic", substituted);
    } }
#line 2983 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 555 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_SpecializedCanonical::toString() const { return baseType->toString() + "<...>"; }
#line 2986 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_SpecializedCanonical::operator==(IR::Type_SpecializedCanonical const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && baseType == a.baseType
        && arguments == a.arguments
        && substituted == a.substituted;
    }
bool IR::Type_SpecializedCanonical::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_SpecializedCanonical &>(a_);
        return (baseType ? a.baseType ? baseType->equiv(*a.baseType) : false : a.baseType == nullptr)
        && (arguments ? a.arguments ? arguments->equiv(*a.arguments) : false : a.arguments == nullptr)
        && (substituted ? a.substituted ? substituted->equiv(*a.substituted) : false : a.substituted == nullptr);
    }
void IR::Type_SpecializedCanonical::visit_children(Visitor & v) {
    Type::visit_children(v);
    v.visit(baseType, "baseType");
    v.visit(arguments, "arguments");
    v.visit(substituted, "substituted");
}
void IR::Type_SpecializedCanonical::visit_children(Visitor & v) const {
    Type::visit_children(v);
    v.visit(baseType, "baseType");
    v.visit(arguments, "arguments");
    v.visit(substituted, "substituted");
}
void IR::Type_SpecializedCanonical::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"baseType\" : " << this->baseType;
    json << "," << std::endl << json.indent << "\"arguments\" : " << this->arguments;
    json << "," << std::endl << json.indent << "\"substituted\" : " << this->substituted;
}
IR::Type_SpecializedCanonical::Type_SpecializedCanonical(JSONLoader & json) : Type(json) {
    json.load("baseType", baseType);
    json.load("arguments", arguments);
    json.load("substituted", substituted);
}
IR::Node * IR::Type_SpecializedCanonical::fromJSON(JSONLoader & json) { return new Type_SpecializedCanonical(json); }
IR::Type_SpecializedCanonical::Type_SpecializedCanonical(Util::SourceInfo srcInfo, const IR::Type* baseType, const IR::Vector<IR::Type>* arguments, const IR::Type* substituted) :
    Type(srcInfo), baseType(baseType), arguments(arguments), substituted(substituted)
    { validate(); }
IR::Type_SpecializedCanonical::Type_SpecializedCanonical(const IR::Type* baseType, const IR::Vector<IR::Type>* arguments, const IR::Type* substituted) :
    baseType(baseType), arguments(arguments), substituted(substituted)
    { validate(); }
bool IR::Declaration_ID::operator==(IR::Declaration_ID const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a));
    }
bool IR::Declaration_ID::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        return true;
    }
void IR::Declaration_ID::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
}
IR::Declaration_ID::Declaration_ID(JSONLoader & json) : Declaration(json) {
}
IR::Node * IR::Declaration_ID::fromJSON(JSONLoader & json) { return new Declaration_ID(json); }
IR::Declaration_ID::Declaration_ID(Util::SourceInfo srcInfo, IR::ID name) :
    Declaration(srcInfo, name)
    { validate(); }
IR::Declaration_ID::Declaration_ID(IR::ID name) :
    Declaration(name)
    { validate(); }
#line 567 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_String::toString() const { return "string"; }
#line 3053 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_String::operator==(IR::Type_String const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_String::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_String::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_String::Type_String(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_String::fromJSON(JSONLoader & json) { return new Type_String(json); }
IR::Type_String::Type_String(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_String::Type_String() 
    { validate(); }
#line 573 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::Annotations *IR::Type_Enum::getAnnotations() const { return annotations; }
#line 3075 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 574 "/home/fengyong/Desktop/p4c/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Type_Enum::getDeclarations() const {
        return members.getDeclarations(); }
#line 3079 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 576 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::IDeclaration *IR::Type_Enum::getDeclByName(cstring name) const {
        return members.getDeclaration(name); }
#line 3083 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 579 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Type_Enum::validate() const {
#line 3086 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        members.validate();
#line 579 "/home/fengyong/Desktop/p4c/ir/type.def"
{ members.check_null(); } }
#line 3092 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Enum::operator==(IR::Type_Enum const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && annotations == a.annotations
        && members == a.members;
    }
bool IR::Type_Enum::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Type_Enum &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && members.equiv(a.members);
    }
void IR::Type_Enum::visit_children(Visitor & v) {
    Type_Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    members.visit_children(v);
}
void IR::Type_Enum::visit_children(Visitor & v) const {
    Type_Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    members.visit_children(v);
}
void IR::Type_Enum::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"members\" : " << this->members;
}
IR::Type_Enum::Type_Enum(JSONLoader & json) : Type_Declaration(json) {
    json.load("annotations", annotations);
    json.load("members", members);
}
IR::Node * IR::Type_Enum::fromJSON(JSONLoader & json) { return new Type_Enum(json); }
IR::Type_Enum::Type_Enum(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::Declaration_ID> members) :
    Type_Declaration(srcInfo, name), annotations(annotations), members(members)
    { validate(); }
IR::Type_Enum::Type_Enum(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::Declaration_ID> members) :
    Type_Declaration(name), annotations(annotations), members(members)
    { validate(); }
IR::Type_Enum::Type_Enum(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::Declaration_ID> members) :
    Type_Declaration(srcInfo, name), members(members)
    { validate(); }
IR::Type_Enum::Type_Enum(IR::ID name, IR::IndexedVector<IR::Declaration_ID> members) :
    Type_Declaration(name), members(members)
    { validate(); }
#line 585 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::SerEnumMember::validate() const {
#line 3139 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(value);
#line 585 "/home/fengyong/Desktop/p4c/ir/type.def"
{ CHECK_NULL(value); } }
#line 3144 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::SerEnumMember::operator==(IR::SerEnumMember const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && value == a.value;
    }
bool IR::SerEnumMember::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const SerEnumMember &>(a_);
        return (value ? a.value ? value->equiv(*a.value) : false : a.value == nullptr);
    }
void IR::SerEnumMember::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(value, "value");
}
void IR::SerEnumMember::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(value, "value");
}
void IR::SerEnumMember::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"value\" : " << this->value;
}
IR::SerEnumMember::SerEnumMember(JSONLoader & json) : Declaration(json) {
    json.load("value", value);
}
IR::Node * IR::SerEnumMember::fromJSON(JSONLoader & json) { return new SerEnumMember(json); }
IR::SerEnumMember::SerEnumMember(Util::SourceInfo srcInfo, IR::ID name, const IR::Expression* value) :
    Declaration(srcInfo, name), value(value)
    { validate(); }
IR::SerEnumMember::SerEnumMember(IR::ID name, const IR::Expression* value) :
    Declaration(name), value(value)
    { validate(); }
#line 594 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::Annotations *IR::Type_SerEnum::getAnnotations() const { return annotations; }
#line 3179 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 595 "/home/fengyong/Desktop/p4c/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Type_SerEnum::getDeclarations() const {
        return members.getDeclarations(); }
#line 3183 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 597 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::IDeclaration *IR::Type_SerEnum::getDeclByName(cstring name) const {
        return members.getDeclaration(name); }
#line 3187 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 600 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Type_SerEnum::validate() const {
#line 3190 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(type);
        members.validate();
#line 600 "/home/fengyong/Desktop/p4c/ir/type.def"
{ members.check_null(); } }
#line 3197 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_SerEnum::operator==(IR::Type_SerEnum const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && annotations == a.annotations
        && type == a.type
        && members == a.members;
    }
bool IR::Type_SerEnum::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Type_SerEnum &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && members.equiv(a.members);
    }
void IR::Type_SerEnum::visit_children(Visitor & v) {
    Type_Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
    members.visit_children(v);
}
void IR::Type_SerEnum::visit_children(Visitor & v) const {
    Type_Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
    members.visit_children(v);
}
void IR::Type_SerEnum::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
    json << "," << std::endl << json.indent << "\"members\" : " << this->members;
}
IR::Type_SerEnum::Type_SerEnum(JSONLoader & json) : Type_Declaration(json) {
    json.load("annotations", annotations);
    json.load("type", type);
    json.load("members", members);
}
IR::Node * IR::Type_SerEnum::fromJSON(JSONLoader & json) { return new Type_SerEnum(json); }
IR::Type_SerEnum::Type_SerEnum(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type, IR::IndexedVector<IR::SerEnumMember> members) :
    Type_Declaration(srcInfo, name), annotations(annotations), type(type), members(members)
    { validate(); }
IR::Type_SerEnum::Type_SerEnum(IR::ID name, const IR::Annotations* annotations, const IR::Type* type, IR::IndexedVector<IR::SerEnumMember> members) :
    Type_Declaration(name), annotations(annotations), type(type), members(members)
    { validate(); }
IR::Type_SerEnum::Type_SerEnum(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type, IR::IndexedVector<IR::SerEnumMember> members) :
    Type_Declaration(srcInfo, name), type(type), members(members)
    { validate(); }
IR::Type_SerEnum::Type_SerEnum(IR::ID name, const IR::Type* type, IR::IndexedVector<IR::SerEnumMember> members) :
    Type_Declaration(name), type(type), members(members)
    { validate(); }
#line 606 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::ParameterList *IR::Type_Table::getApplyParameters() const { return new ParameterList(); }
#line 3250 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
/// names for the fields of the struct returned
/// by applying a table
#line 612 "/home/fengyong/Desktop/p4c/ir/type.def"
IR::Type const * IR::Type_Table::getP4Type() const { return nullptr; }
#line 3255 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 613 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Type_Table::dbprint(std::ostream & out) const { out << table->name; }
#line 3258 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Table::operator==(IR::Type_Table const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && table == a.table;
    }
bool IR::Type_Table::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_Table &>(a_);
        return (table ? a.table ? table->equiv(*a.table) : false : a.table == nullptr);
    }
void IR::Type_Table::visit_children(Visitor & v) {
    Type::visit_children(v);
    v.visit(table, "table");
}
void IR::Type_Table::visit_children(Visitor & v) const {
    Type::visit_children(v);
    v.visit(table, "table");
}
void IR::Type_Table::validate() const {
#line 3278 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(table); }
void IR::Type_Table::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"table\" : " << this->table;
}
IR::Type_Table::Type_Table(JSONLoader & json) : Type(json) {
    json.load("table", table);
}
IR::Node * IR::Type_Table::fromJSON(JSONLoader & json) { return new Type_Table(json); }
IR::Type_Table::Type_Table(Util::SourceInfo srcInfo, const IR::P4Table* table) :
    Type(srcInfo), table(table)
    { validate(); }
IR::Type_Table::Type_Table(const IR::P4Table* table) :
    table(table)
    { validate(); }
#line 622 "/home/fengyong/Desktop/p4c/ir/type.def"
IR::Type const * IR::Type_ActionEnum::getP4Type() const { return nullptr; }
#line 3297 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_ActionEnum::operator==(IR::Type_ActionEnum const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && actionList == a.actionList;
    }
bool IR::Type_ActionEnum::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_ActionEnum &>(a_);
        return (actionList ? a.actionList ? actionList->equiv(*a.actionList) : false : a.actionList == nullptr);
    }
void IR::Type_ActionEnum::visit_children(Visitor & v) {
    Type::visit_children(v);
    v.visit(actionList, "actionList");
}
void IR::Type_ActionEnum::visit_children(Visitor & v) const {
    Type::visit_children(v);
    v.visit(actionList, "actionList");
}
void IR::Type_ActionEnum::validate() const {
#line 3317 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(actionList); }
void IR::Type_ActionEnum::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"actionList\" : " << this->actionList;
}
IR::Type_ActionEnum::Type_ActionEnum(JSONLoader & json) : Type(json) {
    json.load("actionList", actionList);
}
IR::Node * IR::Type_ActionEnum::fromJSON(JSONLoader & json) { return new Type_ActionEnum(json); }
IR::Type_ActionEnum::Type_ActionEnum(Util::SourceInfo srcInfo, const IR::ActionList* actionList) :
    Type(srcInfo), actionList(actionList)
    { validate(); }
IR::Type_ActionEnum::Type_ActionEnum(const IR::ActionList* actionList) :
    actionList(actionList)
    { validate(); }


#line 632 "/home/fengyong/Desktop/p4c/ir/type.def"
size_t IR::Type_MethodBase::maxParameterCount() const { return parameters->size(); }
#line 3338 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 634 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::TypeParameters *IR::Type_MethodBase::getTypeParameters() const { return typeParameters; }
#line 3341 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 636 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_MethodBase::toString() const { return "<Method>"; }
#line 3344 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 637 "/home/fengyong/Desktop/p4c/ir/type.def"
IR::Type const * IR::Type_MethodBase::getP4Type() const { return nullptr; }
#line 3347 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 638 "/home/fengyong/Desktop/p4c/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Type_MethodBase::getDeclarations() const {
        return typeParameters->getDeclarations()->concat(parameters->getDeclarations()); }
#line 3351 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 640 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::IDeclaration *IR::Type_MethodBase::getDeclByName(cstring name) const {
        auto decl = parameters->getDeclByName(name);
        if (!decl) decl = typeParameters->getDeclByName(name);
        return decl; }
#line 3357 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_MethodBase::operator==(IR::Type_MethodBase const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && typeParameters == a.typeParameters
        && returnType == a.returnType
        && parameters == a.parameters;
    }
bool IR::Type_MethodBase::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_MethodBase &>(a_);
        return (typeParameters ? a.typeParameters ? typeParameters->equiv(*a.typeParameters) : false : a.typeParameters == nullptr)
        && (returnType ? a.returnType ? returnType->equiv(*a.returnType) : false : a.returnType == nullptr)
        && (parameters ? a.parameters ? parameters->equiv(*a.parameters) : false : a.parameters == nullptr);
    }
void IR::Type_MethodBase::visit_children(Visitor & v) {
    Type::visit_children(v);
    v.visit(typeParameters, "typeParameters");
    v.visit(returnType, "returnType");
    v.visit(parameters, "parameters");
}
void IR::Type_MethodBase::visit_children(Visitor & v) const {
    Type::visit_children(v);
    v.visit(typeParameters, "typeParameters");
    v.visit(returnType, "returnType");
    v.visit(parameters, "parameters");
}
void IR::Type_MethodBase::validate() const {
#line 3385 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(typeParameters);
        CHECK_NULL(parameters); }
void IR::Type_MethodBase::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"typeParameters\" : " << this->typeParameters;
    if (returnType != nullptr)     json << "," << std::endl << json.indent << "\"returnType\" : " << this->returnType;
    json << "," << std::endl << json.indent << "\"parameters\" : " << this->parameters;
}
IR::Type_MethodBase::Type_MethodBase(JSONLoader & json) : Type(json) {
    json.load("typeParameters", typeParameters);
    json.load("returnType", returnType);
    json.load("parameters", parameters);
}
IR::Type_MethodBase::Type_MethodBase(Util::SourceInfo srcInfo, const IR::TypeParameters* typeParameters, const IR::Type* returnType, const IR::ParameterList* parameters) :
    Type(srcInfo), typeParameters(typeParameters), returnType(returnType), parameters(parameters)
    { validate(); }
IR::Type_MethodBase::Type_MethodBase(const IR::TypeParameters* typeParameters, const IR::Type* returnType, const IR::ParameterList* parameters) :
    typeParameters(typeParameters), returnType(returnType), parameters(parameters)
    { validate(); }
IR::Type_MethodBase::Type_MethodBase(Util::SourceInfo srcInfo, const IR::Type* returnType, const IR::ParameterList* parameters) :
    Type(srcInfo), returnType(returnType), parameters(parameters)
    { validate(); }
IR::Type_MethodBase::Type_MethodBase(const IR::Type* returnType, const IR::ParameterList* parameters) :
    returnType(returnType), parameters(parameters)
    { validate(); }
IR::Type_MethodBase::Type_MethodBase(Util::SourceInfo srcInfo, const IR::TypeParameters* typeParameters, const IR::ParameterList* parameters) :
    Type(srcInfo), typeParameters(typeParameters), parameters(parameters)
    { validate(); }
IR::Type_MethodBase::Type_MethodBase(const IR::TypeParameters* typeParameters, const IR::ParameterList* parameters) :
    typeParameters(typeParameters), parameters(parameters)
    { validate(); }
IR::Type_MethodBase::Type_MethodBase(Util::SourceInfo srcInfo, const IR::ParameterList* parameters) :
    Type(srcInfo), parameters(parameters)
    { validate(); }
IR::Type_MethodBase::Type_MethodBase(const IR::ParameterList* parameters) :
    parameters(parameters)
    { validate(); }

#line 651 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_Method::toString() const { return name; }
#line 3427 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Method::operator==(IR::Type_Method const & a) const {
        return Type_MethodBase::operator==(static_cast<const Type_MethodBase &>(a))
        && name == a.name;
    }
bool IR::Type_Method::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_MethodBase::equiv(a_)) return false;
        auto &a = static_cast<const Type_Method &>(a_);
        return name == a.name;
    }
void IR::Type_Method::dump_fields(std::ostream & out) const {
    Type_MethodBase::dump_fields(out);
        out << " name=" << name;
}
void IR::Type_Method::toJSON(JSONGenerator & json) const {
    Type_MethodBase::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
}
IR::Type_Method::Type_Method(JSONLoader & json) : Type_MethodBase(json) {
    json.load("name", name);
}
IR::Node * IR::Type_Method::fromJSON(JSONLoader & json) { return new Type_Method(json); }
IR::Type_Method::Type_Method(Util::SourceInfo srcInfo, const IR::TypeParameters* typeParameters, const IR::Type* returnType, const IR::ParameterList* parameters, cstring name) :
    Type_MethodBase(srcInfo, typeParameters, returnType, parameters), name(name)
    { validate(); }
IR::Type_Method::Type_Method(const IR::TypeParameters* typeParameters, const IR::Type* returnType, const IR::ParameterList* parameters, cstring name) :
    Type_MethodBase(typeParameters, returnType, parameters), name(name)
    { validate(); }
IR::Type_Method::Type_Method(Util::SourceInfo srcInfo, const IR::Type* returnType, const IR::ParameterList* parameters, cstring name) :
    Type_MethodBase(srcInfo, returnType, parameters), name(name)
    { validate(); }
IR::Type_Method::Type_Method(const IR::Type* returnType, const IR::ParameterList* parameters, cstring name) :
    Type_MethodBase(returnType, parameters), name(name)
    { validate(); }
IR::Type_Method::Type_Method(Util::SourceInfo srcInfo, const IR::TypeParameters* typeParameters, const IR::ParameterList* parameters, cstring name) :
    Type_MethodBase(srcInfo, typeParameters, parameters), name(name)
    { validate(); }
IR::Type_Method::Type_Method(const IR::TypeParameters* typeParameters, const IR::ParameterList* parameters, cstring name) :
    Type_MethodBase(typeParameters, parameters), name(name)
    { validate(); }
IR::Type_Method::Type_Method(Util::SourceInfo srcInfo, const IR::ParameterList* parameters, cstring name) :
    Type_MethodBase(srcInfo, parameters), name(name)
    { validate(); }
IR::Type_Method::Type_Method(const IR::ParameterList* parameters, cstring name) :
    Type_MethodBase(parameters), name(name)
    { validate(); }
#line 661 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::ArgumentInfo::toString() const { return argument->toString(); }
#line 3476 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::ArgumentInfo::operator==(IR::ArgumentInfo const & a) const {
        return typeid(*this) == typeid(a)
        && leftValue == a.leftValue
        && compileTimeConstant == a.compileTimeConstant
        && type == a.type
        && argument == a.argument;
    }
bool IR::ArgumentInfo::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const ArgumentInfo &>(a_);
        return leftValue == a.leftValue
        && compileTimeConstant == a.compileTimeConstant
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (argument ? a.argument ? argument->equiv(*a.argument) : false : a.argument == nullptr);
    }
void IR::ArgumentInfo::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(type, "type");
    v.visit(argument, "argument");
}
void IR::ArgumentInfo::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(type, "type");
    v.visit(argument, "argument");
}
void IR::ArgumentInfo::validate() const {
#line 3504 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(type);
        CHECK_NULL(argument); }
void IR::ArgumentInfo::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " leftValue=" << leftValue;
        out << " compileTimeConstant=" << compileTimeConstant;
}
void IR::ArgumentInfo::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"leftValue\" : " << this->leftValue;
    json << "," << std::endl << json.indent << "\"compileTimeConstant\" : " << this->compileTimeConstant;
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
    json << "," << std::endl << json.indent << "\"argument\" : " << this->argument;
}
IR::ArgumentInfo::ArgumentInfo(JSONLoader & json) : Node(json) {
    json.load("leftValue", leftValue);
    json.load("compileTimeConstant", compileTimeConstant);
    json.load("type", type);
    json.load("argument", argument);
}
IR::Node * IR::ArgumentInfo::fromJSON(JSONLoader & json) { return new ArgumentInfo(json); }
IR::ArgumentInfo::ArgumentInfo(Util::SourceInfo srcInfo, bool leftValue, bool compileTimeConstant, const IR::Type* type, const IR::Argument* argument) :
    Node(srcInfo), leftValue(leftValue), compileTimeConstant(compileTimeConstant), type(type), argument(argument)
    { validate(); }
IR::ArgumentInfo::ArgumentInfo(bool leftValue, bool compileTimeConstant, const IR::Type* type, const IR::Argument* argument) :
    leftValue(leftValue), compileTimeConstant(compileTimeConstant), type(type), argument(argument)
    { validate(); }
#line 672 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Type_MethodCall::validate() const {
#line 3535 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(typeArguments);
        CHECK_NULL(returnType);
        CHECK_NULL(arguments);
#line 672 "/home/fengyong/Desktop/p4c/ir/type.def"
{ typeArguments->check_null(); arguments->check_null(); } }
#line 3542 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 673 "/home/fengyong/Desktop/p4c/ir/type.def"
IR::Type const * IR::Type_MethodCall::getP4Type() const { return nullptr; }
#line 3545 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 674 "/home/fengyong/Desktop/p4c/ir/type.def"
cstring IR::Type_MethodCall::toString() const { return "<Method call>"; }
#line 3548 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_MethodCall::operator==(IR::Type_MethodCall const & a) const {
        return Type::operator==(static_cast<const Type &>(a))
        && typeArguments == a.typeArguments
        && returnType == a.returnType
        && arguments == a.arguments;
    }
bool IR::Type_MethodCall::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type::equiv(a_)) return false;
        auto &a = static_cast<const Type_MethodCall &>(a_);
        return (typeArguments ? a.typeArguments ? typeArguments->equiv(*a.typeArguments) : false : a.typeArguments == nullptr)
        && (returnType ? a.returnType ? returnType->equiv(*a.returnType) : false : a.returnType == nullptr)
        && (arguments ? a.arguments ? arguments->equiv(*a.arguments) : false : a.arguments == nullptr);
    }
void IR::Type_MethodCall::visit_children(Visitor & v) {
    Type::visit_children(v);
    v.visit(typeArguments, "typeArguments");
    v.visit(returnType, "returnType");
    v.visit(arguments, "arguments");
}
void IR::Type_MethodCall::visit_children(Visitor & v) const {
    Type::visit_children(v);
    v.visit(typeArguments, "typeArguments");
    v.visit(returnType, "returnType");
    v.visit(arguments, "arguments");
}
void IR::Type_MethodCall::toJSON(JSONGenerator & json) const {
    Type::toJSON(json);
    json << "," << std::endl << json.indent << "\"typeArguments\" : " << this->typeArguments;
    json << "," << std::endl << json.indent << "\"returnType\" : " << this->returnType;
    json << "," << std::endl << json.indent << "\"arguments\" : " << this->arguments;
}
IR::Type_MethodCall::Type_MethodCall(JSONLoader & json) : Type(json) {
    json.load("typeArguments", typeArguments);
    json.load("returnType", returnType);
    json.load("arguments", arguments);
}
IR::Node * IR::Type_MethodCall::fromJSON(JSONLoader & json) { return new Type_MethodCall(json); }
IR::Type_MethodCall::Type_MethodCall(Util::SourceInfo srcInfo, const IR::Vector<IR::Type>* typeArguments, const IR::Type_Var* returnType, const IR::Vector<IR::ArgumentInfo>* arguments) :
    Type(srcInfo), typeArguments(typeArguments), returnType(returnType), arguments(arguments)
    { validate(); }
IR::Type_MethodCall::Type_MethodCall(const IR::Vector<IR::Type>* typeArguments, const IR::Type_Var* returnType, const IR::Vector<IR::ArgumentInfo>* arguments) :
    typeArguments(typeArguments), returnType(returnType), arguments(arguments)
    { validate(); }
bool IR::Type_Action::operator==(IR::Type_Action const & a) const {
        return Type_MethodBase::operator==(static_cast<const Type_MethodBase &>(a));
    }
bool IR::Type_Action::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_MethodBase::equiv(a_)) return false;
        return true;
    }
void IR::Type_Action::toJSON(JSONGenerator & json) const {
    Type_MethodBase::toJSON(json);
}
IR::Type_Action::Type_Action(JSONLoader & json) : Type_MethodBase(json) {
}
IR::Node * IR::Type_Action::fromJSON(JSONLoader & json) { return new Type_Action(json); }
IR::Type_Action::Type_Action(Util::SourceInfo srcInfo, const IR::TypeParameters* typeParameters, const IR::Type* returnType, const IR::ParameterList* parameters) :
    Type_MethodBase(srcInfo, typeParameters, returnType, parameters)
    { validate(); }
IR::Type_Action::Type_Action(const IR::TypeParameters* typeParameters, const IR::Type* returnType, const IR::ParameterList* parameters) :
    Type_MethodBase(typeParameters, returnType, parameters)
    { validate(); }
IR::Type_Action::Type_Action(Util::SourceInfo srcInfo, const IR::Type* returnType, const IR::ParameterList* parameters) :
    Type_MethodBase(srcInfo, returnType, parameters)
    { validate(); }
IR::Type_Action::Type_Action(const IR::Type* returnType, const IR::ParameterList* parameters) :
    Type_MethodBase(returnType, parameters)
    { validate(); }
IR::Type_Action::Type_Action(Util::SourceInfo srcInfo, const IR::TypeParameters* typeParameters, const IR::ParameterList* parameters) :
    Type_MethodBase(srcInfo, typeParameters, parameters)
    { validate(); }
IR::Type_Action::Type_Action(const IR::TypeParameters* typeParameters, const IR::ParameterList* parameters) :
    Type_MethodBase(typeParameters, parameters)
    { validate(); }
IR::Type_Action::Type_Action(Util::SourceInfo srcInfo, const IR::ParameterList* parameters) :
    Type_MethodBase(srcInfo, parameters)
    { validate(); }
IR::Type_Action::Type_Action(const IR::ParameterList* parameters) :
    Type_MethodBase(parameters)
    { validate(); }
#line 688 "/home/fengyong/Desktop/p4c/ir/type.def"
size_t IR::Method::maxParameterCount() const { return type->maxParameterCount(); }
#line 3633 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 689 "/home/fengyong/Desktop/p4c/ir/type.def"
size_t IR::Method::minParameterCount() const { return type->minParameterCount(); }
#line 3636 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 690 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Method::setAbstract() { isAbstract = true; }
#line 3639 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 691 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::Annotations *IR::Method::getAnnotations() const { return annotations; }
#line 3642 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 692 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::ParameterList *IR::Method::getParameters() const { return type->parameters; }
#line 3645 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

#line 694 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::IDeclaration *IR::Method::getDeclByName(cstring name) const {
        return type->parameters->getDeclByName(name); }
#line 3650 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 696 "/home/fengyong/Desktop/p4c/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Method::getDeclarations() const {
        return type->parameters->getDeclarations(); }
#line 3654 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Method::operator==(IR::Method const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && type == a.type
        && isAbstract == a.isAbstract
        && annotations == a.annotations;
    }
bool IR::Method::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Method &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && isAbstract == a.isAbstract
        && (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr);
    }
void IR::Method::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(type, "type");
    v.visit(annotations, "annotations");
}
void IR::Method::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(type, "type");
    v.visit(annotations, "annotations");
}
void IR::Method::validate() const {
#line 3680 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(type);
        CHECK_NULL(annotations); }
void IR::Method::dump_fields(std::ostream & out) const {
    Declaration::dump_fields(out);
        out << " isAbstract=" << isAbstract;
}
void IR::Method::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
    json << "," << std::endl << json.indent << "\"isAbstract\" : " << this->isAbstract;
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
}
IR::Method::Method(JSONLoader & json) : Declaration(json) {
    json.load("type", type);
    json.load("isAbstract", isAbstract);
    json.load("annotations", annotations);
}
IR::Node * IR::Method::fromJSON(JSONLoader & json) { return new Method(json); }
IR::Method::Method(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Method* type, bool isAbstract, const IR::Annotations* annotations) :
    Declaration(srcInfo, name), type(type), isAbstract(isAbstract), annotations(annotations)
    { validate(); }
IR::Method::Method(IR::ID name, const IR::Type_Method* type, bool isAbstract, const IR::Annotations* annotations) :
    Declaration(name), type(type), isAbstract(isAbstract), annotations(annotations)
    { validate(); }
IR::Method::Method(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Method* type, const IR::Annotations* annotations) :
    Declaration(srcInfo, name), type(type), annotations(annotations)
    { validate(); }
IR::Method::Method(IR::ID name, const IR::Type_Method* type, const IR::Annotations* annotations) :
    Declaration(name), type(type), annotations(annotations)
    { validate(); }
IR::Method::Method(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Method* type, bool isAbstract) :
    Declaration(srcInfo, name), type(type), isAbstract(isAbstract)
    { validate(); }
IR::Method::Method(IR::ID name, const IR::Type_Method* type, bool isAbstract) :
    Declaration(name), type(type), isAbstract(isAbstract)
    { validate(); }
IR::Method::Method(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Method* type) :
    Declaration(srcInfo, name), type(type)
    { validate(); }
IR::Method::Method(IR::ID name, const IR::Type_Method* type) :
    Declaration(name), type(type)
    { validate(); }
#line 703 "/home/fengyong/Desktop/p4c/ir/type.def"
int IR::Type_Typedef::width_bits() const { return type->width_bits(); }
#line 3726 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 704 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::Annotations *IR::Type_Typedef::getAnnotations() const { return annotations; }
#line 3729 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Typedef::operator==(IR::Type_Typedef const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && annotations == a.annotations
        && type == a.type;
    }
bool IR::Type_Typedef::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Type_Typedef &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr);
    }
void IR::Type_Typedef::visit_children(Visitor & v) {
    Type_Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
}
void IR::Type_Typedef::visit_children(Visitor & v) const {
    Type_Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
}
void IR::Type_Typedef::validate() const {
#line 3753 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(type); }
void IR::Type_Typedef::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
}
IR::Type_Typedef::Type_Typedef(JSONLoader & json) : Type_Declaration(json) {
    json.load("annotations", annotations);
    json.load("type", type);
}
IR::Node * IR::Type_Typedef::fromJSON(JSONLoader & json) { return new Type_Typedef(json); }
IR::Type_Typedef::Type_Typedef(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type) :
    Type_Declaration(srcInfo, name), annotations(annotations), type(type)
    { validate(); }
IR::Type_Typedef::Type_Typedef(IR::ID name, const IR::Annotations* annotations, const IR::Type* type) :
    Type_Declaration(name), annotations(annotations), type(type)
    { validate(); }
IR::Type_Typedef::Type_Typedef(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type) :
    Type_Declaration(srcInfo, name), type(type)
    { validate(); }
IR::Type_Typedef::Type_Typedef(IR::ID name, const IR::Type* type) :
    Type_Declaration(name), type(type)
    { validate(); }
#line 716 "/home/fengyong/Desktop/p4c/ir/type.def"
int IR::Type_Newtype::width_bits() const { return type->width_bits(); }
#line 3781 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 717 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::Annotations *IR::Type_Newtype::getAnnotations() const { return annotations; }
#line 3784 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Newtype::operator==(IR::Type_Newtype const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && annotations == a.annotations
        && type == a.type;
    }
bool IR::Type_Newtype::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Type_Newtype &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr);
    }
void IR::Type_Newtype::visit_children(Visitor & v) {
    Type_Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
}
void IR::Type_Newtype::visit_children(Visitor & v) const {
    Type_Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
}
void IR::Type_Newtype::validate() const {
#line 3808 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(type); }
void IR::Type_Newtype::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
}
IR::Type_Newtype::Type_Newtype(JSONLoader & json) : Type_Declaration(json) {
    json.load("annotations", annotations);
    json.load("type", type);
}
IR::Node * IR::Type_Newtype::fromJSON(JSONLoader & json) { return new Type_Newtype(json); }
IR::Type_Newtype::Type_Newtype(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type) :
    Type_Declaration(srcInfo, name), annotations(annotations), type(type)
    { validate(); }
IR::Type_Newtype::Type_Newtype(IR::ID name, const IR::Annotations* annotations, const IR::Type* type) :
    Type_Declaration(name), annotations(annotations), type(type)
    { validate(); }
IR::Type_Newtype::Type_Newtype(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type) :
    Type_Declaration(srcInfo, name), type(type)
    { validate(); }
IR::Type_Newtype::Type_Newtype(IR::ID name, const IR::Type* type) :
    Type_Declaration(name), type(type)
    { validate(); }


#line 729 "/home/fengyong/Desktop/p4c/ir/type.def"
std::vector<const IR::INamespace *> IR::Type_Extern::getNestedNamespaces() const { return { typeParameters }; }
#line 3838 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 730 "/home/fengyong/Desktop/p4c/ir/type.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Type_Extern::getDeclarations() const {
        return attributes.valueEnumerator()->as<const IDeclaration*>()
            ->concat(methods.getEnumerator()->as<const IDeclaration*>()); }
#line 3843 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 733 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::TypeParameters *IR::Type_Extern::getTypeParameters() const { return typeParameters; }
#line 3846 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 734 "/home/fengyong/Desktop/p4c/ir/type.def"
void IR::Type_Extern::validate() const {
#line 3849 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(typeParameters);
        methods.validate();
        attributes.validate();
        CHECK_NULL(annotations);
#line 734 "/home/fengyong/Desktop/p4c/ir/type.def"
{ methods.check_null(); } }
#line 3857 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 735 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::Annotations *IR::Type_Extern::getAnnotations() const { return annotations; }
#line 3860 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
/// Returns the method that matches the specified arguments.
/// Returns nullptr if no method or more than one method match.
/// In the latter case it also reports an error.
/// Returns the constructor that matches the specified arguments.
/// Returns nullptr if no constructor or more than one constructor matches.
/// In the latter case it also reports an error.
#line 743 "/home/fengyong/Desktop/p4c/ir/type.def"
const IR::Method *IR::Type_Extern::lookupConstructor(const IR::Vector<IR::Argument>* arguments) const { return lookupMethod(name, arguments); }
#line 3869 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Extern::operator==(IR::Type_Extern const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && typeParameters == a.typeParameters
        && methods == a.methods
        && attributes == a.attributes
        && annotations == a.annotations;
    }
bool IR::Type_Extern::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Type_Extern &>(a_);
        return (typeParameters ? a.typeParameters ? typeParameters->equiv(*a.typeParameters) : false : a.typeParameters == nullptr)
        && methods.equiv(a.methods)
        && attributes.equiv(a.attributes)
        && (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr);
    }
void IR::Type_Extern::visit_children(Visitor & v) {
    Type_Declaration::visit_children(v);
    v.visit(typeParameters, "typeParameters");
    methods.visit_children(v);
    attributes.visit_children(v);
    v.visit(annotations, "annotations");
}
void IR::Type_Extern::visit_children(Visitor & v) const {
    Type_Declaration::visit_children(v);
    v.visit(typeParameters, "typeParameters");
    methods.visit_children(v);
    attributes.visit_children(v);
    v.visit(annotations, "annotations");
}
void IR::Type_Extern::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"typeParameters\" : " << this->typeParameters;
    json << "," << std::endl << json.indent << "\"methods\" : " << this->methods;
    json << "," << std::endl << json.indent << "\"attributes\" : " << this->attributes;
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
}
IR::Type_Extern::Type_Extern(JSONLoader & json) : Type_Declaration(json) {
    json.load("typeParameters", typeParameters);
    json.load("methods", methods);
    json.load("attributes", attributes);
    json.load("annotations", annotations);
}
IR::Node * IR::Type_Extern::fromJSON(JSONLoader & json) { return new Type_Extern(json); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes, const IR::Annotations* annotations) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters), methods(methods), attributes(attributes), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes, const IR::Annotations* annotations) :
    Type_Declaration(name), typeParameters(typeParameters), methods(methods), attributes(attributes), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes, const IR::Annotations* annotations) :
    Type_Declaration(srcInfo, name), methods(methods), attributes(attributes), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes, const IR::Annotations* annotations) :
    Type_Declaration(name), methods(methods), attributes(attributes), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::NameMap<IR::Attribute, ordered_map> attributes, const IR::Annotations* annotations) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters), attributes(attributes), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, IR::NameMap<IR::Attribute, ordered_map> attributes, const IR::Annotations* annotations) :
    Type_Declaration(name), typeParameters(typeParameters), attributes(attributes), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, IR::NameMap<IR::Attribute, ordered_map> attributes, const IR::Annotations* annotations) :
    Type_Declaration(srcInfo, name), attributes(attributes), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, IR::NameMap<IR::Attribute, ordered_map> attributes, const IR::Annotations* annotations) :
    Type_Declaration(name), attributes(attributes), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods, const IR::Annotations* annotations) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters), methods(methods), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods, const IR::Annotations* annotations) :
    Type_Declaration(name), typeParameters(typeParameters), methods(methods), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Method> methods, const IR::Annotations* annotations) :
    Type_Declaration(srcInfo, name), methods(methods), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, IR::Vector<IR::Method> methods, const IR::Annotations* annotations) :
    Type_Declaration(name), methods(methods), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, const IR::Annotations* annotations) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, const IR::Annotations* annotations) :
    Type_Declaration(name), typeParameters(typeParameters), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Type_Declaration(srcInfo, name), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, const IR::Annotations* annotations) :
    Type_Declaration(name), annotations(annotations)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters), methods(methods), attributes(attributes)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes) :
    Type_Declaration(name), typeParameters(typeParameters), methods(methods), attributes(attributes)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes) :
    Type_Declaration(srcInfo, name), methods(methods), attributes(attributes)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, IR::Vector<IR::Method> methods, IR::NameMap<IR::Attribute, ordered_map> attributes) :
    Type_Declaration(name), methods(methods), attributes(attributes)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::NameMap<IR::Attribute, ordered_map> attributes) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters), attributes(attributes)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, IR::NameMap<IR::Attribute, ordered_map> attributes) :
    Type_Declaration(name), typeParameters(typeParameters), attributes(attributes)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, IR::NameMap<IR::Attribute, ordered_map> attributes) :
    Type_Declaration(srcInfo, name), attributes(attributes)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, IR::NameMap<IR::Attribute, ordered_map> attributes) :
    Type_Declaration(name), attributes(attributes)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters), methods(methods)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters, IR::Vector<IR::Method> methods) :
    Type_Declaration(name), typeParameters(typeParameters), methods(methods)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, IR::Vector<IR::Method> methods) :
    Type_Declaration(srcInfo, name), methods(methods)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, IR::Vector<IR::Method> methods) :
    Type_Declaration(name), methods(methods)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Declaration(srcInfo, name), typeParameters(typeParameters)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Declaration(name), typeParameters(typeParameters)
    { validate(); }
IR::Type_Extern::Type_Extern(Util::SourceInfo srcInfo, IR::ID name) :
    Type_Declaration(srcInfo, name)
    { validate(); }
IR::Type_Extern::Type_Extern(IR::ID name) :
    Type_Declaration(name)
    { validate(); }
#line 15 "/home/fengyong/Desktop/p4c/ir/expression.def"
cstring IR::Operation_Unary::toString() const { return getStringOp() + expr->toString(); }
#line 4012 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Operation_Unary::operator==(IR::Operation_Unary const & a) const {
        return Operation::operator==(static_cast<const Operation &>(a))
        && expr == a.expr;
    }
bool IR::Operation_Unary::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation::equiv(a_)) return false;
        auto &a = static_cast<const Operation_Unary &>(a_);
        return (expr ? a.expr ? expr->equiv(*a.expr) : false : a.expr == nullptr);
    }
void IR::Operation_Unary::visit_children(Visitor & v) {
    Operation::visit_children(v);
    v.visit(expr, "expr");
}
void IR::Operation_Unary::visit_children(Visitor & v) const {
    Operation::visit_children(v);
    v.visit(expr, "expr");
}
void IR::Operation_Unary::validate() const {
#line 4032 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(expr); }
void IR::Operation_Unary::toJSON(JSONGenerator & json) const {
    Operation::toJSON(json);
    json << "," << std::endl << json.indent << "\"expr\" : " << this->expr;
}
IR::Operation_Unary::Operation_Unary(JSONLoader & json) : Operation(json) {
    json.load("expr", expr);
}
IR::Operation_Unary::Operation_Unary(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr) :
    Operation(srcInfo, type), expr(expr)
    {
#line 11 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        if (!srcInfo && expr) srcInfo = expr->srcInfo;
        if (type->is<Type::Unknown>() && expr) type = expr->type; }
#line 4049 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Operation_Unary::Operation_Unary(const IR::Type* type, const IR::Expression* expr) :
    Operation(type), expr(expr)
    {
#line 11 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        if (!srcInfo && expr) srcInfo = expr->srcInfo;
        if (type->is<Type::Unknown>() && expr) type = expr->type; }
#line 4058 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Operation_Unary::Operation_Unary(Util::SourceInfo srcInfo, const IR::Expression* expr) :
    Operation(srcInfo), expr(expr)
    {
#line 11 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        if (!srcInfo && expr) srcInfo = expr->srcInfo;
        if (type->is<Type::Unknown>() && expr) type = expr->type; }
#line 4067 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Operation_Unary::Operation_Unary(const IR::Expression* expr) :
    expr(expr)
    {
#line 11 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        if (!srcInfo && expr) srcInfo = expr->srcInfo;
        if (type->is<Type::Unknown>() && expr) type = expr->type; }
#line 4076 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
bool IR::Neg::operator==(IR::Neg const & a) const {
        return Operation_Unary::operator==(static_cast<const Operation_Unary &>(a));
    }
bool IR::Neg::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Unary::equiv(a_)) return false;
        return true;
    }
void IR::Neg::toJSON(JSONGenerator & json) const {
    Operation_Unary::toJSON(json);
}
IR::Neg::Neg(JSONLoader & json) : Operation_Unary(json) {
}
IR::Node * IR::Neg::fromJSON(JSONLoader & json) { return new Neg(json); }
IR::Neg::Neg(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(srcInfo, type, expr)
    { validate(); }
IR::Neg::Neg(const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(type, expr)
    { validate(); }
IR::Neg::Neg(Util::SourceInfo srcInfo, const IR::Expression* expr) :
    Operation_Unary(srcInfo, expr)
    { validate(); }
IR::Neg::Neg(const IR::Expression* expr) :
    Operation_Unary(expr)
    { validate(); }
bool IR::UPlus::operator==(IR::UPlus const & a) const {
        return Operation_Unary::operator==(static_cast<const Operation_Unary &>(a));
    }
bool IR::UPlus::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Unary::equiv(a_)) return false;
        return true;
    }
void IR::UPlus::toJSON(JSONGenerator & json) const {
    Operation_Unary::toJSON(json);
}
IR::UPlus::UPlus(JSONLoader & json) : Operation_Unary(json) {
}
IR::Node * IR::UPlus::fromJSON(JSONLoader & json) { return new UPlus(json); }
IR::UPlus::UPlus(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(srcInfo, type, expr)
    { validate(); }
IR::UPlus::UPlus(const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(type, expr)
    { validate(); }
IR::UPlus::UPlus(Util::SourceInfo srcInfo, const IR::Expression* expr) :
    Operation_Unary(srcInfo, expr)
    { validate(); }
IR::UPlus::UPlus(const IR::Expression* expr) :
    Operation_Unary(expr)
    { validate(); }
bool IR::Cmpl::operator==(IR::Cmpl const & a) const {
        return Operation_Unary::operator==(static_cast<const Operation_Unary &>(a));
    }
bool IR::Cmpl::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Unary::equiv(a_)) return false;
        return true;
    }
void IR::Cmpl::toJSON(JSONGenerator & json) const {
    Operation_Unary::toJSON(json);
}
IR::Cmpl::Cmpl(JSONLoader & json) : Operation_Unary(json) {
}
IR::Node * IR::Cmpl::fromJSON(JSONLoader & json) { return new Cmpl(json); }
IR::Cmpl::Cmpl(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(srcInfo, type, expr)
    { validate(); }
IR::Cmpl::Cmpl(const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(type, expr)
    { validate(); }
IR::Cmpl::Cmpl(Util::SourceInfo srcInfo, const IR::Expression* expr) :
    Operation_Unary(srcInfo, expr)
    { validate(); }
IR::Cmpl::Cmpl(const IR::Expression* expr) :
    Operation_Unary(expr)
    { validate(); }
bool IR::LNot::operator==(IR::LNot const & a) const {
        return Operation_Unary::operator==(static_cast<const Operation_Unary &>(a));
    }
bool IR::LNot::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Unary::equiv(a_)) return false;
        return true;
    }
void IR::LNot::toJSON(JSONGenerator & json) const {
    Operation_Unary::toJSON(json);
}
IR::LNot::LNot(JSONLoader & json) : Operation_Unary(json) {
}
IR::Node * IR::LNot::fromJSON(JSONLoader & json) { return new LNot(json); }
IR::LNot::LNot(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(srcInfo, type, expr)
    { validate(); }
IR::LNot::LNot(const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(type, expr)
    { validate(); }
IR::LNot::LNot(Util::SourceInfo srcInfo, const IR::Expression* expr) :
    Operation_Unary(srcInfo, expr)
    { validate(); }
IR::LNot::LNot(const IR::Expression* expr) :
    Operation_Unary(expr)
    { validate(); }
#line 41 "/home/fengyong/Desktop/p4c/ir/expression.def"
cstring IR::Operation_Binary::toString() const {
        std::stringstream tmp;
        tmp << DBPrint::Prec_Low << *this;
        return tmp.str();
    }
#line 4188 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Operation_Binary::operator==(IR::Operation_Binary const & a) const {
        return Operation::operator==(static_cast<const Operation &>(a))
        && left == a.left
        && right == a.right;
    }
bool IR::Operation_Binary::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation::equiv(a_)) return false;
        auto &a = static_cast<const Operation_Binary &>(a_);
        return (left ? a.left ? left->equiv(*a.left) : false : a.left == nullptr)
        && (right ? a.right ? right->equiv(*a.right) : false : a.right == nullptr);
    }
void IR::Operation_Binary::visit_children(Visitor & v) {
    Operation::visit_children(v);
    v.visit(left, "left");
    v.visit(right, "right");
}
void IR::Operation_Binary::visit_children(Visitor & v) const {
    Operation::visit_children(v);
    v.visit(left, "left");
    v.visit(right, "right");
}
void IR::Operation_Binary::validate() const {
#line 4212 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(left);
        CHECK_NULL(right); }
void IR::Operation_Binary::toJSON(JSONGenerator & json) const {
    Operation::toJSON(json);
    json << "," << std::endl << json.indent << "\"left\" : " << this->left;
    json << "," << std::endl << json.indent << "\"right\" : " << this->right;
}
IR::Operation_Binary::Operation_Binary(JSONLoader & json) : Operation(json) {
    json.load("left", left);
    json.load("right", right);
}
IR::Operation_Binary::Operation_Binary(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation(srcInfo, type), left(left), right(right)
    {
#line 37 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        if (!srcInfo && left && right) srcInfo = left->srcInfo + right->srcInfo;
        if (type->is<Type::Unknown>() && left && right && left->type == right->type)
            type = left->type; }
#line 4233 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Operation_Binary::Operation_Binary(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation(type), left(left), right(right)
    {
#line 37 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        if (!srcInfo && left && right) srcInfo = left->srcInfo + right->srcInfo;
        if (type->is<Type::Unknown>() && left && right && left->type == right->type)
            type = left->type; }
#line 4243 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Operation_Binary::Operation_Binary(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation(srcInfo), left(left), right(right)
    {
#line 37 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        if (!srcInfo && left && right) srcInfo = left->srcInfo + right->srcInfo;
        if (type->is<Type::Unknown>() && left && right && left->type == right->type)
            type = left->type; }
#line 4253 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Operation_Binary::Operation_Binary(const IR::Expression* left, const IR::Expression* right) :
    left(left), right(right)
    {
#line 37 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        if (!srcInfo && left && right) srcInfo = left->srcInfo + right->srcInfo;
        if (type->is<Type::Unknown>() && left && right && left->type == right->type)
            type = left->type; }
#line 4263 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
bool IR::Operation_Ternary::operator==(IR::Operation_Ternary const & a) const {
        return Operation::operator==(static_cast<const Operation &>(a))
        && e0 == a.e0
        && e1 == a.e1
        && e2 == a.e2;
    }
bool IR::Operation_Ternary::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation::equiv(a_)) return false;
        auto &a = static_cast<const Operation_Ternary &>(a_);
        return (e0 ? a.e0 ? e0->equiv(*a.e0) : false : a.e0 == nullptr)
        && (e1 ? a.e1 ? e1->equiv(*a.e1) : false : a.e1 == nullptr)
        && (e2 ? a.e2 ? e2->equiv(*a.e2) : false : a.e2 == nullptr);
    }
void IR::Operation_Ternary::visit_children(Visitor & v) {
    Operation::visit_children(v);
    v.visit(e0, "e0");
    v.visit(e1, "e1");
    v.visit(e2, "e2");
}
void IR::Operation_Ternary::visit_children(Visitor & v) const {
    Operation::visit_children(v);
    v.visit(e0, "e0");
    v.visit(e1, "e1");
    v.visit(e2, "e2");
}
void IR::Operation_Ternary::validate() const {
#line 4292 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(e0);
        CHECK_NULL(e1);
        CHECK_NULL(e2); }
void IR::Operation_Ternary::toJSON(JSONGenerator & json) const {
    Operation::toJSON(json);
    json << "," << std::endl << json.indent << "\"e0\" : " << this->e0;
    json << "," << std::endl << json.indent << "\"e1\" : " << this->e1;
    json << "," << std::endl << json.indent << "\"e2\" : " << this->e2;
}
IR::Operation_Ternary::Operation_Ternary(JSONLoader & json) : Operation(json) {
    json.load("e0", e0);
    json.load("e1", e1);
    json.load("e2", e2);
}
IR::Operation_Ternary::Operation_Ternary(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation(srcInfo, type), e0(e0), e1(e1), e2(e2)
    {
#line 52 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (!srcInfo && e0 && e2) srcInfo = e0->srcInfo + e2->srcInfo; }
#line 4313 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Operation_Ternary::Operation_Ternary(const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation(type), e0(e0), e1(e1), e2(e2)
    {
#line 52 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (!srcInfo && e0 && e2) srcInfo = e0->srcInfo + e2->srcInfo; }
#line 4320 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Operation_Ternary::Operation_Ternary(Util::SourceInfo srcInfo, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation(srcInfo), e0(e0), e1(e1), e2(e2)
    {
#line 52 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (!srcInfo && e0 && e2) srcInfo = e0->srcInfo + e2->srcInfo; }
#line 4327 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Operation_Ternary::Operation_Ternary(const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    e0(e0), e1(e1), e2(e2)
    {
#line 52 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (!srcInfo && e0 && e2) srcInfo = e0->srcInfo + e2->srcInfo; }
#line 4334 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
bool IR::Operation_Relation::operator==(IR::Operation_Relation const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Operation_Relation::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Operation_Relation::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Operation_Relation::Operation_Relation(JSONLoader & json) : Operation_Binary(json) {
}
IR::Operation_Relation::Operation_Relation(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    {
#line 56 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ type = Type::Boolean::get(); }
#line 4354 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Operation_Relation::Operation_Relation(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    {
#line 56 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ type = Type::Boolean::get(); }
#line 4361 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Operation_Relation::Operation_Relation(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    {
#line 56 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ type = Type::Boolean::get(); }
#line 4368 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Operation_Relation::Operation_Relation(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    {
#line 56 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ type = Type::Boolean::get(); }
#line 4375 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
bool IR::Mul::operator==(IR::Mul const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Mul::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Mul::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Mul::Mul(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Mul::fromJSON(JSONLoader & json) { return new Mul(json); }
IR::Mul::Mul(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
IR::Mul::Mul(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
IR::Mul::Mul(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
IR::Mul::Mul(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
bool IR::Div::operator==(IR::Div const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Div::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Div::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Div::Div(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Div::fromJSON(JSONLoader & json) { return new Div(json); }
IR::Div::Div(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
IR::Div::Div(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
IR::Div::Div(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
IR::Div::Div(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
bool IR::Mod::operator==(IR::Mod const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Mod::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Mod::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Mod::Mod(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Mod::fromJSON(JSONLoader & json) { return new Mod(json); }
IR::Mod::Mod(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
IR::Mod::Mod(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
IR::Mod::Mod(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
IR::Mod::Mod(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
bool IR::Add::operator==(IR::Add const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Add::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Add::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Add::Add(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Add::fromJSON(JSONLoader & json) { return new Add(json); }
IR::Add::Add(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
IR::Add::Add(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
IR::Add::Add(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
IR::Add::Add(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
bool IR::Sub::operator==(IR::Sub const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Sub::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Sub::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Sub::Sub(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Sub::fromJSON(JSONLoader & json) { return new Sub(json); }
IR::Sub::Sub(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
IR::Sub::Sub(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
IR::Sub::Sub(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
IR::Sub::Sub(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
bool IR::AddSat::operator==(IR::AddSat const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::AddSat::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::AddSat::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::AddSat::AddSat(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::AddSat::fromJSON(JSONLoader & json) { return new AddSat(json); }
IR::AddSat::AddSat(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
IR::AddSat::AddSat(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
IR::AddSat::AddSat(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
IR::AddSat::AddSat(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
bool IR::SubSat::operator==(IR::SubSat const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::SubSat::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::SubSat::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::SubSat::SubSat(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::SubSat::fromJSON(JSONLoader & json) { return new SubSat(json); }
IR::SubSat::SubSat(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
IR::SubSat::SubSat(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
IR::SubSat::SubSat(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
IR::SubSat::SubSat(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
bool IR::Shl::operator==(IR::Shl const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Shl::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Shl::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Shl::Shl(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Shl::fromJSON(JSONLoader & json) { return new Shl(json); }
IR::Shl::Shl(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    {
#line 91 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (type->is<Type::Unknown>() && left) type = left->type; }
#line 4578 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Shl::Shl(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    {
#line 91 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (type->is<Type::Unknown>() && left) type = left->type; }
#line 4585 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Shl::Shl(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    {
#line 91 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (type->is<Type::Unknown>() && left) type = left->type; }
#line 4592 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Shl::Shl(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    {
#line 91 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (type->is<Type::Unknown>() && left) type = left->type; }
#line 4599 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
bool IR::Shr::operator==(IR::Shr const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Shr::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Shr::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Shr::Shr(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Shr::fromJSON(JSONLoader & json) { return new Shr(json); }
IR::Shr::Shr(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    {
#line 96 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (type->is<Type::Unknown>() && left) type = left->type; }
#line 4620 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Shr::Shr(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    {
#line 96 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (type->is<Type::Unknown>() && left) type = left->type; }
#line 4627 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Shr::Shr(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    {
#line 96 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (type->is<Type::Unknown>() && left) type = left->type; }
#line 4634 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Shr::Shr(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    {
#line 96 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (type->is<Type::Unknown>() && left) type = left->type; }
#line 4641 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
bool IR::Equ::operator==(IR::Equ const & a) const {
        return Operation_Relation::operator==(static_cast<const Operation_Relation &>(a));
    }
bool IR::Equ::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Relation::equiv(a_)) return false;
        return true;
    }
void IR::Equ::toJSON(JSONGenerator & json) const {
    Operation_Relation::toJSON(json);
}
IR::Equ::Equ(JSONLoader & json) : Operation_Relation(json) {
}
IR::Node * IR::Equ::fromJSON(JSONLoader & json) { return new Equ(json); }
IR::Equ::Equ(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, type, left, right)
    { validate(); }
IR::Equ::Equ(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(type, left, right)
    { validate(); }
IR::Equ::Equ(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, left, right)
    { validate(); }
IR::Equ::Equ(const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(left, right)
    { validate(); }
bool IR::Neq::operator==(IR::Neq const & a) const {
        return Operation_Relation::operator==(static_cast<const Operation_Relation &>(a));
    }
bool IR::Neq::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Relation::equiv(a_)) return false;
        return true;
    }
void IR::Neq::toJSON(JSONGenerator & json) const {
    Operation_Relation::toJSON(json);
}
IR::Neq::Neq(JSONLoader & json) : Operation_Relation(json) {
}
IR::Node * IR::Neq::fromJSON(JSONLoader & json) { return new Neq(json); }
IR::Neq::Neq(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, type, left, right)
    { validate(); }
IR::Neq::Neq(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(type, left, right)
    { validate(); }
IR::Neq::Neq(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, left, right)
    { validate(); }
IR::Neq::Neq(const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(left, right)
    { validate(); }
bool IR::Lss::operator==(IR::Lss const & a) const {
        return Operation_Relation::operator==(static_cast<const Operation_Relation &>(a));
    }
bool IR::Lss::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Relation::equiv(a_)) return false;
        return true;
    }
void IR::Lss::toJSON(JSONGenerator & json) const {
    Operation_Relation::toJSON(json);
}
IR::Lss::Lss(JSONLoader & json) : Operation_Relation(json) {
}
IR::Node * IR::Lss::fromJSON(JSONLoader & json) { return new Lss(json); }
IR::Lss::Lss(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, type, left, right)
    { validate(); }
IR::Lss::Lss(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(type, left, right)
    { validate(); }
IR::Lss::Lss(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, left, right)
    { validate(); }
IR::Lss::Lss(const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(left, right)
    { validate(); }
bool IR::Leq::operator==(IR::Leq const & a) const {
        return Operation_Relation::operator==(static_cast<const Operation_Relation &>(a));
    }
bool IR::Leq::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Relation::equiv(a_)) return false;
        return true;
    }
void IR::Leq::toJSON(JSONGenerator & json) const {
    Operation_Relation::toJSON(json);
}
IR::Leq::Leq(JSONLoader & json) : Operation_Relation(json) {
}
IR::Node * IR::Leq::fromJSON(JSONLoader & json) { return new Leq(json); }
IR::Leq::Leq(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, type, left, right)
    { validate(); }
IR::Leq::Leq(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(type, left, right)
    { validate(); }
IR::Leq::Leq(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, left, right)
    { validate(); }
IR::Leq::Leq(const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(left, right)
    { validate(); }
bool IR::Grt::operator==(IR::Grt const & a) const {
        return Operation_Relation::operator==(static_cast<const Operation_Relation &>(a));
    }
bool IR::Grt::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Relation::equiv(a_)) return false;
        return true;
    }
void IR::Grt::toJSON(JSONGenerator & json) const {
    Operation_Relation::toJSON(json);
}
IR::Grt::Grt(JSONLoader & json) : Operation_Relation(json) {
}
IR::Node * IR::Grt::fromJSON(JSONLoader & json) { return new Grt(json); }
IR::Grt::Grt(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, type, left, right)
    { validate(); }
IR::Grt::Grt(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(type, left, right)
    { validate(); }
IR::Grt::Grt(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, left, right)
    { validate(); }
IR::Grt::Grt(const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(left, right)
    { validate(); }
bool IR::Geq::operator==(IR::Geq const & a) const {
        return Operation_Relation::operator==(static_cast<const Operation_Relation &>(a));
    }
bool IR::Geq::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Relation::equiv(a_)) return false;
        return true;
    }
void IR::Geq::toJSON(JSONGenerator & json) const {
    Operation_Relation::toJSON(json);
}
IR::Geq::Geq(JSONLoader & json) : Operation_Relation(json) {
}
IR::Node * IR::Geq::fromJSON(JSONLoader & json) { return new Geq(json); }
IR::Geq::Geq(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, type, left, right)
    { validate(); }
IR::Geq::Geq(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(type, left, right)
    { validate(); }
IR::Geq::Geq(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(srcInfo, left, right)
    { validate(); }
IR::Geq::Geq(const IR::Expression* left, const IR::Expression* right) :
    Operation_Relation(left, right)
    { validate(); }
bool IR::BAnd::operator==(IR::BAnd const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::BAnd::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::BAnd::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::BAnd::BAnd(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::BAnd::fromJSON(JSONLoader & json) { return new BAnd(json); }
IR::BAnd::BAnd(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
IR::BAnd::BAnd(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
IR::BAnd::BAnd(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
IR::BAnd::BAnd(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
bool IR::BOr::operator==(IR::BOr const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::BOr::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::BOr::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::BOr::BOr(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::BOr::fromJSON(JSONLoader & json) { return new BOr(json); }
IR::BOr::BOr(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
IR::BOr::BOr(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
IR::BOr::BOr(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
IR::BOr::BOr(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
bool IR::BXor::operator==(IR::BXor const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::BXor::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::BXor::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::BXor::BXor(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::BXor::fromJSON(JSONLoader & json) { return new BXor(json); }
IR::BXor::BXor(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
IR::BXor::BXor(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
IR::BXor::BXor(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
IR::BXor::BXor(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
bool IR::LAnd::operator==(IR::LAnd const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::LAnd::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::LAnd::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::LAnd::LAnd(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::LAnd::fromJSON(JSONLoader & json) { return new LAnd(json); }
IR::LAnd::LAnd(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
IR::LAnd::LAnd(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
IR::LAnd::LAnd(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
IR::LAnd::LAnd(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
bool IR::LOr::operator==(IR::LOr const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::LOr::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::LOr::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::LOr::LOr(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::LOr::fromJSON(JSONLoader & json) { return new LOr(json); }
IR::LOr::LOr(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    { validate(); }
IR::LOr::LOr(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    { validate(); }
IR::LOr::LOr(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    { validate(); }
IR::LOr::LOr(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    { validate(); }
#line 145 "/home/fengyong/Desktop/p4c/ir/expression.def"
void IR::Dots::dbprint(std::ostream & out) const { out << "..."; }
#line 4931 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 146 "/home/fengyong/Desktop/p4c/ir/expression.def"
cstring IR::Dots::toString() const { return "..."; }
#line 4934 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Dots::operator==(IR::Dots const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a));
    }
bool IR::Dots::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        return true;
    }
void IR::Dots::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
}
IR::Dots::Dots(JSONLoader & json) : Expression(json) {
}
IR::Node * IR::Dots::fromJSON(JSONLoader & json) { return new Dots(json); }
IR::Dots::Dots(Util::SourceInfo srcInfo, const IR::Type* type) :
    Expression(srcInfo, type)
    { validate(); }
IR::Dots::Dots(const IR::Type* type) :
    Expression(type)
    { validate(); }
IR::Dots::Dots(Util::SourceInfo srcInfo) :
    Expression(srcInfo)
    { validate(); }
IR::Dots::Dots() 
    { validate(); }
#line 152 "/home/fengyong/Desktop/p4c/ir/expression.def"
IR::NamedDots::NamedDots() : NamedExpression("...", new Dots()) {}
#line 4962 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 153 "/home/fengyong/Desktop/p4c/ir/expression.def"
IR::NamedDots::NamedDots(Util::SourceInfo srcInfo, const IR::Dots* dots) : NamedExpression(srcInfo, "...", dots) { CHECK_NULL(dots); }
#line 4965 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 154 "/home/fengyong/Desktop/p4c/ir/expression.def"
IR::NamedDots::NamedDots(Util::SourceInfo srcInfo) : NamedExpression(srcInfo, "...", new Dots()) {}
#line 4968 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 155 "/home/fengyong/Desktop/p4c/ir/expression.def"
void IR::NamedDots::dbprint(std::ostream & out) const { out << "..."; }
#line 4971 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 156 "/home/fengyong/Desktop/p4c/ir/expression.def"
cstring IR::NamedDots::toString() const { return "..."; }
#line 4974 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::NamedDots::operator==(IR::NamedDots const & a) const {
        return NamedExpression::operator==(static_cast<const NamedExpression &>(a));
    }
bool IR::NamedDots::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!NamedExpression::equiv(a_)) return false;
        return true;
    }
void IR::NamedDots::toJSON(JSONGenerator & json) const {
    NamedExpression::toJSON(json);
}
IR::NamedDots::NamedDots(JSONLoader & json) : NamedExpression(json) {
}
IR::Node * IR::NamedDots::fromJSON(JSONLoader & json) { return new NamedDots(json); }
IR::NamedDots::NamedDots(Util::SourceInfo srcInfo, IR::ID name, const IR::Expression* expression) :
    NamedExpression(srcInfo, name, expression)
    { validate(); }
IR::NamedDots::NamedDots(IR::ID name, const IR::Expression* expression) :
    NamedExpression(name, expression)
    { validate(); }
bool IR::Literal::operator==(IR::Literal const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a));
    }
bool IR::Literal::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        return true;
    }
void IR::Literal::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
}
IR::Literal::Literal(JSONLoader & json) : Expression(json) {
}
IR::Literal::Literal(Util::SourceInfo srcInfo, const IR::Type* type) :
    Expression(srcInfo, type)
    { validate(); }
IR::Literal::Literal(const IR::Type* type) :
    Expression(type)
    { validate(); }
IR::Literal::Literal(Util::SourceInfo srcInfo) :
    Expression(srcInfo)
    { validate(); }
IR::Literal::Literal() 
    { validate(); }
/// base used when reading/writing
/// if noWarning is true, no warning is emitted



#line 171 "/home/fengyong/Desktop/p4c/ir/expression.def"
IR::Constant::Constant(int v, unsigned base) :
        Literal(new Type_InfInt()), value(v), base(base) {}
#line 5027 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 173 "/home/fengyong/Desktop/p4c/ir/expression.def"
IR::Constant::Constant(unsigned v, unsigned base) :
        Literal(new Type_InfInt()), value(v), base(base) {}
#line 5031 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 188 "/home/fengyong/Desktop/p4c/ir/expression.def"
IR::Constant::Constant(uint64_t v, unsigned base) :
        Literal(new Type_InfInt()), value(v), base(base) {}
#line 5035 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 190 "/home/fengyong/Desktop/p4c/ir/expression.def"
IR::Constant::Constant(big_int v, unsigned base) :
        Literal(new Type_InfInt()), value(v), base(base) {}
#line 5039 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 192 "/home/fengyong/Desktop/p4c/ir/expression.def"
IR::Constant::Constant(Util::SourceInfo si, big_int v, unsigned base) :
        Literal(si, new Type_InfInt()), value(v), base(base) {}
#line 5043 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 194 "/home/fengyong/Desktop/p4c/ir/expression.def"
IR::Constant::Constant(IR::Type const * t, big_int v, unsigned base, bool noWarning) :
        Literal(t), value(v), base(base) { CHECK_NULL(t); handleOverflow(noWarning); }
#line 5047 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 196 "/home/fengyong/Desktop/p4c/ir/expression.def"
IR::Constant::Constant(Util::SourceInfo si, IR::Type const * t, big_int v, unsigned base, bool noWarning) :
        Literal(si, t), value(v), base(base) { CHECK_NULL(t); handleOverflow(noWarning); }
#line 5051 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 202 "/home/fengyong/Desktop/p4c/ir/expression.def"
bool IR::Constant::fitsInt() const { return value >= INT_MIN && value <= INT_MAX; }
#line 5054 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 203 "/home/fengyong/Desktop/p4c/ir/expression.def"
bool IR::Constant::fitsLong() const { return value >= LONG_MIN && value <= LONG_MAX; }
#line 5057 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 204 "/home/fengyong/Desktop/p4c/ir/expression.def"
bool IR::Constant::fitsUint() const { return value >= 0 && value <= UINT_MAX; }
#line 5060 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 205 "/home/fengyong/Desktop/p4c/ir/expression.def"
bool IR::Constant::fitsUint64() const { return value >= 0 && value <= UINT64_MAX; }
#line 5063 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 206 "/home/fengyong/Desktop/p4c/ir/expression.def"
bool IR::Constant::fitsInt64() const { return value >= INT64_MIN && value <= INT64_MAX; }
#line 5066 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 207 "/home/fengyong/Desktop/p4c/ir/expression.def"
long IR::Constant::asLong() const {
        if (!fitsLong())
            ::error(ErrorType::ERR_OVERLIMIT, "%1$x: Value too large for long", this);
        return static_cast<long>(value); }
#line 5072 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 211 "/home/fengyong/Desktop/p4c/ir/expression.def"
int IR::Constant::asInt() const {
        if (!fitsInt())
            ::error(ErrorType::ERR_OVERLIMIT, "%1$x: Value too large for int", this);
        return static_cast<int>(value); }
#line 5078 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 215 "/home/fengyong/Desktop/p4c/ir/expression.def"
unsigned IR::Constant::asUnsigned() const {
        if (!fitsUint())
            ::error(ErrorType::ERR_OVERLIMIT, "%1$x: Value too large for unsigned int", this);
        return static_cast<unsigned>(value);
    }
#line 5085 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 220 "/home/fengyong/Desktop/p4c/ir/expression.def"
uint64_t IR::Constant::asUint64() const {
        if (!fitsUint64())
            ::error(ErrorType::ERR_OVERLIMIT, "%1$x: Value too large for uint64", this);
        return static_cast<uint64_t>(value);
    }
#line 5092 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 225 "/home/fengyong/Desktop/p4c/ir/expression.def"
int64_t IR::Constant::asInt64() const {
        if (!fitsInt64())
            ::error(ErrorType::ERR_OVERLIMIT, "%1$x: Value too large for int64", this);
        return static_cast<int64_t>(value);
    }
#line 5099 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"



#line 242 "/home/fengyong/Desktop/p4c/ir/expression.def"
cstring IR::Constant::toString() const {
        const IR::Type_Bits* tb = dynamic_cast<const IR::Type_Bits*>(type);
        unsigned width;
        bool sign;
        if (tb == nullptr) {
            width = 0;
            sign = false;
        } else {
            width = tb->size;
            sign = tb->isSigned;
        }
        return Util::toString(value, width, sign, base);
    }
#line 5117 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 255 "/home/fengyong/Desktop/p4c/ir/expression.def"
void IR::Constant::visit_children(Visitor & v) { v.visit(type, "type"); }
#line 255 "/home/fengyong/Desktop/p4c/ir/expression.def"
void IR::Constant::visit_children(Visitor & v) const { v.visit(type, "type"); }
#line 5122 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Constant::operator==(IR::Constant const & a) const {
        return Literal::operator==(static_cast<const Literal &>(a))
        && value == a.value
        && base == a.base;
    }
bool IR::Constant::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Literal::equiv(a_)) return false;
        auto &a = static_cast<const Constant &>(a_);
        return value == a.value
        && base == a.base;
    }
void IR::Constant::dump_fields(std::ostream & out) const {
    Literal::dump_fields(out);
        out << " value=" << value;
        out << " base=" << base;
}
void IR::Constant::toJSON(JSONGenerator & json) const {
    Literal::toJSON(json);
    json << "," << std::endl << json.indent << "\"value\" : " << this->value;
    json << "," << std::endl << json.indent << "\"base\" : " << this->base;
}
IR::Constant::Constant(JSONLoader & json) : Literal(json) {
    json.load("value", value);
    json.load("base", base);
}
IR::Node * IR::Constant::fromJSON(JSONLoader & json) { return new Constant(json); }
#line 260 "/home/fengyong/Desktop/p4c/ir/expression.def"
cstring IR::BoolLiteral::toString() const { return value ? "true" : "false"; }
#line 5152 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::BoolLiteral::operator==(IR::BoolLiteral const & a) const {
        return Literal::operator==(static_cast<const Literal &>(a))
        && value == a.value;
    }
bool IR::BoolLiteral::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Literal::equiv(a_)) return false;
        auto &a = static_cast<const BoolLiteral &>(a_);
        return value == a.value;
    }
void IR::BoolLiteral::dump_fields(std::ostream & out) const {
    Literal::dump_fields(out);
        out << " value=" << value;
}
void IR::BoolLiteral::toJSON(JSONGenerator & json) const {
    Literal::toJSON(json);
    json << "," << std::endl << json.indent << "\"value\" : " << this->value;
}
IR::BoolLiteral::BoolLiteral(JSONLoader & json) : Literal(json) {
    json.load("value", value);
}
IR::Node * IR::BoolLiteral::fromJSON(JSONLoader & json) { return new BoolLiteral(json); }
IR::BoolLiteral::BoolLiteral(Util::SourceInfo srcInfo, const IR::Type* type, bool value) :
    Literal(srcInfo, type), value(value)
    { validate(); }
IR::BoolLiteral::BoolLiteral(const IR::Type* type, bool value) :
    Literal(type), value(value)
    { validate(); }
IR::BoolLiteral::BoolLiteral(Util::SourceInfo srcInfo, bool value) :
    Literal(srcInfo), value(value)
    { validate(); }
IR::BoolLiteral::BoolLiteral(bool value) :
    value(value)
    { validate(); }
#line 265 "/home/fengyong/Desktop/p4c/ir/expression.def"
void IR::StringLiteral::validate() const {
#line 5189 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

#line 265 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (value.isNull()) BUG("null StringLiteral"); } }
#line 5193 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 266 "/home/fengyong/Desktop/p4c/ir/expression.def"
cstring IR::StringLiteral::toString() const { return cstring("\"") + value.escapeJson() + "\""; }
#line 5196 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 267 "/home/fengyong/Desktop/p4c/ir/expression.def"
IR::StringLiteral::StringLiteral(IR::ID v) : Literal(v.srcInfo), value(v.name) {}
#line 5199 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::StringLiteral::operator==(IR::StringLiteral const & a) const {
        return Literal::operator==(static_cast<const Literal &>(a))
        && value == a.value;
    }
bool IR::StringLiteral::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Literal::equiv(a_)) return false;
        auto &a = static_cast<const StringLiteral &>(a_);
        return value == a.value;
    }
void IR::StringLiteral::dump_fields(std::ostream & out) const {
    Literal::dump_fields(out);
        out << " value=" << value;
}
void IR::StringLiteral::toJSON(JSONGenerator & json) const {
    Literal::toJSON(json);
    json << "," << std::endl << json.indent << "\"value\" : " << this->value;
}
IR::StringLiteral::StringLiteral(JSONLoader & json) : Literal(json) {
    json.load("value", value);
}
IR::Node * IR::StringLiteral::fromJSON(JSONLoader & json) { return new StringLiteral(json); }
IR::StringLiteral::StringLiteral(Util::SourceInfo srcInfo, const IR::Type* type, cstring value) :
    Literal(srcInfo, type), value(value)
    { validate(); }
IR::StringLiteral::StringLiteral(const IR::Type* type, cstring value) :
    Literal(type), value(value)
    { validate(); }
IR::StringLiteral::StringLiteral(Util::SourceInfo srcInfo, cstring value) :
    Literal(srcInfo), value(value)
    { validate(); }
IR::StringLiteral::StringLiteral(cstring value) :
    value(value)
    { validate(); }
#line 276 "/home/fengyong/Desktop/p4c/ir/expression.def"
IR::PathExpression::PathExpression(IR::ID id) : Expression(id.srcInfo), path(new IR::Path(id)) {}
#line 5236 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 277 "/home/fengyong/Desktop/p4c/ir/expression.def"
cstring IR::PathExpression::toString() const { return path->toString(); }
#line 5239 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::PathExpression::operator==(IR::PathExpression const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && path == a.path;
    }
bool IR::PathExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const PathExpression &>(a_);
        return (path ? a.path ? path->equiv(*a.path) : false : a.path == nullptr);
    }
void IR::PathExpression::visit_children(Visitor & v) {
    Expression::visit_children(v);
    v.visit(path, "path");
}
void IR::PathExpression::visit_children(Visitor & v) const {
    Expression::visit_children(v);
    v.visit(path, "path");
}
void IR::PathExpression::validate() const {
#line 5259 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(path); }
void IR::PathExpression::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"path\" : " << this->path;
}
IR::PathExpression::PathExpression(JSONLoader & json) : Expression(json) {
    json.load("path", path);
}
IR::Node * IR::PathExpression::fromJSON(JSONLoader & json) { return new PathExpression(json); }
IR::PathExpression::PathExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Path* path) :
    Expression(srcInfo, type), path(path)
    {
#line 275 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (!srcInfo && path) srcInfo = path->srcInfo; }
#line 5275 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::PathExpression::PathExpression(const IR::Type* type, const IR::Path* path) :
    Expression(type), path(path)
    {
#line 275 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (!srcInfo && path) srcInfo = path->srcInfo; }
#line 5282 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::PathExpression::PathExpression(Util::SourceInfo srcInfo, const IR::Path* path) :
    Expression(srcInfo), path(path)
    {
#line 275 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (!srcInfo && path) srcInfo = path->srcInfo; }
#line 5289 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::PathExpression::PathExpression(const IR::Path* path) :
    path(path)
    {
#line 275 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (!srcInfo && path) srcInfo = path->srcInfo; }
#line 5296 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
#line 286 "/home/fengyong/Desktop/p4c/ir/expression.def"
IR::TypeNameExpression::TypeNameExpression(IR::ID id) : Expression(id.srcInfo),
                                typeName(new IR::Type_Name(new IR::Path(id))) {}
#line 5301 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 288 "/home/fengyong/Desktop/p4c/ir/expression.def"
void IR::TypeNameExpression::dbprint(std::ostream & out) const { out << typeName; }
#line 5304 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 289 "/home/fengyong/Desktop/p4c/ir/expression.def"
cstring IR::TypeNameExpression::toString() const { return typeName->toString(); }
#line 5307 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 290 "/home/fengyong/Desktop/p4c/ir/expression.def"
void IR::TypeNameExpression::validate() const {
#line 5310 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(typeName);
#line 290 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ BUG_CHECK(typeName->is<Type_Name>() || typeName->is<Type_Specialized>(),
                         "%1 unexpected type in TypeNameExpression", typeName); } }
#line 5316 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::TypeNameExpression::operator==(IR::TypeNameExpression const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && typeName == a.typeName;
    }
bool IR::TypeNameExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const TypeNameExpression &>(a_);
        return (typeName ? a.typeName ? typeName->equiv(*a.typeName) : false : a.typeName == nullptr);
    }
void IR::TypeNameExpression::visit_children(Visitor & v) {
    Expression::visit_children(v);
    v.visit(typeName, "typeName");
}
void IR::TypeNameExpression::visit_children(Visitor & v) const {
    Expression::visit_children(v);
    v.visit(typeName, "typeName");
}
void IR::TypeNameExpression::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"typeName\" : " << this->typeName;
}
IR::TypeNameExpression::TypeNameExpression(JSONLoader & json) : Expression(json) {
    json.load("typeName", typeName);
}
IR::Node * IR::TypeNameExpression::fromJSON(JSONLoader & json) { return new TypeNameExpression(json); }
IR::TypeNameExpression::TypeNameExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Type* typeName) :
    Expression(srcInfo, type), typeName(typeName)
    {
#line 285 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (!srcInfo && typeName) srcInfo = typeName->srcInfo; }
#line 5348 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::TypeNameExpression::TypeNameExpression(const IR::Type* type, const IR::Type* typeName) :
    Expression(type), typeName(typeName)
    {
#line 285 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (!srcInfo && typeName) srcInfo = typeName->srcInfo; }
#line 5355 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::TypeNameExpression::TypeNameExpression(Util::SourceInfo srcInfo, const IR::Type* typeName) :
    Expression(srcInfo), typeName(typeName)
    {
#line 285 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (!srcInfo && typeName) srcInfo = typeName->srcInfo; }
#line 5362 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::TypeNameExpression::TypeNameExpression(const IR::Type* typeName) :
    typeName(typeName)
    {
#line 285 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (!srcInfo && typeName) srcInfo = typeName->srcInfo; }
#line 5369 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
#line 297 "/home/fengyong/Desktop/p4c/ir/expression.def"
cstring IR::Slice::toString() const { return e0->toString() + "[" + e1->toString() + ":" + e2->toString() + "]"; }
#line 5373 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

#line 299 "/home/fengyong/Desktop/p4c/ir/expression.def"
unsigned IR::Slice::getH() const { return e1->to<IR::Constant>()->asUnsigned(); }
#line 5377 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 300 "/home/fengyong/Desktop/p4c/ir/expression.def"
unsigned IR::Slice::getL() const { return e2->to<IR::Constant>()->asUnsigned(); }
#line 5380 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 301 "/home/fengyong/Desktop/p4c/ir/expression.def"
IR::Slice::Slice(const IR::Expression* a, int hi, int lo) : Operation_Ternary(IR::Type::Bits::get(hi-lo+1), a, new Constant(hi), new Constant(lo)) {}
#line 5383 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 303 "/home/fengyong/Desktop/p4c/ir/expression.def"
IR::Slice::Slice(Util::SourceInfo si, const IR::Expression* a, int hi, int lo) : Operation_Ternary(si, IR::Type::Bits::get(hi-lo+1), a, new Constant(hi), new Constant(lo)) {}
#line 5386 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

bool IR::Slice::operator==(IR::Slice const & a) const {
        return Operation_Ternary::operator==(static_cast<const Operation_Ternary &>(a));
    }
bool IR::Slice::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Ternary::equiv(a_)) return false;
        return true;
    }
void IR::Slice::toJSON(JSONGenerator & json) const {
    Operation_Ternary::toJSON(json);
}
IR::Slice::Slice(JSONLoader & json) : Operation_Ternary(json) {
}
IR::Node * IR::Slice::fromJSON(JSONLoader & json) { return new Slice(json); }
IR::Slice::Slice(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation_Ternary(srcInfo, type, e0, e1, e2)
    {
#line 305 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        if (type->is<Type::Unknown>() && e1 && e1->is<Constant>() && e2 && e2->is<Constant>())
            type = IR::Type::Bits::get(getH() - getL() + 1); }
#line 5409 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Slice::Slice(const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation_Ternary(type, e0, e1, e2)
    {
#line 305 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        if (type->is<Type::Unknown>() && e1 && e1->is<Constant>() && e2 && e2->is<Constant>())
            type = IR::Type::Bits::get(getH() - getL() + 1); }
#line 5418 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Slice::Slice(Util::SourceInfo srcInfo, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation_Ternary(srcInfo, e0, e1, e2)
    {
#line 305 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        if (type->is<Type::Unknown>() && e1 && e1->is<Constant>() && e2 && e2->is<Constant>())
            type = IR::Type::Bits::get(getH() - getL() + 1); }
#line 5427 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Slice::Slice(const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation_Ternary(e0, e1, e2)
    {
#line 305 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        if (type->is<Type::Unknown>() && e1 && e1->is<Constant>() && e2 && e2->is<Constant>())
            type = IR::Type::Bits::get(getH() - getL() + 1); }
#line 5436 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
#line 319 "/home/fengyong/Desktop/p4c/ir/expression.def"
cstring IR::Member::toString() const { return expr->toString() + "." + member; }
#line 5440 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Member::operator==(IR::Member const & a) const {
        return Operation_Unary::operator==(static_cast<const Operation_Unary &>(a))
        && member == a.member;
    }
bool IR::Member::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Unary::equiv(a_)) return false;
        auto &a = static_cast<const Member &>(a_);
        return member == a.member;
    }
void IR::Member::dump_fields(std::ostream & out) const {
    Operation_Unary::dump_fields(out);
        out << " member=" << member;
}
void IR::Member::toJSON(JSONGenerator & json) const {
    Operation_Unary::toJSON(json);
    json << "," << std::endl << json.indent << "\"member\" : " << this->member;
}
IR::Member::Member(JSONLoader & json) : Operation_Unary(json) {
    json.load("member", member);
}
IR::Node * IR::Member::fromJSON(JSONLoader & json) { return new Member(json); }
IR::Member::Member(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr, IR::ID member) :
    Operation_Unary(srcInfo, type, expr), member(member)
    { validate(); }
IR::Member::Member(const IR::Type* type, const IR::Expression* expr, IR::ID member) :
    Operation_Unary(type, expr), member(member)
    { validate(); }
IR::Member::Member(Util::SourceInfo srcInfo, const IR::Expression* expr, IR::ID member) :
    Operation_Unary(srcInfo, expr), member(member)
    { validate(); }
IR::Member::Member(const IR::Expression* expr, IR::ID member) :
    Operation_Unary(expr), member(member)
    { validate(); }
bool IR::Concat::operator==(IR::Concat const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Concat::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Concat::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Concat::Concat(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Concat::fromJSON(JSONLoader & json) { return new Concat(json); }
IR::Concat::Concat(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    {
#line 325 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        if (left && right) {
            auto lt = left->type->to<IR::Type::Bits>();
            auto rt = right->type->to<IR::Type::Bits>();
            if (lt && rt)
                type = IR::Type::Bits::get(lt->size + rt->size, lt->isSigned); } }
#line 5499 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Concat::Concat(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    {
#line 325 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        if (left && right) {
            auto lt = left->type->to<IR::Type::Bits>();
            auto rt = right->type->to<IR::Type::Bits>();
            if (lt && rt)
                type = IR::Type::Bits::get(lt->size + rt->size, lt->isSigned); } }
#line 5511 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Concat::Concat(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    {
#line 325 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        if (left && right) {
            auto lt = left->type->to<IR::Type::Bits>();
            auto rt = right->type->to<IR::Type::Bits>();
            if (lt && rt)
                type = IR::Type::Bits::get(lt->size + rt->size, lt->isSigned); } }
#line 5523 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Concat::Concat(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    {
#line 325 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        if (left && right) {
            auto lt = left->type->to<IR::Type::Bits>();
            auto rt = right->type->to<IR::Type::Bits>();
            if (lt && rt)
                type = IR::Type::Bits::get(lt->size + rt->size, lt->isSigned); } }
#line 5535 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
#line 339 "/home/fengyong/Desktop/p4c/ir/expression.def"
cstring IR::ArrayIndex::toString() const { return left->toString() + "[" + right->toString() + "]"; }
#line 5539 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::ArrayIndex::operator==(IR::ArrayIndex const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::ArrayIndex::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::ArrayIndex::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::ArrayIndex::ArrayIndex(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::ArrayIndex::fromJSON(JSONLoader & json) { return new ArrayIndex(json); }
IR::ArrayIndex::ArrayIndex(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    {
#line 336 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        if (auto st = left ? left->type->to<IR::Type_Stack>() : nullptr)
            type = st->elementType; }
#line 5561 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::ArrayIndex::ArrayIndex(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    {
#line 336 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        if (auto st = left ? left->type->to<IR::Type_Stack>() : nullptr)
            type = st->elementType; }
#line 5570 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::ArrayIndex::ArrayIndex(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    {
#line 336 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        if (auto st = left ? left->type->to<IR::Type_Stack>() : nullptr)
            type = st->elementType; }
#line 5579 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::ArrayIndex::ArrayIndex(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    {
#line 336 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        if (auto st = left ? left->type->to<IR::Type_Stack>() : nullptr)
            type = st->elementType; }
#line 5588 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
bool IR::Range::operator==(IR::Range const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Range::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Range::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Range::Range(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Range::fromJSON(JSONLoader & json) { return new Range(json); }
IR::Range::Range(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    {
#line 345 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (left && type == left->type && !left->type->is<Type::Unknown>())
                type = new Type_Set(left->type); }
#line 5610 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Range::Range(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    {
#line 345 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (left && type == left->type && !left->type->is<Type::Unknown>())
                type = new Type_Set(left->type); }
#line 5618 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Range::Range(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    {
#line 345 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (left && type == left->type && !left->type->is<Type::Unknown>())
                type = new Type_Set(left->type); }
#line 5626 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Range::Range(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    {
#line 345 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (left && type == left->type && !left->type->is<Type::Unknown>())
                type = new Type_Set(left->type); }
#line 5634 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
bool IR::Mask::operator==(IR::Mask const & a) const {
        return Operation_Binary::operator==(static_cast<const Operation_Binary &>(a));
    }
bool IR::Mask::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Binary::equiv(a_)) return false;
        return true;
    }
void IR::Mask::toJSON(JSONGenerator & json) const {
    Operation_Binary::toJSON(json);
}
IR::Mask::Mask(JSONLoader & json) : Operation_Binary(json) {
}
IR::Node * IR::Mask::fromJSON(JSONLoader & json) { return new Mask(json); }
IR::Mask::Mask(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, type, left, right)
    {
#line 352 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (left && type == left->type && !left->type->is<Type::Unknown>())
                type = new Type_Set(left->type); }
#line 5656 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Mask::Mask(const IR::Type* type, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(type, left, right)
    {
#line 352 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (left && type == left->type && !left->type->is<Type::Unknown>())
                type = new Type_Set(left->type); }
#line 5664 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Mask::Mask(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(srcInfo, left, right)
    {
#line 352 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (left && type == left->type && !left->type->is<Type::Unknown>())
                type = new Type_Set(left->type); }
#line 5672 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Mask::Mask(const IR::Expression* left, const IR::Expression* right) :
    Operation_Binary(left, right)
    {
#line 352 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (left && type == left->type && !left->type->is<Type::Unknown>())
                type = new Type_Set(left->type); }
#line 5680 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
#line 359 "/home/fengyong/Desktop/p4c/ir/expression.def"
void IR::Mux::visit_children(Visitor & v) {
        v.visit(e0, "e0");
        SplitFlowVisit<Expression>(v, e1, e2).run_visit(); }
#line 359 "/home/fengyong/Desktop/p4c/ir/expression.def"
void IR::Mux::visit_children(Visitor & v) const {
        v.visit(e0, "e0");
        SplitFlowVisit<Expression>(v, e1, e2).run_visit(); }
#line 5690 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Mux::operator==(IR::Mux const & a) const {
        return Operation_Ternary::operator==(static_cast<const Operation_Ternary &>(a));
    }
bool IR::Mux::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Ternary::equiv(a_)) return false;
        return true;
    }
void IR::Mux::toJSON(JSONGenerator & json) const {
    Operation_Ternary::toJSON(json);
}
IR::Mux::Mux(JSONLoader & json) : Operation_Ternary(json) {
}
IR::Node * IR::Mux::fromJSON(JSONLoader & json) { return new Mux(json); }
IR::Mux::Mux(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation_Ternary(srcInfo, type, e0, e1, e2)
    {
#line 362 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (type->is<Type::Unknown>() && e1 && e2 && e1->type == e2->type) type = e1->type; }
#line 5710 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Mux::Mux(const IR::Type* type, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation_Ternary(type, e0, e1, e2)
    {
#line 362 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (type->is<Type::Unknown>() && e1 && e2 && e1->type == e2->type) type = e1->type; }
#line 5717 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Mux::Mux(Util::SourceInfo srcInfo, const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation_Ternary(srcInfo, e0, e1, e2)
    {
#line 362 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (type->is<Type::Unknown>() && e1 && e2 && e1->type == e2->type) type = e1->type; }
#line 5724 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::Mux::Mux(const IR::Expression* e0, const IR::Expression* e1, const IR::Expression* e2) :
    Operation_Ternary(e0, e1, e2)
    {
#line 362 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ if (type->is<Type::Unknown>() && e1 && e2 && e1->type == e2->type) type = e1->type; }
#line 5731 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
bool IR::DefaultExpression::operator==(IR::DefaultExpression const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a));
    }
bool IR::DefaultExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        return true;
    }
void IR::DefaultExpression::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
}
IR::DefaultExpression::DefaultExpression(JSONLoader & json) : Expression(json) {
}
IR::Node * IR::DefaultExpression::fromJSON(JSONLoader & json) { return new DefaultExpression(json); }
IR::DefaultExpression::DefaultExpression(Util::SourceInfo srcInfo, const IR::Type* type) :
    Expression(srcInfo, type)
    { validate(); }
IR::DefaultExpression::DefaultExpression(const IR::Type* type) :
    Expression(type)
    { validate(); }
IR::DefaultExpression::DefaultExpression(Util::SourceInfo srcInfo) :
    Expression(srcInfo)
    { validate(); }
IR::DefaultExpression::DefaultExpression() 
    { validate(); }
#line 371 "/home/fengyong/Desktop/p4c/ir/expression.def"
cstring IR::This::toString() const { return "this"; }
#line 5760 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::This::operator==(IR::This const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && id == a.id;
    }
bool IR::This::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const This &>(a_);
        return id == a.id;
    }
void IR::This::dump_fields(std::ostream & out) const {
    Expression::dump_fields(out);
        out << " id=" << id;
}
void IR::This::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"id\" : " << this->id;
}
IR::This::This(JSONLoader & json) : Expression(json) {
    json.load("id", id);
}
IR::Node * IR::This::fromJSON(JSONLoader & json) { return new This(json); }
IR::This::This(Util::SourceInfo srcInfo, const IR::Type* type) :
    Expression(srcInfo, type)
    { validate(); }
IR::This::This(const IR::Type* type) :
    Expression(type)
    { validate(); }
IR::This::This(Util::SourceInfo srcInfo) :
    Expression(srcInfo)
    { validate(); }
IR::This::This() 
    { validate(); }
/// These will generally always be the same, except when a cast to a type argument of
/// a generic occurs.  Then at some point, the 'destType' will be specialized to a concrete
/// type, and 'type' will only be updated later when type inferencing occurs
#line 383 "/home/fengyong/Desktop/p4c/ir/expression.def"
cstring IR::Cast::toString() const { return "(" + destType->toString() + ")" + expr->toString(); }
#line 5799 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 384 "/home/fengyong/Desktop/p4c/ir/expression.def"
void IR::Cast::validate() const {
#line 5802 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(destType);
#line 384 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ BUG_CHECK(!destType->is<Type_Unknown>(), "%1%: Cannot cast to unknown type", this); } }
#line 5807 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Cast::operator==(IR::Cast const & a) const {
        return Operation_Unary::operator==(static_cast<const Operation_Unary &>(a))
        && destType == a.destType;
    }
bool IR::Cast::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Unary::equiv(a_)) return false;
        auto &a = static_cast<const Cast &>(a_);
        return (destType ? a.destType ? destType->equiv(*a.destType) : false : a.destType == nullptr);
    }
void IR::Cast::visit_children(Visitor & v) {
    Operation_Unary::visit_children(v);
    v.visit(destType, "destType");
}
void IR::Cast::visit_children(Visitor & v) const {
    Operation_Unary::visit_children(v);
    v.visit(destType, "destType");
}
void IR::Cast::toJSON(JSONGenerator & json) const {
    Operation_Unary::toJSON(json);
    json << "," << std::endl << json.indent << "\"destType\" : " << this->destType;
}
IR::Cast::Cast(JSONLoader & json) : Operation_Unary(json) {
    json.load("destType", destType);
}
IR::Node * IR::Cast::fromJSON(JSONLoader & json) { return new Cast(json); }
IR::Cast::Cast(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(srcInfo, type, expr)
    { validate(); }
IR::Cast::Cast(const IR::Type* type, const IR::Expression* expr) :
    Operation_Unary(type, expr)
    { validate(); }
IR::Cast::Cast(Util::SourceInfo srcInfo, const IR::Expression* expr) :
    Operation_Unary(srcInfo, expr)
    { validate(); }
IR::Cast::Cast(const IR::Expression* expr) :
    Operation_Unary(expr)
    { validate(); }
#line 390 "/home/fengyong/Desktop/p4c/ir/expression.def"
void IR::SelectCase::dbprint(std::ostream & out) const { out << keyset << ": " << state; }
#line 5848 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::SelectCase::operator==(IR::SelectCase const & a) const {
        return typeid(*this) == typeid(a)
        && keyset == a.keyset
        && state == a.state;
    }
bool IR::SelectCase::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const SelectCase &>(a_);
        return (keyset ? a.keyset ? keyset->equiv(*a.keyset) : false : a.keyset == nullptr)
        && (state ? a.state ? state->equiv(*a.state) : false : a.state == nullptr);
    }
void IR::SelectCase::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(keyset, "keyset");
    v.visit(state, "state");
}
void IR::SelectCase::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(keyset, "keyset");
    v.visit(state, "state");
}
void IR::SelectCase::validate() const {
#line 5872 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(keyset);
        CHECK_NULL(state); }
void IR::SelectCase::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"keyset\" : " << this->keyset;
    json << "," << std::endl << json.indent << "\"state\" : " << this->state;
}
IR::SelectCase::SelectCase(JSONLoader & json) : Node(json) {
    json.load("keyset", keyset);
    json.load("state", state);
}
IR::Node * IR::SelectCase::fromJSON(JSONLoader & json) { return new SelectCase(json); }
IR::SelectCase::SelectCase(Util::SourceInfo srcInfo, const IR::Expression* keyset, const IR::PathExpression* state) :
    Node(srcInfo), keyset(keyset), state(state)
    { validate(); }
IR::SelectCase::SelectCase(const IR::Expression* keyset, const IR::PathExpression* state) :
    keyset(keyset), state(state)
    { validate(); }
#line 396 "/home/fengyong/Desktop/p4c/ir/expression.def"
void IR::SelectExpression::visit_children(Visitor & v) {
        v.visit(select, "select");
        SplitFlowVisitVector<SelectCase>(v, selectCases).run_visit(); }
#line 396 "/home/fengyong/Desktop/p4c/ir/expression.def"
void IR::SelectExpression::visit_children(Visitor & v) const {
        v.visit(select, "select");
        SplitFlowVisitVector<SelectCase>(v, selectCases).run_visit(); }
#line 5900 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::SelectExpression::operator==(IR::SelectExpression const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && select == a.select
        && selectCases == a.selectCases;
    }
bool IR::SelectExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const SelectExpression &>(a_);
        return (select ? a.select ? select->equiv(*a.select) : false : a.select == nullptr)
        && selectCases.equiv(a.selectCases);
    }
void IR::SelectExpression::validate() const {
#line 5914 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(select);
        selectCases.validate(); }
void IR::SelectExpression::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"select\" : " << this->select;
    json << "," << std::endl << json.indent << "\"selectCases\" : " << this->selectCases;
}
IR::SelectExpression::SelectExpression(JSONLoader & json) : Expression(json) {
    json.load("select", select);
    json.load("selectCases", selectCases);
}
IR::Node * IR::SelectExpression::fromJSON(JSONLoader & json) { return new SelectExpression(json); }
IR::SelectExpression::SelectExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::ListExpression* select, IR::Vector<IR::SelectCase> selectCases) :
    Expression(srcInfo, type), select(select), selectCases(selectCases)
    { validate(); }
IR::SelectExpression::SelectExpression(const IR::Type* type, const IR::ListExpression* select, IR::Vector<IR::SelectCase> selectCases) :
    Expression(type), select(select), selectCases(selectCases)
    { validate(); }
IR::SelectExpression::SelectExpression(Util::SourceInfo srcInfo, const IR::ListExpression* select, IR::Vector<IR::SelectCase> selectCases) :
    Expression(srcInfo), select(select), selectCases(selectCases)
    { validate(); }
IR::SelectExpression::SelectExpression(const IR::ListExpression* select, IR::Vector<IR::SelectCase> selectCases) :
    select(select), selectCases(selectCases)
    { validate(); }
#line 405 "/home/fengyong/Desktop/p4c/ir/expression.def"
cstring IR::MethodCallExpression::toString() const { return method->toString(); }
#line 5942 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 406 "/home/fengyong/Desktop/p4c/ir/expression.def"
void IR::MethodCallExpression::validate() const {
#line 5945 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(method);
        CHECK_NULL(typeArguments);
        CHECK_NULL(arguments);
#line 406 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ typeArguments->check_null(); arguments->check_null(); } }
#line 5952 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 407 "/home/fengyong/Desktop/p4c/ir/expression.def"
IR::MethodCallExpression::MethodCallExpression(Util::SourceInfo si, IR::ID m, std::initializer_list<const IR::Argument *> const & a) : Expression(si), method(new PathExpression(m)), arguments(new Vector<Argument>(a)) {}
#line 5955 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 409 "/home/fengyong/Desktop/p4c/ir/expression.def"
IR::MethodCallExpression::MethodCallExpression(Util::SourceInfo si, const IR::Expression* m, std::initializer_list<const IR::Argument *> const & a) : Expression(si), method(m), arguments(new Vector<Argument>(a)) {}
#line 5958 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 412 "/home/fengyong/Desktop/p4c/ir/expression.def"
IR::MethodCallExpression::MethodCallExpression(const IR::Expression* m, std::initializer_list<IR::Expression const *> const & a) : method(m), arguments(nullptr)  {
        auto arguments = new Vector<Argument>;
        for (auto arg : a) arguments->push_back(new Argument(arg));
        this->arguments = arguments; }
#line 5964 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::MethodCallExpression::operator==(IR::MethodCallExpression const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && method == a.method
        && typeArguments == a.typeArguments
        && arguments == a.arguments;
    }
bool IR::MethodCallExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const MethodCallExpression &>(a_);
        return (method ? a.method ? method->equiv(*a.method) : false : a.method == nullptr)
        && (typeArguments ? a.typeArguments ? typeArguments->equiv(*a.typeArguments) : false : a.typeArguments == nullptr)
        && (arguments ? a.arguments ? arguments->equiv(*a.arguments) : false : a.arguments == nullptr);
    }
void IR::MethodCallExpression::visit_children(Visitor & v) {
    Expression::visit_children(v);
    v.visit(method, "method");
    v.visit(typeArguments, "typeArguments");
    v.visit(arguments, "arguments");
}
void IR::MethodCallExpression::visit_children(Visitor & v) const {
    Expression::visit_children(v);
    v.visit(method, "method");
    v.visit(typeArguments, "typeArguments");
    v.visit(arguments, "arguments");
}
void IR::MethodCallExpression::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"method\" : " << this->method;
    json << "," << std::endl << json.indent << "\"typeArguments\" : " << this->typeArguments;
    json << "," << std::endl << json.indent << "\"arguments\" : " << this->arguments;
}
IR::MethodCallExpression::MethodCallExpression(JSONLoader & json) : Expression(json) {
    json.load("method", method);
    json.load("typeArguments", typeArguments);
    json.load("arguments", arguments);
}
IR::Node * IR::MethodCallExpression::fromJSON(JSONLoader & json) { return new MethodCallExpression(json); }
IR::MethodCallExpression::MethodCallExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments) :
    Expression(srcInfo, type), method(method), typeArguments(typeArguments), arguments(arguments)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments) :
    Expression(type), method(method), typeArguments(typeArguments), arguments(arguments)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(Util::SourceInfo srcInfo, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments) :
    Expression(srcInfo), method(method), typeArguments(typeArguments), arguments(arguments)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments) :
    method(method), typeArguments(typeArguments), arguments(arguments)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Argument>* arguments) :
    Expression(srcInfo, type), method(method), arguments(arguments)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Argument>* arguments) :
    Expression(type), method(method), arguments(arguments)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(Util::SourceInfo srcInfo, const IR::Expression* method, const IR::Vector<IR::Argument>* arguments) :
    Expression(srcInfo), method(method), arguments(arguments)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(const IR::Expression* method, const IR::Vector<IR::Argument>* arguments) :
    method(method), arguments(arguments)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments) :
    Expression(srcInfo, type), method(method), typeArguments(typeArguments)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments) :
    Expression(type), method(method), typeArguments(typeArguments)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(Util::SourceInfo srcInfo, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments) :
    Expression(srcInfo), method(method), typeArguments(typeArguments)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments) :
    method(method), typeArguments(typeArguments)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method) :
    Expression(srcInfo, type), method(method)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(const IR::Type* type, const IR::Expression* method) :
    Expression(type), method(method)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(Util::SourceInfo srcInfo, const IR::Expression* method) :
    Expression(srcInfo), method(method)
    { validate(); }
IR::MethodCallExpression::MethodCallExpression(const IR::Expression* method) :
    method(method)
    { validate(); }

#line 422 "/home/fengyong/Desktop/p4c/ir/expression.def"
cstring IR::ConstructorCallExpression::toString() const { return constructedType->toString(); }
#line 6054 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 423 "/home/fengyong/Desktop/p4c/ir/expression.def"
void IR::ConstructorCallExpression::validate() const {
#line 6057 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(constructedType);
        CHECK_NULL(arguments);
#line 423 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ BUG_CHECK(constructedType->is<Type_Name>() ||
                        constructedType->is<Type_Specialized>(),
                        "%1%: unexpected type", constructedType);
        arguments->check_null(); } }
#line 6066 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::ConstructorCallExpression::operator==(IR::ConstructorCallExpression const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && constructedType == a.constructedType
        && arguments == a.arguments;
    }
bool IR::ConstructorCallExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const ConstructorCallExpression &>(a_);
        return (constructedType ? a.constructedType ? constructedType->equiv(*a.constructedType) : false : a.constructedType == nullptr)
        && (arguments ? a.arguments ? arguments->equiv(*a.arguments) : false : a.arguments == nullptr);
    }
void IR::ConstructorCallExpression::visit_children(Visitor & v) {
    Expression::visit_children(v);
    v.visit(constructedType, "constructedType");
    v.visit(arguments, "arguments");
}
void IR::ConstructorCallExpression::visit_children(Visitor & v) const {
    Expression::visit_children(v);
    v.visit(constructedType, "constructedType");
    v.visit(arguments, "arguments");
}
void IR::ConstructorCallExpression::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"constructedType\" : " << this->constructedType;
    json << "," << std::endl << json.indent << "\"arguments\" : " << this->arguments;
}
IR::ConstructorCallExpression::ConstructorCallExpression(JSONLoader & json) : Expression(json) {
    json.load("constructedType", constructedType);
    json.load("arguments", arguments);
}
IR::Node * IR::ConstructorCallExpression::fromJSON(JSONLoader & json) { return new ConstructorCallExpression(json); }
IR::ConstructorCallExpression::ConstructorCallExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Vector<IR::Argument>* arguments) :
    Expression(srcInfo, type), arguments(arguments)
    { validate(); }
IR::ConstructorCallExpression::ConstructorCallExpression(const IR::Type* type, const IR::Vector<IR::Argument>* arguments) :
    Expression(type), arguments(arguments)
    { validate(); }
IR::ConstructorCallExpression::ConstructorCallExpression(Util::SourceInfo srcInfo, const IR::Vector<IR::Argument>* arguments) :
    Expression(srcInfo), arguments(arguments)
    { validate(); }
IR::ConstructorCallExpression::ConstructorCallExpression(const IR::Vector<IR::Argument>* arguments) :
    arguments(arguments)
    { validate(); }
#line 431 "/home/fengyong/Desktop/p4c/ir/expression.def"
void IR::BaseListExpression::validate() const {
#line 6113 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        components.validate();
#line 431 "/home/fengyong/Desktop/p4c/ir/expression.def"
{ components.check_null(); } }
#line 6118 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 432 "/home/fengyong/Desktop/p4c/ir/expression.def"
size_t IR::BaseListExpression::size() const { return components.size(); }
#line 6121 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 433 "/home/fengyong/Desktop/p4c/ir/expression.def"
void IR::BaseListExpression::push_back(const IR::Expression* e) { components.push_back(e); }
#line 6124 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 434 "/home/fengyong/Desktop/p4c/ir/expression.def"
bool IR::BaseListExpression::containsDots() const {
        if (components.empty())
            return false;
        size_t size = components.size();
        return components.at(size - 1)->is<IR::Dots>();
    }
#line 6132 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::BaseListExpression::operator==(IR::BaseListExpression const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && components == a.components;
    }
bool IR::BaseListExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const BaseListExpression &>(a_);
        return components.equiv(a.components);
    }
void IR::BaseListExpression::visit_children(Visitor & v) {
    Expression::visit_children(v);
    components.visit_children(v);
}
void IR::BaseListExpression::visit_children(Visitor & v) const {
    Expression::visit_children(v);
    components.visit_children(v);
}
void IR::BaseListExpression::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"components\" : " << this->components;
}
IR::BaseListExpression::BaseListExpression(JSONLoader & json) : Expression(json) {
    json.load("components", components);
}
IR::Node * IR::BaseListExpression::fromJSON(JSONLoader & json) { return new BaseListExpression(json); }
IR::BaseListExpression::BaseListExpression(Util::SourceInfo srcInfo, const IR::Type* type, IR::Vector<IR::Expression> components) :
    Expression(srcInfo, type), components(components)
    { validate(); }
IR::BaseListExpression::BaseListExpression(const IR::Type* type, IR::Vector<IR::Expression> components) :
    Expression(type), components(components)
    { validate(); }
IR::BaseListExpression::BaseListExpression(Util::SourceInfo srcInfo, IR::Vector<IR::Expression> components) :
    Expression(srcInfo), components(components)
    { validate(); }
IR::BaseListExpression::BaseListExpression(IR::Vector<IR::Expression> components) :
    components(components)
    { validate(); }
bool IR::ListExpression::operator==(IR::ListExpression const & a) const {
        return BaseListExpression::operator==(static_cast<const BaseListExpression &>(a));
    }
bool IR::ListExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!BaseListExpression::equiv(a_)) return false;
        return true;
    }
void IR::ListExpression::toJSON(JSONGenerator & json) const {
    BaseListExpression::toJSON(json);
}
IR::ListExpression::ListExpression(JSONLoader & json) : BaseListExpression(json) {
}
IR::Node * IR::ListExpression::fromJSON(JSONLoader & json) { return new ListExpression(json); }
IR::ListExpression::ListExpression(Util::SourceInfo srcInfo, const IR::Type* type, IR::Vector<IR::Expression> components) :
    BaseListExpression(srcInfo, type, components)
    {
#line 445 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        validate();
        if (type->is<Type::Unknown>()) {
            Vector<Type> tuple;
            for (auto e : components)
                tuple.push_back(e->type);
            type = new Type_List(tuple); } }
#line 6196 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::ListExpression::ListExpression(const IR::Type* type, IR::Vector<IR::Expression> components) :
    BaseListExpression(type, components)
    {
#line 445 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        validate();
        if (type->is<Type::Unknown>()) {
            Vector<Type> tuple;
            for (auto e : components)
                tuple.push_back(e->type);
            type = new Type_List(tuple); } }
#line 6209 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::ListExpression::ListExpression(Util::SourceInfo srcInfo, IR::Vector<IR::Expression> components) :
    BaseListExpression(srcInfo, components)
    {
#line 445 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        validate();
        if (type->is<Type::Unknown>()) {
            Vector<Type> tuple;
            for (auto e : components)
                tuple.push_back(e->type);
            type = new Type_List(tuple); } }
#line 6222 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::ListExpression::ListExpression(IR::Vector<IR::Expression> components) :
    BaseListExpression(components)
    {
#line 445 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        validate();
        if (type->is<Type::Unknown>()) {
            Vector<Type> tuple;
            for (auto e : components)
                tuple.push_back(e->type);
            type = new Type_List(tuple); } }
#line 6235 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
bool IR::P4ListExpression::operator==(IR::P4ListExpression const & a) const {
        return BaseListExpression::operator==(static_cast<const BaseListExpression &>(a))
        && elementType == a.elementType;
    }
bool IR::P4ListExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!BaseListExpression::equiv(a_)) return false;
        auto &a = static_cast<const P4ListExpression &>(a_);
        return (elementType ? a.elementType ? elementType->equiv(*a.elementType) : false : a.elementType == nullptr);
    }
void IR::P4ListExpression::visit_children(Visitor & v) {
    BaseListExpression::visit_children(v);
    v.visit(elementType, "elementType");
}
void IR::P4ListExpression::visit_children(Visitor & v) const {
    BaseListExpression::visit_children(v);
    v.visit(elementType, "elementType");
}
void IR::P4ListExpression::validate() const {
#line 6256 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(elementType); }
void IR::P4ListExpression::toJSON(JSONGenerator & json) const {
    BaseListExpression::toJSON(json);
    json << "," << std::endl << json.indent << "\"elementType\" : " << this->elementType;
}
IR::P4ListExpression::P4ListExpression(JSONLoader & json) : BaseListExpression(json) {
    json.load("elementType", elementType);
}
IR::Node * IR::P4ListExpression::fromJSON(JSONLoader & json) { return new P4ListExpression(json); }
IR::P4ListExpression::P4ListExpression(Util::SourceInfo srcInfo, const IR::Type* type, IR::Vector<IR::Expression> components, const IR::Type* elementType) :
    BaseListExpression(srcInfo, type, components), elementType(elementType)
    {
#line 458 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        validate();
        if (type->is<Type::Unknown>()) {
            type = new Type_P4List(elementType); } }
#line 6275 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::P4ListExpression::P4ListExpression(const IR::Type* type, IR::Vector<IR::Expression> components, const IR::Type* elementType) :
    BaseListExpression(type, components), elementType(elementType)
    {
#line 458 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        validate();
        if (type->is<Type::Unknown>()) {
            type = new Type_P4List(elementType); } }
#line 6285 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::P4ListExpression::P4ListExpression(Util::SourceInfo srcInfo, IR::Vector<IR::Expression> components, const IR::Type* elementType) :
    BaseListExpression(srcInfo, components), elementType(elementType)
    {
#line 458 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        validate();
        if (type->is<Type::Unknown>()) {
            type = new Type_P4List(elementType); } }
#line 6295 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::P4ListExpression::P4ListExpression(IR::Vector<IR::Expression> components, const IR::Type* elementType) :
    BaseListExpression(components), elementType(elementType)
    {
#line 458 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        validate();
        if (type->is<Type::Unknown>()) {
            type = new Type_P4List(elementType); } }
#line 6305 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
/// The struct or header type that is being intialized.
/// May only be known after type checking; so it can be nullptr.
#line 470 "/home/fengyong/Desktop/p4c/ir/expression.def"
void IR::StructExpression::validate() const {
#line 6311 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        components.validate();
#line 470 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        components.check_null(); components.validate();
        BUG_CHECK(structType == nullptr || structType->is<IR::Type_Name>() ||
                  structType->is<IR::Type_Specialized>(),
                  "%1%: unexpected struct type", this);
    } }
#line 6321 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 476 "/home/fengyong/Desktop/p4c/ir/expression.def"
size_t IR::StructExpression::size() const { return components.size(); }
#line 6324 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 477 "/home/fengyong/Desktop/p4c/ir/expression.def"
const IR::NamedExpression *IR::StructExpression::getField(cstring name) const {
        return components.getDeclaration<NamedExpression>(name); }
#line 6328 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 479 "/home/fengyong/Desktop/p4c/ir/expression.def"
bool IR::StructExpression::containsDots() const {
        if (components.empty())
            return false;
        size_t size = components.size();
        return components.at(size - 1)->is<IR::NamedDots>();
    }
#line 6336 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::StructExpression::operator==(IR::StructExpression const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && structType == a.structType
        && components == a.components;
    }
bool IR::StructExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const StructExpression &>(a_);
        return (structType ? a.structType ? structType->equiv(*a.structType) : false : a.structType == nullptr)
        && components.equiv(a.components);
    }
void IR::StructExpression::visit_children(Visitor & v) {
    Expression::visit_children(v);
    v.visit(structType, "structType");
    components.visit_children(v);
}
void IR::StructExpression::visit_children(Visitor & v) const {
    Expression::visit_children(v);
    v.visit(structType, "structType");
    components.visit_children(v);
}
void IR::StructExpression::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    if (structType != nullptr)     json << "," << std::endl << json.indent << "\"structType\" : " << this->structType;
    json << "," << std::endl << json.indent << "\"components\" : " << this->components;
}
IR::StructExpression::StructExpression(JSONLoader & json) : Expression(json) {
    json.load("structType", structType);
    json.load("components", components);
}
IR::Node * IR::StructExpression::fromJSON(JSONLoader & json) { return new StructExpression(json); }
IR::StructExpression::StructExpression(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Type* structType, IR::IndexedVector<IR::NamedExpression> components) :
    Expression(srcInfo, type), structType(structType), components(components)
    { validate(); }
IR::StructExpression::StructExpression(const IR::Type* type, const IR::Type* structType, IR::IndexedVector<IR::NamedExpression> components) :
    Expression(type), structType(structType), components(components)
    { validate(); }
IR::StructExpression::StructExpression(Util::SourceInfo srcInfo, const IR::Type* structType, IR::IndexedVector<IR::NamedExpression> components) :
    Expression(srcInfo), structType(structType), components(components)
    { validate(); }
IR::StructExpression::StructExpression(const IR::Type* structType, IR::IndexedVector<IR::NamedExpression> components) :
    structType(structType), components(components)
    { validate(); }
bool IR::Invalid::operator==(IR::Invalid const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a));
    }
bool IR::Invalid::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        return true;
    }
void IR::Invalid::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
}
IR::Invalid::Invalid(JSONLoader & json) : Expression(json) {
}
IR::Node * IR::Invalid::fromJSON(JSONLoader & json) { return new Invalid(json); }
IR::Invalid::Invalid(Util::SourceInfo srcInfo, const IR::Type* type) :
    Expression(srcInfo, type)
    { validate(); }
IR::Invalid::Invalid(const IR::Type* type) :
    Expression(type)
    { validate(); }
IR::Invalid::Invalid(Util::SourceInfo srcInfo) :
    Expression(srcInfo)
    { validate(); }
IR::Invalid::Invalid() 
    { validate(); }
bool IR::InvalidHeader::operator==(IR::InvalidHeader const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && headerType == a.headerType;
    }
bool IR::InvalidHeader::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const InvalidHeader &>(a_);
        return (headerType ? a.headerType ? headerType->equiv(*a.headerType) : false : a.headerType == nullptr);
    }
void IR::InvalidHeader::visit_children(Visitor & v) {
    Expression::visit_children(v);
    v.visit(headerType, "headerType");
}
void IR::InvalidHeader::visit_children(Visitor & v) const {
    Expression::visit_children(v);
    v.visit(headerType, "headerType");
}
void IR::InvalidHeader::validate() const {
#line 6425 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(headerType); }
void IR::InvalidHeader::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"headerType\" : " << this->headerType;
}
IR::InvalidHeader::InvalidHeader(JSONLoader & json) : Expression(json) {
    json.load("headerType", headerType);
}
IR::Node * IR::InvalidHeader::fromJSON(JSONLoader & json) { return new InvalidHeader(json); }
IR::InvalidHeader::InvalidHeader(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Type* headerType) :
    Expression(srcInfo, type), headerType(headerType)
    { validate(); }
IR::InvalidHeader::InvalidHeader(const IR::Type* type, const IR::Type* headerType) :
    Expression(type), headerType(headerType)
    { validate(); }
IR::InvalidHeader::InvalidHeader(Util::SourceInfo srcInfo, const IR::Type* headerType) :
    Expression(srcInfo), headerType(headerType)
    { validate(); }
IR::InvalidHeader::InvalidHeader(const IR::Type* headerType) :
    headerType(headerType)
    { validate(); }
bool IR::InvalidHeaderUnion::operator==(IR::InvalidHeaderUnion const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && headerUnionType == a.headerUnionType;
    }
bool IR::InvalidHeaderUnion::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const InvalidHeaderUnion &>(a_);
        return (headerUnionType ? a.headerUnionType ? headerUnionType->equiv(*a.headerUnionType) : false : a.headerUnionType == nullptr);
    }
void IR::InvalidHeaderUnion::visit_children(Visitor & v) {
    Expression::visit_children(v);
    v.visit(headerUnionType, "headerUnionType");
}
void IR::InvalidHeaderUnion::visit_children(Visitor & v) const {
    Expression::visit_children(v);
    v.visit(headerUnionType, "headerUnionType");
}
void IR::InvalidHeaderUnion::validate() const {
#line 6467 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(headerUnionType); }
void IR::InvalidHeaderUnion::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"headerUnionType\" : " << this->headerUnionType;
}
IR::InvalidHeaderUnion::InvalidHeaderUnion(JSONLoader & json) : Expression(json) {
    json.load("headerUnionType", headerUnionType);
}
IR::Node * IR::InvalidHeaderUnion::fromJSON(JSONLoader & json) { return new InvalidHeaderUnion(json); }
IR::InvalidHeaderUnion::InvalidHeaderUnion(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Type* headerUnionType) :
    Expression(srcInfo, type), headerUnionType(headerUnionType)
    { validate(); }
IR::InvalidHeaderUnion::InvalidHeaderUnion(const IR::Type* type, const IR::Type* headerUnionType) :
    Expression(type), headerUnionType(headerUnionType)
    { validate(); }
IR::InvalidHeaderUnion::InvalidHeaderUnion(Util::SourceInfo srcInfo, const IR::Type* headerUnionType) :
    Expression(srcInfo), headerUnionType(headerUnionType)
    { validate(); }
IR::InvalidHeaderUnion::InvalidHeaderUnion(const IR::Type* headerUnionType) :
    headerUnionType(headerUnionType)
    { validate(); }
/// May only be known after type checking; so it can be nullptr.
#line 505 "/home/fengyong/Desktop/p4c/ir/expression.def"
void IR::HeaderStackExpression::validate() const {
#line 6493 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

#line 505 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        components.check_null();
    } }
#line 6499 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::HeaderStackExpression::operator==(IR::HeaderStackExpression const & a) const {
        return BaseListExpression::operator==(static_cast<const BaseListExpression &>(a))
        && headerStackType == a.headerStackType;
    }
bool IR::HeaderStackExpression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!BaseListExpression::equiv(a_)) return false;
        auto &a = static_cast<const HeaderStackExpression &>(a_);
        return (headerStackType ? a.headerStackType ? headerStackType->equiv(*a.headerStackType) : false : a.headerStackType == nullptr);
    }
void IR::HeaderStackExpression::visit_children(Visitor & v) {
    BaseListExpression::visit_children(v);
    v.visit(headerStackType, "headerStackType");
}
void IR::HeaderStackExpression::visit_children(Visitor & v) const {
    BaseListExpression::visit_children(v);
    v.visit(headerStackType, "headerStackType");
}
void IR::HeaderStackExpression::toJSON(JSONGenerator & json) const {
    BaseListExpression::toJSON(json);
    if (headerStackType != nullptr)     json << "," << std::endl << json.indent << "\"headerStackType\" : " << this->headerStackType;
}
IR::HeaderStackExpression::HeaderStackExpression(JSONLoader & json) : BaseListExpression(json) {
    json.load("headerStackType", headerStackType);
}
IR::Node * IR::HeaderStackExpression::fromJSON(JSONLoader & json) { return new HeaderStackExpression(json); }
IR::HeaderStackExpression::HeaderStackExpression(Util::SourceInfo srcInfo, const IR::Type* type, IR::Vector<IR::Expression> components, const IR::Type* headerStackType) :
    BaseListExpression(srcInfo, type, components), headerStackType(headerStackType)
    { validate(); }
IR::HeaderStackExpression::HeaderStackExpression(const IR::Type* type, IR::Vector<IR::Expression> components, const IR::Type* headerStackType) :
    BaseListExpression(type, components), headerStackType(headerStackType)
    { validate(); }
IR::HeaderStackExpression::HeaderStackExpression(Util::SourceInfo srcInfo, IR::Vector<IR::Expression> components, const IR::Type* headerStackType) :
    BaseListExpression(srcInfo, components), headerStackType(headerStackType)
    { validate(); }
IR::HeaderStackExpression::HeaderStackExpression(IR::Vector<IR::Expression> components, const IR::Type* headerStackType) :
    BaseListExpression(components), headerStackType(headerStackType)
    { validate(); }
#line 514 "/home/fengyong/Desktop/p4c/ir/expression.def"
void IR::ListCompileTimeValue::validate() const {
#line 6540 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        components.validate();
#line 514 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        for (auto v : components)
            BUG_CHECK(v->is<CompileTimeValue>(), "%1%: not a compile-time value", v); } }
#line 6547 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::ListCompileTimeValue::operator==(IR::ListCompileTimeValue const & a) const {
        return typeid(*this) == typeid(a)
        && components == a.components;
    }
bool IR::ListCompileTimeValue::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const ListCompileTimeValue &>(a_);
        return components.equiv(a.components);
    }
void IR::ListCompileTimeValue::visit_children(Visitor & v) {
    Node::visit_children(v);
    components.visit_children(v);
}
void IR::ListCompileTimeValue::visit_children(Visitor & v) const {
    Node::visit_children(v);
    components.visit_children(v);
}
void IR::ListCompileTimeValue::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"components\" : " << this->components;
}
IR::ListCompileTimeValue::ListCompileTimeValue(JSONLoader & json) : Node(json) {
    json.load("components", components);
}
IR::Node * IR::ListCompileTimeValue::fromJSON(JSONLoader & json) { return new ListCompileTimeValue(json); }
IR::ListCompileTimeValue::ListCompileTimeValue(Util::SourceInfo srcInfo, IR::Vector<IR::Node> components) :
    Node(srcInfo), components(components)
    { validate(); }
IR::ListCompileTimeValue::ListCompileTimeValue(IR::Vector<IR::Node> components) :
    components(components)
    { validate(); }
#line 524 "/home/fengyong/Desktop/p4c/ir/expression.def"
void IR::P4ListCompileTimeValue::validate() const {
#line 6582 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        components.validate();
#line 524 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        for (auto v : components)
            BUG_CHECK(v->is<CompileTimeValue>(), "%1%: not a compile-time value", v); } }
#line 6589 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::P4ListCompileTimeValue::operator==(IR::P4ListCompileTimeValue const & a) const {
        return typeid(*this) == typeid(a)
        && components == a.components;
    }
bool IR::P4ListCompileTimeValue::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const P4ListCompileTimeValue &>(a_);
        return components.equiv(a.components);
    }
void IR::P4ListCompileTimeValue::visit_children(Visitor & v) {
    Node::visit_children(v);
    components.visit_children(v);
}
void IR::P4ListCompileTimeValue::visit_children(Visitor & v) const {
    Node::visit_children(v);
    components.visit_children(v);
}
void IR::P4ListCompileTimeValue::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"components\" : " << this->components;
}
IR::P4ListCompileTimeValue::P4ListCompileTimeValue(JSONLoader & json) : Node(json) {
    json.load("components", components);
}
IR::Node * IR::P4ListCompileTimeValue::fromJSON(JSONLoader & json) { return new P4ListCompileTimeValue(json); }
IR::P4ListCompileTimeValue::P4ListCompileTimeValue(Util::SourceInfo srcInfo, IR::Vector<IR::Node> components) :
    Node(srcInfo), components(components)
    { validate(); }
IR::P4ListCompileTimeValue::P4ListCompileTimeValue(IR::Vector<IR::Node> components) :
    components(components)
    { validate(); }
#line 534 "/home/fengyong/Desktop/p4c/ir/expression.def"
void IR::StructCompileTimeValue::validate() const {
#line 6624 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        components.validate();
#line 534 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        for (auto v : components)
            BUG_CHECK(v->is<CompileTimeValue>(), "%1%: not a compile-time value", v); } }
#line 6631 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::StructCompileTimeValue::operator==(IR::StructCompileTimeValue const & a) const {
        return typeid(*this) == typeid(a)
        && components == a.components;
    }
bool IR::StructCompileTimeValue::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const StructCompileTimeValue &>(a_);
        return components.equiv(a.components);
    }
void IR::StructCompileTimeValue::visit_children(Visitor & v) {
    Node::visit_children(v);
    components.visit_children(v);
}
void IR::StructCompileTimeValue::visit_children(Visitor & v) const {
    Node::visit_children(v);
    components.visit_children(v);
}
void IR::StructCompileTimeValue::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"components\" : " << this->components;
}
IR::StructCompileTimeValue::StructCompileTimeValue(JSONLoader & json) : Node(json) {
    json.load("components", components);
}
IR::Node * IR::StructCompileTimeValue::fromJSON(JSONLoader & json) { return new StructCompileTimeValue(json); }
IR::StructCompileTimeValue::StructCompileTimeValue(Util::SourceInfo srcInfo, IR::Vector<IR::Node> components) :
    Node(srcInfo), components(components)
    { validate(); }
IR::StructCompileTimeValue::StructCompileTimeValue(IR::Vector<IR::Node> components) :
    components(components)
    { validate(); }
#line 543 "/home/fengyong/Desktop/p4c/ir/expression.def"
IR::CompileTimeMethodCall::CompileTimeMethodCall(const IR::MethodCallExpression* e) : MethodCallExpression(*e) {}
#line 6666 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 544 "/home/fengyong/Desktop/p4c/ir/expression.def"
void IR::CompileTimeMethodCall::validate() const {
#line 6669 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

#line 544 "/home/fengyong/Desktop/p4c/ir/expression.def"
{
        for (auto v : *arguments)
            BUG_CHECK(v->is<CompileTimeValue>(), "%1%: not a compile-time value", v); } }
#line 6675 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::CompileTimeMethodCall::operator==(IR::CompileTimeMethodCall const & a) const {
        return MethodCallExpression::operator==(static_cast<const MethodCallExpression &>(a));
    }
bool IR::CompileTimeMethodCall::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!MethodCallExpression::equiv(a_)) return false;
        return true;
    }
void IR::CompileTimeMethodCall::toJSON(JSONGenerator & json) const {
    MethodCallExpression::toJSON(json);
}
IR::CompileTimeMethodCall::CompileTimeMethodCall(JSONLoader & json) : MethodCallExpression(json) {
}
IR::Node * IR::CompileTimeMethodCall::fromJSON(JSONLoader & json) { return new CompileTimeMethodCall(json); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments) :
    MethodCallExpression(srcInfo, type, method, typeArguments, arguments)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments) :
    MethodCallExpression(type, method, typeArguments, arguments)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments) :
    MethodCallExpression(srcInfo, method, typeArguments, arguments)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments, const IR::Vector<IR::Argument>* arguments) :
    MethodCallExpression(method, typeArguments, arguments)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Argument>* arguments) :
    MethodCallExpression(srcInfo, type, method, arguments)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Argument>* arguments) :
    MethodCallExpression(type, method, arguments)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Expression* method, const IR::Vector<IR::Argument>* arguments) :
    MethodCallExpression(srcInfo, method, arguments)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(const IR::Expression* method, const IR::Vector<IR::Argument>* arguments) :
    MethodCallExpression(method, arguments)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments) :
    MethodCallExpression(srcInfo, type, method, typeArguments)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(const IR::Type* type, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments) :
    MethodCallExpression(type, method, typeArguments)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments) :
    MethodCallExpression(srcInfo, method, typeArguments)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(const IR::Expression* method, const IR::Vector<IR::Type>* typeArguments) :
    MethodCallExpression(method, typeArguments)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* method) :
    MethodCallExpression(srcInfo, type, method)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(const IR::Type* type, const IR::Expression* method) :
    MethodCallExpression(type, method)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(Util::SourceInfo srcInfo, const IR::Expression* method) :
    MethodCallExpression(srcInfo, method)
    { validate(); }
IR::CompileTimeMethodCall::CompileTimeMethodCall(const IR::Expression* method) :
    MethodCallExpression(method)
    { validate(); }

#line 63 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::Annotations *IR::ParserState::getAnnotations() const { return annotations; }
#line 6741 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 64 "/home/fengyong/Desktop/p4c/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::ParserState::getDeclarations() const {
        return components.getDeclarations(); }
#line 6745 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 66 "/home/fengyong/Desktop/p4c/ir/ir.def"
IR::IDeclaration const * IR::ParserState::getDeclByName(cstring name) const {
        return components.getDeclaration(name); }
#line 6749 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 73 "/home/fengyong/Desktop/p4c/ir/ir.def"
bool IR::ParserState::isBuiltin() const { return name == ParserState::accept || name == ParserState::reject; }
#line 6752 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 74 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::ParserState::validate() const {
#line 6755 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        components.validate();
#line 74 "/home/fengyong/Desktop/p4c/ir/ir.def"
{
        if (selectExpression != nullptr)
            BUG_CHECK(selectExpression->is<IR::PathExpression>() ||
                      selectExpression->is<IR::SelectExpression>(),
                      "%1%: unexpected select expression", selectExpression);
    } }
#line 6766 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::ParserState::operator==(IR::ParserState const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && components == a.components
        && selectExpression == a.selectExpression;
    }
bool IR::ParserState::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const ParserState &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && components.equiv(a.components)
        && (selectExpression ? a.selectExpression ? selectExpression->equiv(*a.selectExpression) : false : a.selectExpression == nullptr);
    }
void IR::ParserState::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    components.visit_children(v);
    v.visit(selectExpression, "selectExpression");
}
void IR::ParserState::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    components.visit_children(v);
    v.visit(selectExpression, "selectExpression");
}
void IR::ParserState::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"components\" : " << this->components;
    if (selectExpression != nullptr)     json << "," << std::endl << json.indent << "\"selectExpression\" : " << this->selectExpression;
}
IR::ParserState::ParserState(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("components", components);
    json.load("selectExpression", selectExpression);
}
IR::Node * IR::ParserState::fromJSON(JSONLoader & json) { return new ParserState(json); }
IR::ParserState::ParserState(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StatOrDecl> components, const IR::Expression* selectExpression) :
    Declaration(srcInfo, name), annotations(annotations), components(components), selectExpression(selectExpression)
    { validate(); }
IR::ParserState::ParserState(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StatOrDecl> components, const IR::Expression* selectExpression) :
    Declaration(name), annotations(annotations), components(components), selectExpression(selectExpression)
    { validate(); }
IR::ParserState::ParserState(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StatOrDecl> components, const IR::Expression* selectExpression) :
    Declaration(srcInfo, name), components(components), selectExpression(selectExpression)
    { validate(); }
IR::ParserState::ParserState(IR::ID name, IR::IndexedVector<IR::StatOrDecl> components, const IR::Expression* selectExpression) :
    Declaration(name), components(components), selectExpression(selectExpression)
    { validate(); }
IR::ParserState::ParserState(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Expression* selectExpression) :
    Declaration(srcInfo, name), annotations(annotations), selectExpression(selectExpression)
    { validate(); }
IR::ParserState::ParserState(IR::ID name, const IR::Annotations* annotations, const IR::Expression* selectExpression) :
    Declaration(name), annotations(annotations), selectExpression(selectExpression)
    { validate(); }
IR::ParserState::ParserState(Util::SourceInfo srcInfo, IR::ID name, const IR::Expression* selectExpression) :
    Declaration(srcInfo, name), selectExpression(selectExpression)
    { validate(); }
IR::ParserState::ParserState(IR::ID name, const IR::Expression* selectExpression) :
    Declaration(name), selectExpression(selectExpression)
    { validate(); }
#line 89 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::Annotations *IR::P4Parser::getAnnotations() const { return type->getAnnotations(); }
#line 6831 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 90 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::TypeParameters *IR::P4Parser::getTypeParameters() const { return type->getTypeParameters(); }
#line 6834 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 91 "/home/fengyong/Desktop/p4c/ir/ir.def"
std::vector<const IR::INamespace *> IR::P4Parser::getNestedNamespaces() const {
        return { type->typeParameters, type->applyParams, constructorParams }; }
#line 6838 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 93 "/home/fengyong/Desktop/p4c/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::P4Parser::getDeclarations() const {
        return parserLocals.getDeclarations()->concat(states.getDeclarations()); }
#line 6842 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 95 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::IDeclaration *IR::P4Parser::getDeclByName(cstring name) const {
        auto decl = parserLocals.getDeclaration(name);
        if (!decl) decl = states.getDeclaration(name);
        return decl; }
#line 6848 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 99 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::Type_Method *IR::P4Parser::getApplyMethodType() const { return type->getApplyMethodType(); }
#line 6851 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 100 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::ParameterList *IR::P4Parser::getApplyParameters() const { return type->getApplyParameters(); }
#line 6854 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 102 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::ParameterList *IR::P4Parser::getConstructorParameters() const { return constructorParams; }
#line 6857 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 104 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::Type *IR::P4Parser::getType() const { return this->type; }
#line 6860 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
IRNODE_DEFINE_APPLY_OVERLOAD(P4Parser, , )
#line 106 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::P4Parser::validate() const {
#line 6864 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(type);
        CHECK_NULL(constructorParams);
        parserLocals.validate();
        states.validate();
#line 106 "/home/fengyong/Desktop/p4c/ir/ir.def"
{
        if (!(name == type->name))
            BUG("Name mismatch for %1%: %2% != %3%", this, name, type->name);
        parserLocals.check_null();
        states.check_null();
        checkDuplicates();
        for (auto d : parserLocals)
            BUG_CHECK(!d->is<ParserState>(), "%1%: state in locals", d);
    } }
#line 6880 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 115 "/home/fengyong/Desktop/p4c/ir/ir.def"
cstring IR::P4Parser::toString() const { return cstring("parser ") + externalName(); }
#line 6883 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::P4Parser::operator==(IR::P4Parser const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && type == a.type
        && constructorParams == a.constructorParams
        && parserLocals == a.parserLocals
        && states == a.states;
    }
bool IR::P4Parser::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const P4Parser &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (constructorParams ? a.constructorParams ? constructorParams->equiv(*a.constructorParams) : false : a.constructorParams == nullptr)
        && parserLocals.equiv(a.parserLocals)
        && states.equiv(a.states);
    }
void IR::P4Parser::visit_children(Visitor & v) {
    Type_Declaration::visit_children(v);
    v.visit(type, "type");
    v.visit(constructorParams, "constructorParams");
    parserLocals.visit_children(v);
    states.visit_children(v);
}
void IR::P4Parser::visit_children(Visitor & v) const {
    Type_Declaration::visit_children(v);
    v.visit(type, "type");
    v.visit(constructorParams, "constructorParams");
    parserLocals.visit_children(v);
    states.visit_children(v);
}
void IR::P4Parser::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
    json << "," << std::endl << json.indent << "\"constructorParams\" : " << this->constructorParams;
    json << "," << std::endl << json.indent << "\"parserLocals\" : " << this->parserLocals;
    json << "," << std::endl << json.indent << "\"states\" : " << this->states;
}
IR::P4Parser::P4Parser(JSONLoader & json) : Type_Declaration(json) {
    json.load("type", type);
    json.load("constructorParams", constructorParams);
    json.load("parserLocals", parserLocals);
    json.load("states", states);
}
IR::Node * IR::P4Parser::fromJSON(JSONLoader & json) { return new P4Parser(json); }
IR::P4Parser::P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::Declaration> parserLocals, IR::IndexedVector<IR::ParserState> states) :
    Type_Declaration(srcInfo, name), type(type), constructorParams(constructorParams), parserLocals(parserLocals), states(states)
    { validate(); }
IR::P4Parser::P4Parser(IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::Declaration> parserLocals, IR::IndexedVector<IR::ParserState> states) :
    Type_Declaration(name), type(type), constructorParams(constructorParams), parserLocals(parserLocals), states(states)
    { validate(); }
IR::P4Parser::P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, IR::IndexedVector<IR::Declaration> parserLocals, IR::IndexedVector<IR::ParserState> states) :
    Type_Declaration(srcInfo, name), type(type), parserLocals(parserLocals), states(states)
    { validate(); }
IR::P4Parser::P4Parser(IR::ID name, const IR::Type_Parser* type, IR::IndexedVector<IR::Declaration> parserLocals, IR::IndexedVector<IR::ParserState> states) :
    Type_Declaration(name), type(type), parserLocals(parserLocals), states(states)
    { validate(); }
IR::P4Parser::P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::ParserState> states) :
    Type_Declaration(srcInfo, name), type(type), constructorParams(constructorParams), states(states)
    { validate(); }
IR::P4Parser::P4Parser(IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::ParserState> states) :
    Type_Declaration(name), type(type), constructorParams(constructorParams), states(states)
    { validate(); }
IR::P4Parser::P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, IR::IndexedVector<IR::ParserState> states) :
    Type_Declaration(srcInfo, name), type(type), states(states)
    { validate(); }
IR::P4Parser::P4Parser(IR::ID name, const IR::Type_Parser* type, IR::IndexedVector<IR::ParserState> states) :
    Type_Declaration(name), type(type), states(states)
    { validate(); }
IR::P4Parser::P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::Declaration> parserLocals) :
    Type_Declaration(srcInfo, name), type(type), constructorParams(constructorParams), parserLocals(parserLocals)
    { validate(); }
IR::P4Parser::P4Parser(IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::Declaration> parserLocals) :
    Type_Declaration(name), type(type), constructorParams(constructorParams), parserLocals(parserLocals)
    { validate(); }
IR::P4Parser::P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, IR::IndexedVector<IR::Declaration> parserLocals) :
    Type_Declaration(srcInfo, name), type(type), parserLocals(parserLocals)
    { validate(); }
IR::P4Parser::P4Parser(IR::ID name, const IR::Type_Parser* type, IR::IndexedVector<IR::Declaration> parserLocals) :
    Type_Declaration(name), type(type), parserLocals(parserLocals)
    { validate(); }
IR::P4Parser::P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams) :
    Type_Declaration(srcInfo, name), type(type), constructorParams(constructorParams)
    { validate(); }
IR::P4Parser::P4Parser(IR::ID name, const IR::Type_Parser* type, const IR::ParameterList* constructorParams) :
    Type_Declaration(name), type(type), constructorParams(constructorParams)
    { validate(); }
IR::P4Parser::P4Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Parser* type) :
    Type_Declaration(srcInfo, name), type(type)
    { validate(); }
IR::P4Parser::P4Parser(IR::ID name, const IR::Type_Parser* type) :
    Type_Declaration(name), type(type)
    { validate(); }
#line 124 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::Annotations *IR::P4Control::getAnnotations() const { return type->getAnnotations(); }
#line 6978 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 125 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::TypeParameters *IR::P4Control::getTypeParameters() const { return type->getTypeParameters(); }
#line 6981 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 126 "/home/fengyong/Desktop/p4c/ir/ir.def"
std::vector<const IR::INamespace *> IR::P4Control::getNestedNamespaces() const {
        return { type->typeParameters, type->applyParams, constructorParams }; }
#line 6985 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 128 "/home/fengyong/Desktop/p4c/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::P4Control::getDeclarations() const {
        return controlLocals.getDeclarations(); }
#line 6989 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 130 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::Type_Method *IR::P4Control::getApplyMethodType() const { return type->getApplyMethodType(); }
#line 6992 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 131 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::ParameterList *IR::P4Control::getApplyParameters() const { return type->getApplyParameters(); }
#line 6995 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 133 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::IDeclaration *IR::P4Control::getDeclByName(cstring name) const {
        return controlLocals.getDeclaration(name); }
#line 6999 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 135 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::ParameterList *IR::P4Control::getConstructorParameters() const { return constructorParams; }
#line 7002 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 136 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::Type *IR::P4Control::getType() const { return this->type; }
#line 7005 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
IRNODE_DEFINE_APPLY_OVERLOAD(P4Control, , )
#line 138 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::P4Control::validate() const {
#line 7009 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(type);
        CHECK_NULL(constructorParams);
        controlLocals.validate();
        CHECK_NULL(body);
#line 138 "/home/fengyong/Desktop/p4c/ir/ir.def"
{
        if (!(name == type->name))
            BUG("Name mismatch for %1%: %2% != %3%", this, name, type->name);
        controlLocals.check_null();
    } }
#line 7021 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 143 "/home/fengyong/Desktop/p4c/ir/ir.def"
cstring IR::P4Control::toString() const { return cstring("control ") + externalName(); }
#line 7024 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::P4Control::operator==(IR::P4Control const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && type == a.type
        && constructorParams == a.constructorParams
        && controlLocals == a.controlLocals
        && body == a.body;
    }
bool IR::P4Control::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const P4Control &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (constructorParams ? a.constructorParams ? constructorParams->equiv(*a.constructorParams) : false : a.constructorParams == nullptr)
        && controlLocals.equiv(a.controlLocals)
        && (body ? a.body ? body->equiv(*a.body) : false : a.body == nullptr);
    }
void IR::P4Control::visit_children(Visitor & v) {
    Type_Declaration::visit_children(v);
    v.visit(type, "type");
    v.visit(constructorParams, "constructorParams");
    controlLocals.visit_children(v);
    v.visit(body, "body");
}
void IR::P4Control::visit_children(Visitor & v) const {
    Type_Declaration::visit_children(v);
    v.visit(type, "type");
    v.visit(constructorParams, "constructorParams");
    controlLocals.visit_children(v);
    v.visit(body, "body");
}
void IR::P4Control::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
    json << "," << std::endl << json.indent << "\"constructorParams\" : " << this->constructorParams;
    json << "," << std::endl << json.indent << "\"controlLocals\" : " << this->controlLocals;
    json << "," << std::endl << json.indent << "\"body\" : " << this->body;
}
IR::P4Control::P4Control(JSONLoader & json) : Type_Declaration(json) {
    json.load("type", type);
    json.load("constructorParams", constructorParams);
    json.load("controlLocals", controlLocals);
    json.load("body", body);
}
IR::Node * IR::P4Control::fromJSON(JSONLoader & json) { return new P4Control(json); }
IR::P4Control::P4Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Control* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::Declaration> controlLocals, const IR::BlockStatement* body) :
    Type_Declaration(srcInfo, name), type(type), constructorParams(constructorParams), controlLocals(controlLocals), body(body)
    { validate(); }
IR::P4Control::P4Control(IR::ID name, const IR::Type_Control* type, const IR::ParameterList* constructorParams, IR::IndexedVector<IR::Declaration> controlLocals, const IR::BlockStatement* body) :
    Type_Declaration(name), type(type), constructorParams(constructorParams), controlLocals(controlLocals), body(body)
    { validate(); }
IR::P4Control::P4Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Control* type, IR::IndexedVector<IR::Declaration> controlLocals, const IR::BlockStatement* body) :
    Type_Declaration(srcInfo, name), type(type), controlLocals(controlLocals), body(body)
    { validate(); }
IR::P4Control::P4Control(IR::ID name, const IR::Type_Control* type, IR::IndexedVector<IR::Declaration> controlLocals, const IR::BlockStatement* body) :
    Type_Declaration(name), type(type), controlLocals(controlLocals), body(body)
    { validate(); }
IR::P4Control::P4Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Control* type, const IR::ParameterList* constructorParams, const IR::BlockStatement* body) :
    Type_Declaration(srcInfo, name), type(type), constructorParams(constructorParams), body(body)
    { validate(); }
IR::P4Control::P4Control(IR::ID name, const IR::Type_Control* type, const IR::ParameterList* constructorParams, const IR::BlockStatement* body) :
    Type_Declaration(name), type(type), constructorParams(constructorParams), body(body)
    { validate(); }
IR::P4Control::P4Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Control* type, const IR::BlockStatement* body) :
    Type_Declaration(srcInfo, name), type(type), body(body)
    { validate(); }
IR::P4Control::P4Control(IR::ID name, const IR::Type_Control* type, const IR::BlockStatement* body) :
    Type_Declaration(name), type(type), body(body)
    { validate(); }
#line 151 "/home/fengyong/Desktop/p4c/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::P4Action::getDeclarations() const {
        return parameters->getDeclarations(); }
#line 7096 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 153 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::IDeclaration *IR::P4Action::getDeclByName(cstring name) const {
        return parameters->getDeclByName(name); }
#line 7100 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 155 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::Annotations *IR::P4Action::getAnnotations() const { return annotations; }
#line 7103 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 156 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::ParameterList *IR::P4Action::getParameters() const { return parameters; }
#line 7106 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::P4Action::operator==(IR::P4Action const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && parameters == a.parameters
        && body == a.body;
    }
bool IR::P4Action::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const P4Action &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (parameters ? a.parameters ? parameters->equiv(*a.parameters) : false : a.parameters == nullptr)
        && (body ? a.body ? body->equiv(*a.body) : false : a.body == nullptr);
    }
void IR::P4Action::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(parameters, "parameters");
    v.visit(body, "body");
}
void IR::P4Action::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(parameters, "parameters");
    v.visit(body, "body");
}
void IR::P4Action::validate() const {
#line 7134 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(parameters);
        CHECK_NULL(body); }
void IR::P4Action::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"parameters\" : " << this->parameters;
    json << "," << std::endl << json.indent << "\"body\" : " << this->body;
}
IR::P4Action::P4Action(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("parameters", parameters);
    json.load("body", body);
}
IR::Node * IR::P4Action::fromJSON(JSONLoader & json) { return new P4Action(json); }
IR::P4Action::P4Action(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::ParameterList* parameters, const IR::BlockStatement* body) :
    Declaration(srcInfo, name), annotations(annotations), parameters(parameters), body(body)
    { validate(); }
IR::P4Action::P4Action(IR::ID name, const IR::Annotations* annotations, const IR::ParameterList* parameters, const IR::BlockStatement* body) :
    Declaration(name), annotations(annotations), parameters(parameters), body(body)
    { validate(); }
IR::P4Action::P4Action(Util::SourceInfo srcInfo, IR::ID name, const IR::ParameterList* parameters, const IR::BlockStatement* body) :
    Declaration(srcInfo, name), parameters(parameters), body(body)
    { validate(); }
IR::P4Action::P4Action(IR::ID name, const IR::ParameterList* parameters, const IR::BlockStatement* body) :
    Declaration(name), parameters(parameters), body(body)
    { validate(); }
#line 162 "/home/fengyong/Desktop/p4c/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Type_Error::getDeclarations() const {
        return members.getDeclarations(); }
#line 7166 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 164 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::IDeclaration *IR::Type_Error::getDeclByName(cstring name) const {
        return members.getDeclaration(name); }
#line 7170 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 166 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::Type_Error::validate() const {
#line 7173 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        members.validate();
#line 166 "/home/fengyong/Desktop/p4c/ir/ir.def"
{ members.check_null(); } }
#line 7178 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Error::operator==(IR::Type_Error const & a) const {
        return Type_Declaration::operator==(static_cast<const Type_Declaration &>(a))
        && members == a.members;
    }
bool IR::Type_Error::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Type_Error &>(a_);
        return members.equiv(a.members);
    }
void IR::Type_Error::visit_children(Visitor & v) {
    Type_Declaration::visit_children(v);
    members.visit_children(v);
}
void IR::Type_Error::visit_children(Visitor & v) const {
    Type_Declaration::visit_children(v);
    members.visit_children(v);
}
void IR::Type_Error::toJSON(JSONGenerator & json) const {
    Type_Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"members\" : " << this->members;
}
IR::Type_Error::Type_Error(JSONLoader & json) : Type_Declaration(json) {
    json.load("members", members);
}
IR::Node * IR::Type_Error::fromJSON(JSONLoader & json) { return new Type_Error(json); }
IR::Type_Error::Type_Error(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::Declaration_ID> members) :
    Type_Declaration(srcInfo, name), members(members)
    { validate(); }
IR::Type_Error::Type_Error(IR::ID name, IR::IndexedVector<IR::Declaration_ID> members) :
    Type_Declaration(name), members(members)
    { validate(); }
IR::Type_Error::Type_Error(Util::SourceInfo srcInfo, IR::ID name) :
    Type_Declaration(srcInfo, name)
    { validate(); }
IR::Type_Error::Type_Error(IR::ID name) :
    Type_Declaration(name)
    { validate(); }
#line 172 "/home/fengyong/Desktop/p4c/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Declaration_MatchKind::getDeclarations() const {
        return members.getDeclarations(); }
#line 7220 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 174 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::IDeclaration *IR::Declaration_MatchKind::getDeclByName(cstring name) const {
        return members.getDeclaration(name); }
#line 7224 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 176 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::Declaration_MatchKind::validate() const {
#line 7227 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        members.validate();
#line 176 "/home/fengyong/Desktop/p4c/ir/ir.def"
{ members.check_null(); } }
#line 7232 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Declaration_MatchKind::operator==(IR::Declaration_MatchKind const & a) const {
        return typeid(*this) == typeid(a)
        && members == a.members;
    }
bool IR::Declaration_MatchKind::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const Declaration_MatchKind &>(a_);
        return members.equiv(a.members);
    }
void IR::Declaration_MatchKind::visit_children(Visitor & v) {
    Node::visit_children(v);
    members.visit_children(v);
}
void IR::Declaration_MatchKind::visit_children(Visitor & v) const {
    Node::visit_children(v);
    members.visit_children(v);
}
void IR::Declaration_MatchKind::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"members\" : " << this->members;
}
IR::Declaration_MatchKind::Declaration_MatchKind(JSONLoader & json) : Node(json) {
    json.load("members", members);
}
IR::Node * IR::Declaration_MatchKind::fromJSON(JSONLoader & json) { return new Declaration_MatchKind(json); }
IR::Declaration_MatchKind::Declaration_MatchKind(Util::SourceInfo srcInfo, IR::IndexedVector<IR::Declaration_ID> members) :
    Node(srcInfo), members(members)
    { validate(); }
IR::Declaration_MatchKind::Declaration_MatchKind(IR::IndexedVector<IR::Declaration_ID> members) :
    members(members)
    { validate(); }
IR::Declaration_MatchKind::Declaration_MatchKind(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::Declaration_MatchKind::Declaration_MatchKind() 
    { validate(); }
bool IR::PropertyValue::operator==(IR::PropertyValue const & a) const {
        return typeid(*this) == typeid(a);
    }
bool IR::PropertyValue::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        return true;
    }
void IR::PropertyValue::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
}
IR::PropertyValue::PropertyValue(JSONLoader & json) : Node(json) {
}
IR::PropertyValue::PropertyValue(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::PropertyValue::PropertyValue() 
    { validate(); }
#line 185 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::ExpressionValue::dbprint(std::ostream & out) const { out << expression; }
#line 7290 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::ExpressionValue::operator==(IR::ExpressionValue const & a) const {
        return PropertyValue::operator==(static_cast<const PropertyValue &>(a))
        && expression == a.expression;
    }
bool IR::ExpressionValue::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!PropertyValue::equiv(a_)) return false;
        auto &a = static_cast<const ExpressionValue &>(a_);
        return (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr);
    }
void IR::ExpressionValue::visit_children(Visitor & v) {
    PropertyValue::visit_children(v);
    v.visit(expression, "expression");
}
void IR::ExpressionValue::visit_children(Visitor & v) const {
    PropertyValue::visit_children(v);
    v.visit(expression, "expression");
}
void IR::ExpressionValue::validate() const {
#line 7310 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(expression); }
void IR::ExpressionValue::toJSON(JSONGenerator & json) const {
    PropertyValue::toJSON(json);
    json << "," << std::endl << json.indent << "\"expression\" : " << this->expression;
}
IR::ExpressionValue::ExpressionValue(JSONLoader & json) : PropertyValue(json) {
    json.load("expression", expression);
}
IR::Node * IR::ExpressionValue::fromJSON(JSONLoader & json) { return new ExpressionValue(json); }
IR::ExpressionValue::ExpressionValue(Util::SourceInfo srcInfo, const IR::Expression* expression) :
    PropertyValue(srcInfo), expression(expression)
    { validate(); }
IR::ExpressionValue::ExpressionValue(const IR::Expression* expression) :
    expression(expression)
    { validate(); }
#line 190 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::ExpressionListValue::dbprint(std::ostream & out) const { out << expressions; }
#line 7329 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::ExpressionListValue::operator==(IR::ExpressionListValue const & a) const {
        return PropertyValue::operator==(static_cast<const PropertyValue &>(a))
        && expressions == a.expressions;
    }
bool IR::ExpressionListValue::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!PropertyValue::equiv(a_)) return false;
        auto &a = static_cast<const ExpressionListValue &>(a_);
        return expressions.equiv(a.expressions);
    }
void IR::ExpressionListValue::visit_children(Visitor & v) {
    PropertyValue::visit_children(v);
    expressions.visit_children(v);
}
void IR::ExpressionListValue::visit_children(Visitor & v) const {
    PropertyValue::visit_children(v);
    expressions.visit_children(v);
}
void IR::ExpressionListValue::validate() const {
#line 7349 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        expressions.validate(); }
void IR::ExpressionListValue::toJSON(JSONGenerator & json) const {
    PropertyValue::toJSON(json);
    json << "," << std::endl << json.indent << "\"expressions\" : " << this->expressions;
}
IR::ExpressionListValue::ExpressionListValue(JSONLoader & json) : PropertyValue(json) {
    json.load("expressions", expressions);
}
IR::Node * IR::ExpressionListValue::fromJSON(JSONLoader & json) { return new ExpressionListValue(json); }
IR::ExpressionListValue::ExpressionListValue(Util::SourceInfo srcInfo, IR::Vector<IR::Expression> expressions) :
    PropertyValue(srcInfo), expressions(expressions)
    { validate(); }
IR::ExpressionListValue::ExpressionListValue(IR::Vector<IR::Expression> expressions) :
    expressions(expressions)
    { validate(); }

#line 197 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::ActionListElement::dbprint(std::ostream & out) const { out << annotations << expression; }
#line 7369 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 198 "/home/fengyong/Desktop/p4c/ir/ir.def"
IR::ID IR::ActionListElement::getName() const { return getPath()->name; }
#line 7372 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 200 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::Annotations *IR::ActionListElement::getAnnotations() const { return annotations; }
#line 7375 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 201 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::ActionListElement::validate() const {
#line 7378 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(expression);
#line 201 "/home/fengyong/Desktop/p4c/ir/ir.def"
{
        BUG_CHECK(expression->is<IR::PathExpression>() ||
                  expression->is<IR::MethodCallExpression>(),
                  "%1%: unexpected expression", expression);
    } }
#line 7388 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 206 "/home/fengyong/Desktop/p4c/ir/ir.def"
cstring IR::ActionListElement::toString() const { return getName().toString(); }
#line 7391 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::ActionListElement::operator==(IR::ActionListElement const & a) const {
        return typeid(*this) == typeid(a)
        && annotations == a.annotations
        && expression == a.expression;
    }
bool IR::ActionListElement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const ActionListElement &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr);
    }
void IR::ActionListElement::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(expression, "expression");
}
void IR::ActionListElement::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(expression, "expression");
}
void IR::ActionListElement::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"expression\" : " << this->expression;
}
IR::ActionListElement::ActionListElement(JSONLoader & json) : Node(json) {
    json.load("annotations", annotations);
    json.load("expression", expression);
}
IR::Node * IR::ActionListElement::fromJSON(JSONLoader & json) { return new ActionListElement(json); }
IR::ActionListElement::ActionListElement(Util::SourceInfo srcInfo, const IR::Annotations* annotations, const IR::Expression* expression) :
    Node(srcInfo), annotations(annotations), expression(expression)
    { validate(); }
IR::ActionListElement::ActionListElement(const IR::Annotations* annotations, const IR::Expression* expression) :
    annotations(annotations), expression(expression)
    { validate(); }
IR::ActionListElement::ActionListElement(Util::SourceInfo srcInfo, const IR::Expression* expression) :
    Node(srcInfo), expression(expression)
    { validate(); }
IR::ActionListElement::ActionListElement(const IR::Expression* expression) :
    expression(expression)
    { validate(); }
#line 212 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::ActionList::validate() const {
#line 7438 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        actionList.validate();
#line 212 "/home/fengyong/Desktop/p4c/ir/ir.def"
{ actionList.check_null(); } }
#line 7443 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 213 "/home/fengyong/Desktop/p4c/ir/ir.def"
size_t IR::ActionList::size() const { return actionList.size(); }
#line 7446 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 214 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::ActionList::push_back(const IR::ActionListElement* e) { actionList.push_back(e); }
#line 7449 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 215 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::ActionListElement *IR::ActionList::getDeclaration(cstring n) const {
        return actionList.getDeclaration<ActionListElement>(n); }
#line 7453 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::ActionList::operator==(IR::ActionList const & a) const {
        return PropertyValue::operator==(static_cast<const PropertyValue &>(a))
        && actionList == a.actionList;
    }
bool IR::ActionList::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!PropertyValue::equiv(a_)) return false;
        auto &a = static_cast<const ActionList &>(a_);
        return actionList.equiv(a.actionList);
    }
void IR::ActionList::visit_children(Visitor & v) {
    PropertyValue::visit_children(v);
    actionList.visit_children(v);
}
void IR::ActionList::visit_children(Visitor & v) const {
    PropertyValue::visit_children(v);
    actionList.visit_children(v);
}
void IR::ActionList::toJSON(JSONGenerator & json) const {
    PropertyValue::toJSON(json);
    json << "," << std::endl << json.indent << "\"actionList\" : " << this->actionList;
}
IR::ActionList::ActionList(JSONLoader & json) : PropertyValue(json) {
    json.load("actionList", actionList);
}
IR::Node * IR::ActionList::fromJSON(JSONLoader & json) { return new ActionList(json); }
IR::ActionList::ActionList(Util::SourceInfo srcInfo, IR::IndexedVector<IR::ActionListElement> actionList) :
    PropertyValue(srcInfo), actionList(actionList)
    { validate(); }
IR::ActionList::ActionList(IR::IndexedVector<IR::ActionListElement> actionList) :
    actionList(actionList)
    { validate(); }
#line 224 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::Annotations *IR::KeyElement::getAnnotations() const { return annotations; }
#line 7488 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 225 "/home/fengyong/Desktop/p4c/ir/ir.def"
IR::Node const * IR::KeyElement::transform_visit(Transform & v) {
        // call this from Transform::preorder(KeyElement) if the transform might split
        // the expression into a Vector<Expression>
        v.visit(annotations, "annotations");
        auto exp = v.apply_visitor(expression, "expression");
        v.visit(matchType, "matchType");
        v.prune();
        if (exp == expression) {
        } else if (auto vec = exp->to<Vector<Expression>>()) {
            auto *rv = new Vector<KeyElement>();
            for (auto el : *vec) {
                auto *kel = clone();
                kel->expression = el;
                rv->push_back(kel); }
            return rv;
        } else {
            expression = exp->to<IR::Expression>(); }
        return this; }
#line 7508 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::KeyElement::operator==(IR::KeyElement const & a) const {
        return typeid(*this) == typeid(a)
        && annotations == a.annotations
        && expression == a.expression
        && matchType == a.matchType;
    }
bool IR::KeyElement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const KeyElement &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr)
        && (matchType ? a.matchType ? matchType->equiv(*a.matchType) : false : a.matchType == nullptr);
    }
void IR::KeyElement::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(expression, "expression");
    v.visit(matchType, "matchType");
}
void IR::KeyElement::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(expression, "expression");
    v.visit(matchType, "matchType");
}
void IR::KeyElement::validate() const {
#line 7536 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(expression);
        CHECK_NULL(matchType); }
void IR::KeyElement::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"expression\" : " << this->expression;
    json << "," << std::endl << json.indent << "\"matchType\" : " << this->matchType;
}
IR::KeyElement::KeyElement(JSONLoader & json) : Node(json) {
    json.load("annotations", annotations);
    json.load("expression", expression);
    json.load("matchType", matchType);
}
IR::Node * IR::KeyElement::fromJSON(JSONLoader & json) { return new KeyElement(json); }
IR::KeyElement::KeyElement(Util::SourceInfo srcInfo, const IR::Annotations* annotations, const IR::Expression* expression, const IR::PathExpression* matchType) :
    Node(srcInfo), annotations(annotations), expression(expression), matchType(matchType)
    { validate(); }
IR::KeyElement::KeyElement(const IR::Annotations* annotations, const IR::Expression* expression, const IR::PathExpression* matchType) :
    annotations(annotations), expression(expression), matchType(matchType)
    { validate(); }
IR::KeyElement::KeyElement(Util::SourceInfo srcInfo, const IR::Expression* expression, const IR::PathExpression* matchType) :
    Node(srcInfo), expression(expression), matchType(matchType)
    { validate(); }
IR::KeyElement::KeyElement(const IR::Expression* expression, const IR::PathExpression* matchType) :
    expression(expression), matchType(matchType)
    { validate(); }
#line 248 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::Key::validate() const {
#line 7567 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        keyElements.validate();
#line 248 "/home/fengyong/Desktop/p4c/ir/ir.def"
{ keyElements.check_null(); } }
#line 7572 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 249 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::Key::push_back(const IR::KeyElement* ke) { keyElements.push_back(ke); }
#line 7575 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Key::operator==(IR::Key const & a) const {
        return PropertyValue::operator==(static_cast<const PropertyValue &>(a))
        && keyElements == a.keyElements;
    }
bool IR::Key::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!PropertyValue::equiv(a_)) return false;
        auto &a = static_cast<const Key &>(a_);
        return keyElements.equiv(a.keyElements);
    }
void IR::Key::visit_children(Visitor & v) {
    PropertyValue::visit_children(v);
    keyElements.visit_children(v);
}
void IR::Key::visit_children(Visitor & v) const {
    PropertyValue::visit_children(v);
    keyElements.visit_children(v);
}
void IR::Key::toJSON(JSONGenerator & json) const {
    PropertyValue::toJSON(json);
    json << "," << std::endl << json.indent << "\"keyElements\" : " << this->keyElements;
}
IR::Key::Key(JSONLoader & json) : PropertyValue(json) {
    json.load("keyElements", keyElements);
}
IR::Node * IR::Key::fromJSON(JSONLoader & json) { return new Key(json); }
IR::Key::Key(Util::SourceInfo srcInfo, IR::Vector<IR::KeyElement> keyElements) :
    PropertyValue(srcInfo), keyElements(keyElements)
    { validate(); }
IR::Key::Key(IR::Vector<IR::KeyElement> keyElements) :
    keyElements(keyElements)
    { validate(); }
/// annotations are optional (supported annotations: @priority(value))
/// optional const annotation
/// optional entry priority
/// must be a tuple expression
/// typically a MethodCallExpression.
/// The action must be defined in action list
/// True if the entry is not a list.
#line 263 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::Annotations *IR::Entry::getAnnotations() const { return annotations; }
#line 7617 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 264 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::ListExpression *IR::Entry::getKeys() const { return keys; }
#line 7620 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 265 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::Expression *IR::Entry::getAction() const { return action; }
#line 7623 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 266 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::Entry::dbprint(std::ostream & out) const { out << annotations << keys << action; }
#line 7626 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Entry::operator==(IR::Entry const & a) const {
        return typeid(*this) == typeid(a)
        && annotations == a.annotations
        && isConst == a.isConst
        && priority == a.priority
        && keys == a.keys
        && action == a.action
        && singleton == a.singleton;
    }
bool IR::Entry::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const Entry &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && isConst == a.isConst
        && (priority ? a.priority ? priority->equiv(*a.priority) : false : a.priority == nullptr)
        && (keys ? a.keys ? keys->equiv(*a.keys) : false : a.keys == nullptr)
        && (action ? a.action ? action->equiv(*a.action) : false : a.action == nullptr)
        && singleton == a.singleton;
    }
void IR::Entry::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(priority, "priority");
    v.visit(keys, "keys");
    v.visit(action, "action");
}
void IR::Entry::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(priority, "priority");
    v.visit(keys, "keys");
    v.visit(action, "action");
}
void IR::Entry::validate() const {
#line 7662 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(keys);
        CHECK_NULL(action); }
void IR::Entry::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " isConst=" << isConst;
        out << " singleton=" << singleton;
}
void IR::Entry::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"isConst\" : " << this->isConst;
    if (priority != nullptr)     json << "," << std::endl << json.indent << "\"priority\" : " << this->priority;
    json << "," << std::endl << json.indent << "\"keys\" : " << this->keys;
    json << "," << std::endl << json.indent << "\"action\" : " << this->action;
    json << "," << std::endl << json.indent << "\"singleton\" : " << this->singleton;
}
IR::Entry::Entry(JSONLoader & json) : Node(json) {
    json.load("annotations", annotations);
    json.load("isConst", isConst);
    json.load("priority", priority);
    json.load("keys", keys);
    json.load("action", action);
    json.load("singleton", singleton);
}
IR::Node * IR::Entry::fromJSON(JSONLoader & json) { return new Entry(json); }
IR::Entry::Entry(Util::SourceInfo srcInfo, const IR::Annotations* annotations, bool isConst, const IR::Expression* priority, const IR::ListExpression* keys, const IR::Expression* action, bool singleton) :
    Node(srcInfo), annotations(annotations), isConst(isConst), priority(priority), keys(keys), action(action), singleton(singleton)
    { validate(); }
IR::Entry::Entry(const IR::Annotations* annotations, bool isConst, const IR::Expression* priority, const IR::ListExpression* keys, const IR::Expression* action, bool singleton) :
    annotations(annotations), isConst(isConst), priority(priority), keys(keys), action(action), singleton(singleton)
    { validate(); }
IR::Entry::Entry(Util::SourceInfo srcInfo, bool isConst, const IR::Expression* priority, const IR::ListExpression* keys, const IR::Expression* action, bool singleton) :
    Node(srcInfo), isConst(isConst), priority(priority), keys(keys), action(action), singleton(singleton)
    { validate(); }
IR::Entry::Entry(bool isConst, const IR::Expression* priority, const IR::ListExpression* keys, const IR::Expression* action, bool singleton) :
    isConst(isConst), priority(priority), keys(keys), action(action), singleton(singleton)
    { validate(); }
#line 272 "/home/fengyong/Desktop/p4c/ir/ir.def"
size_t IR::EntriesList::size() const { return entries.size(); }
#line 7704 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 273 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::EntriesList::dbprint(std::ostream & out) const { out << "{ " << entries << "}"; }
#line 7707 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::EntriesList::operator==(IR::EntriesList const & a) const {
        return PropertyValue::operator==(static_cast<const PropertyValue &>(a))
        && entries == a.entries;
    }
bool IR::EntriesList::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!PropertyValue::equiv(a_)) return false;
        auto &a = static_cast<const EntriesList &>(a_);
        return entries.equiv(a.entries);
    }
void IR::EntriesList::visit_children(Visitor & v) {
    PropertyValue::visit_children(v);
    entries.visit_children(v);
}
void IR::EntriesList::visit_children(Visitor & v) const {
    PropertyValue::visit_children(v);
    entries.visit_children(v);
}
void IR::EntriesList::validate() const {
#line 7727 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        entries.validate(); }
void IR::EntriesList::toJSON(JSONGenerator & json) const {
    PropertyValue::toJSON(json);
    json << "," << std::endl << json.indent << "\"entries\" : " << this->entries;
}
IR::EntriesList::EntriesList(JSONLoader & json) : PropertyValue(json) {
    json.load("entries", entries);
}
IR::Node * IR::EntriesList::fromJSON(JSONLoader & json) { return new EntriesList(json); }
IR::EntriesList::EntriesList(Util::SourceInfo srcInfo, IR::Vector<IR::Entry> entries) :
    PropertyValue(srcInfo), entries(entries)
    { validate(); }
IR::EntriesList::EntriesList(IR::Vector<IR::Entry> entries) :
    entries(entries)
    { validate(); }
#line 280 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::Annotations *IR::Property::getAnnotations() const { return annotations; }
#line 7746 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 281 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::Property::dbprint(std::ostream & out) const { out << annotations << (isConstant ? "const " : "") << name << " = " << value; }
#line 7749 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Property::operator==(IR::Property const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && value == a.value
        && isConstant == a.isConstant;
    }
bool IR::Property::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Property &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (value ? a.value ? value->equiv(*a.value) : false : a.value == nullptr)
        && isConstant == a.isConstant;
    }
void IR::Property::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(value, "value");
}
void IR::Property::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(value, "value");
}
void IR::Property::validate() const {
#line 7775 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(value); }
void IR::Property::dump_fields(std::ostream & out) const {
    Declaration::dump_fields(out);
        out << " isConstant=" << isConstant;
}
void IR::Property::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"value\" : " << this->value;
    json << "," << std::endl << json.indent << "\"isConstant\" : " << this->isConstant;
}
IR::Property::Property(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("value", value);
    json.load("isConstant", isConstant);
}
IR::Node * IR::Property::fromJSON(JSONLoader & json) { return new Property(json); }
IR::Property::Property(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::PropertyValue* value, bool isConstant) :
    Declaration(srcInfo, name), annotations(annotations), value(value), isConstant(isConstant)
    { validate(); }
IR::Property::Property(IR::ID name, const IR::Annotations* annotations, const IR::PropertyValue* value, bool isConstant) :
    Declaration(name), annotations(annotations), value(value), isConstant(isConstant)
    { validate(); }
IR::Property::Property(Util::SourceInfo srcInfo, IR::ID name, const IR::PropertyValue* value, bool isConstant) :
    Declaration(srcInfo, name), value(value), isConstant(isConstant)
    { validate(); }
IR::Property::Property(IR::ID name, const IR::PropertyValue* value, bool isConstant) :
    Declaration(name), value(value), isConstant(isConstant)
    { validate(); }
#line 286 "/home/fengyong/Desktop/p4c/ir/ir.def"
cstring IR::TableProperties::toString() const { return "TableProperties(" + Util::toString(properties.size()) + ")"; }
#line 7809 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 287 "/home/fengyong/Desktop/p4c/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::TableProperties::getDeclarations() const {
        return properties.getDeclarations(); }
#line 7813 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 289 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::Property *IR::TableProperties::getProperty(cstring name) const {
        return properties.getDeclaration<Property>(name); }
#line 7817 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 291 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::IDeclaration *IR::TableProperties::getDeclByName(cstring name) const {
        return properties.getDeclaration(name); }
#line 7821 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 293 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::TableProperties::push_back(const IR::Property* prop) { properties.push_back(prop); }
#line 7824 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 301 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::TableProperties::validate() const {
#line 7827 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        properties.validate();
#line 301 "/home/fengyong/Desktop/p4c/ir/ir.def"
{ properties.check_null(); properties.validate(); } }
#line 7832 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::TableProperties::operator==(IR::TableProperties const & a) const {
        return typeid(*this) == typeid(a)
        && properties == a.properties;
    }
bool IR::TableProperties::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const TableProperties &>(a_);
        return properties.equiv(a.properties);
    }
void IR::TableProperties::visit_children(Visitor & v) {
    Node::visit_children(v);
    properties.visit_children(v);
}
void IR::TableProperties::visit_children(Visitor & v) const {
    Node::visit_children(v);
    properties.visit_children(v);
}
void IR::TableProperties::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"properties\" : " << this->properties;
}
IR::TableProperties::TableProperties(JSONLoader & json) : Node(json) {
    json.load("properties", properties);
}
IR::Node * IR::TableProperties::fromJSON(JSONLoader & json) { return new TableProperties(json); }
IR::TableProperties::TableProperties(Util::SourceInfo srcInfo, IR::IndexedVector<IR::Property> properties) :
    Node(srcInfo), properties(properties)
    { validate(); }
IR::TableProperties::TableProperties(IR::IndexedVector<IR::Property> properties) :
    properties(properties)
    { validate(); }
IR::TableProperties::TableProperties(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::TableProperties::TableProperties() 
    { validate(); }
#line 308 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::Annotations *IR::P4Table::getAnnotations() const { return annotations; }
#line 7872 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 310 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::ParameterList *IR::P4Table::getApplyParameters() const { return new ParameterList(); }
#line 7875 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 311 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::ActionList *IR::P4Table::getActionList() const {
        auto ap = properties->getProperty(TableProperties::actionsPropertyName);
        if (ap == nullptr)
            return nullptr;
        if (!ap->value->is<IR::ActionList>()) {
            ::error(ErrorType::ERR_INVALID, "%1%: must be an action list", ap);
            return nullptr; }
        return ap->value->to<IR::ActionList>(); }
#line 7885 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 319 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::Key *IR::P4Table::getKey() const {
        auto kp = properties->getProperty(TableProperties::keyPropertyName);
        if (kp == nullptr)
            return nullptr;
        if (!kp->value->is<IR::Key>()) {
            ::error(ErrorType::ERR_INVALID, "%1%: must be a key", kp);
            return nullptr; }
        return kp->value->to<IR::Key>(); }
#line 7895 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 327 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::Expression *IR::P4Table::getDefaultAction() const {
        auto d = properties->getProperty(TableProperties::defaultActionPropertyName);
        if (d == nullptr)
            return nullptr;
        if (!d->value->is<IR::ExpressionValue>()) {
            ::error(ErrorType::ERR_INVALID, "%1%: must be an expression", d);
            return nullptr; }
        return d->value->to<IR::ExpressionValue>()->expression; }
#line 7905 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 335 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::Constant *IR::P4Table::getConstantProperty(cstring name) const {
        if (auto d = properties->getProperty(name)) {
            if (auto ev = d->value->to<IR::ExpressionValue>()) {
                if (auto k = ev->expression->to<IR::Constant>()) {
                    return k; } }
            error(ErrorType::ERR_INVALID, "%1% must be a constant numeric expression", d); }
        return nullptr; }
#line 7914 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 342 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::BoolLiteral *IR::P4Table::getBooleanProperty(cstring name) const {
        if (auto d = properties->getProperty(name)) {
            if (auto ev = d->value->to<IR::ExpressionValue>()) {
                if (auto k = ev->expression->to<IR::BoolLiteral>()) {
                    return k; } }
            error(ErrorType::ERR_INVALID, "%1% must be a boolean expression", d); }
        return nullptr; }
#line 7923 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 349 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::Constant *IR::P4Table::getSizeProperty() const {
        return getConstantProperty(TableProperties::sizePropertyName);
    }
#line 7928 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 352 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::EntriesList *IR::P4Table::getEntries() const {
        auto ep = properties->getProperty(TableProperties::entriesPropertyName);
        if (ep == nullptr)
            return nullptr;
        if (!ep->value->is<IR::EntriesList>()) {
            ::error(ErrorType::ERR_INVALID, "%1%: must be a list of entries", ep);
            return nullptr;
        }
        return ep->value->to<IR::EntriesList>();
    }
#line 7940 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::P4Table::operator==(IR::P4Table const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && properties == a.properties;
    }
bool IR::P4Table::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const P4Table &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (properties ? a.properties ? properties->equiv(*a.properties) : false : a.properties == nullptr);
    }
void IR::P4Table::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(properties, "properties");
}
void IR::P4Table::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(properties, "properties");
}
void IR::P4Table::validate() const {
#line 7964 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(properties); }
void IR::P4Table::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"properties\" : " << this->properties;
}
IR::P4Table::P4Table(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("properties", properties);
}
IR::Node * IR::P4Table::fromJSON(JSONLoader & json) { return new P4Table(json); }
IR::P4Table::P4Table(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TableProperties* properties) :
    Declaration(srcInfo, name), annotations(annotations), properties(properties)
    { validate(); }
IR::P4Table::P4Table(IR::ID name, const IR::Annotations* annotations, const IR::TableProperties* properties) :
    Declaration(name), annotations(annotations), properties(properties)
    { validate(); }
IR::P4Table::P4Table(Util::SourceInfo srcInfo, IR::ID name, const IR::TableProperties* properties) :
    Declaration(srcInfo, name), properties(properties)
    { validate(); }
IR::P4Table::P4Table(IR::ID name, const IR::TableProperties* properties) :
    Declaration(name), properties(properties)
    { validate(); }

#line 368 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::Annotations *IR::P4ValueSet::getAnnotations() const { return annotations; }
#line 7993 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::P4ValueSet::operator==(IR::P4ValueSet const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && elementType == a.elementType
        && size == a.size;
    }
bool IR::P4ValueSet::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const P4ValueSet &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (elementType ? a.elementType ? elementType->equiv(*a.elementType) : false : a.elementType == nullptr)
        && (size ? a.size ? size->equiv(*a.size) : false : a.size == nullptr);
    }
void IR::P4ValueSet::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(elementType, "elementType");
    v.visit(size, "size");
}
void IR::P4ValueSet::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(elementType, "elementType");
    v.visit(size, "size");
}
void IR::P4ValueSet::validate() const {
#line 8021 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(elementType);
        CHECK_NULL(size); }
void IR::P4ValueSet::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"elementType\" : " << this->elementType;
    json << "," << std::endl << json.indent << "\"size\" : " << this->size;
}
IR::P4ValueSet::P4ValueSet(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("elementType", elementType);
    json.load("size", size);
}
IR::Node * IR::P4ValueSet::fromJSON(JSONLoader & json) { return new P4ValueSet(json); }
IR::P4ValueSet::P4ValueSet(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* elementType, const IR::Expression* size) :
    Declaration(srcInfo, name), annotations(annotations), elementType(elementType), size(size)
    { validate(); }
IR::P4ValueSet::P4ValueSet(IR::ID name, const IR::Annotations* annotations, const IR::Type* elementType, const IR::Expression* size) :
    Declaration(name), annotations(annotations), elementType(elementType), size(size)
    { validate(); }
IR::P4ValueSet::P4ValueSet(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* elementType, const IR::Expression* size) :
    Declaration(srcInfo, name), elementType(elementType), size(size)
    { validate(); }
IR::P4ValueSet::P4ValueSet(IR::ID name, const IR::Type* elementType, const IR::Expression* size) :
    Declaration(name), elementType(elementType), size(size)
    { validate(); }
#line 376 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::Annotations *IR::Declaration_Variable::getAnnotations() const { return annotations; }
#line 8052 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 377 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::Declaration_Variable::dbprint(std::ostream & out) const {
        out << annotations << type << ' ' << name;
        if (initializer) out << " = " << *initializer; }
#line 8057 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Declaration_Variable::operator==(IR::Declaration_Variable const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && type == a.type
        && initializer == a.initializer;
    }
bool IR::Declaration_Variable::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Declaration_Variable &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (initializer ? a.initializer ? initializer->equiv(*a.initializer) : false : a.initializer == nullptr);
    }
void IR::Declaration_Variable::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
    v.visit(initializer, "initializer");
}
void IR::Declaration_Variable::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
    v.visit(initializer, "initializer");
}
void IR::Declaration_Variable::validate() const {
#line 8085 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(type); }
void IR::Declaration_Variable::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
    if (initializer != nullptr)     json << "," << std::endl << json.indent << "\"initializer\" : " << this->initializer;
}
IR::Declaration_Variable::Declaration_Variable(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("type", type);
    json.load("initializer", initializer);
}
IR::Node * IR::Declaration_Variable::fromJSON(JSONLoader & json) { return new Declaration_Variable(json); }
IR::Declaration_Variable::Declaration_Variable(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Expression* initializer) :
    Declaration(srcInfo, name), annotations(annotations), type(type), initializer(initializer)
    { validate(); }
IR::Declaration_Variable::Declaration_Variable(IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Expression* initializer) :
    Declaration(name), annotations(annotations), type(type), initializer(initializer)
    { validate(); }
IR::Declaration_Variable::Declaration_Variable(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type, const IR::Expression* initializer) :
    Declaration(srcInfo, name), type(type), initializer(initializer)
    { validate(); }
IR::Declaration_Variable::Declaration_Variable(IR::ID name, const IR::Type* type, const IR::Expression* initializer) :
    Declaration(name), type(type), initializer(initializer)
    { validate(); }
IR::Declaration_Variable::Declaration_Variable(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type) :
    Declaration(srcInfo, name), annotations(annotations), type(type)
    { validate(); }
IR::Declaration_Variable::Declaration_Variable(IR::ID name, const IR::Annotations* annotations, const IR::Type* type) :
    Declaration(name), annotations(annotations), type(type)
    { validate(); }
IR::Declaration_Variable::Declaration_Variable(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type) :
    Declaration(srcInfo, name), type(type)
    { validate(); }
IR::Declaration_Variable::Declaration_Variable(IR::ID name, const IR::Type* type) :
    Declaration(name), type(type)
    { validate(); }
#line 387 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::Annotations *IR::Declaration_Constant::getAnnotations() const { return annotations; }
#line 8127 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 388 "/home/fengyong/Desktop/p4c/ir/ir.def"
cstring IR::Declaration_Constant::toString() const { return Declaration::toString(); }
#line 8130 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 389 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::Declaration_Constant::dbprint(std::ostream & out) const { out << annotations << type << ' ' << name << " = " << *initializer; }
#line 8133 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Declaration_Constant::operator==(IR::Declaration_Constant const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && type == a.type
        && initializer == a.initializer;
    }
bool IR::Declaration_Constant::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Declaration_Constant &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (initializer ? a.initializer ? initializer->equiv(*a.initializer) : false : a.initializer == nullptr);
    }
void IR::Declaration_Constant::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
    v.visit(initializer, "initializer");
}
void IR::Declaration_Constant::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
    v.visit(initializer, "initializer");
}
void IR::Declaration_Constant::validate() const {
#line 8161 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(type);
        CHECK_NULL(initializer); }
void IR::Declaration_Constant::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
    json << "," << std::endl << json.indent << "\"initializer\" : " << this->initializer;
}
IR::Declaration_Constant::Declaration_Constant(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("type", type);
    json.load("initializer", initializer);
}
IR::Node * IR::Declaration_Constant::fromJSON(JSONLoader & json) { return new Declaration_Constant(json); }
IR::Declaration_Constant::Declaration_Constant(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Expression* initializer) :
    Declaration(srcInfo, name), annotations(annotations), type(type), initializer(initializer)
    { validate(); }
IR::Declaration_Constant::Declaration_Constant(IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Expression* initializer) :
    Declaration(name), annotations(annotations), type(type), initializer(initializer)
    { validate(); }
IR::Declaration_Constant::Declaration_Constant(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type, const IR::Expression* initializer) :
    Declaration(srcInfo, name), type(type), initializer(initializer)
    { validate(); }
IR::Declaration_Constant::Declaration_Constant(IR::ID name, const IR::Type* type, const IR::Expression* initializer) :
    Declaration(name), type(type), initializer(initializer)
    { validate(); }



#line 404 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::Annotations *IR::Declaration_Instance::getAnnotations() const { return annotations; }
#line 8195 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 405 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::Type *IR::Declaration_Instance::getType() const { return type; }
#line 8198 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 406 "/home/fengyong/Desktop/p4c/ir/ir.def"
IR::ID IR::Declaration_Instance::Name() const { return name; }
#line 8201 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 407 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::Declaration_Instance::validate() const {
#line 8204 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        CHECK_NULL(type);
        CHECK_NULL(arguments);
        properties.validate();
#line 407 "/home/fengyong/Desktop/p4c/ir/ir.def"
{ arguments->check_null(); } }
#line 8212 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Declaration_Instance::operator==(IR::Declaration_Instance const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && annotations == a.annotations
        && type == a.type
        && arguments == a.arguments
        && properties == a.properties
        && initializer == a.initializer;
    }
bool IR::Declaration_Instance::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Declaration_Instance &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (arguments ? a.arguments ? arguments->equiv(*a.arguments) : false : a.arguments == nullptr)
        && properties.equiv(a.properties)
        && (initializer ? a.initializer ? initializer->equiv(*a.initializer) : false : a.initializer == nullptr);
    }
void IR::Declaration_Instance::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
    v.visit(arguments, "arguments");
    properties.visit_children(v);
    v.visit(initializer, "initializer");
}
void IR::Declaration_Instance::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
    v.visit(arguments, "arguments");
    properties.visit_children(v);
    v.visit(initializer, "initializer");
}
void IR::Declaration_Instance::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
    json << "," << std::endl << json.indent << "\"arguments\" : " << this->arguments;
    json << "," << std::endl << json.indent << "\"properties\" : " << this->properties;
    if (initializer != nullptr)     json << "," << std::endl << json.indent << "\"initializer\" : " << this->initializer;
}
IR::Declaration_Instance::Declaration_Instance(JSONLoader & json) : Declaration(json) {
    json.load("annotations", annotations);
    json.load("type", type);
    json.load("arguments", arguments);
    json.load("properties", properties);
    json.load("initializer", initializer);
}
IR::Node * IR::Declaration_Instance::fromJSON(JSONLoader & json) { return new Declaration_Instance(json); }
IR::Declaration_Instance::Declaration_Instance(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer) :
    Declaration(srcInfo, name), annotations(annotations), type(type), arguments(arguments), initializer(initializer)
    { validate(); }
IR::Declaration_Instance::Declaration_Instance(IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer) :
    Declaration(name), annotations(annotations), type(type), arguments(arguments), initializer(initializer)
    { validate(); }
IR::Declaration_Instance::Declaration_Instance(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer) :
    Declaration(srcInfo, name), type(type), arguments(arguments), initializer(initializer)
    { validate(); }
IR::Declaration_Instance::Declaration_Instance(IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer) :
    Declaration(name), type(type), arguments(arguments), initializer(initializer)
    { validate(); }
IR::Declaration_Instance::Declaration_Instance(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments) :
    Declaration(srcInfo, name), annotations(annotations), type(type), arguments(arguments)
    { validate(); }
IR::Declaration_Instance::Declaration_Instance(IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments) :
    Declaration(name), annotations(annotations), type(type), arguments(arguments)
    { validate(); }
IR::Declaration_Instance::Declaration_Instance(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments) :
    Declaration(srcInfo, name), type(type), arguments(arguments)
    { validate(); }
IR::Declaration_Instance::Declaration_Instance(IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments) :
    Declaration(name), type(type), arguments(arguments)
    { validate(); }
/// Top-level program objects.
/// This is not an IndexedVector because:
/// - we allow overloaded function-like objects.
/// - not all objects in a P4Program are declarations (e.g., match_kind is not).
#line 418 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::P4Program::validate() const {
#line 8293 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        objects.validate();
#line 418 "/home/fengyong/Desktop/p4c/ir/ir.def"
{ objects.check_null(); } }
#line 8298 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
IRNODE_DEFINE_APPLY_OVERLOAD(P4Program, , )
bool IR::P4Program::operator==(IR::P4Program const & a) const {
        return typeid(*this) == typeid(a)
        && objects == a.objects;
    }
bool IR::P4Program::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const P4Program &>(a_);
        return objects.equiv(a.objects);
    }
void IR::P4Program::visit_children(Visitor & v) {
    Node::visit_children(v);
    objects.visit_children(v);
}
void IR::P4Program::visit_children(Visitor & v) const {
    Node::visit_children(v);
    objects.visit_children(v);
}
void IR::P4Program::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"objects\" : " << this->objects;
}
IR::P4Program::P4Program(JSONLoader & json) : Node(json) {
    json.load("objects", objects);
}
IR::Node * IR::P4Program::fromJSON(JSONLoader & json) { return new P4Program(json); }
IR::P4Program::P4Program(Util::SourceInfo srcInfo, IR::Vector<IR::Node> objects) :
    Node(srcInfo), objects(objects)
    { validate(); }
IR::P4Program::P4Program(IR::Vector<IR::Node> objects) :
    objects(objects)
    { validate(); }
IR::P4Program::P4Program(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::P4Program::P4Program() 
    { validate(); }
bool IR::Statement::operator==(IR::Statement const & a) const {
        return StatOrDecl::operator==(static_cast<const StatOrDecl &>(a));
    }
bool IR::Statement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!StatOrDecl::equiv(a_)) return false;
        return true;
    }
void IR::Statement::toJSON(JSONGenerator & json) const {
    StatOrDecl::toJSON(json);
}
IR::Statement::Statement(JSONLoader & json) : StatOrDecl(json) {
}
IR::Statement::Statement(Util::SourceInfo srcInfo) :
    StatOrDecl(srcInfo)
    { validate(); }
IR::Statement::Statement() 
    { validate(); }
#line 428 "/home/fengyong/Desktop/p4c/ir/ir.def"
cstring IR::ExitStatement::toString() const { return "exit"; }
#line 8357 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 429 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::ExitStatement::dbprint(std::ostream & out) const { out << "exit"; }
#line 8360 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::ExitStatement::operator==(IR::ExitStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a));
    }
bool IR::ExitStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        return true;
    }
void IR::ExitStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
}
IR::ExitStatement::ExitStatement(JSONLoader & json) : Statement(json) {
}
IR::Node * IR::ExitStatement::fromJSON(JSONLoader & json) { return new ExitStatement(json); }
IR::ExitStatement::ExitStatement(Util::SourceInfo srcInfo) :
    Statement(srcInfo)
    { validate(); }
IR::ExitStatement::ExitStatement() 
    { validate(); }
#line 434 "/home/fengyong/Desktop/p4c/ir/ir.def"
cstring IR::ReturnStatement::toString() const { return cstring("return ") +
                (expression != nullptr ? expression->toString() : cstring("")); }
#line 8383 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::ReturnStatement::operator==(IR::ReturnStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a))
        && expression == a.expression;
    }
bool IR::ReturnStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        auto &a = static_cast<const ReturnStatement &>(a_);
        return (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr);
    }
void IR::ReturnStatement::visit_children(Visitor & v) {
    Statement::visit_children(v);
    v.visit(expression, "expression");
}
void IR::ReturnStatement::visit_children(Visitor & v) const {
    Statement::visit_children(v);
    v.visit(expression, "expression");
}
void IR::ReturnStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
    if (expression != nullptr)     json << "," << std::endl << json.indent << "\"expression\" : " << this->expression;
}
IR::ReturnStatement::ReturnStatement(JSONLoader & json) : Statement(json) {
    json.load("expression", expression);
}
IR::Node * IR::ReturnStatement::fromJSON(JSONLoader & json) { return new ReturnStatement(json); }
IR::ReturnStatement::ReturnStatement(Util::SourceInfo srcInfo, const IR::Expression* expression) :
    Statement(srcInfo), expression(expression)
    { validate(); }
IR::ReturnStatement::ReturnStatement(const IR::Expression* expression) :
    expression(expression)
    { validate(); }
#line 439 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::EmptyStatement::dbprint(std::ostream & out) const { out << ""; }
#line 8418 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::EmptyStatement::operator==(IR::EmptyStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a));
    }
bool IR::EmptyStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        return true;
    }
void IR::EmptyStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
}
IR::EmptyStatement::EmptyStatement(JSONLoader & json) : Statement(json) {
}
IR::Node * IR::EmptyStatement::fromJSON(JSONLoader & json) { return new EmptyStatement(json); }
IR::EmptyStatement::EmptyStatement(Util::SourceInfo srcInfo) :
    Statement(srcInfo)
    { validate(); }
IR::EmptyStatement::EmptyStatement() 
    { validate(); }
bool IR::AssignmentStatement::operator==(IR::AssignmentStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a))
        && left == a.left
        && right == a.right;
    }
bool IR::AssignmentStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        auto &a = static_cast<const AssignmentStatement &>(a_);
        return (left ? a.left ? left->equiv(*a.left) : false : a.left == nullptr)
        && (right ? a.right ? right->equiv(*a.right) : false : a.right == nullptr);
    }
void IR::AssignmentStatement::visit_children(Visitor & v) {
    Statement::visit_children(v);
    v.visit(left, "left");
    v.visit(right, "right");
}
void IR::AssignmentStatement::visit_children(Visitor & v) const {
    Statement::visit_children(v);
    v.visit(left, "left");
    v.visit(right, "right");
}
void IR::AssignmentStatement::validate() const {
#line 8461 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(left);
        CHECK_NULL(right); }
void IR::AssignmentStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
    json << "," << std::endl << json.indent << "\"left\" : " << this->left;
    json << "," << std::endl << json.indent << "\"right\" : " << this->right;
}
IR::AssignmentStatement::AssignmentStatement(JSONLoader & json) : Statement(json) {
    json.load("left", left);
    json.load("right", right);
}
IR::Node * IR::AssignmentStatement::fromJSON(JSONLoader & json) { return new AssignmentStatement(json); }
IR::AssignmentStatement::AssignmentStatement(Util::SourceInfo srcInfo, const IR::Expression* left, const IR::Expression* right) :
    Statement(srcInfo), left(left), right(right)
    { validate(); }
IR::AssignmentStatement::AssignmentStatement(const IR::Expression* left, const IR::Expression* right) :
    left(left), right(right)
    { validate(); }
#line 451 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::IfStatement::visit_children(Visitor & v) {
        v.visit(condition, "condition");
        SplitFlowVisit<Statement>(v, ifTrue, ifFalse).run_visit(); }
#line 451 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::IfStatement::visit_children(Visitor & v) const {
        v.visit(condition, "condition");
        SplitFlowVisit<Statement>(v, ifTrue, ifFalse).run_visit(); }
#line 8489 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::IfStatement::operator==(IR::IfStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a))
        && condition == a.condition
        && ifTrue == a.ifTrue
        && ifFalse == a.ifFalse;
    }
bool IR::IfStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        auto &a = static_cast<const IfStatement &>(a_);
        return (condition ? a.condition ? condition->equiv(*a.condition) : false : a.condition == nullptr)
        && (ifTrue ? a.ifTrue ? ifTrue->equiv(*a.ifTrue) : false : a.ifTrue == nullptr)
        && (ifFalse ? a.ifFalse ? ifFalse->equiv(*a.ifFalse) : false : a.ifFalse == nullptr);
    }
void IR::IfStatement::validate() const {
#line 8505 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(condition);
        CHECK_NULL(ifTrue); }
void IR::IfStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
    json << "," << std::endl << json.indent << "\"condition\" : " << this->condition;
    json << "," << std::endl << json.indent << "\"ifTrue\" : " << this->ifTrue;
    if (ifFalse != nullptr)     json << "," << std::endl << json.indent << "\"ifFalse\" : " << this->ifFalse;
}
IR::IfStatement::IfStatement(JSONLoader & json) : Statement(json) {
    json.load("condition", condition);
    json.load("ifTrue", ifTrue);
    json.load("ifFalse", ifFalse);
}
IR::Node * IR::IfStatement::fromJSON(JSONLoader & json) { return new IfStatement(json); }
IR::IfStatement::IfStatement(Util::SourceInfo srcInfo, const IR::Expression* condition, const IR::Statement* ifTrue, const IR::Statement* ifFalse) :
    Statement(srcInfo), condition(condition), ifTrue(ifTrue), ifFalse(ifFalse)
    { validate(); }
IR::IfStatement::IfStatement(const IR::Expression* condition, const IR::Statement* ifTrue, const IR::Statement* ifFalse) :
    condition(condition), ifTrue(ifTrue), ifFalse(ifFalse)
    { validate(); }
#line 459 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::IDeclaration *IR::BlockStatement::getDeclByName(cstring name) const {
        return components.getDeclaration(name); }
#line 8530 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 461 "/home/fengyong/Desktop/p4c/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::BlockStatement::getDeclarations() const {
        return components.getDeclarations(); }
#line 8534 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 463 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::BlockStatement::push_back(const IR::StatOrDecl* st) { components.push_back(st); }
#line 8537 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 464 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::Annotations *IR::BlockStatement::getAnnotations() const { return annotations; }
#line 8540 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 465 "/home/fengyong/Desktop/p4c/ir/ir.def"
bool IR::BlockStatement::empty() const { return components.empty(); }
#line 8543 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::BlockStatement::operator==(IR::BlockStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a))
        && annotations == a.annotations
        && components == a.components;
    }
bool IR::BlockStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        auto &a = static_cast<const BlockStatement &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && components.equiv(a.components);
    }
void IR::BlockStatement::visit_children(Visitor & v) {
    Statement::visit_children(v);
    v.visit(annotations, "annotations");
    components.visit_children(v);
}
void IR::BlockStatement::visit_children(Visitor & v) const {
    Statement::visit_children(v);
    v.visit(annotations, "annotations");
    components.visit_children(v);
}
void IR::BlockStatement::validate() const {
#line 8567 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        components.validate(); }
void IR::BlockStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"components\" : " << this->components;
}
IR::BlockStatement::BlockStatement(JSONLoader & json) : Statement(json) {
    json.load("annotations", annotations);
    json.load("components", components);
}
IR::Node * IR::BlockStatement::fromJSON(JSONLoader & json) { return new BlockStatement(json); }
IR::BlockStatement::BlockStatement(Util::SourceInfo srcInfo, const IR::Annotations* annotations, IR::IndexedVector<IR::StatOrDecl> components) :
    Statement(srcInfo), annotations(annotations), components(components)
    { validate(); }
IR::BlockStatement::BlockStatement(const IR::Annotations* annotations, IR::IndexedVector<IR::StatOrDecl> components) :
    annotations(annotations), components(components)
    { validate(); }
IR::BlockStatement::BlockStatement(Util::SourceInfo srcInfo, IR::IndexedVector<IR::StatOrDecl> components) :
    Statement(srcInfo), components(components)
    { validate(); }
IR::BlockStatement::BlockStatement(IR::IndexedVector<IR::StatOrDecl> components) :
    components(components)
    { validate(); }
IR::BlockStatement::BlockStatement(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    Statement(srcInfo), annotations(annotations)
    { validate(); }
IR::BlockStatement::BlockStatement(const IR::Annotations* annotations) :
    annotations(annotations)
    { validate(); }
IR::BlockStatement::BlockStatement(Util::SourceInfo srcInfo) :
    Statement(srcInfo)
    { validate(); }
IR::BlockStatement::BlockStatement() 
    { validate(); }
#line 471 "/home/fengyong/Desktop/p4c/ir/ir.def"
IR::MethodCallStatement::MethodCallStatement(Util::SourceInfo si, IR::ID m, std::initializer_list<const IR::Argument *> const & a) : Statement(si), methodCall(new MethodCallExpression(si, m, a)) {}
#line 8606 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 473 "/home/fengyong/Desktop/p4c/ir/ir.def"
IR::MethodCallStatement::MethodCallStatement(Util::SourceInfo si, const IR::Expression* m, std::initializer_list<const IR::Argument *> const & a) : Statement(si), methodCall(new MethodCallExpression(si, m, a)) {}
#line 8609 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 476 "/home/fengyong/Desktop/p4c/ir/ir.def"
cstring IR::MethodCallStatement::toString() const { return methodCall->toString(); }
#line 8612 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::MethodCallStatement::operator==(IR::MethodCallStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a))
        && methodCall == a.methodCall;
    }
bool IR::MethodCallStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        auto &a = static_cast<const MethodCallStatement &>(a_);
        return (methodCall ? a.methodCall ? methodCall->equiv(*a.methodCall) : false : a.methodCall == nullptr);
    }
void IR::MethodCallStatement::visit_children(Visitor & v) {
    Statement::visit_children(v);
    v.visit(methodCall, "methodCall");
}
void IR::MethodCallStatement::visit_children(Visitor & v) const {
    Statement::visit_children(v);
    v.visit(methodCall, "methodCall");
}
void IR::MethodCallStatement::validate() const {
#line 8632 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(methodCall); }
void IR::MethodCallStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
    json << "," << std::endl << json.indent << "\"methodCall\" : " << this->methodCall;
}
IR::MethodCallStatement::MethodCallStatement(JSONLoader & json) : Statement(json) {
    json.load("methodCall", methodCall);
}
IR::Node * IR::MethodCallStatement::fromJSON(JSONLoader & json) { return new MethodCallStatement(json); }
IR::MethodCallStatement::MethodCallStatement(Util::SourceInfo srcInfo, const IR::MethodCallExpression* methodCall) :
    Statement(srcInfo), methodCall(methodCall)
    {
#line 470 "/home/fengyong/Desktop/p4c/ir/ir.def"
{ if (!srcInfo) srcInfo = methodCall->srcInfo; }
#line 8648 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::MethodCallStatement::MethodCallStatement(const IR::MethodCallExpression* methodCall) :
    methodCall(methodCall)
    {
#line 470 "/home/fengyong/Desktop/p4c/ir/ir.def"
{ if (!srcInfo) srcInfo = methodCall->srcInfo; }
#line 8655 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }

#line 483 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::SwitchCase::validate() const {
#line 8660 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(label);
#line 483 "/home/fengyong/Desktop/p4c/ir/ir.def"
{
        BUG_CHECK(statement == nullptr || statement->is<IR::BlockStatement>(),
                  "%1%: Expected a block statement",
                  statement);
    } }
#line 8669 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::SwitchCase::operator==(IR::SwitchCase const & a) const {
        return typeid(*this) == typeid(a)
        && label == a.label
        && statement == a.statement;
    }
bool IR::SwitchCase::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const SwitchCase &>(a_);
        return (label ? a.label ? label->equiv(*a.label) : false : a.label == nullptr)
        && (statement ? a.statement ? statement->equiv(*a.statement) : false : a.statement == nullptr);
    }
void IR::SwitchCase::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(label, "label");
    v.visit(statement, "statement");
}
void IR::SwitchCase::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(label, "label");
    v.visit(statement, "statement");
}
void IR::SwitchCase::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"label\" : " << this->label;
    if (statement != nullptr)     json << "," << std::endl << json.indent << "\"statement\" : " << this->statement;
}
IR::SwitchCase::SwitchCase(JSONLoader & json) : Node(json) {
    json.load("label", label);
    json.load("statement", statement);
}
IR::Node * IR::SwitchCase::fromJSON(JSONLoader & json) { return new SwitchCase(json); }
IR::SwitchCase::SwitchCase(Util::SourceInfo srcInfo, const IR::Expression* label, const IR::Statement* statement) :
    Node(srcInfo), label(label), statement(statement)
    { validate(); }
IR::SwitchCase::SwitchCase(const IR::Expression* label, const IR::Statement* statement) :
    label(label), statement(statement)
    { validate(); }
#line 495 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::SwitchStatement::visit_children(Visitor & v) {
        v.visit(expression, "expression");
        SplitFlowVisit<SwitchCase> split(v);
        for (auto &c : cases) split.addNode(c);
        split.run_visit(); }
#line 495 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::SwitchStatement::visit_children(Visitor & v) const {
        v.visit(expression, "expression");
        SplitFlowVisit<SwitchCase> split(v);
        for (auto &c : cases) split.addNode(c);
        split.run_visit(); }
#line 8720 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::SwitchStatement::operator==(IR::SwitchStatement const & a) const {
        return Statement::operator==(static_cast<const Statement &>(a))
        && expression == a.expression
        && cases == a.cases;
    }
bool IR::SwitchStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Statement::equiv(a_)) return false;
        auto &a = static_cast<const SwitchStatement &>(a_);
        return (expression ? a.expression ? expression->equiv(*a.expression) : false : a.expression == nullptr)
        && cases.equiv(a.cases);
    }
void IR::SwitchStatement::validate() const {
#line 8734 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(expression);
        cases.validate(); }
void IR::SwitchStatement::toJSON(JSONGenerator & json) const {
    Statement::toJSON(json);
    json << "," << std::endl << json.indent << "\"expression\" : " << this->expression;
    json << "," << std::endl << json.indent << "\"cases\" : " << this->cases;
}
IR::SwitchStatement::SwitchStatement(JSONLoader & json) : Statement(json) {
    json.load("expression", expression);
    json.load("cases", cases);
}
IR::Node * IR::SwitchStatement::fromJSON(JSONLoader & json) { return new SwitchStatement(json); }
IR::SwitchStatement::SwitchStatement(Util::SourceInfo srcInfo, const IR::Expression* expression, IR::Vector<IR::SwitchCase> cases) :
    Statement(srcInfo), expression(expression), cases(cases)
    { validate(); }
IR::SwitchStatement::SwitchStatement(const IR::Expression* expression, IR::Vector<IR::SwitchCase> cases) :
    expression(expression), cases(cases)
    { validate(); }
#line 505 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::ParameterList *IR::Function::getParameters() const {
        return type->parameters;
    }
#line 8758 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 508 "/home/fengyong/Desktop/p4c/ir/ir.def"
Util::Enumerator<const IR::IDeclaration *> * IR::Function::getDeclarations() const {
        return type->parameters->getDeclarations(); }
#line 8762 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 510 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::IDeclaration *IR::Function::getDeclByName(cstring name) const {
        return type->parameters->getDeclByName(name); }
#line 8766 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 512 "/home/fengyong/Desktop/p4c/ir/ir.def"
std::vector<const IR::INamespace *> IR::Function::getNestedNamespaces() const {
        return { type->typeParameters }; }
#line 8770 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Function::operator==(IR::Function const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && type == a.type
        && body == a.body;
    }
bool IR::Function::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Function &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (body ? a.body ? body->equiv(*a.body) : false : a.body == nullptr);
    }
void IR::Function::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(type, "type");
    v.visit(body, "body");
}
void IR::Function::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(type, "type");
    v.visit(body, "body");
}
void IR::Function::validate() const {
#line 8794 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(type);
        CHECK_NULL(body); }
void IR::Function::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
    json << "," << std::endl << json.indent << "\"body\" : " << this->body;
}
IR::Function::Function(JSONLoader & json) : Declaration(json) {
    json.load("type", type);
    json.load("body", body);
}
IR::Node * IR::Function::fromJSON(JSONLoader & json) { return new Function(json); }
IR::Function::Function(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Method* type, const IR::BlockStatement* body) :
    Declaration(srcInfo, name), type(type), body(body)
    { validate(); }
IR::Function::Function(IR::ID name, const IR::Type_Method* type, const IR::BlockStatement* body) :
    Declaration(name), type(type), body(body)
    { validate(); }
/// Node that evaluates to this block.
/// This is either a Declaration_Instance or a ConstructorCallExpression.
/// One value for each Node inside that evaluates to a compile-time constant.
/// This includes all constructor parameters, and all inner nested blocks.
/// value can be null for parameters which are optional
#line 537 "/home/fengyong/Desktop/p4c/ir/ir.def"
bool IR::Block::hasValue(const IR::Node* node) const {
        return constantValue.find(node) != constantValue.end();
    }
#line 8823 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 540 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::CompileTimeValue *IR::Block::getValue(const IR::Node* node) const {
        CHECK_NULL(node);
        auto it = constantValue.find(node);
        BUG_CHECK(it != constantValue.end(), "%1%: No such node %2%", this, node);
        return it->second; }
#line 8830 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 545 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::Block::visit_children(Visitor & v) { (void)v; }
#line 545 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::Block::visit_children(Visitor & v) const { (void)v; }
#line 8835 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 546 "/home/fengyong/Desktop/p4c/ir/ir.def"
IR::IDeclaration const * IR::Block::getContainer() const { return nullptr; }
#line 8838 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Block::operator==(IR::Block const & a) const {
        return typeid(*this) == typeid(a)
        && node == a.node
        && constantValue == a.constantValue;
    }
bool IR::Block::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const Block &>(a_);
        return (node ? a.node ? node->equiv(*a.node) : false : a.node == nullptr)
        && constantValue == a.constantValue;
    }
void IR::Block::validate() const {
#line 8852 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(node); }
void IR::Block::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"node\" : " << this->node;
    json << "," << std::endl << json.indent << "\"constantValue\" : " << this->constantValue;
}
IR::Block::Block(JSONLoader & json) : Node(json) {
    json.load("node", node);
    json.load("constantValue", constantValue);
}
IR::Block::Block(Util::SourceInfo srcInfo, const IR::Node* node) :
    Node(srcInfo), node(node)
    { validate(); }
IR::Block::Block(const IR::Node* node) :
    node(node)
    { validate(); }
#line 551 "/home/fengyong/Desktop/p4c/ir/ir.def"
IR::IDeclaration const * IR::TableBlock::getContainer() const { return container; }
#line 8872 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::TableBlock::operator==(IR::TableBlock const & a) const {
        return Block::operator==(static_cast<const Block &>(a))
        && container == a.container;
    }
bool IR::TableBlock::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Block::equiv(a_)) return false;
        auto &a = static_cast<const TableBlock &>(a_);
        return (container ? a.container ? container->equiv(*a.container) : false : a.container == nullptr);
    }
void IR::TableBlock::visit_children(Visitor & v) {
    Block::visit_children(v);
    v.visit(container, "container");
}
void IR::TableBlock::visit_children(Visitor & v) const {
    Block::visit_children(v);
    v.visit(container, "container");
}
void IR::TableBlock::validate() const {
#line 8892 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(container); }
void IR::TableBlock::toJSON(JSONGenerator & json) const {
    Block::toJSON(json);
    json << "," << std::endl << json.indent << "\"container\" : " << this->container;
}
IR::TableBlock::TableBlock(JSONLoader & json) : Block(json) {
    json.load("container", container);
}
IR::Node * IR::TableBlock::fromJSON(JSONLoader & json) { return new TableBlock(json); }
IR::TableBlock::TableBlock(Util::SourceInfo srcInfo, const IR::Node* node, const IR::P4Table* container) :
    Block(srcInfo, node), container(container)
    { validate(); }
IR::TableBlock::TableBlock(const IR::Node* node, const IR::P4Table* container) :
    Block(node), container(container)
    { validate(); }

/// @return the argument that the given parameter was instantiated with.
/// It's a fatal error if no such parameter exists.
/// @return the argument that the given parameter was instantiated with, or
/// null if no such parameter exists.
bool IR::InstantiatedBlock::operator==(IR::InstantiatedBlock const & a) const {
        return Block::operator==(static_cast<const Block &>(a))
        && instanceType == a.instanceType;
    }
bool IR::InstantiatedBlock::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Block::equiv(a_)) return false;
        auto &a = static_cast<const InstantiatedBlock &>(a_);
        return (instanceType ? a.instanceType ? instanceType->equiv(*a.instanceType) : false : a.instanceType == nullptr);
    }
void IR::InstantiatedBlock::visit_children(Visitor & v) {
    Block::visit_children(v);
    v.visit(instanceType, "instanceType");
}
void IR::InstantiatedBlock::visit_children(Visitor & v) const {
    Block::visit_children(v);
    v.visit(instanceType, "instanceType");
}
void IR::InstantiatedBlock::validate() const {
#line 8933 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(instanceType); }
void IR::InstantiatedBlock::toJSON(JSONGenerator & json) const {
    Block::toJSON(json);
    json << "," << std::endl << json.indent << "\"instanceType\" : " << this->instanceType;
}
IR::InstantiatedBlock::InstantiatedBlock(JSONLoader & json) : Block(json) {
    json.load("instanceType", instanceType);
}
IR::InstantiatedBlock::InstantiatedBlock(Util::SourceInfo srcInfo, const IR::Node* node, const IR::Type* instanceType) :
    Block(srcInfo, node), instanceType(instanceType)
    { validate(); }
IR::InstantiatedBlock::InstantiatedBlock(const IR::Node* node, const IR::Type* instanceType) :
    Block(node), instanceType(instanceType)
    { validate(); }
#line 575 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::ParameterList *IR::ParserBlock::getConstructorParameters() const {
        return container->constructorParams; }
#line 8952 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 577 "/home/fengyong/Desktop/p4c/ir/ir.def"
cstring IR::ParserBlock::toString() const { return container->toString(); }
#line 8955 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 578 "/home/fengyong/Desktop/p4c/ir/ir.def"
IR::ID IR::ParserBlock::getName() const { return container->getName(); }
#line 8958 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 579 "/home/fengyong/Desktop/p4c/ir/ir.def"
IR::IDeclaration const * IR::ParserBlock::getContainer() const { return container; }
#line 8961 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::ParserBlock::operator==(IR::ParserBlock const & a) const {
        return InstantiatedBlock::operator==(static_cast<const InstantiatedBlock &>(a))
        && container == a.container;
    }
bool IR::ParserBlock::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!InstantiatedBlock::equiv(a_)) return false;
        auto &a = static_cast<const ParserBlock &>(a_);
        return (container ? a.container ? container->equiv(*a.container) : false : a.container == nullptr);
    }
void IR::ParserBlock::visit_children(Visitor & v) {
    InstantiatedBlock::visit_children(v);
    v.visit(container, "container");
}
void IR::ParserBlock::visit_children(Visitor & v) const {
    InstantiatedBlock::visit_children(v);
    v.visit(container, "container");
}
void IR::ParserBlock::validate() const {
#line 8981 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(container); }
void IR::ParserBlock::toJSON(JSONGenerator & json) const {
    InstantiatedBlock::toJSON(json);
    json << "," << std::endl << json.indent << "\"container\" : " << this->container;
}
IR::ParserBlock::ParserBlock(JSONLoader & json) : InstantiatedBlock(json) {
    json.load("container", container);
}
IR::Node * IR::ParserBlock::fromJSON(JSONLoader & json) { return new ParserBlock(json); }
IR::ParserBlock::ParserBlock(Util::SourceInfo srcInfo, const IR::Node* node, const IR::Type* instanceType, const IR::P4Parser* container) :
    InstantiatedBlock(srcInfo, node, instanceType), container(container)
    { validate(); }
IR::ParserBlock::ParserBlock(const IR::Node* node, const IR::Type* instanceType, const IR::P4Parser* container) :
    InstantiatedBlock(node, instanceType), container(container)
    { validate(); }
#line 585 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::ParameterList *IR::ControlBlock::getConstructorParameters() const {
        return container->constructorParams; }
#line 9001 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 587 "/home/fengyong/Desktop/p4c/ir/ir.def"
cstring IR::ControlBlock::toString() const { return container->toString(); }
#line 9004 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 588 "/home/fengyong/Desktop/p4c/ir/ir.def"
IR::ID IR::ControlBlock::getName() const { return container->getName(); }
#line 9007 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 589 "/home/fengyong/Desktop/p4c/ir/ir.def"
IR::IDeclaration const * IR::ControlBlock::getContainer() const { return container; }
#line 9010 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::ControlBlock::operator==(IR::ControlBlock const & a) const {
        return InstantiatedBlock::operator==(static_cast<const InstantiatedBlock &>(a))
        && container == a.container;
    }
bool IR::ControlBlock::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!InstantiatedBlock::equiv(a_)) return false;
        auto &a = static_cast<const ControlBlock &>(a_);
        return (container ? a.container ? container->equiv(*a.container) : false : a.container == nullptr);
    }
void IR::ControlBlock::visit_children(Visitor & v) {
    InstantiatedBlock::visit_children(v);
    v.visit(container, "container");
}
void IR::ControlBlock::visit_children(Visitor & v) const {
    InstantiatedBlock::visit_children(v);
    v.visit(container, "container");
}
void IR::ControlBlock::validate() const {
#line 9030 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(container); }
void IR::ControlBlock::toJSON(JSONGenerator & json) const {
    InstantiatedBlock::toJSON(json);
    json << "," << std::endl << json.indent << "\"container\" : " << this->container;
}
IR::ControlBlock::ControlBlock(JSONLoader & json) : InstantiatedBlock(json) {
    json.load("container", container);
}
IR::Node * IR::ControlBlock::fromJSON(JSONLoader & json) { return new ControlBlock(json); }
IR::ControlBlock::ControlBlock(Util::SourceInfo srcInfo, const IR::Node* node, const IR::Type* instanceType, const IR::P4Control* container) :
    InstantiatedBlock(srcInfo, node, instanceType), container(container)
    { validate(); }
IR::ControlBlock::ControlBlock(const IR::Node* node, const IR::Type* instanceType, const IR::P4Control* container) :
    InstantiatedBlock(node, instanceType), container(container)
    { validate(); }
#line 595 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::ParameterList *IR::PackageBlock::getConstructorParameters() const { return type->constructorParams; }
#line 9049 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 596 "/home/fengyong/Desktop/p4c/ir/ir.def"
cstring IR::PackageBlock::toString() const { return type->toString(); }
#line 9052 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 597 "/home/fengyong/Desktop/p4c/ir/ir.def"
IR::ID IR::PackageBlock::getName() const { return type->getName(); }
#line 9055 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::PackageBlock::operator==(IR::PackageBlock const & a) const {
        return InstantiatedBlock::operator==(static_cast<const InstantiatedBlock &>(a))
        && type == a.type;
    }
bool IR::PackageBlock::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!InstantiatedBlock::equiv(a_)) return false;
        auto &a = static_cast<const PackageBlock &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr);
    }
void IR::PackageBlock::visit_children(Visitor & v) {
    InstantiatedBlock::visit_children(v);
    v.visit(type, "type");
}
void IR::PackageBlock::visit_children(Visitor & v) const {
    InstantiatedBlock::visit_children(v);
    v.visit(type, "type");
}
void IR::PackageBlock::validate() const {
#line 9075 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(type); }
void IR::PackageBlock::toJSON(JSONGenerator & json) const {
    InstantiatedBlock::toJSON(json);
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
}
IR::PackageBlock::PackageBlock(JSONLoader & json) : InstantiatedBlock(json) {
    json.load("type", type);
}
IR::Node * IR::PackageBlock::fromJSON(JSONLoader & json) { return new PackageBlock(json); }
IR::PackageBlock::PackageBlock(Util::SourceInfo srcInfo, const IR::Node* node, const IR::Type* instanceType, const IR::Type_Package* type) :
    InstantiatedBlock(srcInfo, node, instanceType), type(type)
    { validate(); }
IR::PackageBlock::PackageBlock(const IR::Node* node, const IR::Type* instanceType, const IR::Type_Package* type) :
    InstantiatedBlock(node, instanceType), type(type)
    { validate(); }

#line 604 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::ParameterList *IR::ExternBlock::getConstructorParameters() const {
        return constructor->type->parameters; }
#line 9096 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 606 "/home/fengyong/Desktop/p4c/ir/ir.def"
cstring IR::ExternBlock::toString() const { return type->toString(); }
#line 9099 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 607 "/home/fengyong/Desktop/p4c/ir/ir.def"
IR::ID IR::ExternBlock::getName() const { return type->getName(); }
#line 9102 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::ExternBlock::operator==(IR::ExternBlock const & a) const {
        return InstantiatedBlock::operator==(static_cast<const InstantiatedBlock &>(a))
        && type == a.type
        && constructor == a.constructor;
    }
bool IR::ExternBlock::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!InstantiatedBlock::equiv(a_)) return false;
        auto &a = static_cast<const ExternBlock &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (constructor ? a.constructor ? constructor->equiv(*a.constructor) : false : a.constructor == nullptr);
    }
void IR::ExternBlock::visit_children(Visitor & v) {
    InstantiatedBlock::visit_children(v);
    v.visit(type, "type");
    v.visit(constructor, "constructor");
}
void IR::ExternBlock::visit_children(Visitor & v) const {
    InstantiatedBlock::visit_children(v);
    v.visit(type, "type");
    v.visit(constructor, "constructor");
}
void IR::ExternBlock::validate() const {
#line 9126 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(type);
        CHECK_NULL(constructor); }
void IR::ExternBlock::toJSON(JSONGenerator & json) const {
    InstantiatedBlock::toJSON(json);
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
    json << "," << std::endl << json.indent << "\"constructor\" : " << this->constructor;
}
IR::ExternBlock::ExternBlock(JSONLoader & json) : InstantiatedBlock(json) {
    json.load("type", type);
    json.load("constructor", constructor);
}
IR::Node * IR::ExternBlock::fromJSON(JSONLoader & json) { return new ExternBlock(json); }
IR::ExternBlock::ExternBlock(Util::SourceInfo srcInfo, const IR::Node* node, const IR::Type* instanceType, const IR::Type_Extern* type, const IR::Method* constructor) :
    InstantiatedBlock(srcInfo, node, instanceType), type(type), constructor(constructor)
    { validate(); }
IR::ExternBlock::ExternBlock(const IR::Node* node, const IR::Type* instanceType, const IR::Type_Extern* type, const IR::Method* constructor) :
    InstantiatedBlock(node, instanceType), type(type), constructor(constructor)
    { validate(); }
#line 613 "/home/fengyong/Desktop/p4c/ir/ir.def"
const IR::P4Program *IR::ToplevelBlock::getProgram() const { return node->to<IR::P4Program>(); }
#line 9148 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 615 "/home/fengyong/Desktop/p4c/ir/ir.def"
IR::ID IR::ToplevelBlock::getName() const { return "main"; }
#line 9151 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 617 "/home/fengyong/Desktop/p4c/ir/ir.def"
void IR::ToplevelBlock::validate() const {
#line 9154 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

#line 617 "/home/fengyong/Desktop/p4c/ir/ir.def"
{ BUG_CHECK(node->is<IR::P4Program>(), "%1%: expected a P4Program", node); } }
#line 9158 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::ToplevelBlock::operator==(IR::ToplevelBlock const & a) const {
        return Block::operator==(static_cast<const Block &>(a));
    }
bool IR::ToplevelBlock::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Block::equiv(a_)) return false;
        return true;
    }
void IR::ToplevelBlock::toJSON(JSONGenerator & json) const {
    Block::toJSON(json);
}
IR::ToplevelBlock::ToplevelBlock(JSONLoader & json) : Block(json) {
}
IR::Node * IR::ToplevelBlock::fromJSON(JSONLoader & json) { return new ToplevelBlock(json); }
IR::ToplevelBlock::ToplevelBlock(Util::SourceInfo srcInfo, const IR::Node* node) :
    Block(srcInfo, node)
    { validate(); }
IR::ToplevelBlock::ToplevelBlock(const IR::Node* node) :
    Block(node)
    { validate(); }
/** @} */
/* end group irdefs */
/* -*-C++-*- */
/*
  This file contains IR classes needed just for the P4 v1.0/v1.1 front-end.
*/
/** \addtogroup irdefs
  * @{
  */
#line 46 "/home/fengyong/Desktop/p4c/ir/v1.def"
cstring IR::Type_Block::toString() const { return "block"; }
#line 9190 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 48 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::Type_Block::dbprint(std::ostream & out) const { out << "block"; }
#line 9193 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Block::operator==(IR::Type_Block const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Block::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Block::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Block::Type_Block(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Block::fromJSON(JSONLoader & json) { return new Type_Block(json); }
IR::Type_Block::Type_Block(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_Block::Type_Block() 
    { validate(); }
#line 51 "/home/fengyong/Desktop/p4c/ir/v1.def"
cstring IR::Type_Counter::toString() const { return "counter"; }
#line 9215 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 53 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::Type_Counter::dbprint(std::ostream & out) const { out << "counter"; }
#line 9218 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Counter::operator==(IR::Type_Counter const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Counter::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Counter::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Counter::Type_Counter(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Counter::fromJSON(JSONLoader & json) { return new Type_Counter(json); }
IR::Type_Counter::Type_Counter(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_Counter::Type_Counter() 
    { validate(); }
#line 56 "/home/fengyong/Desktop/p4c/ir/v1.def"
cstring IR::Type_Expression::toString() const { return "expression"; }
#line 9240 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 58 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::Type_Expression::dbprint(std::ostream & out) const { out << "expression"; }
#line 9243 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Expression::operator==(IR::Type_Expression const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Expression::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Expression::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Expression::Type_Expression(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Expression::fromJSON(JSONLoader & json) { return new Type_Expression(json); }
IR::Type_Expression::Type_Expression(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_Expression::Type_Expression() 
    { validate(); }
#line 61 "/home/fengyong/Desktop/p4c/ir/v1.def"
cstring IR::Type_FieldListCalculation::toString() const { return "field_list_calculation"; }
#line 9265 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 63 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::Type_FieldListCalculation::dbprint(std::ostream & out) const { out << "field_list_calculation"; }
#line 9268 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_FieldListCalculation::operator==(IR::Type_FieldListCalculation const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_FieldListCalculation::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_FieldListCalculation::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_FieldListCalculation::Type_FieldListCalculation(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_FieldListCalculation::fromJSON(JSONLoader & json) { return new Type_FieldListCalculation(json); }
IR::Type_FieldListCalculation::Type_FieldListCalculation(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_FieldListCalculation::Type_FieldListCalculation() 
    { validate(); }
#line 66 "/home/fengyong/Desktop/p4c/ir/v1.def"
cstring IR::Type_Meter::toString() const { return "meter"; }
#line 9290 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 68 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::Type_Meter::dbprint(std::ostream & out) const { out << "meter"; }
#line 9293 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Meter::operator==(IR::Type_Meter const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Meter::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Meter::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Meter::Type_Meter(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Meter::fromJSON(JSONLoader & json) { return new Type_Meter(json); }
IR::Type_Meter::Type_Meter(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_Meter::Type_Meter() 
    { validate(); }
#line 71 "/home/fengyong/Desktop/p4c/ir/v1.def"
cstring IR::Type_Register::toString() const { return "register"; }
#line 9315 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 73 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::Type_Register::dbprint(std::ostream & out) const { out << "register"; }
#line 9318 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_Register::operator==(IR::Type_Register const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_Register::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_Register::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_Register::Type_Register(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_Register::fromJSON(JSONLoader & json) { return new Type_Register(json); }
IR::Type_Register::Type_Register(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_Register::Type_Register() 
    { validate(); }
#line 76 "/home/fengyong/Desktop/p4c/ir/v1.def"
cstring IR::Type_AnyTable::toString() const { return "table"; }
#line 9340 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 78 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::Type_AnyTable::dbprint(std::ostream & out) const { out << "table"; }
#line 9343 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Type_AnyTable::operator==(IR::Type_AnyTable const & a) const {
        return Type_Base::operator==(static_cast<const Type_Base &>(a));
    }
bool IR::Type_AnyTable::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Base::equiv(a_)) return false;
        return true;
    }
void IR::Type_AnyTable::toJSON(JSONGenerator & json) const {
    Type_Base::toJSON(json);
}
IR::Type_AnyTable::Type_AnyTable(JSONLoader & json) : Type_Base(json) {
}
IR::Node * IR::Type_AnyTable::fromJSON(JSONLoader & json) { return new Type_AnyTable(json); }
IR::Type_AnyTable::Type_AnyTable(Util::SourceInfo srcInfo) :
    Type_Base(srcInfo)
    { validate(); }
IR::Type_AnyTable::Type_AnyTable() 
    { validate(); }
#line 87 "/home/fengyong/Desktop/p4c/ir/v1.def"
const IR::Annotations *IR::HeaderOrMetadata::getAnnotations() const { return annotations; }
#line 9365 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 88 "/home/fengyong/Desktop/p4c/ir/v1.def"
IR::HeaderOrMetadata::HeaderOrMetadata(IR::ID n, const IR::Type_StructLike* t) : type_name(t->name), name(n), annotations(Annotations::empty), type(t) {}
#line 9368 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 90 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::HeaderOrMetadata::dbprint(std::ostream & out) const { out << type_name << ' ' << name; }
#line 9371 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::HeaderOrMetadata::operator==(IR::HeaderOrMetadata const & a) const {
        return typeid(*this) == typeid(a)
        && type_name == a.type_name
        && name == a.name
        && annotations == a.annotations
        && type == a.type;
    }
bool IR::HeaderOrMetadata::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const HeaderOrMetadata &>(a_);
        return type_name == a.type_name
        && name == a.name
        && (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr);
    }
void IR::HeaderOrMetadata::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
}
void IR::HeaderOrMetadata::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
    v.visit(type, "type");
}
void IR::HeaderOrMetadata::validate() const {
#line 9399 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations); }
void IR::HeaderOrMetadata::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " type_name=" << type_name;
        out << " name=" << name;
}
void IR::HeaderOrMetadata::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"type_name\" : " << this->type_name;
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    if (type != nullptr)     json << "," << std::endl << json.indent << "\"type\" : " << this->type;
}
IR::HeaderOrMetadata::HeaderOrMetadata(JSONLoader & json) : Node(json) {
    json.load("type_name", type_name);
    json.load("name", name);
    json.load("annotations", annotations);
    json.load("type", type);
}
IR::HeaderOrMetadata::HeaderOrMetadata(Util::SourceInfo srcInfo, IR::ID type_name, IR::ID name, const IR::Annotations* annotations) :
    Node(srcInfo), type_name(type_name), name(name), annotations(annotations)
    { validate(); }
IR::HeaderOrMetadata::HeaderOrMetadata(IR::ID type_name, IR::ID name, const IR::Annotations* annotations) :
    type_name(type_name), name(name), annotations(annotations)
    { validate(); }
#line 94 "/home/fengyong/Desktop/p4c/ir/v1.def"
IR::Header::Header(IR::ID n, const IR::Type_Header* t) : HeaderOrMetadata(n, t) {}
#line 9428 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Header::operator==(IR::Header const & a) const {
        return HeaderOrMetadata::operator==(static_cast<const HeaderOrMetadata &>(a));
    }
bool IR::Header::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!HeaderOrMetadata::equiv(a_)) return false;
        return true;
    }
void IR::Header::toJSON(JSONGenerator & json) const {
    HeaderOrMetadata::toJSON(json);
}
IR::Header::Header(JSONLoader & json) : HeaderOrMetadata(json) {
}
IR::Node * IR::Header::fromJSON(JSONLoader & json) { return new Header(json); }
IR::Header::Header(Util::SourceInfo srcInfo, IR::ID type_name, IR::ID name, const IR::Annotations* annotations) :
    HeaderOrMetadata(srcInfo, type_name, name, annotations)
    { validate(); }
IR::Header::Header(IR::ID type_name, IR::ID name, const IR::Annotations* annotations) :
    HeaderOrMetadata(type_name, name, annotations)
    { validate(); }
#line 100 "/home/fengyong/Desktop/p4c/ir/v1.def"
IR::HeaderStack::HeaderStack(IR::ID n, const IR::Type_Header* t, int sz) : HeaderOrMetadata(n, t), size(sz) {}
#line 9451 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::HeaderStack::operator==(IR::HeaderStack const & a) const {
        return HeaderOrMetadata::operator==(static_cast<const HeaderOrMetadata &>(a))
        && size == a.size;
    }
bool IR::HeaderStack::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!HeaderOrMetadata::equiv(a_)) return false;
        auto &a = static_cast<const HeaderStack &>(a_);
        return size == a.size;
    }
void IR::HeaderStack::dump_fields(std::ostream & out) const {
    HeaderOrMetadata::dump_fields(out);
        out << " size=" << size;
}
void IR::HeaderStack::toJSON(JSONGenerator & json) const {
    HeaderOrMetadata::toJSON(json);
    json << "," << std::endl << json.indent << "\"size\" : " << this->size;
}
IR::HeaderStack::HeaderStack(JSONLoader & json) : HeaderOrMetadata(json) {
    json.load("size", size);
}
IR::Node * IR::HeaderStack::fromJSON(JSONLoader & json) { return new HeaderStack(json); }
IR::HeaderStack::HeaderStack(Util::SourceInfo srcInfo, IR::ID type_name, IR::ID name, const IR::Annotations* annotations, int size) :
    HeaderOrMetadata(srcInfo, type_name, name, annotations), size(size)
    { validate(); }
IR::HeaderStack::HeaderStack(IR::ID type_name, IR::ID name, const IR::Annotations* annotations, int size) :
    HeaderOrMetadata(type_name, name, annotations), size(size)
    { validate(); }
#line 105 "/home/fengyong/Desktop/p4c/ir/v1.def"
IR::Metadata::Metadata(IR::ID n, const IR::Type_StructLike* t) : HeaderOrMetadata(n, t) {}
#line 9482 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Metadata::operator==(IR::Metadata const & a) const {
        return HeaderOrMetadata::operator==(static_cast<const HeaderOrMetadata &>(a));
    }
bool IR::Metadata::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!HeaderOrMetadata::equiv(a_)) return false;
        return true;
    }
void IR::Metadata::toJSON(JSONGenerator & json) const {
    HeaderOrMetadata::toJSON(json);
}
IR::Metadata::Metadata(JSONLoader & json) : HeaderOrMetadata(json) {
}
IR::Node * IR::Metadata::fromJSON(JSONLoader & json) { return new Metadata(json); }
IR::Metadata::Metadata(Util::SourceInfo srcInfo, IR::ID type_name, IR::ID name, const IR::Annotations* annotations) :
    HeaderOrMetadata(srcInfo, type_name, name, annotations)
    { validate(); }
IR::Metadata::Metadata(IR::ID type_name, IR::ID name, const IR::Annotations* annotations) :
    HeaderOrMetadata(type_name, name, annotations)
    { validate(); }
bool IR::HeaderRef::operator==(IR::HeaderRef const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a));
    }
bool IR::HeaderRef::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        return true;
    }
void IR::HeaderRef::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
}
IR::HeaderRef::HeaderRef(JSONLoader & json) : Expression(json) {
}
IR::HeaderRef::HeaderRef(Util::SourceInfo srcInfo, const IR::Type* type) :
    Expression(srcInfo, type)
    { validate(); }
IR::HeaderRef::HeaderRef(const IR::Type* type) :
    Expression(type)
    { validate(); }
IR::HeaderRef::HeaderRef(Util::SourceInfo srcInfo) :
    Expression(srcInfo)
    { validate(); }
IR::HeaderRef::HeaderRef() 
    { validate(); }
#line 116 "/home/fengyong/Desktop/p4c/ir/v1.def"
const IR::HeaderOrMetadata *IR::ConcreteHeaderRef::baseRef() const { return ref; }
#line 9529 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 117 "/home/fengyong/Desktop/p4c/ir/v1.def"
cstring IR::ConcreteHeaderRef::toString() const { return ref->name; }
#line 9532 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 118 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::ConcreteHeaderRef::dbprint(std::ostream & out) const { out << ref->name; }
#line 9535 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::ConcreteHeaderRef::operator==(IR::ConcreteHeaderRef const & a) const {
        return HeaderRef::operator==(static_cast<const HeaderRef &>(a))
        && ref == a.ref;
    }
bool IR::ConcreteHeaderRef::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!HeaderRef::equiv(a_)) return false;
        auto &a = static_cast<const ConcreteHeaderRef &>(a_);
        return (ref ? a.ref ? ref->equiv(*a.ref) : false : a.ref == nullptr);
    }
void IR::ConcreteHeaderRef::visit_children(Visitor & v) {
    HeaderRef::visit_children(v);
    v.visit(ref, "ref");
}
void IR::ConcreteHeaderRef::visit_children(Visitor & v) const {
    HeaderRef::visit_children(v);
    v.visit(ref, "ref");
}
void IR::ConcreteHeaderRef::validate() const {
#line 9555 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(ref); }
void IR::ConcreteHeaderRef::toJSON(JSONGenerator & json) const {
    HeaderRef::toJSON(json);
    json << "," << std::endl << json.indent << "\"ref\" : " << this->ref;
}
IR::ConcreteHeaderRef::ConcreteHeaderRef(JSONLoader & json) : HeaderRef(json) {
    json.load("ref", ref);
}
IR::Node * IR::ConcreteHeaderRef::fromJSON(JSONLoader & json) { return new ConcreteHeaderRef(json); }
IR::ConcreteHeaderRef::ConcreteHeaderRef(Util::SourceInfo srcInfo, const IR::Type* type, const IR::HeaderOrMetadata* ref) :
    HeaderRef(srcInfo, type), ref(ref)
    {
#line 115 "/home/fengyong/Desktop/p4c/ir/v1.def"
{ if (type->is<Type::Unknown>() && ref) type = ref->type; }
#line 9571 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::ConcreteHeaderRef::ConcreteHeaderRef(const IR::Type* type, const IR::HeaderOrMetadata* ref) :
    HeaderRef(type), ref(ref)
    {
#line 115 "/home/fengyong/Desktop/p4c/ir/v1.def"
{ if (type->is<Type::Unknown>() && ref) type = ref->type; }
#line 9578 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::ConcreteHeaderRef::ConcreteHeaderRef(Util::SourceInfo srcInfo, const IR::HeaderOrMetadata* ref) :
    HeaderRef(srcInfo), ref(ref)
    {
#line 115 "/home/fengyong/Desktop/p4c/ir/v1.def"
{ if (type->is<Type::Unknown>() && ref) type = ref->type; }
#line 9585 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::ConcreteHeaderRef::ConcreteHeaderRef(const IR::HeaderOrMetadata* ref) :
    ref(ref)
    {
#line 115 "/home/fengyong/Desktop/p4c/ir/v1.def"
{ if (type->is<Type::Unknown>() && ref) type = ref->type; }
#line 9592 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
#line 128 "/home/fengyong/Desktop/p4c/ir/v1.def"
const IR::Expression *IR::HeaderStackItemRef::base() const { return base_; }
#line 9596 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
/// Returns `nullptr` if the base is not `HeaderOrMetadata` (e.g. when this
/// is stack ref of an expression such as `lookahead`).
#line 131 "/home/fengyong/Desktop/p4c/ir/v1.def"
const IR::HeaderOrMetadata *IR::HeaderStackItemRef::baseRef() const {
        auto hdrRef = base_->to<HeaderRef>();
        return hdrRef ? hdrRef->baseRef() : nullptr;
    }
#line 9604 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 135 "/home/fengyong/Desktop/p4c/ir/v1.def"
const IR::Expression *IR::HeaderStackItemRef::index() const { return index_; }
#line 9607 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 136 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::HeaderStackItemRef::set_base(const IR::Expression* b) { base_ = b; }
#line 9610 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 137 "/home/fengyong/Desktop/p4c/ir/v1.def"
cstring IR::HeaderStackItemRef::toString() const { return base_->toString() + "[" + index_->toString() + "]"; }
#line 9613 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::HeaderStackItemRef::operator==(IR::HeaderStackItemRef const & a) const {
        return HeaderRef::operator==(static_cast<const HeaderRef &>(a))
        && base_ == a.base_
        && index_ == a.index_;
    }
bool IR::HeaderStackItemRef::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!HeaderRef::equiv(a_)) return false;
        auto &a = static_cast<const HeaderStackItemRef &>(a_);
        return (base_ ? a.base_ ? base_->equiv(*a.base_) : false : a.base_ == nullptr)
        && (index_ ? a.index_ ? index_->equiv(*a.index_) : false : a.index_ == nullptr);
    }
void IR::HeaderStackItemRef::visit_children(Visitor & v) {
    HeaderRef::visit_children(v);
    v.visit(base_, "base_");
    v.visit(index_, "index_");
}
void IR::HeaderStackItemRef::visit_children(Visitor & v) const {
    HeaderRef::visit_children(v);
    v.visit(base_, "base_");
    v.visit(index_, "index_");
}
void IR::HeaderStackItemRef::validate() const {
#line 9637 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(base_);
        CHECK_NULL(index_); }
void IR::HeaderStackItemRef::toJSON(JSONGenerator & json) const {
    HeaderRef::toJSON(json);
    json << "," << std::endl << json.indent << "\"base_\" : " << this->base_;
    json << "," << std::endl << json.indent << "\"index_\" : " << this->index_;
}
IR::HeaderStackItemRef::HeaderStackItemRef(JSONLoader & json) : HeaderRef(json) {
    json.load("base_", base_);
    json.load("index_", index_);
}
IR::Node * IR::HeaderStackItemRef::fromJSON(JSONLoader & json) { return new HeaderStackItemRef(json); }
IR::HeaderStackItemRef::HeaderStackItemRef(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* base_, const IR::Expression* index_) :
    HeaderRef(srcInfo, type), base_(base_), index_(index_)
    {
#line 124 "/home/fengyong/Desktop/p4c/ir/v1.def"
{
        if (type->is<Type::Unknown>() && base_)
            if (auto *hr = base_->to<HeaderRef>())
                type = hr->baseRef()->type; }
#line 9659 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::HeaderStackItemRef::HeaderStackItemRef(const IR::Type* type, const IR::Expression* base_, const IR::Expression* index_) :
    HeaderRef(type), base_(base_), index_(index_)
    {
#line 124 "/home/fengyong/Desktop/p4c/ir/v1.def"
{
        if (type->is<Type::Unknown>() && base_)
            if (auto *hr = base_->to<HeaderRef>())
                type = hr->baseRef()->type; }
#line 9669 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::HeaderStackItemRef::HeaderStackItemRef(Util::SourceInfo srcInfo, const IR::Expression* base_, const IR::Expression* index_) :
    HeaderRef(srcInfo), base_(base_), index_(index_)
    {
#line 124 "/home/fengyong/Desktop/p4c/ir/v1.def"
{
        if (type->is<Type::Unknown>() && base_)
            if (auto *hr = base_->to<HeaderRef>())
                type = hr->baseRef()->type; }
#line 9679 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::HeaderStackItemRef::HeaderStackItemRef(const IR::Expression* base_, const IR::Expression* index_) :
    base_(base_), index_(index_)
    {
#line 124 "/home/fengyong/Desktop/p4c/ir/v1.def"
{
        if (type->is<Type::Unknown>() && base_)
            if (auto *hr = base_->to<HeaderRef>())
                type = hr->baseRef()->type; }
#line 9689 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
#line 144 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::If::visit_children(Visitor & v) {
        v.visit(pred, "pred");
        SplitFlowVisit<Vector<Expression>>(v, ifTrue, ifFalse).run_visit();
        Expression::visit_children(v);
    }
#line 144 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::If::visit_children(Visitor & v) const {
        v.visit(pred, "pred");
        SplitFlowVisit<Vector<Expression>>(v, ifTrue, ifFalse).run_visit();
        Expression::visit_children(v);
    }
#line 9703 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::If::operator==(IR::If const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && pred == a.pred
        && ifTrue == a.ifTrue
        && ifFalse == a.ifFalse;
    }
bool IR::If::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const If &>(a_);
        return (pred ? a.pred ? pred->equiv(*a.pred) : false : a.pred == nullptr)
        && (ifTrue ? a.ifTrue ? ifTrue->equiv(*a.ifTrue) : false : a.ifTrue == nullptr)
        && (ifFalse ? a.ifFalse ? ifFalse->equiv(*a.ifFalse) : false : a.ifFalse == nullptr);
    }
void IR::If::validate() const {
#line 9719 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(pred); }
void IR::If::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"pred\" : " << this->pred;
    if (ifTrue != nullptr)     json << "," << std::endl << json.indent << "\"ifTrue\" : " << this->ifTrue;
    if (ifFalse != nullptr)     json << "," << std::endl << json.indent << "\"ifFalse\" : " << this->ifFalse;
}
IR::If::If(JSONLoader & json) : Expression(json) {
    json.load("pred", pred);
    json.load("ifTrue", ifTrue);
    json.load("ifFalse", ifFalse);
}
IR::Node * IR::If::fromJSON(JSONLoader & json) { return new If(json); }
IR::If::If(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* pred, const IR::Vector<IR::Expression>* ifTrue, const IR::Vector<IR::Expression>* ifFalse) :
    Expression(srcInfo, type), pred(pred), ifTrue(ifTrue), ifFalse(ifFalse)
    { validate(); }
IR::If::If(const IR::Type* type, const IR::Expression* pred, const IR::Vector<IR::Expression>* ifTrue, const IR::Vector<IR::Expression>* ifFalse) :
    Expression(type), pred(pred), ifTrue(ifTrue), ifFalse(ifFalse)
    { validate(); }
IR::If::If(Util::SourceInfo srcInfo, const IR::Expression* pred, const IR::Vector<IR::Expression>* ifTrue, const IR::Vector<IR::Expression>* ifFalse) :
    Expression(srcInfo), pred(pred), ifTrue(ifTrue), ifFalse(ifFalse)
    { validate(); }
IR::If::If(const IR::Expression* pred, const IR::Vector<IR::Expression>* ifTrue, const IR::Vector<IR::Expression>* ifFalse) :
    pred(pred), ifTrue(ifTrue), ifFalse(ifFalse)
    { validate(); }
#line 156 "/home/fengyong/Desktop/p4c/ir/v1.def"
IR::NamedCond::NamedCond(IR::If const & i) : If(i), name(unique_name()) {}
#line 9748 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 157 "/home/fengyong/Desktop/p4c/ir/v1.def"
bool IR::NamedCond::operator==(IR::NamedCond const & a) const { return If::operator==(static_cast<const If &>(a)); }
#line 9751 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::NamedCond::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!If::equiv(a_)) return false;
        auto &a = static_cast<const NamedCond &>(a_);
        return name == a.name;
    }
void IR::NamedCond::dump_fields(std::ostream & out) const {
    If::dump_fields(out);
        out << " name=" << name;
}
void IR::NamedCond::toJSON(JSONGenerator & json) const {
    If::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
}
IR::NamedCond::NamedCond(JSONLoader & json) : If(json) {
    json.load("name", name);
}
IR::Node * IR::NamedCond::fromJSON(JSONLoader & json) { return new NamedCond(json); }


bool IR::Apply::operator==(IR::Apply const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && name == a.name
        && actions == a.actions
        && position == a.position;
    }
bool IR::Apply::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const Apply &>(a_);
        return name == a.name
        && actions.equiv(a.actions)
        && position.equiv(a.position);
    }
void IR::Apply::visit_children(Visitor & v) {
    Expression::visit_children(v);
    actions.visit_children(v);
    position.visit_children(v);
}
void IR::Apply::visit_children(Visitor & v) const {
    Expression::visit_children(v);
    actions.visit_children(v);
    position.visit_children(v);
}
void IR::Apply::validate() const {
#line 9797 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        actions.validate();
        position.validate(); }
void IR::Apply::dump_fields(std::ostream & out) const {
    Expression::dump_fields(out);
        out << " name=" << name;
}
void IR::Apply::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"actions\" : " << this->actions;
    json << "," << std::endl << json.indent << "\"position\" : " << this->position;
}
IR::Apply::Apply(JSONLoader & json) : Expression(json) {
    json.load("name", name);
    json.load("actions", actions);
    json.load("position", position);
}
IR::Node * IR::Apply::fromJSON(JSONLoader & json) { return new Apply(json); }
IR::Apply::Apply(Util::SourceInfo srcInfo, const IR::Type* type, IR::ID name) :
    Expression(srcInfo, type), name(name)
    { validate(); }
IR::Apply::Apply(const IR::Type* type, IR::ID name) :
    Expression(type), name(name)
    { validate(); }
IR::Apply::Apply(Util::SourceInfo srcInfo, IR::ID name) :
    Expression(srcInfo), name(name)
    { validate(); }
IR::Apply::Apply(IR::ID name) :
    name(name)
    { validate(); }
IR::Apply::Apply(Util::SourceInfo srcInfo, const IR::Type* type) :
    Expression(srcInfo, type)
    { validate(); }
IR::Apply::Apply(const IR::Type* type) :
    Expression(type)
    { validate(); }
IR::Apply::Apply(Util::SourceInfo srcInfo) :
    Expression(srcInfo)
    { validate(); }
IR::Apply::Apply() 
    { validate(); }
#line 174 "/home/fengyong/Desktop/p4c/ir/v1.def"
IR::Primitive::Primitive(cstring n, const IR::Vector<IR::Expression>* l) : name(n) {
        if (l) for (auto e : *l) operands.push_back(e); }
#line 9843 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 176 "/home/fengyong/Desktop/p4c/ir/v1.def"
IR::Primitive::Primitive(Util::SourceInfo si, cstring n, const IR::Vector<IR::Expression>* l) : Operation(si), name(n) {
        if (l) for (auto e : *l) operands.push_back(e); }
#line 9847 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 178 "/home/fengyong/Desktop/p4c/ir/v1.def"
IR::Primitive::Primitive(cstring n, const IR::Expression* a1) : name(n) {
        operands.push_back(a1); }
#line 9851 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 180 "/home/fengyong/Desktop/p4c/ir/v1.def"
IR::Primitive::Primitive(Util::SourceInfo si, cstring n, const IR::Expression* a1) : Operation(si), name(n) {
        operands.push_back(a1); }
#line 9855 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 182 "/home/fengyong/Desktop/p4c/ir/v1.def"
IR::Primitive::Primitive(cstring n, const IR::Expression* a1, const IR::Expression* a2) : name(n) {
        operands.push_back(a1); operands.push_back(a2); }
#line 9859 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 184 "/home/fengyong/Desktop/p4c/ir/v1.def"
IR::Primitive::Primitive(Util::SourceInfo si, cstring n, const IR::Expression* a1, const IR::Expression* a2) : Operation(si), name(n) {
        operands.push_back(a1); operands.push_back(a2); }
#line 9863 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 187 "/home/fengyong/Desktop/p4c/ir/v1.def"
IR::Primitive::Primitive(cstring n, const IR::Expression* a1, const IR::Vector<IR::Expression>* a2) : name(n) {
        operands.push_back(a1);
        if (a2) for (auto e : *a2) operands.push_back(e); }
#line 9868 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 190 "/home/fengyong/Desktop/p4c/ir/v1.def"
IR::Primitive::Primitive(Util::SourceInfo si, cstring n, const IR::Expression* a1, const IR::Vector<IR::Expression>* a2) : Operation(si), name(n) {
        operands.push_back(a1);
        if (a2) for (auto e : *a2) operands.push_back(e); }
#line 9873 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 194 "/home/fengyong/Desktop/p4c/ir/v1.def"
IR::Primitive::Primitive(cstring n, const IR::Expression* a1, const IR::Expression* a2, const IR::Expression* a3) : name(n) {
        operands.push_back(a1); operands.push_back(a2); operands.push_back(a3); }
#line 9877 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 196 "/home/fengyong/Desktop/p4c/ir/v1.def"
IR::Primitive::Primitive(Util::SourceInfo si, cstring n, const IR::Expression* a1, const IR::Expression* a2, const IR::Expression* a3) : Operation(si), name(n) {
        operands.push_back(a1); operands.push_back(a2); operands.push_back(a3); }
#line 9881 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
IRNODE_DEFINE_APPLY_OVERLOAD(Primitive, , )
bool IR::Primitive::operator==(IR::Primitive const & a) const {
        return Operation::operator==(static_cast<const Operation &>(a))
        && name == a.name
        && operands == a.operands;
    }
bool IR::Primitive::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation::equiv(a_)) return false;
        auto &a = static_cast<const Primitive &>(a_);
        return name == a.name
        && operands.equiv(a.operands);
    }
void IR::Primitive::visit_children(Visitor & v) {
    Operation::visit_children(v);
    operands.visit_children(v);
}
void IR::Primitive::visit_children(Visitor & v) const {
    Operation::visit_children(v);
    operands.visit_children(v);
}
void IR::Primitive::validate() const {
#line 9904 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        operands.validate(); }
void IR::Primitive::dump_fields(std::ostream & out) const {
    Operation::dump_fields(out);
        out << " name=" << name;
}
void IR::Primitive::toJSON(JSONGenerator & json) const {
    Operation::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"operands\" : " << this->operands;
}
IR::Primitive::Primitive(JSONLoader & json) : Operation(json) {
    json.load("name", name);
    json.load("operands", operands);
}
IR::Node * IR::Primitive::fromJSON(JSONLoader & json) { return new Primitive(json); }
IR::Primitive::Primitive(Util::SourceInfo srcInfo, const IR::Type* type, cstring name) :
    Operation(srcInfo, type), name(name)
    { validate(); }
IR::Primitive::Primitive(const IR::Type* type, cstring name) :
    Operation(type), name(name)
    { validate(); }
IR::Primitive::Primitive(Util::SourceInfo srcInfo, cstring name) :
    Operation(srcInfo), name(name)
    { validate(); }
IR::Primitive::Primitive(cstring name) :
    name(name)
    { validate(); }
#line 213 "/home/fengyong/Desktop/p4c/ir/v1.def"
const IR::Annotations *IR::FieldList::getAnnotations() const { return annotations; }
#line 9935 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::FieldList::operator==(IR::FieldList const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && payload == a.payload
        && annotations == a.annotations
        && fields == a.fields;
    }
bool IR::FieldList::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const FieldList &>(a_);
        return name == a.name
        && payload == a.payload
        && (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && fields.equiv(a.fields);
    }
void IR::FieldList::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
    fields.visit_children(v);
}
void IR::FieldList::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
    fields.visit_children(v);
}
void IR::FieldList::validate() const {
#line 9963 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        fields.validate(); }
void IR::FieldList::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
        out << " payload=" << payload;
}
void IR::FieldList::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"payload\" : " << this->payload;
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"fields\" : " << this->fields;
}
IR::FieldList::FieldList(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("payload", payload);
    json.load("annotations", annotations);
    json.load("fields", fields);
}
IR::Node * IR::FieldList::fromJSON(JSONLoader & json) { return new FieldList(json); }
IR::FieldList::FieldList(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Node(srcInfo), name(name), annotations(annotations)
    { validate(); }
IR::FieldList::FieldList(IR::ID name, const IR::Annotations* annotations) :
    name(name), annotations(annotations)
    { validate(); }
IR::FieldList::FieldList(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    Node(srcInfo), annotations(annotations)
    { validate(); }
IR::FieldList::FieldList(const IR::Annotations* annotations) :
    annotations(annotations)
    { validate(); }
IR::FieldList::FieldList(Util::SourceInfo srcInfo, IR::ID name) :
    Node(srcInfo), name(name)
    { validate(); }
IR::FieldList::FieldList(IR::ID name) :
    name(name)
    { validate(); }
IR::FieldList::FieldList(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::FieldList::FieldList() 
    { validate(); }
#line 223 "/home/fengyong/Desktop/p4c/ir/v1.def"
const IR::Annotations *IR::FieldListCalculation::getAnnotations() const { return annotations; }
#line 10011 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::FieldListCalculation::operator==(IR::FieldListCalculation const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && input == a.input
        && input_fields == a.input_fields
        && algorithm == a.algorithm
        && output_width == a.output_width
        && annotations == a.annotations;
    }
bool IR::FieldListCalculation::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const FieldListCalculation &>(a_);
        return name == a.name
        && (input ? a.input ? input->equiv(*a.input) : false : a.input == nullptr)
        && (input_fields ? a.input_fields ? input_fields->equiv(*a.input_fields) : false : a.input_fields == nullptr)
        && (algorithm ? a.algorithm ? algorithm->equiv(*a.algorithm) : false : a.algorithm == nullptr)
        && output_width == a.output_width
        && (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr);
    }
void IR::FieldListCalculation::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(input, "input");
    v.visit(input_fields, "input_fields");
    v.visit(algorithm, "algorithm");
    v.visit(annotations, "annotations");
}
void IR::FieldListCalculation::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(input, "input");
    v.visit(input_fields, "input_fields");
    v.visit(algorithm, "algorithm");
    v.visit(annotations, "annotations");
}
void IR::FieldListCalculation::validate() const {
#line 10047 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations); }
void IR::FieldListCalculation::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
        out << " output_width=" << output_width;
}
void IR::FieldListCalculation::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    if (input != nullptr)     json << "," << std::endl << json.indent << "\"input\" : " << this->input;
    if (input_fields != nullptr)     json << "," << std::endl << json.indent << "\"input_fields\" : " << this->input_fields;
    if (algorithm != nullptr)     json << "," << std::endl << json.indent << "\"algorithm\" : " << this->algorithm;
    json << "," << std::endl << json.indent << "\"output_width\" : " << this->output_width;
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
}
IR::FieldListCalculation::FieldListCalculation(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("input", input);
    json.load("input_fields", input_fields);
    json.load("algorithm", algorithm);
    json.load("output_width", output_width);
    json.load("annotations", annotations);
}
IR::Node * IR::FieldListCalculation::fromJSON(JSONLoader & json) { return new FieldListCalculation(json); }
IR::FieldListCalculation::FieldListCalculation(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Node(srcInfo), name(name), annotations(annotations)
    { validate(); }
IR::FieldListCalculation::FieldListCalculation(IR::ID name, const IR::Annotations* annotations) :
    name(name), annotations(annotations)
    { validate(); }
IR::FieldListCalculation::FieldListCalculation(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    Node(srcInfo), annotations(annotations)
    { validate(); }
IR::FieldListCalculation::FieldListCalculation(const IR::Annotations* annotations) :
    annotations(annotations)
    { validate(); }
IR::FieldListCalculation::FieldListCalculation(Util::SourceInfo srcInfo, IR::ID name) :
    Node(srcInfo), name(name)
    { validate(); }
IR::FieldListCalculation::FieldListCalculation(IR::ID name) :
    name(name)
    { validate(); }
IR::FieldListCalculation::FieldListCalculation(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::FieldListCalculation::FieldListCalculation() 
    { validate(); }
#line 233 "/home/fengyong/Desktop/p4c/ir/v1.def"
IR::CalculatedField::update_or_verify::update_or_verify() { }
#line 10098 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

bool IR::CalculatedField::update_or_verify::operator==(IR::CalculatedField::update_or_verify const & a) const {
        return update == a.update
        && name == a.name
        && cond == a.cond;
    }
void IR::CalculatedField::update_or_verify::toJSON(JSONGenerator & json) const {
    json << "," << std::endl << json.indent << "\"update\" : " << this->update;
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"cond\" : " << this->cond;
}
IR::CalculatedField::update_or_verify::update_or_verify(JSONLoader & json)  {
    json.load("update", update);
    json.load("name", name);
    json.load("cond", cond);
}
IR::CalculatedField::update_or_verify * IR::CalculatedField::update_or_verify::fromJSON(JSONLoader & json) { return new update_or_verify(json); }
IR::CalculatedField::update_or_verify::update_or_verify(Util::SourceInfo srcInfo, bool update, IR::ID name, const IR::Expression* cond) :
    srcInfo(srcInfo), update(update), name(name), cond(cond)
    {}
IR::CalculatedField::update_or_verify::update_or_verify(Util::SourceInfo srcInfo, IR::ID name, const IR::Expression* cond) :
    srcInfo(srcInfo), name(name), cond(cond)
    {}
#line 237 "/home/fengyong/Desktop/p4c/ir/v1.def"
const IR::Annotations *IR::CalculatedField::getAnnotations() const { return annotations; }
#line 10124 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 238 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::CalculatedField::visit_children(Visitor & v) {
        v.visit(field, "field");
        for (auto &s : specs) v.visit(s.cond, s.name.name);
        v.visit(annotations, "annotations"); }
#line 238 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::CalculatedField::visit_children(Visitor & v) const {
        v.visit(field, "field");
        for (auto &s : specs) v.visit(s.cond, s.name.name);
        v.visit(annotations, "annotations"); }
#line 10135 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::CalculatedField::operator==(IR::CalculatedField const & a) const {
        return typeid(*this) == typeid(a)
        && field == a.field
        && specs == a.specs
        && annotations == a.annotations;
    }
bool IR::CalculatedField::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const CalculatedField &>(a_);
        return (field ? a.field ? field->equiv(*a.field) : false : a.field == nullptr)
        && specs == a.specs
        && (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr);
    }
void IR::CalculatedField::validate() const {
#line 10151 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations); }
void IR::CalculatedField::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    if (field != nullptr)     json << "," << std::endl << json.indent << "\"field\" : " << this->field;
    json << "," << std::endl << json.indent << "\"specs\" : " << this->specs;
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
}
IR::CalculatedField::CalculatedField(JSONLoader & json) : Node(json) {
    json.load("field", field);
    json.load("specs", specs);
    json.load("annotations", annotations);
}
IR::Node * IR::CalculatedField::fromJSON(JSONLoader & json) { return new CalculatedField(json); }
IR::CalculatedField::CalculatedField(Util::SourceInfo srcInfo, const IR::Expression* field, const IR::Annotations* annotations) :
    Node(srcInfo), field(field), annotations(annotations)
    { validate(); }
IR::CalculatedField::CalculatedField(const IR::Expression* field, const IR::Annotations* annotations) :
    field(field), annotations(annotations)
    { validate(); }
IR::CalculatedField::CalculatedField(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    Node(srcInfo), annotations(annotations)
    { validate(); }
IR::CalculatedField::CalculatedField(const IR::Annotations* annotations) :
    annotations(annotations)
    { validate(); }
#line 247 "/home/fengyong/Desktop/p4c/ir/v1.def"
const IR::Annotations *IR::ParserValueSet::getAnnotations() const { return annotations; }
#line 10180 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 248 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::ParserValueSet::dbprint(std::ostream & out) const { out << node_type_name() << " " << name; }
#line 10183 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 249 "/home/fengyong/Desktop/p4c/ir/v1.def"
cstring IR::ParserValueSet::toString() const { return node_type_name() + " " + name; }
#line 10186 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::ParserValueSet::operator==(IR::ParserValueSet const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && annotations == a.annotations;
    }
bool IR::ParserValueSet::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const ParserValueSet &>(a_);
        return name == a.name
        && (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr);
    }
void IR::ParserValueSet::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
}
void IR::ParserValueSet::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
}
void IR::ParserValueSet::validate() const {
#line 10208 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations); }
void IR::ParserValueSet::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
}
void IR::ParserValueSet::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
}
IR::ParserValueSet::ParserValueSet(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("annotations", annotations);
}
IR::Node * IR::ParserValueSet::fromJSON(JSONLoader & json) { return new ParserValueSet(json); }
IR::ParserValueSet::ParserValueSet(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Node(srcInfo), name(name), annotations(annotations)
    { validate(); }
IR::ParserValueSet::ParserValueSet(IR::ID name, const IR::Annotations* annotations) :
    name(name), annotations(annotations)
    { validate(); }
IR::ParserValueSet::ParserValueSet(Util::SourceInfo srcInfo, IR::ID name) :
    Node(srcInfo), name(name)
    { validate(); }
IR::ParserValueSet::ParserValueSet(IR::ID name) :
    name(name)
    { validate(); }
bool IR::CaseEntry::operator==(IR::CaseEntry const & a) const {
        return typeid(*this) == typeid(a)
        && values == a.values
        && action == a.action;
    }
bool IR::CaseEntry::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const CaseEntry &>(a_);
        return values == a.values
        && action == a.action;
    }
void IR::CaseEntry::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " action=" << action;
}
void IR::CaseEntry::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"values\" : " << this->values;
    json << "," << std::endl << json.indent << "\"action\" : " << this->action;
}
IR::CaseEntry::CaseEntry(JSONLoader & json) : Node(json) {
    json.load("values", values);
    json.load("action", action);
}
IR::Node * IR::CaseEntry::fromJSON(JSONLoader & json) { return new CaseEntry(json); }
IR::CaseEntry::CaseEntry(Util::SourceInfo srcInfo, IR::ID action) :
    Node(srcInfo), action(action)
    { validate(); }
IR::CaseEntry::CaseEntry(IR::ID action) :
    action(action)
    { validate(); }
IR::CaseEntry::CaseEntry(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::CaseEntry::CaseEntry() 
    { validate(); }
#line 266 "/home/fengyong/Desktop/p4c/ir/v1.def"
const IR::Annotations *IR::V1Parser::getAnnotations() const { return annotations; }
#line 10276 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 267 "/home/fengyong/Desktop/p4c/ir/v1.def"
cstring IR::V1Parser::toString() const { return node_type_name() + " " + name; }
#line 10279 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::V1Parser::operator==(IR::V1Parser const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && stmts == a.stmts
        && select == a.select
        && cases == a.cases
        && default_return == a.default_return
        && parse_error == a.parse_error
        && drop == a.drop
        && annotations == a.annotations;
    }
bool IR::V1Parser::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const V1Parser &>(a_);
        return name == a.name
        && stmts.equiv(a.stmts)
        && (select ? a.select ? select->equiv(*a.select) : false : a.select == nullptr)
        && (cases ? a.cases ? cases->equiv(*a.cases) : false : a.cases == nullptr)
        && default_return == a.default_return
        && parse_error == a.parse_error
        && drop == a.drop
        && (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr);
    }
void IR::V1Parser::visit_children(Visitor & v) {
    Node::visit_children(v);
    stmts.visit_children(v);
    v.visit(select, "select");
    v.visit(cases, "cases");
    v.visit(annotations, "annotations");
}
void IR::V1Parser::visit_children(Visitor & v) const {
    Node::visit_children(v);
    stmts.visit_children(v);
    v.visit(select, "select");
    v.visit(cases, "cases");
    v.visit(annotations, "annotations");
}
void IR::V1Parser::validate() const {
#line 10319 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        stmts.validate();
        CHECK_NULL(annotations); }
void IR::V1Parser::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
        out << " default_return=" << default_return;
        out << " parse_error=" << parse_error;
        out << " drop=" << drop;
}
void IR::V1Parser::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"stmts\" : " << this->stmts;
    if (select != nullptr)     json << "," << std::endl << json.indent << "\"select\" : " << this->select;
    if (cases != nullptr)     json << "," << std::endl << json.indent << "\"cases\" : " << this->cases;
    json << "," << std::endl << json.indent << "\"default_return\" : " << this->default_return;
    json << "," << std::endl << json.indent << "\"parse_error\" : " << this->parse_error;
    json << "," << std::endl << json.indent << "\"drop\" : " << this->drop;
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
}
IR::V1Parser::V1Parser(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("stmts", stmts);
    json.load("select", select);
    json.load("cases", cases);
    json.load("default_return", default_return);
    json.load("parse_error", parse_error);
    json.load("drop", drop);
    json.load("annotations", annotations);
}
IR::Node * IR::V1Parser::fromJSON(JSONLoader & json) { return new V1Parser(json); }
IR::V1Parser::V1Parser(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Node(srcInfo), name(name), annotations(annotations)
    { validate(); }
IR::V1Parser::V1Parser(IR::ID name, const IR::Annotations* annotations) :
    name(name), annotations(annotations)
    { validate(); }
IR::V1Parser::V1Parser(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    Node(srcInfo), annotations(annotations)
    { validate(); }
IR::V1Parser::V1Parser(const IR::Annotations* annotations) :
    annotations(annotations)
    { validate(); }
bool IR::ParserException::operator==(IR::ParserException const & a) const {
        return typeid(*this) == typeid(a);
    }
bool IR::ParserException::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        return true;
    }
void IR::ParserException::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
}
IR::ParserException::ParserException(JSONLoader & json) : Node(json) {
}
IR::Node * IR::ParserException::fromJSON(JSONLoader & json) { return new ParserException(json); }
IR::ParserException::ParserException(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::ParserException::ParserException() 
    { validate(); }
#line 275 "/home/fengyong/Desktop/p4c/ir/v1.def"
IR::ID IR::Attached::Name() const { return name; }
#line 10385 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 277 "/home/fengyong/Desktop/p4c/ir/v1.def"
const IR::Type *IR::Attached::getType() const { return Type_Unknown::get(); }
#line 10388 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 278 "/home/fengyong/Desktop/p4c/ir/v1.def"
const IR::Annotations *IR::Attached::getAnnotations() const { return annotations; }
#line 10391 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 279 "/home/fengyong/Desktop/p4c/ir/v1.def"
bool IR::Attached::indexed() const { return false; }
#line 10394 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 280 "/home/fengyong/Desktop/p4c/ir/v1.def"
IR::Attached * IR::Attached::clone_rename(char const * ext) const {
        Attached *rv = clone();
        rv->name = ID(Util::SourceInfo(), rv->name.name + ext);
        return rv; }
#line 10400 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 284 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::Attached::dbprint(std::ostream & out) const { out << node_type_name() << " " << name; }
#line 10403 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 285 "/home/fengyong/Desktop/p4c/ir/v1.def"
cstring IR::Attached::toString() const { return node_type_name() + " " + name; }
#line 10406 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Attached::operator==(IR::Attached const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && annotations == a.annotations;
    }
bool IR::Attached::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const Attached &>(a_);
        return name == a.name
        && (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr);
    }
void IR::Attached::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
}
void IR::Attached::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
}
void IR::Attached::validate() const {
#line 10428 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations); }
void IR::Attached::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
}
void IR::Attached::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
}
IR::Attached::Attached(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("annotations", annotations);
}
IR::Attached::Attached(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Node(srcInfo), name(name), annotations(annotations)
    { validate(); }
IR::Attached::Attached(IR::ID name, const IR::Annotations* annotations) :
    name(name), annotations(annotations)
    { validate(); }
IR::Attached::Attached(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    Node(srcInfo), annotations(annotations)
    { validate(); }
IR::Attached::Attached(const IR::Annotations* annotations) :
    annotations(annotations)
    { validate(); }
IR::Attached::Attached(Util::SourceInfo srcInfo, IR::ID name) :
    Node(srcInfo), name(name)
    { validate(); }
IR::Attached::Attached(IR::ID name) :
    name(name)
    { validate(); }
IR::Attached::Attached(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::Attached::Attached() 
    { validate(); }
#line 293 "/home/fengyong/Desktop/p4c/ir/v1.def"
bool IR::Stateful::indexed() const { return !direct; }
#line 10469 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

bool IR::Stateful::operator==(IR::Stateful const & a) const {
        return Attached::operator==(static_cast<const Attached &>(a))
        && table == a.table
        && direct == a.direct
        && saturating == a.saturating
        && instance_count == a.instance_count;
    }
bool IR::Stateful::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Attached::equiv(a_)) return false;
        auto &a = static_cast<const Stateful &>(a_);
        return table == a.table
        && direct == a.direct
        && saturating == a.saturating
        && instance_count == a.instance_count;
    }
void IR::Stateful::dump_fields(std::ostream & out) const {
    Attached::dump_fields(out);
        out << " table=" << table;
        out << " direct=" << direct;
        out << " saturating=" << saturating;
        out << " instance_count=" << instance_count;
}
void IR::Stateful::toJSON(JSONGenerator & json) const {
    Attached::toJSON(json);
    json << "," << std::endl << json.indent << "\"table\" : " << this->table;
    json << "," << std::endl << json.indent << "\"direct\" : " << this->direct;
    json << "," << std::endl << json.indent << "\"saturating\" : " << this->saturating;
    json << "," << std::endl << json.indent << "\"instance_count\" : " << this->instance_count;
}
IR::Stateful::Stateful(JSONLoader & json) : Attached(json) {
    json.load("table", table);
    json.load("direct", direct);
    json.load("saturating", saturating);
    json.load("instance_count", instance_count);
}
IR::Stateful::Stateful(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Attached(srcInfo, name, annotations)
    { validate(); }
IR::Stateful::Stateful(IR::ID name, const IR::Annotations* annotations) :
    Attached(name, annotations)
    { validate(); }
IR::Stateful::Stateful(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    Attached(srcInfo, annotations)
    { validate(); }
IR::Stateful::Stateful(const IR::Annotations* annotations) :
    Attached(annotations)
    { validate(); }
IR::Stateful::Stateful(Util::SourceInfo srcInfo, IR::ID name) :
    Attached(srcInfo, name)
    { validate(); }
IR::Stateful::Stateful(IR::ID name) :
    Attached(name)
    { validate(); }
IR::Stateful::Stateful(Util::SourceInfo srcInfo) :
    Attached(srcInfo)
    { validate(); }
IR::Stateful::Stateful() 
    { validate(); }
#line 299 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::CounterOrMeter::settype(cstring t) {
        if (strcasecmp(t.c_str(), "packets") == 0) type = CounterType::PACKETS;
        else if (strcasecmp(t.c_str(), "bytes") == 0) type = CounterType::BYTES;
        else if (strcasecmp(t.c_str(), "packets_and_bytes") == 0 ||
                 strcasecmp(t.c_str(), "PacketAndBytes") == 0) type = CounterType::BOTH;
        else error(ErrorType::ERR_UNKNOWN, "%s: Unknown type %s", srcInfo, t); }
#line 10537 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

bool IR::CounterOrMeter::operator==(IR::CounterOrMeter const & a) const {
        return Stateful::operator==(static_cast<const Stateful &>(a))
        && type == a.type;
    }
bool IR::CounterOrMeter::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Stateful::equiv(a_)) return false;
        auto &a = static_cast<const CounterOrMeter &>(a_);
        return type == a.type;
    }
void IR::CounterOrMeter::dump_fields(std::ostream & out) const {
    Stateful::dump_fields(out);
        out << " type=" << type;
}
void IR::CounterOrMeter::toJSON(JSONGenerator & json) const {
    Stateful::toJSON(json);
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
}
IR::CounterOrMeter::CounterOrMeter(JSONLoader & json) : Stateful(json) {
    json.load("type", type);
}
IR::CounterOrMeter::CounterOrMeter(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Stateful(srcInfo, name, annotations)
    { validate(); }
IR::CounterOrMeter::CounterOrMeter(IR::ID name, const IR::Annotations* annotations) :
    Stateful(name, annotations)
    { validate(); }
IR::CounterOrMeter::CounterOrMeter(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    Stateful(srcInfo, annotations)
    { validate(); }
IR::CounterOrMeter::CounterOrMeter(const IR::Annotations* annotations) :
    Stateful(annotations)
    { validate(); }
IR::CounterOrMeter::CounterOrMeter(Util::SourceInfo srcInfo, IR::ID name) :
    Stateful(srcInfo, name)
    { validate(); }
IR::CounterOrMeter::CounterOrMeter(IR::ID name) :
    Stateful(name)
    { validate(); }
IR::CounterOrMeter::CounterOrMeter(Util::SourceInfo srcInfo) :
    Stateful(srcInfo)
    { validate(); }
IR::CounterOrMeter::CounterOrMeter() 
    { validate(); }
#line 310 "/home/fengyong/Desktop/p4c/ir/v1.def"
char const * IR::Counter::kind() const { return "stats"; }
#line 10585 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 311 "/home/fengyong/Desktop/p4c/ir/v1.def"
IR::Type const * IR::Counter::getType() const { return Type_Counter::get(); }
#line 10588 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Counter::operator==(IR::Counter const & a) const {
        return CounterOrMeter::operator==(static_cast<const CounterOrMeter &>(a))
        && max_width == a.max_width
        && min_width == a.min_width;
    }
bool IR::Counter::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!CounterOrMeter::equiv(a_)) return false;
        auto &a = static_cast<const Counter &>(a_);
        return max_width == a.max_width
        && min_width == a.min_width;
    }
void IR::Counter::dump_fields(std::ostream & out) const {
    CounterOrMeter::dump_fields(out);
        out << " max_width=" << max_width;
        out << " min_width=" << min_width;
}
void IR::Counter::toJSON(JSONGenerator & json) const {
    CounterOrMeter::toJSON(json);
    json << "," << std::endl << json.indent << "\"max_width\" : " << this->max_width;
    json << "," << std::endl << json.indent << "\"min_width\" : " << this->min_width;
}
IR::Counter::Counter(JSONLoader & json) : CounterOrMeter(json) {
    json.load("max_width", max_width);
    json.load("min_width", min_width);
}
IR::Node * IR::Counter::fromJSON(JSONLoader & json) { return new Counter(json); }
IR::Counter::Counter(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    CounterOrMeter(srcInfo, name, annotations)
    { validate(); }
IR::Counter::Counter(IR::ID name, const IR::Annotations* annotations) :
    CounterOrMeter(name, annotations)
    { validate(); }
IR::Counter::Counter(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    CounterOrMeter(srcInfo, annotations)
    { validate(); }
IR::Counter::Counter(const IR::Annotations* annotations) :
    CounterOrMeter(annotations)
    { validate(); }
IR::Counter::Counter(Util::SourceInfo srcInfo, IR::ID name) :
    CounterOrMeter(srcInfo, name)
    { validate(); }
IR::Counter::Counter(IR::ID name) :
    CounterOrMeter(name)
    { validate(); }
IR::Counter::Counter(Util::SourceInfo srcInfo) :
    CounterOrMeter(srcInfo)
    { validate(); }
IR::Counter::Counter() 
    { validate(); }
#line 318 "/home/fengyong/Desktop/p4c/ir/v1.def"
char const * IR::Meter::kind() const { return "meter"; }
#line 10641 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 319 "/home/fengyong/Desktop/p4c/ir/v1.def"
const IR::Type *IR::Meter::getType() const { return Type_Meter::get(); }
#line 10644 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Meter::operator==(IR::Meter const & a) const {
        return CounterOrMeter::operator==(static_cast<const CounterOrMeter &>(a))
        && result == a.result
        && pre_color == a.pre_color
        && implementation == a.implementation;
    }
bool IR::Meter::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!CounterOrMeter::equiv(a_)) return false;
        auto &a = static_cast<const Meter &>(a_);
        return (result ? a.result ? result->equiv(*a.result) : false : a.result == nullptr)
        && (pre_color ? a.pre_color ? pre_color->equiv(*a.pre_color) : false : a.pre_color == nullptr)
        && implementation == a.implementation;
    }
void IR::Meter::visit_children(Visitor & v) {
    CounterOrMeter::visit_children(v);
    v.visit(result, "result");
    v.visit(pre_color, "pre_color");
}
void IR::Meter::visit_children(Visitor & v) const {
    CounterOrMeter::visit_children(v);
    v.visit(result, "result");
    v.visit(pre_color, "pre_color");
}
void IR::Meter::dump_fields(std::ostream & out) const {
    CounterOrMeter::dump_fields(out);
        out << " implementation=" << implementation;
}
void IR::Meter::toJSON(JSONGenerator & json) const {
    CounterOrMeter::toJSON(json);
    if (result != nullptr)     json << "," << std::endl << json.indent << "\"result\" : " << this->result;
    if (pre_color != nullptr)     json << "," << std::endl << json.indent << "\"pre_color\" : " << this->pre_color;
    json << "," << std::endl << json.indent << "\"implementation\" : " << this->implementation;
}
IR::Meter::Meter(JSONLoader & json) : CounterOrMeter(json) {
    json.load("result", result);
    json.load("pre_color", pre_color);
    json.load("implementation", implementation);
}
IR::Node * IR::Meter::fromJSON(JSONLoader & json) { return new Meter(json); }
IR::Meter::Meter(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    CounterOrMeter(srcInfo, name, annotations)
    { validate(); }
IR::Meter::Meter(IR::ID name, const IR::Annotations* annotations) :
    CounterOrMeter(name, annotations)
    { validate(); }
IR::Meter::Meter(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    CounterOrMeter(srcInfo, annotations)
    { validate(); }
IR::Meter::Meter(const IR::Annotations* annotations) :
    CounterOrMeter(annotations)
    { validate(); }
IR::Meter::Meter(Util::SourceInfo srcInfo, IR::ID name) :
    CounterOrMeter(srcInfo, name)
    { validate(); }
IR::Meter::Meter(IR::ID name) :
    CounterOrMeter(name)
    { validate(); }
IR::Meter::Meter(Util::SourceInfo srcInfo) :
    CounterOrMeter(srcInfo)
    { validate(); }
IR::Meter::Meter() 
    { validate(); }

#line 327 "/home/fengyong/Desktop/p4c/ir/v1.def"
char const * IR::Register::kind() const { return "register"; }
#line 10711 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 328 "/home/fengyong/Desktop/p4c/ir/v1.def"
const IR::Type *IR::Register::getType() const { return Type_Register::get(); }
#line 10714 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Register::operator==(IR::Register const & a) const {
        return Stateful::operator==(static_cast<const Stateful &>(a))
        && layout == a.layout
        && width == a.width
        && signed_ == a.signed_;
    }
bool IR::Register::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Stateful::equiv(a_)) return false;
        auto &a = static_cast<const Register &>(a_);
        return layout == a.layout
        && width == a.width
        && signed_ == a.signed_;
    }
void IR::Register::dump_fields(std::ostream & out) const {
    Stateful::dump_fields(out);
        out << " layout=" << layout;
        out << " width=" << width;
        out << " signed_=" << signed_;
}
void IR::Register::toJSON(JSONGenerator & json) const {
    Stateful::toJSON(json);
    json << "," << std::endl << json.indent << "\"layout\" : " << this->layout;
    json << "," << std::endl << json.indent << "\"width\" : " << this->width;
    json << "," << std::endl << json.indent << "\"signed_\" : " << this->signed_;
}
IR::Register::Register(JSONLoader & json) : Stateful(json) {
    json.load("layout", layout);
    json.load("width", width);
    json.load("signed_", signed_);
}
IR::Node * IR::Register::fromJSON(JSONLoader & json) { return new Register(json); }
IR::Register::Register(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Stateful(srcInfo, name, annotations)
    { validate(); }
IR::Register::Register(IR::ID name, const IR::Annotations* annotations) :
    Stateful(name, annotations)
    { validate(); }
IR::Register::Register(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    Stateful(srcInfo, annotations)
    { validate(); }
IR::Register::Register(const IR::Annotations* annotations) :
    Stateful(annotations)
    { validate(); }
IR::Register::Register(Util::SourceInfo srcInfo, IR::ID name) :
    Stateful(srcInfo, name)
    { validate(); }
IR::Register::Register(IR::ID name) :
    Stateful(name)
    { validate(); }
IR::Register::Register(Util::SourceInfo srcInfo) :
    Stateful(srcInfo)
    { validate(); }
IR::Register::Register() 
    { validate(); }
bool IR::PrimitiveAction::operator==(IR::PrimitiveAction const & a) const {
        return typeid(*this) == typeid(a);
    }
bool IR::PrimitiveAction::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        return true;
    }
void IR::PrimitiveAction::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
}
IR::PrimitiveAction::PrimitiveAction(JSONLoader & json) : Node(json) {
}
IR::Node * IR::PrimitiveAction::fromJSON(JSONLoader & json) { return new PrimitiveAction(json); }
IR::PrimitiveAction::PrimitiveAction(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::PrimitiveAction::PrimitiveAction() 
    { validate(); }
#line 335 "/home/fengyong/Desktop/p4c/ir/v1.def"
IR::NameList::NameList(Util::SourceInfo si, cstring n) { names.emplace_back(si, n); }
#line 10791 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 336 "/home/fengyong/Desktop/p4c/ir/v1.def"
IR::NameList::NameList(Util::SourceInfo si, IR::ID n) { names.emplace_back(si, n); }
#line 10794 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 337 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::NameList::dump_fields(std::ostream & out) const { out << "names=" << names; }
#line 10797 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::NameList::operator==(IR::NameList const & a) const {
        return typeid(*this) == typeid(a)
        && names == a.names;
    }
bool IR::NameList::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const NameList &>(a_);
        return names == a.names;
    }
void IR::NameList::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"names\" : " << this->names;
}
IR::NameList::NameList(JSONLoader & json) : Node(json) {
    json.load("names", names);
}
IR::Node * IR::NameList::fromJSON(JSONLoader & json) { return new NameList(json); }
IR::NameList::NameList(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::NameList::NameList() 
    { validate(); }
#line 346 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::ActionArg::dbprint(std::ostream & out) const { out << action_name << ':' << name; }
#line 10823 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 347 "/home/fengyong/Desktop/p4c/ir/v1.def"
cstring IR::ActionArg::toString() const { return name.name; }
#line 10826 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::ActionArg::operator==(IR::ActionArg const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && action_name == a.action_name
        && name == a.name
        && read == a.read
        && write == a.write;
    }
bool IR::ActionArg::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const ActionArg &>(a_);
        return action_name == a.action_name
        && name == a.name
        && read == a.read
        && write == a.write;
    }
void IR::ActionArg::dump_fields(std::ostream & out) const {
    Expression::dump_fields(out);
        out << " action_name=" << action_name;
        out << " name=" << name;
        out << " read=" << read;
        out << " write=" << write;
}
void IR::ActionArg::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"action_name\" : " << this->action_name;
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"read\" : " << this->read;
    json << "," << std::endl << json.indent << "\"write\" : " << this->write;
}
IR::ActionArg::ActionArg(JSONLoader & json) : Expression(json) {
    json.load("action_name", action_name);
    json.load("name", name);
    json.load("read", read);
    json.load("write", write);
}
IR::Node * IR::ActionArg::fromJSON(JSONLoader & json) { return new ActionArg(json); }
IR::ActionArg::ActionArg(Util::SourceInfo srcInfo, const IR::Type* type, cstring action_name, IR::ID name) :
    Expression(srcInfo, type), action_name(action_name), name(name)
    {
#line 345 "/home/fengyong/Desktop/p4c/ir/v1.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 10869 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::ActionArg::ActionArg(const IR::Type* type, cstring action_name, IR::ID name) :
    Expression(type), action_name(action_name), name(name)
    {
#line 345 "/home/fengyong/Desktop/p4c/ir/v1.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 10876 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::ActionArg::ActionArg(Util::SourceInfo srcInfo, cstring action_name, IR::ID name) :
    Expression(srcInfo), action_name(action_name), name(name)
    {
#line 345 "/home/fengyong/Desktop/p4c/ir/v1.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 10883 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::ActionArg::ActionArg(cstring action_name, IR::ID name) :
    action_name(action_name), name(name)
    {
#line 345 "/home/fengyong/Desktop/p4c/ir/v1.def"
{ if (!srcInfo) srcInfo = name.srcInfo; }
#line 10890 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
#line 357 "/home/fengyong/Desktop/p4c/ir/v1.def"
const IR::Annotations *IR::ActionFunction::getAnnotations() const { return annotations; }
#line 10894 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 358 "/home/fengyong/Desktop/p4c/ir/v1.def"
const IR::ActionArg *IR::ActionFunction::arg(cstring n) const {
        for (auto a : args)
            if (a->name == n)
                return a;
        return nullptr; }
#line 10901 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 363 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::ActionFunction::visit_children(Visitor & v) {
        v.visit(action, "action");
        // DANGER -- visiting action first so type inferencing will push types to
        // DANGER -- action args based on use.  This is immoral.
        for (auto &a : args) v.visit(a, "arg");
        v.visit(annotations, "annotations");
    }
#line 363 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::ActionFunction::visit_children(Visitor & v) const {
        v.visit(action, "action");
        // DANGER -- visiting action first so type inferencing will push types to
        // DANGER -- action args based on use.  This is immoral.
        for (auto &a : args) v.visit(a, "arg");
        v.visit(annotations, "annotations");
    }
#line 10918 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 370 "/home/fengyong/Desktop/p4c/ir/v1.def"
cstring IR::ActionFunction::toString() const {
        return cstring("action ") + name + " {\n" +
                 cstring::join(action.begin(), action.end(), ";\n") +
                 " }"; }
#line 10924 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::ActionFunction::operator==(IR::ActionFunction const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && action == a.action
        && args == a.args
        && annotations == a.annotations;
    }
bool IR::ActionFunction::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const ActionFunction &>(a_);
        return name == a.name
        && action.equiv(a.action)
        && args == a.args
        && (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr);
    }
void IR::ActionFunction::validate() const {
#line 10942 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        action.validate();
        CHECK_NULL(annotations); }
void IR::ActionFunction::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
}
void IR::ActionFunction::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"action\" : " << this->action;
    json << "," << std::endl << json.indent << "\"args\" : " << this->args;
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
}
IR::ActionFunction::ActionFunction(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("action", action);
    json.load("args", args);
    json.load("annotations", annotations);
}
IR::Node * IR::ActionFunction::fromJSON(JSONLoader & json) { return new ActionFunction(json); }
IR::ActionFunction::ActionFunction(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Node(srcInfo), name(name), annotations(annotations)
    { validate(); }
IR::ActionFunction::ActionFunction(IR::ID name, const IR::Annotations* annotations) :
    name(name), annotations(annotations)
    { validate(); }
IR::ActionFunction::ActionFunction(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    Node(srcInfo), annotations(annotations)
    { validate(); }
IR::ActionFunction::ActionFunction(const IR::Annotations* annotations) :
    annotations(annotations)
    { validate(); }
IR::ActionFunction::ActionFunction(Util::SourceInfo srcInfo, IR::ID name) :
    Node(srcInfo), name(name)
    { validate(); }
IR::ActionFunction::ActionFunction(IR::ID name) :
    name(name)
    { validate(); }
IR::ActionFunction::ActionFunction(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::ActionFunction::ActionFunction() 
    { validate(); }
#line 380 "/home/fengyong/Desktop/p4c/ir/v1.def"
char const * IR::ActionProfile::kind() const { return "action_profile"; }
#line 10989 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 381 "/home/fengyong/Desktop/p4c/ir/v1.def"
bool IR::ActionProfile::indexed() const { return true; }
#line 10992 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::ActionProfile::operator==(IR::ActionProfile const & a) const {
        return Attached::operator==(static_cast<const Attached &>(a))
        && selector == a.selector
        && actions == a.actions
        && size == a.size;
    }
bool IR::ActionProfile::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Attached::equiv(a_)) return false;
        auto &a = static_cast<const ActionProfile &>(a_);
        return selector == a.selector
        && actions == a.actions
        && size == a.size;
    }
void IR::ActionProfile::dump_fields(std::ostream & out) const {
    Attached::dump_fields(out);
        out << " selector=" << selector;
        out << " size=" << size;
}
void IR::ActionProfile::toJSON(JSONGenerator & json) const {
    Attached::toJSON(json);
    json << "," << std::endl << json.indent << "\"selector\" : " << this->selector;
    json << "," << std::endl << json.indent << "\"actions\" : " << this->actions;
    json << "," << std::endl << json.indent << "\"size\" : " << this->size;
}
IR::ActionProfile::ActionProfile(JSONLoader & json) : Attached(json) {
    json.load("selector", selector);
    json.load("actions", actions);
    json.load("size", size);
}
IR::Node * IR::ActionProfile::fromJSON(JSONLoader & json) { return new ActionProfile(json); }
IR::ActionProfile::ActionProfile(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Attached(srcInfo, name, annotations)
    { validate(); }
IR::ActionProfile::ActionProfile(IR::ID name, const IR::Annotations* annotations) :
    Attached(name, annotations)
    { validate(); }
IR::ActionProfile::ActionProfile(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    Attached(srcInfo, annotations)
    { validate(); }
IR::ActionProfile::ActionProfile(const IR::Annotations* annotations) :
    Attached(annotations)
    { validate(); }
IR::ActionProfile::ActionProfile(Util::SourceInfo srcInfo, IR::ID name) :
    Attached(srcInfo, name)
    { validate(); }
IR::ActionProfile::ActionProfile(IR::ID name) :
    Attached(name)
    { validate(); }
IR::ActionProfile::ActionProfile(Util::SourceInfo srcInfo) :
    Attached(srcInfo)
    { validate(); }
IR::ActionProfile::ActionProfile() 
    { validate(); }
#line 389 "/home/fengyong/Desktop/p4c/ir/v1.def"
char const * IR::ActionSelector::kind() const { return "action_selector"; }
#line 11049 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::ActionSelector::operator==(IR::ActionSelector const & a) const {
        return Attached::operator==(static_cast<const Attached &>(a))
        && key == a.key
        && key_fields == a.key_fields
        && mode == a.mode
        && type == a.type;
    }
bool IR::ActionSelector::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Attached::equiv(a_)) return false;
        auto &a = static_cast<const ActionSelector &>(a_);
        return key == a.key
        && (key_fields ? a.key_fields ? key_fields->equiv(*a.key_fields) : false : a.key_fields == nullptr)
        && mode == a.mode
        && type == a.type;
    }
void IR::ActionSelector::visit_children(Visitor & v) {
    Attached::visit_children(v);
    v.visit(key_fields, "key_fields");
}
void IR::ActionSelector::visit_children(Visitor & v) const {
    Attached::visit_children(v);
    v.visit(key_fields, "key_fields");
}
void IR::ActionSelector::dump_fields(std::ostream & out) const {
    Attached::dump_fields(out);
        out << " key=" << key;
        out << " mode=" << mode;
        out << " type=" << type;
}
void IR::ActionSelector::toJSON(JSONGenerator & json) const {
    Attached::toJSON(json);
    json << "," << std::endl << json.indent << "\"key\" : " << this->key;
    if (key_fields != nullptr)     json << "," << std::endl << json.indent << "\"key_fields\" : " << this->key_fields;
    json << "," << std::endl << json.indent << "\"mode\" : " << this->mode;
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
}
IR::ActionSelector::ActionSelector(JSONLoader & json) : Attached(json) {
    json.load("key", key);
    json.load("key_fields", key_fields);
    json.load("mode", mode);
    json.load("type", type);
}
IR::Node * IR::ActionSelector::fromJSON(JSONLoader & json) { return new ActionSelector(json); }
IR::ActionSelector::ActionSelector(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Attached(srcInfo, name, annotations)
    { validate(); }
IR::ActionSelector::ActionSelector(IR::ID name, const IR::Annotations* annotations) :
    Attached(name, annotations)
    { validate(); }
IR::ActionSelector::ActionSelector(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    Attached(srcInfo, annotations)
    { validate(); }
IR::ActionSelector::ActionSelector(const IR::Annotations* annotations) :
    Attached(annotations)
    { validate(); }
IR::ActionSelector::ActionSelector(Util::SourceInfo srcInfo, IR::ID name) :
    Attached(srcInfo, name)
    { validate(); }
IR::ActionSelector::ActionSelector(IR::ID name) :
    Attached(name)
    { validate(); }
IR::ActionSelector::ActionSelector(Util::SourceInfo srcInfo) :
    Attached(srcInfo)
    { validate(); }
IR::ActionSelector::ActionSelector() 
    { validate(); }

#line 407 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::V1Table::addProperty(const IR::Property* prop) { properties.push_back(prop); }
#line 11120 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 408 "/home/fengyong/Desktop/p4c/ir/v1.def"
const IR::Annotations *IR::V1Table::getAnnotations() const { return annotations; }
#line 11123 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 409 "/home/fengyong/Desktop/p4c/ir/v1.def"
cstring IR::V1Table::toString() const { return node_type_name() + " " + name; }
#line 11126 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 410 "/home/fengyong/Desktop/p4c/ir/v1.def"
IR::ID IR::V1Table::Name() const { return name; }
#line 11129 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 411 "/home/fengyong/Desktop/p4c/ir/v1.def"
const IR::Type *IR::V1Table::getType() const { return Type_AnyTable::get(); }
#line 11132 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::V1Table::operator==(IR::V1Table const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && reads == a.reads
        && reads_types == a.reads_types
        && min_size == a.min_size
        && max_size == a.max_size
        && size == a.size
        && action_profile == a.action_profile
        && actions == a.actions
        && default_action == a.default_action
        && default_action_is_const == a.default_action_is_const
        && default_action_args == a.default_action_args
        && properties == a.properties
        && annotations == a.annotations;
    }
bool IR::V1Table::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const V1Table &>(a_);
        return name == a.name
        && (reads ? a.reads ? reads->equiv(*a.reads) : false : a.reads == nullptr)
        && reads_types == a.reads_types
        && min_size == a.min_size
        && max_size == a.max_size
        && size == a.size
        && action_profile == a.action_profile
        && actions == a.actions
        && default_action == a.default_action
        && default_action_is_const == a.default_action_is_const
        && (default_action_args ? a.default_action_args ? default_action_args->equiv(*a.default_action_args) : false : a.default_action_args == nullptr)
        && properties.equiv(a.properties)
        && (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr);
    }
void IR::V1Table::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(reads, "reads");
    v.visit(default_action_args, "default_action_args");
    properties.visit_children(v);
    v.visit(annotations, "annotations");
}
void IR::V1Table::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(reads, "reads");
    v.visit(default_action_args, "default_action_args");
    properties.visit_children(v);
    v.visit(annotations, "annotations");
}
void IR::V1Table::validate() const {
#line 11182 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        properties.validate();
        CHECK_NULL(annotations); }
void IR::V1Table::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
        out << " min_size=" << min_size;
        out << " max_size=" << max_size;
        out << " size=" << size;
        out << " action_profile=" << action_profile;
        out << " default_action=" << default_action;
        out << " default_action_is_const=" << default_action_is_const;
}
void IR::V1Table::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    if (reads != nullptr)     json << "," << std::endl << json.indent << "\"reads\" : " << this->reads;
    json << "," << std::endl << json.indent << "\"reads_types\" : " << this->reads_types;
    json << "," << std::endl << json.indent << "\"min_size\" : " << this->min_size;
    json << "," << std::endl << json.indent << "\"max_size\" : " << this->max_size;
    json << "," << std::endl << json.indent << "\"size\" : " << this->size;
    json << "," << std::endl << json.indent << "\"action_profile\" : " << this->action_profile;
    json << "," << std::endl << json.indent << "\"actions\" : " << this->actions;
    json << "," << std::endl << json.indent << "\"default_action\" : " << this->default_action;
    json << "," << std::endl << json.indent << "\"default_action_is_const\" : " << this->default_action_is_const;
    if (default_action_args != nullptr)     json << "," << std::endl << json.indent << "\"default_action_args\" : " << this->default_action_args;
    json << "," << std::endl << json.indent << "\"properties\" : " << this->properties;
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
}
IR::V1Table::V1Table(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("reads", reads);
    json.load("reads_types", reads_types);
    json.load("min_size", min_size);
    json.load("max_size", max_size);
    json.load("size", size);
    json.load("action_profile", action_profile);
    json.load("actions", actions);
    json.load("default_action", default_action);
    json.load("default_action_is_const", default_action_is_const);
    json.load("default_action_args", default_action_args);
    json.load("properties", properties);
    json.load("annotations", annotations);
}
IR::Node * IR::V1Table::fromJSON(JSONLoader & json) { return new V1Table(json); }
IR::V1Table::V1Table(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Node(srcInfo), name(name), annotations(annotations)
    { validate(); }
IR::V1Table::V1Table(IR::ID name, const IR::Annotations* annotations) :
    name(name), annotations(annotations)
    { validate(); }
IR::V1Table::V1Table(Util::SourceInfo srcInfo, const IR::Annotations* annotations) :
    Node(srcInfo), annotations(annotations)
    { validate(); }
IR::V1Table::V1Table(const IR::Annotations* annotations) :
    annotations(annotations)
    { validate(); }
IR::V1Table::V1Table(Util::SourceInfo srcInfo, IR::ID name) :
    Node(srcInfo), name(name)
    { validate(); }
IR::V1Table::V1Table(IR::ID name) :
    name(name)
    { validate(); }
IR::V1Table::V1Table(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::V1Table::V1Table() 
    { validate(); }
#line 419 "/home/fengyong/Desktop/p4c/ir/v1.def"
IR::V1Control::V1Control(IR::ID n) : name(n), code(new Vector<Expression>()) {}
#line 11253 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 420 "/home/fengyong/Desktop/p4c/ir/v1.def"
IR::V1Control::V1Control(Util::SourceInfo si, IR::ID n) : Node(si), name(n), code(new Vector<Expression>()) {}
#line 11256 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
IRNODE_DEFINE_APPLY_OVERLOAD(V1Control, , )
#line 422 "/home/fengyong/Desktop/p4c/ir/v1.def"
const IR::Annotations *IR::V1Control::getAnnotations() const { return annotations; }
#line 11260 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 423 "/home/fengyong/Desktop/p4c/ir/v1.def"
cstring IR::V1Control::toString() const { return node_type_name() + " " + name; }
#line 11263 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::V1Control::operator==(IR::V1Control const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && code == a.code
        && annotations == a.annotations;
    }
bool IR::V1Control::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const V1Control &>(a_);
        return name == a.name
        && (code ? a.code ? code->equiv(*a.code) : false : a.code == nullptr)
        && (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr);
    }
void IR::V1Control::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(code, "code");
    v.visit(annotations, "annotations");
}
void IR::V1Control::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(code, "code");
    v.visit(annotations, "annotations");
}
void IR::V1Control::validate() const {
#line 11289 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(code);
        CHECK_NULL(annotations); }
void IR::V1Control::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
}
void IR::V1Control::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"code\" : " << this->code;
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
}
IR::V1Control::V1Control(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("code", code);
    json.load("annotations", annotations);
}
IR::Node * IR::V1Control::fromJSON(JSONLoader & json) { return new V1Control(json); }
IR::V1Control::V1Control(Util::SourceInfo srcInfo, IR::ID name, const IR::Vector<IR::Expression>* code, const IR::Annotations* annotations) :
    Node(srcInfo), name(name), code(code), annotations(annotations)
    { validate(); }
IR::V1Control::V1Control(IR::ID name, const IR::Vector<IR::Expression>* code, const IR::Annotations* annotations) :
    name(name), code(code), annotations(annotations)
    { validate(); }
#line 428 "/home/fengyong/Desktop/p4c/ir/v1.def"
IR::ID IR::AttribLocal::getName() const { return name; }
#line 11317 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 429 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::AttribLocal::dbprint(std::ostream & out) const { out << name; }
#line 11320 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::AttribLocal::operator==(IR::AttribLocal const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && name == a.name;
    }
bool IR::AttribLocal::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const AttribLocal &>(a_);
        return name == a.name;
    }
void IR::AttribLocal::dump_fields(std::ostream & out) const {
    Expression::dump_fields(out);
        out << " name=" << name;
}
void IR::AttribLocal::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
}
IR::AttribLocal::AttribLocal(JSONLoader & json) : Expression(json) {
    json.load("name", name);
}
IR::Node * IR::AttribLocal::fromJSON(JSONLoader & json) { return new AttribLocal(json); }
IR::AttribLocal::AttribLocal(Util::SourceInfo srcInfo, const IR::Type* type, IR::ID name) :
    Expression(srcInfo, type), name(name)
    { validate(); }
IR::AttribLocal::AttribLocal(const IR::Type* type, IR::ID name) :
    Expression(type), name(name)
    { validate(); }
IR::AttribLocal::AttribLocal(Util::SourceInfo srcInfo, IR::ID name) :
    Expression(srcInfo), name(name)
    { validate(); }
IR::AttribLocal::AttribLocal(IR::ID name) :
    name(name)
    { validate(); }
#line 435 "/home/fengyong/Desktop/p4c/ir/v1.def"
Util::Enumerator<const IR::IDeclaration *> * IR::AttribLocals::getDeclarations() const {
        return locals.valueEnumerator()->as<const IDeclaration *>(); }
#line 11358 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 437 "/home/fengyong/Desktop/p4c/ir/v1.def"
const IR::IDeclaration *IR::AttribLocals::getDeclByName(cstring name) const { return locals[name]; }
#line 11361 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::AttribLocals::operator==(IR::AttribLocals const & a) const {
        return typeid(*this) == typeid(a)
        && locals == a.locals;
    }
bool IR::AttribLocals::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const AttribLocals &>(a_);
        return locals.equiv(a.locals);
    }
void IR::AttribLocals::visit_children(Visitor & v) {
    Node::visit_children(v);
    locals.visit_children(v);
}
void IR::AttribLocals::visit_children(Visitor & v) const {
    Node::visit_children(v);
    locals.visit_children(v);
}
void IR::AttribLocals::validate() const {
#line 11381 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        locals.validate(); }
void IR::AttribLocals::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"locals\" : " << this->locals;
}
IR::AttribLocals::AttribLocals(JSONLoader & json) : Node(json) {
    json.load("locals", locals);
}
IR::Node * IR::AttribLocals::fromJSON(JSONLoader & json) { return new AttribLocals(json); }
IR::AttribLocals::AttribLocals(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::AttribLocals::AttribLocals() 
    { validate(); }
#line 444 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::Attribute::dbprint(std::ostream & out) const { if (type) out << type << ' '; out << name; }
#line 11399 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::Attribute::operator==(IR::Attribute const & a) const {
        return Declaration::operator==(static_cast<const Declaration &>(a))
        && type == a.type
        && locals == a.locals
        && optional == a.optional;
    }
bool IR::Attribute::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration::equiv(a_)) return false;
        auto &a = static_cast<const Attribute &>(a_);
        return (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr)
        && (locals ? a.locals ? locals->equiv(*a.locals) : false : a.locals == nullptr)
        && optional == a.optional;
    }
void IR::Attribute::visit_children(Visitor & v) {
    Declaration::visit_children(v);
    v.visit(type, "type");
    v.visit(locals, "locals");
}
void IR::Attribute::visit_children(Visitor & v) const {
    Declaration::visit_children(v);
    v.visit(type, "type");
    v.visit(locals, "locals");
}
void IR::Attribute::dump_fields(std::ostream & out) const {
    Declaration::dump_fields(out);
        out << " optional=" << optional;
}
void IR::Attribute::toJSON(JSONGenerator & json) const {
    Declaration::toJSON(json);
    if (type != nullptr)     json << "," << std::endl << json.indent << "\"type\" : " << this->type;
    if (locals != nullptr)     json << "," << std::endl << json.indent << "\"locals\" : " << this->locals;
    json << "," << std::endl << json.indent << "\"optional\" : " << this->optional;
}
IR::Attribute::Attribute(JSONLoader & json) : Declaration(json) {
    json.load("type", type);
    json.load("locals", locals);
    json.load("optional", optional);
}
IR::Node * IR::Attribute::fromJSON(JSONLoader & json) { return new Attribute(json); }
IR::Attribute::Attribute(Util::SourceInfo srcInfo, IR::ID name) :
    Declaration(srcInfo, name)
    { validate(); }
IR::Attribute::Attribute(IR::ID name) :
    Declaration(name)
    { validate(); }


#line 451 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::GlobalRef::validate() const {
#line 11450 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(obj);
#line 451 "/home/fengyong/Desktop/p4c/ir/v1.def"
{ BUG_CHECK(obj->is<IInstance>(), "Invalid object %1%", obj); } }
#line 11455 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 452 "/home/fengyong/Desktop/p4c/ir/v1.def"
cstring IR::GlobalRef::toString() const { return obj->to<IInstance>()->toString(); }
#line 11458 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 453 "/home/fengyong/Desktop/p4c/ir/v1.def"
IR::ID IR::GlobalRef::Name() const { return obj->to<IInstance>()->Name(); }
#line 11461 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 454 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::GlobalRef::dbprint(std::ostream & out) const { out << obj->to<IInstance>()->Name(); }
#line 11464 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::GlobalRef::operator==(IR::GlobalRef const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && obj == a.obj;
    }
bool IR::GlobalRef::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const GlobalRef &>(a_);
        return (obj ? a.obj ? obj->equiv(*a.obj) : false : a.obj == nullptr);
    }
void IR::GlobalRef::visit_children(Visitor & v) {
    Expression::visit_children(v);
    v.visit(obj, "obj");
}
void IR::GlobalRef::visit_children(Visitor & v) const {
    Expression::visit_children(v);
    v.visit(obj, "obj");
}
void IR::GlobalRef::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"obj\" : " << this->obj;
}
IR::GlobalRef::GlobalRef(JSONLoader & json) : Expression(json) {
    json.load("obj", obj);
}
IR::Node * IR::GlobalRef::fromJSON(JSONLoader & json) { return new GlobalRef(json); }
IR::GlobalRef::GlobalRef(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Node* obj) :
    Expression(srcInfo, type), obj(obj)
    {
#line 450 "/home/fengyong/Desktop/p4c/ir/v1.def"
{ type = obj->to<IInstance>()->getType(); }
#line 11496 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::GlobalRef::GlobalRef(const IR::Type* type, const IR::Node* obj) :
    Expression(type), obj(obj)
    {
#line 450 "/home/fengyong/Desktop/p4c/ir/v1.def"
{ type = obj->to<IInstance>()->getType(); }
#line 11503 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::GlobalRef::GlobalRef(Util::SourceInfo srcInfo, const IR::Node* obj) :
    Expression(srcInfo), obj(obj)
    {
#line 450 "/home/fengyong/Desktop/p4c/ir/v1.def"
{ type = obj->to<IInstance>()->getType(); }
#line 11510 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::GlobalRef::GlobalRef(const IR::Node* obj) :
    obj(obj)
    {
#line 450 "/home/fengyong/Desktop/p4c/ir/v1.def"
{ type = obj->to<IInstance>()->getType(); }
#line 11517 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
#line 462 "/home/fengyong/Desktop/p4c/ir/v1.def"
cstring IR::AttributeRef::toString() const { return attrib->name; }
#line 11521 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 463 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::AttributeRef::dbprint(std::ostream & out) const { out << attrib->name; }
#line 11524 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::AttributeRef::operator==(IR::AttributeRef const & a) const {
        return Expression::operator==(static_cast<const Expression &>(a))
        && extern_name == a.extern_name
        && extern_type == a.extern_type
        && attrib == a.attrib;
    }
bool IR::AttributeRef::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Expression::equiv(a_)) return false;
        auto &a = static_cast<const AttributeRef &>(a_);
        return extern_name == a.extern_name
        && (extern_type ? a.extern_type ? extern_type->equiv(*a.extern_type) : false : a.extern_type == nullptr)
        && (attrib ? a.attrib ? attrib->equiv(*a.attrib) : false : a.attrib == nullptr);
    }
void IR::AttributeRef::visit_children(Visitor & v) {
    Expression::visit_children(v);
    v.visit(extern_type, "extern_type");
    v.visit(attrib, "attrib");
}
void IR::AttributeRef::visit_children(Visitor & v) const {
    Expression::visit_children(v);
    v.visit(extern_type, "extern_type");
    v.visit(attrib, "attrib");
}
void IR::AttributeRef::validate() const {
#line 11550 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(extern_type);
        CHECK_NULL(attrib); }
void IR::AttributeRef::dump_fields(std::ostream & out) const {
    Expression::dump_fields(out);
        out << " extern_name=" << extern_name;
}
void IR::AttributeRef::toJSON(JSONGenerator & json) const {
    Expression::toJSON(json);
    json << "," << std::endl << json.indent << "\"extern_name\" : " << this->extern_name;
    json << "," << std::endl << json.indent << "\"extern_type\" : " << this->extern_type;
    json << "," << std::endl << json.indent << "\"attrib\" : " << this->attrib;
}
IR::AttributeRef::AttributeRef(JSONLoader & json) : Expression(json) {
    json.load("extern_name", extern_name);
    json.load("extern_type", extern_type);
    json.load("attrib", attrib);
}
IR::Node * IR::AttributeRef::fromJSON(JSONLoader & json) { return new AttributeRef(json); }
IR::AttributeRef::AttributeRef(Util::SourceInfo srcInfo, const IR::Type* type, cstring extern_name, const IR::Type_Extern* extern_type, const IR::Attribute* attrib) :
    Expression(srcInfo, type), extern_name(extern_name), extern_type(extern_type), attrib(attrib)
    {
#line 461 "/home/fengyong/Desktop/p4c/ir/v1.def"
{ type = attrib->type; }
#line 11575 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::AttributeRef::AttributeRef(const IR::Type* type, cstring extern_name, const IR::Type_Extern* extern_type, const IR::Attribute* attrib) :
    Expression(type), extern_name(extern_name), extern_type(extern_type), attrib(attrib)
    {
#line 461 "/home/fengyong/Desktop/p4c/ir/v1.def"
{ type = attrib->type; }
#line 11582 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::AttributeRef::AttributeRef(Util::SourceInfo srcInfo, cstring extern_name, const IR::Type_Extern* extern_type, const IR::Attribute* attrib) :
    Expression(srcInfo), extern_name(extern_name), extern_type(extern_type), attrib(attrib)
    {
#line 461 "/home/fengyong/Desktop/p4c/ir/v1.def"
{ type = attrib->type; }
#line 11589 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
IR::AttributeRef::AttributeRef(cstring extern_name, const IR::Type_Extern* extern_type, const IR::Attribute* attrib) :
    extern_name(extern_name), extern_type(extern_type), attrib(attrib)
    {
#line 461 "/home/fengyong/Desktop/p4c/ir/v1.def"
{ type = attrib->type; }
#line 11596 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
     validate(); }
#line 474 "/home/fengyong/Desktop/p4c/ir/v1.def"
void IR::V1Program::add(cstring name, IR::Node const * n) { scope.add(name, n); }
#line 11600 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
IRNODE_DEFINE_APPLY_OVERLOAD(V1Program, , )
bool IR::V1Program::operator==(IR::V1Program const & a) const {
        return typeid(*this) == typeid(a)
        && scope == a.scope;
    }
bool IR::V1Program::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const V1Program &>(a_);
        return scope.equiv(a.scope);
    }
void IR::V1Program::visit_children(Visitor & v) {
    Node::visit_children(v);
    scope.visit_children(v);
}
void IR::V1Program::visit_children(Visitor & v) const {
    Node::visit_children(v);
    scope.visit_children(v);
}
void IR::V1Program::validate() const {
#line 11621 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        scope.validate(); }
void IR::V1Program::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"scope\" : " << this->scope;
}
IR::V1Program::V1Program(JSONLoader & json) : Node(json) {
    json.load("scope", scope);
}
IR::Node * IR::V1Program::fromJSON(JSONLoader & json) { return new V1Program(json); }
#line 7 "/home/fengyong/Desktop/p4c/frontends/p4-14/ir-v1.def"
IR::v1HeaderType::v1HeaderType(IR::Type_Struct const * m, IR::Type_Header const * h) : v1HeaderType(Util::SourceInfo(), m->name, m, h) {}
#line 11634 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 9 "/home/fengyong/Desktop/p4c/frontends/p4-14/ir-v1.def"
void IR::v1HeaderType::dbprint(std::ostream & out) const { out << "header " << name; }
#line 11637 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::v1HeaderType::operator==(IR::v1HeaderType const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && as_metadata == a.as_metadata
        && as_header == a.as_header;
    }
bool IR::v1HeaderType::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const v1HeaderType &>(a_);
        return name == a.name
        && (as_metadata ? a.as_metadata ? as_metadata->equiv(*a.as_metadata) : false : a.as_metadata == nullptr)
        && (as_header ? a.as_header ? as_header->equiv(*a.as_header) : false : a.as_header == nullptr);
    }
void IR::v1HeaderType::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(as_metadata, "as_metadata");
    v.visit(as_header, "as_header");
}
void IR::v1HeaderType::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(as_metadata, "as_metadata");
    v.visit(as_header, "as_header");
}
void IR::v1HeaderType::validate() const {
#line 11663 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(as_metadata); }
void IR::v1HeaderType::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
}
void IR::v1HeaderType::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"as_metadata\" : " << this->as_metadata;
    if (as_header != nullptr)     json << "," << std::endl << json.indent << "\"as_header\" : " << this->as_header;
}
IR::v1HeaderType::v1HeaderType(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("as_metadata", as_metadata);
    json.load("as_header", as_header);
}
IR::Node * IR::v1HeaderType::fromJSON(JSONLoader & json) { return new v1HeaderType(json); }
IR::v1HeaderType::v1HeaderType(Util::SourceInfo srcInfo, IR::ID name, const IR::Type_Struct* as_metadata, const IR::Type_Header* as_header) :
    Node(srcInfo), name(name), as_metadata(as_metadata), as_header(as_header)
    { validate(); }
IR::v1HeaderType::v1HeaderType(IR::ID name, const IR::Type_Struct* as_metadata, const IR::Type_Header* as_header) :
    name(name), as_metadata(as_metadata), as_header(as_header)
    { validate(); }
bool IR::IntMod::operator==(IR::IntMod const & a) const {
        return Operation_Unary::operator==(static_cast<const Operation_Unary &>(a))
        && width == a.width;
    }
bool IR::IntMod::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Operation_Unary::equiv(a_)) return false;
        auto &a = static_cast<const IntMod &>(a_);
        return width == a.width;
    }
void IR::IntMod::dump_fields(std::ostream & out) const {
    Operation_Unary::dump_fields(out);
        out << " width=" << width;
}
void IR::IntMod::toJSON(JSONGenerator & json) const {
    Operation_Unary::toJSON(json);
    json << "," << std::endl << json.indent << "\"width\" : " << this->width;
}
IR::IntMod::IntMod(JSONLoader & json) : Operation_Unary(json) {
    json.load("width", width);
}
IR::Node * IR::IntMod::fromJSON(JSONLoader & json) { return new IntMod(json); }
IR::IntMod::IntMod(Util::SourceInfo srcInfo, const IR::Type* type, const IR::Expression* expr, unsigned width) :
    Operation_Unary(srcInfo, type, expr), width(width)
    { validate(); }
IR::IntMod::IntMod(const IR::Type* type, const IR::Expression* expr, unsigned width) :
    Operation_Unary(type, expr), width(width)
    { validate(); }
IR::IntMod::IntMod(Util::SourceInfo srcInfo, const IR::Expression* expr, unsigned width) :
    Operation_Unary(srcInfo, expr), width(width)
    { validate(); }
IR::IntMod::IntMod(const IR::Expression* expr, unsigned width) :
    Operation_Unary(expr), width(width)
    { validate(); }
bool IR::DpdkDeclaration::operator==(IR::DpdkDeclaration const & a) const {
        return typeid(*this) == typeid(a)
        && global == a.global;
    }
bool IR::DpdkDeclaration::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const DpdkDeclaration &>(a_);
        return (global ? a.global ? global->equiv(*a.global) : false : a.global == nullptr);
    }
void IR::DpdkDeclaration::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(global, "global");
}
void IR::DpdkDeclaration::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(global, "global");
}
void IR::DpdkDeclaration::validate() const {
#line 11741 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(global); }
void IR::DpdkDeclaration::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"global\" : " << this->global;
}
IR::DpdkDeclaration::DpdkDeclaration(JSONLoader & json) : Node(json) {
    json.load("global", global);
}
IR::Node * IR::DpdkDeclaration::fromJSON(JSONLoader & json) { return new DpdkDeclaration(json); }
IR::DpdkDeclaration::DpdkDeclaration(Util::SourceInfo srcInfo, const IR::Declaration* global) :
    Node(srcInfo), global(global)
    { validate(); }
IR::DpdkDeclaration::DpdkDeclaration(const IR::Declaration* global) :
    global(global)
    { validate(); }
bool IR::DpdkExternDeclaration::operator==(IR::DpdkExternDeclaration const & a) const {
        return Declaration_Instance::operator==(static_cast<const Declaration_Instance &>(a));
    }
bool IR::DpdkExternDeclaration::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Declaration_Instance::equiv(a_)) return false;
        return true;
    }
void IR::DpdkExternDeclaration::toJSON(JSONGenerator & json) const {
    Declaration_Instance::toJSON(json);
}
IR::DpdkExternDeclaration::DpdkExternDeclaration(JSONLoader & json) : Declaration_Instance(json) {
}
IR::Node * IR::DpdkExternDeclaration::fromJSON(JSONLoader & json) { return new DpdkExternDeclaration(json); }
IR::DpdkExternDeclaration::DpdkExternDeclaration(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer) :
    Declaration_Instance(srcInfo, name, annotations, type, arguments, initializer)
    { validate(); }
IR::DpdkExternDeclaration::DpdkExternDeclaration(IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer) :
    Declaration_Instance(name, annotations, type, arguments, initializer)
    { validate(); }
IR::DpdkExternDeclaration::DpdkExternDeclaration(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer) :
    Declaration_Instance(srcInfo, name, type, arguments, initializer)
    { validate(); }
IR::DpdkExternDeclaration::DpdkExternDeclaration(IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments, const IR::BlockStatement* initializer) :
    Declaration_Instance(name, type, arguments, initializer)
    { validate(); }
IR::DpdkExternDeclaration::DpdkExternDeclaration(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments) :
    Declaration_Instance(srcInfo, name, annotations, type, arguments)
    { validate(); }
IR::DpdkExternDeclaration::DpdkExternDeclaration(IR::ID name, const IR::Annotations* annotations, const IR::Type* type, const IR::Vector<IR::Argument>* arguments) :
    Declaration_Instance(name, annotations, type, arguments)
    { validate(); }
IR::DpdkExternDeclaration::DpdkExternDeclaration(Util::SourceInfo srcInfo, IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments) :
    Declaration_Instance(srcInfo, name, type, arguments)
    { validate(); }
IR::DpdkExternDeclaration::DpdkExternDeclaration(IR::ID name, const IR::Type* type, const IR::Vector<IR::Argument>* arguments) :
    Declaration_Instance(name, type, arguments)
    { validate(); }
bool IR::DpdkHeaderType::operator==(IR::DpdkHeaderType const & a) const {
        return Type_Header::operator==(static_cast<const Type_Header &>(a));
    }
bool IR::DpdkHeaderType::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Header::equiv(a_)) return false;
        return true;
    }
void IR::DpdkHeaderType::toJSON(JSONGenerator & json) const {
    Type_Header::toJSON(json);
}
IR::DpdkHeaderType::DpdkHeaderType(JSONLoader & json) : Type_Header(json) {
}
IR::Node * IR::DpdkHeaderType::fromJSON(JSONLoader & json) { return new DpdkHeaderType(json); }
IR::DpdkHeaderType::DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Header(srcInfo, name, annotations, typeParameters, fields)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Header(name, annotations, typeParameters, fields)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Header(srcInfo, name, typeParameters, fields)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Header(name, typeParameters, fields)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_Header(srcInfo, name, annotations, fields)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_Header(name, annotations, fields)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_Header(srcInfo, name, fields)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_Header(name, fields)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_Header(srcInfo, name, annotations, typeParameters)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_Header(name, annotations, typeParameters)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Header(srcInfo, name, typeParameters)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Header(name, typeParameters)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Type_Header(srcInfo, name, annotations)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(IR::ID name, const IR::Annotations* annotations) :
    Type_Header(name, annotations)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(Util::SourceInfo srcInfo, IR::ID name) :
    Type_Header(srcInfo, name)
    { validate(); }
IR::DpdkHeaderType::DpdkHeaderType(IR::ID name) :
    Type_Header(name)
    { validate(); }
bool IR::DpdkStructType::operator==(IR::DpdkStructType const & a) const {
        return Type_Struct::operator==(static_cast<const Type_Struct &>(a));
    }
bool IR::DpdkStructType::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!Type_Struct::equiv(a_)) return false;
        return true;
    }
void IR::DpdkStructType::toJSON(JSONGenerator & json) const {
    Type_Struct::toJSON(json);
}
IR::DpdkStructType::DpdkStructType(JSONLoader & json) : Type_Struct(json) {
}
IR::Node * IR::DpdkStructType::fromJSON(JSONLoader & json) { return new DpdkStructType(json); }
IR::DpdkStructType::DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Struct(srcInfo, name, annotations, typeParameters, fields)
    { validate(); }
IR::DpdkStructType::DpdkStructType(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Struct(name, annotations, typeParameters, fields)
    { validate(); }
IR::DpdkStructType::DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Struct(srcInfo, name, typeParameters, fields)
    { validate(); }
IR::DpdkStructType::DpdkStructType(IR::ID name, const IR::TypeParameters* typeParameters, IR::IndexedVector<IR::StructField> fields) :
    Type_Struct(name, typeParameters, fields)
    { validate(); }
IR::DpdkStructType::DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_Struct(srcInfo, name, annotations, fields)
    { validate(); }
IR::DpdkStructType::DpdkStructType(IR::ID name, const IR::Annotations* annotations, IR::IndexedVector<IR::StructField> fields) :
    Type_Struct(name, annotations, fields)
    { validate(); }
IR::DpdkStructType::DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_Struct(srcInfo, name, fields)
    { validate(); }
IR::DpdkStructType::DpdkStructType(IR::ID name, IR::IndexedVector<IR::StructField> fields) :
    Type_Struct(name, fields)
    { validate(); }
IR::DpdkStructType::DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_Struct(srcInfo, name, annotations, typeParameters)
    { validate(); }
IR::DpdkStructType::DpdkStructType(IR::ID name, const IR::Annotations* annotations, const IR::TypeParameters* typeParameters) :
    Type_Struct(name, annotations, typeParameters)
    { validate(); }
IR::DpdkStructType::DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Struct(srcInfo, name, typeParameters)
    { validate(); }
IR::DpdkStructType::DpdkStructType(IR::ID name, const IR::TypeParameters* typeParameters) :
    Type_Struct(name, typeParameters)
    { validate(); }
IR::DpdkStructType::DpdkStructType(Util::SourceInfo srcInfo, IR::ID name, const IR::Annotations* annotations) :
    Type_Struct(srcInfo, name, annotations)
    { validate(); }
IR::DpdkStructType::DpdkStructType(IR::ID name, const IR::Annotations* annotations) :
    Type_Struct(name, annotations)
    { validate(); }
IR::DpdkStructType::DpdkStructType(Util::SourceInfo srcInfo, IR::ID name) :
    Type_Struct(srcInfo, name)
    { validate(); }
IR::DpdkStructType::DpdkStructType(IR::ID name) :
    Type_Struct(name)
    { validate(); }
bool IR::DpdkAsmStatement::operator==(IR::DpdkAsmStatement const & a) const {
        return typeid(*this) == typeid(a);
    }
bool IR::DpdkAsmStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        return true;
    }
void IR::DpdkAsmStatement::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
}
IR::DpdkAsmStatement::DpdkAsmStatement(JSONLoader & json) : Node(json) {
}
IR::DpdkAsmStatement::DpdkAsmStatement(Util::SourceInfo srcInfo) :
    Node(srcInfo)
    { validate(); }
IR::DpdkAsmStatement::DpdkAsmStatement() 
    { validate(); }
bool IR::DpdkAction::operator==(IR::DpdkAction const & a) const {
        return typeid(*this) == typeid(a)
        && annotations == a.annotations
        && statements == a.statements
        && name == a.name
        && para == a.para;
    }
bool IR::DpdkAction::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const DpdkAction &>(a_);
        return (annotations ? a.annotations ? annotations->equiv(*a.annotations) : false : a.annotations == nullptr)
        && statements.equiv(a.statements)
        && name == a.name
        && para.equiv(a.para);
    }
void IR::DpdkAction::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
    statements.visit_children(v);
    para.visit_children(v);
}
void IR::DpdkAction::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(annotations, "annotations");
    statements.visit_children(v);
    para.visit_children(v);
}
void IR::DpdkAction::validate() const {
#line 11967 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(annotations);
        statements.validate();
        para.validate(); }
void IR::DpdkAction::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
}
void IR::DpdkAction::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"annotations\" : " << this->annotations;
    json << "," << std::endl << json.indent << "\"statements\" : " << this->statements;
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"para\" : " << this->para;
}
IR::DpdkAction::DpdkAction(JSONLoader & json) : Node(json) {
    json.load("annotations", annotations);
    json.load("statements", statements);
    json.load("name", name);
    json.load("para", para);
}
IR::Node * IR::DpdkAction::fromJSON(JSONLoader & json) { return new DpdkAction(json); }
IR::DpdkAction::DpdkAction(Util::SourceInfo srcInfo, const IR::Annotations* annotations, IR::IndexedVector<IR::DpdkAsmStatement> statements, IR::ID name, IR::ParameterList para) :
    Node(srcInfo), annotations(annotations), statements(statements), name(name), para(para)
    { validate(); }
IR::DpdkAction::DpdkAction(const IR::Annotations* annotations, IR::IndexedVector<IR::DpdkAsmStatement> statements, IR::ID name, IR::ParameterList para) :
    annotations(annotations), statements(statements), name(name), para(para)
    { validate(); }
IR::DpdkAction::DpdkAction(Util::SourceInfo srcInfo, IR::IndexedVector<IR::DpdkAsmStatement> statements, IR::ID name, IR::ParameterList para) :
    Node(srcInfo), statements(statements), name(name), para(para)
    { validate(); }
IR::DpdkAction::DpdkAction(IR::IndexedVector<IR::DpdkAsmStatement> statements, IR::ID name, IR::ParameterList para) :
    statements(statements), name(name), para(para)
    { validate(); }
#line 46 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
const IR::Key *IR::DpdkTable::getKey() const {
        auto kp = properties->getProperty(TableProperties::keyPropertyName);
        if (kp == nullptr)
            return nullptr;
        if (!kp->value->is<IR::Key>()) {
            ::error(ErrorType::ERR_INVALID, "%1%: must be a key", kp);
            return nullptr; }
        return kp->value->to<IR::Key>(); }
#line 12011 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 54 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
const IR::EntriesList *IR::DpdkTable::getEntries() const {
        auto ep = properties->getProperty(TableProperties::entriesPropertyName);
        if (ep == nullptr)
            return nullptr;
        if (!ep->value->is<IR::EntriesList>()) {
            ::error(ErrorType::ERR_INVALID, "%1%: must be a list of entries", ep);
            return nullptr;
        }
        return ep->value->to<IR::EntriesList>();
    }
#line 12023 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkTable::operator==(IR::DpdkTable const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && match_keys == a.match_keys
        && actions == a.actions
        && default_action == a.default_action
        && properties == a.properties
        && default_action_paraList == a.default_action_paraList;
    }
bool IR::DpdkTable::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const DpdkTable &>(a_);
        return name == a.name
        && (match_keys ? a.match_keys ? match_keys->equiv(*a.match_keys) : false : a.match_keys == nullptr)
        && (actions ? a.actions ? actions->equiv(*a.actions) : false : a.actions == nullptr)
        && (default_action ? a.default_action ? default_action->equiv(*a.default_action) : false : a.default_action == nullptr)
        && (properties ? a.properties ? properties->equiv(*a.properties) : false : a.properties == nullptr)
        && default_action_paraList.equiv(a.default_action_paraList);
    }
void IR::DpdkTable::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(match_keys, "match_keys");
    v.visit(actions, "actions");
    v.visit(default_action, "default_action");
    v.visit(properties, "properties");
    default_action_paraList.visit_children(v);
}
void IR::DpdkTable::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(match_keys, "match_keys");
    v.visit(actions, "actions");
    v.visit(default_action, "default_action");
    v.visit(properties, "properties");
    default_action_paraList.visit_children(v);
}
void IR::DpdkTable::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
}
void IR::DpdkTable::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"match_keys\" : " << this->match_keys;
    json << "," << std::endl << json.indent << "\"actions\" : " << this->actions;
    json << "," << std::endl << json.indent << "\"default_action\" : " << this->default_action;
    json << "," << std::endl << json.indent << "\"properties\" : " << this->properties;
    json << "," << std::endl << json.indent << "\"default_action_paraList\" : " << this->default_action_paraList;
}
IR::DpdkTable::DpdkTable(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("match_keys", match_keys);
    json.load("actions", actions);
    json.load("default_action", default_action);
    json.load("properties", properties);
    json.load("default_action_paraList", default_action_paraList);
}
IR::Node * IR::DpdkTable::fromJSON(JSONLoader & json) { return new DpdkTable(json); }
IR::DpdkTable::DpdkTable(Util::SourceInfo srcInfo, cstring name, const IR::Key* match_keys, const IR::ActionList* actions, const IR::Expression* default_action, const IR::TableProperties* properties, IR::ParameterList default_action_paraList) :
    Node(srcInfo), name(name), match_keys(match_keys), actions(actions), default_action(default_action), properties(properties), default_action_paraList(default_action_paraList)
    { validate(); }
IR::DpdkTable::DpdkTable(cstring name, const IR::Key* match_keys, const IR::ActionList* actions, const IR::Expression* default_action, const IR::TableProperties* properties, IR::ParameterList default_action_paraList) :
    name(name), match_keys(match_keys), actions(actions), default_action(default_action), properties(properties), default_action_paraList(default_action_paraList)
    { validate(); }
bool IR::DpdkSelector::operator==(IR::DpdkSelector const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && group_id == a.group_id
        && member_id == a.member_id
        && selectors == a.selectors
        && n_groups_max == a.n_groups_max
        && n_members_per_group_max == a.n_members_per_group_max;
    }
bool IR::DpdkSelector::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const DpdkSelector &>(a_);
        return name == a.name
        && (group_id ? a.group_id ? group_id->equiv(*a.group_id) : false : a.group_id == nullptr)
        && (member_id ? a.member_id ? member_id->equiv(*a.member_id) : false : a.member_id == nullptr)
        && (selectors ? a.selectors ? selectors->equiv(*a.selectors) : false : a.selectors == nullptr)
        && n_groups_max == a.n_groups_max
        && n_members_per_group_max == a.n_members_per_group_max;
    }
void IR::DpdkSelector::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(group_id, "group_id");
    v.visit(member_id, "member_id");
    v.visit(selectors, "selectors");
}
void IR::DpdkSelector::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(group_id, "group_id");
    v.visit(member_id, "member_id");
    v.visit(selectors, "selectors");
}
void IR::DpdkSelector::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
        out << " n_groups_max=" << n_groups_max;
        out << " n_members_per_group_max=" << n_members_per_group_max;
}
void IR::DpdkSelector::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"group_id\" : " << this->group_id;
    json << "," << std::endl << json.indent << "\"member_id\" : " << this->member_id;
    json << "," << std::endl << json.indent << "\"selectors\" : " << this->selectors;
    json << "," << std::endl << json.indent << "\"n_groups_max\" : " << this->n_groups_max;
    json << "," << std::endl << json.indent << "\"n_members_per_group_max\" : " << this->n_members_per_group_max;
}
IR::DpdkSelector::DpdkSelector(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("group_id", group_id);
    json.load("member_id", member_id);
    json.load("selectors", selectors);
    json.load("n_groups_max", n_groups_max);
    json.load("n_members_per_group_max", n_members_per_group_max);
}
IR::Node * IR::DpdkSelector::fromJSON(JSONLoader & json) { return new DpdkSelector(json); }
IR::DpdkSelector::DpdkSelector(Util::SourceInfo srcInfo, cstring name, const IR::Expression* group_id, const IR::Expression* member_id, const IR::Key* selectors, int n_groups_max, int n_members_per_group_max) :
    Node(srcInfo), name(name), group_id(group_id), member_id(member_id), selectors(selectors), n_groups_max(n_groups_max), n_members_per_group_max(n_members_per_group_max)
    { validate(); }
IR::DpdkSelector::DpdkSelector(cstring name, const IR::Expression* group_id, const IR::Expression* member_id, const IR::Key* selectors, int n_groups_max, int n_members_per_group_max) :
    name(name), group_id(group_id), member_id(member_id), selectors(selectors), n_groups_max(n_groups_max), n_members_per_group_max(n_members_per_group_max)
    { validate(); }
bool IR::DpdkLearner::operator==(IR::DpdkLearner const & a) const {
        return typeid(*this) == typeid(a)
        && name == a.name
        && match_keys == a.match_keys
        && actions == a.actions
        && default_action == a.default_action
        && properties == a.properties;
    }
bool IR::DpdkLearner::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const DpdkLearner &>(a_);
        return name == a.name
        && (match_keys ? a.match_keys ? match_keys->equiv(*a.match_keys) : false : a.match_keys == nullptr)
        && (actions ? a.actions ? actions->equiv(*a.actions) : false : a.actions == nullptr)
        && (default_action ? a.default_action ? default_action->equiv(*a.default_action) : false : a.default_action == nullptr)
        && (properties ? a.properties ? properties->equiv(*a.properties) : false : a.properties == nullptr);
    }
void IR::DpdkLearner::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(match_keys, "match_keys");
    v.visit(actions, "actions");
    v.visit(default_action, "default_action");
    v.visit(properties, "properties");
}
void IR::DpdkLearner::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(match_keys, "match_keys");
    v.visit(actions, "actions");
    v.visit(default_action, "default_action");
    v.visit(properties, "properties");
}
void IR::DpdkLearner::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " name=" << name;
}
void IR::DpdkLearner::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"name\" : " << this->name;
    json << "," << std::endl << json.indent << "\"match_keys\" : " << this->match_keys;
    json << "," << std::endl << json.indent << "\"actions\" : " << this->actions;
    json << "," << std::endl << json.indent << "\"default_action\" : " << this->default_action;
    json << "," << std::endl << json.indent << "\"properties\" : " << this->properties;
}
IR::DpdkLearner::DpdkLearner(JSONLoader & json) : Node(json) {
    json.load("name", name);
    json.load("match_keys", match_keys);
    json.load("actions", actions);
    json.load("default_action", default_action);
    json.load("properties", properties);
}
IR::Node * IR::DpdkLearner::fromJSON(JSONLoader & json) { return new DpdkLearner(json); }
IR::DpdkLearner::DpdkLearner(Util::SourceInfo srcInfo, cstring name, const IR::Key* match_keys, const IR::ActionList* actions, const IR::Expression* default_action, const IR::TableProperties* properties) :
    Node(srcInfo), name(name), match_keys(match_keys), actions(actions), default_action(default_action), properties(properties)
    { validate(); }
IR::DpdkLearner::DpdkLearner(cstring name, const IR::Key* match_keys, const IR::ActionList* actions, const IR::Expression* default_action, const IR::TableProperties* properties) :
    name(name), match_keys(match_keys), actions(actions), default_action(default_action), properties(properties)
    { validate(); }
bool IR::DpdkAsmProgram::operator==(IR::DpdkAsmProgram const & a) const {
        return typeid(*this) == typeid(a)
        && headerType == a.headerType
        && structType == a.structType
        && externDeclarations == a.externDeclarations
        && actions == a.actions
        && tables == a.tables
        && selectors == a.selectors
        && learners == a.learners
        && statements == a.statements
        && globals == a.globals;
    }
bool IR::DpdkAsmProgram::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const DpdkAsmProgram &>(a_);
        return headerType.equiv(a.headerType)
        && structType.equiv(a.structType)
        && externDeclarations.equiv(a.externDeclarations)
        && actions.equiv(a.actions)
        && tables.equiv(a.tables)
        && selectors.equiv(a.selectors)
        && learners.equiv(a.learners)
        && statements.equiv(a.statements)
        && globals.equiv(a.globals);
    }
void IR::DpdkAsmProgram::visit_children(Visitor & v) {
    Node::visit_children(v);
    headerType.visit_children(v);
    structType.visit_children(v);
    externDeclarations.visit_children(v);
    actions.visit_children(v);
    tables.visit_children(v);
    selectors.visit_children(v);
    learners.visit_children(v);
    statements.visit_children(v);
    globals.visit_children(v);
}
void IR::DpdkAsmProgram::visit_children(Visitor & v) const {
    Node::visit_children(v);
    headerType.visit_children(v);
    structType.visit_children(v);
    externDeclarations.visit_children(v);
    actions.visit_children(v);
    tables.visit_children(v);
    selectors.visit_children(v);
    learners.visit_children(v);
    statements.visit_children(v);
    globals.visit_children(v);
}
void IR::DpdkAsmProgram::validate() const {
#line 12259 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        headerType.validate();
        structType.validate();
        externDeclarations.validate();
        actions.validate();
        tables.validate();
        selectors.validate();
        learners.validate();
        statements.validate();
        globals.validate(); }
void IR::DpdkAsmProgram::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"headerType\" : " << this->headerType;
    json << "," << std::endl << json.indent << "\"structType\" : " << this->structType;
    json << "," << std::endl << json.indent << "\"externDeclarations\" : " << this->externDeclarations;
    json << "," << std::endl << json.indent << "\"actions\" : " << this->actions;
    json << "," << std::endl << json.indent << "\"tables\" : " << this->tables;
    json << "," << std::endl << json.indent << "\"selectors\" : " << this->selectors;
    json << "," << std::endl << json.indent << "\"learners\" : " << this->learners;
    json << "," << std::endl << json.indent << "\"statements\" : " << this->statements;
    json << "," << std::endl << json.indent << "\"globals\" : " << this->globals;
}
IR::DpdkAsmProgram::DpdkAsmProgram(JSONLoader & json) : Node(json) {
    json.load("headerType", headerType);
    json.load("structType", structType);
    json.load("externDeclarations", externDeclarations);
    json.load("actions", actions);
    json.load("tables", tables);
    json.load("selectors", selectors);
    json.load("learners", learners);
    json.load("statements", statements);
    json.load("globals", globals);
}
IR::Node * IR::DpdkAsmProgram::fromJSON(JSONLoader & json) { return new DpdkAsmProgram(json); }
IR::DpdkAsmProgram::DpdkAsmProgram(Util::SourceInfo srcInfo, IR::IndexedVector<IR::DpdkHeaderType> headerType, IR::IndexedVector<IR::DpdkStructType> structType, IR::IndexedVector<IR::DpdkExternDeclaration> externDeclarations, IR::IndexedVector<IR::DpdkAction> actions, IR::IndexedVector<IR::DpdkTable> tables, IR::IndexedVector<IR::DpdkSelector> selectors, IR::IndexedVector<IR::DpdkLearner> learners, IR::IndexedVector<IR::DpdkAsmStatement> statements, IR::IndexedVector<IR::DpdkDeclaration> globals) :
    Node(srcInfo), headerType(headerType), structType(structType), externDeclarations(externDeclarations), actions(actions), tables(tables), selectors(selectors), learners(learners), statements(statements), globals(globals)
    { validate(); }
IR::DpdkAsmProgram::DpdkAsmProgram(IR::IndexedVector<IR::DpdkHeaderType> headerType, IR::IndexedVector<IR::DpdkStructType> structType, IR::IndexedVector<IR::DpdkExternDeclaration> externDeclarations, IR::IndexedVector<IR::DpdkAction> actions, IR::IndexedVector<IR::DpdkTable> tables, IR::IndexedVector<IR::DpdkSelector> selectors, IR::IndexedVector<IR::DpdkLearner> learners, IR::IndexedVector<IR::DpdkAsmStatement> statements, IR::IndexedVector<IR::DpdkDeclaration> globals) :
    headerType(headerType), structType(structType), externDeclarations(externDeclarations), actions(actions), tables(tables), selectors(selectors), learners(learners), statements(statements), globals(globals)
    { validate(); }
bool IR::DpdkListStatement::operator==(IR::DpdkListStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && statements == a.statements;
    }
bool IR::DpdkListStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkListStatement &>(a_);
        return statements.equiv(a.statements);
    }
void IR::DpdkListStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    statements.visit_children(v);
}
void IR::DpdkListStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    statements.visit_children(v);
}
void IR::DpdkListStatement::validate() const {
#line 12319 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        statements.validate(); }
void IR::DpdkListStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"statements\" : " << this->statements;
}
IR::DpdkListStatement::DpdkListStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("statements", statements);
}
IR::Node * IR::DpdkListStatement::fromJSON(JSONLoader & json) { return new DpdkListStatement(json); }
IR::DpdkListStatement::DpdkListStatement(Util::SourceInfo srcInfo, IR::IndexedVector<IR::DpdkAsmStatement> statements) :
    DpdkAsmStatement(srcInfo), statements(statements)
    { validate(); }
IR::DpdkListStatement::DpdkListStatement(IR::IndexedVector<IR::DpdkAsmStatement> statements) :
    statements(statements)
    { validate(); }
IR::DpdkListStatement::DpdkListStatement(Util::SourceInfo srcInfo) :
    DpdkAsmStatement(srcInfo)
    { validate(); }
IR::DpdkListStatement::DpdkListStatement() 
    { validate(); }
bool IR::DpdkApplyStatement::operator==(IR::DpdkApplyStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && table == a.table;
    }
bool IR::DpdkApplyStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkApplyStatement &>(a_);
        return table == a.table;
    }
void IR::DpdkApplyStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " table=" << table;
}
void IR::DpdkApplyStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"table\" : " << this->table;
}
IR::DpdkApplyStatement::DpdkApplyStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("table", table);
}
IR::Node * IR::DpdkApplyStatement::fromJSON(JSONLoader & json) { return new DpdkApplyStatement(json); }
IR::DpdkApplyStatement::DpdkApplyStatement(Util::SourceInfo srcInfo, cstring table) :
    DpdkAsmStatement(srcInfo), table(table)
    { validate(); }
IR::DpdkApplyStatement::DpdkApplyStatement(cstring table) :
    table(table)
    { validate(); }
bool IR::DpdkLearnStatement::operator==(IR::DpdkLearnStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && action == a.action
        && timeout == a.timeout
        && argument == a.argument;
    }
bool IR::DpdkLearnStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkLearnStatement &>(a_);
        return action == a.action
        && (timeout ? a.timeout ? timeout->equiv(*a.timeout) : false : a.timeout == nullptr)
        && (argument ? a.argument ? argument->equiv(*a.argument) : false : a.argument == nullptr);
    }
void IR::DpdkLearnStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(timeout, "timeout");
    v.visit(argument, "argument");
}
void IR::DpdkLearnStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(timeout, "timeout");
    v.visit(argument, "argument");
}
void IR::DpdkLearnStatement::validate() const {
#line 12394 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(timeout); }
void IR::DpdkLearnStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " action=" << action;
}
void IR::DpdkLearnStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"action\" : " << this->action;
    json << "," << std::endl << json.indent << "\"timeout\" : " << this->timeout;
    if (argument != nullptr)     json << "," << std::endl << json.indent << "\"argument\" : " << this->argument;
}
IR::DpdkLearnStatement::DpdkLearnStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("action", action);
    json.load("timeout", timeout);
    json.load("argument", argument);
}
IR::Node * IR::DpdkLearnStatement::fromJSON(JSONLoader & json) { return new DpdkLearnStatement(json); }
IR::DpdkLearnStatement::DpdkLearnStatement(Util::SourceInfo srcInfo, IR::ID action, const IR::Expression* timeout, const IR::Expression* argument) :
    DpdkAsmStatement(srcInfo), action(action), timeout(timeout), argument(argument)
    { validate(); }
IR::DpdkLearnStatement::DpdkLearnStatement(IR::ID action, const IR::Expression* timeout, const IR::Expression* argument) :
    action(action), timeout(timeout), argument(argument)
    { validate(); }
IR::DpdkLearnStatement::DpdkLearnStatement(Util::SourceInfo srcInfo, IR::ID action, const IR::Expression* timeout) :
    DpdkAsmStatement(srcInfo), action(action), timeout(timeout)
    { validate(); }
IR::DpdkLearnStatement::DpdkLearnStatement(IR::ID action, const IR::Expression* timeout) :
    action(action), timeout(timeout)
    { validate(); }
bool IR::DpdkMirrorStatement::operator==(IR::DpdkMirrorStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && slotId == a.slotId
        && sessionId == a.sessionId;
    }
bool IR::DpdkMirrorStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkMirrorStatement &>(a_);
        return (slotId ? a.slotId ? slotId->equiv(*a.slotId) : false : a.slotId == nullptr)
        && (sessionId ? a.sessionId ? sessionId->equiv(*a.sessionId) : false : a.sessionId == nullptr);
    }
void IR::DpdkMirrorStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(slotId, "slotId");
    v.visit(sessionId, "sessionId");
}
void IR::DpdkMirrorStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(slotId, "slotId");
    v.visit(sessionId, "sessionId");
}
void IR::DpdkMirrorStatement::validate() const {
#line 12448 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(slotId);
        CHECK_NULL(sessionId); }
void IR::DpdkMirrorStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"slotId\" : " << this->slotId;
    json << "," << std::endl << json.indent << "\"sessionId\" : " << this->sessionId;
}
IR::DpdkMirrorStatement::DpdkMirrorStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("slotId", slotId);
    json.load("sessionId", sessionId);
}
IR::Node * IR::DpdkMirrorStatement::fromJSON(JSONLoader & json) { return new DpdkMirrorStatement(json); }
IR::DpdkMirrorStatement::DpdkMirrorStatement(Util::SourceInfo srcInfo, const IR::Expression* slotId, const IR::Expression* sessionId) :
    DpdkAsmStatement(srcInfo), slotId(slotId), sessionId(sessionId)
    { validate(); }
IR::DpdkMirrorStatement::DpdkMirrorStatement(const IR::Expression* slotId, const IR::Expression* sessionId) :
    slotId(slotId), sessionId(sessionId)
    { validate(); }
bool IR::DpdkEmitStatement::operator==(IR::DpdkEmitStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && header == a.header;
    }
bool IR::DpdkEmitStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkEmitStatement &>(a_);
        return (header ? a.header ? header->equiv(*a.header) : false : a.header == nullptr);
    }
void IR::DpdkEmitStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(header, "header");
}
void IR::DpdkEmitStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(header, "header");
}
void IR::DpdkEmitStatement::validate() const {
#line 12487 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(header); }
void IR::DpdkEmitStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"header\" : " << this->header;
}
IR::DpdkEmitStatement::DpdkEmitStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("header", header);
}
IR::Node * IR::DpdkEmitStatement::fromJSON(JSONLoader & json) { return new DpdkEmitStatement(json); }
IR::DpdkEmitStatement::DpdkEmitStatement(Util::SourceInfo srcInfo, const IR::Expression* header) :
    DpdkAsmStatement(srcInfo), header(header)
    { validate(); }
IR::DpdkEmitStatement::DpdkEmitStatement(const IR::Expression* header) :
    header(header)
    { validate(); }
bool IR::DpdkExtractStatement::operator==(IR::DpdkExtractStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && header == a.header
        && length == a.length;
    }
bool IR::DpdkExtractStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkExtractStatement &>(a_);
        return (header ? a.header ? header->equiv(*a.header) : false : a.header == nullptr)
        && (length ? a.length ? length->equiv(*a.length) : false : a.length == nullptr);
    }
void IR::DpdkExtractStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(header, "header");
    v.visit(length, "length");
}
void IR::DpdkExtractStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(header, "header");
    v.visit(length, "length");
}
void IR::DpdkExtractStatement::validate() const {
#line 12527 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(header); }
void IR::DpdkExtractStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"header\" : " << this->header;
    if (length != nullptr)     json << "," << std::endl << json.indent << "\"length\" : " << this->length;
}
IR::DpdkExtractStatement::DpdkExtractStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("header", header);
    json.load("length", length);
}
IR::Node * IR::DpdkExtractStatement::fromJSON(JSONLoader & json) { return new DpdkExtractStatement(json); }
IR::DpdkExtractStatement::DpdkExtractStatement(Util::SourceInfo srcInfo, const IR::Expression* header, const IR::Expression* length) :
    DpdkAsmStatement(srcInfo), header(header), length(length)
    { validate(); }
IR::DpdkExtractStatement::DpdkExtractStatement(const IR::Expression* header, const IR::Expression* length) :
    header(header), length(length)
    { validate(); }
IR::DpdkExtractStatement::DpdkExtractStatement(Util::SourceInfo srcInfo, const IR::Expression* header) :
    DpdkAsmStatement(srcInfo), header(header)
    { validate(); }
IR::DpdkExtractStatement::DpdkExtractStatement(const IR::Expression* header) :
    header(header)
    { validate(); }
bool IR::DpdkLookaheadStatement::operator==(IR::DpdkLookaheadStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && header == a.header;
    }
bool IR::DpdkLookaheadStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkLookaheadStatement &>(a_);
        return (header ? a.header ? header->equiv(*a.header) : false : a.header == nullptr);
    }
void IR::DpdkLookaheadStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(header, "header");
}
void IR::DpdkLookaheadStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(header, "header");
}
void IR::DpdkLookaheadStatement::validate() const {
#line 12571 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(header); }
void IR::DpdkLookaheadStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"header\" : " << this->header;
}
IR::DpdkLookaheadStatement::DpdkLookaheadStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("header", header);
}
IR::Node * IR::DpdkLookaheadStatement::fromJSON(JSONLoader & json) { return new DpdkLookaheadStatement(json); }
IR::DpdkLookaheadStatement::DpdkLookaheadStatement(Util::SourceInfo srcInfo, const IR::Expression* header) :
    DpdkAsmStatement(srcInfo), header(header)
    { validate(); }
IR::DpdkLookaheadStatement::DpdkLookaheadStatement(const IR::Expression* header) :
    header(header)
    { validate(); }
#line 156 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpStatement::DpdkJmpStatement(cstring instruction, cstring l) :
        instruction(instruction), label(l.toUpper()) { }
#line 12591 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpStatement::operator==(IR::DpdkJmpStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && instruction == a.instruction
        && label == a.label;
    }
bool IR::DpdkJmpStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkJmpStatement &>(a_);
        return instruction == a.instruction
        && label == a.label;
    }
void IR::DpdkJmpStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " instruction=" << instruction;
        out << " label=" << label;
}
void IR::DpdkJmpStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"instruction\" : " << this->instruction;
    json << "," << std::endl << json.indent << "\"label\" : " << this->label;
}
IR::DpdkJmpStatement::DpdkJmpStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("instruction", instruction);
    json.load("label", label);
}
#line 162 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpLabelStatement::DpdkJmpLabelStatement(cstring label) :
        DpdkJmpStatement("jmp", label) { }
#line 12621 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpLabelStatement::operator==(IR::DpdkJmpLabelStatement const & a) const {
        return DpdkJmpStatement::operator==(static_cast<const DpdkJmpStatement &>(a));
    }
bool IR::DpdkJmpLabelStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpLabelStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpStatement::toJSON(json);
}
IR::DpdkJmpLabelStatement::DpdkJmpLabelStatement(JSONLoader & json) : DpdkJmpStatement(json) {
}
IR::Node * IR::DpdkJmpLabelStatement::fromJSON(JSONLoader & json) { return new DpdkJmpLabelStatement(json); }
#line 169 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpHitStatement::DpdkJmpHitStatement(cstring label) :
        DpdkJmpStatement("jmph", label) { }
#line 12639 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpHitStatement::operator==(IR::DpdkJmpHitStatement const & a) const {
        return DpdkJmpStatement::operator==(static_cast<const DpdkJmpStatement &>(a));
    }
bool IR::DpdkJmpHitStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpHitStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpStatement::toJSON(json);
}
IR::DpdkJmpHitStatement::DpdkJmpHitStatement(JSONLoader & json) : DpdkJmpStatement(json) {
}
IR::Node * IR::DpdkJmpHitStatement::fromJSON(JSONLoader & json) { return new DpdkJmpHitStatement(json); }
#line 176 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpMissStatement::DpdkJmpMissStatement(cstring label) :
        DpdkJmpStatement("jmpnh", label) { }
#line 12657 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpMissStatement::operator==(IR::DpdkJmpMissStatement const & a) const {
        return DpdkJmpStatement::operator==(static_cast<const DpdkJmpStatement &>(a));
    }
bool IR::DpdkJmpMissStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpMissStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpStatement::toJSON(json);
}
IR::DpdkJmpMissStatement::DpdkJmpMissStatement(JSONLoader & json) : DpdkJmpStatement(json) {
}
IR::Node * IR::DpdkJmpMissStatement::fromJSON(JSONLoader & json) { return new DpdkJmpMissStatement(json); }
#line 185 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpActionStatement::DpdkJmpActionStatement(cstring instruction, cstring label, IR::ID action) :
        DpdkJmpStatement(instruction, label), action(action) { }
#line 12675 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpActionStatement::operator==(IR::DpdkJmpActionStatement const & a) const {
        return DpdkJmpStatement::operator==(static_cast<const DpdkJmpStatement &>(a))
        && action == a.action;
    }
bool IR::DpdkJmpActionStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkJmpActionStatement &>(a_);
        return action == a.action;
    }
void IR::DpdkJmpActionStatement::dump_fields(std::ostream & out) const {
    DpdkJmpStatement::dump_fields(out);
        out << " action=" << action;
}
void IR::DpdkJmpActionStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"action\" : " << this->action;
}
IR::DpdkJmpActionStatement::DpdkJmpActionStatement(JSONLoader & json) : DpdkJmpStatement(json) {
    json.load("action", action);
}
#line 192 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpIfActionRunStatement::DpdkJmpIfActionRunStatement(cstring label, cstring act) :
        DpdkJmpActionStatement("jmpa", label, act) { }
#line 12700 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpIfActionRunStatement::operator==(IR::DpdkJmpIfActionRunStatement const & a) const {
        return DpdkJmpActionStatement::operator==(static_cast<const DpdkJmpActionStatement &>(a));
    }
bool IR::DpdkJmpIfActionRunStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpActionStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpIfActionRunStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpActionStatement::toJSON(json);
}
IR::DpdkJmpIfActionRunStatement::DpdkJmpIfActionRunStatement(JSONLoader & json) : DpdkJmpActionStatement(json) {
}
IR::Node * IR::DpdkJmpIfActionRunStatement::fromJSON(JSONLoader & json) { return new DpdkJmpIfActionRunStatement(json); }
#line 199 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpIfActionNotRunStatement::DpdkJmpIfActionNotRunStatement(cstring label, cstring act) :
        DpdkJmpActionStatement("jmpna", label, act) { }
#line 12718 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpIfActionNotRunStatement::operator==(IR::DpdkJmpIfActionNotRunStatement const & a) const {
        return DpdkJmpActionStatement::operator==(static_cast<const DpdkJmpActionStatement &>(a));
    }
bool IR::DpdkJmpIfActionNotRunStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpActionStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpIfActionNotRunStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpActionStatement::toJSON(json);
}
IR::DpdkJmpIfActionNotRunStatement::DpdkJmpIfActionNotRunStatement(JSONLoader & json) : DpdkJmpActionStatement(json) {
}
IR::Node * IR::DpdkJmpIfActionNotRunStatement::fromJSON(JSONLoader & json) { return new DpdkJmpIfActionNotRunStatement(json); }
#line 207 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpHeaderStatement::DpdkJmpHeaderStatement(cstring instruction, cstring label, const IR::Expression* hdr) :
        DpdkJmpStatement(instruction, label), header(hdr) { }
#line 12736 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpHeaderStatement::operator==(IR::DpdkJmpHeaderStatement const & a) const {
        return DpdkJmpStatement::operator==(static_cast<const DpdkJmpStatement &>(a))
        && header == a.header;
    }
bool IR::DpdkJmpHeaderStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkJmpHeaderStatement &>(a_);
        return (header ? a.header ? header->equiv(*a.header) : false : a.header == nullptr);
    }
void IR::DpdkJmpHeaderStatement::visit_children(Visitor & v) {
    DpdkJmpStatement::visit_children(v);
    v.visit(header, "header");
}
void IR::DpdkJmpHeaderStatement::visit_children(Visitor & v) const {
    DpdkJmpStatement::visit_children(v);
    v.visit(header, "header");
}
void IR::DpdkJmpHeaderStatement::validate() const {
#line 12756 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(header); }
void IR::DpdkJmpHeaderStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"header\" : " << this->header;
}
IR::DpdkJmpHeaderStatement::DpdkJmpHeaderStatement(JSONLoader & json) : DpdkJmpStatement(json) {
    json.load("header", header);
}
#line 213 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpIfInvalidStatement::DpdkJmpIfInvalidStatement(cstring label, const IR::Expression* hdr) :
        DpdkJmpHeaderStatement("jmpnv", label, hdr) { }
#line 12769 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpIfInvalidStatement::operator==(IR::DpdkJmpIfInvalidStatement const & a) const {
        return DpdkJmpHeaderStatement::operator==(static_cast<const DpdkJmpHeaderStatement &>(a));
    }
bool IR::DpdkJmpIfInvalidStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpHeaderStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpIfInvalidStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpHeaderStatement::toJSON(json);
}
IR::DpdkJmpIfInvalidStatement::DpdkJmpIfInvalidStatement(JSONLoader & json) : DpdkJmpHeaderStatement(json) {
}
IR::Node * IR::DpdkJmpIfInvalidStatement::fromJSON(JSONLoader & json) { return new DpdkJmpIfInvalidStatement(json); }
#line 220 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpIfValidStatement::DpdkJmpIfValidStatement(cstring label, const IR::Expression* hdr) :
        DpdkJmpHeaderStatement("jmpv", label, hdr) { }
#line 12787 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpIfValidStatement::operator==(IR::DpdkJmpIfValidStatement const & a) const {
        return DpdkJmpHeaderStatement::operator==(static_cast<const DpdkJmpHeaderStatement &>(a));
    }
bool IR::DpdkJmpIfValidStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpHeaderStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpIfValidStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpHeaderStatement::toJSON(json);
}
IR::DpdkJmpIfValidStatement::DpdkJmpIfValidStatement(JSONLoader & json) : DpdkJmpHeaderStatement(json) {
}
IR::Node * IR::DpdkJmpIfValidStatement::fromJSON(JSONLoader & json) { return new DpdkJmpIfValidStatement(json); }
#line 229 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpCondStatement::DpdkJmpCondStatement(cstring instruction, cstring label, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkJmpStatement(instruction, label), src1(src1), src2(src2) { }
#line 12805 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpCondStatement::operator==(IR::DpdkJmpCondStatement const & a) const {
        return DpdkJmpStatement::operator==(static_cast<const DpdkJmpStatement &>(a))
        && src1 == a.src1
        && src2 == a.src2;
    }
bool IR::DpdkJmpCondStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkJmpCondStatement &>(a_);
        return (src1 ? a.src1 ? src1->equiv(*a.src1) : false : a.src1 == nullptr)
        && (src2 ? a.src2 ? src2->equiv(*a.src2) : false : a.src2 == nullptr);
    }
void IR::DpdkJmpCondStatement::visit_children(Visitor & v) {
    DpdkJmpStatement::visit_children(v);
    v.visit(src1, "src1");
    v.visit(src2, "src2");
}
void IR::DpdkJmpCondStatement::visit_children(Visitor & v) const {
    DpdkJmpStatement::visit_children(v);
    v.visit(src1, "src1");
    v.visit(src2, "src2");
}
void IR::DpdkJmpCondStatement::validate() const {
#line 12829 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(src1);
        CHECK_NULL(src2); }
void IR::DpdkJmpCondStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"src1\" : " << this->src1;
    json << "," << std::endl << json.indent << "\"src2\" : " << this->src2;
}
IR::DpdkJmpCondStatement::DpdkJmpCondStatement(JSONLoader & json) : DpdkJmpStatement(json) {
    json.load("src1", src1);
    json.load("src2", src2);
}
#line 234 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpEqualStatement::DpdkJmpEqualStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkJmpCondStatement("jmpeq", label, src1, src2) { }
#line 12845 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpEqualStatement::operator==(IR::DpdkJmpEqualStatement const & a) const {
        return DpdkJmpCondStatement::operator==(static_cast<const DpdkJmpCondStatement &>(a));
    }
bool IR::DpdkJmpEqualStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpCondStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpEqualStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpCondStatement::toJSON(json);
}
IR::DpdkJmpEqualStatement::DpdkJmpEqualStatement(JSONLoader & json) : DpdkJmpCondStatement(json) {
}
IR::Node * IR::DpdkJmpEqualStatement::fromJSON(JSONLoader & json) { return new DpdkJmpEqualStatement(json); }
#line 241 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpNotEqualStatement::DpdkJmpNotEqualStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkJmpCondStatement("jmpneq", label, src1, src2) { }
#line 12863 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpNotEqualStatement::operator==(IR::DpdkJmpNotEqualStatement const & a) const {
        return DpdkJmpCondStatement::operator==(static_cast<const DpdkJmpCondStatement &>(a));
    }
bool IR::DpdkJmpNotEqualStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpCondStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpNotEqualStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpCondStatement::toJSON(json);
}
IR::DpdkJmpNotEqualStatement::DpdkJmpNotEqualStatement(JSONLoader & json) : DpdkJmpCondStatement(json) {
}
IR::Node * IR::DpdkJmpNotEqualStatement::fromJSON(JSONLoader & json) { return new DpdkJmpNotEqualStatement(json); }
#line 248 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpGreaterEqualStatement::DpdkJmpGreaterEqualStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkJmpCondStatement("jmpge", label, src1, src2) { }
#line 12881 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpGreaterEqualStatement::operator==(IR::DpdkJmpGreaterEqualStatement const & a) const {
        return DpdkJmpCondStatement::operator==(static_cast<const DpdkJmpCondStatement &>(a));
    }
bool IR::DpdkJmpGreaterEqualStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpCondStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpGreaterEqualStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpCondStatement::toJSON(json);
}
IR::DpdkJmpGreaterEqualStatement::DpdkJmpGreaterEqualStatement(JSONLoader & json) : DpdkJmpCondStatement(json) {
}
IR::Node * IR::DpdkJmpGreaterEqualStatement::fromJSON(JSONLoader & json) { return new DpdkJmpGreaterEqualStatement(json); }
#line 255 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpGreaterStatement::DpdkJmpGreaterStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkJmpCondStatement("jmpgt", label, src1, src2) { }
#line 12899 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpGreaterStatement::operator==(IR::DpdkJmpGreaterStatement const & a) const {
        return DpdkJmpCondStatement::operator==(static_cast<const DpdkJmpCondStatement &>(a));
    }
bool IR::DpdkJmpGreaterStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpCondStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpGreaterStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpCondStatement::toJSON(json);
}
IR::DpdkJmpGreaterStatement::DpdkJmpGreaterStatement(JSONLoader & json) : DpdkJmpCondStatement(json) {
}
IR::Node * IR::DpdkJmpGreaterStatement::fromJSON(JSONLoader & json) { return new DpdkJmpGreaterStatement(json); }
#line 262 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpLessOrEqualStatement::DpdkJmpLessOrEqualStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkJmpCondStatement("jmple", label, src1, src2) { }
#line 12917 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpLessOrEqualStatement::operator==(IR::DpdkJmpLessOrEqualStatement const & a) const {
        return DpdkJmpCondStatement::operator==(static_cast<const DpdkJmpCondStatement &>(a));
    }
bool IR::DpdkJmpLessOrEqualStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpCondStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpLessOrEqualStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpCondStatement::toJSON(json);
}
IR::DpdkJmpLessOrEqualStatement::DpdkJmpLessOrEqualStatement(JSONLoader & json) : DpdkJmpCondStatement(json) {
}
IR::Node * IR::DpdkJmpLessOrEqualStatement::fromJSON(JSONLoader & json) { return new DpdkJmpLessOrEqualStatement(json); }
#line 269 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkJmpLessStatement::DpdkJmpLessStatement(cstring label, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkJmpCondStatement("jmplt", label, src1, src2) { }
#line 12935 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkJmpLessStatement::operator==(IR::DpdkJmpLessStatement const & a) const {
        return DpdkJmpCondStatement::operator==(static_cast<const DpdkJmpCondStatement &>(a));
    }
bool IR::DpdkJmpLessStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkJmpCondStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkJmpLessStatement::toJSON(JSONGenerator & json) const {
    DpdkJmpCondStatement::toJSON(json);
}
IR::DpdkJmpLessStatement::DpdkJmpLessStatement(JSONLoader & json) : DpdkJmpCondStatement(json) {
}
IR::Node * IR::DpdkJmpLessStatement::fromJSON(JSONLoader & json) { return new DpdkJmpLessStatement(json); }
bool IR::DpdkRxStatement::operator==(IR::DpdkRxStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && port == a.port;
    }
bool IR::DpdkRxStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkRxStatement &>(a_);
        return (port ? a.port ? port->equiv(*a.port) : false : a.port == nullptr);
    }
void IR::DpdkRxStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(port, "port");
}
void IR::DpdkRxStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(port, "port");
}
void IR::DpdkRxStatement::validate() const {
#line 12969 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(port); }
void IR::DpdkRxStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"port\" : " << this->port;
}
IR::DpdkRxStatement::DpdkRxStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("port", port);
}
IR::Node * IR::DpdkRxStatement::fromJSON(JSONLoader & json) { return new DpdkRxStatement(json); }
IR::DpdkRxStatement::DpdkRxStatement(Util::SourceInfo srcInfo, const IR::Expression* port) :
    DpdkAsmStatement(srcInfo), port(port)
    { validate(); }
IR::DpdkRxStatement::DpdkRxStatement(const IR::Expression* port) :
    port(port)
    { validate(); }
bool IR::DpdkTxStatement::operator==(IR::DpdkTxStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && port == a.port;
    }
bool IR::DpdkTxStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkTxStatement &>(a_);
        return (port ? a.port ? port->equiv(*a.port) : false : a.port == nullptr);
    }
void IR::DpdkTxStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(port, "port");
}
void IR::DpdkTxStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(port, "port");
}
void IR::DpdkTxStatement::validate() const {
#line 13005 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(port); }
void IR::DpdkTxStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"port\" : " << this->port;
}
IR::DpdkTxStatement::DpdkTxStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("port", port);
}
IR::Node * IR::DpdkTxStatement::fromJSON(JSONLoader & json) { return new DpdkTxStatement(json); }
IR::DpdkTxStatement::DpdkTxStatement(Util::SourceInfo srcInfo, const IR::Expression* port) :
    DpdkAsmStatement(srcInfo), port(port)
    { validate(); }
IR::DpdkTxStatement::DpdkTxStatement(const IR::Expression* port) :
    port(port)
    { validate(); }
#line 289 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkAssignmentStatement::DpdkAssignmentStatement(cstring instruction, const IR::Expression* dst) :
        instruction(instruction), dst(dst) { }
#line 13025 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkAssignmentStatement::operator==(IR::DpdkAssignmentStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && instruction == a.instruction
        && dst == a.dst;
    }
bool IR::DpdkAssignmentStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkAssignmentStatement &>(a_);
        return instruction == a.instruction
        && (dst ? a.dst ? dst->equiv(*a.dst) : false : a.dst == nullptr);
    }
void IR::DpdkAssignmentStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(dst, "dst");
}
void IR::DpdkAssignmentStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(dst, "dst");
}
void IR::DpdkAssignmentStatement::validate() const {
#line 13047 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(dst); }
void IR::DpdkAssignmentStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " instruction=" << instruction;
}
void IR::DpdkAssignmentStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"instruction\" : " << this->instruction;
    json << "," << std::endl << json.indent << "\"dst\" : " << this->dst;
}
IR::DpdkAssignmentStatement::DpdkAssignmentStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("instruction", instruction);
    json.load("dst", dst);
}
#line 297 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkUnaryStatement::DpdkUnaryStatement(cstring instruction, const IR::Expression* dst, const IR::Expression* src) :
        DpdkAssignmentStatement(instruction, dst), src(src) { }
#line 13066 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkUnaryStatement::operator==(IR::DpdkUnaryStatement const & a) const {
        return DpdkAssignmentStatement::operator==(static_cast<const DpdkAssignmentStatement &>(a))
        && src == a.src;
    }
bool IR::DpdkUnaryStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAssignmentStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkUnaryStatement &>(a_);
        return (src ? a.src ? src->equiv(*a.src) : false : a.src == nullptr);
    }
void IR::DpdkUnaryStatement::visit_children(Visitor & v) {
    DpdkAssignmentStatement::visit_children(v);
    v.visit(src, "src");
}
void IR::DpdkUnaryStatement::visit_children(Visitor & v) const {
    DpdkAssignmentStatement::visit_children(v);
    v.visit(src, "src");
}
void IR::DpdkUnaryStatement::validate() const {
#line 13086 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(src); }
void IR::DpdkUnaryStatement::toJSON(JSONGenerator & json) const {
    DpdkAssignmentStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"src\" : " << this->src;
}
IR::DpdkUnaryStatement::DpdkUnaryStatement(JSONLoader & json) : DpdkAssignmentStatement(json) {
    json.load("src", src);
}
#line 302 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkMovStatement::DpdkMovStatement(const IR::Expression* dst, const IR::Expression* src) :
        DpdkUnaryStatement("mov", dst, src) { }
#line 13099 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkMovStatement::operator==(IR::DpdkMovStatement const & a) const {
        return DpdkUnaryStatement::operator==(static_cast<const DpdkUnaryStatement &>(a));
    }
bool IR::DpdkMovStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkUnaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkMovStatement::toJSON(JSONGenerator & json) const {
    DpdkUnaryStatement::toJSON(json);
}
IR::DpdkMovStatement::DpdkMovStatement(JSONLoader & json) : DpdkUnaryStatement(json) {
}
IR::Node * IR::DpdkMovStatement::fromJSON(JSONLoader & json) { return new DpdkMovStatement(json); }
#line 312 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkBinaryStatement::DpdkBinaryStatement(cstring instruction, const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkAssignmentStatement(instruction, dst), src1(src1), src2(src2) { }
#line 13117 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkBinaryStatement::operator==(IR::DpdkBinaryStatement const & a) const {
        return DpdkAssignmentStatement::operator==(static_cast<const DpdkAssignmentStatement &>(a))
        && src1 == a.src1
        && src2 == a.src2;
    }
bool IR::DpdkBinaryStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAssignmentStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkBinaryStatement &>(a_);
        return (src1 ? a.src1 ? src1->equiv(*a.src1) : false : a.src1 == nullptr)
        && (src2 ? a.src2 ? src2->equiv(*a.src2) : false : a.src2 == nullptr);
    }
void IR::DpdkBinaryStatement::visit_children(Visitor & v) {
    DpdkAssignmentStatement::visit_children(v);
    v.visit(src1, "src1");
    v.visit(src2, "src2");
}
void IR::DpdkBinaryStatement::visit_children(Visitor & v) const {
    DpdkAssignmentStatement::visit_children(v);
    v.visit(src1, "src1");
    v.visit(src2, "src2");
}
void IR::DpdkBinaryStatement::validate() const {
#line 13141 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(src1);
        CHECK_NULL(src2); }
void IR::DpdkBinaryStatement::toJSON(JSONGenerator & json) const {
    DpdkAssignmentStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"src1\" : " << this->src1;
    json << "," << std::endl << json.indent << "\"src2\" : " << this->src2;
}
IR::DpdkBinaryStatement::DpdkBinaryStatement(JSONLoader & json) : DpdkAssignmentStatement(json) {
    json.load("src1", src1);
    json.load("src2", src2);
}
#line 319 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkAddStatement::DpdkAddStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("add", dst, src1, src2) { }
#line 13157 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkAddStatement::operator==(IR::DpdkAddStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkAddStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkAddStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkAddStatement::DpdkAddStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkAddStatement::fromJSON(JSONLoader & json) { return new DpdkAddStatement(json); }
#line 326 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkAndStatement::DpdkAndStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("and", dst, src1, src2) { }
#line 13175 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkAndStatement::operator==(IR::DpdkAndStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkAndStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkAndStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkAndStatement::DpdkAndStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkAndStatement::fromJSON(JSONLoader & json) { return new DpdkAndStatement(json); }
#line 333 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkShlStatement::DpdkShlStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("shl", dst, src1, src2) { }
#line 13193 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkShlStatement::operator==(IR::DpdkShlStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkShlStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkShlStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkShlStatement::DpdkShlStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkShlStatement::fromJSON(JSONLoader & json) { return new DpdkShlStatement(json); }
#line 340 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkShrStatement::DpdkShrStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("shr", dst, src1, src2) { }
#line 13211 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkShrStatement::operator==(IR::DpdkShrStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkShrStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkShrStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkShrStatement::DpdkShrStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkShrStatement::fromJSON(JSONLoader & json) { return new DpdkShrStatement(json); }
#line 347 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkSubStatement::DpdkSubStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("sub", dst, src1, src2) { }
#line 13229 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkSubStatement::operator==(IR::DpdkSubStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkSubStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkSubStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkSubStatement::DpdkSubStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkSubStatement::fromJSON(JSONLoader & json) { return new DpdkSubStatement(json); }
#line 354 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkOrStatement::DpdkOrStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("or", dst, src1, src2) { }
#line 13247 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkOrStatement::operator==(IR::DpdkOrStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkOrStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkOrStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkOrStatement::DpdkOrStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkOrStatement::fromJSON(JSONLoader & json) { return new DpdkOrStatement(json); }
#line 361 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkXorStatement::DpdkXorStatement(const IR::Expression* dst, const IR::Expression* src1, const IR::Expression* src2) :
        DpdkBinaryStatement("xor", dst, src1, src2) { }
#line 13265 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkXorStatement::operator==(IR::DpdkXorStatement const & a) const {
        return DpdkBinaryStatement::operator==(static_cast<const DpdkBinaryStatement &>(a));
    }
bool IR::DpdkXorStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkBinaryStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkXorStatement::toJSON(JSONGenerator & json) const {
    DpdkBinaryStatement::toJSON(json);
}
IR::DpdkXorStatement::DpdkXorStatement(JSONLoader & json) : DpdkBinaryStatement(json) {
}
IR::Node * IR::DpdkXorStatement::fromJSON(JSONLoader & json) { return new DpdkXorStatement(json); }
bool IR::DpdkRecircidStatement::operator==(IR::DpdkRecircidStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && pass == a.pass;
    }
bool IR::DpdkRecircidStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkRecircidStatement &>(a_);
        return (pass ? a.pass ? pass->equiv(*a.pass) : false : a.pass == nullptr);
    }
void IR::DpdkRecircidStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(pass, "pass");
}
void IR::DpdkRecircidStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(pass, "pass");
}
void IR::DpdkRecircidStatement::validate() const {
#line 13299 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(pass); }
void IR::DpdkRecircidStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"pass\" : " << this->pass;
}
IR::DpdkRecircidStatement::DpdkRecircidStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("pass", pass);
}
IR::Node * IR::DpdkRecircidStatement::fromJSON(JSONLoader & json) { return new DpdkRecircidStatement(json); }
IR::DpdkRecircidStatement::DpdkRecircidStatement(Util::SourceInfo srcInfo, const IR::Expression* pass) :
    DpdkAsmStatement(srcInfo), pass(pass)
    { validate(); }
IR::DpdkRecircidStatement::DpdkRecircidStatement(const IR::Expression* pass) :
    pass(pass)
    { validate(); }
bool IR::DpdkReturnStatement::operator==(IR::DpdkReturnStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a));
    }
bool IR::DpdkReturnStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkReturnStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
}
IR::DpdkReturnStatement::DpdkReturnStatement(JSONLoader & json) : DpdkAsmStatement(json) {
}
IR::Node * IR::DpdkReturnStatement::fromJSON(JSONLoader & json) { return new DpdkReturnStatement(json); }
IR::DpdkReturnStatement::DpdkReturnStatement(Util::SourceInfo srcInfo) :
    DpdkAsmStatement(srcInfo)
    { validate(); }
IR::DpdkReturnStatement::DpdkReturnStatement() 
    { validate(); }
bool IR::DpdkRearmStatement::operator==(IR::DpdkRearmStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && timeout == a.timeout;
    }
bool IR::DpdkRearmStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkRearmStatement &>(a_);
        return (timeout ? a.timeout ? timeout->equiv(*a.timeout) : false : a.timeout == nullptr);
    }
void IR::DpdkRearmStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(timeout, "timeout");
}
void IR::DpdkRearmStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(timeout, "timeout");
}
void IR::DpdkRearmStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    if (timeout != nullptr)     json << "," << std::endl << json.indent << "\"timeout\" : " << this->timeout;
}
IR::DpdkRearmStatement::DpdkRearmStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("timeout", timeout);
}
IR::Node * IR::DpdkRearmStatement::fromJSON(JSONLoader & json) { return new DpdkRearmStatement(json); }
IR::DpdkRearmStatement::DpdkRearmStatement(Util::SourceInfo srcInfo, const IR::Expression* timeout) :
    DpdkAsmStatement(srcInfo), timeout(timeout)
    { validate(); }
IR::DpdkRearmStatement::DpdkRearmStatement(const IR::Expression* timeout) :
    timeout(timeout)
    { validate(); }
IR::DpdkRearmStatement::DpdkRearmStatement(Util::SourceInfo srcInfo) :
    DpdkAsmStatement(srcInfo)
    { validate(); }
IR::DpdkRearmStatement::DpdkRearmStatement() 
    { validate(); }
bool IR::DpdkRecirculateStatement::operator==(IR::DpdkRecirculateStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a));
    }
bool IR::DpdkRecirculateStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkRecirculateStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
}
IR::DpdkRecirculateStatement::DpdkRecirculateStatement(JSONLoader & json) : DpdkAsmStatement(json) {
}
IR::Node * IR::DpdkRecirculateStatement::fromJSON(JSONLoader & json) { return new DpdkRecirculateStatement(json); }
IR::DpdkRecirculateStatement::DpdkRecirculateStatement(Util::SourceInfo srcInfo) :
    DpdkAsmStatement(srcInfo)
    { validate(); }
IR::DpdkRecirculateStatement::DpdkRecirculateStatement() 
    { validate(); }
#line 391 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkLabelStatement::DpdkLabelStatement(cstring l) : label(l.toUpper()) { }
#line 13393 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkLabelStatement::operator==(IR::DpdkLabelStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && label == a.label;
    }
bool IR::DpdkLabelStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkLabelStatement &>(a_);
        return label == a.label;
    }
void IR::DpdkLabelStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " label=" << label;
}
void IR::DpdkLabelStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"label\" : " << this->label;
}
IR::DpdkLabelStatement::DpdkLabelStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("label", label);
}
IR::Node * IR::DpdkLabelStatement::fromJSON(JSONLoader & json) { return new DpdkLabelStatement(json); }
bool IR::DpdkChecksumAddStatement::operator==(IR::DpdkChecksumAddStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && csum == a.csum
        && intermediate_value == a.intermediate_value
        && field == a.field;
    }
bool IR::DpdkChecksumAddStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkChecksumAddStatement &>(a_);
        return csum == a.csum
        && intermediate_value == a.intermediate_value
        && (field ? a.field ? field->equiv(*a.field) : false : a.field == nullptr);
    }
void IR::DpdkChecksumAddStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(field, "field");
}
void IR::DpdkChecksumAddStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(field, "field");
}
void IR::DpdkChecksumAddStatement::validate() const {
#line 13439 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(field); }
void IR::DpdkChecksumAddStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " csum=" << csum;
        out << " intermediate_value=" << intermediate_value;
}
void IR::DpdkChecksumAddStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"csum\" : " << this->csum;
    json << "," << std::endl << json.indent << "\"intermediate_value\" : " << this->intermediate_value;
    json << "," << std::endl << json.indent << "\"field\" : " << this->field;
}
IR::DpdkChecksumAddStatement::DpdkChecksumAddStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("csum", csum);
    json.load("intermediate_value", intermediate_value);
    json.load("field", field);
}
IR::Node * IR::DpdkChecksumAddStatement::fromJSON(JSONLoader & json) { return new DpdkChecksumAddStatement(json); }
IR::DpdkChecksumAddStatement::DpdkChecksumAddStatement(Util::SourceInfo srcInfo, cstring csum, cstring intermediate_value, const IR::Expression* field) :
    DpdkAsmStatement(srcInfo), csum(csum), intermediate_value(intermediate_value), field(field)
    { validate(); }
IR::DpdkChecksumAddStatement::DpdkChecksumAddStatement(cstring csum, cstring intermediate_value, const IR::Expression* field) :
    csum(csum), intermediate_value(intermediate_value), field(field)
    { validate(); }
bool IR::DpdkChecksumSubStatement::operator==(IR::DpdkChecksumSubStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && csum == a.csum
        && intermediate_value == a.intermediate_value
        && field == a.field;
    }
bool IR::DpdkChecksumSubStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkChecksumSubStatement &>(a_);
        return csum == a.csum
        && intermediate_value == a.intermediate_value
        && (field ? a.field ? field->equiv(*a.field) : false : a.field == nullptr);
    }
void IR::DpdkChecksumSubStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(field, "field");
}
void IR::DpdkChecksumSubStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(field, "field");
}
void IR::DpdkChecksumSubStatement::validate() const {
#line 13488 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(field); }
void IR::DpdkChecksumSubStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " csum=" << csum;
        out << " intermediate_value=" << intermediate_value;
}
void IR::DpdkChecksumSubStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"csum\" : " << this->csum;
    json << "," << std::endl << json.indent << "\"intermediate_value\" : " << this->intermediate_value;
    json << "," << std::endl << json.indent << "\"field\" : " << this->field;
}
IR::DpdkChecksumSubStatement::DpdkChecksumSubStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("csum", csum);
    json.load("intermediate_value", intermediate_value);
    json.load("field", field);
}
IR::Node * IR::DpdkChecksumSubStatement::fromJSON(JSONLoader & json) { return new DpdkChecksumSubStatement(json); }
IR::DpdkChecksumSubStatement::DpdkChecksumSubStatement(Util::SourceInfo srcInfo, cstring csum, cstring intermediate_value, const IR::Expression* field) :
    DpdkAsmStatement(srcInfo), csum(csum), intermediate_value(intermediate_value), field(field)
    { validate(); }
IR::DpdkChecksumSubStatement::DpdkChecksumSubStatement(cstring csum, cstring intermediate_value, const IR::Expression* field) :
    csum(csum), intermediate_value(intermediate_value), field(field)
    { validate(); }
bool IR::DpdkChecksumClearStatement::operator==(IR::DpdkChecksumClearStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && csum == a.csum
        && intermediate_value == a.intermediate_value;
    }
bool IR::DpdkChecksumClearStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkChecksumClearStatement &>(a_);
        return csum == a.csum
        && intermediate_value == a.intermediate_value;
    }
void IR::DpdkChecksumClearStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " csum=" << csum;
        out << " intermediate_value=" << intermediate_value;
}
void IR::DpdkChecksumClearStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"csum\" : " << this->csum;
    json << "," << std::endl << json.indent << "\"intermediate_value\" : " << this->intermediate_value;
}
IR::DpdkChecksumClearStatement::DpdkChecksumClearStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("csum", csum);
    json.load("intermediate_value", intermediate_value);
}
IR::Node * IR::DpdkChecksumClearStatement::fromJSON(JSONLoader & json) { return new DpdkChecksumClearStatement(json); }
IR::DpdkChecksumClearStatement::DpdkChecksumClearStatement(Util::SourceInfo srcInfo, cstring csum, cstring intermediate_value) :
    DpdkAsmStatement(srcInfo), csum(csum), intermediate_value(intermediate_value)
    { validate(); }
IR::DpdkChecksumClearStatement::DpdkChecksumClearStatement(cstring csum, cstring intermediate_value) :
    csum(csum), intermediate_value(intermediate_value)
    { validate(); }
bool IR::DpdkHashDeclStatement::operator==(IR::DpdkHashDeclStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && hash == a.hash;
    }
bool IR::DpdkHashDeclStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkHashDeclStatement &>(a_);
        return hash == a.hash;
    }
void IR::DpdkHashDeclStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " hash=" << hash;
}
void IR::DpdkHashDeclStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"hash\" : " << this->hash;
}
IR::DpdkHashDeclStatement::DpdkHashDeclStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("hash", hash);
}
IR::Node * IR::DpdkHashDeclStatement::fromJSON(JSONLoader & json) { return new DpdkHashDeclStatement(json); }
IR::DpdkHashDeclStatement::DpdkHashDeclStatement(Util::SourceInfo srcInfo, cstring hash) :
    DpdkAsmStatement(srcInfo), hash(hash)
    { validate(); }
IR::DpdkHashDeclStatement::DpdkHashDeclStatement(cstring hash) :
    hash(hash)
    { validate(); }
bool IR::DpdkGetHashStatement::operator==(IR::DpdkGetHashStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && instr == a.instr
        && hash == a.hash
        && fields == a.fields
        && dst == a.dst;
    }
bool IR::DpdkGetHashStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkGetHashStatement &>(a_);
        return instr == a.instr
        && hash == a.hash
        && (fields ? a.fields ? fields->equiv(*a.fields) : false : a.fields == nullptr)
        && (dst ? a.dst ? dst->equiv(*a.dst) : false : a.dst == nullptr);
    }
void IR::DpdkGetHashStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(fields, "fields");
    v.visit(dst, "dst");
}
void IR::DpdkGetHashStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(fields, "fields");
    v.visit(dst, "dst");
}
void IR::DpdkGetHashStatement::validate() const {
#line 13602 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(fields);
        CHECK_NULL(dst); }
void IR::DpdkGetHashStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " instr=" << instr;
        out << " hash=" << hash;
}
void IR::DpdkGetHashStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"instr\" : " << this->instr;
    json << "," << std::endl << json.indent << "\"hash\" : " << this->hash;
    json << "," << std::endl << json.indent << "\"fields\" : " << this->fields;
    json << "," << std::endl << json.indent << "\"dst\" : " << this->dst;
}
IR::DpdkGetHashStatement::DpdkGetHashStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("instr", instr);
    json.load("hash", hash);
    json.load("fields", fields);
    json.load("dst", dst);
}
IR::Node * IR::DpdkGetHashStatement::fromJSON(JSONLoader & json) { return new DpdkGetHashStatement(json); }
IR::DpdkGetHashStatement::DpdkGetHashStatement(Util::SourceInfo srcInfo, cstring instr, cstring hash, const IR::Expression* fields, const IR::Expression* dst) :
    DpdkAsmStatement(srcInfo), instr(instr), hash(hash), fields(fields), dst(dst)
    { validate(); }
IR::DpdkGetHashStatement::DpdkGetHashStatement(cstring instr, cstring hash, const IR::Expression* fields, const IR::Expression* dst) :
    instr(instr), hash(hash), fields(fields), dst(dst)
    { validate(); }
bool IR::DpdkGetChecksumStatement::operator==(IR::DpdkGetChecksumStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && dst == a.dst
        && checksum == a.checksum
        && intermediate_value == a.intermediate_value;
    }
bool IR::DpdkGetChecksumStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkGetChecksumStatement &>(a_);
        return (dst ? a.dst ? dst->equiv(*a.dst) : false : a.dst == nullptr)
        && checksum == a.checksum
        && intermediate_value == a.intermediate_value;
    }
void IR::DpdkGetChecksumStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(dst, "dst");
}
void IR::DpdkGetChecksumStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(dst, "dst");
}
void IR::DpdkGetChecksumStatement::validate() const {
#line 13654 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(dst); }
void IR::DpdkGetChecksumStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " checksum=" << checksum;
        out << " intermediate_value=" << intermediate_value;
}
void IR::DpdkGetChecksumStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"dst\" : " << this->dst;
    json << "," << std::endl << json.indent << "\"checksum\" : " << this->checksum;
    json << "," << std::endl << json.indent << "\"intermediate_value\" : " << this->intermediate_value;
}
IR::DpdkGetChecksumStatement::DpdkGetChecksumStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("dst", dst);
    json.load("checksum", checksum);
    json.load("intermediate_value", intermediate_value);
}
IR::Node * IR::DpdkGetChecksumStatement::fromJSON(JSONLoader & json) { return new DpdkGetChecksumStatement(json); }
IR::DpdkGetChecksumStatement::DpdkGetChecksumStatement(Util::SourceInfo srcInfo, const IR::Expression* dst, cstring checksum, cstring intermediate_value) :
    DpdkAsmStatement(srcInfo), dst(dst), checksum(checksum), intermediate_value(intermediate_value)
    { validate(); }
IR::DpdkGetChecksumStatement::DpdkGetChecksumStatement(const IR::Expression* dst, cstring checksum, cstring intermediate_value) :
    dst(dst), checksum(checksum), intermediate_value(intermediate_value)
    { validate(); }
bool IR::DpdkCastStatement::operator==(IR::DpdkCastStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && dst == a.dst
        && src == a.src
        && type == a.type;
    }
bool IR::DpdkCastStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkCastStatement &>(a_);
        return (dst ? a.dst ? dst->equiv(*a.dst) : false : a.dst == nullptr)
        && (src ? a.src ? src->equiv(*a.src) : false : a.src == nullptr)
        && (type ? a.type ? type->equiv(*a.type) : false : a.type == nullptr);
    }
void IR::DpdkCastStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(dst, "dst");
    v.visit(src, "src");
    v.visit(type, "type");
}
void IR::DpdkCastStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(dst, "dst");
    v.visit(src, "src");
    v.visit(type, "type");
}
void IR::DpdkCastStatement::validate() const {
#line 13707 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(dst);
        CHECK_NULL(src);
        CHECK_NULL(type); }
void IR::DpdkCastStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"dst\" : " << this->dst;
    json << "," << std::endl << json.indent << "\"src\" : " << this->src;
    json << "," << std::endl << json.indent << "\"type\" : " << this->type;
}
IR::DpdkCastStatement::DpdkCastStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("dst", dst);
    json.load("src", src);
    json.load("type", type);
}
IR::Node * IR::DpdkCastStatement::fromJSON(JSONLoader & json) { return new DpdkCastStatement(json); }
IR::DpdkCastStatement::DpdkCastStatement(Util::SourceInfo srcInfo, const IR::Expression* dst, const IR::Expression* src, const IR::Type* type) :
    DpdkAsmStatement(srcInfo), dst(dst), src(src), type(type)
    { validate(); }
IR::DpdkCastStatement::DpdkCastStatement(const IR::Expression* dst, const IR::Expression* src, const IR::Type* type) :
    dst(dst), src(src), type(type)
    { validate(); }
bool IR::DpdkVerifyStatement::operator==(IR::DpdkVerifyStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && condition == a.condition
        && error == a.error;
    }
bool IR::DpdkVerifyStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkVerifyStatement &>(a_);
        return (condition ? a.condition ? condition->equiv(*a.condition) : false : a.condition == nullptr)
        && (error ? a.error ? error->equiv(*a.error) : false : a.error == nullptr);
    }
void IR::DpdkVerifyStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(condition, "condition");
    v.visit(error, "error");
}
void IR::DpdkVerifyStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(condition, "condition");
    v.visit(error, "error");
}
void IR::DpdkVerifyStatement::validate() const {
#line 13753 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(condition);
        CHECK_NULL(error); }
void IR::DpdkVerifyStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"condition\" : " << this->condition;
    json << "," << std::endl << json.indent << "\"error\" : " << this->error;
}
IR::DpdkVerifyStatement::DpdkVerifyStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("condition", condition);
    json.load("error", error);
}
IR::Node * IR::DpdkVerifyStatement::fromJSON(JSONLoader & json) { return new DpdkVerifyStatement(json); }
IR::DpdkVerifyStatement::DpdkVerifyStatement(Util::SourceInfo srcInfo, const IR::Expression* condition, const IR::Expression* error) :
    DpdkAsmStatement(srcInfo), condition(condition), error(error)
    { validate(); }
IR::DpdkVerifyStatement::DpdkVerifyStatement(const IR::Expression* condition, const IR::Expression* error) :
    condition(condition), error(error)
    { validate(); }
bool IR::DpdkMeterDeclStatement::operator==(IR::DpdkMeterDeclStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && meter == a.meter
        && size == a.size;
    }
bool IR::DpdkMeterDeclStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkMeterDeclStatement &>(a_);
        return meter == a.meter
        && (size ? a.size ? size->equiv(*a.size) : false : a.size == nullptr);
    }
void IR::DpdkMeterDeclStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(size, "size");
}
void IR::DpdkMeterDeclStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(size, "size");
}
void IR::DpdkMeterDeclStatement::validate() const {
#line 13794 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(size); }
void IR::DpdkMeterDeclStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " meter=" << meter;
}
void IR::DpdkMeterDeclStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"meter\" : " << this->meter;
    json << "," << std::endl << json.indent << "\"size\" : " << this->size;
}
IR::DpdkMeterDeclStatement::DpdkMeterDeclStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("meter", meter);
    json.load("size", size);
}
IR::Node * IR::DpdkMeterDeclStatement::fromJSON(JSONLoader & json) { return new DpdkMeterDeclStatement(json); }
IR::DpdkMeterDeclStatement::DpdkMeterDeclStatement(Util::SourceInfo srcInfo, cstring meter, const IR::Expression* size) :
    DpdkAsmStatement(srcInfo), meter(meter), size(size)
    { validate(); }
IR::DpdkMeterDeclStatement::DpdkMeterDeclStatement(cstring meter, const IR::Expression* size) :
    meter(meter), size(size)
    { validate(); }
bool IR::DpdkMeterExecuteStatement::operator==(IR::DpdkMeterExecuteStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && meter == a.meter
        && index == a.index
        && length == a.length
        && color_in == a.color_in
        && color_out == a.color_out;
    }
bool IR::DpdkMeterExecuteStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkMeterExecuteStatement &>(a_);
        return meter == a.meter
        && (index ? a.index ? index->equiv(*a.index) : false : a.index == nullptr)
        && (length ? a.length ? length->equiv(*a.length) : false : a.length == nullptr)
        && (color_in ? a.color_in ? color_in->equiv(*a.color_in) : false : a.color_in == nullptr)
        && (color_out ? a.color_out ? color_out->equiv(*a.color_out) : false : a.color_out == nullptr);
    }
void IR::DpdkMeterExecuteStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(index, "index");
    v.visit(length, "length");
    v.visit(color_in, "color_in");
    v.visit(color_out, "color_out");
}
void IR::DpdkMeterExecuteStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(index, "index");
    v.visit(length, "length");
    v.visit(color_in, "color_in");
    v.visit(color_out, "color_out");
}
void IR::DpdkMeterExecuteStatement::validate() const {
#line 13850 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(index);
        CHECK_NULL(color_in);
        CHECK_NULL(color_out); }
void IR::DpdkMeterExecuteStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " meter=" << meter;
}
void IR::DpdkMeterExecuteStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"meter\" : " << this->meter;
    json << "," << std::endl << json.indent << "\"index\" : " << this->index;
    if (length != nullptr)     json << "," << std::endl << json.indent << "\"length\" : " << this->length;
    json << "," << std::endl << json.indent << "\"color_in\" : " << this->color_in;
    json << "," << std::endl << json.indent << "\"color_out\" : " << this->color_out;
}
IR::DpdkMeterExecuteStatement::DpdkMeterExecuteStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("meter", meter);
    json.load("index", index);
    json.load("length", length);
    json.load("color_in", color_in);
    json.load("color_out", color_out);
}
IR::Node * IR::DpdkMeterExecuteStatement::fromJSON(JSONLoader & json) { return new DpdkMeterExecuteStatement(json); }
IR::DpdkMeterExecuteStatement::DpdkMeterExecuteStatement(Util::SourceInfo srcInfo, cstring meter, const IR::Expression* index, const IR::Expression* length, const IR::Expression* color_in, const IR::Expression* color_out) :
    DpdkAsmStatement(srcInfo), meter(meter), index(index), length(length), color_in(color_in), color_out(color_out)
    { validate(); }
IR::DpdkMeterExecuteStatement::DpdkMeterExecuteStatement(cstring meter, const IR::Expression* index, const IR::Expression* length, const IR::Expression* color_in, const IR::Expression* color_out) :
    meter(meter), index(index), length(length), color_in(color_in), color_out(color_out)
    { validate(); }
bool IR::DpdkGetTableEntryIndex::operator==(IR::DpdkGetTableEntryIndex const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && index == a.index;
    }
bool IR::DpdkGetTableEntryIndex::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkGetTableEntryIndex &>(a_);
        return (index ? a.index ? index->equiv(*a.index) : false : a.index == nullptr);
    }
void IR::DpdkGetTableEntryIndex::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(index, "index");
}
void IR::DpdkGetTableEntryIndex::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(index, "index");
}
void IR::DpdkGetTableEntryIndex::validate() const {
#line 13900 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(index); }
void IR::DpdkGetTableEntryIndex::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"index\" : " << this->index;
}
IR::DpdkGetTableEntryIndex::DpdkGetTableEntryIndex(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("index", index);
}
IR::Node * IR::DpdkGetTableEntryIndex::fromJSON(JSONLoader & json) { return new DpdkGetTableEntryIndex(json); }
IR::DpdkGetTableEntryIndex::DpdkGetTableEntryIndex(Util::SourceInfo srcInfo, const IR::Expression* index) :
    DpdkAsmStatement(srcInfo), index(index)
    { validate(); }
IR::DpdkGetTableEntryIndex::DpdkGetTableEntryIndex(const IR::Expression* index) :
    index(index)
    { validate(); }
bool IR::DpdkCounterCountStatement::operator==(IR::DpdkCounterCountStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && counter == a.counter
        && index == a.index
        && incr == a.incr;
    }
bool IR::DpdkCounterCountStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkCounterCountStatement &>(a_);
        return counter == a.counter
        && (index ? a.index ? index->equiv(*a.index) : false : a.index == nullptr)
        && (incr ? a.incr ? incr->equiv(*a.incr) : false : a.incr == nullptr);
    }
void IR::DpdkCounterCountStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(index, "index");
    v.visit(incr, "incr");
}
void IR::DpdkCounterCountStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(index, "index");
    v.visit(incr, "incr");
}
void IR::DpdkCounterCountStatement::validate() const {
#line 13942 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(index); }
void IR::DpdkCounterCountStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " counter=" << counter;
}
void IR::DpdkCounterCountStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"counter\" : " << this->counter;
    json << "," << std::endl << json.indent << "\"index\" : " << this->index;
    if (incr != nullptr)     json << "," << std::endl << json.indent << "\"incr\" : " << this->incr;
}
IR::DpdkCounterCountStatement::DpdkCounterCountStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("counter", counter);
    json.load("index", index);
    json.load("incr", incr);
}
IR::Node * IR::DpdkCounterCountStatement::fromJSON(JSONLoader & json) { return new DpdkCounterCountStatement(json); }
IR::DpdkCounterCountStatement::DpdkCounterCountStatement(Util::SourceInfo srcInfo, cstring counter, const IR::Expression* index, const IR::Expression* incr) :
    DpdkAsmStatement(srcInfo), counter(counter), index(index), incr(incr)
    { validate(); }
IR::DpdkCounterCountStatement::DpdkCounterCountStatement(cstring counter, const IR::Expression* index, const IR::Expression* incr) :
    counter(counter), index(index), incr(incr)
    { validate(); }
IR::DpdkCounterCountStatement::DpdkCounterCountStatement(Util::SourceInfo srcInfo, cstring counter, const IR::Expression* index) :
    DpdkAsmStatement(srcInfo), counter(counter), index(index)
    { validate(); }
IR::DpdkCounterCountStatement::DpdkCounterCountStatement(cstring counter, const IR::Expression* index) :
    counter(counter), index(index)
    { validate(); }
bool IR::DpdkRegisterDeclStatement::operator==(IR::DpdkRegisterDeclStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && reg == a.reg
        && size == a.size
        && init_val == a.init_val;
    }
bool IR::DpdkRegisterDeclStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkRegisterDeclStatement &>(a_);
        return reg == a.reg
        && (size ? a.size ? size->equiv(*a.size) : false : a.size == nullptr)
        && (init_val ? a.init_val ? init_val->equiv(*a.init_val) : false : a.init_val == nullptr);
    }
void IR::DpdkRegisterDeclStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(size, "size");
    v.visit(init_val, "init_val");
}
void IR::DpdkRegisterDeclStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(size, "size");
    v.visit(init_val, "init_val");
}
void IR::DpdkRegisterDeclStatement::validate() const {
#line 13998 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(size); }
void IR::DpdkRegisterDeclStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " reg=" << reg;
}
void IR::DpdkRegisterDeclStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"reg\" : " << this->reg;
    json << "," << std::endl << json.indent << "\"size\" : " << this->size;
    if (init_val != nullptr)     json << "," << std::endl << json.indent << "\"init_val\" : " << this->init_val;
}
IR::DpdkRegisterDeclStatement::DpdkRegisterDeclStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("reg", reg);
    json.load("size", size);
    json.load("init_val", init_val);
}
IR::Node * IR::DpdkRegisterDeclStatement::fromJSON(JSONLoader & json) { return new DpdkRegisterDeclStatement(json); }
IR::DpdkRegisterDeclStatement::DpdkRegisterDeclStatement(Util::SourceInfo srcInfo, cstring reg, const IR::Expression* size, const IR::Expression* init_val) :
    DpdkAsmStatement(srcInfo), reg(reg), size(size), init_val(init_val)
    { validate(); }
IR::DpdkRegisterDeclStatement::DpdkRegisterDeclStatement(cstring reg, const IR::Expression* size, const IR::Expression* init_val) :
    reg(reg), size(size), init_val(init_val)
    { validate(); }
IR::DpdkRegisterDeclStatement::DpdkRegisterDeclStatement(Util::SourceInfo srcInfo, cstring reg, const IR::Expression* size) :
    DpdkAsmStatement(srcInfo), reg(reg), size(size)
    { validate(); }
IR::DpdkRegisterDeclStatement::DpdkRegisterDeclStatement(cstring reg, const IR::Expression* size) :
    reg(reg), size(size)
    { validate(); }
#line 501 "/home/fengyong/Desktop/p4c/backends/dpdk/dpdk.def"
IR::DpdkRegisterReadStatement::DpdkRegisterReadStatement(const IR::Expression* dst, cstring reg, const IR::Expression* index) :
        DpdkAssignmentStatement("read", dst), reg(reg), index(index) { }
#line 14032 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::DpdkRegisterReadStatement::operator==(IR::DpdkRegisterReadStatement const & a) const {
        return DpdkAssignmentStatement::operator==(static_cast<const DpdkAssignmentStatement &>(a))
        && reg == a.reg
        && index == a.index;
    }
bool IR::DpdkRegisterReadStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAssignmentStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkRegisterReadStatement &>(a_);
        return reg == a.reg
        && (index ? a.index ? index->equiv(*a.index) : false : a.index == nullptr);
    }
void IR::DpdkRegisterReadStatement::visit_children(Visitor & v) {
    DpdkAssignmentStatement::visit_children(v);
    v.visit(index, "index");
}
void IR::DpdkRegisterReadStatement::visit_children(Visitor & v) const {
    DpdkAssignmentStatement::visit_children(v);
    v.visit(index, "index");
}
void IR::DpdkRegisterReadStatement::validate() const {
#line 14054 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(index); }
void IR::DpdkRegisterReadStatement::dump_fields(std::ostream & out) const {
    DpdkAssignmentStatement::dump_fields(out);
        out << " reg=" << reg;
}
void IR::DpdkRegisterReadStatement::toJSON(JSONGenerator & json) const {
    DpdkAssignmentStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"reg\" : " << this->reg;
    json << "," << std::endl << json.indent << "\"index\" : " << this->index;
}
IR::DpdkRegisterReadStatement::DpdkRegisterReadStatement(JSONLoader & json) : DpdkAssignmentStatement(json) {
    json.load("reg", reg);
    json.load("index", index);
}
IR::Node * IR::DpdkRegisterReadStatement::fromJSON(JSONLoader & json) { return new DpdkRegisterReadStatement(json); }
bool IR::DpdkRegisterWriteStatement::operator==(IR::DpdkRegisterWriteStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && reg == a.reg
        && index == a.index
        && src == a.src;
    }
bool IR::DpdkRegisterWriteStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkRegisterWriteStatement &>(a_);
        return reg == a.reg
        && (index ? a.index ? index->equiv(*a.index) : false : a.index == nullptr)
        && (src ? a.src ? src->equiv(*a.src) : false : a.src == nullptr);
    }
void IR::DpdkRegisterWriteStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(index, "index");
    v.visit(src, "src");
}
void IR::DpdkRegisterWriteStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(index, "index");
    v.visit(src, "src");
}
void IR::DpdkRegisterWriteStatement::validate() const {
#line 14096 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(index);
        CHECK_NULL(src); }
void IR::DpdkRegisterWriteStatement::dump_fields(std::ostream & out) const {
    DpdkAsmStatement::dump_fields(out);
        out << " reg=" << reg;
}
void IR::DpdkRegisterWriteStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"reg\" : " << this->reg;
    json << "," << std::endl << json.indent << "\"index\" : " << this->index;
    json << "," << std::endl << json.indent << "\"src\" : " << this->src;
}
IR::DpdkRegisterWriteStatement::DpdkRegisterWriteStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("reg", reg);
    json.load("index", index);
    json.load("src", src);
}
IR::Node * IR::DpdkRegisterWriteStatement::fromJSON(JSONLoader & json) { return new DpdkRegisterWriteStatement(json); }
IR::DpdkRegisterWriteStatement::DpdkRegisterWriteStatement(Util::SourceInfo srcInfo, cstring reg, const IR::Expression* index, const IR::Expression* src) :
    DpdkAsmStatement(srcInfo), reg(reg), index(index), src(src)
    { validate(); }
IR::DpdkRegisterWriteStatement::DpdkRegisterWriteStatement(cstring reg, const IR::Expression* index, const IR::Expression* src) :
    reg(reg), index(index), src(src)
    { validate(); }
bool IR::DpdkValidateStatement::operator==(IR::DpdkValidateStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && header == a.header;
    }
bool IR::DpdkValidateStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkValidateStatement &>(a_);
        return (header ? a.header ? header->equiv(*a.header) : false : a.header == nullptr);
    }
void IR::DpdkValidateStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(header, "header");
}
void IR::DpdkValidateStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(header, "header");
}
void IR::DpdkValidateStatement::validate() const {
#line 14141 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(header); }
void IR::DpdkValidateStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"header\" : " << this->header;
}
IR::DpdkValidateStatement::DpdkValidateStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("header", header);
}
IR::Node * IR::DpdkValidateStatement::fromJSON(JSONLoader & json) { return new DpdkValidateStatement(json); }
IR::DpdkValidateStatement::DpdkValidateStatement(Util::SourceInfo srcInfo, const IR::Expression* header) :
    DpdkAsmStatement(srcInfo), header(header)
    { validate(); }
IR::DpdkValidateStatement::DpdkValidateStatement(const IR::Expression* header) :
    header(header)
    { validate(); }
bool IR::DpdkInvalidateStatement::operator==(IR::DpdkInvalidateStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a))
        && header == a.header;
    }
bool IR::DpdkInvalidateStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        auto &a = static_cast<const DpdkInvalidateStatement &>(a_);
        return (header ? a.header ? header->equiv(*a.header) : false : a.header == nullptr);
    }
void IR::DpdkInvalidateStatement::visit_children(Visitor & v) {
    DpdkAsmStatement::visit_children(v);
    v.visit(header, "header");
}
void IR::DpdkInvalidateStatement::visit_children(Visitor & v) const {
    DpdkAsmStatement::visit_children(v);
    v.visit(header, "header");
}
void IR::DpdkInvalidateStatement::validate() const {
#line 14177 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(header); }
void IR::DpdkInvalidateStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
    json << "," << std::endl << json.indent << "\"header\" : " << this->header;
}
IR::DpdkInvalidateStatement::DpdkInvalidateStatement(JSONLoader & json) : DpdkAsmStatement(json) {
    json.load("header", header);
}
IR::Node * IR::DpdkInvalidateStatement::fromJSON(JSONLoader & json) { return new DpdkInvalidateStatement(json); }
IR::DpdkInvalidateStatement::DpdkInvalidateStatement(Util::SourceInfo srcInfo, const IR::Expression* header) :
    DpdkAsmStatement(srcInfo), header(header)
    { validate(); }
IR::DpdkInvalidateStatement::DpdkInvalidateStatement(const IR::Expression* header) :
    header(header)
    { validate(); }
bool IR::DpdkDropStatement::operator==(IR::DpdkDropStatement const & a) const {
        return DpdkAsmStatement::operator==(static_cast<const DpdkAsmStatement &>(a));
    }
bool IR::DpdkDropStatement::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (!DpdkAsmStatement::equiv(a_)) return false;
        return true;
    }
void IR::DpdkDropStatement::toJSON(JSONGenerator & json) const {
    DpdkAsmStatement::toJSON(json);
}
IR::DpdkDropStatement::DpdkDropStatement(JSONLoader & json) : DpdkAsmStatement(json) {
}
IR::Node * IR::DpdkDropStatement::fromJSON(JSONLoader & json) { return new DpdkDropStatement(json); }
IR::DpdkDropStatement::DpdkDropStatement(Util::SourceInfo srcInfo) :
    DpdkAsmStatement(srcInfo)
    { validate(); }
IR::DpdkDropStatement::DpdkDropStatement() 
    { validate(); }

#line 23 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
cstring IR::TCKernelMetadata::toString() const {
        std::string metaName = "kernel.";
        switch (metaField) {
            case TC::SKBREDIR: {
                metaName += "skbredir";
                break;
            }
            case TC::SKBIIF: {
                metaName += "skbiif";
                break;
            }
            case TC::SKBTSTAMP: {
                metaName += "skbtstamp";
                break;
            }
            case TC::SKBPRIO: {
                metaName += "skbprio";
                break;
            }
        }
        return metaName;
    }
#line 14237 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 45 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCKernelMetadata::dbprint(std::ostream & out) const { out << toString(); }
#line 14240 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::TCKernelMetadata::operator==(IR::TCKernelMetadata const & a) const {
        return typeid(*this) == typeid(a)
        && metaField == a.metaField;
    }
bool IR::TCKernelMetadata::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const TCKernelMetadata &>(a_);
        return metaField == a.metaField;
    }
void IR::TCKernelMetadata::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " metaField=" << metaField;
}
void IR::TCKernelMetadata::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"metaField\" : " << this->metaField;
}
IR::TCKernelMetadata::TCKernelMetadata(JSONLoader & json) : Node(json) {
    json.load("metaField", metaField);
}
IR::Node * IR::TCKernelMetadata::fromJSON(JSONLoader & json) { return new TCKernelMetadata(json); }
IR::TCKernelMetadata::TCKernelMetadata(Util::SourceInfo srcInfo, unsigned metaField) :
    Node(srcInfo), metaField(metaField)
    { validate(); }
IR::TCKernelMetadata::TCKernelMetadata(unsigned metaField) :
    metaField(metaField)
    { validate(); }
#line 52 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCActionParam::setParamName(cstring pN) {
        paramName = pN;
    }
#line 14273 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 55 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCActionParam::setBitSize(unsigned bS) {
        bitSize = bS;
    }
#line 14278 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 58 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCActionParam::setDataType(unsigned d) {
        dataType = d;
    }
#line 14283 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 61 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
IR::TCActionParam::TCActionParam() {
        paramName = nullptr;
        bitSize = 0;
    }
#line 14289 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 65 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
cstring IR::TCActionParam::getParamName() const {
        return paramName;
    }
#line 14294 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 68 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
cstring IR::TCActionParam::getName() const {
        return "param." + paramName;
    }
#line 14299 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 71 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
cstring IR::TCActionParam::toString() const {
        std::string tcActionParam = "";
        tcActionParam += "\n\tparam ";
        tcActionParam += paramName;
        tcActionParam += " type ";
        switch(dataType) {
            case TC::BIT_TYPE :
                tcActionParam += "bit" + Util::toString(bitSize);
                break;
            case TC::DEV_TYPE :
                tcActionParam += "dev";
                break;
            case TC::MACADDR_TYPE :
                tcActionParam += "macaddr";
                break;
            case TC::IPV4_TYPE :
                tcActionParam += "ipv4";
                break;
            case TC::IPV6_TYPE :
                tcActionParam += "ipv6";
                break;
            case TC::BE16_TYPE :
                tcActionParam += "be16";
                break;
            case TC::BE32_TYPE :
                tcActionParam += "be32";
                break;
            case TC::BE64_TYPE :
                tcActionParam += "be64";
                break;
        }
        return tcActionParam;
    }
#line 14334 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 104 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCActionParam::dbprint(std::ostream & out) const { out << toString(); }
#line 14337 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::TCActionParam::operator==(IR::TCActionParam const & a) const {
        return typeid(*this) == typeid(a)
        && paramName == a.paramName
        && dataType == a.dataType
        && bitSize == a.bitSize;
    }
bool IR::TCActionParam::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const TCActionParam &>(a_);
        return paramName == a.paramName
        && dataType == a.dataType
        && bitSize == a.bitSize;
    }
void IR::TCActionParam::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " paramName=" << paramName;
        out << " dataType=" << dataType;
        out << " bitSize=" << bitSize;
}
void IR::TCActionParam::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"paramName\" : " << this->paramName;
    json << "," << std::endl << json.indent << "\"dataType\" : " << this->dataType;
    json << "," << std::endl << json.indent << "\"bitSize\" : " << this->bitSize;
}
IR::TCActionParam::TCActionParam(JSONLoader & json) : Node(json) {
    json.load("paramName", paramName);
    json.load("dataType", dataType);
    json.load("bitSize", bitSize);
}
IR::Node * IR::TCActionParam::fromJSON(JSONLoader & json) { return new TCActionParam(json); }
IR::TCActionParam::TCActionParam(Util::SourceInfo srcInfo, cstring paramName, unsigned dataType, unsigned bitSize) :
    Node(srcInfo), paramName(paramName), dataType(dataType), bitSize(bitSize)
    { validate(); }
IR::TCActionParam::TCActionParam(cstring paramName, unsigned dataType, unsigned bitSize) :
    paramName(paramName), dataType(dataType), bitSize(bitSize)
    { validate(); }
#line 112 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
cstring IR::TCAction::getName() const {
        cstring tcAction = pipelineName;
        tcAction += "/" + actionName;
        return tcAction;
    }
#line 14382 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 117 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCAction::setPipelineName(cstring pN) {
        pipelineName = pN;
    }
#line 14387 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 120 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCAction::addActionParams(const IR::TCActionParam* tca) {
        actionParams.push_back(tca);
    }
#line 14392 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 123 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCAction::setActionId(unsigned id) {
        actId = id;
    }
#line 14397 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 126 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
IR::TCAction::TCAction(cstring aN) {
        actionName = aN;
        pipelineName = nullptr;
        actId = 0;
    }
#line 14404 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 131 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
cstring IR::TCAction::toString() const {
        std::string tcAction = "";
        tcAction += "\n$TC p4template create action/";
        tcAction += pipelineName;
        tcAction += "/" + actionName;
        if (actId != 0) {
            tcAction += " actid " + Util::toString(actId);
        }
        if (!actionParams.empty()) {
            for (auto actParam : actionParams) {
                tcAction += " \\";
                tcAction += actParam->toString();
            }
        }
        tcAction += "\n$TC p4template update action/";
        tcAction += pipelineName;
        tcAction += "/" + actionName + " state active";

        return tcAction;
    }
#line 14426 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 151 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCAction::dbprint(std::ostream & out) const { out << toString(); }
#line 14429 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::TCAction::operator==(IR::TCAction const & a) const {
        return typeid(*this) == typeid(a)
        && actionName == a.actionName
        && pipelineName == a.pipelineName
        && actId == a.actId
        && actionParams == a.actionParams;
    }
bool IR::TCAction::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const TCAction &>(a_);
        return actionName == a.actionName
        && pipelineName == a.pipelineName
        && actId == a.actId
        && actionParams == a.actionParams;
    }
void IR::TCAction::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " actionName=" << actionName;
        out << " pipelineName=" << pipelineName;
        out << " actId=" << actId;
}
void IR::TCAction::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"actionName\" : " << this->actionName;
    json << "," << std::endl << json.indent << "\"pipelineName\" : " << this->pipelineName;
    json << "," << std::endl << json.indent << "\"actId\" : " << this->actId;
    json << "," << std::endl << json.indent << "\"actionParams\" : " << this->actionParams;
}
IR::TCAction::TCAction(JSONLoader & json) : Node(json) {
    json.load("actionName", actionName);
    json.load("pipelineName", pipelineName);
    json.load("actId", actId);
    json.load("actionParams", actionParams);
}
IR::Node * IR::TCAction::fromJSON(JSONLoader & json) { return new TCAction(json); }
IR::TCAction::TCAction(Util::SourceInfo srcInfo, cstring actionName, cstring pipelineName, unsigned actId, safe_vector<const IR::TCActionParam *> actionParams) :
    Node(srcInfo), actionName(actionName), pipelineName(pipelineName), actId(actId), actionParams(actionParams)
    { validate(); }
IR::TCAction::TCAction(cstring actionName, cstring pipelineName, unsigned actId, safe_vector<const IR::TCActionParam *> actionParams) :
    actionName(actionName), pipelineName(pipelineName), actId(actId), actionParams(actionParams)
    { validate(); }
IR::TCAction::TCAction(Util::SourceInfo srcInfo, cstring actionName, cstring pipelineName, unsigned actId) :
    Node(srcInfo), actionName(actionName), pipelineName(pipelineName), actId(actId)
    { validate(); }
IR::TCAction::TCAction(cstring actionName, cstring pipelineName, unsigned actId) :
    actionName(actionName), pipelineName(pipelineName), actId(actId)
    { validate(); }
#line 170 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCTable::setKeySize(unsigned k) {
        keySize = k;
    }
#line 14482 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 173 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCTable::setTableEntriesCount(unsigned t) {
        tableEntriesCount = t;
    }
#line 14487 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 176 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCTable::setNumMask(unsigned n) {
        numMask = n;
    }
#line 14492 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 179 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCTable::setMatchType(unsigned m) {
        matchType = m;
    }
#line 14497 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 182 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCTable::setPreaction(const IR::TCAction* p) {
        preaction = p;
    }
#line 14502 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 185 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCTable::setPostaction(const IR::TCAction* p) {
        postaction = p;
    }
#line 14507 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 188 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCTable::setDefaultHitAction(const IR::TCAction* d) {
        defaultHitAction = d;
    }
#line 14512 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 191 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCTable::setDefaultMissAction(const IR::TCAction* d) {
        defaultMissAction = d;
    }
#line 14517 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 194 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCTable::setDefaultHitConst(bool i) {
        isDefaultHitConst = i;
    }
#line 14522 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 197 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCTable::setDefaultMissConst(bool i) {
        isDefaultMissConst = i;
    }
#line 14527 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 200 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCTable::addAction(const IR::TCAction* action, unsigned flag) {
        actionList.emplace(action, flag);
    }
#line 14532 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 203 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
cstring IR::TCTable::printMatchType(unsigned matchType) const {
        cstring matchTypeString = "";
        switch(matchType) {
                case TC::EXACT_TYPE :
                    matchTypeString = "exact";
                    break;
                case TC::LPM_TYPE :
                    matchTypeString = "lpm";
                    break;
                case TC::TERNARY_TYPE :
                    matchTypeString = "ternary";
                    break;
        }
        return matchTypeString;
    }
#line 14549 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 218 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
IR::TCTable::TCTable(unsigned tId, cstring tN, cstring cN, cstring pN) {
        tableID = tId;
        tableName = tN;
        controlName = cN;
        pipelineName = pN;
        keySize = 0;
        tableEntriesCount = TC::DEFAULT_TABLE_ENTRIES;
        numMask = TC::DEFAULT_KEY_MASK;
        matchType = TC::EXACT_TYPE;
        preaction = nullptr;
        postaction = nullptr;
        defaultHitAction = nullptr;
        defaultMissAction = nullptr;
        isDefaultHitConst = false;
        isDefaultMissConst = false;
    }
#line 14567 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 234 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
cstring IR::TCTable::toString() const {
        std::string tcTable = "";
        tcTable += "\n$TC p4template create table/";
        tcTable += pipelineName + "/" + controlName + "/" + tableName + " \\";
        tcTable += "\n\ttblid " + Util::toString(tableID) + " \\";
        tcTable += "\n\ttype " + printMatchType(matchType) + " \\";
        tcTable += "\n\tkeysz " + Util::toString(keySize);
        tcTable += " nummasks " + Util::toString(numMask);
        tcTable += " tentries " + Util::toString(tableEntriesCount);

        if (!actionList.empty()) {
            tcTable += " \\";
            tcTable += "\n\ttable_acts ";
            for (auto iter = actionList.begin(); iter != actionList.end(); iter++) {
                tcTable += "act name " + iter->first->getName();
                if (iter->second == TC::TABLEONLY) {
                    tcTable += " flags tableonly";
                } else if (iter->second == TC::DEFAULTONLY) {
                    tcTable += " flags defaultonly";
                }
                if (std::next(iter) != actionList.end()) {
                    tcTable += " \\";
                    tcTable += "\n\t";
                }
            }
        }

        if (preaction != nullptr) {
            tcTable += "\n" + preaction->toString();
            tcTable += "\n$TC p4template update table/" + pipelineName
                      + "/" + controlName + "/" + tableName
                      + " preactions action " + preaction->getName();
        }
        if (postaction != nullptr) {
            tcTable += "\n" + postaction->toString();
            tcTable += "\n$TC p4template update table/" + pipelineName
                      + "/" + controlName + "/" + tableName
                      + " postactions action " + postaction->getName();
        }
        if (defaultHitAction != nullptr) {
            tcTable += "\n$TC p4template update table/" + pipelineName
                      + "/" + controlName + "/" + tableName
                      + " default_hit_action";
            if (isDefaultHitConst) {
                tcTable += " permissions 0x1024";
            }
            tcTable += " action " + defaultHitAction->getName();
        }
        if (defaultMissAction != nullptr) {
            tcTable += "\n$TC p4template update table/" + pipelineName
                      + "/" + controlName + "/" + tableName
                      + " default_miss_action";
            if (isDefaultMissConst) {
                tcTable += " permissions 0x1024";
            }
            tcTable += " action " + defaultMissAction->getName();
        }
        return tcTable;
    }
#line 14628 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 293 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCTable::dbprint(std::ostream & out) const { out << toString(); }
#line 14631 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::TCTable::operator==(IR::TCTable const & a) const {
        return typeid(*this) == typeid(a)
        && tableID == a.tableID
        && tableName == a.tableName
        && controlName == a.controlName
        && pipelineName == a.pipelineName
        && keySize == a.keySize
        && tableEntriesCount == a.tableEntriesCount
        && numMask == a.numMask
        && matchType == a.matchType
        && preaction == a.preaction
        && postaction == a.postaction
        && defaultHitAction == a.defaultHitAction
        && isDefaultHitConst == a.isDefaultHitConst
        && defaultMissAction == a.defaultMissAction
        && isDefaultMissConst == a.isDefaultMissConst
        && actionList == a.actionList;
    }
bool IR::TCTable::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const TCTable &>(a_);
        return tableID == a.tableID
        && tableName == a.tableName
        && controlName == a.controlName
        && pipelineName == a.pipelineName
        && keySize == a.keySize
        && tableEntriesCount == a.tableEntriesCount
        && numMask == a.numMask
        && matchType == a.matchType
        && (preaction ? a.preaction ? preaction->equiv(*a.preaction) : false : a.preaction == nullptr)
        && (postaction ? a.postaction ? postaction->equiv(*a.postaction) : false : a.postaction == nullptr)
        && (defaultHitAction ? a.defaultHitAction ? defaultHitAction->equiv(*a.defaultHitAction) : false : a.defaultHitAction == nullptr)
        && isDefaultHitConst == a.isDefaultHitConst
        && (defaultMissAction ? a.defaultMissAction ? defaultMissAction->equiv(*a.defaultMissAction) : false : a.defaultMissAction == nullptr)
        && isDefaultMissConst == a.isDefaultMissConst
        && actionList == a.actionList;
    }
void IR::TCTable::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(preaction, "preaction");
    v.visit(postaction, "postaction");
    v.visit(defaultHitAction, "defaultHitAction");
    v.visit(defaultMissAction, "defaultMissAction");
}
void IR::TCTable::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(preaction, "preaction");
    v.visit(postaction, "postaction");
    v.visit(defaultHitAction, "defaultHitAction");
    v.visit(defaultMissAction, "defaultMissAction");
}
void IR::TCTable::validate() const {
#line 14685 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(preaction);
        CHECK_NULL(postaction);
        CHECK_NULL(defaultHitAction);
        CHECK_NULL(defaultMissAction); }
void IR::TCTable::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " tableID=" << tableID;
        out << " tableName=" << tableName;
        out << " controlName=" << controlName;
        out << " pipelineName=" << pipelineName;
        out << " keySize=" << keySize;
        out << " tableEntriesCount=" << tableEntriesCount;
        out << " numMask=" << numMask;
        out << " matchType=" << matchType;
        out << " isDefaultHitConst=" << isDefaultHitConst;
        out << " isDefaultMissConst=" << isDefaultMissConst;
}
void IR::TCTable::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"tableID\" : " << this->tableID;
    json << "," << std::endl << json.indent << "\"tableName\" : " << this->tableName;
    json << "," << std::endl << json.indent << "\"controlName\" : " << this->controlName;
    json << "," << std::endl << json.indent << "\"pipelineName\" : " << this->pipelineName;
    json << "," << std::endl << json.indent << "\"keySize\" : " << this->keySize;
    json << "," << std::endl << json.indent << "\"tableEntriesCount\" : " << this->tableEntriesCount;
    json << "," << std::endl << json.indent << "\"numMask\" : " << this->numMask;
    json << "," << std::endl << json.indent << "\"matchType\" : " << this->matchType;
    json << "," << std::endl << json.indent << "\"preaction\" : " << this->preaction;
    json << "," << std::endl << json.indent << "\"postaction\" : " << this->postaction;
    json << "," << std::endl << json.indent << "\"defaultHitAction\" : " << this->defaultHitAction;
    json << "," << std::endl << json.indent << "\"isDefaultHitConst\" : " << this->isDefaultHitConst;
    json << "," << std::endl << json.indent << "\"defaultMissAction\" : " << this->defaultMissAction;
    json << "," << std::endl << json.indent << "\"isDefaultMissConst\" : " << this->isDefaultMissConst;
    json << "," << std::endl << json.indent << "\"actionList\" : " << this->actionList;
}
IR::TCTable::TCTable(JSONLoader & json) : Node(json) {
    json.load("tableID", tableID);
    json.load("tableName", tableName);
    json.load("controlName", controlName);
    json.load("pipelineName", pipelineName);
    json.load("keySize", keySize);
    json.load("tableEntriesCount", tableEntriesCount);
    json.load("numMask", numMask);
    json.load("matchType", matchType);
    json.load("preaction", preaction);
    json.load("postaction", postaction);
    json.load("defaultHitAction", defaultHitAction);
    json.load("isDefaultHitConst", isDefaultHitConst);
    json.load("defaultMissAction", defaultMissAction);
    json.load("isDefaultMissConst", isDefaultMissConst);
    json.load("actionList", actionList);
}
IR::Node * IR::TCTable::fromJSON(JSONLoader & json) { return new TCTable(json); }
IR::TCTable::TCTable(Util::SourceInfo srcInfo, unsigned tableID, cstring tableName, cstring controlName, cstring pipelineName, unsigned keySize, unsigned tableEntriesCount, unsigned numMask, unsigned matchType, const IR::TCAction* preaction, const IR::TCAction* postaction, const IR::TCAction* defaultHitAction, bool isDefaultHitConst, const IR::TCAction* defaultMissAction, bool isDefaultMissConst, ordered_map<const IR::TCAction *, unsigned> actionList) :
    Node(srcInfo), tableID(tableID), tableName(tableName), controlName(controlName), pipelineName(pipelineName), keySize(keySize), tableEntriesCount(tableEntriesCount), numMask(numMask), matchType(matchType), preaction(preaction), postaction(postaction), defaultHitAction(defaultHitAction), isDefaultHitConst(isDefaultHitConst), defaultMissAction(defaultMissAction), isDefaultMissConst(isDefaultMissConst), actionList(actionList)
    { validate(); }
IR::TCTable::TCTable(unsigned tableID, cstring tableName, cstring controlName, cstring pipelineName, unsigned keySize, unsigned tableEntriesCount, unsigned numMask, unsigned matchType, const IR::TCAction* preaction, const IR::TCAction* postaction, const IR::TCAction* defaultHitAction, bool isDefaultHitConst, const IR::TCAction* defaultMissAction, bool isDefaultMissConst, ordered_map<const IR::TCAction *, unsigned> actionList) :
    tableID(tableID), tableName(tableName), controlName(controlName), pipelineName(pipelineName), keySize(keySize), tableEntriesCount(tableEntriesCount), numMask(numMask), matchType(matchType), preaction(preaction), postaction(postaction), defaultHitAction(defaultHitAction), isDefaultHitConst(isDefaultHitConst), defaultMissAction(defaultMissAction), isDefaultMissConst(isDefaultMissConst), actionList(actionList)
    { validate(); }
#line 304 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCPipeline::setPipelineName(cstring pName) {
        pipelineName = pName;
    }
#line 14750 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 307 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCPipeline::setPipelineId(unsigned p) {
        pipelineId = p;
    }
#line 14755 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 310 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCPipeline::setNumTables(unsigned n) {
        numTables = n;
    }
#line 14760 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 313 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCPipeline::addActionDefinition(const IR::TCAction* actionDef) {
        actionDefs.push_back(actionDef);
    }
#line 14765 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 316 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCPipeline::addTableDefinition(const IR::TCTable* tableDef) {
        tableDefs.push_back(tableDef);
    }
#line 14770 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 319 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCPipeline::setPipelinePreAction(const IR::TCAction* action) {
        preaction = action;
    }
#line 14775 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 322 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCPipeline::setPipelinePostAction(const IR::TCAction* action) {
        postaction = action;
    }
#line 14780 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 325 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
IR::TCPipeline::TCPipeline() {
        Util::SourceInfo* srcinfo = new Util::SourceInfo();
        Node::srcInfo = *srcinfo;
        pipelineName = nullptr;
        numTables = 0;
        preaction = nullptr;
        postaction = nullptr;
    }
#line 14790 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 333 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
cstring IR::TCPipeline::toString() const {
        std::string tcCode = "#!/bin/bash -x\n";
        tcCode += "\nset -e\n";
        tcCode += "\nTC=\"tc\"";
        tcCode += "\n$TC p4template create pipeline/" + pipelineName + " pipeid ";
        tcCode += Util::toString(pipelineId);
        tcCode += " numtables ";
        tcCode += Util::toString(numTables);
        if (!actionDefs.empty()) {
            for (auto a : actionDefs) {
                tcCode += "\n" + a->toString();
            }
        }
        if (!tableDefs.empty()) {
            for (auto t : tableDefs) {
                tcCode += "\n" + t->toString();
            }
        }
        if (preaction != nullptr) {
            tcCode += "\n" + preaction->toString();
            tcCode += "\n$TC p4template update pipeline/" + pipelineName
                      + " preactions action " + pipelineName + "/preaction";
        }
        if (postaction != nullptr) {
            tcCode += "\n" + postaction->toString();
            tcCode += "\n$TC p4template update pipeline/" + pipelineName
                      + " postactions action " + pipelineName + "/postaction";
        }
        tcCode += "\n$TC p4template update pipeline/" + pipelineName + " state ready";
        return tcCode;
    }
#line 14823 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
#line 364 "/home/fengyong/Desktop/p4c/backends/tc/tc.def"
void IR::TCPipeline::dbprint(std::ostream & out) const { out << toString(); }
#line 14826 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"
bool IR::TCPipeline::operator==(IR::TCPipeline const & a) const {
        return typeid(*this) == typeid(a)
        && pipelineName == a.pipelineName
        && pipelineId == a.pipelineId
        && numTables == a.numTables
        && actionDefs == a.actionDefs
        && tableDefs == a.tableDefs
        && preaction == a.preaction
        && postaction == a.postaction;
    }
bool IR::TCPipeline::equiv(IR::Node const & a_) const {
        if (static_cast<const Node *>(this) == &a_) return true;
        if (typeid(*this) != typeid(a_)) return false;
        auto &a = static_cast<const TCPipeline &>(a_);
        return pipelineName == a.pipelineName
        && pipelineId == a.pipelineId
        && numTables == a.numTables
        && actionDefs == a.actionDefs
        && tableDefs == a.tableDefs
        && (preaction ? a.preaction ? preaction->equiv(*a.preaction) : false : a.preaction == nullptr)
        && (postaction ? a.postaction ? postaction->equiv(*a.postaction) : false : a.postaction == nullptr);
    }
void IR::TCPipeline::visit_children(Visitor & v) {
    Node::visit_children(v);
    v.visit(preaction, "preaction");
    v.visit(postaction, "postaction");
}
void IR::TCPipeline::visit_children(Visitor & v) const {
    Node::visit_children(v);
    v.visit(preaction, "preaction");
    v.visit(postaction, "postaction");
}
void IR::TCPipeline::validate() const {
#line 14860 "/home/fengyong/Desktop/p4c/build/ir/ir-generated.cpp"

        CHECK_NULL(preaction);
        CHECK_NULL(postaction); }
void IR::TCPipeline::dump_fields(std::ostream & out) const {
    Node::dump_fields(out);
        out << " pipelineName=" << pipelineName;
        out << " pipelineId=" << pipelineId;
        out << " numTables=" << numTables;
}
void IR::TCPipeline::toJSON(JSONGenerator & json) const {
    Node::toJSON(json);
    json << "," << std::endl << json.indent << "\"pipelineName\" : " << this->pipelineName;
    json << "," << std::endl << json.indent << "\"pipelineId\" : " << this->pipelineId;
    json << "," << std::endl << json.indent << "\"numTables\" : " << this->numTables;
    json << "," << std::endl << json.indent << "\"actionDefs\" : " << this->actionDefs;
    json << "," << std::endl << json.indent << "\"tableDefs\" : " << this->tableDefs;
    json << "," << std::endl << json.indent << "\"preaction\" : " << this->preaction;
    json << "," << std::endl << json.indent << "\"postaction\" : " << this->postaction;
}
IR::TCPipeline::TCPipeline(JSONLoader & json) : Node(json) {
    json.load("pipelineName", pipelineName);
    json.load("pipelineId", pipelineId);
    json.load("numTables", numTables);
    json.load("actionDefs", actionDefs);
    json.load("tableDefs", tableDefs);
    json.load("preaction", preaction);
    json.load("postaction", postaction);
}
IR::Node * IR::TCPipeline::fromJSON(JSONLoader & json) { return new TCPipeline(json); }
IR::TCPipeline::TCPipeline(Util::SourceInfo srcInfo, cstring pipelineName, unsigned pipelineId, unsigned numTables, safe_vector<const IR::TCAction *> actionDefs, safe_vector<const IR::TCTable *> tableDefs, const IR::TCAction* preaction, const IR::TCAction* postaction) :
    Node(srcInfo), pipelineName(pipelineName), pipelineId(pipelineId), numTables(numTables), actionDefs(actionDefs), tableDefs(tableDefs), preaction(preaction), postaction(postaction)
    { validate(); }
IR::TCPipeline::TCPipeline(cstring pipelineName, unsigned pipelineId, unsigned numTables, safe_vector<const IR::TCAction *> actionDefs, safe_vector<const IR::TCTable *> tableDefs, const IR::TCAction* preaction, const IR::TCAction* postaction) :
    pipelineName(pipelineName), pipelineId(pipelineId), numTables(numTables), actionDefs(actionDefs), tableDefs(tableDefs), preaction(preaction), postaction(postaction)
    { validate(); }
