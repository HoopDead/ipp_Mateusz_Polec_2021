#pragma once

#include "Component.hpp"
#include "MapRenderer.h"
#include "Object.hpp"
#include "Logs.hpp"

class Component_MapCollision : Component {

public:

	Component_MapCollision(Object* owner);
	~Component_MapCollision();
};