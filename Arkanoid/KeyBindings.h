#pragma once
#include <SFML/Graphics.hpp>

namespace Arkanoid 
{
	class KeyBindings 
	{
		KeyBindings();

		~KeyBindings();

		struct KeyBinds
		{
			sf::Keyboard::Key keyRight = sf::Keyboard::D;
			sf::Keyboard::Key keyLeft = sf::Keyboard::A;
		};

		KeyBinds keyBinds;
		sf::Keyboard::Key pressedKey;

	public:
		KeyBindings(const KeyBindings& keyBindings) = delete;
		KeyBindings& operator= (const KeyBindings&) = delete;

		static KeyBindings& Instance();

		const enum Key
		{
			left = 0,
			right = 3,
			none
		};

		Key PressedKey(sf::Event& event);
		sf::Keyboard::Key GetKeyPressed();

	};
}