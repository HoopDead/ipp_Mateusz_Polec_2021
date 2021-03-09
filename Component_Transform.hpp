#pragma once

#include "Component.hpp"
#include "Logs.hpp"

class Component_Transform : public Component {

public:
	/*
	* Constructor of Component Transition Object
	* Sets the owner of this Compontent and initialise the m_position value
	* @Param: Object* owner - pointer to owner of this Compontent
	* @Return: -
	*/
	Component_Transform(Object* owner);

	/*
	* SetPosition method
	* Sets the position by given x and y values
	* @Param: float x - x coordinate of Object that we want to set
	* @Param: float y - y coordiante of Object that we want to set
	* @Return: -
	*/
	void SetPosition(float x, float y);

	/*
	* SetPosition method
	* Sets the position by given sf::Vector2f value
	* @Param: const sf::Vector2f& pos - constant reference to Vector that we want to set
	* @Return: -
	*/
	void SetPosition(const sf::Vector2f& pos);

	/*
	* AddPosition method
	* Add the position to Object by given x and y values
	* @Param: float x - x coordinate of Object we want to add
	* @Param: float y - y coordinate of Object we want to add
	* @Return: -
	*/
	void AddPosition(float x, float y);

	/*
	* AddPosition method
	* Add the position to Object by given sf::Vector2f value
	* @Param: sf::Vector2f pos - vector that we want to add to Object position.
	* @Return: -
	*/
	void AddPosition(sf::Vector2f pos);

	/*
	* SetX method
	* Separated method to set only X value for Object
	* @Param: float x - x value we want to set for Object
	* @Return: -
	*/
	void SetX(float x);

	/*
	* SetY method
	* Separated method to set only Y value for Object
	* @Param: float y - y value we want to set for Object
	* @Return: -
	*/
	void SetY(float y);

	/*
	* AddX method
	* Separated method to add only X value for Object
	* @Param: float x - x value we want to add for Object
	* @Return: -
	*/
	void AddX(float x);

	/*
	* AddY method
	* Separated method to add only Y value for Object
	* @Param: float y - y value we want to add for Object
	* @Return: - 
	*/
	void AddY(float y);


	/*
	* const GetPosition method
	* Method to get position of player
	* @Param: -
	* @Return: immutable reference to vector of player position
	*/
	const sf::Vector2f& GetPosition() const;

private:

	sf::Vector2f m_position;
};