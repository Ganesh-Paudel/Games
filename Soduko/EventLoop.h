#pragma once
#include "Render.h"

class EventLoop {
public:
    EventLoop(int width, int height);
    void Run();

private:
    Render renderer;
    const int screenWidth;
    const int screenHeight;
};
