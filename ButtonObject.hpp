#pragma once

#include "Window.hpp"
#include "Button.hpp"

class ButtonObject {

public:

	ButtonObject();

	void Awake();

	void Update(float deltaTime);

	void LateUpdate(float deltaTime);

	void Draw(Window& draw);

	template <typename T> std::shared_ptr<T> AddButton() {

		static_assert(std::is_base_of<Button, T>::value,
			"T must derive from Button");

		for (auto& existingButton : m_buttons) {
			if (std::dynamic_pointer_cast<T>(existingButton)) {
				return std::dynamic_pointer_cast<T>(existingButton);
			}
		}

		std::shared_ptr<T> newButton = std::make_shared<T>(this);
		m_buttons.push_back(newButton);

		return newButton;
	};

	template <typename T> std::shared_ptr<T> GetButton() {

		static_assert(std::is_base_of<Button, T>::value,
			"T must derive from Button");

		for (auto& existingButton : m_buttons) {
			if (std::dynamic_pointer_cast<T>(existingButton)) {
				return std::dynamic_pointer_cast<T>(existingButton);
			}
		}

		return nullptr;
	};


	~ButtonObject();

private:
	std::vector<std::shared_ptr<Button>> m_buttons;
};