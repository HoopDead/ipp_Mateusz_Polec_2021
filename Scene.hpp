#pragma once

#include "Window.hpp"

class Scene {
public:

	/*
	* Virtual method OnCreate
	* Method is overriden by Scene (fe. Game Scene), called when new Scene is created
	* @Param: -
	* @Return: -
	*/
	virtual void OnCreate() = 0;

	/*
	* Virtual method OnDestroy
	* Method is overriden by Scene (fe. Game Scene), called when new Scene is destroyed
	* @Param: -
	* @Return: -
	*/
	virtual void OnDestroy() = 0;

	/*
	* Virtual method OnActivate
	* Method can be overriden by Scene (fe. Game Scene), called whenever a scene is transitioned into.
	* @Param: -
	* @Return: -
	*/
	virtual void OnActivate() {};

	/*
	* Virtual method OnDeactivate
	* Method can be overriden by Scene (fe. Game Scene), called whenever a transition is out of scene occurs.
	* @Param: -
	* @Return: -
	*/
	virtual void OnDeactivate() {};

	/*
	* Virtual method ProcessInput
	* Method can be overriden by Scene (fe. Game Scene), process the Input given from keyboard
	* @Param: -
	* @Return: -
	*/
	virtual void ProcessInput() {};

	/*
	* Virtual method Update
	* Method can be overriden by Scene (fe. Game Scene), called every frame to update the operations given in Scene
	* @Param: -
	* @Return: -
	*/
	virtual void Update(float deltaTime) {};

	/*
	* Virtual method LateUpdate
	* Method can be overriden by Scene (fe. Game Scene), called just after Update to handle more aggravating operations
	* @Param: -
	* @Return: -
	*/
	virtual void LateUpdate(float deltaTime) {};

	/*
	* Virtual method Draw
	* Method can be overriden by Scene (fe. Game Scene), called to render after updates to screen
	* @Param: Window& window - reference to Window class
	* @Return: -
	*/
	virtual void Draw(Window& window) {};

};