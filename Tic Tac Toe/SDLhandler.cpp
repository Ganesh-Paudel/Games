#include "SDLhandler.h"
#include <iostream>


bool SDLhandler::init() {
	if (SDL_INIT_EVERYTHING < 0) {
		std::cout << " SDL initialization failed" << std::endl;
		return false;
	}
	else {
		window = SDL_CreateWindow("Tic Tac Toe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			std::cout << "Window creation failed" << std::endl;
			return false;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer == NULL) {
			std::cout << "Renderer creation failed" << std::endl;
			return false;
		}
	}
	return true;
}

SDLhandler::SDLhandler() {
	
}
void SDLhandler::clearScreen() {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
}

void SDLhandler::render() {

	SDL_RenderPresent(renderer);
}

SDL_Renderer* SDLhandler::getRenderer() {
	return renderer;
}


SDLhandler::~SDLhandler() {

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
