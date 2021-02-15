#include "Game.h"
#include <iostream>
#include <memory>

void Game::createWindow() {
	this->m_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "Onyx DEV 1.0.0");
	this->m_window->setFramerateLimit(60);
	this->m_player = std::make_unique<Entity>();
	this->m_player->load("player_temp.png", true);
}


void Game::listenEvent() {

		while (this->m_window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				this->m_window->close();
			}
		}

}

void Game::refreshWindow() {
	while (this->m_window->isOpen()) {
		this->render();
		this->listenEvent();
	}
}

void Game::render() {
		this->m_window->clear(sf::Color::Black);
		this->m_player->update(this->m_window);
		this->m_window->display();
}

Game::Game() {
	this->createWindow();
}
