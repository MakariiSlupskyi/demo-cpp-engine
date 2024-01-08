#pragma once

#include <SFML/Graphics.hpp>
#include "SceneManager.h"
#include "Scenes.h"
#include "Options.h"

class App
{
public:
	App() {
		window.create(sf::VideoMode(WIDTH, HEIGHT), "Window", sf::Style::Close);
		window.setFramerateLimit(FPS);
	}

	void run() {
		SceneManager::setScene(new Menu());

		while (window.isOpen()) {
			SceneManager::proceedScene(window);
			SceneManager::renderScene(window);

			window.display();
		}
	}

private:
	sf::RenderWindow window;
};