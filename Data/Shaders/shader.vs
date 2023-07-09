#version 330 core

layout (location = 0) in vec3 position;

uniform vec3 primColor;
out vec3 outColor;

void main()
{
    gl_Position = vec4(position, 1.0);
    outColor = primColor;
}