#pragma once
#include "Logs.hpp"
#include "ObjectCollection.hpp"
#include "Component_Animation.hpp"
#include "Component_BoxCollider.hpp"
#include "Component_Camera.hpp"
#include "Component_KeyboardMovement.hpp"
#include "Component_MapCollision.hpp"
#include "Component_MovementAnimation.hpp"
#include "Component_Sprite.hpp"
#include "Component_Velocity.hpp"

class EntityLoader {
public:

	//TODO: Documentation
	EntityLoader() = default;

	//TODO: Documentation
	void Awake();

	//TODO: Documentation
	ObjectCollection GetObjects();

	ObjectCollection operator=(ObjectCollection&& other);

	//TODO: Documentation
	~EntityLoader() = default;


private:

	ObjectCollection m_objects;

};