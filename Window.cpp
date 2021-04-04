#include "Window.hpp"


Window::Window(const std::string& windowName)
	: m_window(sf::VideoMode(1920, 1080), windowName) {
	m_window.setVerticalSyncEnabled(true);
	Log("Called Window Constructor");
}

void Window::Update() {

	sf::Event event;

	if (m_window.pollEvent(event)) 
	{
		if (event.type == sf::Event::Closed) {
			m_window.close();
		}
	}

}

void Window::BeginDraw() {
	m_window.clear(sf::Color::Black);
}

void Window::Draw(const sf::Drawable& drawable) {
	m_window.draw(drawable);
}

void Window::EndDraw() {
	m_window.display();
}

bool Window::IsOpen() const {
	return m_window.isOpen();
}

Window::~Window() {
	Log("Called Window Destructor");
}