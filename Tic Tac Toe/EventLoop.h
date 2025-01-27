#pragma once
#include "SDLhandler.h"

class EventLoop
{
public:
	EventLoop();
	~EventLoop();
	bool initialize();
	void run();
	SDLhandler* handler;

private:
	bool isRunning;
};

