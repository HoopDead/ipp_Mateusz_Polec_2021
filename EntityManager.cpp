#include "EntityManager.hpp"

EntityManager::EntityManager() {
	Log("Called EntityManager Constructor");
}

void EntityManager::Add(std::string name, std::shared_ptr<Entity> entity) {

	std::unordered_map<std::string, std::shared_ptr<Entity>>::const_iterator found = this->entities.find(name);

	//Security that will protect duplicate names of entities
	while (found != this->entities.end()) {
		name += "0";
		found = this->entities.find(name);
	}
	
	this->entities.insert(std::make_pair(name, entity));

}

//TODO: TEST
void EntityManager::Add(std::string name, std::string filename, bool dynamic) {

	std::unordered_map<std::string, std::shared_ptr<Entity>>::const_iterator found = this->entities.find(name);

	// Security that will protect duplicate names of entities
	while (found != this->entities.end()) {
		name += "0";
		found = this->entities.find(name);
	}

	std::shared_ptr<Entity> entity = std::make_shared<Entity>();
	entity->Load(filename, dynamic);
	this->entities.insert(std::make_pair(name, entity));

}

//TODO TEST:
std::shared_ptr<Entity> EntityManager::Get(std::string name) {

	std::unordered_map<std::string, std::shared_ptr<Entity>>::const_iterator found = this->entities.find(name);

	if (found == this->entities.end()) {
		return nullptr;
	}
	else {
		return found->second;
	}

}

//TODO: TEST
void EntityManager::Render(std::shared_ptr<sf::RenderWindow> window) {

	for (auto& iterator : this->entities) {
		window->draw(iterator.second->m_sprite);
	}
} 

//TODO: TEST
EntityManager::~EntityManager() {
	this->entities.clear();
	Log("Called Entity Manager Destructor");
}