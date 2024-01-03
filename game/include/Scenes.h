#pragma once

#include "Scene.h"
#include "Options.h"

class Menu : public Scene
{
public:
	Menu();

	void proceed(sf::RenderWindow& window) override;
	void render(sf::RenderWindow& window) override;
	int getId() const override { return 1; }

private:
	sf::CircleShape circle;
	sf::Font font;
	sf::Text text;
};

class Game : public Scene
{
public:
	void proceed(sf::RenderWindow& window) override;
	void render(sf::RenderWindow& window) override;
	int getId() const override { return 2; }
};