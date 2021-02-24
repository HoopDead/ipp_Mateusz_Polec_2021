#include <iostream>
#include "Game.h"

int main() {

	Game game;

	while (game.isRunning()) {

		game.update();
		game.lateUpdate();
		game.draw();
		game.calculateDeltaTime();
	}

	return 0;
}