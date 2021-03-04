#include "Game.hpp"

Game::Game() : window("Onyx Game DEV 1.0.1") {

	std::shared_ptr<SceneGame> gameScene = std::make_shared<SceneGame>();

	unsigned int gameSceneID = sceneStateMachine.Add(gameScene);

	sceneStateMachine.SwitchTo(gameSceneID);

	m_deltaTime = m_clock.restart().asSeconds();
	Log("Called Game Constructor");
}

void Game::ConsumeInput() {
	sceneStateMachine.ProcessInput();
}

void Game::Update() {
	window.Update();

	sceneStateMachine.Update(m_deltaTime);
}

void Game::LateUpdate() {
	sceneStateMachine.LateUpdate(m_deltaTime);
}

void Game::Draw() {
	window.BeginDraw();

	sceneStateMachine.Draw(window);

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