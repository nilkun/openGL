#include <SDL2/SDL.h>
#include <iostream>
#include "renderer.h"
#include "shader.h"
#include "buffer.h"
#include "debug.h"

Renderer renderer;
Shader shader;
Buffer buffer;
Debug debug;

GLfloat vertexData[] = {
    //  X     Y     Z       U     V
     0.0f, 0.8f, 0.0f,   0.5f, 1.0f,
    -0.8f,-0.8f, 0.0f,   0.0f, 0.0f,
     0.8f,-0.8f, 0.0f,   1.0f, 0.0f,
};

// DECLARATIONS
void start();

int main() 
{ 
    if(!renderer.init()) return -1;

	debug.enable();
	if (!shader.init()) return false;
	shader.useProgram();

    if(!buffer.init(shader)) return -1;

    renderer.clearScreen();
	glDrawArrays(GL_LINE_LOOP, 0, 4);
	renderer.swapBuffers();
	std::cout << "Press ENTER to render next frame" << std::endl;

	std::cin.ignore();
	renderer.clear(1.0, 0.0, 0.0, 1.0);

	int location = glGetUniformLocation(shader.getProgram(), "tex");
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, buffer.textureIDs[0]);
	glUniform1i(location, 0);
	glBindVertexArray(buffer.vao[0]);

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