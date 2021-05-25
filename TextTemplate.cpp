#include "TextTemplate.hpp"

TextTemplate::TextTemplate() : m_input(nullptr) {
	Log("Called TextTemplate Constructor");
}

TextTemplate::TextTemplate(std::shared_ptr<Input> input) : m_input(input) {}

TextTemplate::TextTemplate(const std::string& text, const float x, const float y, const float size, const int r, const int g, const int b) : 
	m_input(nullptr) {
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


	auto mouse_pos = sf::Mouse::getPosition();
	sf::Vector2f mousePos = { (float)mouse_pos.x, (float)mouse_pos.y };
	const sf::FloatRect text_rect = { m_text.getGlobalBounds().left, m_text.getGlobalBounds().top, m_text.getGlobalBounds().width + m_text.getCharacterSize()* 1.5f, m_text.getGlobalBounds().height + m_text.getCharacterSize()* 1.5f };
	if (text_rect.contains(mousePos) && m_typeOfText == Type::MENU) {
		Log("Contains");
		SetColor(232, 192, 14);
		m_input->Update();
		if (m_input->IsKeyDown(Input::Key::MouseLeft)) {
			for (const auto& action : m_actions) {
				action->RunAction();
			}
		}

	}
	else if (!text_rect.contains(mousePos)) {
		SetColor(255, 255, 255);
	}

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

void TextTemplate::SetFontSize(const float size) {
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

sf::Vector2f TextTemplate::GetDimensions() const {
	const sf::Vector2f textDimensions = { m_text.getLocalBounds().width / 2, m_text.getLocalBounds().height / 2 };
	return textDimensions;
}

void TextTemplate::SetType(Type type) {
	m_typeOfText = type;
}

Type TextTemplate::GetType() const {
	return m_typeOfText;
}

void TextTemplate::Refresh() {
	m_text.setPosition(m_text.getPosition());
}

void TextTemplate::QueueForRemoval() {
	m_isQueuedForRemoval = true;
}

bool TextTemplate::IsQueuedForRemoval() const {
	return m_isQueuedForRemoval;
}


TextTemplate::~TextTemplate() {
	Log("Called Text Template Destructor");
}