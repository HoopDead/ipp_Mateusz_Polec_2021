#pragma once

#include "Window.hpp"

class ModalTemplate {
public:

	ModalTemplate() {};

	virtual void Initialise() {};

	virtual void Draw(Window& window) {};

	~ModalTemplate() {};
};