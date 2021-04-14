#pragma once

#include "Component.hpp"
#include "Component_BoxCollider.hpp"
#include "MapRenderer.h"
#include "Component_Sprite.hpp"
#include "Object.hpp"
#include "Logs.hpp"

class Component_MapCollision : public Component {

public:
	/*
	* Constructor of Map Collision Component
	* @Param: Object* owner - pointer to owner of this component
	* @Return: -
	*/
	Component_MapCollision(Object* owner);

	/*
	* Destructor of Map Collision Component
	* Created only for test purpopses
	* @Param: -
	* @Return: -
	*/
	~Component_MapCollision();

	/*
	* SetLayer method
	* Sets layer that is considered to be layer that have all collision tiles/objects
	* @Param: tmx::ObjectGroup objectGroup - all objects that covers map and are collision tiles/rectangles
	* @Return: -
	*/
	void SetLayer(tmx::ObjectGroup objectGroup);

	/*
	* Update method - overriden from Component.h
	* Check if player collides with any of object represented on collision layer
	* @Param: float deltaTime - time between each frame
	* @Return: -
	*/
	void Update(float deltaTime) override;

private:
	std::vector<sf::FloatRect> m_boundPoints;
};