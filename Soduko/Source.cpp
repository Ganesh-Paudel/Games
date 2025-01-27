#include "EventLoop.h"


int main(int argc, char* argv[]) {

	EventLoop loop;
	if (loop.initialize()) {

		loop.run();

	}

	return 0;
}