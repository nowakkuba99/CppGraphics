//
//  Shaders.metal
//  FirstMetalApp
//
//  Created by Jakub Nowak on 31/12/2022.
//

#include <metal_stdlib>
using namespace metal;

/* Vertex Shader */
[[vertex]] float4 vertexShader(
                               const constant packed_float3* triangleVertices [[buffer(5)]],
                               const constant float* timer [[buffer(6)]],
                               const ushort vertexIndex [[vertex_id]])
{
    const float valX = triangleVertices[vertexIndex].x;
    const float valY = triangleVertices[vertexIndex].y + sin(*timer);
    const float valZ = triangleVertices[vertexIndex].z;
    return float4(valX,valY,valZ,1.0f);
//    return float4(triangleVertices[vertexIndex],1.0f);
}

/* Fragment Shader */
[[fragment]] float4 fragmentShader()
{
    return float4(1.0f,1.0f,1.0f,1.0f);
}
