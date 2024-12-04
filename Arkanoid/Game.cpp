#include "Game.h"
namespace Arkanoid
{
	void Game::RunApplication(GameStruct& gameStruct)
	{
		InitializingResources(gameStruct.resources);
		gameStruct.ball.Initialization({400.f, 400.f}, gameStruct.resources.ballTexture, sf::Color::Red);
		gameStruct.walls.Initialization({ 1280.f, 720.f }, { WINDOW_SIZE }, gameStruct.resources.wallTexture, sf::Color::Cyan);
		gameStruct.platform.Initialization({ 640.f, 620.f }, gameStruct.resources.platformTexture, sf::Color::Cyan);
		for (int i = 0; i < BRICK_FOR_WIDTH; ++i)
		{
			for (int j = 0; j < BRICK_FOR_HEIGHT; ++j)
			{
				gameStruct.bricks[i][j].RandomColoring();
				gameStruct.bricks[i][j].Initialization({ STARTING_POSITION_BRICK.x + DISTANCE_BETWEEN_BRICKS.x * i, STARTING_POSITION_BRICK.y + DISTANCE_BETWEEN_BRICKS.y * j }, BRICK_SIZE, gameStruct.resources.brickClassicTexture, sf::Color::Cyan);
			}
		}
	}

	void Game::RestartGame(GameStruct& gameStruct)
	{

	}

	void Game::UpdateGame(GameStruct& gameStruct, float deltaTime, sf::RenderWindow& window)
	{
		gameStruct.ball.Update(deltaTime);
		gameStruct.ball.WallCollision(gameStruct.walls);
		gameStruct.ball.PlatformCollision(gameStruct.platform, gameStruct.ball);
		gameStruct.platform.Update(deltaTime);
		for (int i = 0; i < BRICK_FOR_WIDTH; ++i)
		{
			for (int j = 0; j < BRICK_FOR_HEIGHT; ++j)
			{
				if (!gameStruct.bricks[i][j].IsBreakDestroy())
				{
					if (gameStruct.ball.BrickCollision(gameStruct.bricks[i][j], gameStruct.ball)) 
					{
						gameStruct.bricks[i][j].DestroyCollision();
					}
				}
			}
		}
	}

	void Game::UpdateEvent(GameStruct& gameStruct, sf::Event& event, sf::Window& window, float deltaTime)
	{
		KeyBindings::Instance().PressedKey(event);
	}

	void Game::DrawGame(GameStruct& gameStruct, sf::RenderWindow& window)
	{
		gameStruct.ball.Draw(window);
		gameStruct.walls.Draw(window);
		gameStruct.platform.Draw(window);
		for (int i = 0; i < BRICK_FOR_WIDTH; ++i)
		{
			for (int j = 0; j < BRICK_FOR_HEIGHT; ++j)
			{
				if (!gameStruct.bricks[i][j].IsBreakDestroy()) 
				{
					gameStruct.bricks[i][j].Draw(window);
				}
			}
		}
	}
}