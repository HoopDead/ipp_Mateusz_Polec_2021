#pragma once

#include "Entity.h"
#include <unordered_map>
#include <string>
#include <iostream>

class EntityManager {

public:

	/*
	* Add method that allow to create new Entity and put it in unordered_map with name and unique pointer to entity
	* @Param: std::string name - represents name of object
	* @Param: std::unique_ptr<Entity> entity - represents unique pointer to created Entity
	* @Return: -
	*/
	void add(std::string name, std::shared_ptr<Entity> entity);

	/* 
	* Add methtod that allow to create new Entity and put it in unordered_map with name, filename and is object dynamic
	* @Param: std::string name - represents name of object
	* @Param: std::string filename - represent name of file with extension to load Sprite
	* @Param: boolean dynamic - set object to dynamic or static
	* @Return: -
	*/
	void add(std::string name, std::string filename, bool dynamic);
	
	/* 
	* Get method that allow to get pointer to entity by knowing only name of it
	* @Param: std::string name - name of entity that we want to get
	* @Return: nullptr if there's no entity with that name, or pointer to entity if found
	*/
	std::shared_ptr<Entity> get(std::string name);

	/*
	* Render method for render every entity in unordered map to screen
	* @Param: Shared Pointer to window that needs to be rendered
	* @Return: -
	*/
	void render(std::shared_ptr<sf::RenderWindow> window);

	~EntityManager();

private:

	std::unordered_map<std::string, std::shared_ptr<Entity>> entities;

};