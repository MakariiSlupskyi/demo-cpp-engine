#pragma once

#include "Scene.h"
#include "Options.h"
#include "Player.h"

// Opening Credits
class OpeningCredits : public Scene
{
public:
	OpeningCredits();

	void proceed(sf::RenderWindow& window) override;
	void render(sf::RenderWindow& window) override;
	int getId() const override { return 0; }

private:
	sf::Texture logoTexture;
	sf::Sprite logo;
};

// Main Screen
class MainScreen : public Scene
{
public:
	MainScreen();

	void proceed(sf::RenderWindow& window) override;
	void render(sf::RenderWindow& window) override;
	int getId() const override { return 1; }

private:
	sf::Font font;
	sf::Text text;
};

// Game
class Game : public Scene
{
public:
	void proceed(sf::RenderWindow& window) override;
	void render(sf::RenderWindow& window) override;
	int getId() const override { return 2; }

private:
	Player player;
};