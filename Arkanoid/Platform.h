#pragma once
#include <SFML/Graphics.hpp>
#include "SpriteObject.h"
#include "Constants.h"
namespace Arkanoid
{
	class Platform : public SpriteObject
	{
	private:
		float directionSpeed = 100;
		sf::Vector2f sizePlaform = {200, 20};
		sf::Vector2f positionPlaform;
	public:
		Platform(sf::Color color) : SpriteObject(color) {};
		void Initialization(sf::Vector2f newPosition, sf::Texture& texture);
		void Update(float& deltaTime);
	};
}

