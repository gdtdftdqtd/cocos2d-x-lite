
#include "CCEdgeNode.h"


// EdgeNode - init & alloc & dealloc
namespace creator {

EdgeNode::EdgeNode()
    :m_isInit(false)
    ,m_opacity(255)
    ,m_texture(nullptr)
    ,m_color(Color3B::WHITE)
{
    m_edgeSprites.clear();
    m_path.clear();
}

EdgeNode::~EdgeNode()
{
    
}
    
bool EdgeNode::initWithTexture(cocos2d::Texture2D* texture, const cocos2d::Vec2 *path, unsigned int count)
{
    if (nullptr == texture){
        return false;
    }
    this->m_texture = texture;
    this->m_path.clear();
    for (int i=0; i<count; ++i) {
        this->m_path.push_back(path[i]);
    }
    
    if (SpriteBatchNode::initWithTexture(texture, static_cast<ssize_t>(count)))
    {
        m_isInit = true;
        this->resetEdgeNodeSprite();
        return true;
    }
    return false;
}
    
void EdgeNode::resetPath(const cocos2d::Vec2 *path, unsigned int count)
{
    this->m_path.clear();
    for (int i=0; i<count; ++i) {
        this->m_path.push_back(path[i]);
    }
    this->resetEdgeNodeSprite();
}
    
void EdgeNode::resetEdgeNodeSprite()
{
    if(m_edgeSprites.size() < m_path.size()){
        for (long i=m_edgeSprites.size(); i<m_path.size(); ++i) {
            Sprite* sp = Sprite::createWithTexture(this->m_texture);
            if(sp){
                m_edgeSprites.push_back(sp);
                this->addChild(sp);
            }
        }
    }
    else if(m_edgeSprites.size() > m_path.size()){
        for (long i=m_path.size(); i<m_edgeSprites.size(); ++i) {
            m_edgeSprites[i]->setVisible(false);
        }
    }
    for (int i=0; i<m_path.size(); ++i) {
        Sprite* sp = m_edgeSprites[i];
        sp->setVisible(true);
        sp->setPosition(m_path[i]);
        sp->setOpacity(m_opacity);
        sp->setColor(m_color);
    }
}

void EdgeNode::setNodeOpacity(unsigned int opacity) {
    m_opacity = opacity;
    for (int i=0; i<m_edgeSprites.size(); ++i) {
        Sprite* sp = m_edgeSprites[i];
        if (sp) {
            sp->setOpacity(m_opacity);
        }
    }
}
    
void EdgeNode::setNodeColor(const Color3B& color){
    for (int i=0; i<m_edgeSprites.size(); ++i) {
        Sprite* sp = m_edgeSprites[i];
        if (sp) {
            sp->setColor(color);
        }
    }
}

}

