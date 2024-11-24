#pragma once
#include <SFML/Graphics.hpp>
#include "VectorMain.h"
#include "GameObject.h"
namespace Arkanoid
{

	class SpriteObject : public GameObject
	{
	protected:
	public:
		SpriteObject(sf::Color color) : GameObject(color){};
		sf::Vector2f scale;
		void Initialization(sf::Vector2f newPosition, sf::Vector2f newScale, sf::Texture& texture) override;

		void Draw(sf::RenderWindow& window)  override;
		sf::Vector2f GetScale() override;
		sf::Vector2f GetPosition() override;
	};

}