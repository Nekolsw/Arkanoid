#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "SpriteObject.h"
#include "Ball.h"
#include "Platform.h"
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
			Ball ball {sf::Color::Red};
			Platform platform {sf::Color::Yellow};
			SpriteObject walls {sf::Color::Yellow};

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
