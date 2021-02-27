#pragma once
 
#include "SFML/Window.hpp"
#include <SFML/Graphics.hpp>

class Entity;

class Input
{
public:
	//TODO: Documentation
	Input();

	//TODO: Documentation
	Input(std::shared_ptr<Entity> owner);

	//TODO: Documentation
	void consumeInput(sf::Event event, sf::RenderWindow& window);


	//TODO: Documentation
	void setOwner(std::shared_ptr<Entity> newOwner);

	~Input();

protected:

	std::shared_ptr<Entity> m_owner; 
};

