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
    Renderer(CA::MetalDrawable* const pDrawable, MTL::Device* const pDevice);
    // Destructor
    ~Renderer();
    
    // Custom functions
    void draw() const;
    
private:
    // Member variables
    CA::MetalDrawable* p_Drawable;
    MTL::Device* const p_Device;
    MTL::CommandQueue* const p_CommandQueue;
};
}
#endif /* Renderer_hpp */
