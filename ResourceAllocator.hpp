#pragma once

#include <map>
#include <memory>
#include <string>
#include "Logs.hpp"

template <typename T>
class ResourceAllocator {
public:
	
	/*
	* Constructor of Resource Allocator Object
	* Created only for test purposes
	*/
	ResourceAllocator() {
		Log("Called Resource Allocator Constructor");
	}

	/*
	* Destructor of Resource Allocator Object
	* Created only for test purposes
	*/
	~ResourceAllocator() {
		Log("Called Resource Allocator Destructor");
	}

	/*
	* Add method
	* Allows programmer to add new resource to map of resources
	* @Param: const std::string& filePath - reference to string that leads to file that we want to load
	* @Return: ID of resouerce that was added to map
	*/
	int Add(const std::string& filePath) {
		auto it = m_resources.find(filePath);

		if (it != m_resources.end()) {
			return it->second.first;
		}

		std::shared_ptr<T> resource = std::make_shared<T>();
		
		if (!resource->loadFromFile(filePath)) {
			return -1;
		}

		m_resources.insert(
			std::make_pair(filePath, std::make_pair(m_currentId, resource)));

		return m_currentId++;

	}

	/*
	* Remove method
	* Allows programmer to remove resource from map full of resources
	* @Param: int id - id of resource we want to remove
	* @Return: -
	*/
	void Remove(int id) {
		for (auto it = m_resources.begin(); it != m_resources.end(); ++it) {
			if (it->second.first == id) {
				m_resources.erase(it->first);
			}
		}
	}

	/*
	* Get method
	* Returns the shared pointer to resource we want to get
	* @Param: int id - id of resource we want to get
	* @Return: if found, shared pointer to resource
	* OR
	* @Return: if not found, nullptr
	*/
	std::shared_ptr<T> Get(int id)
	{
		for (auto it = m_resources.begin(); it != m_resources.end(); ++it)
		{
			if (it->second.first == id)
			{
				return it->second.second;
			}
		}

		return nullptr;
	}

	/*
	* Has method 
	* Check, if resource exists in map
	* @Param: int id - id of resource we want to check
	* @Return: boolean if there is resource or not
	*/
	bool Has(int id) {
		return (Get(id) != nullptr);
	}

private:
	int m_currentId;
	std::map <std::string, std::pair<int, std::shared_ptr<T>>> m_resources;
};