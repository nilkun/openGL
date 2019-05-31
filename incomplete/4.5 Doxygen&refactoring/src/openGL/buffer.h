#include <SDL2/SDL.h>

#include "shader.h"

class Buffer
{

public:
    GLuint triangleID;
    GLuint colorbuffer;
    GLuint texBuffer;

    GLuint textureIDs[1];
    GLuint location;
    GLuint create(const GLfloat* data, int size, GLuint index);
    Buffer(){};
    void setTexture();
    SDL_Surface* getSurface();
    void loadUniform(GLuint id);
    void bindAll();
    void bindTexture();
    bool init();
    GLuint vbo[1], vao[1]; 
    const uint32_t positionAttributeIndex = 0, colorAttributeIndex = 1;
    static const uint32_t points = 3;
    static const uint32_t floatsPerPoint = 3;
    static const uint32_t floatsPerColor = 4;

    const GLfloat cube[36*3] = {
        -1.0f, 1.0f, 1.0f, //front (left on screen)
        -1.0f,-1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,

        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f, 

        1.0f, 1.0f, 1.0f, // right
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f,-1.0f,

        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,

        -1.0f,-1.0f,-1.0f, // left
        -1.0f,-1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f, 

        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,

        1.0f, 1.0f,-1.0f, // back
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f, 

        1.0f, 1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f, 
        
        1.0f, 1.0f, 1.0f, // top
        1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,

        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f, 

        1.0f,-1.0f, 1.0f, // bottom
        -1.0f,-1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,

        1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f,-1.0f,
    };

    const GLfloat textureMap[36*2] = {     
        0.0f, 1.0f, 
        0.0f, 0.0f,
        1.0f, 0.0f,

        1.0f, 1.0f,
        0.0f, 1.0f,
        1.0f, 0.0f,    

        0.0f, 1.0f, // RIGHT
        1.0f, 0.0f,
        0.0f, 0.0f,  

        1.0f, 0.0f,
        0.0f, 1.0f,
        1.0f, 1.0f,  


        0.0f, 0.0f,  // left
        1.0f, 1.0f,
        0.0f, 1.0f,

        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,   

        0.0f, 1.0f, // back
        0.0f, 0.0f,
        1.0f, 0.0f,    

        0.0f, 1.0f,
        1.0f, 0.0f,
        1.0f, 1.0f, 
  
        1.0f, 0.0f, // top
        1.0f, 1.0f,
        0.0f, 1.0f,

        1.0f, 0.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,

        1.0f, 1.0f, // bottom 
        0.0f, 0.0f,
        1.0f, 0.0f,

        1.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,
    };
};