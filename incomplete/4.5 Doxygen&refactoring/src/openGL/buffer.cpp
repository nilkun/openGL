// OpenGL
#include "buffer.h"

#include <GL/glew.h>
#include <iostream>
#include <SDL2/SDL_image.h>

GLuint Buffer::create(const GLfloat* data, int size, GLuint index)
{
	/** Creates a new VBO */
	GLuint buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	return buffer;
}

bool Buffer::init()
{
    /**
	*	Generates a Vertex Array Object and all the Vertex Buffer Objects
	*/

	glGenVertexArrays(1, vao);
	glBindVertexArray(vao[0]);

	triangleID = create(cube, sizeof(cube), 0);
	texBuffer = create(textureMap, sizeof(textureMap), 1);
	setTexture();
}

void Buffer::bindAll() {
	/** 
	 * Binds all buffers and textures
	 */

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, triangleID);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, texBuffer);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glBindVertexArray(vao[0]);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureIDs[0]);
}

void Buffer::setTexture() {
	/**
	 * Creates a surface and loads an image onto it.
	 */

    SDL_Surface *surface = getSurface();
    glGenTextures(1, textureIDs);
    glBindTexture(GL_TEXTURE_2D, textureIDs[0]);
    std::cout << "Texture ID: " << (textureIDs[0]) << std::endl;

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    int Mode = GL_RGB;
    if(surface->format->BytesPerPixel == 4) { Mode = GL_RGBA; };  
    glTexImage2D(GL_TEXTURE_2D, 0, Mode, surface->w, surface->h, 0, Mode, GL_UNSIGNED_BYTE, surface->pixels);

    SDL_FreeSurface(surface);
}

void Buffer::loadUniform(GLuint id) {
	/**
	 * binds a texture to a uniform
	 */

    glUniform1i(id, GL_TEXTURE0);
}

SDL_Surface* Buffer::getSurface() {  
	/**
	 * Loads "texture.png" and returns it as a SDL surface.
	 */
    std::string filename = "resources/images/texture.png";
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
    return surface;
}