#include "SpriteObject.h"
#include "GameMath.h"
namespace Arkanoid
{

	void SpriteObject::Initialization(sf::Vector2f newPosition, sf::Vector2f newScale, sf::Texture& texture)
	{
		texture.setSmooth(true);
		objectSprite.setTexture(texture);
		objectSprite.setPosition(newPosition);
		SetSpriteRelativeOrigin(objectSprite, { 1.0f, 1.0f });
		scale = newScale;
		SetSpriteSize(objectSprite, { scale.x, scale.y });
		
	}

	void SpriteObject::Draw(sf::RenderWindow& window)
	{
		window.draw(objectSprite);
	}
	sf::Vector2f SpriteObject::GetScale()
	{
		return scale;
	}
	sf::Vector2f SpriteObject::GetPosition()
	{
		return objectSprite.getPosition();
	}
}