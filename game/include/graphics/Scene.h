#pragma once

#include <SFML/Graphics.hpp>

class Scene
{
public:
	virtual void proceed(sf::RenderWindow& window) = 0;
	virtual void render(sf::RenderWindow& window) = 0;
	virtual int getId() const { return -1; }
}; 