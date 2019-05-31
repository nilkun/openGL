#include <iostream>
#include <SDL2/SDL.h>

#include "./sdl/renderer.h"
#include "./openGL/shader.h"
#include "./debug/debug.h"
#include "./openGL/buffer.h"
#include "./openGL/matrices.h"

Renderer renderer;
Shader shader;
Buffer buffer;
Matrix matrix;

void start();

int main() { 
/** 
	Playing around with OpenGL 
	This is a neverending project, where new functionality will be constantly added.	
*/
    Debug debug;

    if(!renderer.init()) return -1;

	glEnable(GL_NORMALIZE);
    // renderer.clearScreen();
	// glDrawArrays(GL_LINE_LOOP, 0, 3);
	// renderer.swapBuffers();
    debug.enable();
    buffer.init();
    if (!shader.init()) return false;
	shader.useProgram();
	
	GLuint matrixID = glGetUniformLocation(shader.getProgram(), "MVP");

	buffer.loadUniform(glGetUniformLocation(shader.getProgram(), "tex"));


	std::cout << "Press ENTER to render next frame\n";
	std::cin.ignore();

	renderer.clear(0.0, 0.0, 0.0, 1.0);
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &matrix.mvp[0][0]);

	buffer.bindAll();
	glDrawArrays(GL_TRIANGLES, 0, 12 * 3);

	glDisableVertexAttribArray(0);
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