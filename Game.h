#pragma once

#include <SFML/Graphics.hpp>

class Game {

private:

	std::unique_ptr<sf::RenderWindow> m_window;
	sf::Event event;
	
public:

	/*
	Constructor for Game class - handle method for createWindow
	Param: null
	Return: null
	*/
	Game();

	/*
	Method that initalize window and set pointer to it
	Param: null
	Return: null
	*/
	void createWindow();


	/*
	Method that draw everything and refresh the window
	Param: null
	Return: null
	*/
	void refreshWindow();

	/*
	Method that listens for any keyboard/mouse provided by player
	Param: null
	Return: null
	*/
	void listenEvent();

	/*
	Method, that render everything to screen while game is alive
	Param: null
	Return: null
	*/
	void render();
};