#include "Component_MapCollision.hpp"

Component_MapCollision::Component_MapCollision(Object* owner) : Component(owner) {
	Log("Called Component_MapCollision Constructor!");
}

Component_MapCollision::~Component_MapCollision() {
	Log("Called Component_MapCollision Destructor!");
}