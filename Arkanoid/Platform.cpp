#include "Platform.h"
#include "GameMath.h"
#include "KeyBindings.h"
void Arkanoid::Platform::Initialization(sf::Vector2f newPosition, sf::Texture& texture)
{
	positionPlaform = newPosition;
	SpriteObject::Initialization(newPosition, sizePlaform, texture);
	SetSpriteRelativeOrigin(objectSprite, { 0.5f, 0.5f });
	directionSpeed = PLATFORM_SPEED;
}

void Arkanoid::Platform::Update(float& deltaTime)
{
		if (KeyBindings::Instance().GetKeyPressed() == KeyBindings::Key::right)
		{
			objectSprite.setPosition({ positionPlaform.x += directionSpeed * deltaTime, positionPlaform.y });
		}

		if (KeyBindings::Instance().GetKeyPressed() == KeyBindings::Key::left)
		{
			objectSprite.setPosition({ positionPlaform.x -= directionSpeed * deltaTime, positionPlaform.y });
		}

		if (KeyBindings::Instance().GetKeyPressed() == KeyBindings::Key::none)
		{

		}
}
