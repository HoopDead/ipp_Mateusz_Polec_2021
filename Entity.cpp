#include "Entity.hpp"

#include <iostream>

Entity::Entity() {
	this->m_active = 1;
	this->m_groupId = 0;
	this->m_dynamic = false;
	Log("Called Entity Constructor");
}


void Entity::Load(std::string filename, bool dynamic) {
	this->m_texture.loadFromFile("Graphics/sprites/" + filename);
	this->m_sprite.setTexture(this->m_texture);
	this->setTexture(this->m_texture);


	this->m_dynamic = dynamic;

}

bool Entity::Update(std::shared_ptr<sf::RenderWindow> window) {
	this->m_sprite.setPosition(32, 32);
	std::cout << "Position of object is: " << this->m_sprite.getPosition().x << " " << this->m_sprite.getPosition().y << "\n";
	window->draw(this->m_sprite);
	return true;
}

int Entity::GroupId() {
	return this->m_groupId;
}

int Entity::Active() {
	return this->m_active;
}

void Entity::Destroy() {
	this->m_active = false;
}

Entity::~Entity() {
	Log("Called Entity Destructor");
}