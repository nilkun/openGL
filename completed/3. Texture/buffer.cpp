#include "buffer.h"

#include <GL/glew.h>
#include <iostream>
#include <SDL2/SDL_image.h>

GLuint Buffer::create(const GLfloat* data, int size, GLuint index, GLboolean normalize, int amount)
{
	GLuint buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);

	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	glVertexAttribPointer(index, amount, GL_FLOAT, normalize, NULL, NULL);

	glEnableVertexAttribArray(index); // Add array to VAO
	
	return buffer;
}

bool Buffer::init()
{
	const GLfloat colors[] = {
		1.0, 0.0, 0.0, 1.0, // Top left
		0.0, 1.0, 0.0, 1.0, // Top right
		0.0, 0.0, 1.0, 1.0, // Bottom right 
	};
    const GLfloat textures[] = {    
        0.0f,     0.8f,   0.0f,   0.5f,   1.0f,
        -0.8f,    -0.8f,  0.0f,   0.0f,   0.0f,
        0.8f,     -0.8f,  0.0f,   1.0f,   0.0f,
    };

    const GLfloat tri[] = {    
        0.0f,     0.8f,   0.0f, 
        -0.8f,    -0.8f,  0.0f,
        0.8f,     -0.8f,  0.0f, 
    };

	const GLfloat uv[] = {
		0.5f,   1.0f,   
		0.0f,   0.0f,  
		1.0f,   0.0f,
	};

    // VERTEX ARRAY
	glGenVertexArrays(1, vao);
	glBindVertexArray(vao[0]);

	GLuint idno = create(tri, sizeof(tri), 0, GL_FALSE, 3);
	GLuint idno2 = create(uv, sizeof(uv), 1, GL_TRUE, 2);

	setTexture();
}

void Buffer::bindAll() {

	glBindVertexArray(vao[0]);
	    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureIDs[0]);
}
void Buffer::setTexture() {

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

void Buffer::tex(GLuint id) {
    glUniform1i(id, GL_TEXTURE0);
}

SDL_Surface* Buffer::getSurface() {  
    std::string filename = "texture.png";
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