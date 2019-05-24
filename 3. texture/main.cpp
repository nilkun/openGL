#include <SDL2/SDL.h>
#include <iostream>
#include "renderer.h"
#include "shader.h"
#include "buffer.h"

// DEBUGGING
void GLAPIENTRY
MessageCallback( GLenum source,
                 GLenum type,
                 GLuint id,
                 GLenum severity,
                 GLsizei length,
                 const GLchar* message,
                 const void* userParam )
{
  fprintf( stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
           ( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ),
            type, severity, message );
}
// END OF DEBUGGING CODE

Renderer renderer;
Shader shader;
Buffer buffer;

// DECLARATIONS
void start();

int main() 
{ 
	
    if(!renderer.init()) return -1;

	// DEBUGGING
	glEnable              ( GL_DEBUG_OUTPUT );
	glDebugMessageCallback( MessageCallback, 0 );
	// END OF DEBUGGING

    if(!buffer.init(shader)) return -1;

    renderer.clearScreen();
	glDrawArrays(GL_LINE_LOOP, 0, 4);
	renderer.swapBuffers();
	std::cout << "Press ENTER to render next frame" << std::endl;

	std::cin.ignore();
	renderer.clear(1.0, 0.0, 0.0, 1.0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	renderer.swapBuffers();
    start();
    renderer.close();
	shader.close();
    return 0;
}

void start()
{
	bool loop=true;;

	while (loop)
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				loop = false;

			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					loop = false;
					break;
				case SDLK_r:
                    renderer.clear(1.0, 0.0, 0.0, 1.0);
					break;
				case SDLK_g:
					renderer.clear(0.0, 1.0, 0.0, 1.0);
					break;
				case SDLK_b:
					renderer.clear(0.0, 0.0, 1.0, 1.0);
					break;
				default:
					break;
				}
			}
		}
        renderer.swapBuffers();
	}
}