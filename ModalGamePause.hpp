#pragma once

#include "ModalTemplate.hpp"
#include "Window.hpp"
#include "TextTemplate.hpp"
#include "TextCollection.hpp"

class ModalGamePause : public ModalTemplate {
public:

	ModalGamePause();

	void Initialise(std::shared_ptr<Input> input, Window* window);

	void Update(float deltaTime) override;

	void Draw(Window& window) override;

	void Activate();

	void Deactivate();

	bool IsActive() const;

	~ModalGamePause();

private:

	bool m_isActive;
	TextCollection m_textCollection;
	std::shared_ptr<TextTemplate> ExitModalButton;
	std::shared_ptr<Input> m_input;
	Window* m_window;

};