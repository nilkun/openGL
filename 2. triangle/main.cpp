#include <SDL2/SDL.h>
#include "renderer.h"
#include "shader.h"

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


GLuint vbo[2], vao[1]; 
const uint32_t positionAttributeIndex = 0, colorAttributeIndex = 1;
const uint32_t points = 3;
const uint32_t floatsPerPoint = 3;
const uint32_t floatsPerColor = 4;

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

Renderer renderer;
Shader shader;

bool setupBuffers()
{
	glGenBuffers(2, vbo);
	glGenVertexArrays(1, vao);
	glBindVertexArray(vao[0]);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, ( points * floatsPerPoint) * sizeof(GLfloat), diamond, GL_STATIC_DRAW);
	glVertexAttribPointer(positionAttributeIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(positionAttributeIndex);
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, ( points * floatsPerColor) * sizeof(GLfloat), colors, GL_STATIC_DRAW);
	glVertexAttribPointer(colorAttributeIndex, 4, GL_FLOAT, GL_FALSE, 0, 0);

	if (!shader.init()) return false;
	shader.useProgram();
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	return true;
}

void start();


int main() { 
    if(!renderer.init()) return -1;

	glEnable              ( GL_DEBUG_OUTPUT );
	glDebugMessageCallback( MessageCallback, 0 );
    if(!setupBuffers()) return -1;

    renderer.clearScreen();
	glDrawArrays(GL_LINE_LOOP, 0, 4);
	renderer.swapBuffers();
	std::cout << "Press ENTER to render next frame\n";
	std::cin.ignore();
	glEnableVertexAttribArray(colorAttributeIndex);
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