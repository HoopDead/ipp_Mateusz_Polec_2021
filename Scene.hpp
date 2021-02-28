#pragma once

#include "Window.hpp"

class Scene {
public:

	//TODO: Documentation
	virtual void OnCreate() = 0;

	//TODO: Documentation
	virtual void OnDestroy() = 0;

	//TODO: Documentation
	virtual void OnActivate() {};

	//TODO: Documentation
	virtual void OnDeactivate() {};

	//TODO: Documentation
	virtual void ProcessInput() {};

	//TODO: Documentation
	virtual void Update(float deltaTime) {};

	//TODO: Documentation
	virtual void LateUpdate(float deltaTime) {};

	//TODO: Documentation
	virtual void Draw(Window& window) {};

};