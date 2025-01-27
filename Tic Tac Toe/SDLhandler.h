#pragma once
#include <SDL.h>

class SDLhandler
{
public:
	SDLhandler();
	~SDLhandler();
	bool init();
	void clearScreen();
	void render();
	SDL_Renderer* getRenderer();
	SDL_Event e;

private:
	int tileSize = 100;
	SDL_Window* window;
	SDL_Renderer* renderer;
	int screenWidth = tileSize * 3;
	int screenHeight = tileSize * 3;
};

