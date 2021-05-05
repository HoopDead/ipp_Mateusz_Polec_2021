	#include "ModalOptions.hpp"

ModalOptions::ModalOptions() : m_isActive(false) {}

void ModalOptions::Initialise() {
	m_modalRect.setSize(sf::Vector2f(500, 700));
	m_modalRect.setFillColor(sf::Color(13, 120, 186));

	ExitModalButton = std::make_shared<TextTemplate>();

	ExitModalButton->Awake();
	ExitModalButton->SetText("CLOSE OPTIONS");
	ExitModalButton->SetFontSize(24);
	ExitModalButton->SetColor(255, 255, 255);
	ExitModalButton->SetType(Type::MENU);
	auto ExitModalAction = ExitModalButton->AddAction<TextAction_ExitOptionsModal>();
	ExitModalAction->SetModal(this);

	m_textCollection.Add(ExitModalButton);
}

void ModalOptions::Update(float deltaTime) {
	if (m_isActive) {
		m_textCollection.Update(deltaTime);
	}
}

void ModalOptions::Draw(Window& window) {
	if (m_isActive) {
		m_modalRect.setPosition(window.GetCenter().x - m_modalRect.getLocalBounds().width / 2, window.GetCenter().y - m_modalRect.getLocalBounds().height / 2);
		ExitModalButton->SetPosition(window.GetCenter().x - ExitModalButton->GetDimensions().x, window.GetCenter().y + m_modalRect.getLocalBounds().height / 2.3);
		window.Draw(m_modalRect);
		m_textCollection.Draw(window);
	}
}

void ModalOptions::Activate() {
	m_isActive = true;
}

void ModalOptions::Deactivate() {
	m_isActive = false;
}

bool ModalOptions::IsActive() const {
	return m_isActive;
}


ModalOptions::~ModalOptions() {}