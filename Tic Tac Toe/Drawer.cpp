#include "Drawer.h"


void Drawer::drawBackground(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 138, 43, 226, 255);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderDrawLine(renderer, 100, 0, 100, 300);
	SDL_RenderDrawLine(renderer, 200, 0, 200, 300);
	SDL_RenderDrawLine(renderer, 0, 100, 300, 100);
	SDL_RenderDrawLine(renderer, 0, 200, 300, 200);
}

void Drawer::drawBoard(SDL_Renderer* renderer, const int (&grid)[3][3]) {
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (grid[i][j] == 1) {
				drawCross(renderer, i, j);
			}
			else if (grid[i][j] == -1) {
				drawCircle(renderer, i, j);
			}
		}
	}
}


void Drawer::drawCross(SDL_Renderer* renderer, int x, int y) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	// Draw line from left corner to bottom right corner
	SDL_RenderDrawLine(renderer, x * 100 + 20, y * 100 + 20, x * 100 + 80, y * 100 + 80);
	// Draw line from right corner to bottom left corner
	SDL_RenderDrawLine(renderer, x * 100 + 80 , y * 100 + 20, x * 100 + 20, y * 100 + 80);
}

void Drawer::drawCircle(SDL_Renderer* renderer, int x, int y) {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_Rect rect= { x * 100 + 20, y * 100 + 20, 60, 60 };
	SDL_RenderDrawRect(renderer, &rect);
	
}

int Drawer::checkWinner(const int(&grid)[3][3]) {

	// Check rows and columns
	for (int i = 0; i < 3; ++i) {
		// Check row
		if (grid[i][0] != 0 && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
			return grid[i][0];
		}
		// Check column
		if (grid[0][i] != 0 && grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) {
			return grid[0][i];
		}
	}

	// Check diagonals
	if (grid[0][0] != 0 && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
		return grid[0][0];
	}
	if (grid[0][2] != 0 && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
		return grid[0][2];
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (grid[i][j] == 0) {
				return 0;
			}
		}
	}

	// No winner
	return 2;
	
}

