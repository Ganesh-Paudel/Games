#include "EventLoop.h"

int main() {
    const int tileSize = 50;
    const int screenWidth = tileSize * 9;
    const int screenHeight = tileSize* 9;

    EventLoop gameLoop(screenWidth, screenHeight);
    gameLoop.Run();

    return 0;
}
