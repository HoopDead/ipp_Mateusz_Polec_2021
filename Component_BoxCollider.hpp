#pragma once
#include "Component.hpp"
#include "Object.hpp"
#include "Logs.hpp"

class Component_BoxCollider : public Component {
public:
	//TODO: Documentation
	Component_BoxCollider(Object* owner);
	
	//TODO: Documentation
	~Component_BoxCollider();

	//TODO: Documentation
	void SetCollidable(const sf::FloatRect& rect);

	//TODO: Documentation
	void SetPosition();

	//TODO: Documentation
	const sf::FloatRect& GetColliderBox() const;
private:
	sf::FloatRect m_AABB;
};