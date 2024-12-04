#pragma once
#include "VectorMain.h"
#include "Constants.h"
#include "SpriteObject.h"
#include "Platform.h"
#include "Brick.h"
namespace Arkanoid
{
	class Ball : public SpriteObject
	{
	private:
		sf::Vector2f direction;
		float radius = BALL_RADIUS;
		float collisionBall = radius / 2;
		void MirroringDirectionX();
		void MirroringDirectionY();
		sf::Text textBall, textPlatform;
	public:
		bool WallCollision(SpriteObject& walls);
		bool PlatformCollision(Platform& platform, SpriteObject& ball);
		bool BrickCollision(Brick& brick, SpriteObject& ball);
		void Update(float& deltaTime);
		void Initialization(sf::Vector2f newPosition, sf::Texture& texture, sf::Color color);
	};
}

