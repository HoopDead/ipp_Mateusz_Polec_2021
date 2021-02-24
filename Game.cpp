#include "Game.h"

Game::Game() : window("Onyx Game DEV 1.0.0") {
	m_deltaTime = m_clock.restart().asSeconds();
}

void Game::update() {
	window.update();
}

void Game::lateUpdate() {}

void Game::draw() {
	window.beginDraw();

	window.endDraw();
}

void Game::calculateDeltaTime() {
	m_deltaTime = m_clock.restart().asSeconds();
	LogAll("Delta time: ", m_deltaTime);
}

bool Game::isRunning() const {
	return window.isOpen();
}