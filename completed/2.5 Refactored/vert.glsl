#version 330

in vec3 in_Position;
in vec4 in_Color;
 
 
out vec4 ex_Color;

void main(void) {
    
    gl_Position = vec4(in_Position, 1.0f);
    
    ex_Color = in_Color;
}