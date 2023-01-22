//
//  RendererAdapter.m
//  FirstMetalApp
//
//  Created by Jakub Nowak on 30/12/2022.
//

#import "RendererAdapter.h"

@implementation RendererAdapter
//- (void)draw:(id <CAMetalDrawable>) drawable device: (id <MTLDevice>) device
//{
//    p_Renderer = new Barrel::Renderer((__bridge CA::MetalDrawable *)drawable, (__bridge MTL::Device *)device);
//    p_Renderer->draw();
//}
-(nonnull instancetype) initWithMTKView: (MTKView*) pView
{
    self = [super init];
    p_Renderer = new Barrel::Renderer((__bridge MTL::Device *)pView.device);
    return self;
}
- (void)drawInMTKView:(MTKView *)view
{
    p_Renderer->drawFrame((__bridge CA::MetalDrawable *)view.currentDrawable);
}
- (void) mtkView:(MTKView *)view drawableSizeWillChange:(CGSize)size
{
    //TBD
}
-(void)dealloc
{
    delete p_Renderer;
}
@end
