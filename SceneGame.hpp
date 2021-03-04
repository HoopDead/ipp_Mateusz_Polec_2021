#pragma once

#include "Scene.hpp"
#include "Input.hpp"
#include <SFML/Graphics.hpp>

class SceneGame : public Scene {

public:
	SceneGame();

	void OnCreate() override;

	void OnDestroy() override;

	void ProcessInput() override;

	void Update(float deltaTime) override;
	
	void Draw(Window &window) override;

	~SceneGame();

private:
	sf::Texture testPlayerTexture;
	sf::Sprite testPlayerSprite;

	Input input;
};