#pragma once
#include <SDL.h>
class Board
{
public:
	const int(&getGrid() const)[3][3];
	void drawBoard(SDL_Renderer* renderer);
	void checkPosition();
private:
	int grid[9][9] = { 0 };

};

