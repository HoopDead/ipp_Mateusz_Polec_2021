#pragma once

#include "Window.hpp"
#include "Logs.hpp"

class Object;

class Component {
public:

	//TODO: Documentation
	Component(Object* owner) : m_owner(owner) {
		Log("Called Compontent Constructor");
	}

	//TODO: Documentation
	virtual void Awake() {};

	//TODO: Documentation
	virtual void Start() {};

	//TODO: Documentation
	virtual void Update(float deltaTime) {};

	//TODO: Documentation
	virtual void LateUpdate(float deltaTime) {};

	//TODO: Documentation
	virtual void Draw(Window& window) {};

	~Component() {
		Log("Called Component Destructor");
	}

protected:
	Object* m_owner;

};