#include "Brick.h"
#include "GameMath.h"
namespace Arkanoid
{
	void Brick::Initialization(sf::Vector2f newPosition, sf::Vector2f sizeBrick, sf::Texture& texture, sf::Color color)
	{
		SpriteObject::Initialization(newPosition, sizeBrick, texture, color);
		SetSpriteRelativeOrigin(objectSprite, { 0.5f, 0.5f });
	}
	void Brick::RandomColoring()
	{
		objectSprite.setColor(sf::Color::Cyan);
	}
	bool Brick::DestroyCollision()
	{
		if (brickStrength > 0)
		{
			brickStrength -= 1;
		}
		if (brickStrength <= 0)
		{
			return true;
		}
		return false;
	}
	bool Brick::IsBreakDestroy()
	{
		if (brickStrength <= 0)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
}