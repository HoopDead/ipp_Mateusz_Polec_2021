#include "SceneGame.hpp"

SceneGame::SceneGame() {
	Log("Called Scene Game Constructor");
}

void SceneGame::OnCreate() {
	m_player = std::make_shared<Object>();

	// Adds a component by calling our previously written template function.
	auto sprite = m_player->AddComponent<Component_Sprite>();
	auto movement = m_player->AddComponent<Component_KeyboardMovement>();

	sprite->Load("Graphics/sprites/player_temp.png");
	movement->SetInput(&input);
}

void SceneGame::OnDestroy() {}

void SceneGame::ProcessInput() {
	input.Update();
}

void SceneGame::Update(float deltaTime) {
	m_player->Update(deltaTime);
}

void SceneGame::LateUpdate(float deltaTime) {
	m_player->LateUpdate(deltaTime);
}

void SceneGame::Draw(Window& window) {
	m_player->Draw(window);
}

SceneGame::~SceneGame() {
	Log("Called Scene Game Destructor");
}