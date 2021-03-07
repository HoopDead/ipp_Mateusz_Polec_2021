#pragma once

#include <SFML/Graphics.hpp>
#include "Bitmask.hpp"
#include "Logs.hpp"

class Input {

public:

	enum class Key {
		None = 0,
		Left = 1,
		Right = 2,
		Up = 3,
		Down = 4,
		Esc = 5
	};

	/*
	* Update method
	* Check what key has ben pressed and set bitmask for pressed keys.
	* @Param: -
	* @Return: -
	*/
	void Update();

	/*
	*  isKeyPressed method
	* Check, if key from enum declared above is pressed
	* @Param: Key keycode - code of key that is pressed
	* @Return: Boolean wheter key is pressed or not
	*/
	bool IsKeyPressed(Key keycode);

	/*
	* isKeyDown method
	* Check, if key is pressed down all the time.
	* @Param: Key keycode - code of key that is pressed
	* @Return: Boolean if Bit for this keycode is True or False
	*/
	bool IsKeyDown(Key keycode);

	/*
	* isKeyUp method
	* Check, if key was released
	* @Param: Key keycode - code of key that has been released
	* @Return: Boolean wheter key is released or not
	*/
	bool IsKeyUp(Key keycode);

private:

	Bitmask m_frameKeys;
	Bitmask m_lastFrameKeys;
};