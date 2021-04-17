#pragma once

#include <math.h>
#include "Component.hpp"
#include "Logs.hpp"
#include "Object.hpp"

class Component_Velocity : public Component {

public:

	/*
	* Constructor of Velocity Component
	* Sets the owner of this Component
	* @Param: Object* owner - pointer to owner of this Component
	*/
	Component_Velocity(Object* owner);

	/*
	* Update method - overriden from Component
	* Transfer owner of this Component by velocity and time between frames
	* @Param: float deltaTime - time between each frame
	* @Return: -
	*/
	void Update(float deltaTime) override;

	/*
	* Set Method
	* Sets the Velocity for owner of this Component
	* @Param: const sf::Vector2f& velocity - reference to constant vector to set new velocity
	* @Return: -
	*/
	void Set(const sf::Vector2f& velocity);

	/*
	* Set Method
	* Sets the Velocity for owner of this Component
	* @Param: float x - x-axis velocity
	* @Param: float y - y-axis velocity 
	*/
	void Set(float x, float y);

	/*
	* Get Method
	* Return the current immutable velocity of owner of this Component
	* @Param: -
	* @Return: immutable sf::Vector2f with velocity of player x - x-axis, y - y.axis
	*/
	const sf::Vector2f& Get() const;

	/*
	* Destructor of Velocity Component
	* Created only for test purposes
	*/
	~Component_Velocity();

private:
	
	/*
	* ClamVelocity method
	* Checks if player is not going faster than maxVelocity
	* @Param: -
	* @Return: -
	*/
	void ClampVelocity();

	sf::Vector2f m_velocity;
	sf::Vector2f m_maxVelocity;
};