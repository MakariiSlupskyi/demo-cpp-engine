#pragma once

#include <SFML/Graphics.hpp>
#include "graphics/SceneManager.h"
#include "graphics/Scenes.h"
#include "Options.h"

class App
{
public:
	App() {
		window.create(sf::VideoMode(WIDTH, HEIGHT), "Window", sf::Style::Close);
		window.setFramerateLimit(FPS);
	}

	void run() {
		SceneManager::addScene(new MainScreen());

		while (window.isOpen()) {
			SceneManager::proceedScene(window);
			SceneManager::renderScene(window);

			window.display();
		}
	}

private:
	sf::RenderWindow window;
};