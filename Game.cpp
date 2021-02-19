#include "Game.h"

Game::Game() : window("Onyx Game DEV 1.0.0") { }

void Game::update() {
	window.update();
}

void Game::lateUpdate() {}

void Game::draw() {
	window.beginDraw();

	window.endDraw();
}

bool Game::isRunning() const {
	return window.isOpen();
}