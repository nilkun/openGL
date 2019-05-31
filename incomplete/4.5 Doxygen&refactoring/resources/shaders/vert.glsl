#version 330

layout(location = 0) in vec3 triangle;
layout(location = 1) in vec2 vu;

out vec2 fragmentColor;

uniform mat4 MVP;

void main(void) {
    gl_Position = MVP * vec4(triangle, 1);
    fragmentColor = vu;
}