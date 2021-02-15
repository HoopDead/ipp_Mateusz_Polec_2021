#pragma once

#include <SFML/Graphics.hpp>
#include <string>


class Entity : sf::Sprite {

public:

	sf::Vector2f m_velocity;

	virtual void load(std::string filename, bool dynamic);

	virtual bool update(std::shared_ptr<sf::RenderWindow> window);


	Entity();

	void destroy();

	int active();

	int groupId();

private:

	bool m_active;
	bool m_dynamic;
	int m_groupId;

public:

	sf::Texture m_texture;
	sf::Sprite m_sprite;
};