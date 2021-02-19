#pragma once

#include "Window.h"

class Game {

public:

	//TODO: Documentation
	Game();

	//TODO: Documentation
	void update();

	//TODO: Documentation
	void lateUpdate();

	//TODO: Documentation
	void draw();

	//TODO: Documentation
	bool isRunning() const;

private:

	Window window;

};