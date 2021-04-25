#pragma once

#include "Window.hpp"
#include "Logs.hpp"

class ButtonObject;

class Button {
public:

	//TODO: Documentation
	Button(ButtonObject* owner) : owner(owner) {
		Log("Called Button Constructor");
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

	//TODO: Documentation
	~Button() {
		Log("Called Button Destructor");
	}

protected:
	ButtonObject* owner; //Because it is used in other, derivered classes

};