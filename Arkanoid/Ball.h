#pragma once
#include "VectorMain.h"
#include "Constants.h"
#include "SpriteObject.h"
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
	public:
		Ball(sf::Color color) : SpriteObject(color) {};
		bool WallCollision(SpriteObject& walls);
		bool PlatformCollision(SpriteObject& platform, SpriteObject& ball);
		void Update(float& deltaTime);
		void Initialization(sf::Vector2f newPosition, sf::Texture& texture);
	};
}

