#pragma once

#include "Component.hpp"
#include "Component_Velocity.hpp"
#include "Component_Animation.hpp"
#include "Object.hpp"
#include "Logs.hpp"

class Component_MovementAnimation : public Component {
public:
	//TODO: Documentation
	Component_MovementAnimation(Object* owner);

	//TODO: Documentation
	void Awake() override;

	//TODO: Documentation
	void Update(float deltaTime) override;

	//TODO: Documentation
	~Component_MovementAnimation();

private:
	std::shared_ptr<Component_Velocity> m_velocity;
	std::shared_ptr<Component_Animation> m_animation;
};