#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Logs.hpp"


class Entity : sf::Sprite {

public:

	sf::Vector2f m_velocity;

	virtual void Load(std::string filename, bool dynamic);

	virtual bool Update(std::shared_ptr<sf::RenderWindow> window);


	Entity();

	void Destroy();

	int Active();

	int GroupId();

	~Entity();

private:

	bool m_active;
	bool m_dynamic;
	int m_groupId;

public:

	sf::Texture m_texture;
	sf::Sprite m_sprite;
};