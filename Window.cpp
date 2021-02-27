#include "Window.hpp"


Window::Window(const std::string& windowName)
	: m_window(sf::VideoMode(800, 600), windowName) {
	m_window.setVerticalSyncEnabled(true);
	Log("Called Window Constructor");
}

void Window::Update() {

	sf::Event event;

	if (m_window.pollEvent(event)) 
	{
		input.ConsumeInput(event, m_window);
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

void Window::UpdateInput(std::shared_ptr<Entity> entity) {
	input.SetOwner(entity);
}

Window::~Window() {
	Log("Called Window Destructor");
}