#pragma once
#include <SFML/Graphics.hpp>
class GameObject
{

protected:
	sf::Sprite objectSprite;
public:
	GameObject(sf::Color color);

	virtual void Initialization(sf::Vector2f newPosition, sf::Vector2f scale, sf::Texture& texture) = 0;

	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual sf::Vector2f GetScale() = 0;
	virtual sf::Vector2f GetPosition() = 0;
};

