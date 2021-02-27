#include "Game.hpp"

Game::Game() : window("Onyx Game DEV 1.0.1") {
	m_deltaTime = m_clock.restart().asSeconds();
	m_testEntity = std::make_shared<Entity>();
	m_entityManager = std::make_unique<EntityManager>();
	m_entityManager->Add("Test Entity", m_testEntity);
	window.UpdateInput(m_testEntity);
	Log("Called Game Constructor");
}

void Game::Update() {
	window.Update();
}

void Game::LateUpdate() {}

void Game::Draw() {
	window.BeginDraw();

	window.EndDraw();
}

void Game::CalculateDeltaTime() {
	m_deltaTime = m_clock.restart().asSeconds();
}

bool Game::IsRunning() const {
	return window.IsOpen();
}

Game::~Game() {
	Log("Called Game Destructor");
}