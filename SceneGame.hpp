#pragma once

#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include "Input.hpp"
#include "Object.hpp"
#include "Component_Sprite.hpp"

class SceneGame : public Scene {

public:

	/*
	* Constructor of Scene Game object
	* Created only for tests purpopses
	* @Param: -
	* @Return: -
	*/
	SceneGame();

	/*
	* OnCreate method
	* Called every time, that this (Game Scene) is created, overrided from Scene class
	* @Param: -
	* @Return: -
	*/
	void OnCreate() override;

	/*
	* OnDestroy method
	* Called every time, that this (Game scene) is destroyed, overrided from Scene class
	* @Param: -
	* @Return: -
	*/
	void OnDestroy() override;

	/*
	* ProcessInput method
	* Listen for player event and send it to Input class, overrided from Scene class
	* @Param: -
	* @Return: -
	*/
	void ProcessInput() override;

	//TODO: Documentation
	void Update(float deltaTime) override;
	
	/*
	* Draw method
	* Draw every object to screen of player,
	* @Param: Window& window - Reference to window class
	* @Return: -
	*/
	void Draw(Window &window) override;

	/*
	* Destructor of Scene Game Object
	* Created only for test purposes
	* @Param: -
	* @Return: -	
	*/
	~SceneGame();

private:

	std::shared_ptr<Object> m_player;

	Input input;
};