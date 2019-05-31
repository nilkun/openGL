#include <GL/glew.h>

#include "renderer.h"
#include "error.h"

Renderer::Renderer() {
    m_width = 512;
    m_height = 512;
    m_title = "Renderer";
};

bool Renderer::init()
{
    if(!initSDL()) return false;
    setAttributes();
    SDL_GL_SetSwapInterval(1);
    glewInit();
    setOptions();

    return true;
};

bool Renderer::initSDL() 
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        return error("Initialization Error", SDL_GetError());
    }
    m_Window = SDL_CreateWindow(
        "test", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED,
        m_width, 
        m_height, 
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    
    if (!m_Window )
    {
        return error("Window Creation Error", SDL_GetError());
    }

    m_Context = SDL_GL_CreateContext(m_Window);
    return true;
}
void Renderer::clear(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
};
void Renderer::clearScreen()
{
    clear(0.0, 0.0, 0.0, 1.0);
};

void Renderer::swapBuffers()
{
    SDL_GL_SwapWindow(m_Window);
};

void Renderer::render(int points)
{
    glDrawArrays(GL_TRIANGLES, 0, points);
    SDL_GL_SwapWindow(m_Window);
};

void Renderer::close()
{
    SDL_GL_DeleteContext(m_Context);
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
};

bool Renderer::setAttributes()
{
    int major = 3;
    int minor = 3;
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    return true;
};

void Renderer::setOptions()
{
    glEnable(GL_BLEND) ;
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
};