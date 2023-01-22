//
//  Renderer.hpp
//  FirstMetalApp
//
//  Created by Jakub Nowak on 30/12/2022.
//

#ifndef Renderer_hpp
#define Renderer_hpp

#include "Metal/Metal.hpp"
#include "QuartzCore/CAMetalDrawable.hpp"


namespace Barrel
{
class Renderer
{
public:
    // Constructor
    Renderer( MTL::Device* const pDevice);
    // Destructor
    ~Renderer();
    
    // Custom functions
//    void draw() const;
    void drawFrame(const CA::MetalDrawable* const pDrawable);
    
private:
    // Member variables
//    CA::MetalDrawable* p_Drawable;
    MTL::Device* const p_Device;
    MTL::CommandQueue* const p_CommandQueue;
    std::unique_ptr<MTL::RenderPipelineState, void(*)(MTL::RenderPipelineState *)> p_RenderPipelineState;
    float timer;
    
    // Member functions
    void buildShaders();
    
};
}
#endif /* Renderer_hpp */
