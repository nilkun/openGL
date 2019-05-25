#version 330

// layout(location = 4) 
uniform sampler2D tex;
in vec2 texCoord; //this is the texture coord
out vec4 color; //this is the output color of the pixel

void main() {
    color = texture(tex, texCoord);
}