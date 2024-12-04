#pragma once
#include <cassert>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Constants.h"

namespace Arkanoid
{
	struct GameResources {
		sf::Texture ballTexture, wallTexture, platformTexture, brickClassicTexture;
	//	sf::SoundBuffer ballHit, gameOver, menuHover, menuEnter;
		sf::Font fontText;
	};

	void InitializingResources(GameResources& resources);


}
