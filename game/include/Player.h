#pragma once

#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();

	void move();
	void draw(sf::RenderWindow& window);

private:
	sf::Texture texture;
	sf::Sprite sprite;
};