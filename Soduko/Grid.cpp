#include "Grid.h"

Grid::Grid():
	rng(std::random_device()()),
	dist(0,9)
{
	for (int i = 0; i < 9; ++i) {
		for(int j = 0; j< 9; ++j){
			grid[i][j] = -1;
		}
	}
	fillInitialValues();
}

const int(&Grid::getGrid() const)[9][9] {
	return grid;
}


void Grid::updateGrid(int x, int y, int value) {
	if (checkAvailability(x, y, value)) {
		grid[x][y] = value;
	}
}

void Grid::fillInitialValues() {
	int count = 0;
	int i, j, val;
	while (count <= 9) {
		i = dist(rng);
		j = dist(rng);
		val = dist(rng);

		if (!preAssigned(i, j)) {
			if (checkAvailability(i, j, val)) {
				grid[i][j] = val;
				preAssignedTiles[count] = { static_cast<float>(i), static_cast<float>(j) };
				++count;
			}
		}

	}
}

bool Grid::checkAvailability(int x, int y, int value) const {
	int leftX = (x / 3) * 3;
	int leftY = (y / 3) * 3;

	for (int i = leftX; i < leftX + 3; ++i) {
		for (int j = leftY; j < leftY + 3; ++j) {
			if (grid[i][j] == value && (x != i || y != j)) {
				return false;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (grid[i][y] == value && i != x) {
			return false;
		}

		if (grid[x][i] == value && i != y) {
			return false;
		}
	}
	return true;
}


bool Grid::preAssigned(int x, int y) const {
	for (const auto& coord : preAssignedTiles) {
		if (coord.x == x && coord.y == y) {
			return true;
		}
	}
	return false;
}