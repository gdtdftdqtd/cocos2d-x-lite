
#ifndef __CCEDGE_NODE_H__
#define __CCEDGE_NODE_H__

#include "cocos2d.h"
#include "2d/CCSpriteBatchNode.h"

using namespace cocos2d;

namespace creator {
class CC_DLL EdgeNode : public cocos2d::SpriteBatchNode
{
public:
    EdgeNode();
    virtual ~EdgeNode();

    bool initWithTexture(cocos2d::Texture2D* texture, const cocos2d::Vec2 *path, unsigned int count);
    void resetPath(const cocos2d::Vec2 *path, unsigned int count);
    
    void setNodeOpacity(unsigned int opacity);
    unsigned int getNodeOpacity(){return m_opacity;}
    void setNodeColor(const cocos2d::Color3B& color);
    cocos2d::Color3B getNodeColor(){return m_color;}
    
    bool getIsInit(){return m_isInit;}
    
protected:
    void resetEdgeNodeSprite();
    
protected:
    //texture
    bool m_isInit;
    cocos2d::Texture2D* m_texture;
    unsigned int m_opacity;
    cocos2d::Color3B m_color;
    std::vector<cocos2d::Sprite*> m_edgeSprites;
    std::vector<cocos2d::Vec2> m_path;
};
}

#endif //__CCEDGE_NODE_H__

