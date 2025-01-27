#include "InputHandler.h"
#include "Drawer.h"
#include <SDL.h>


void InputHandler::handleInput(SDL_Event e, bool& isRunning, SDL_Renderer* renderer) {
	if (e.type == SDL_QUIT) {
		handleQuit(e, isRunning);
	}
	else if (e.type == SDL_MOUSEBUTTONDOWN) {
		handleMouseClick(e, isRunning, renderer);
	}
}

void InputHandler::handleQuit(SDL_Event e, bool& isRunning) {
	isRunning = false;
}

void InputHandler::handleMouseClick(SDL_Event e, bool& isRunning, SDL_Renderer* renderer) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	x /= 100;
	y /= 100;

	checkValidity(x, y);
	
}

bool InputHandler::checkValidity(int x, int y) {
	if (grid[x][y] == 0) {
		grid[x][y] = currentPlayer;
		currentPlayer = currentPlayer == 1 ? -1 : 1;
		return true;
	}
	return false;
}

const int (&InputHandler::getGrid() const)[3][3] {
    return grid;
}