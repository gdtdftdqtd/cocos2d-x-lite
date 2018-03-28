#include "scripting/js-bindings/auto/jsb_creator_edgeNode.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "editor-support/creator/CCEdgeNode.h"

se::Object* __jsb_creator_EdgeNode_proto = nullptr;
se::Class* __jsb_creator_EdgeNode_class = nullptr;

static bool js_creator_edgeNode_EdgeNode_resetPath(se::State& s)
{
    creator::EdgeNode* cobj = (creator::EdgeNode*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_creator_edgeNode_EdgeNode_resetPath : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        const cocos2d::Vec2* arg0 = nullptr;
        unsigned int arg1 = 0;
        std::vector<cocos2d::Vec2> tempData;ok &= seval_to_std_vector_Vec2(args[0], &tempData);arg0=tempData.data();
        ok &= seval_to_uint32(args[1], (uint32_t*)&arg1);
        SE_PRECONDITION2(ok, false, "js_creator_edgeNode_EdgeNode_resetPath : Error processing arguments");
        cobj->resetPath(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_creator_edgeNode_EdgeNode_resetPath)

static bool js_creator_edgeNode_EdgeNode_initWithTexture(se::State& s)
{
    creator::EdgeNode* cobj = (creator::EdgeNode*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_creator_edgeNode_EdgeNode_initWithTexture : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        cocos2d::Texture2D* arg0 = nullptr;
        const cocos2d::Vec2* arg1 = nullptr;
        unsigned int arg2 = 0;
        ok &= seval_to_native_ptr(args[0], &arg0);
        std::vector<cocos2d::Vec2> tempData;ok &= seval_to_std_vector_Vec2(args[1], &tempData);arg1=tempData.data();
        ok &= seval_to_uint32(args[2], (uint32_t*)&arg2);
        SE_PRECONDITION2(ok, false, "js_creator_edgeNode_EdgeNode_initWithTexture : Error processing arguments");
        bool result = cobj->initWithTexture(arg0, arg1, arg2);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_creator_edgeNode_EdgeNode_initWithTexture : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_creator_edgeNode_EdgeNode_initWithTexture)

static bool js_creator_edgeNode_EdgeNode_getNodeColor(se::State& s)
{
    creator::EdgeNode* cobj = (creator::EdgeNode*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_creator_edgeNode_EdgeNode_getNodeColor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Color3B result = cobj->getNodeColor();
        ok &= Color3B_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_creator_edgeNode_EdgeNode_getNodeColor : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_creator_edgeNode_EdgeNode_getNodeColor)

static bool js_creator_edgeNode_EdgeNode_setNodeColor(se::State& s)
{
    creator::EdgeNode* cobj = (creator::EdgeNode*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_creator_edgeNode_EdgeNode_setNodeColor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Color3B arg0;
        ok &= seval_to_Color3B(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_creator_edgeNode_EdgeNode_setNodeColor : Error processing arguments");
        cobj->setNodeColor(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_creator_edgeNode_EdgeNode_setNodeColor)

static bool js_creator_edgeNode_EdgeNode_getNodeOpacity(se::State& s)
{
    creator::EdgeNode* cobj = (creator::EdgeNode*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_creator_edgeNode_EdgeNode_getNodeOpacity : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        unsigned int result = cobj->getNodeOpacity();
        ok &= uint32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_creator_edgeNode_EdgeNode_getNodeOpacity : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_creator_edgeNode_EdgeNode_getNodeOpacity)

static bool js_creator_edgeNode_EdgeNode_getIsInit(se::State& s)
{
    creator::EdgeNode* cobj = (creator::EdgeNode*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_creator_edgeNode_EdgeNode_getIsInit : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->getIsInit();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_creator_edgeNode_EdgeNode_getIsInit : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_creator_edgeNode_EdgeNode_getIsInit)

static bool js_creator_edgeNode_EdgeNode_setNodeOpacity(se::State& s)
{
    creator::EdgeNode* cobj = (creator::EdgeNode*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_creator_edgeNode_EdgeNode_setNodeOpacity : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned int arg0 = 0;
        ok &= seval_to_uint32(args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_creator_edgeNode_EdgeNode_setNodeOpacity : Error processing arguments");
        cobj->setNodeOpacity(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_creator_edgeNode_EdgeNode_setNodeOpacity)

SE_DECLARE_FINALIZE_FUNC(js_creator_EdgeNode_finalize)

static bool js_creator_edgeNode_EdgeNode_constructor(se::State& s)
{
    creator::EdgeNode* cobj = new (std::nothrow) creator::EdgeNode();
    s.thisObject()->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_creator_edgeNode_EdgeNode_constructor, __jsb_creator_EdgeNode_class, js_creator_EdgeNode_finalize)



extern se::Object* __jsb_cocos2d_SpriteBatchNode_proto;

static bool js_creator_EdgeNode_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (creator::EdgeNode)", s.nativeThisObject());
    creator::EdgeNode* cobj = (creator::EdgeNode*)s.nativeThisObject();
    if (cobj->getReferenceCount() == 1)
        cobj->autorelease();
    else
        cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_creator_EdgeNode_finalize)

bool js_register_creator_edgeNode_EdgeNode(se::Object* obj)
{
    auto cls = se::Class::create("EdgeNode", obj, __jsb_cocos2d_SpriteBatchNode_proto, _SE(js_creator_edgeNode_EdgeNode_constructor));

    cls->defineFunction("resetPath", _SE(js_creator_edgeNode_EdgeNode_resetPath));
    cls->defineFunction("initWithTexture", _SE(js_creator_edgeNode_EdgeNode_initWithTexture));
    cls->defineFunction("getNodeColor", _SE(js_creator_edgeNode_EdgeNode_getNodeColor));
    cls->defineFunction("setNodeColor", _SE(js_creator_edgeNode_EdgeNode_setNodeColor));
    cls->defineFunction("getNodeOpacity", _SE(js_creator_edgeNode_EdgeNode_getNodeOpacity));
    cls->defineFunction("getIsInit", _SE(js_creator_edgeNode_EdgeNode_getIsInit));
    cls->defineFunction("setNodeOpacity", _SE(js_creator_edgeNode_EdgeNode_setNodeOpacity));
    cls->defineFinalizeFunction(_SE(js_creator_EdgeNode_finalize));
    cls->install();
    JSBClassType::registerClass<creator::EdgeNode>(cls);

    __jsb_creator_EdgeNode_proto = cls->getProto();
    __jsb_creator_EdgeNode_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_creator_edgeNode(se::Object* obj)
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

    js_register_creator_edgeNode_EdgeNode(ns);
    return true;
}

