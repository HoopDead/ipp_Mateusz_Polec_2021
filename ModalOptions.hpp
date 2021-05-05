#pragma once

#include "ModalTemplate.hpp"
#include "Window.hpp"

class ModalOptions : public ModalTemplate {
public:

	ModalOptions();

	void Initialise() override;

	void Draw(Window& window) override;

	void Activate();

	void Deactivate();

	bool IsActive() const;

	~ModalOptions();

private:

	bool m_isActive;
	sf::RectangleShape m_modalRect;
};