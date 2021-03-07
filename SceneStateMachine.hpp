#pragma once

#include <unordered_map>

#include "Window.hpp"
#include "Scene.hpp"
#include "Logs.hpp"

class SceneStateMachine {

public:

	/*
	* Constructor of Scene State Machine
	* Construtor intialise the private values to empty, null or zero
	* @Param: -
	* @Return: -
	*/
	SceneStateMachine();

	/*
	* Update Method
	* Called every frame to update operations given by Player
	* @Param: float deltaTime - time between each frame
	* @Return: -
	*/
	void Update(float deltaTime);

	/*
	* ProcessInput Method
	* Checks, wheter player has clicked something on current scene or not
	* @Param: -
	* @Return: -
	*/
	void ProcessInput();

	/*
	* LateUpdate method
	* Called just after Update method to handle more aggravating operations
	* @Param: float deltaTime - time between each frame,
	* @Return: -
	*/
	void LateUpdate(float deltaTime);

	/*
	* Draw Method
	* Used to Draw render current scene
	* @Param: Window& window - reference to the window
	*/
	void Draw(Window& window);

	/*
	* Add Method
	* Used to Add new shared pointer of Scene to Scenes
	* @Param: shared pointer to Scene
	* @Return: ID of Scene that has been added to Scenes vector.
	*/
	unsigned int Add(std::shared_ptr<Scene> scene);

	/*
	* SwitchTo method
	* Used to Switch between scenes by given id
	* @Param: ID of Scene that we want to Switch
	* @Return: -
	*/
	void SwitchTo(unsigned int id);

	/*
	* Remove method
	* Used to remove scene by given ID
	* @Param: ID of scene that we want to remove
	*/
	void Remove(unsigned int id);

	~SceneStateMachine();

private:
	
	std::unordered_map<unsigned int, std::shared_ptr<Scene>> m_scenes;

	std::shared_ptr<Scene> m_currentScene;

	unsigned int m_insertedSceneID;


};