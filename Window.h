#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Window {

public:

	//TODO: Documentation
	Window(const std::string& windowName);

	//TODO: Documentation
	void update();

	//TODO: Documentation
	void beginDraw();

	//TODO: Documentation
	void draw(const sf::Drawable& drawable);

	//TODO: Documentation
	void endDraw();

	//TODO: Documentation
	bool isOpen() const;

private:

	sf::RenderWindow m_window;

};