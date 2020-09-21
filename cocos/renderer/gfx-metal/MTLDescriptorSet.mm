#include "MTLStd.h"

#include "MTLBuffer.h"
#include "MTLDescriptorSet.h"
#include "MTLGPUObjects.h"
#include "MTLSampler.h"
#include "MTLTexture.h"
#include "MTLDescriptorSetLayout.h"

namespace cc {
namespace gfx {
CCMTLDescriptorSet::CCMTLDescriptorSet(Device *device) : DescriptorSet(device) {
}
CCMTLDescriptorSet::~CCMTLDescriptorSet() {
    destroy();
}

bool CCMTLDescriptorSet::initialize(const DescriptorSetInfo &info) {
    _layout = info.layout;

    const auto gpuDescriptorSetLayout = static_cast<CCMTLDescriptorSetLayout*>(_layout)->gpuDescriptorSetLayout();
    const auto descriptorCount = gpuDescriptorSetLayout->descriptorCount;
    const auto bindingCount = gpuDescriptorSetLayout->bindings.size();
    const auto &descriptorIndices = gpuDescriptorSetLayout->descriptorIndices;

    _buffers.resize(descriptorCount);
    _textures.resize(descriptorCount);
    _samplers.resize(descriptorCount);

    _gpuDescriptorSet = CC_NEW(CCMTLGPUDescriptorSet);
    _gpuDescriptorSet->descriptorIndices = &gpuDescriptorSetLayout->descriptorIndices;
    _gpuDescriptorSet->gpuDescriptors.resize(descriptorCount);
    for (size_t i = 0; i < bindingCount; i++) {
        const auto &binding = gpuDescriptorSetLayout->bindings[i];
        const auto descriptorIndex = descriptorIndices[i];
        for(size_t j = descriptorIndex; j < descriptorIndex + binding.count; j++) {
            _gpuDescriptorSet->gpuDescriptors[j].type = binding.descriptorType;
        }
    }

    return true;
}
void CCMTLDescriptorSet::destroy() {
    _layout = nullptr;
    CC_SAFE_DELETE(_gpuDescriptorSet);
}

void CCMTLDescriptorSet::update() {
    if (_isDirty && _gpuDescriptorSet) {
        const auto &descriptors = _gpuDescriptorSet->gpuDescriptors;
        for (size_t i = 0; i < descriptors.size(); i++) {
            if (static_cast<uint>(descriptors[i].type) & DESCRIPTOR_BUFFER_TYPE) {
                if (_buffers[i]) {
                    _gpuDescriptorSet->gpuDescriptors[i].buffer = static_cast<CCMTLBuffer *>(_buffers[i]);
                }
            } else if (static_cast<uint>(descriptors[i].type) & DESCRIPTOR_SAMPLER_TYPE) {
                if (_textures[i]) {
                    _gpuDescriptorSet->gpuDescriptors[i].texture = static_cast<CCMTLTexture *>(_textures[i]);
                }
                if (_samplers[i]) {
                    _gpuDescriptorSet->gpuDescriptors[i].sampler = static_cast<CCMTLSampler *>(_samplers[i]);
                }
            }
        }
        _isDirty = false;
    }
}
}
}