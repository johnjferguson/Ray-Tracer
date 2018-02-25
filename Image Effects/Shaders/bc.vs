#version 410
layout(location = 0) in vec2 VertexPosition;

uniform mat4 srt;

void main()
{
    // assign vertex position without modification
    gl_Position = vec4(VertexPosition, 0.0, 1.0)*srt;

}