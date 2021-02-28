#include "SceneGame.hpp"

SceneGame::SceneGame() {
	Log("Called Scene Game Constructor");
}

void SceneGame::OnCreate() {
	testPlayerTexture.loadFromFile("Graphics/sprites/player_temp.png");
	testPlayerSprite.setTexture(testPlayerTexture);
}

void SceneGame::OnDestroy() {}

void SceneGame::ProcessInput() {
	input.Update();
}

void SceneGame::Update(float deltaTime) {
	Log("Update input");
	if (input.IsKeyPressed(Input::Key::Up)) {
		Log("Key UP Pressed");
	}
	if (input.IsKeyPressed(Input::Key::Down)) {
		Log("Key DOWN Pressed");
	}
	if (input.IsKeyPressed(Input::Key::Left)) {
		Log("Key LEFT Pressed");
	}
	if (input.IsKeyPressed(Input::Key::Right)) {
		Log("Key Right Pressed");
	}
}

void SceneGame::Draw(Window& window) {
	window.Draw(testPlayerSprite);
}

SceneGame::~SceneGame() {
	Log("Called Scene Game Destructor");
}