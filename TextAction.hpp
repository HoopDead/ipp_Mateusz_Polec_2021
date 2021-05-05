#pragma once

#include "Logs.hpp"
#include "Window.hpp"


class TextTemplate;

class TextAction {

public:

	TextAction(TextTemplate* owner) : owner(owner) {
		Log("Called TextAction constructor");
	}

	virtual void RunAction() {};

	virtual void Draw(Window& window) {};

	~TextAction() {
		Log("Called TextAction destructor");
	}

protected:

	TextTemplate* owner;
};