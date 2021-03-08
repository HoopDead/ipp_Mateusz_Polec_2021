#pragma once

#include "Component.hpp"
#include "Logs.hpp"

class Component_Transform : public Component {

public:
	//TODO: Documentation
	Component_Transform(Object* owner);

	//TODO: Documentation
	void SetPosition(float x, float y);

	//TODO: Documentation
	void SetPosition(const sf::Vector2f& pos);

	//TODO: Documentation
	void AddPosition(float x, float y);

	//TODO: Documentation
	void AddPosition(sf::Vector2f pos);

	//TODO: Documentation
	void SetX(float x);

	//TODO: Documentation
	void SetY(float y);

	//TODO: Documentation
	void AddX(float x);

	//TODO: Documentation
	void AddY(float y);


	const sf::Vector2f& GetPosition() const;

private:

	sf::Vector2f m_position;
};