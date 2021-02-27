#include "Input.hpp"
#include "Entity.hpp"
#include "Logs.hpp"

Input::Input()
{
	Log("Called Input Constructor");
}

Input::Input(std::shared_ptr<Entity> owner) {
	Log("Called Input Constructor");
	m_owner = owner;
}

void Input::ConsumeInput(sf::Event event, sf::RenderWindow& window)
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
				m_owner->GroupId();
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

void Input::SetOwner(std::shared_ptr<Entity> newOwner)
{
	m_owner = newOwner;
}

Input::~Input() {
	Log("Called Input Destructor");
}