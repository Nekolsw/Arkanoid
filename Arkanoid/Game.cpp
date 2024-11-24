#include "Game.h"
namespace Arkanoid
{
	void Game::RunApplication(GameStruct& gameStruct)
	{
		InitializingResources(gameStruct.resources);
		gameStruct.ball.Initialization({400.f, 400.f}, gameStruct.resources.ballTexture);
		gameStruct.walls.Initialization({ 1280.f, 720.f }, { 1280.f, 720.f }, gameStruct.resources.wallTexture);
		gameStruct.platform.Initialization({ 640.f, 620.f }, gameStruct.resources.platformTexture);
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
	}
}