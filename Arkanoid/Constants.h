#pragma once
#include <SFML/Graphics.hpp>
namespace Arkanoid 
{
	const std::string RESOURCES_PATH = "Resources/\\";
	const float BALL_RADIUS = 30.f;
	const sf::Vector2f BALL_SPEED = { 150.f, 150.f };
	const sf::Vector2f BRICK_SIZE = { 70.f, 30.f };
	const float PLATFORM_SPEED = 300.f;
	const int BRICK_FOR_WIDTH = 16;
	const int BRICK_FOR_HEIGHT = 3;
	const sf::Vector2f WINDOW_SIZE = { 1280.f, 720.f };
	const sf::Vector2f STARTING_POSITION_BRICK = { 46.f, 100.f };
	const  sf::Vector2f DISTANCE_BETWEEN_BRICKS = { 79.f, 35.f };
	const float ACCELETATION_PLATFORM_CONTACT = 300.f;
	const sf::Vector2f  LOSS_BALL_SPEED = { 600.f, 10.f }; // Returning the speed of the ball to its original speed
	const float MAX_BALL_SPEED = 400.f;
}
