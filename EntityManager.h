#pragma once

#include "Entity.h"
#include <unordered_map>
#include <string>

class EntityManager {

public:

	/*
	* Add method that allow to create new Entity and put it in unordered_map with name and unique pointer to entity
	* Param: std::string name - represents name of object
	* Param: std::unique_ptr<Entity> entity - represents unique pointer to created Entity
	* Return: -
	*/
	void Add(std::string name, std::unique_ptr<Entity> entity);

	/* Add methtod that allow to create new Entity and put it in unordered_map with name, filename and is object dynamic
	* Param: std::string name - represents name of object
	* Param: std::string filename - represent name of file with extension to load Sprite
	* Param: boolean dynamic - set object to dynamic or static
	*/
	void Add(std::string name, std::string filename, bool dynamic);

private:

	std::unordered_map<std::string, std::unique_ptr<Entity>> entities;

};