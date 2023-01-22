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
#include <vector>

namespace Barrel
{
// Constructor
Renderer::Renderer( MTL::Device* const pDevice)
                :p_Device(pDevice),
                p_CommandQueue(p_Device->newCommandQueue()),
                timer(),
                p_RenderPipelineState(nullptr,[](MTL::RenderPipelineState* const pipeline){ pipeline->release();})
                {
                    buildShaders();
                }

// Destructor
Renderer::~Renderer()
{
    p_CommandQueue->release();
}

//// Custom functions
//void Renderer::draw() const
//{
//    /* Render somthing by sending commands to GPU */
//    MTL::CommandBuffer* pCmdBuf = p_CommandQueue->commandBuffer();  //Extract command buffer from member command queue variable
//
//    MTL::RenderPassDescriptor* pRpd = MTL::RenderPassDescriptor::alloc()->init();   //Create and initialize RenderPassDescriptor
//    pRpd->colorAttachments()->object(0)->setTexture(p_Drawable->texture());
//    pRpd->colorAttachments()->object(0)->setLoadAction(MTL::LoadActionClear);
//    pRpd->colorAttachments()->object(0)->setClearColor(MTL::ClearColor::Make(0.0, 0.5, 0.5, 1.0));  //Set color toteal
//
//    /* Create verticies array */
//    const std::vector<float> vertices   //Three points for triangle
//    {
//        -0.5f, 0.5f, .0f,
//        0.5f, 0.5f, .0f,
//        .0f, -1.0f, .0f
//    };
//
//    /* Create buffer and store in unique pointer with custom destructor */
//    const std::unique_ptr<MTL::Buffer, void(*)(MTL::Buffer* const)> pVertexBuffer(
//        p_Device->newBuffer(vertices.data(), sizeof(float)*9, MTL::ResourceStorageModeShared),
//        [](MTL::Buffer* const buff){
//        buff->release();
//        });
//    /* Create Renderer Enccoder */
//    MTL::RenderCommandEncoder* pEnc = pCmdBuf->renderCommandEncoder(pRpd);
//    pEnc->setRenderPipelineState(p_RenderPipelineState.get());
//    pEnc->setVertexBuffer(pVertexBuffer.get(), 0, 5);   //Pass the vertex buffer
//    pEnc->drawPrimitives(MTL::PrimitiveTypeTriangle, NS::Integer(0), NS::Integer(3));   //Set rendering to Triangle from 3 points
//    pEnc->endEncoding();
//    pCmdBuf->presentDrawable(p_Drawable);
//    pCmdBuf->commit();
//
//    pRpd->release();
//}

void Renderer::buildShaders()
{
    /* Initialize default library (Get all shaders code) */
    const std::unique_ptr<MTL::Library, void(*)(MTL::Library* const)>
        pLib(
             p_Device->newDefaultLibrary(),
             [](MTL::Library* const lib){ lib->release();}
             );
    /* Set shaders */
    const std::unique_ptr<MTL::Function, void(*)(MTL::Function* const)>
        pVertexShader(
                      pLib.get()->newFunction(NS::String::string("vertexShader",NS::UTF8StringEncoding)),
                      [](MTL::Function* const func){ func->release(); }
                      );
    const std::unique_ptr<MTL::Function, void(*)(MTL::Function* const)>
        pFragmentShader(
                        pLib.get()->newFunction(NS::String::string("fragmentShader",NS::UTF8StringEncoding)),
                        [](MTL::Function* const func) {func->release(); }
                        );
    /* Pipeline descriptor */
    const std::unique_ptr<MTL::RenderPipelineDescriptor, void(*)(MTL::RenderPipelineDescriptor* const)>
        pRpd(
             MTL::RenderPipelineDescriptor::alloc()->init(),
             [](MTL::RenderPipelineDescriptor* const rpd) { rpd->release();}
             );
    pRpd.get()->setVertexFunction(pVertexShader.get());
    pRpd.get()->setFragmentFunction(pFragmentShader.get());
    pRpd.get()->colorAttachments()->object(0)->setPixelFormat(MTL::PixelFormatBGRA8Unorm);
    
    NS::Error* pErr {nullptr};
    p_RenderPipelineState.reset(p_Device->newRenderPipelineState(pRpd.get(), &pErr));
    if(!p_RenderPipelineState.get())    //If still nullptr
    {
        __builtin_printf("%s",pErr->localizedDescription()->utf8String());
    }
}

void Renderer::drawFrame(const CA::MetalDrawable *const pDrawable)
{
    /* Render somthing by sending commands to GPU */
    MTL::CommandBuffer* pCmdBuf = p_CommandQueue->commandBuffer();  //Extract command buffer from member command queue variable

    MTL::RenderPassDescriptor* pRpd = MTL::RenderPassDescriptor::alloc()->init();   //Create and initialize RenderPassDescriptor
    pRpd->colorAttachments()->object(0)->setTexture(pDrawable->texture());
    pRpd->colorAttachments()->object(0)->setLoadAction(MTL::LoadActionClear);
    pRpd->colorAttachments()->object(0)->setClearColor(MTL::ClearColor::Make(0.0, 0.5, 0.5, 1.0));  //Set color toteal

    /* Create verticies array */
    const std::vector<float> vertices   //Three points for triangle
    {
        -0.5f, 0.5f, .0f,
        0.5f, 0.5f, .0f,
        .0f, -1.0f, .0f
    };

    /* Create buffer and store in unique pointer with custom destructor */
    const std::unique_ptr<MTL::Buffer, void(*)(MTL::Buffer* const)> pVertexBuffer(
        p_Device->newBuffer(vertices.data(), sizeof(float)*9, MTL::ResourceStorageModeShared),
        [](MTL::Buffer* const buff){
        buff->release();
        });
    /* Create Renderer Enccoder */
    MTL::RenderCommandEncoder* pEnc = pCmdBuf->renderCommandEncoder(pRpd);
    pEnc->setRenderPipelineState(p_RenderPipelineState.get());
    pEnc->setVertexBuffer(pVertexBuffer.get(), 0, 5);   //Pass the vertex buffer
    pEnc->setVertexBytes(&timer, sizeof(float), 6);     //Pass the timer variable to GPU
    pEnc->drawPrimitives(MTL::PrimitiveTypeTriangle, NS::Integer(0), NS::Integer(3));   //Set rendering to Triangle from 3 points
    pEnc->endEncoding();
    pCmdBuf->presentDrawable(pDrawable);
    pCmdBuf->commit();

    pRpd->release();
    /* Incerement timer to move triangle with sinus function */
    timer += 0.01f;
}








}

