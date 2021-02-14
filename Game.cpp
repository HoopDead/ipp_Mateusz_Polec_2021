#include "Game.h"
#include <iostream>
#include <memory>

void Game::createWindow() {
	this->m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 600), "Onyx DEV 1.0.0");
	this->m_window->setFramerateLimit(60);
}

void Game::refreshWindow() {
	this->m_window->clear(sf::Color::Black);
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(100, 50));
	rectangle.setOutlineColor(sf::Color::Red);
	rectangle.setOutlineThickness(5);
	rectangle.setPosition(10, 20);
	this->m_window->draw(rectangle);
	this->m_window->display();
	std::cout << "Refresh window called" << "\n";
}

void Game::listenEvent() {
	while (this->m_window->isOpen()) {
		while (this->m_window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				this->m_window->close();
			}
		}
	}
}

void Game::render() {
	std::cout << "Render called" << "\n";

	while (this->m_window->isOpen()) {
		this->m_window->clear(sf::Color::Black);
		sf::RectangleShape rectangle;
		rectangle.setSize(sf::Vector2f(100, 50));
		rectangle.setOutlineColor(sf::Color::Red);
		rectangle.setOutlineThickness(5);
		rectangle.setPosition(10, 20);
		this->m_window->draw(rectangle);
		this->m_window->display();
	}
}

Game::Game() {
	this->createWindow();
	std::cout << "Constructor called" << "\n";
}
