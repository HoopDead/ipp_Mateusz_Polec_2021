#pragma once

#include "Component.hpp"
#include "Component_BoxCollider.hpp"
#include "MapRenderer.h"
#include "Component_Sprite.hpp"
#include "Component_KeyboardMovement.hpp"
#include "Component_KeyboardMovement.hpp"
#include "Component_Animation.hpp"
#include "Object.hpp"
#include "Logs.hpp"
#include "Component_Velocity.hpp"

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
	* Awake method - overriden from Component class
	* Initialies all members - gets Component from Object class
	* @Param: -
	* @Return: -
	*/
	void Awake() override;

	/*
	* Update method - overriden from Component.h
	* Check if player collides with any of object represented on collision layer
	* @Param: float deltaTime - time between each frame
	* @Return: -
	*/
	void Update(float deltaTime) override;

private:
	std::vector<sf::FloatRect> m_boundPoints;

	std::shared_ptr<Component_BoxCollider> m_boxCollider;
	std::shared_ptr<Component_Velocity> m_velocity;
	std::shared_ptr<Component_Transform> m_transform;
	std::shared_ptr<Component_Animation> m_animation;

};	