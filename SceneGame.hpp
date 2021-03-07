#pragma once

#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include "Input.hpp"
#include "Object.hpp"
#include "Component_Sprite.hpp"

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

	std::shared_ptr<Object> m_player;

	Input input;
};