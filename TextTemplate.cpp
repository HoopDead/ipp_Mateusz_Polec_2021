#include "TextTemplate.hpp"

TextTemplate::TextTemplate() {
	Log("Called TextTemplate Constructor");
}
TextTemplate::TextTemplate(const std::string& text, const float x, const float y, const float size, const int r, const int g, const int b) {
	SetText(text);
	SetPosition(x, y);
	SetFontSize(size);
	SetColor(r, g, b);
}

void TextTemplate::Awake() {
	if (!m_font.loadFromFile("Graphics/font/PressStart2P-Regular.ttf")) {
		std::cerr << "ERROR: Loading Font!\n";
	}

	m_text.setFont(m_font);
}



void TextTemplate::Update(float deltaTime) {
}

void TextTemplate::Draw(Window& window) {
	window.Draw(m_text);
}

void TextTemplate::SetText(const char* text) {
	m_text.setString(text);
}

void TextTemplate::SetText(const std::string& text) {
	m_text.setString(text);
}

void TextTemplate::SetFontSize(const unsigned int size) {
	m_text.setCharacterSize(size);
}

void TextTemplate::SetColor(const int r, const int g, const int b) {
	m_text.setFillColor(sf::Color(r, g, b));
}


void TextTemplate::SetPosition(const sf::Vector2f& pos) {
	m_text.setPosition(pos);
}

void TextTemplate::SetPosition(const float x, const float y) {
	m_text.setPosition(x, y);
}



TextTemplate::~TextTemplate() {
	Log("Called Text Template Destructor");
}