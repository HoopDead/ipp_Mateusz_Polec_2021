#include <iostream>
#include "Game.hpp"

int main() {

	Game game;

	while (game.IsRunning()) {
		game.ConsumeInput();
		game.Update();
		game.LateUpdate();
		game.Draw();
		game.CalculateDeltaTime();
	}

	return 0;
}