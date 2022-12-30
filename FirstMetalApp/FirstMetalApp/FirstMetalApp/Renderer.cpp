//
//  Renderer.cpp
//  FirstMetalApp
//
//  Created by Jakub Nowak on 30/12/2022.
//
/* --- Metal needed defines --- */
#define NS_PRIVATE_IMPLEMENTATION
#define CA_PRIVATE_IMPLEMENTATION
#define MTL_PRIVATE_IMPLEMENTATION
/* ---------------------------- */

#include "Renderer.hpp"
#include <iostream>

namespace Barrel
{
// Constructor
Renderer::Renderer(CA::MetalDrawable* const pDrawable, MTL::Device* const pDevice)
:p_Drawable(pDrawable), p_Device(pDevice), p_CommandQueue(p_Device->newCommandQueue())
{}

// Destructor
Renderer::~Renderer()
{
    p_CommandQueue->release();
}

// Custom functions
void Renderer::draw() const
{
    std::cout<< " I'm so tired of this\n";
    
    // Render somthing by sending commands to GPU
    MTL::CommandBuffer* pCmdBuf = p_CommandQueue->commandBuffer();  //Extract command buffer from member command queue variable
    
    MTL::RenderPassDescriptor* pRpd = MTL::RenderPassDescriptor::alloc()->init();
    pRpd->colorAttachments()->object(0)->setTexture(p_Drawable->texture());
    pRpd->colorAttachments()->object(0)->setLoadAction(MTL::LoadActionClear);
    pRpd->colorAttachments()->object(0)->setClearColor(MTL::ClearColor::Make(0.0, 0.5, 0.5, 1.0));
    
    MTL::RenderCommandEncoder* pEnc = pCmdBuf->renderCommandEncoder(pRpd);
    pEnc->endEncoding();
    pCmdBuf->presentDrawable(p_Drawable);
    pCmdBuf->commit();
    
    pRpd->release();
}










}

