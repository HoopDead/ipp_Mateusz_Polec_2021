#include "Entity.h"

#include <iostream>

Entity::Entity() {
	this->m_active = 1;
	this->m_groupId = 0;
	this->m_dynamic = false;
}

void Entity::load(std::string filename, bool dynamic) {
	this->m_texture.loadFromFile("Graphics/sprites/" + filename);
	this->m_sprite.setTexture(this->m_texture);
	this->setTexture(this->m_texture);

	if (dynamic) {
		this->m_dynamic = true;
	}
	else {
		this->m_dynamic = false;
	}
}

bool Entity::update(std::shared_ptr<sf::RenderWindow> window) {
	this->m_sprite.setPosition(32, 32);
	std::cout << "Position of object is: " << this->m_sprite.getPosition().x << " " << this->m_sprite.getPosition().y << "\n";
	window->draw(this->m_sprite);
	return true;
}

int Entity::groupId() {
	return this->m_groupId;
}

int Entity::active() {
	return this->m_active;
}

void Entity::destroy() {
	this->m_active = false;
}