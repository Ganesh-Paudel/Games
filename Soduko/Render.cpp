#include "Render.h"

Render::Render(int width, int height) : screenWidth(width), screenHeight(height) {}

void Render::BeginDraw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
}

void Render::EndDraw() {
    EndDrawing();
}

void Render::DrawBackground() {
    
    for (int i = 0; i < 9; i++) {
        DrawLine(0, i * 50, 9 * 50, i * 50, i % 3 == 0 ? RED : BLACK);
        DrawLine(i * 50, 0, i * 50, 9 * 50, i % 3 == 0 ? RED : BLACK);

    }

    DrawLine(3 * 50 + 1, 0, 3 * 50 + 1, 9 * 50, RED);
    DrawLine(6 * 50 + 1, 0, 6 * 50 + 1, 9 * 50, RED);
    DrawLine(9 * 50 + 1, 0, 9 * 50 + 1, 9 * 50, RED);

    DrawLine(0, 3 * 50 + 1, 9 * 50, 3 * 50 + 1, RED);
    DrawLine(0, 6 * 50 + 1, 9 * 50, 6 * 50 + 1, RED);
    DrawLine(0, 9 * 50 + 1, 9 * 50, 9 * 50 + 1, RED);
}

void Render::DrawBoard(const int (&grid)[9][9], int activeX, int activeY, int activeValue) {
    
    for (int i = 0; i < 9; i++) {
        DrawRectangle(activeX * 50, i * 50, 50, 50, Fade(YELLOW, 0.3f));
        DrawRectangle(i * 50, activeY * 50, 50, 50, Fade(YELLOW, 0.3f));
    }

    // Highlight the cells with the same value
    if (activeValue != -1) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (grid[i][j] == activeValue) {
                    DrawRectangle(i * 50, j * 50, 50, 50, Fade(GREEN, 0.3f));
                }
            }
        }
    }

    DrawBackground();

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] != -1) {
                DrawText(TextFormat("%d", grid[i][j]), i * 50 + 20, j * 50 + 20, 20, RED);
            }
        }
    }
}


void Render::highlightBoard(int x, int y, int value) {

}
