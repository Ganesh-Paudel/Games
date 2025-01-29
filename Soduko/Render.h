#pragma once
#include "raylib.h"

class Render {
public:
    Render(int width, int height);
    void BeginDraw();
    void EndDraw();
    void DrawBoard(const int(&grid)[9][9], int activeX, int activeY, int activeValue);
    void highlightBoard(int x, int y, int value);
    void DrawBackground();

private:
    int screenWidth;
    int screenHeight;
};
