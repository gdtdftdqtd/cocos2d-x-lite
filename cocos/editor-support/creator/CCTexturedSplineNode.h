
/**
 * copy http://discuss.cocos2d-x.org/t/beding-warping-sprites-by-bezier/33758/8
 */

#ifndef __CREATOR_TEXTUREDSPLINE_H__
#define __CREATOR_TEXTUREDSPLINE_H__

#include "cocos2d.h"

namespace creator {
class TexturedSplineNode : public cocos2d::Node, public cocos2d::TextureProtocol
{
public:

	enum class InterpolationType
	{
		CATMULL_ROM,
		B_CUBIC,
		LINEAR,
	};
    TexturedSplineNode();
	virtual ~TexturedSplineNode();

//    //static constructors
//    static TexturedSpline* create(std::vector<cocos2d::Vec2> *path, unsigned int count, unsigned int subvisionLevel, const std::string& imagePath, InterpolationType type = InterpolationType::CATMULL_ROM);
//    static TexturedSpline* create(std::vector<cocos2d::Vec2> *path, unsigned int count, unsigned int subvisionLevel, cocos2d::Texture2D* texture, InterpolationType type = InterpolationType::CATMULL_ROM);

	//--Node--
	void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags) override;

	//--TextureProtocol--
	virtual cocos2d::Texture2D* getTexture() const override;
	virtual void setTexture(cocos2d::Texture2D *texture) override;

	//--BlendProtocol--
	virtual void setBlendFunc(const cocos2d::BlendFunc &blendFunc) override;
	virtual const cocos2d::BlendFunc& getBlendFunc() const override;

	//--configuration--
	//scales the thickness of line and repeat rate
	CC_PROPERTY_PASS_BY_REF(float, m_strokeScale, StrokeScale);
	//true by default. The texture is repeated around the ring. Textures must be PoT for GL_REPEAT
	CC_PROPERTY_PASS_BY_REF(bool, m_isTextureRepeated, IsTextureRepeated);

public:
//    TexturedSpline();
	bool initWithImagePath(const cocos2d::Vec2 *path, unsigned int count, unsigned int subvisionLevel, const std::string& imagePath, int type = 0);
	bool initWithTexture(const cocos2d::Vec2 *path, unsigned int count, unsigned int subvisionLevel, cocos2d::Texture2D* texture, int type = 0);
    
	//texture
	cocos2d::Texture2D* m_texture;
	cocos2d::BlendFunc m_blendFunc;

	//geometry
	std::vector<cocos2d::Vec2> m_path;
	unsigned int m_subvisionLevel;
	std::vector<cocos2d::Vec2> m_vertices;
	std::vector<cocos2d::Tex2F> m_texCoords;
	
protected:
    //--helper methods--
    bool buildGeometry(std::vector<cocos2d::Vec2> path, unsigned int subvisionLevel);
    //interpolation
	InterpolationType			m_interpolationType;
	std::vector<cocos2d::Vec2>	GetInterpolatedPath(unsigned int segments = 1) const;
	cocos2d::Vec2				GetInterpolation(float t, unsigned int pointNum) const;
	static cocos2d::Vec2		GetInterpolation(InterpolationType type, float t, cocos2d::Vec2 p0, cocos2d::Vec2 p1, cocos2d::Vec2 p2, cocos2d::Vec2 p3);

	//rendering
	void onDraw(const cocos2d::Mat4 &transform, uint32_t flags);
	cocos2d::CustomCommand _customCommand;

private:
	CC_DISALLOW_COPY_AND_ASSIGN(TexturedSplineNode);
};
    
}

#endif //TEXTUREDSPLINE
