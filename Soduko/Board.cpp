#include "Board.h"



void Board::drawBoard(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	for (int i = 0; i < 9; i++) {
		SDL_RenderDrawLine(renderer, 0, i * 50, 50 * 9,i * 50);
		SDL_RenderDrawLine(renderer, i * 50, 0, i * 50, 50 * 9);
	}
}