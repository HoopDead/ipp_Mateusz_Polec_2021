#pragma once

#include <memory>
#include <vector>

#include "ButtonObject.hpp"
#include "Logs.hpp"

class ButtonCollection {
public:

	//TODO: Documentation
	ButtonCollection();

	//TODO: Documentation
	~ButtonCollection();

	//TODO: Documentation
	void Add(std::shared_ptr<ButtonObject> object);

	//TODO: Documentation
	void Update(float deltaTime);

	//TODO: Documentation
	void LateUpdate(float deltaTime);

	//TODO: Documentation
	void Draw(Window& window);

	//TODO: Documentation
	void ProcessNewObjects();

private:
	std::vector<std::shared_ptr<ButtonObject>> m_ButtonObjects;
	std::vector<std::shared_ptr<ButtonObject>> m_ButtonNewObjects;
};