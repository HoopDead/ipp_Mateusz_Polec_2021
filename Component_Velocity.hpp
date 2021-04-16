#pragma once

#include <math.h>
#include "Component.hpp"
#include "Logs.hpp"
#include "Object.hpp"

class Component_Velocity : public Component {

public:

	//TODO: Documentation
	Component_Velocity(Object* owner);

	//TODO: Documentation
	void Update(float deltaTime) override;

	//TODO: Documentation
	void Set(const sf::Vector2f& velocity);

	//TODO: Documentation
	void Set(float x, float y);

	//TODO: Documentation
	const sf::Vector2f& Get() const;

	//TODO: Documentation
	~Component_Velocity();

private:
	
	//TODO: Documentation
	void ClampVelocity();

	sf::Vector2f m_velocity;
	sf::Vector2f m_maxVelocity;
};