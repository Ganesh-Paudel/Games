#include "EventLoop.h"
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



	while (isRunning) {
		while (SDL_PollEvent(&handler->e)) {
			if (handler->e.type == SDL_QUIT) {
				isRunning = false;
			}
		}

		handler->clearScreen();
		handler->render();

		SDL_Delay(16);
	}
}


EventLoop::~EventLoop() {
	delete handler;
}