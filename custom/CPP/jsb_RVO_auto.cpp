#include "jsb_RVO_auto.hpp"
#include "scripting/js-bindings/manual/cocos2d_specifics.hpp"
#include "RVO_For_Cocos.h"

JSClass  *jsb_CocosRVO_class;
JS::PersistentRootedObject *jsb_CocosRVO_prototype;

bool js_RVO_CocosRVO_setAgentVelocity(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_setAgentVelocity : Invalid Native Object");
    if (argc == 2) {
        unsigned long arg0 = 0;
        cocos2d::Vec2 arg1;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        ok &= jsval_to_vector2(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_setAgentVelocity : Error processing arguments");
        cobj->setAgentVelocity(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_setAgentVelocity : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_RVO_CocosRVO_setAgentRadius(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_setAgentRadius : Invalid Native Object");
    if (argc == 2) {
        unsigned long arg0 = 0;
        float arg1 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        ok &= jsval_to_float(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_setAgentRadius : Error processing arguments");
        cobj->setAgentRadius(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_setAgentRadius : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_RVO_CocosRVO_setAgentPrefVelocity(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_setAgentPrefVelocity : Invalid Native Object");
    if (argc == 2) {
        unsigned long arg0 = 0;
        cocos2d::Vec2 arg1;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        ok &= jsval_to_vector2(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_setAgentPrefVelocity : Error processing arguments");
        cobj->setAgentPrefVelocity(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_setAgentPrefVelocity : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_RVO_CocosRVO_setTimeStep(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_setTimeStep : Invalid Native Object");
    if (argc == 1) {
        float arg0 = 0;
        ok &= jsval_to_float(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_setTimeStep : Error processing arguments");
        cobj->setTimeStep(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_setTimeStep : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_RVO_CocosRVO_getNextObstacleVertexNo(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_getNextObstacleVertexNo : Invalid Native Object");
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getNextObstacleVertexNo : Error processing arguments");
        unsigned long ret = cobj->getNextObstacleVertexNo(arg0);
        JS::RootedValue jsret(cx);
        ok &= ulong_to_jsval(cx, ret, &jsret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getNextObstacleVertexNo : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_getNextObstacleVertexNo : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_RVO_CocosRVO_setAgentDefaults(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_setAgentDefaults : Invalid Native Object");
    if (argc == 7) {
        float arg0 = 0;
        unsigned long arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        float arg4 = 0;
        float arg5 = 0;
        cocos2d::Vec2 arg6;
        ok &= jsval_to_float(cx, args.get(0), &arg0);
        ok &= jsval_to_ulong(cx, args.get(1), &arg1);
        ok &= jsval_to_float(cx, args.get(2), &arg2);
        ok &= jsval_to_float(cx, args.get(3), &arg3);
        ok &= jsval_to_float(cx, args.get(4), &arg4);
        ok &= jsval_to_float(cx, args.get(5), &arg5);
        ok &= jsval_to_vector2(cx, args.get(6), &arg6);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_setAgentDefaults : Error processing arguments");
        cobj->setAgentDefaults(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_setAgentDefaults : wrong number of arguments: %d, was expecting %d", argc, 7);
    return false;
}
bool js_RVO_CocosRVO_updateVisualization(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_updateVisualization : Invalid Native Object");
    if (argc == 0) {
        cobj->updateVisualization();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_updateVisualization : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_RVO_CocosRVO_getNumObstacleVertices(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_getNumObstacleVertices : Invalid Native Object");
    if (argc == 0) {
        unsigned long ret = cobj->getNumObstacleVertices();
        JS::RootedValue jsret(cx);
        ok &= ulong_to_jsval(cx, ret, &jsret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getNumObstacleVertices : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_getNumObstacleVertices : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_RVO_CocosRVO_getAgentTimeHorizon(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_getAgentTimeHorizon : Invalid Native Object");
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentTimeHorizon : Error processing arguments");
        float ret = cobj->getAgentTimeHorizon(arg0);
        JS::RootedValue jsret(cx);
        jsret = JS::NumberValue(ret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentTimeHorizon : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_getAgentTimeHorizon : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_RVO_CocosRVO_getTimeStep(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_getTimeStep : Invalid Native Object");
    if (argc == 0) {
        float ret = cobj->getTimeStep();
        JS::RootedValue jsret(cx);
        jsret = JS::NumberValue(ret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getTimeStep : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_getTimeStep : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_RVO_CocosRVO_doStep(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_doStep : Invalid Native Object");
    if (argc == 0) {
        cobj->doStep();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_doStep : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_RVO_CocosRVO_getAgentMaxNeighbors(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_getAgentMaxNeighbors : Invalid Native Object");
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentMaxNeighbors : Error processing arguments");
        unsigned long ret = cobj->getAgentMaxNeighbors(arg0);
        JS::RootedValue jsret(cx);
        ok &= ulong_to_jsval(cx, ret, &jsret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentMaxNeighbors : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_getAgentMaxNeighbors : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_RVO_CocosRVO_setAgentTimeHorizon(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_setAgentTimeHorizon : Invalid Native Object");
    if (argc == 2) {
        unsigned long arg0 = 0;
        float arg1 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        ok &= jsval_to_float(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_setAgentTimeHorizon : Error processing arguments");
        cobj->setAgentTimeHorizon(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_setAgentTimeHorizon : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_RVO_CocosRVO_addObstacle(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_addObstacle : Invalid Native Object");
    if (argc == 1) {
        std::vector<cocos2d::Vec2> arg0;
        ok &= jsval_to_std_vector_vector2(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_addObstacle : Error processing arguments");
        unsigned long ret = cobj->addObstacle(arg0);
        JS::RootedValue jsret(cx);
        ok &= ulong_to_jsval(cx, ret, &jsret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_addObstacle : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_addObstacle : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_RVO_CocosRVO_getAgentNumAgentNeighbors(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_getAgentNumAgentNeighbors : Invalid Native Object");
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentNumAgentNeighbors : Error processing arguments");
        unsigned long ret = cobj->getAgentNumAgentNeighbors(arg0);
        JS::RootedValue jsret(cx);
        ok &= ulong_to_jsval(cx, ret, &jsret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentNumAgentNeighbors : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_getAgentNumAgentNeighbors : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_RVO_CocosRVO_getAgentRadius(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_getAgentRadius : Invalid Native Object");
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentRadius : Error processing arguments");
        float ret = cobj->getAgentRadius(arg0);
        JS::RootedValue jsret(cx);
        jsret = JS::NumberValue(ret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentRadius : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_getAgentRadius : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_RVO_CocosRVO_getAgentVelocity(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_getAgentVelocity : Invalid Native Object");
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentVelocity : Error processing arguments");
        cocos2d::Vec2 ret = cobj->getAgentVelocity(arg0);
        JS::RootedValue jsret(cx);
        ok &= vector2_to_jsval(cx, ret, &jsret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentVelocity : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_getAgentVelocity : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_RVO_CocosRVO_setAgentsNextPos(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_setAgentsNextPos : Invalid Native Object");
    if (argc == 1) {
        std::vector<cocos2d::Vec2> arg0;
        ok &= jsval_to_std_vector_vector2(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_setAgentsNextPos : Error processing arguments");
        unsigned long ret = cobj->setAgentsNextPos(arg0);
        JS::RootedValue jsret(cx);
        ok &= ulong_to_jsval(cx, ret, &jsret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_setAgentsNextPos : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_setAgentsNextPos : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_RVO_CocosRVO_removeAgent(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_removeAgent : Invalid Native Object");
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_removeAgent : Error processing arguments");
        bool ret = cobj->removeAgent(arg0);
        JS::RootedValue jsret(cx);
        jsret = JS::BooleanValue(ret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_removeAgent : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_removeAgent : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_RVO_CocosRVO_getAgentNumORCALines(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_getAgentNumORCALines : Invalid Native Object");
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentNumORCALines : Error processing arguments");
        unsigned long ret = cobj->getAgentNumORCALines(arg0);
        JS::RootedValue jsret(cx);
        ok &= ulong_to_jsval(cx, ret, &jsret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentNumORCALines : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_getAgentNumORCALines : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_RVO_CocosRVO_reachedGoal(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_reachedGoal : Invalid Native Object");
    if (argc == 0) {
        std::vector<int> ret = cobj->reachedGoal();
        JS::RootedValue jsret(cx);
        ok &= std_vector_int_to_jsval(cx, ret, &jsret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_reachedGoal : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_reachedGoal : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_RVO_CocosRVO_getAgentNeighborDist(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_getAgentNeighborDist : Invalid Native Object");
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentNeighborDist : Error processing arguments");
        float ret = cobj->getAgentNeighborDist(arg0);
        JS::RootedValue jsret(cx);
        jsret = JS::NumberValue(ret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentNeighborDist : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_getAgentNeighborDist : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_RVO_CocosRVO_setAgentMaxSpeed(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_setAgentMaxSpeed : Invalid Native Object");
    if (argc == 2) {
        unsigned long arg0 = 0;
        float arg1 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        ok &= jsval_to_float(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_setAgentMaxSpeed : Error processing arguments");
        cobj->setAgentMaxSpeed(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_setAgentMaxSpeed : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_RVO_CocosRVO_getAgentPrefVelocity(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_getAgentPrefVelocity : Invalid Native Object");
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentPrefVelocity : Error processing arguments");
        cocos2d::Vec2 ret = cobj->getAgentPrefVelocity(arg0);
        JS::RootedValue jsret(cx);
        ok &= vector2_to_jsval(cx, ret, &jsret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentPrefVelocity : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_getAgentPrefVelocity : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_RVO_CocosRVO_setPreferredVelocities(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_setPreferredVelocities : Invalid Native Object");
    if (argc == 0) {
        cobj->setPreferredVelocities();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_setPreferredVelocities : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_RVO_CocosRVO_setAgentMaxNeighbors(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_setAgentMaxNeighbors : Invalid Native Object");
    if (argc == 2) {
        unsigned long arg0 = 0;
        unsigned long arg1 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        ok &= jsval_to_ulong(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_setAgentMaxNeighbors : Error processing arguments");
        cobj->setAgentMaxNeighbors(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_setAgentMaxNeighbors : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_RVO_CocosRVO_getNumAgents(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_getNumAgents : Invalid Native Object");
    if (argc == 0) {
        unsigned long ret = cobj->getNumAgents();
        JS::RootedValue jsret(cx);
        ok &= ulong_to_jsval(cx, ret, &jsret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getNumAgents : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_getNumAgents : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_RVO_CocosRVO_getAgentMaxSpeed(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_getAgentMaxSpeed : Invalid Native Object");
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentMaxSpeed : Error processing arguments");
        float ret = cobj->getAgentMaxSpeed(arg0);
        JS::RootedValue jsret(cx);
        jsret = JS::NumberValue(ret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentMaxSpeed : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_getAgentMaxSpeed : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_RVO_CocosRVO_setAgentTimeHorizonObst(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_setAgentTimeHorizonObst : Invalid Native Object");
    if (argc == 2) {
        unsigned long arg0 = 0;
        float arg1 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        ok &= jsval_to_float(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_setAgentTimeHorizonObst : Error processing arguments");
        cobj->setAgentTimeHorizonObst(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_setAgentTimeHorizonObst : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_RVO_CocosRVO_addAgent(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    bool ok = true;
    CocosRVO* cobj = nullptr;

    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx);
    obj.set(args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    cobj = (CocosRVO *)(proxy ? proxy->ptr : nullptr);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_addAgent : Invalid Native Object");
    do {
        ok = true;
        if (argc == 9) {
            cocos2d::Node* arg0 = nullptr;
            do {
                if (args.get(0).isNull()) { arg0 = nullptr; break; }
                if (!args.get(0).isObject()) { ok = false; break; }
                js_proxy_t *jsProxy;
                JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
                jsProxy = jsb_get_js_proxy(cx, tmpObj);
                arg0 = (cocos2d::Node*)(jsProxy ? jsProxy->ptr : NULL);
                JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
            } while (0);
            if (!ok) { ok = true; break; }
            cocos2d::Vec2 arg1;
            ok &= jsval_to_vector2(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            float arg2 = 0;
            ok &= jsval_to_float(cx, args.get(2), &arg2);
            if (!ok) { ok = true; break; }
            unsigned long arg3 = 0;
            ok &= jsval_to_ulong(cx, args.get(3), &arg3);
            if (!ok) { ok = true; break; }
            float arg4 = 0;
            ok &= jsval_to_float(cx, args.get(4), &arg4);
            if (!ok) { ok = true; break; }
            float arg5 = 0;
            ok &= jsval_to_float(cx, args.get(5), &arg5);
            if (!ok) { ok = true; break; }
            float arg6 = 0;
            ok &= jsval_to_float(cx, args.get(6), &arg6);
            if (!ok) { ok = true; break; }
            float arg7 = 0;
            ok &= jsval_to_float(cx, args.get(7), &arg7);
            if (!ok) { ok = true; break; }
            cocos2d::Vec2 arg8;
            ok &= jsval_to_vector2(cx, args.get(8), &arg8);
            if (!ok) { ok = true; break; }
            unsigned long ret = cobj->addAgent(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
            JS::RootedValue jsret(cx, JS::NullHandleValue);
            ok &= ulong_to_jsval(cx, ret, &jsret);
            JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_addAgent : error parsing return value");
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    do {
        ok = true;
        if (argc == 2) {
            cocos2d::Node* arg0 = nullptr;
            do {
                if (args.get(0).isNull()) { arg0 = nullptr; break; }
                if (!args.get(0).isObject()) { ok = false; break; }
                js_proxy_t *jsProxy;
                JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
                jsProxy = jsb_get_js_proxy(cx, tmpObj);
                arg0 = (cocos2d::Node*)(jsProxy ? jsProxy->ptr : NULL);
                JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
            } while (0);
            if (!ok) { ok = true; break; }
            cocos2d::Vec2 arg1;
            ok &= jsval_to_vector2(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            unsigned long ret = cobj->addAgent(arg0, arg1);
            JS::RootedValue jsret(cx, JS::NullHandleValue);
            ok &= ulong_to_jsval(cx, ret, &jsret);
            JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_addAgent : error parsing return value");
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_addAgent : arguments error");
    return false;
}
bool js_RVO_CocosRVO_getAgentObstacleNeighbor(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_getAgentObstacleNeighbor : Invalid Native Object");
    if (argc == 2) {
        unsigned long arg0 = 0;
        unsigned long arg1 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        ok &= jsval_to_ulong(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentObstacleNeighbor : Error processing arguments");
        unsigned long ret = cobj->getAgentObstacleNeighbor(arg0, arg1);
        JS::RootedValue jsret(cx);
        ok &= ulong_to_jsval(cx, ret, &jsret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentObstacleNeighbor : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_getAgentObstacleNeighbor : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_RVO_CocosRVO_getGlobalTime(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_getGlobalTime : Invalid Native Object");
    if (argc == 0) {
        float ret = cobj->getGlobalTime();
        JS::RootedValue jsret(cx);
        jsret = JS::NumberValue(ret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getGlobalTime : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_getGlobalTime : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_RVO_CocosRVO_getObstacleVertex(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_getObstacleVertex : Invalid Native Object");
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getObstacleVertex : Error processing arguments");
        cocos2d::Vec2 ret = cobj->getObstacleVertex(arg0);
        JS::RootedValue jsret(cx);
        ok &= vector2_to_jsval(cx, ret, &jsret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getObstacleVertex : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_getObstacleVertex : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_RVO_CocosRVO_getAgentAgentNeighbor(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_getAgentAgentNeighbor : Invalid Native Object");
    if (argc == 2) {
        unsigned long arg0 = 0;
        unsigned long arg1 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        ok &= jsval_to_ulong(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentAgentNeighbor : Error processing arguments");
        unsigned long ret = cobj->getAgentAgentNeighbor(arg0, arg1);
        JS::RootedValue jsret(cx);
        ok &= ulong_to_jsval(cx, ret, &jsret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentAgentNeighbor : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_getAgentAgentNeighbor : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_RVO_CocosRVO_setAgentPosition(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_setAgentPosition : Invalid Native Object");
    if (argc == 2) {
        unsigned long arg0 = 0;
        cocos2d::Vec2 arg1;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        ok &= jsval_to_vector2(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_setAgentPosition : Error processing arguments");
        cobj->setAgentPosition(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_setAgentPosition : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_RVO_CocosRVO_getAgentTimeHorizonObst(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_getAgentTimeHorizonObst : Invalid Native Object");
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentTimeHorizonObst : Error processing arguments");
        float ret = cobj->getAgentTimeHorizonObst(arg0);
        JS::RootedValue jsret(cx);
        jsret = JS::NumberValue(ret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentTimeHorizonObst : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_getAgentTimeHorizonObst : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_RVO_CocosRVO_getAgentNumObstacleNeighbors(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_getAgentNumObstacleNeighbors : Invalid Native Object");
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentNumObstacleNeighbors : Error processing arguments");
        unsigned long ret = cobj->getAgentNumObstacleNeighbors(arg0);
        JS::RootedValue jsret(cx);
        ok &= ulong_to_jsval(cx, ret, &jsret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentNumObstacleNeighbors : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_getAgentNumObstacleNeighbors : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_RVO_CocosRVO_queryVisibility(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_queryVisibility : Invalid Native Object");
    if (argc == 2) {
        cocos2d::Vec2 arg0;
        cocos2d::Vec2 arg1;
        ok &= jsval_to_vector2(cx, args.get(0), &arg0);
        ok &= jsval_to_vector2(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_queryVisibility : Error processing arguments");
        bool ret = cobj->queryVisibility(arg0, arg1);
        JS::RootedValue jsret(cx);
        jsret = JS::BooleanValue(ret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_queryVisibility : error parsing return value");
        args.rval().set(jsret);
        return true;
    }
    if (argc == 3) {
        cocos2d::Vec2 arg0;
        cocos2d::Vec2 arg1;
        float arg2 = 0;
        ok &= jsval_to_vector2(cx, args.get(0), &arg0);
        ok &= jsval_to_vector2(cx, args.get(1), &arg1);
        ok &= jsval_to_float(cx, args.get(2), &arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_queryVisibility : Error processing arguments");
        bool ret = cobj->queryVisibility(arg0, arg1, arg2);
        JS::RootedValue jsret(cx);
        jsret = JS::BooleanValue(ret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_queryVisibility : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_queryVisibility : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_RVO_CocosRVO_getAgentPosition(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_getAgentPosition : Invalid Native Object");
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentPosition : Error processing arguments");
        cocos2d::Vec2 ret = cobj->getAgentPosition(arg0);
        JS::RootedValue jsret(cx);
        ok &= vector2_to_jsval(cx, ret, &jsret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentPosition : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_getAgentPosition : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_RVO_CocosRVO_processObstacles(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_processObstacles : Invalid Native Object");
    if (argc == 0) {
        cobj->processObstacles();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_processObstacles : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_RVO_CocosRVO_getPrevObstacleVertexNo(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_getPrevObstacleVertexNo : Invalid Native Object");
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getPrevObstacleVertexNo : Error processing arguments");
        unsigned long ret = cobj->getPrevObstacleVertexNo(arg0);
        JS::RootedValue jsret(cx);
        ok &= ulong_to_jsval(cx, ret, &jsret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getPrevObstacleVertexNo : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_getPrevObstacleVertexNo : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_RVO_CocosRVO_release(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_release : Invalid Native Object");
    if (argc == 0) {
        cobj->release();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_release : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_RVO_CocosRVO_setAgentNeighborDist(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_setAgentNeighborDist : Invalid Native Object");
    if (argc == 2) {
        unsigned long arg0 = 0;
        float arg1 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        ok &= jsval_to_float(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_setAgentNeighborDist : Error processing arguments");
        cobj->setAgentNeighborDist(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_setAgentNeighborDist : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_RVO_CocosRVO_getAgentORCALine(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true; CC_UNUSED_PARAM(ok);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(cx, obj);
    CocosRVO* cobj = (CocosRVO *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_RVO_CocosRVO_getAgentORCALine : Invalid Native Object");
    if (argc == 2) {
        unsigned long arg0 = 0;
        unsigned long arg1 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        ok &= jsval_to_ulong(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentORCALine : Error processing arguments");
        std::vector<cocos2d::Vec2> ret = cobj->getAgentORCALine(arg0, arg1);
        JS::RootedValue jsret(cx);
        std_vector_vector2_to_jsval(cx, ret, &jsret);
        JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_getAgentORCALine : error parsing return value");
        args.rval().set(jsret);
        return true;
    }

    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_getAgentORCALine : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_RVO_CocosRVO_create(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    
    do {
        bool ok = true; CC_UNUSED_PARAM(ok);
        if (argc == 8) {
            float arg0 = 0;
            ok &= jsval_to_float(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            float arg1 = 0;
            ok &= jsval_to_float(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            unsigned long arg2 = 0;
            ok &= jsval_to_ulong(cx, args.get(2), &arg2);
            if (!ok) { ok = true; break; }
            float arg3 = 0;
            ok &= jsval_to_float(cx, args.get(3), &arg3);
            if (!ok) { ok = true; break; }
            float arg4 = 0;
            ok &= jsval_to_float(cx, args.get(4), &arg4);
            if (!ok) { ok = true; break; }
            float arg5 = 0;
            ok &= jsval_to_float(cx, args.get(5), &arg5);
            if (!ok) { ok = true; break; }
            float arg6 = 0;
            ok &= jsval_to_float(cx, args.get(6), &arg6);
            if (!ok) { ok = true; break; }
            cocos2d::Vec2 arg7;
            ok &= jsval_to_vector2(cx, args.get(7), &arg7);
            if (!ok) { ok = true; break; }
            CocosRVO* ret = CocosRVO::create(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
            JS::RootedValue jsret(cx, JS::NullHandleValue);
            if (ret) {
                JS::RootedObject jsretObj(cx);
                js_get_or_create_jsobject<CocosRVO>(cx, (CocosRVO*)ret, &jsretObj);
                jsret = JS::ObjectOrNullValue(jsretObj);
            } else {
                jsret = JS::NullHandleValue;
            };
            JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_create : error parsing return value");
            args.rval().set(jsret);
            return true;
        }
    } while (0);
    
    do {
        bool ok = true; CC_UNUSED_PARAM(ok);
        if (argc == 0) {
            CocosRVO* ret = CocosRVO::create();
            JS::RootedValue jsret(cx, JS::NullHandleValue);
            if (ret) {
                JS::RootedObject jsretObj(cx);
                js_get_or_create_jsobject<CocosRVO>(cx, (CocosRVO*)ret, &jsretObj);
                jsret = JS::ObjectOrNullValue(jsretObj);
            } else {
                jsret = JS::NullHandleValue;
            };
            JSB_PRECONDITION2(ok, cx, false, "js_RVO_CocosRVO_create : error parsing return value");
            args.rval().set(jsret);
            return true;
        }
    } while (0);
    JS_ReportErrorUTF8(cx, "js_RVO_CocosRVO_create : wrong number of arguments");
    return false;
}

void js_register_RVO_CocosRVO(JSContext *cx, JS::HandleObject global) {
    static const JSClassOps CocosRVO_classOps = {
        nullptr, nullptr, nullptr, nullptr,
        nullptr, nullptr, nullptr,
        nullptr,
        nullptr, nullptr, nullptr, nullptr
    };
    static JSClass CocosRVO_class = {
        "CocosRVO",
        JSCLASS_HAS_PRIVATE,
        &CocosRVO_classOps
    };
    jsb_CocosRVO_class = &CocosRVO_class;

    static JSFunctionSpec funcs[] = {
        JS_FN("setAgentVelocity", js_RVO_CocosRVO_setAgentVelocity, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAgentRadius", js_RVO_CocosRVO_setAgentRadius, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAgentPrefVelocity", js_RVO_CocosRVO_setAgentPrefVelocity, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setTimeStep", js_RVO_CocosRVO_setTimeStep, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getNextObstacleVertexNo", js_RVO_CocosRVO_getNextObstacleVertexNo, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAgentDefaults", js_RVO_CocosRVO_setAgentDefaults, 7, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("updateVisualization", js_RVO_CocosRVO_updateVisualization, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getNumObstacleVertices", js_RVO_CocosRVO_getNumObstacleVertices, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAgentTimeHorizon", js_RVO_CocosRVO_getAgentTimeHorizon, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getTimeStep", js_RVO_CocosRVO_getTimeStep, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("doStep", js_RVO_CocosRVO_doStep, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAgentMaxNeighbors", js_RVO_CocosRVO_getAgentMaxNeighbors, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAgentTimeHorizon", js_RVO_CocosRVO_setAgentTimeHorizon, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("addObstacle", js_RVO_CocosRVO_addObstacle, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAgentNumAgentNeighbors", js_RVO_CocosRVO_getAgentNumAgentNeighbors, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAgentRadius", js_RVO_CocosRVO_getAgentRadius, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAgentVelocity", js_RVO_CocosRVO_getAgentVelocity, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAgentsNextPos", js_RVO_CocosRVO_setAgentsNextPos, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("removeAgent", js_RVO_CocosRVO_removeAgent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAgentNumORCALines", js_RVO_CocosRVO_getAgentNumORCALines, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("reachedGoal", js_RVO_CocosRVO_reachedGoal, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAgentNeighborDist", js_RVO_CocosRVO_getAgentNeighborDist, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAgentMaxSpeed", js_RVO_CocosRVO_setAgentMaxSpeed, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAgentPrefVelocity", js_RVO_CocosRVO_getAgentPrefVelocity, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setPreferredVelocities", js_RVO_CocosRVO_setPreferredVelocities, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAgentMaxNeighbors", js_RVO_CocosRVO_setAgentMaxNeighbors, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getNumAgents", js_RVO_CocosRVO_getNumAgents, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAgentMaxSpeed", js_RVO_CocosRVO_getAgentMaxSpeed, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAgentTimeHorizonObst", js_RVO_CocosRVO_setAgentTimeHorizonObst, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("addAgent", js_RVO_CocosRVO_addAgent, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAgentObstacleNeighbor", js_RVO_CocosRVO_getAgentObstacleNeighbor, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getGlobalTime", js_RVO_CocosRVO_getGlobalTime, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getObstacleVertex", js_RVO_CocosRVO_getObstacleVertex, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAgentAgentNeighbor", js_RVO_CocosRVO_getAgentAgentNeighbor, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAgentPosition", js_RVO_CocosRVO_setAgentPosition, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAgentTimeHorizonObst", js_RVO_CocosRVO_getAgentTimeHorizonObst, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAgentNumObstacleNeighbors", js_RVO_CocosRVO_getAgentNumObstacleNeighbors, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("queryVisibility", js_RVO_CocosRVO_queryVisibility, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAgentPosition", js_RVO_CocosRVO_getAgentPosition, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("processObstacles", js_RVO_CocosRVO_processObstacles, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getPrevObstacleVertexNo", js_RVO_CocosRVO_getPrevObstacleVertexNo, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("release", js_RVO_CocosRVO_release, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAgentNeighborDist", js_RVO_CocosRVO_setAgentNeighborDist, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAgentORCALine", js_RVO_CocosRVO_getAgentORCALine, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("create", js_RVO_CocosRVO_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JS::RootedObject parent_proto(cx, nullptr);
    JS::RootedObject proto(cx, JS_InitClass(
        cx, global,
        parent_proto,
        jsb_CocosRVO_class,
        dummy_constructor<CocosRVO>, 0,
        nullptr,
        funcs,
        nullptr,
        st_funcs));

    // add the proto and JSClass to the type->js info hash table
    js_type_class_t *typeClass = jsb_register_class<CocosRVO>(cx, jsb_CocosRVO_class, proto);
    jsb_CocosRVO_prototype = typeClass->proto;
    JS::RootedValue className(cx);
    std_string_to_jsval(cx, "CocosRVO", &className);
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
}

void register_all_RVO(JSContext* cx, JS::HandleObject obj) {
    // Get the ns
    JS::RootedObject ns(cx);
    get_or_create_js_obj(cx, obj, "RVO", &ns);

    js_register_RVO_CocosRVO(cx, ns);
}

