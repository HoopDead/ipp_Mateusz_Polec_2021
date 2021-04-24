#pragma once

#include "Window.hpp"
#include "ButtonObject.hpp"
#include "Logs.hpp"

class ButtonObject;

class Button {
public:

	Button(ButtonObject* owner) : owner(owner) {
		Log("Called Button Object Constructor");
	}

	virtual void Awake() {};

	virtual void Start() {};

	virtual void Update(float deltaTime) {};

	virtual void LateUpdate(float deltaTime) {};

	virtual void Draw(Window& window) {};

	~Button() {
		Log("Called Button Object Destructor");
	}

private:

	ButtonObject* owner;
};