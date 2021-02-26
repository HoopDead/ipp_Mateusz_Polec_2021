#include "Window.h"


Window::Window(const std::string& windowName)
	: m_window(sf::VideoMode(800, 600), windowName) {
	m_window.setVerticalSyncEnabled(true);
}

void Window::update() {

	sf::Event event;

	if (m_window.pollEvent(event)) 
	{
		m_input.ConsumeInput(event);
	}

}

void Window::beginDraw() {
	m_window.clear(sf::Color::Black);
}

void Window::draw(const sf::Drawable& drawable) {
	m_window.draw(drawable);
}

void Window::endDraw() {
	m_window.display();
}

bool Window::isOpen() const {
	return m_window.isOpen();
}