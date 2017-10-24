#include "jsb_RVO_auto.hpp"
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "RVO_For_Cocos.h"

se::Object* __jsb_CocosRVO_proto = nullptr;
se::Class* __jsb_CocosRVO_class = nullptr;

static bool js_RVO_CocosRVO_setAgentVelocity(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_setAgentVelocity : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        unsigned long arg0 = 0;
        cocos2d::Vec2 arg1;
        ok &= seval_to_ulong(args[0], &arg0);
        ok &= seval_to_Vec2(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_setAgentVelocity : Error processing arguments");
        cobj->setAgentVelocity(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_setAgentVelocity)

static bool js_RVO_CocosRVO_setAgentRadius(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_setAgentRadius : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        unsigned long arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_ulong(args[0], &arg0);
        ok &= seval_to_float(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_setAgentRadius : Error processing arguments");
        cobj->setAgentRadius(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_setAgentRadius)

static bool js_RVO_CocosRVO_setAgentPrefVelocity(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_setAgentPrefVelocity : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        unsigned long arg0 = 0;
        cocos2d::Vec2 arg1;
        ok &= seval_to_ulong(args[0], &arg0);
        ok &= seval_to_Vec2(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_setAgentPrefVelocity : Error processing arguments");
        cobj->setAgentPrefVelocity(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_setAgentPrefVelocity)

static bool js_RVO_CocosRVO_setTimeStep(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_setTimeStep : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_setTimeStep : Error processing arguments");
        cobj->setTimeStep(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_setTimeStep)

static bool js_RVO_CocosRVO_getNextObstacleVertexNo(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_getNextObstacleVertexNo : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= seval_to_ulong(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getNextObstacleVertexNo : Error processing arguments");
        unsigned long result = cobj->getNextObstacleVertexNo(arg0);
        ok &= ulong_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getNextObstacleVertexNo : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_getNextObstacleVertexNo)

static bool js_RVO_CocosRVO_setAgentDefaults(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_setAgentDefaults : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 7) {
        float arg0 = 0;
        unsigned long arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        float arg4 = 0;
        float arg5 = 0;
        cocos2d::Vec2 arg6;
        ok &= seval_to_float(args[0], &arg0);
        ok &= seval_to_ulong(args[1], &arg1);
        ok &= seval_to_float(args[2], &arg2);
        ok &= seval_to_float(args[3], &arg3);
        ok &= seval_to_float(args[4], &arg4);
        ok &= seval_to_float(args[5], &arg5);
        ok &= seval_to_Vec2(args[6], &arg6);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_setAgentDefaults : Error processing arguments");
        cobj->setAgentDefaults(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 7);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_setAgentDefaults)

static bool js_RVO_CocosRVO_updateVisualization(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_updateVisualization : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->updateVisualization();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_updateVisualization)

static bool js_RVO_CocosRVO_getNumObstacleVertices(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_getNumObstacleVertices : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        unsigned long result = cobj->getNumObstacleVertices();
        ok &= ulong_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getNumObstacleVertices : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_getNumObstacleVertices)

static bool js_RVO_CocosRVO_getAgentTimeHorizon(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_getAgentTimeHorizon : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= seval_to_ulong(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentTimeHorizon : Error processing arguments");
        float result = cobj->getAgentTimeHorizon(arg0);
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentTimeHorizon : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_getAgentTimeHorizon)

static bool js_RVO_CocosRVO_getTimeStep(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_getTimeStep : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getTimeStep();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getTimeStep : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_getTimeStep)

static bool js_RVO_CocosRVO_doStep(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_doStep : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->doStep();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_doStep)

static bool js_RVO_CocosRVO_getAgentMaxNeighbors(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_getAgentMaxNeighbors : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= seval_to_ulong(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentMaxNeighbors : Error processing arguments");
        unsigned long result = cobj->getAgentMaxNeighbors(arg0);
        ok &= ulong_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentMaxNeighbors : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_getAgentMaxNeighbors)

static bool js_RVO_CocosRVO_setAgentTimeHorizon(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_setAgentTimeHorizon : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        unsigned long arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_ulong(args[0], &arg0);
        ok &= seval_to_float(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_setAgentTimeHorizon : Error processing arguments");
        cobj->setAgentTimeHorizon(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_setAgentTimeHorizon)

static bool js_RVO_CocosRVO_addObstacle(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_addObstacle : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::vector<cocos2d::Vec2, std::allocator<cocos2d::Vec2> > arg0;
        std::vector<cocos2d::Vec2> tempData;ok &= seval_to_std_vector_cocos_Vec2(args[0], &tempData);arg0=tempData;
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_addObstacle : Error processing arguments");
        unsigned long result = cobj->addObstacle(arg0);
        ok &= ulong_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_addObstacle : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_addObstacle)

static bool js_RVO_CocosRVO_getAgentNumAgentNeighbors(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_getAgentNumAgentNeighbors : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= seval_to_ulong(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentNumAgentNeighbors : Error processing arguments");
        unsigned long result = cobj->getAgentNumAgentNeighbors(arg0);
        ok &= ulong_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentNumAgentNeighbors : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_getAgentNumAgentNeighbors)

static bool js_RVO_CocosRVO_getAgentRadius(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_getAgentRadius : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= seval_to_ulong(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentRadius : Error processing arguments");
        float result = cobj->getAgentRadius(arg0);
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentRadius : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_getAgentRadius)

static bool js_RVO_CocosRVO_getAgentVelocity(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_getAgentVelocity : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= seval_to_ulong(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentVelocity : Error processing arguments");
        cocos2d::Vec2 result = cobj->getAgentVelocity(arg0);
        ok &= Vec2_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentVelocity : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_getAgentVelocity)

static bool js_RVO_CocosRVO_setAgentsNextPos(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_setAgentsNextPos : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        std::vector<cocos2d::Vec2, std::allocator<cocos2d::Vec2> > arg0;
        std::vector<cocos2d::Vec2> tempData;ok &= seval_to_std_vector_cocos_Vec2(args[0], &tempData);arg0=tempData;
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_setAgentsNextPos : Error processing arguments");
        unsigned long result = cobj->setAgentsNextPos(arg0);
        ok &= ulong_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_setAgentsNextPos : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_setAgentsNextPos)

static bool js_RVO_CocosRVO_removeAgent(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_removeAgent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= seval_to_ulong(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_removeAgent : Error processing arguments");
        bool result = cobj->removeAgent(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_removeAgent : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_removeAgent)

static bool js_RVO_CocosRVO_getAgentNumORCALines(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_getAgentNumORCALines : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= seval_to_ulong(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentNumORCALines : Error processing arguments");
        unsigned long result = cobj->getAgentNumORCALines(arg0);
        ok &= ulong_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentNumORCALines : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_getAgentNumORCALines)

static bool js_RVO_CocosRVO_reachedGoal(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_reachedGoal : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::vector<int> result = cobj->reachedGoal();
        ok &= std_vector_int_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_reachedGoal : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_reachedGoal)

static bool js_RVO_CocosRVO_getAgentNeighborDist(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_getAgentNeighborDist : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= seval_to_ulong(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentNeighborDist : Error processing arguments");
        float result = cobj->getAgentNeighborDist(arg0);
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentNeighborDist : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_getAgentNeighborDist)

static bool js_RVO_CocosRVO_setAgentMaxSpeed(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_setAgentMaxSpeed : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        unsigned long arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_ulong(args[0], &arg0);
        ok &= seval_to_float(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_setAgentMaxSpeed : Error processing arguments");
        cobj->setAgentMaxSpeed(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_setAgentMaxSpeed)

static bool js_RVO_CocosRVO_getAgentPrefVelocity(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_getAgentPrefVelocity : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= seval_to_ulong(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentPrefVelocity : Error processing arguments");
        cocos2d::Vec2 result = cobj->getAgentPrefVelocity(arg0);
        ok &= Vec2_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentPrefVelocity : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_getAgentPrefVelocity)

static bool js_RVO_CocosRVO_setPreferredVelocities(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_setPreferredVelocities : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->setPreferredVelocities();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_setPreferredVelocities)

static bool js_RVO_CocosRVO_setAgentMaxNeighbors(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_setAgentMaxNeighbors : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        unsigned long arg0 = 0;
        unsigned long arg1 = 0;
        ok &= seval_to_ulong(args[0], &arg0);
        ok &= seval_to_ulong(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_setAgentMaxNeighbors : Error processing arguments");
        cobj->setAgentMaxNeighbors(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_setAgentMaxNeighbors)

static bool js_RVO_CocosRVO_getNumAgents(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_getNumAgents : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        unsigned long result = cobj->getNumAgents();
        ok &= ulong_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getNumAgents : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_getNumAgents)

static bool js_RVO_CocosRVO_getAgentMaxSpeed(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_getAgentMaxSpeed : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= seval_to_ulong(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentMaxSpeed : Error processing arguments");
        float result = cobj->getAgentMaxSpeed(arg0);
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentMaxSpeed : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_getAgentMaxSpeed)

static bool js_RVO_CocosRVO_setAgentTimeHorizonObst(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_setAgentTimeHorizonObst : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        unsigned long arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_ulong(args[0], &arg0);
        ok &= seval_to_float(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_setAgentTimeHorizonObst : Error processing arguments");
        cobj->setAgentTimeHorizonObst(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_setAgentTimeHorizonObst)

static bool js_RVO_CocosRVO_addAgent(se::State& s)
{
    CC_UNUSED bool ok = true;
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2( cobj, false, "js_RVO_CocosRVO_addAgent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 9) {
            cocos2d::Node* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Vec2 arg1;
            ok &= seval_to_Vec2(args[1], &arg1);
            if (!ok) { ok = true; break; }
            float arg2 = 0;
            ok &= seval_to_float(args[2], &arg2);
            if (!ok) { ok = true; break; }
            unsigned long arg3 = 0;
            ok &= seval_to_ulong(args[3], &arg3);
            if (!ok) { ok = true; break; }
            float arg4 = 0;
            ok &= seval_to_float(args[4], &arg4);
            if (!ok) { ok = true; break; }
            float arg5 = 0;
            ok &= seval_to_float(args[5], &arg5);
            if (!ok) { ok = true; break; }
            float arg6 = 0;
            ok &= seval_to_float(args[6], &arg6);
            if (!ok) { ok = true; break; }
            float arg7 = 0;
            ok &= seval_to_float(args[7], &arg7);
            if (!ok) { ok = true; break; }
            cocos2d::Vec2 arg8;
            ok &= seval_to_Vec2(args[8], &arg8);
            if (!ok) { ok = true; break; }
            unsigned long result = cobj->addAgent(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
            ok &= ulong_to_seval(result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_addAgent : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 2) {
            cocos2d::Node* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Vec2 arg1;
            ok &= seval_to_Vec2(args[1], &arg1);
            if (!ok) { ok = true; break; }
            unsigned long result = cobj->addAgent(arg0, arg1);
            ok &= ulong_to_seval(result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_addAgent : Error processing arguments");
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_addAgent)

static bool js_RVO_CocosRVO_getAgentObstacleNeighbor(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_getAgentObstacleNeighbor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        unsigned long arg0 = 0;
        unsigned long arg1 = 0;
        ok &= seval_to_ulong(args[0], &arg0);
        ok &= seval_to_ulong(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentObstacleNeighbor : Error processing arguments");
        unsigned long result = cobj->getAgentObstacleNeighbor(arg0, arg1);
        ok &= ulong_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentObstacleNeighbor : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_getAgentObstacleNeighbor)

static bool js_RVO_CocosRVO_getGlobalTime(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_getGlobalTime : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getGlobalTime();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getGlobalTime : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_getGlobalTime)

static bool js_RVO_CocosRVO_getObstacleVertex(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_getObstacleVertex : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= seval_to_ulong(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getObstacleVertex : Error processing arguments");
        cocos2d::Vec2 result = cobj->getObstacleVertex(arg0);
        ok &= Vec2_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getObstacleVertex : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_getObstacleVertex)

static bool js_RVO_CocosRVO_getAgentAgentNeighbor(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_getAgentAgentNeighbor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        unsigned long arg0 = 0;
        unsigned long arg1 = 0;
        ok &= seval_to_ulong(args[0], &arg0);
        ok &= seval_to_ulong(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentAgentNeighbor : Error processing arguments");
        unsigned long result = cobj->getAgentAgentNeighbor(arg0, arg1);
        ok &= ulong_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentAgentNeighbor : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_getAgentAgentNeighbor)

static bool js_RVO_CocosRVO_setAgentPosition(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_setAgentPosition : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        unsigned long arg0 = 0;
        cocos2d::Vec2 arg1;
        ok &= seval_to_ulong(args[0], &arg0);
        ok &= seval_to_Vec2(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_setAgentPosition : Error processing arguments");
        cobj->setAgentPosition(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_setAgentPosition)

static bool js_RVO_CocosRVO_getAgentTimeHorizonObst(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_getAgentTimeHorizonObst : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= seval_to_ulong(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentTimeHorizonObst : Error processing arguments");
        float result = cobj->getAgentTimeHorizonObst(arg0);
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentTimeHorizonObst : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_getAgentTimeHorizonObst)

static bool js_RVO_CocosRVO_getAgentNumObstacleNeighbors(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_getAgentNumObstacleNeighbors : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= seval_to_ulong(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentNumObstacleNeighbors : Error processing arguments");
        unsigned long result = cobj->getAgentNumObstacleNeighbors(arg0);
        ok &= ulong_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentNumObstacleNeighbors : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_getAgentNumObstacleNeighbors)

static bool js_RVO_CocosRVO_queryVisibility(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_queryVisibility : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        cocos2d::Vec2 arg0;
        cocos2d::Vec2 arg1;
        ok &= seval_to_Vec2(args[0], &arg0);
        ok &= seval_to_Vec2(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_queryVisibility : Error processing arguments");
        bool result = cobj->queryVisibility(arg0, arg1);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_queryVisibility : Error processing arguments");
        return true;
    }
    if (argc == 3) {
        cocos2d::Vec2 arg0;
        cocos2d::Vec2 arg1;
        float arg2 = 0;
        ok &= seval_to_Vec2(args[0], &arg0);
        ok &= seval_to_Vec2(args[1], &arg1);
        ok &= seval_to_float(args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_queryVisibility : Error processing arguments");
        bool result = cobj->queryVisibility(arg0, arg1, arg2);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_queryVisibility : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_queryVisibility)

static bool js_RVO_CocosRVO_getAgentPosition(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_getAgentPosition : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= seval_to_ulong(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentPosition : Error processing arguments");
        cocos2d::Vec2 result = cobj->getAgentPosition(arg0);
        ok &= Vec2_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentPosition : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_getAgentPosition)

static bool js_RVO_CocosRVO_processObstacles(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_processObstacles : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->processObstacles();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_processObstacles)

static bool js_RVO_CocosRVO_getPrevObstacleVertexNo(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_getPrevObstacleVertexNo : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= seval_to_ulong(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getPrevObstacleVertexNo : Error processing arguments");
        unsigned long result = cobj->getPrevObstacleVertexNo(arg0);
        ok &= ulong_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getPrevObstacleVertexNo : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_getPrevObstacleVertexNo)

static bool js_RVO_CocosRVO_release(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_release : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->release();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_release)

static bool js_RVO_CocosRVO_setAgentNeighborDist(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_setAgentNeighborDist : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        unsigned long arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_ulong(args[0], &arg0);
        ok &= seval_to_float(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_setAgentNeighborDist : Error processing arguments");
        cobj->setAgentNeighborDist(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_setAgentNeighborDist)

static bool js_RVO_CocosRVO_getAgentORCALine(se::State& s)
{
    CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_RVO_CocosRVO_getAgentORCALine : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        unsigned long arg0 = 0;
        unsigned long arg1 = 0;
        ok &= seval_to_ulong(args[0], &arg0);
        ok &= seval_to_ulong(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentORCALine : Error processing arguments");
        std::vector<cocos2d::Vec2, std::allocator<cocos2d::Vec2> > result = cobj->getAgentORCALine(arg0, arg1);
        ok &= std_vector_Vec2_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_getAgentORCALine : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_getAgentORCALine)

static bool js_RVO_CocosRVO_create(se::State& s)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 8) {
            float arg0 = 0;
            ok &= seval_to_float(args[0], &arg0);
            if (!ok) { ok = true; break; }
            float arg1 = 0;
            ok &= seval_to_float(args[1], &arg1);
            if (!ok) { ok = true; break; }
            unsigned long arg2 = 0;
            ok &= seval_to_ulong(args[2], &arg2);
            if (!ok) { ok = true; break; }
            float arg3 = 0;
            ok &= seval_to_float(args[3], &arg3);
            if (!ok) { ok = true; break; }
            float arg4 = 0;
            ok &= seval_to_float(args[4], &arg4);
            if (!ok) { ok = true; break; }
            float arg5 = 0;
            ok &= seval_to_float(args[5], &arg5);
            if (!ok) { ok = true; break; }
            float arg6 = 0;
            ok &= seval_to_float(args[6], &arg6);
            if (!ok) { ok = true; break; }
            cocos2d::Vec2 arg7;
            ok &= seval_to_Vec2(args[7], &arg7);
            if (!ok) { ok = true; break; }
            CocosRVO* result = CocosRVO::create(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
            ok &= native_ptr_to_seval<CocosRVO>((CocosRVO*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 0) {
            CocosRVO* result = CocosRVO::create();
            ok &= native_ptr_to_seval<CocosRVO>((CocosRVO*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_RVO_CocosRVO_create : Error processing arguments");
            return true;
        }
    } while (false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_RVO_CocosRVO_create)



static bool js_CocosRVO_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (CocosRVO)", s.nativeThisObject());
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(s.nativeThisObject());
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        CocosRVO* cobj = (CocosRVO*)s.nativeThisObject();
        delete cobj;
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_CocosRVO_finalize)

bool js_register_RVO_CocosRVO(se::Object* obj)
{
    auto cls = se::Class::create("CocosRVO", obj, nullptr, nullptr);

    cls->defineFunction("setAgentVelocity", _SE(js_RVO_CocosRVO_setAgentVelocity));
    cls->defineFunction("setAgentRadius", _SE(js_RVO_CocosRVO_setAgentRadius));
    cls->defineFunction("setAgentPrefVelocity", _SE(js_RVO_CocosRVO_setAgentPrefVelocity));
    cls->defineFunction("setTimeStep", _SE(js_RVO_CocosRVO_setTimeStep));
    cls->defineFunction("getNextObstacleVertexNo", _SE(js_RVO_CocosRVO_getNextObstacleVertexNo));
    cls->defineFunction("setAgentDefaults", _SE(js_RVO_CocosRVO_setAgentDefaults));
    cls->defineFunction("updateVisualization", _SE(js_RVO_CocosRVO_updateVisualization));
    cls->defineFunction("getNumObstacleVertices", _SE(js_RVO_CocosRVO_getNumObstacleVertices));
    cls->defineFunction("getAgentTimeHorizon", _SE(js_RVO_CocosRVO_getAgentTimeHorizon));
    cls->defineFunction("getTimeStep", _SE(js_RVO_CocosRVO_getTimeStep));
    cls->defineFunction("doStep", _SE(js_RVO_CocosRVO_doStep));
    cls->defineFunction("getAgentMaxNeighbors", _SE(js_RVO_CocosRVO_getAgentMaxNeighbors));
    cls->defineFunction("setAgentTimeHorizon", _SE(js_RVO_CocosRVO_setAgentTimeHorizon));
    cls->defineFunction("addObstacle", _SE(js_RVO_CocosRVO_addObstacle));
    cls->defineFunction("getAgentNumAgentNeighbors", _SE(js_RVO_CocosRVO_getAgentNumAgentNeighbors));
    cls->defineFunction("getAgentRadius", _SE(js_RVO_CocosRVO_getAgentRadius));
    cls->defineFunction("getAgentVelocity", _SE(js_RVO_CocosRVO_getAgentVelocity));
    cls->defineFunction("setAgentsNextPos", _SE(js_RVO_CocosRVO_setAgentsNextPos));
    cls->defineFunction("removeAgent", _SE(js_RVO_CocosRVO_removeAgent));
    cls->defineFunction("getAgentNumORCALines", _SE(js_RVO_CocosRVO_getAgentNumORCALines));
    cls->defineFunction("reachedGoal", _SE(js_RVO_CocosRVO_reachedGoal));
    cls->defineFunction("getAgentNeighborDist", _SE(js_RVO_CocosRVO_getAgentNeighborDist));
    cls->defineFunction("setAgentMaxSpeed", _SE(js_RVO_CocosRVO_setAgentMaxSpeed));
    cls->defineFunction("getAgentPrefVelocity", _SE(js_RVO_CocosRVO_getAgentPrefVelocity));
    cls->defineFunction("setPreferredVelocities", _SE(js_RVO_CocosRVO_setPreferredVelocities));
    cls->defineFunction("setAgentMaxNeighbors", _SE(js_RVO_CocosRVO_setAgentMaxNeighbors));
    cls->defineFunction("getNumAgents", _SE(js_RVO_CocosRVO_getNumAgents));
    cls->defineFunction("getAgentMaxSpeed", _SE(js_RVO_CocosRVO_getAgentMaxSpeed));
    cls->defineFunction("setAgentTimeHorizonObst", _SE(js_RVO_CocosRVO_setAgentTimeHorizonObst));
    cls->defineFunction("addAgent", _SE(js_RVO_CocosRVO_addAgent));
    cls->defineFunction("getAgentObstacleNeighbor", _SE(js_RVO_CocosRVO_getAgentObstacleNeighbor));
    cls->defineFunction("getGlobalTime", _SE(js_RVO_CocosRVO_getGlobalTime));
    cls->defineFunction("getObstacleVertex", _SE(js_RVO_CocosRVO_getObstacleVertex));
    cls->defineFunction("getAgentAgentNeighbor", _SE(js_RVO_CocosRVO_getAgentAgentNeighbor));
    cls->defineFunction("setAgentPosition", _SE(js_RVO_CocosRVO_setAgentPosition));
    cls->defineFunction("getAgentTimeHorizonObst", _SE(js_RVO_CocosRVO_getAgentTimeHorizonObst));
    cls->defineFunction("getAgentNumObstacleNeighbors", _SE(js_RVO_CocosRVO_getAgentNumObstacleNeighbors));
    cls->defineFunction("queryVisibility", _SE(js_RVO_CocosRVO_queryVisibility));
    cls->defineFunction("getAgentPosition", _SE(js_RVO_CocosRVO_getAgentPosition));
    cls->defineFunction("processObstacles", _SE(js_RVO_CocosRVO_processObstacles));
    cls->defineFunction("getPrevObstacleVertexNo", _SE(js_RVO_CocosRVO_getPrevObstacleVertexNo));
    cls->defineFunction("release", _SE(js_RVO_CocosRVO_release));
    cls->defineFunction("setAgentNeighborDist", _SE(js_RVO_CocosRVO_setAgentNeighborDist));
    cls->defineFunction("getAgentORCALine", _SE(js_RVO_CocosRVO_getAgentORCALine));
    cls->defineStaticFunction("create", _SE(js_RVO_CocosRVO_create));
    cls->defineFinalizeFunction(_SE(js_CocosRVO_finalize));
    cls->install();
    JSBClassType::registerClass<CocosRVO>(cls);

    __jsb_CocosRVO_proto = cls->getProto();
    __jsb_CocosRVO_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_RVO(se::Object* obj)
{
    // Get the ns
    se::Value nsVal;
    if (!obj->getProperty("RVO", &nsVal))
    {
        se::HandleObject jsobj(se::Object::createPlainObject());
        nsVal.setObject(jsobj);
        obj->setProperty("RVO", nsVal);
    }
    se::Object* ns = nsVal.toObject();

    js_register_RVO_CocosRVO(ns);
    return true;
}

