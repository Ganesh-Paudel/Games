#pragma once
#include "Grid.h"
#include "raylib.h"
class EventHandler
{
public:

	EventHandler();
	void HandleInput(Grid& grid);
	int getActiveX() const { return currentActiveTile.x; }
	int getActiveY() const { return currentActiveTile.y; }
	int getActiveValue() const { return activeValue; }
private:
	Vector2 currentActiveTile;
	void HandleMousePressed(Grid& grid);
	void HandleKeyPressed(Grid& grid);
	int activeValue;
};

