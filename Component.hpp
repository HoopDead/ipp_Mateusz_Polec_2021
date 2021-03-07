#pragma once

#include "Window.hpp"
#include "Logs.hpp"

class Object;

class Component {
public:

	/*
	* Constructor of Compontent object
	* Constructor of Compontent object is called every time that new Object appers in code, like Player. This method sets owner of new compontent.
	* @Param: Object* owner - Pointer to owner of this Compontent
	* @Return: -
	*/
	Component(Object* owner) : m_owner(owner) {
		Log("Called Compontent Constructor");
	}

	/*
	* Virtual Awake method
	* Method is overrided by Component classes, it's called every time that object is created
	*/
	virtual void Awake() {};

	/*
	* Virtual Start method
	* Called just after Awake method, used to initialise variables. Overrided by Compotnent classes.
	* @Param: -
	* @Return: -
	*/
	virtual void Start() {};

	//TODO: Documentation
	virtual void Update(float deltaTime) {};

	//TODO: Documentation
	virtual void LateUpdate(float deltaTime) {};

	/*
	* Virtual Draw method
	* Called for draw everything on screen from Scene, that needs it. Overrided by Compontent classes.
	* @Param: Window& window - reference to window class
	* @Return: -
	*/
	virtual void Draw(Window& window) {};

	/*
	* Destructor of Compontent
	* Created only for test purposes.
	*/
	~Component() {
		Log("Called Component Destructor");
	}

protected:
	Object* m_owner;

};