#pragma once

#include "Window.hpp"
#include "MapLoader.hpp"
#include "Logs.hpp"
#include "Informations.hpp"

struct MapRenderer {
public:
	/*
	* Constructor of Map Renderer Object
	* @Param: -
	* @Return: -
	*/
	MapRenderer();

	/*
	* Destructor of Map Renderer Object
	* Created only for test purposes
	*/
	~MapRenderer();

	/*
	* Awake Method
	* Initialise all layers and load map into the members of this class
	* @Param: -
	* @Return: -
	*/
	void Awake();

	/*
	* Draw method
	* Render all layers on window
	* @Param: Window& window - reference to window where map is rendering
	* @Return: -
	*/
	//void Draw(Window& window);

	/*
	* DrawLayersBelow method
	* Draw all layers that must be located BELOW Entities like Player, NPCs
	* @Param: Window& window - reference to Window class
	* @Return: -
	*/
	void DrawLayersBelow(Window& window);

	/*
	* DrawLayersAbove method
	* Draw all layers that must be located ABOVE Entities like Player, NPCs
	* Param: Window& window - reference to Window class
	* @Return: -
	*/
	void DrawLayersAbove(Window& window);

	/*
	* GetCollisionLayer method
	* Getter of collision layer
	* @Param: -
	* @Return: tmx::ObjectGroup - all objects that are based on collision layer
	*/
	tmx::ObjectGroup GetCollisionLayer();

private:
		
	tmx::Map m_map;
	MapLayer m_layer_above_2;
	MapLayer m_layer_above_1;
	MapLayer m_layer_main;
	MapLayer m_layer_below;
	MapLayer m_layer_below_1;
	MapLayer m_layer_below_2;
	MapLayer m_layer_collision;

};