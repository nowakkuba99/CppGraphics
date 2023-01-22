//
//  ViewController.m
//  FirstMetalApp
//
//  Created by Jakub Nowak on 30/12/2022.
//

#import "ViewController.h"
#import "RendererAdapter.h"

@implementation ViewController
{
    MTKView* view;
    
    RendererAdapter* p_RendererAdapter;
}


- (void)viewDidLoad {
    [super viewDidLoad];

    // Do any additional setup after loading the view.
    view = (MTKView*)self.view;
    view.device = MTLCreateSystemDefaultDevice();
    p_RendererAdapter = [[RendererAdapter alloc]initWithMTKView:view];
    view.delegate = p_RendererAdapter;
//    [p_RendererAdapter draw:view.currentDrawable device:view.device];
    
}


- (void)setRepresentedObject:(id)representedObject {
    [super setRepresentedObject:representedObject];

    // Update the view, if already loaded.
}


@end
