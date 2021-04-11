#pragma once

#include "Component.hpp"
#include "Component_BoxCollider.hpp"
#include "MapRenderer.h"
#include "Object.hpp"
#include "Logs.hpp"

class Component_MapCollision : public Component {

public:
	//TODO: Documentation
	Component_MapCollision(Object* owner);

	//TODO: Documentation
	~Component_MapCollision();

	//TODO: Documentation
	void SetLayer(tmx::ObjectGroup objectGroup);

	//TODO: Documentation
	void Update(float deltaTime) override;

private:
	std::vector<sf::FloatRect> m_boundPoints;
};