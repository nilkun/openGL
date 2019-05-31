#version 330
// in_Position was bound to attribute index 0 and in_Color was bound to attribute index 1
layout(location = 0) in vec3 triangle;
layout(location = 1) in vec2 inCoord;
out vec4 outColors;
out vec2 texCoord;

void main(void) {
    gl_Position = vec4(triangle, 1.0f);
    // gl_Position = vec4(outCoord, 0.0f, 1.0f);
    texCoord = inCoord;
}