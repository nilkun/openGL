#include "shader.h"
#include <SDL2/SDL.h>

class Buffer
{
public:
GLuint textureIDs[1];

    GLuint vbo[1], vao[1]; 
    Buffer(){};
    bool init(Shader &shader);
    void uploadSurface(SDL_Surface* surface);
};