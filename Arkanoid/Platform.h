#pragma once
#include <SFML/Graphics.hpp>
#include "SpriteObject.h"
#include "Constants.h"
namespace Arkanoid
{
	class Platform : public SpriteObject
	{
	private:
		float directionSpeed = PLATFORM_SPEED;
		sf::Vector2f sizePlaform = {200.f, 40.f};
		sf::Vector2f positionPlaform;
	public:
		void Initialization(sf::Vector2f newPosition, sf::Texture& texture, sf::Color color);
		void Update(float& deltaTime);
		float GetDirectionSpeed();
	};
}

