#include "Input.hpp"

void Input::Update() {

	m_lastFrameKeys.SetMask(m_frameKeys);

	m_frameKeys.SetBit((int)Key::Up, (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)));

	m_frameKeys.SetBit((int)Key::Down, (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)));

	m_frameKeys.SetBit((int)Key::Left, (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)));

	m_frameKeys.SetBit((int)Key::Right, (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)));

	m_frameKeys.SetBit((int)Key::Esc), sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);

	m_frameKeys.SetBit((int)Key::MouseLeft, sf::Mouse::isButtonPressed(sf::Mouse::Left));

}

bool Input::IsKeyDown(Key keycode) {

	bool lastFrame = m_lastFrameKeys.GetBit((int)keycode);
	bool thisFrame = m_frameKeys.GetBit((int)keycode);

	return !lastFrame && thisFrame;
}

bool Input::IsKeyPressed(Key keycode) {
	return m_frameKeys.GetBit((int)keycode);
}

bool Input::IsKeyUp(Key keycode) {
	
	bool lastFrame = m_lastFrameKeys.GetBit((int)keycode);
	bool thisFrame = m_frameKeys.GetBit((int)keycode);

	return lastFrame && thisFrame;
}