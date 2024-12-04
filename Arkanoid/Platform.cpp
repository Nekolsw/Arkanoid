#include "Platform.h"
#include "GameMath.h"
#include "KeyBindings.h"
void Arkanoid::Platform::Initialization(sf::Vector2f newPosition, sf::Texture& texture, sf::Color color)
{
	positionPlaform = newPosition;
	SpriteObject::Initialization(newPosition, sizePlaform, texture, color);
	SetSpriteRelativeOrigin(objectSprite, { 0.5f, 0.5f });
	directionSpeed = PLATFORM_SPEED;
}

void Arkanoid::Platform::Update(float& deltaTime)
{
		if (KeyBindings::Instance().GetKeyPressed() == KeyBindings::Key::Right && objectSprite.getPosition().x <= (WINDOW_SIZE.x - objectSprite.getOrigin().x - 30.f))
		{
			objectSprite.setPosition({ positionPlaform.x += directionSpeed * deltaTime, positionPlaform.y });
		}

		if (KeyBindings::Instance().GetKeyPressed() == KeyBindings::Key::Left && objectSprite.getPosition().x >= (30.f + objectSprite.getOrigin().x))
		{
			objectSprite.setPosition({ positionPlaform.x -= directionSpeed * deltaTime, positionPlaform.y });
		}

		if (KeyBindings::Instance().GetKeyPressed() == KeyBindings::Key::None)
		{

		}
}

float Arkanoid::Platform::GetDirectionSpeed()
{
	return directionSpeed;
}
