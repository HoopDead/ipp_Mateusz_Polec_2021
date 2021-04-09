#include "Component_MapCollision.hpp"

Component_MapCollision::Component_MapCollision(Object* owner) : Component(owner) {
	Log("Called Component_MapCollision Constructor!");
}

void Component_MapCollision::SetLayer(tmx::ObjectGroup objectGroup) {
	m_objectGroup = objectGroup;
	Log("Layer set!");
}

void Component_MapCollision::Update(float deltaTime) {
	Log("Updating Collision");
}

Component_MapCollision::~Component_MapCollision() {
	Log("Called Component_MapCollision Destructor!");
}