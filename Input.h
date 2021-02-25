#pragma once
#include "SFML/Window.hpp"

class Entity;

class Input
{
public:
	Input();
	Input(Entity* owner);

	void ConsumeInput(sf::Event m_event);

	void setOwner(Entity* NewOwner);

protected:

	/*
		No need for smart pointer, because Entity is already allocated on the Heap
	*/
	Entity* Owner; 
};

