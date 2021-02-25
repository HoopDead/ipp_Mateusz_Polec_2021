#pragma once

#include <SFML/Graphics.hpp>
#include "Input.h"
#include <string>


class Window {

public:

	/*
	* Construtor of Window object
	* Method creates the new window and sets every option of it provided by user
	* @Param: const std::string reference to Window Name - programmer can provide the name of window
	* @Return: -
	*/
	Window(const std::string& windowName);

	/*
	* Update method
	* Listen for event provided by player from keyboard
	* @Param: -
	* @Return: -
	*/
	void update();

	/*
	* beginDraw method
	* Called, on begin of render method - it has to clear the screen, because otherwise we would see all previous framerates
	* @Param: -
	* @Return: -
	*/
	void beginDraw();

	/*
	* draw method
	* Called to draw everything on screen
	* @Param: const sf::Drawable (SFML virtual object) reference to drawable - you can pass any drawable object by it. (Rectangle, Sprite etc.)
	* @Return: -
	*/
	void draw(const sf::Drawable& drawable);

	/*
	* endDraw method
	* Called, to display window on screen
	* @Param: -
	* @Return: -
	*/
	void endDraw();

	/*
	* isOpen method
	* Returns whether window is alive, or dead
	* @Param: none
	* @Return: boolean represents the state logic state of window.
	*/
	bool isOpen() const;

private:

	sf::RenderWindow m_window;
	Input m_input;

};