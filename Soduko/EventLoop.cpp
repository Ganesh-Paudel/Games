#include "EventLoop.h"
#include "Board.h"
#include <SDL.h>

bool EventLoop::initialize() {
	return handler->init();
}

EventLoop::EventLoop() :
	isRunning(true),
	handler(new SDLhandler())
{

}

void EventLoop::run() {

	Board board;

	while (isRunning) {
		while (SDL_PollEvent(&handler->e)) {
			if (handler->e.type == SDL_QUIT) {
				isRunning = false;
			}
		}

		handler->clearScreen();
		board.drawBoard(handler->getRenderer());
		handler->render();

		SDL_Delay(16);
	}
}


EventLoop::~EventLoop() {
	delete handler;
}