#pragma once

#include "Window.hpp"
#include "TextTemplate.hpp"

class TextCollection {

public:

	/*
	* TextCollection Constructor
	* Initialise TextCollection Object
	* @Param: -
	* @Return: -
	*/
	TextCollection();

	/*
	* Awake Method
	* Loop thru m_texts texts and run Awake() method on them
	* @Param: -
	* @Return: -
	*/
	void Awake();

	/*
	* Update Method
	* Update each Text by difference time between each frame
	* @Param: float deltaTime - time between each frame
	* @Return: -
	*/
	void Update(float deltaTime);

	/*
	* Draw Method
	* Draw Texts on window
	* @Param: Window& window - reference to Window class
	* @Return: -
	*/
	void Draw(Window& window);

	/*
	* Add Method
	* Add new text to m_texts member
	* @Param: std::shared_ptr<texttemplate> text - shared pointer to text that we want to add
	* @Return: -
	*/
	void Add(std::shared_ptr<TextTemplate> text);

	//TODO: Implement Remove method.

	/*
	* Destructor of TextCollection Object
	* Created only for test purposes.
	*/
	~TextCollection();

private:

	std::vector<std::shared_ptr<TextTemplate>> m_texts;


};