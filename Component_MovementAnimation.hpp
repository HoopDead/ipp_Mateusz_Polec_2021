#pragma once

#include "Component.hpp"
#include "Component_Velocity.hpp"
#include "Component_Animation.hpp"
#include "Object.hpp"
#include "Logs.hpp"

class Component_MovementAnimation : public Component {
public:
	/*
	* Constructor of Component Movement Animation
	* Sets owner of this Component
	* @Param: Object* owner - pointer to owner of this component
	* @Return: -
	*/
	Component_MovementAnimation(Object* owner);

	/*
	* Awake method, overriden from Component class
	* On wake up sets all members of this class to Components get from owner
	* @Param: -
	* @Return: -
	*/
	void Awake() override;

	/*
	* Update method - overriden from Component class
	* Updates the movement animation depending on Velocity of player
	* @Param: float deltaTime - time between each frame
	*/
	void Update(float deltaTime) override;

	/*
	* Destructor of Movement Animation Component
	* Created only for tests purposes
	*/
	~Component_MovementAnimation();

private:
	std::shared_ptr<Component_Velocity> m_velocity;
	std::shared_ptr<Component_Animation> m_animation;
};