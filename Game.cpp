#include "Game.hpp"

Game::Game() : m_window("Onyx Game DEV 1.0.2") {

	std::shared_ptr<SceneGame> gameScene = std::make_shared<SceneGame>(m_textureAllocator, m_window);
	std::shared_ptr<SceneMenu> menuScene = std::make_shared<SceneMenu>(m_window);

	unsigned int menuSceneID = sceneStateMachine.Add(menuScene);
	unsigned int gameSceneID = sceneStateMachine.Add(gameScene);

	sceneStateMachine.SwitchTo(menuSceneID);

	m_deltaTime = m_clock.restart().asSeconds();
	Log("Called Game Constructor");
}

void Game::ConsumeInput() {
	sceneStateMachine.ProcessInput();
}

void Game::Update() {
	m_window.Update();

	sceneStateMachine.Update(m_deltaTime);
}

void Game::LateUpdate() {
	sceneStateMachine.LateUpdate(m_deltaTime);
}

void Game::Draw() {
	m_window.BeginDraw();

	sceneStateMachine.Draw(m_window);

	m_window.EndDraw();
}

void Game::CalculateDeltaTime() {
	m_deltaTime = m_clock.restart().asSeconds();
}

bool Game::IsRunning() const {
	return m_window.IsOpen();
}

Game::~Game() {
	Log("Called Game Destructor");
}