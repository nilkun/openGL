#version 330
// in_Position was bound to attribute index 0 and in_Color was bound to attribute index 1
in vec3 triangle;
in vec2 inCoord;
out vec2 outCoord;

void main(void) {
    gl_Position = vec4(triangle, 1.0f);
    outCoord = inCoord;
}