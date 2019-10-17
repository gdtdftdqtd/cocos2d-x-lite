#ifndef CC_GFXGLES3_GLES3_SAMPLER_H_
#define CC_GFXGLES3_GLES3_SAMPLER_H_

CC_NAMESPACE_BEGIN

class GLES3GPUSampler;

class CC_GLES3_API GLES3Sampler : public GFXSampler {
public:
  GLES3Sampler(GFXDevice* device);
  ~GLES3Sampler();
  
public:
  bool Initialize(const GFXSamplerInfo& info);
  void Destroy();
  
  CC_INLINE GLES3GPUSampler* gpu_sampler() const { return gpu_sampler_; }
  
private:
  GLES3GPUSampler* gpu_sampler_;
};

CC_NAMESPACE_END

#endif