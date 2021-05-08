#pragma once

#include <SFML/Graphics.hpp>

#include "Window.hpp"
#include "Logs.hpp"
#include "TextAction.hpp"
#include "Input.hpp"


enum class Type {
	MENU,
	GAME,
	RAW
};

class TextTemplate {

public:

	/*
	* TextTemplate Constructor
	* Default Constructor, that takes no parameters and just initalise new Text Object
	* @Param: -
	* @Return: -
	*/
	TextTemplate();

	TextTemplate(std::shared_ptr<Input> input);

	/*
	* TextTemplate Constructor (probably will be depracted)
	* Second destructor, that sets all necessary data to create new Text
	* @Param: const std::string& text - reference to const string, that set m_text text (XD)
	* @Param: const float x - X-axis point for Text
	* @Param: const float y - Y-axis point for Text
	* @Param: const float size - Font size of Text
	* @Param: cosnt int r - Red RGB value for Text,
	* @Param: const int g - Green RGB value for Text,
	* @Param: const int b - Blue RGB value for Text,
	* @Return: -
	*/
	TextTemplate(const std::string& text, const float x, const float y, const float size, const int r, const int g, const int b);

	/*
	* Awake Method
	* Initialise Font for Text and all needed members of class in future
	* @Param: -
	* @Return: -
	*/
	void Awake();

	/*
	* Update method
	* Update m_text member
	* @Param: float deltaTime - time difference between each frame
	* @Return: -
	*/
	void Update(float deltaTime);

	/*
	* Draw method
	* Draw m_text on screen
	* @Param: Window& window - reference to Window class
	* @Return: -
	*/
	void Draw(Window& window);

	/*
	* SetText method (1)
	* Set text of m_text member
	* @Param: const char* text - text to set represented by const char* type
	* @Return: -
	*/
	void SetText(const char* text);

	/*
	* SetText method (2)
	* Set text for m_text member
	* @Param: const std::string& text - reference to const string, text to set
	* @Return: -
	*/
	void SetText(const std::string& text);

	/*
	* SetFontSize method
	* Set font size of m_text member
	* @Param: const unsigned float size - size of font that we want in our text
	* @Return: -
	*/
	void SetFontSize(const float size);

	/*
	* SetColor method
	* Set color of text represented by RGB values
	* @Param: const int r - Red RGB value,
	* @Param: const int g - Green RGB value,
	* @Param: const int b - Blue RGB value,
	* @Return: -
	*/
	void SetColor(const int r, const int g, const int b);

	/*
	* SetPosition method (1)
	* SetPosition of text on screen
	* @Param: const sf::Vector2f& pos - reference to const sf::Vectro2f, that have information about pos of text
	* @Return: -
	*/
	void SetPosition(const sf::Vector2f& pos);

	/*
	* SetPosition method (2)
	* SetPosition of text on screen
	* @Param: const float x - X-axis pos of text,
	* @Param: const float y - Y-axis pos of text,
	* @Return: -
	*/
	void SetPosition(const float x, const float y);

	sf::Vector2f GetDimensions() const;

	/*
	* SetType method
	* Set Type of text to handle some hover actions
	* @Param: Type type - type of text
	* @Return: -
	*/
	void SetType(Type type);

	/*
	* GetType method
	* Return immutable type of text
	* @Param: -
	* @Return: Type m_typeOfText - type of text from enum class Type
	*/
	Type GetType() const;

	void Refresh();

	/*
	* QueueForRemoval method
	* Set m_queuedForRemoval boolean to true
	* @Param: -
	* @Return: -
	*/
	void QueueForRemoval();

	/*
	* IsQueuedForRemoval method
	* Return m_isQueuedForRemoval member
	* @Param: -
	* @Return: bool m_isQueuedForRemoval
	*/
	bool IsQueuedForRemoval() const;

	template <typename T> std::shared_ptr<T> AddAction() // 1
	{
		//Check, if class based to template is derivered from Compontent
		static_assert(std::is_base_of<TextAction, T>::value,
			"T must derive from TextAction");

		//Check, if any Compontent of this type exstsis in vector
		for (auto& exisitingAction : m_actions)
		{

			//Security for now to prevent adding two components twice
			if (std::dynamic_pointer_cast<T>(exisitingAction))
			{
				return std::dynamic_pointer_cast<T>(exisitingAction); // 2
			}
		}

		std::shared_ptr<T> newAction = std::make_shared<T>(this);
		m_actions.push_back(newAction);

		return newAction;
	};


	/*
	* TextTemplate destructor
	* Created only for test purposes
	*/
	~TextTemplate();


private:
	sf::Font m_font;
	sf::Text m_text;
	Type m_typeOfText;
	bool m_isQueuedForRemoval = false;
	std::vector<std::shared_ptr<TextAction>> m_actions;
	bool m_isMousePressed = false;
	std::shared_ptr<Input> m_input;
};