#pragma once
#include <random>
#include "raylib.h"
class Grid
{
public:
	Grid();
	void updateGrid(int x, int y, int value);
	const int(&getGrid() const)[9][9];
	bool checkAvailability(int x, int y, int value) const;
	void fillInitialValues();
	bool preAssigned(int x, int y) const;

private:

	Vector2 preAssignedTiles[10];

	int grid[9][9] = { { -1} };

	std::mt19937 rng;
	std::uniform_int_distribution<int> dist;
};

