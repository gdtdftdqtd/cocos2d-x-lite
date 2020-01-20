#pragma once

NS_CC_BEGIN

class CCMTLBindingLayout : public GFXBindingLayout
{
public:
    CCMTLBindingLayout(GFXDevice* device);
    virtual ~CCMTLBindingLayout();
    
    virtual bool Initialize(const GFXBindingLayoutInfo& info) override;
    virtual void destroy() override;
    virtual void Update() override;
};

NS_CC_END