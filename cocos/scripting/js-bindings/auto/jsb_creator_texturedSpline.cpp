#include "scripting/js-bindings/auto/jsb_creator_texturedSpline.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "editor-support/creator/CCTexturedSplineNode.h"

se::Object* __jsb_creator_TexturedSplineNode_proto = nullptr;
se::Class* __jsb_creator_TexturedSplineNode_class = nullptr;

static bool js_creator_texturedSpline_TexturedSplineNode_setTexture(se::State& s)
{
    creator::TexturedSplineNode* cobj = (creator::TexturedSplineNode*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_creator_texturedSpline_TexturedSplineNode_setTexture : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Texture2D* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_creator_texturedSpline_TexturedSplineNode_setTexture : Error processing arguments");
        cobj->setTexture(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_creator_texturedSpline_TexturedSplineNode_setTexture)

static bool js_creator_texturedSpline_TexturedSplineNode_initWithTexture(se::State& s)
{
    creator::TexturedSplineNode* cobj = (creator::TexturedSplineNode*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_creator_texturedSpline_TexturedSplineNode_initWithTexture : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        const cocos2d::Vec2* arg0 = nullptr;
        unsigned int arg1 = 0;
        unsigned int arg2 = 0;
        cocos2d::Texture2D* arg3 = nullptr;
        std::vector<cocos2d::Vec2> tempData;ok &= seval_to_std_vector_Vec2(args[0], &tempData);arg0=tempData.data();
        ok &= seval_to_uint32(args[1], (uint32_t*)&arg1);
        ok &= seval_to_uint32(args[2], (uint32_t*)&arg2);
        ok &= seval_to_native_ptr(args[3], &arg3);
        SE_PRECONDITION2(ok, false, "js_creator_texturedSpline_TexturedSplineNode_initWithTexture : Error processing arguments");
        bool result = cobj->initWithTexture(arg0, arg1, arg2, arg3);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_creator_texturedSpline_TexturedSplineNode_initWithTexture : Error processing arguments");
        return true;
    }
    if (argc == 5) {
        const cocos2d::Vec2* arg0 = nullptr;
        unsigned int arg1 = 0;
        unsigned int arg2 = 0;
        cocos2d::Texture2D* arg3 = nullptr;
        int arg4 = 0;
        std::vector<cocos2d::Vec2> tempData;ok &= seval_to_std_vector_Vec2(args[0], &tempData);arg0=tempData.data();
        ok &= seval_to_uint32(args[1], (uint32_t*)&arg1);
        ok &= seval_to_uint32(args[2], (uint32_t*)&arg2);
        ok &= seval_to_native_ptr(args[3], &arg3);
        ok &= seval_to_int32(args[4], (int32_t*)&arg4);
        SE_PRECONDITION2(ok, false, "js_creator_texturedSpline_TexturedSplineNode_initWithTexture : Error processing arguments");
        bool result = cobj->initWithTexture(arg0, arg1, arg2, arg3, arg4);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_creator_texturedSpline_TexturedSplineNode_initWithTexture : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 5);
    return false;
}
SE_BIND_FUNC(js_creator_texturedSpline_TexturedSplineNode_initWithTexture)

static bool js_creator_texturedSpline_TexturedSplineNode_getTexture(se::State& s)
{
    creator::TexturedSplineNode* cobj = (creator::TexturedSplineNode*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_creator_texturedSpline_TexturedSplineNode_getTexture : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Texture2D* result = cobj->getTexture();
        ok &= native_ptr_to_seval<cocos2d::Texture2D>((cocos2d::Texture2D*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_creator_texturedSpline_TexturedSplineNode_getTexture : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_creator_texturedSpline_TexturedSplineNode_getTexture)

static bool js_creator_texturedSpline_TexturedSplineNode_getStrokeScale(se::State& s)
{
    creator::TexturedSplineNode* cobj = (creator::TexturedSplineNode*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_creator_texturedSpline_TexturedSplineNode_getStrokeScale : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const float& result = cobj->getStrokeScale();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_creator_texturedSpline_TexturedSplineNode_getStrokeScale : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_creator_texturedSpline_TexturedSplineNode_getStrokeScale)

static bool js_creator_texturedSpline_TexturedSplineNode_setBlendFunc(se::State& s)
{
    creator::TexturedSplineNode* cobj = (creator::TexturedSplineNode*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_creator_texturedSpline_TexturedSplineNode_setBlendFunc : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::BlendFunc arg0;
        ok &= seval_to_blendfunc(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_creator_texturedSpline_TexturedSplineNode_setBlendFunc : Error processing arguments");
        cobj->setBlendFunc(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_creator_texturedSpline_TexturedSplineNode_setBlendFunc)

static bool js_creator_texturedSpline_TexturedSplineNode_setStrokeScale(se::State& s)
{
    creator::TexturedSplineNode* cobj = (creator::TexturedSplineNode*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_creator_texturedSpline_TexturedSplineNode_setStrokeScale : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_creator_texturedSpline_TexturedSplineNode_setStrokeScale : Error processing arguments");
        cobj->setStrokeScale(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_creator_texturedSpline_TexturedSplineNode_setStrokeScale)

static bool js_creator_texturedSpline_TexturedSplineNode_initWithImagePath(se::State& s)
{
    creator::TexturedSplineNode* cobj = (creator::TexturedSplineNode*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_creator_texturedSpline_TexturedSplineNode_initWithImagePath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        const cocos2d::Vec2* arg0 = nullptr;
        unsigned int arg1 = 0;
        unsigned int arg2 = 0;
        std::string arg3;
        std::vector<cocos2d::Vec2> tempData;ok &= seval_to_std_vector_Vec2(args[0], &tempData);arg0=tempData.data();
        ok &= seval_to_uint32(args[1], (uint32_t*)&arg1);
        ok &= seval_to_uint32(args[2], (uint32_t*)&arg2);
        ok &= seval_to_std_string(args[3], &arg3);
        SE_PRECONDITION2(ok, false, "js_creator_texturedSpline_TexturedSplineNode_initWithImagePath : Error processing arguments");
        bool result = cobj->initWithImagePath(arg0, arg1, arg2, arg3);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_creator_texturedSpline_TexturedSplineNode_initWithImagePath : Error processing arguments");
        return true;
    }
    if (argc == 5) {
        const cocos2d::Vec2* arg0 = nullptr;
        unsigned int arg1 = 0;
        unsigned int arg2 = 0;
        std::string arg3;
        int arg4 = 0;
        std::vector<cocos2d::Vec2> tempData;ok &= seval_to_std_vector_Vec2(args[0], &tempData);arg0=tempData.data();
        ok &= seval_to_uint32(args[1], (uint32_t*)&arg1);
        ok &= seval_to_uint32(args[2], (uint32_t*)&arg2);
        ok &= seval_to_std_string(args[3], &arg3);
        ok &= seval_to_int32(args[4], (int32_t*)&arg4);
        SE_PRECONDITION2(ok, false, "js_creator_texturedSpline_TexturedSplineNode_initWithImagePath : Error processing arguments");
        bool result = cobj->initWithImagePath(arg0, arg1, arg2, arg3, arg4);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_creator_texturedSpline_TexturedSplineNode_initWithImagePath : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 5);
    return false;
}
SE_BIND_FUNC(js_creator_texturedSpline_TexturedSplineNode_initWithImagePath)

static bool js_creator_texturedSpline_TexturedSplineNode_getBlendFunc(se::State& s)
{
    creator::TexturedSplineNode* cobj = (creator::TexturedSplineNode*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_creator_texturedSpline_TexturedSplineNode_getBlendFunc : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const cocos2d::BlendFunc& result = cobj->getBlendFunc();
        ok &= blendfunc_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_creator_texturedSpline_TexturedSplineNode_getBlendFunc : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_creator_texturedSpline_TexturedSplineNode_getBlendFunc)

static bool js_creator_texturedSpline_TexturedSplineNode_setIsTextureRepeated(se::State& s)
{
    creator::TexturedSplineNode* cobj = (creator::TexturedSplineNode*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_creator_texturedSpline_TexturedSplineNode_setIsTextureRepeated : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_creator_texturedSpline_TexturedSplineNode_setIsTextureRepeated : Error processing arguments");
        cobj->setIsTextureRepeated(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_creator_texturedSpline_TexturedSplineNode_setIsTextureRepeated)

static bool js_creator_texturedSpline_TexturedSplineNode_getIsTextureRepeated(se::State& s)
{
    creator::TexturedSplineNode* cobj = (creator::TexturedSplineNode*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_creator_texturedSpline_TexturedSplineNode_getIsTextureRepeated : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const bool& result = cobj->getIsTextureRepeated();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_creator_texturedSpline_TexturedSplineNode_getIsTextureRepeated : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_creator_texturedSpline_TexturedSplineNode_getIsTextureRepeated)

SE_DECLARE_FINALIZE_FUNC(js_creator_TexturedSplineNode_finalize)

static bool js_creator_texturedSpline_TexturedSplineNode_constructor(se::State& s)
{
    creator::TexturedSplineNode* cobj = new (std::nothrow) creator::TexturedSplineNode();
    s.thisObject()->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_creator_texturedSpline_TexturedSplineNode_constructor, __jsb_creator_TexturedSplineNode_class, js_creator_TexturedSplineNode_finalize)

static bool js_creator_texturedSpline_TexturedSplineNode_ctor(se::State& s)
{
    creator::TexturedSplineNode* cobj = new (std::nothrow) creator::TexturedSplineNode();
    s.thisObject()->setPrivateData(cobj);
    return true;
}
SE_BIND_SUB_CLS_CTOR(js_creator_texturedSpline_TexturedSplineNode_ctor, __jsb_creator_TexturedSplineNode_class, js_creator_TexturedSplineNode_finalize)


    

extern se::Object* __jsb_cocos2d_Node_proto;

static bool js_creator_TexturedSplineNode_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (creator::TexturedSplineNode)", s.nativeThisObject());
    creator::TexturedSplineNode* cobj = (creator::TexturedSplineNode*)s.nativeThisObject();
    if (cobj->getReferenceCount() == 1)
        cobj->autorelease();
    else
        cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_creator_TexturedSplineNode_finalize)

bool js_register_creator_texturedSpline_TexturedSplineNode(se::Object* obj)
{
    auto cls = se::Class::create("TexturedSplineNode", obj, __jsb_cocos2d_Node_proto, _SE(js_creator_texturedSpline_TexturedSplineNode_constructor));

    cls->defineFunction("setTexture", _SE(js_creator_texturedSpline_TexturedSplineNode_setTexture));
    cls->defineFunction("initWithTexture", _SE(js_creator_texturedSpline_TexturedSplineNode_initWithTexture));
    cls->defineFunction("getTexture", _SE(js_creator_texturedSpline_TexturedSplineNode_getTexture));
    cls->defineFunction("getStrokeScale", _SE(js_creator_texturedSpline_TexturedSplineNode_getStrokeScale));
    cls->defineFunction("setBlendFunc", _SE(js_creator_texturedSpline_TexturedSplineNode_setBlendFunc));
    cls->defineFunction("setStrokeScale", _SE(js_creator_texturedSpline_TexturedSplineNode_setStrokeScale));
    cls->defineFunction("initWithImagePath", _SE(js_creator_texturedSpline_TexturedSplineNode_initWithImagePath));
    cls->defineFunction("getBlendFunc", _SE(js_creator_texturedSpline_TexturedSplineNode_getBlendFunc));
    cls->defineFunction("setIsTextureRepeated", _SE(js_creator_texturedSpline_TexturedSplineNode_setIsTextureRepeated));
    cls->defineFunction("getIsTextureRepeated", _SE(js_creator_texturedSpline_TexturedSplineNode_getIsTextureRepeated));
    cls->defineFunction("ctor", _SE(js_creator_texturedSpline_TexturedSplineNode_ctor));
    cls->defineFinalizeFunction(_SE(js_creator_TexturedSplineNode_finalize));
    cls->install();
    JSBClassType::registerClass<creator::TexturedSplineNode>(cls);

    __jsb_creator_TexturedSplineNode_proto = cls->getProto();
    __jsb_creator_TexturedSplineNode_class = cls;

    jsb_set_extend_property("cc", "TexturedSplineNode");
    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_creator_texturedSpline(se::Object* obj)
{
    // Get the ns
    se::Value nsVal;
    if (!obj->getProperty("cc", &nsVal))
    {
        se::HandleObject jsobj(se::Object::createPlainObject());
        nsVal.setObject(jsobj);
        obj->setProperty("cc", nsVal);
    }
    se::Object* ns = nsVal.toObject();

    js_register_creator_texturedSpline_TexturedSplineNode(ns);
    return true;
}

