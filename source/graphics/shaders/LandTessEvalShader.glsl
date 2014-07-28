#version 410 core

layout(triangles, fractional_even_spacing, ccw) in;

in FragmentData
{
    vec2 terrainTexCoord;
    vec4 terrainInfo1;
    vec4 terrainInfo2;
    vec4 terrainInfo3;
    vec4 terrainInfo4;
    vec4 terrainInfo5;
} inData[];

out FragmentData
{
    vec3 position;
    vec2 normalTexCoord;
    vec2 terrainTexCoord;
    vec4 terrainInfo1;
    vec4 terrainInfo2;
    vec4 terrainInfo3;
    vec4 terrainInfo4;
    vec4 terrainInfo5;
} outData;

#include "graphics/shaders/LandCommon.glsl"

const float WORLD_RADIUS = 10000.0;

void main()
{
    vec4 modelPos = gl_in[0].gl_Position * gl_TessCoord.x +
                    gl_in[1].gl_Position * gl_TessCoord.y +
                    gl_in[2].gl_Position * gl_TessCoord.z;

    vec4 worldPos = modelMatrix * modelPos;

    modelPos.z = modelPos.z + offsetBase + texture(offsetTex, modelPos.xy / 192.0).r * offsetScale;

    float angle = atan(distance(worldPos.xy, cameraPosition.xy) / WORLD_RADIUS);
    modelPos.z = modelPos.z - WORLD_RADIUS * (1.0 - cos(angle));

    gl_Position = modelViewProjectionMatrix * modelPos;

    outData.position = (modelViewMatrix * modelPos).xyz;

    outData.normalTexCoord = modelPos.xy / 192.0;

    outData.terrainTexCoord = inData[0].terrainTexCoord * gl_TessCoord.x +
                              inData[1].terrainTexCoord * gl_TessCoord.y +
                              inData[2].terrainTexCoord * gl_TessCoord.z;

    outData.terrainInfo1 = inData[0].terrainInfo1 * gl_TessCoord.x +
                           inData[1].terrainInfo1 * gl_TessCoord.y +
                           inData[2].terrainInfo1 * gl_TessCoord.z;

    outData.terrainInfo2 = inData[0].terrainInfo2 * gl_TessCoord.x +
                           inData[1].terrainInfo2 * gl_TessCoord.y +
                           inData[2].terrainInfo2 * gl_TessCoord.z;

    outData.terrainInfo3 = inData[0].terrainInfo3 * gl_TessCoord.x +
                           inData[1].terrainInfo3 * gl_TessCoord.y +
                           inData[2].terrainInfo3 * gl_TessCoord.z;

    outData.terrainInfo4 = inData[0].terrainInfo4 * gl_TessCoord.x +
                           inData[1].terrainInfo4 * gl_TessCoord.y +
                           inData[2].terrainInfo4 * gl_TessCoord.z;

    outData.terrainInfo5 = inData[0].terrainInfo5 * gl_TessCoord.x +
                           inData[1].terrainInfo5 * gl_TessCoord.y +
                           inData[2].terrainInfo5 * gl_TessCoord.z;
}