#include "Input.h"
#include "Entity.h"

Input::Input()
{
}

Input::Input(Entity* owner)
{
	Owner = owner;
}

void Input::ConsumeInput(sf::Event m_event)
{
	if (Owner != nullptr)
	{
		switch (m_event.type)
		{

		case sf::Event::KeyPressed:

			switch (m_event.key.code)
			{
			case sf::Keyboard::W:
			{
				Owner->groupId();
				// Owner->KeyWAction 
				// We can later change Owner type to be player-specific
				break;
			}
			case sf::Keyboard::S:
			{

				break;
			}

			default:
			{
				break;
			}
			}
			break;


		case sf::Event::KeyReleased:

			switch (m_event.key.code)
			{
			case sf::Keyboard::W:
			{
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

void Input::setOwner(Entity* NewOwner)
{
	Owner = NewOwner;
}
