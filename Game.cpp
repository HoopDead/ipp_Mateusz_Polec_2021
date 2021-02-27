#include "Game.h"

Game::Game() : window("Onyx Game DEV 1.0.0") {
	m_deltaTime = m_clock.restart().asSeconds();
	m_testEntity = std::make_shared<Entity>();
	m_entityManager = std::make_unique<EntityManager>();
	m_entityManager->add("Test Entity", m_testEntity);
	window.updateInput(m_testEntity);
	Log("Called Game Constructor");
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
}

bool Game::isRunning() const {
	return window.isOpen();
}

Game::~Game() {
	Log("Called Game Destructor");
}