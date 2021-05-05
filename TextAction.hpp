#pragma once

#include "Logs.hpp"


class TextTemplate;

class TextAction {

public:

	TextAction(TextTemplate* owner) : owner(owner) {
		Log("Called TextAction constructor");
	}

	virtual void RunAction() {};

	~TextAction() {
		Log("Called TextAction destructor");
	}

protected:

	TextTemplate* owner;
};