#pragma once
#include <SDL.h>

class SDLhandler
{
public:
	SDLhandler();
	~SDLhandler();
	bool init();
	SDL_Renderer* getRenderer();
	void clearScreen();
	void render();
	int getTileSize();
	SDL_Event getEvent();

	SDL_Event e;
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
private:
	int tileSize;
	int screenWidth;
	int screenHeight;
};

