#include "base/ccConfig.h"
#ifndef __RVO_h__
#define __RVO_h__

#include "jsapi.h"
#include "jsfriendapi.h"

extern JSClass  *jsb_CocosRVO_class;
extern JSObject *jsb_CocosRVO_prototype;

bool js_RVO_CocosRVO_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_RVO_CocosRVO_finalize(JSContext *cx, JSObject *obj);
void js_register_RVO_CocosRVO(JSContext *cx, JS::HandleObject global);
void register_all_RVO(JSContext* cx, JS::HandleObject obj);
bool js_RVO_CocosRVO_setAgentVelocity(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_setAgentRadius(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_setAgentPrefVelocity(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_setTimeStep(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_getNextObstacleVertexNo(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_setAgentDefaults(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_updateVisualization(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_getNumObstacleVertices(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_getAgentTimeHorizon(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_getTimeStep(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_doStep(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_getAgentMaxNeighbors(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_setAgentTimeHorizon(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_addObstacle(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_getAgentNumAgentNeighbors(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_getAgentRadius(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_getAgentVelocity(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_setAgentsNextPos(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_removeAgent(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_getAgentNumORCALines(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_reachedGoal(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_getAgentNeighborDist(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_setAgentMaxSpeed(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_getAgentPrefVelocity(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_setPreferredVelocities(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_setAgentMaxNeighbors(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_getNumAgents(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_getAgentMaxSpeed(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_setAgentTimeHorizonObst(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_addAgent(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_getAgentObstacleNeighbor(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_getGlobalTime(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_getObstacleVertex(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_getAgentAgentNeighbor(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_setAgentPosition(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_getAgentTimeHorizonObst(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_getAgentNumObstacleNeighbors(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_queryVisibility(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_getAgentPosition(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_processObstacles(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_getPrevObstacleVertexNo(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_release(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_setAgentNeighborDist(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_getAgentORCALine(JSContext *cx, uint32_t argc, jsval *vp);
bool js_RVO_CocosRVO_create(JSContext *cx, uint32_t argc, jsval *vp);

#endif // __RVO_h__
