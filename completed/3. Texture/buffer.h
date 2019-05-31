#include "shader.h"
#include <SDL2/SDL.h>

class Buffer
{
public:
    GLuint textureIDs[1];
    GLuint location;
    GLuint create(const GLfloat* data, int size, GLuint index, GLboolean normalize, int amount);
    // GLuint vbo[1], vao[1]; 
    Buffer(){};
    // void set(GLuint programID);
    // bool init(Shader &shader);
    // bool load();
    void setTexture();
    SDL_Surface* getSurface();
    void tex(GLuint id);
    void bindAll();
    bool init();
    GLuint vbo[1], vao[1]; 
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
	{ 0.0, 1.0, 0.0, 1.0 }, // Top left
	{ 1.0, 1.0, 0.0, 1.0  }, // Top right
	{ 1.0, 0.0, 0.0, 1.0  }, // Bottom right 
};
    // GLfloat cube[] = {
    //     //  X     Y     Z       U     V
    //     // bottom
    //     -1.0f,-1.0f,-1.0f,   0.0f, 0.0f,
    //     1.0f,-1.0f,-1.0f,   1.0f, 0.0f,
    //     -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,
    //     1.0f,-1.0f,-1.0f,   1.0f, 0.0f,
    //     1.0f,-1.0f, 1.0f,   1.0f, 1.0f,
    //     -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,

    //     // top
    //     -1.0f, 1.0f,-1.0f,   0.0f, 0.0f,
    //     -1.0f, 1.0f, 1.0f,   0.0f, 1.0f,
    //     1.0f, 1.0f,-1.0f,   1.0f, 0.0f,
    //     1.0f, 1.0f,-1.0f,   1.0f, 0.0f,
    //     -1.0f, 1.0f, 1.0f,   0.0f, 1.0f,
    //     1.0f, 1.0f, 1.0f,   1.0f, 1.0f,

    //     // front
    //     -1.0f,-1.0f, 1.0f,   1.0f, 0.0f,
    //     1.0f,-1.0f, 1.0f,   0.0f, 0.0f,
    //     -1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
    //     1.0f,-1.0f, 1.0f,   0.0f, 0.0f,
    //     1.0f, 1.0f, 1.0f,   0.0f, 1.0f,
    //     -1.0f, 1.0f, 1.0f,   1.0f, 1.0f,

    //     // back
    //     -1.0f,-1.0f,-1.0f,   0.0f, 0.0f,
    //     -1.0f, 1.0f,-1.0f,   0.0f, 1.0f,
    //     1.0f,-1.0f,-1.0f,   1.0f, 0.0f,
    //     1.0f,-1.0f,-1.0f,   1.0f, 0.0f,
    //     -1.0f, 1.0f,-1.0f,   0.0f, 1.0f,
    //     1.0f, 1.0f,-1.0f,   1.0f, 1.0f,

    //     // left
    //     -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,
    //     -1.0f, 1.0f,-1.0f,   1.0f, 0.0f,
    //     -1.0f,-1.0f,-1.0f,   0.0f, 0.0f,
    //     -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,
    //     -1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
    //     -1.0f, 1.0f,-1.0f,   1.0f, 0.0f,

    //     // right
    //     1.0f,-1.0f, 1.0f,   1.0f, 1.0f,
    //     1.0f,-1.0f,-1.0f,   1.0f, 0.0f,
    //     1.0f, 1.0f,-1.0f,   0.0f, 0.0f,
    //     1.0f,-1.0f, 1.0f,   1.0f, 1.0f,
    //     1.0f, 1.0f,-1.0f,   0.0f, 0.0f,
    //     1.0f, 1.0f, 1.0f,   0.0f, 1.0f
    // };

    GLfloat triangle[9] = {
        -1.0f, -.5f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f,
    };
};