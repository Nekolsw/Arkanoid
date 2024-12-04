#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "SpriteObject.h"
#include "Ball.h"
#include "Platform.h"
#include "Brick.h"
#include "KeyBindings.h"
#include "Resources.h"

namespace Arkanoid
{
	class Game
	{
	private:
		struct GameStruct
		{
			GameResources resources;
			Ball ball = {};
			Platform platform = {};
			SpriteObject walls = {};
			Brick bricks[BRICK_FOR_WIDTH][BRICK_FOR_HEIGHT] = {};

		};
	public:
		GameStruct mainGameStruct;
		void RunApplication(GameStruct& gameStruct);
		void RestartGame(GameStruct& gameStruct);
		void UpdateGame(GameStruct& gameStruct, float deltaTime, sf::RenderWindow& window); 
		void UpdateEvent(GameStruct& gameStruct, sf::Event& event, sf::Window& window, float deltaTime);
		void DrawGame(GameStruct& gameStruct, sf::RenderWindow& window);
	};
}
