#include "ModalGamePause.hpp"

ModalGamePause::ModalGamePause() : m_isActive(false) {}

void ModalGamePause::Initialise(std::shared_ptr<Input> input, Window* window) {
	m_input = input;
	m_window = window;
	//m_modalRect.setSize(sf::Vector2f(150, 50));
	//m_modalRect.setFillColor(sf::Color(13, 120, 186));

	ExitModalButton = std::make_shared<TextTemplate>(m_input);

	ExitModalButton->Awake();
	ExitModalButton->SetText("GAME PAUSED");
	ExitModalButton->SetFontSize(36);
	ExitModalButton->SetColor(255, 255, 255);
	ExitModalButton->SetType(Type::RAW);

	m_textCollection.Awake();

	m_textCollection.Add(ExitModalButton);
}

void ModalGamePause::Update(float deltaTime) {
	if (m_isActive) {
		m_textCollection.Update(deltaTime);
	}
}

void ModalGamePause::Draw(Window& window) {
	if (m_isActive) {
		//m_modalRect.setPosition(window.GetCenter().x - m_modalRect.getLocalBounds().width / 2, window.GetCenter().y - m_modalRect.getLocalBounds().height / 2);
		ExitModalButton->SetPosition(window.GetCenter().x - ExitModalButton->GetDimensions().x, window.GetCenter().y);
		//window.Draw(m_modalRect);
		m_textCollection.Draw(window);
	}
}

void ModalGamePause::Activate() {
	m_isActive = true;
}

void ModalGamePause::Deactivate() {
	m_isActive = false;
}

bool ModalGamePause::IsActive() const {
	return m_isActive;
}


ModalGamePause::~ModalGamePause() {}