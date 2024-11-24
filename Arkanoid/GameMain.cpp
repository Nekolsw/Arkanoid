// ©2023, XYZ School. All rights reserved.
// Authored by Aleksandr Rybalka (polterageist@gmail.com)

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"


int main()
{
	using namespace Arkanoid;
	int seed = (int)time(nullptr);
	srand(seed);
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Arkanoid");

	//Game initialized
	Game game;
	game.RunApplication(game.mainGameStruct);
	sf::Clock gameClock;
	float lastTime = gameClock.getElapsedTime().asSeconds();

	while (window.isOpen())
	{
		// Calculate time delta
		float currentTime = gameClock.getElapsedTime().asSeconds();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) 
			{
				window.close();
			}
			game.UpdateEvent(game.mainGameStruct, event, window, deltaTime);
		}
		game.UpdateGame(game.mainGameStruct, deltaTime, window);
		window.clear();
		game.DrawGame(game.mainGameStruct, window);
		window.display();
	}

	return 0;
}
