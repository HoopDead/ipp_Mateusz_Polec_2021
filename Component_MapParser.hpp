#pragma once
#include "Component.hpp"
#include "MapLoader.hpp"

class Component_MapParser : public Component {
public:

	/*
	* Compontent Map Parser Constructor
	* Sets the Object owner for Compontent
	* @Param: Object* owner - pointer to owner of Component
	* @Return: -
	*/
	Component_MapParser(Object* owner);

	/*
	* Awake Method - overriden from Component class
	* Load map and assign each layer
	* @Param: -
	* @Return: -
	*/
	void Awake() override;

	/*
	* Draw method - overriden from component class
	* Draw all of the layers on the window
	* @Param: Window& window - reference to Window class for drawing
	* @Return: -
	*/
	void Draw(Window& window) override;

private:
	tmx::Map m_map;
	MapLayer m_layer_above;
	MapLayer m_layer_main;
	MapLayer m_layer_below;
	MapLayer m_layer_below_1;

};