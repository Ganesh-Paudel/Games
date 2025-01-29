#include "EventHandler.h"
EventHandler::EventHandler() :
    currentActiveTile{0, 0} 
{}

void EventHandler::HandleInput(Grid& grid) {
    HandleMousePressed(grid);
    HandleKeyPressed(grid);
}

void EventHandler::HandleMousePressed(Grid& grid) {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePosition = GetMousePosition();
        int x = static_cast<int>(mousePosition.x) / 50;
        int y = static_cast<int>(mousePosition.y) / 50;

        currentActiveTile.x = x;
        currentActiveTile.y = y;

        activeValue = grid.getGrid()[x][y];
    }
}

void EventHandler::HandleKeyPressed(Grid& grid) {
    
    int value = -1;

    if (IsKeyPressed(KEY_ONE)) value = 1;
    else if (IsKeyPressed(KEY_TWO)) value = 2;
    else if (IsKeyPressed(KEY_THREE)) value = 3;
    else if (IsKeyPressed(KEY_FOUR)) value = 4;
    else if (IsKeyPressed(KEY_FIVE)) value = 5;
    else if (IsKeyPressed(KEY_SIX)) value = 6;
    else if (IsKeyPressed(KEY_SEVEN)) value = 7;
    else if (IsKeyPressed(KEY_EIGHT)) value = 8;
    else if (IsKeyPressed(KEY_NINE)) value = 9;


    if (value != -1) {
        grid.updateGrid(currentActiveTile.x, currentActiveTile.y, value);
        activeValue = value;
    }
}