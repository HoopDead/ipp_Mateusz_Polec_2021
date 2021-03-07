#pragma once

#include "Window.hpp"
#include "SceneStateMachine.hpp"
#include "SceneGame.hpp"

class Game {

public:

	/* Constructor of Game Object
	* Intialise code for Game class, right now it sets Window object running
	* @Param: -
	* @Return: -
	*/
	Game();

	/*
	* Update method
	* Handling the most of game logic - movement, AI & animation updates. Right now it updates only window class with update method
	* @Param: -
	* @Return: -
	*/
	void Update();

	void ConsumeInput();

	/*
	* LateUpdate method
	* Handling the logic relies on data calculated in update method.
	* @Param: -
	* @Return: -
	*/
	void LateUpdate();

	/*
	* Draw method
	* When every Entity object is updated it needs to be drawed on screen. Method is responsible for drawing everything.
	* @Param: -
	* @Return: -
	*/
	void Draw();

	/*
	* calculateDeltaTime method
	* calculate the time need to update between two framerates
	* @Param: -
	* @Return: -
	*/
	void CalculateDeltaTime();

	/*
	* isRunning method
	* Returns whether window is alive, or dead
	* @Param: -
	* @Return: boolean represents the state logic state of window.
	*/
	bool IsRunning() const;

	~Game();

private:

	//Construtor is called from windows.h
	Window window;

	
	//Handling time in game
	sf::Clock m_clock;
	float m_deltaTime;

	//Handling scenes
	SceneStateMachine sceneStateMachine;



};