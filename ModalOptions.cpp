#include "ModalOptions.hpp"

ModalOptions::ModalOptions() : m_isActive(false) {}

void ModalOptions::Initialise() {
	m_modalRect.setSize(sf::Vector2f(128, 256));
	m_modalRect.setFillColor(sf::Color(255, 255, 255));
}

void ModalOptions::Draw(Window& window) {
	if (m_isActive) {
		m_modalRect.setPosition(window.GetCenter().x - m_modalRect.getLocalBounds().width / 2, window.GetCenter().y - m_modalRect.getLocalBounds().height / 2);
		window.Draw(m_modalRect);
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