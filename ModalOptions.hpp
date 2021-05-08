#pragma once

#include "ModalTemplate.hpp"
#include "Window.hpp"
#include "TextTemplate.hpp"
#include "TextCollection.hpp"
#include "TextAction_ExitOptionsModal.hpp"
#include "TextAction_ChangeResolution.hpp"

class ModalOptions : public ModalTemplate {
public:

	ModalOptions();

	void Initialise(std::shared_ptr<Input> input, Setup* setup, Window* window);

	void Update(float deltaTime) override;

	void Draw(Window& window) override;

	void Activate();

	void Deactivate();

	bool IsActive() const;

	~ModalOptions();

private:

	bool m_isActive;
	sf::RectangleShape m_modalRect;
	TextCollection m_textCollection;
	std::shared_ptr<TextTemplate> ExitModalButton;
	std::shared_ptr<TextTemplate> ResolutionRawText;
	std::shared_ptr<TextTemplate> ResolutionText;
	std::shared_ptr<Input> m_input;
	Setup* m_setup;
	Window* m_window;

};