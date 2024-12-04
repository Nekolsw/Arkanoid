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

		if (objectSprite.getPosition().x - collisionBall <= 0 && direction.x < 0)
		{
			MirroringDirectionX();
		}

		if (objectSprite.getPosition().x + collisionBall >= walls.GetPosition().x && direction.x > 0)
		{
			MirroringDirectionX();
		}

		if (objectSprite.getPosition().y - collisionBall <= 0 && direction.y < 0)
		{
			MirroringDirectionY();
		}

		if (objectSprite.getPosition().y + collisionBall >= walls.GetPosition().y && direction.y > 0) 
		{
			MirroringDirectionY();
		}
		return false;
	}

	bool Ball::PlatformCollision(Platform& platform, SpriteObject& ball)
	{
		float dx = (float)fabs(platform.GetPosition().x - objectSprite.getPosition().x);
		float dy = (float)fabs(platform.GetPosition().y - objectSprite.getPosition().y);

		if (dx <= (platform.GetScale().x + ball.GetScale().x) / 2.f &&
			dy <= (platform.GetScale().y + ball.GetScale().y) / 2.f) 
		{
			if ((platform.GetPosition().x - platform.GetScale().x / 2.f) >= ball.GetPosition().x)  // left
			{
				if (platform.GetDirectionSpeed() != 0)
				{
					direction.x = platform.GetDirectionSpeed();
				}
				if (ball.GetPosition().x && direction.x > 0) //Ñhanges in direction only if the ball is flying in the opposite direction
				{
					MirroringDirectionX();
				}
			}
		if ((platform.GetPosition().x + platform.GetScale().x / 2.f) <= ball.GetPosition().x) // right
			{
				if (platform.GetDirectionSpeed() != 0)
				{
					direction.x = platform.GetDirectionSpeed();
				}
				if (ball.GetPosition().x && direction.x < 0) //Ñhanges in direction only if the ball is flying in the opposite direction
				{
					MirroringDirectionX();
				}
			}
			if (platform.GetPosition().y - platform.GetScale().y / 2.f >= ball.GetPosition().y && direction.y > 0) // up
			{
				if (direction.y < MAX_BALL_SPEED) 
				{
					direction.y += ACCELETATION_PLATFORM_CONTACT;
				}
				else 
				{
					direction.y = MAX_BALL_SPEED;
				}
				MirroringDirectionY();
			}
			if ((platform.GetScale().y / 2.f + platform.GetPosition().y) <= ball.GetPosition().y && direction.y < 0) // down
			{
				if (direction.y > -MAX_BALL_SPEED)
				{
					direction.y -= ACCELETATION_PLATFORM_CONTACT;
				}
				else
				{
					direction.y = -MAX_BALL_SPEED;
				}
				MirroringDirectionY();
			}
			return true;
		}
		return false;
	}

	bool Ball::BrickCollision(Brick& brick, SpriteObject& ball)
	{
		float dx = (float)fabs(brick.GetPosition().x - objectSprite.getPosition().x);
		float dy = (float)fabs(brick.GetPosition().y - objectSprite.getPosition().y);

		if (dx <= (brick.GetScale().x + ball.GetScale().x) / 2.f &&
			dy <= (brick.GetScale().y + ball.GetScale().y) / 2.f)
		{
			if ((brick.GetPosition().x - brick.GetScale().x / 2.f) >= ball.GetPosition().x)  // left
			{
				if (ball.GetPosition().x && direction.x > 0) //Ñhanges in direction only if the ball is flying in the opposite direction
				{
					MirroringDirectionX();
				}
			}
			if ((brick.GetPosition().x + brick.GetScale().x / 2.f) <= ball.GetPosition().x) // right
			{
				if (ball.GetPosition().x && direction.x < 0) //Ñhanges in direction only if the ball is flying in the opposite direction
				{
					MirroringDirectionX();
				}
			}
			if (brick.GetPosition().y - brick.GetScale().y / 2.f >= ball.GetPosition().y && direction.y > 0) // up
			{
				MirroringDirectionY();
			}
			if ((brick.GetScale().y / 2.f + brick.GetPosition().y) <= ball.GetPosition().y && direction.y < 0) // down
			{
				MirroringDirectionY();
			}

			brick.DestroyCollision();

			return true;

		}
		return false;
	}

	void Ball::Update(float& deltaTime)
	{
		if (direction.x > BALL_SPEED.x && direction.x > 0)
		{
			direction.x -= LOSS_BALL_SPEED.x * deltaTime;
		}
		if (direction.x < -BALL_SPEED.x && direction.x < 0)
		{
			direction.x += LOSS_BALL_SPEED.x * deltaTime;
		}
		if (direction.y > BALL_SPEED.y && direction.y > 0)
		{
			direction.y -= LOSS_BALL_SPEED.y * deltaTime;
		}
		if (direction.y < -BALL_SPEED.y && direction.y < 0)
		{
			direction.y += LOSS_BALL_SPEED.y * deltaTime;
		}
		objectSprite.setPosition(objectSprite.getPosition() + direction * deltaTime);
	}
	void Ball::Initialization(sf::Vector2f newPosition, sf::Texture& texture, sf::Color color)
	{
		SpriteObject::Initialization(newPosition, { radius, radius }, texture, color);
		SetSpriteRelativeOrigin(objectSprite, { 0.5f, 0.5f });
		direction = BALL_SPEED;
	}
}