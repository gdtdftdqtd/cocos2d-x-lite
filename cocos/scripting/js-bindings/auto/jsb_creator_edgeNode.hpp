#pragma once
#include "base/ccConfig.h"

#include "cocos/scripting/js-bindings/jswrapper/SeApi.h"

extern se::Object* __jsb_creator_EdgeNode_proto;
extern se::Class* __jsb_creator_EdgeNode_class;

bool js_register_creator_EdgeNode(se::Object* obj);
bool register_all_creator_edgeNode(se::Object* obj);
SE_DECLARE_FUNC(js_creator_edgeNode_EdgeNode_resetPath);
SE_DECLARE_FUNC(js_creator_edgeNode_EdgeNode_initWithTexture);
SE_DECLARE_FUNC(js_creator_edgeNode_EdgeNode_getNodeColor);
SE_DECLARE_FUNC(js_creator_edgeNode_EdgeNode_setNodeColor);
SE_DECLARE_FUNC(js_creator_edgeNode_EdgeNode_getNodeOpacity);
SE_DECLARE_FUNC(js_creator_edgeNode_EdgeNode_getIsInit);
SE_DECLARE_FUNC(js_creator_edgeNode_EdgeNode_setNodeOpacity);
SE_DECLARE_FUNC(js_creator_edgeNode_EdgeNode_EdgeNode);

