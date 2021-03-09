#pragma once

#include <memory>
#include <vector>

#include "Object.hpp"
#include "Logs.hpp"

class ObjectCollection {
public:

	/*
	* ObjectCollection Constructor
	* Created only for test purposes
	*/
	ObjectCollection();

	/*
	* ObjectCollection Destructor
	* Created only for test purposes
	*/
	~ObjectCollection();

	/*
	* Add method
	* Allow to add new object to vector of shared pointers
	* @Param: std::shared_ptr<Object> object - shared pointer to object we want to add
	* @Return: -
	*/
	void Add(std::shared_ptr<Object> object);

	/*
	* Update method
	* Updates all objects in vector
	* @Param: float deltaTime - time between each frame
	* @Return: - 
	*/
	void Update(float deltaTime);

	/*
	* LateUpdate method
	* LateUpdates all objects in vector - handles more challanging operations
	* @Param: float deltaTime - time between each frame
	* @Return: - 
	*/
	void LateUpdate(float deltaTime);

	/*
	* Draw method
	* Renders all objects in vector on screen
	* @Param: Window& window - reference to window that we want to render our objects
	* @Return: - 
	*/
	void Draw(Window& window);

	/*
	* ProcessNewObjects method
	* Awake and Start new objects that was just added to vector
	* @Param: -
	* @Return: -
	*/
	void ProcessNewObjects();

	/*
	* ProcessRemoval method
	* Remove object queued for removal
	* @Param: -
	* @Return: -
	*/
	void ProcessRemoval();

private:
	std::vector<std::shared_ptr<Object>> m_objects;
	std::vector<std::shared_ptr<Object>> m_newObjects;
};