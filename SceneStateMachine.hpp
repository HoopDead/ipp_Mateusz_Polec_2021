#pragma once

#include <unordered_map>

#include "Window.hpp"
#include "Scene.hpp"
#include "Logs.hpp"

class SceneStateMachine {

public:

	//TODO: Documentation
	SceneStateMachine();

	//TODO: Documentation
	void Update(float deltaTime);

	//TODO: Documentation
	void ProcessInput();

	//TODO: Documentation
	void LateUpdate(float deltaTime);

	//TODO: Documentation
	void Draw(Window& window);

	//TODO: Documentation
	unsigned int Add(std::shared_ptr<Scene> scene);

	//TODO: Documentation
	void SwitchTo(unsigned int id);

	//TODO: Documentation
	void Remove(unsigned int id);

	~SceneStateMachine();

private:
	
	std::unordered_map<unsigned int, std::shared_ptr<Scene>> m_scenes;

	std::shared_ptr<Scene> m_currentScene;

	unsigned int m_insertedSceneID;


};