#include "EventLoop.h"
#include "Drawer.h"
#include "InputHandler.h"
#include <SDL.h>
#include <iostream>

bool EventLoop::initialize() {
	return handler->init();
}

EventLoop::EventLoop() :
	isRunning(true),
	handler(new SDLhandler())
{

}

void EventLoop::run() {


	Drawer drawer;
	InputHandler inputHandler;
	int winner;

	while (isRunning) {
		while (SDL_PollEvent(&handler->e)) {
			inputHandler.handleInput(handler->e, isRunning, handler->getRenderer());
		}
		handler->clearScreen();
		drawer.drawBackground(handler->getRenderer());
		drawer.drawBoard(handler->getRenderer(), inputHandler.getGrid());
		winner = drawer.checkWinner(inputHandler.getGrid());
		if (winner == 1) {
			isRunning = false;
			std::cout << "X wins" << std::endl;
		}
		else if (winner == -1) {
			isRunning = false;
			std::cout << "O wins" << std::endl;
		}
		else if (winner == 2) {
			isRunning = false;
			std::cout << "Draw" << std::endl;
		}
		handler->render();
		SDL_Delay(16);
	}
}


EventLoop::~EventLoop() {
	delete handler;
}