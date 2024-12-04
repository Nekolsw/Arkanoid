#pragma once
#include "SpriteObject.h"
namespace Arkanoid 
{
	class Brick : public SpriteObject
	{
	private:
		int brickStrength = 1;
	public:
		void Initialization(sf::Vector2f newPosition, sf::Vector2f sizeBrick, sf::Texture& texture, sf::Color color);
		void RandomColoring();
		bool DestroyCollision();
		bool IsBreakDestroy();
	};
}

