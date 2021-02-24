#pragma once

#include "Window.h"

class Game {

public:

	/* Constructor of Game Object
	* Intialise code for Game class, right now it sets Window object running
	* @Param: none
	* @Return: none
	*/
	Game();

	/*
	* Update method
	* Handling the most of game logic - movement, AI & animation updates. Right now it updates only window class with update method
	* @Param: none
	* @Return: none
	*/
	void update();

	/*
	* LateUpdate method
	* Handling the logic relies on data calculated in update method.
	* @Param: none
	* @Return: none
	*/
	void lateUpdate();

	/*
	* Draw method
	* When every Entity object is updated it needs to be drawed on screen. Method is responsible for drawing everything.
	* @Param: none
	* @Return: none
	*/
	void draw();

	/*
	* isRunning method
	* Returns whether window is alive, or dead
	* @Param: none
	* @Return: boolean represents the state logic state of window.
	*/
	bool isRunning() const;

private:

	Window window;

};