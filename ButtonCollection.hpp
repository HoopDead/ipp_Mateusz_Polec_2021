#pragma once

#include "ButtonObject.hpp"

class ButtonCollection {
public:
	ButtonCollection();

	void Add(std::shared_ptr<ButtonObject> buttonObject);

	void Update(float deltaTime);

	void LateUpdate(float deltaTime);

	void Draw(Window& window);

	void ProcessNewObjects();

	~ButtonCollection();

private:

	std::vector<std::shared_ptr<ButtonObject>> m_newObjects;
	std::vector<std::shared_ptr<ButtonObject>> m_objects;
};