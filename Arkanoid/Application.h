#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Constants.h"
#include "Game.h"
#include "Brick.h"
namespace Arkanoid
{
	class Application
	{
	private:
		Application();

		~Application();
		int seed = (int)time(nullptr);
		//Game initialized
		Game game;
		sf::Clock gameClock;
	public:
		Application(const Application& application) = delete;
		Application& operator= (const Application&) = delete;

		static Application& Instance();
		void StartGame();


	};
}

