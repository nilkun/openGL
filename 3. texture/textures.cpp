#include "textures.h"
// #include <SDL2/SDL.h> // for image function only
// installed through pacman 
#include <SDL2/SDL_image.h>

Textures::Textures()
{
	add("texture.png");
}
void Textures::add(std::string filename) {
	const char* file = filename.c_str();
	SDL_Surface* image = IMG_Load(file);

	if(image == nullptr)
	{
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
		"Error Loading Image",
		file,
		NULL);
	}
	else
	{
		std::cout << "Image loaded successfully..." << std::endl;
	}
	upload(image);
    SDL_FreeSurface(image);
}

void Textures::upload(SDL_Surface* surface)
{
	GLint minMagFilter = GL_LINEAR;
	GLINT wrapMode = GL_LINEAR; //??
    glGenTextures(1, &_object);
    glBindTexture(GL_TEXTURE_2D, _object);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minMagFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, minMagFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);
    glTexImage2D(GL_TEXTURE_2D,
                 0, 
                 3,
                 surface->w, 
                 surface->h,
                 0, 
                 GL_RGB, 
                 GL_UNSIGNED_BYTE, 
                 surface->pixels);
    glBindTexture(GL_TEXTURE_2D, 0);
}
