#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 TexData;

out vec2 TexCoord;

uniform vec2 screenSize;

void main()
{
    gl_Position = vec4(aPos.x/600.0, aPos.y*2/400.0, 1.0, 1.0);
    TexCoord = TexData;
}