#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Logs.hpp"

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
	void Update();

	/*
	* GetCenter method
	* Return center of View
	* @Param:
	* @Return: const Vector2f - immutable vector of center of view
	*/
	sf::Vector2f GetCenter() const;

	/*
	* GetViewSpace method
	* Return ViewSpace providen by programmer for player
	* @Param: -
	* @Return: FloatRect - immuatble Float Rectangle of View Space for player
	*/
	sf::FloatRect GetViewSpace() const;

	/*
	* GetView method
	* Getter of View for Camera Component
	* @Param: -
	* @Return: const sf::View& - reference of immutable view for Camera
	*/
	const sf::View& GetView() const;

	/*
	* SetView Method
	* Setter of View object
	* @Param: const sf::View& view - reference to const View object
	* @Return: -
	*/
	void SetView(const sf::View& view);

	/*
	* beginDraw method
	* Called, on begin of render method - it has to clear the screen, because otherwise we would see all previous framerates
	* @Param: -
	* @Return: -
	*/
	void BeginDraw();

	/*
	* draw method
	* Called to draw everything on screen
	* @Param: const sf::Drawable (SFML virtual object) reference to drawable - you can pass any drawable object by it. (Rectangle, Sprite etc.)
	* @Return: -
	*/
	void Draw(const sf::Drawable& drawable);


	/*
	* endDraw method
	* Called, to display window on screen
	* @Param: -
	* @Return: -
	*/
	void EndDraw();

	/*
	* isOpen method
	* Returns whether window is alive, or dead
	* @Param: none
	* @Return: boolean represents the state logic state of window.
	*/
	bool IsOpen() const;

	/*
	* Destructor of Window object
	* Created only for tests purposes
	* @Param: -
	* @Return: -
	*/
	~Window();

private:

	sf::RenderWindow m_window;
};