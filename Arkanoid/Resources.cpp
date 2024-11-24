#include "Resources.h"
namespace Arkanoid
{
	void InitializingResources(GameResources& resources)
	{
		//Load image
		assert(resources.ballTexture.loadFromFile(RESOURCES_PATH + "Ball.png"));
		assert(resources.wallTexture.loadFromFile(RESOURCES_PATH + "Wall.png"));
		assert(resources.platformTexture.loadFromFile(RESOURCES_PATH + "Platform.png"));


		//Load font
		assert(resources.fontText.loadFromFile(RESOURCES_PATH + "Fonts/Roboto-Bold.ttf"));

		//Load sound
		//assert(resources.snakeHit.loadFromFile(RESOURCES_PATH + "ClapApple.wav"));
		//assert(resources.playerDeath.loadFromFile(RESOURCES_PATH + "GameOverSound.wav"));
		//assert(resources.menuHover.loadFromFile(RESOURCES_PATH + "Theevilsocks__menu-hover.wav"));
		//assert(resources.menuEnter.loadFromFile(RESOURCES_PATH + "Timgormly__Enter.wav"));
	}




}