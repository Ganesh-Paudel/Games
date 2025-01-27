#pragma once

#include <SDL.h>

class InputHandler
{
public:
	void handleInput(SDL_Event e, bool& isRunning, SDL_Renderer* renderer);
	const int (&getGrid() const)[3][3];

private:
	void handleMouseClick(SDL_Event e, bool& isRunning, SDL_Renderer* renderer);
	void handleQuit(SDL_Event e, bool& isRunning);
	bool checkValidity(int x, int y);

	int grid[3][3] = { 0 };
	int currentPlayer = 1;
};
