#pragma once
#include "Component.hpp"
#include "Object.hpp"
#include "Logs.hpp"

class Component_BoxCollider : public Component {
public:
	/*
	* Construtor of Compontent Box Collider
	* @Param: Object* owner - pointer to owner of this Component
	* @Return: -
	*/
	Component_BoxCollider(Object* owner);
	
	/*
	* Destructor of Component Box Collider
	* Created only for test purposes
	* @Param: -
	* @Return: -
	*/
	~Component_BoxCollider();

	/*
	* SetCollidable method
	* Sets member m_AABB to argument passed to function,
	* @Param: const sf::FloatRect& rect - reference to const sf::FloatRect that represents width and height of sprite loaded to game
	* @Return: -
	*/
	void SetCollidable(const sf::FloatRect& rect);

	/*
	* SetPosition method
	* Update position of member m_AABB to position of sprite
	* @Param: -
	* @Return: -
	*/
	void SetPosition();


	/*
	* Draw method - overriden from Compontent.h
	* Created only for tests purposes to check how big is Sprite compared to BoxCollider
	* @Param: Window& window - reference to window class to render BoxCollider on screen
	* @Return: -
	*/
	void Draw(Window& window) override;

	/*
	* GetColliderBox method
	* Gets the m_AABB member of this class - immutable
	* @Param: -
	* @Return: const sf::FloatRect& const - immutable float rectangle that is member of this class (m_AABB)
	*/
	const sf::FloatRect& GetColliderBox() const;
private:
	sf::FloatRect m_AABB;
};