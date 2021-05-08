#pragma once

#include "Scene.hpp"
#include "Window.hpp"
#include "SceneStateMachine.hpp"
#include "Logs.hpp"
#include "TextTemplate.hpp"
#include "TextCollection.hpp"
#include "TextAction_Exit.hpp"
#include "TextAction_LoadGame.hpp"
#include "TextAction_Options.hpp"
#include "ModalOptions.hpp"
#include "Input.hpp"

class SceneMenu : public Scene {

public:
	//TODO: Documentation
	SceneMenu(Window& window, SceneStateMachine* sceneStateMachine, std::shared_ptr<Input> input, Setup* setup);

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
	SceneStateMachine* m_sceneStateMachine;
	ModalOptions m_modalOptions;
	std::shared_ptr<Input> m_input;
	Setup* m_setup;
};