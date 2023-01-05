//
//  Shaders.metal
//  FirstMetalApp
//
//  Created by Jakub Nowak on 31/12/2022.
//

#include <metal_stdlib>
using namespace metal;

/* Vertex Shader */
[[vertex]] float4 vertexShader(const constant packed_float3* triangleVertices [[buffer(5)]], const ushort vertexIndex [[vertex_id]])
{
    return float4(triangleVertices[vertexIndex],1.0f);
}

/* Fragment Shader */
[[fragment]] float4 fragmentShader()
{
    return float4(1.0f,1.0f,1.0f,1.0f);
}
