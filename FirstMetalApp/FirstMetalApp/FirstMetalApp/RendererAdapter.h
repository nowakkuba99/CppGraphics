//
//  RendererAdapter.h
//  FirstMetalApp
//
//  Created by Jakub Nowak on 30/12/2022.
//

#ifndef RendererAdapter_h
#define RendererAdapter_h

#import "QuartzCore/CAMetalLayer.h"
#import "Metal/MTLDevice.h"
#import "Renderer.hpp"

@interface RendererAdapter : NSObject
{
    Barrel::Renderer* p_Renderer;
}
-(void)draw:(id <CAMetalDrawable>) drawable device: (id <MTLDevice>) device;
@end

#endif /* RendererAdapter_h */
