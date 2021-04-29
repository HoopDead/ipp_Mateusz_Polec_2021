#pragma once

#include <SFML/Graphics.hpp>

#include "Window.hpp"
#include "Logs.hpp"

class TextTemplate {

public:

	TextTemplate();

	TextTemplate(const std::string& text, const float x, const float y, const float size, const int r, const int g, const int b);

	void Awake();

	void Update(float deltaTime);

	void Draw(Window& window);

	void SetText(const char* text);

	void SetText(const std::string& text);

	void SetFontSize(const unsigned int size);

	void SetColor(const int r, const int g, const int b);

	void SetPosition(const sf::Vector2f& pos);

	void SetPosition(const float x, const float y);

	~TextTemplate();

private:
	sf::Font m_font;
	sf::Text m_text;

};