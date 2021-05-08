#pragma once

#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include "Input.hpp"
#include "Object.hpp"
#include "Component_Sprite.hpp"
#include "Component_KeyboardMovement.hpp"
#include "ResourceAllocator.hpp"
#include "ObjectCollection.hpp"
#include "MapRenderer.h"
#include "Component_Animation.hpp";
#include "Component_MapCollision.hpp";
#include "Component_BoxCollider.hpp"
#include "Component_Camera.hpp"
#include "Component_MovementAnimation.hpp"
#include "Component_Velocity.hpp"

class SceneGame : public Scene {

public:

	/*
	* Constructor of Scene Game object
	* Created only for tests purpopses
	* @Param: -
	* @Return: -
	*/
	SceneGame(ResourceAllocator<sf::Texture>& textureAllocator, Window& window, std::shared_ptr<Input> input);

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

	/*
	* Update method - overriden from Scene class
	* Updates the Objects that are represented on this Scene
	* @Param: float deltaTime - time between each frame
	* @Return: -
	*/
	void Update(float deltaTime) override;
	
	/*
	* LateUpdate method - overriden from Scene class
	* Updates the Objects that are represtend on this Scene and requires more operations to handle
	* @Param: float deltaTime - time between each frame
	* @Return: -
	*/
	void LateUpdate(float deltaTime) override;

	/*
	* Draw method
	* Draw every object to screen of player,
	* @Param: Window& window - Reference to window class
	* @Return: -
	*/
	void Draw(Window &window) override;

	//SECTION: Loading Entities

	/*
	* CreatePlayer Method
	* Initialise all player components
	* @Param: -
	* @Return: -
	*/
	void CreatePlayer();


	/*
	* Destructor of Scene Game Object
	* Created only for test purposes
	* @Param: -
	* @Return: -	
	*/
	~SceneGame();

private:

	Window& m_window;

	std::shared_ptr<MapRenderer> m_mapRenderer;

	ResourceAllocator<sf::Texture>& m_textureAllocator;

	ObjectCollection m_objects;

	std::shared_ptr<Input> m_input;
};