#include "shader.h"
#include <SDL2/SDL.h>

class Buffer
{
public:
    Buffer(){};

    bool init();
    GLuint vbo[2], vao[1]; 
    const uint32_t positionAttributeIndex = 0, colorAttributeIndex = 1;
    static const uint32_t points = 3;
    static const uint32_t floatsPerPoint = 3;
    static const uint32_t floatsPerColor = 4;

    const GLfloat diamond[points][floatsPerPoint] = {
        {  0.0f,  0.8f,  0.0f }, 
        { -0.8f,  -0.8f,  0.0f }, 
        {  0.8f,  -0.8f,  0.0f }, 
    };

    const GLfloat colors[points][floatsPerColor] = {
        { 1.0, 1.0, 0.0, 1.0 }, // Top left
        { 1.0, 1.0, 0.0, 1.0  }, // Top right
        { 1.0, 1.0, 0.0, 1.0  }, // Bottom right 
    };

    GLfloat triangle[9] = {
        -1.0f, -.5f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f,
    };
};