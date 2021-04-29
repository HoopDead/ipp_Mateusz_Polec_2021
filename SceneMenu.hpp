#pragma once

#include "Scene.hpp"
#include "Window.hpp"
#include "Logs.hpp"
#include "TextTemplate.hpp"
#include "TextCollection.hpp"

class SceneMenu : public Scene {

public:
	//TODO: Documentation
	SceneMenu(Window& window);

	//TODO: Documentation
	void OnCreate() override;

	//TODO: Documentation
	void OnDestroy() override;

	//TODO: Documentation
	void ProcessInput() override;

	//TODO: Documentation
	void Update(float deltaTime) override;

	//TODO: Documentation
	void LateUpdate(float deltaTime) override;

	//TODO: Documentation
	void Draw(Window& window) override;

	//TODO: Documentation
	~SceneMenu();

private:

	Window& m_window;
	TextCollection m_textCollection;
};