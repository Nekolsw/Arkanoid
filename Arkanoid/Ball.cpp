#include <SFML/Graphics.hpp>
#include "GameMath.h"
#include "SpriteObject.h"
#include "Ball.h"

namespace Arkanoid
{
	void Ball::MirroringDirectionX()
	{
		direction.x = -direction.x;
	}
	void Ball::MirroringDirectionY()
	{
		direction.y = -direction.y;
	}

	bool Ball::WallCollision(SpriteObject& walls)
	{

		bool isCollision = false;
		if (objectSprite.getPosition().x - collisionBall < 0)
		{
			MirroringDirectionX();
			isCollision = true;
		}

		if (objectSprite.getPosition().x + collisionBall > walls.GetPosition().x)
		{
			MirroringDirectionX();
			isCollision = true;
		}

		if (objectSprite.getPosition().y - collisionBall < 0)
		{
			MirroringDirectionY();
			isCollision = true;
		}

		if (objectSprite.getPosition().y + collisionBall > walls.GetPosition().y)
		{
			MirroringDirectionY();
			isCollision = true;
		}
		return false;
	}

	bool Ball::PlatformCollision(SpriteObject& platform, SpriteObject& ball)
	{
		float dx = (float)fabs(platform.GetPosition().x - objectSprite.getPosition().x);
		float dy = (float)fabs(platform.GetPosition().y - objectSprite.getPosition().y);

		if (dx <= (platform.GetScale().x + ball.GetScale().x) / 2.f &&
			dy <= (platform.GetScale().y + ball.GetScale().y) / 2.f) 
		{
			MirroringDirectionY();
			return true;
		}
		return false;
	}

	void Ball::Update(float& deltaTime)
	{
		objectSprite.setPosition(objectSprite.getPosition() + direction * deltaTime);
	}
	void Ball::Initialization(sf::Vector2f newPosition, sf::Texture& texture)
	{
		SpriteObject::Initialization(newPosition, { radius, radius }, texture);
		SetSpriteRelativeOrigin(objectSprite, { 0.5f, 0.5f });
		direction = BALL_SPEED;
	}
}