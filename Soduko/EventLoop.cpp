#include "EventLoop.h"
#include "EventHandler.h"
#include "raylib.h"
#include <iostream>
#include "Grid.h"

EventLoop::EventLoop(int width, int height)
    : screenWidth(width), screenHeight(height), renderer(width, height)
     {
}

void EventLoop::Run() {
    InitWindow(screenWidth, screenHeight, "Soduko");
    SetTargetFPS(60);
    Grid grid;
    EventHandler eventHandler;
    while (!WindowShouldClose()) {
        // Update
        eventHandler.HandleInput(grid);
        // Draw
        renderer.BeginDraw();

        renderer.DrawBoard(grid.getGrid(), eventHandler.getActiveX(), eventHandler.getActiveY(), eventHandler.getActiveValue());
        renderer.EndDraw();
    }

    CloseWindow(); // Close window and OpenGL context
}
