#pragma once

#include "Component.hpp"
#include "Object.hpp"
#include "Logs.hpp"
#include "Component_Sprite.hpp"
#include "Informations.hpp"

class Component_Camera : public Component {
public:

	/*
	* Camera Component Constructor
	* @Param: Object* owner - pointer to owner of this Component
	*/
	Component_Camera(Object* owner);

	/*
	* LateUpdate Method - overriden from Component.hpp
	* Update Camera to desired view followed by player path
	* @Param: float deltaTime
	* @Return: -
	*/
	void LateUpdate(float deltaTime) override;

	/*
	* SetWindow Method
	* Set Window that "owns" this Camera
	* @Param: Window* window - pointer to window that "owns" this Camera
	* @Return: -
	*/
	void SetWindow(Window* gameWindow);

	/*
	* Component Camera Destructor
	* Created only for test purpopses
	* @Param: -
	* @Return: -
	*/
	~Component_Camera();

private:
	Window* m_window;
};
