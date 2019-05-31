#pragma once

#include <string>
#include <SDL2/SDL.h>

class Renderer
{
public:
	Renderer();
	bool init();
	void clear(float r, float g, float b, float a);
	void clearScreen();
	void swapBuffers();
	void setOptions();
	bool setAttributes();
	void render(int points);
	void close();
	bool initSDL();

private:
	int m_width;
	int m_height;
	std::string m_title;
	void SetOpenGLOptions();
	bool SetSDL_GL_Attributes();
	SDL_Window *m_Window;
	SDL_GLContext m_Context;
};
