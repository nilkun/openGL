#include "buffer.h"

#include <GL/glew.h>

// TEMP IMPORTS
#include <SDL2/SDL_image.h>
#include <iostream>

bool Buffer::init(Shader &shader)
{    
    // TEXTURE TIME
    glActiveTexture(GL_TEXTURE0);   
    
    std::string filename = "hazard.png";
	const char* file = filename.c_str();
	SDL_Surface* surface = IMG_Load(file);

	if(surface == nullptr)
	{
	SDL_ShowSimpleMessageBox(
        SDL_MESSAGEBOX_ERROR,
		"Error Loading Image",
		file,
		NULL);
	}
	else
	{
		std::cout << "Image loaded successfully..." << std::endl;
	}

    glGenTextures(1, textureIDs);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureIDs[0]);

    int Mode = GL_RGB;
    // const bpp = surface->format->BytesPerPixel;

    if(surface->format->BytesPerPixel == 4) { Mode = GL_RGBA; };        
    glTexImage2D(GL_TEXTURE_2D, 0, Mode, surface->w, surface->h, 0, Mode, GL_UNSIGNED_BYTE, surface->pixels);

	int location = glGetUniformLocation(shader.getProgram(), "tex");
	glUniform1i(location, 0);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    const GLfloat textures[] = {    
        0.0f,     0.8f,   0.0f,   0.5f,   1.0f,
        -0.8f,    -0.8f,  0.0f,   0.0f,   0.0f,
        0.8f,     -0.8f,  0.0f,   1.0f,   0.0f,
    };

    // VERTEX ARRAY
	glGenVertexArrays(1, vao);
	glBindVertexArray(vao[0]);

    // only needs textures
	glGenBuffers(1, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(textures), textures, GL_STATIC_DRAW);

    const GLuint triangleIndex = 0;
    const GLuint uvIndex = 1;

    // Points to triangle
	glEnableVertexAttribArray(triangleIndex);
	glVertexAttribPointer(triangleIndex, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), NULL);

	glEnableVertexAttribArray(uvIndex);
    glVertexAttribPointer(uvIndex, 2, GL_FLOAT, GL_TRUE,  5 * sizeof(GLfloat), (const GLvoid*)(3 * sizeof(GLfloat)));

    // Cleanup
    glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindTexture(GL_TEXTURE_2D, 0);

	return true;
}
