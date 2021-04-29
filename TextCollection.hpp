#pragma once

#include "Window.hpp"
#include "TextTemplate.hpp"

class TextCollection {

public:

	TextCollection();

	void Awake();

	void Update(float deltaTime);

	void Draw(Window& window);

	void Add(std::shared_ptr<TextTemplate> text);


	~TextCollection();

private:

	std::vector<std::shared_ptr<TextTemplate>> m_texts;


};