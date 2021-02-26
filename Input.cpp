#include "Input.h"
#include "Entity.h"
#include "Logs.h"

Input::Input()
{
	Log("Called Input Constructor");
}

Input::Input(std::shared_ptr<Entity> owner) {
	Log("Called Input Constructor");
	m_owner = owner;
}

void Input::consumeInput(sf::Event event, sf::RenderWindow& window)
{
	if (m_owner != nullptr)
	{
		switch (event.type)
		{
		case sf::Event::Closed:
		{
			window.close();
			break;
		}

			switch (event.key.code)
			{
			case sf::Keyboard::W:
			{
				m_owner->groupId();
				// Owner->KeyWAction 
				// We can later change Owner type to be player-specific
				Log("Key W is pressed");
				break;
			}
			case sf::Keyboard::S:
			{
				Log("Key S is pressed");
				break;
			}

			default:
			{
				break;
			}
			}
			break;


		case sf::Event::KeyReleased:

			switch (event.key.code)
			{
			case sf::Keyboard::W:
			{
				Log("Key W released");
				break;
			}
			case sf::Keyboard::S:
			{
				Log("Key S released");
				break;	
			}
			default:
			{
				break;
			}
			}
			break;

		default:

			break;
		}
	}
}

void Input::setOwner(std::shared_ptr<Entity> newOwner)
{
	m_owner = newOwner;
}

Input::~Input() {
	Log("Called Input Destructor");
}