#pragma once
#include <SDL.h>
class Drawer
{
public:
	void drawCross(SDL_Renderer* renderer, int x, int y);
	void drawCircle(SDL_Renderer* renderer, int x, int y);
	void drawBoard(SDL_Renderer* renderer,const int (&grid)[3][3]);
	void drawBackground(SDL_Renderer* renderer);
	int checkWinner(const int(&grid)[3][3]);

private:
};

