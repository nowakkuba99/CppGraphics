//
//  RendererAdapter.m
//  FirstMetalApp
//
//  Created by Jakub Nowak on 30/12/2022.
//

#import "RendererAdapter.h"

@implementation RendererAdapter
- (void)draw:(id <CAMetalDrawable>) drawable device: (id <MTLDevice>) device
{
    p_Renderer = new Barrel::Renderer((__bridge CA::MetalDrawable *)drawable, (__bridge MTL::Device *)device);
    p_Renderer->draw();
}
-(void)dealloc
{
    delete p_Renderer;
}
@end
