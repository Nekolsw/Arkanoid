#include "KeyBindings.h"

namespace Arkanoid 
{
	KeyBindings::KeyBindings()
	{
		pressedKey = sf::Keyboard::Key::Unknown;
	}

	KeyBindings::~KeyBindings()
	{

	}
	KeyBindings& KeyBindings::Instance()
	{
		static KeyBindings instance;
		return instance;
	}
	KeyBindings::Key KeyBindings::PressedKey(sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == keyBinds.keyRight)
			{
				pressedKey = keyBinds.keyRight;
				return Key::Right;
			}
			if (event.key.code == keyBinds.keyLeft)
			{
				pressedKey = keyBinds.keyLeft;
				return Key::Left;
			}
		}
		if (event.type == sf::Event::KeyReleased)
		{
			pressedKey = sf::Keyboard::Key::Unknown;
			return Key::None;
		}
	}
	sf::Keyboard::Key KeyBindings::GetKeyPressed()
	{	
			return pressedKey;	
	}
};