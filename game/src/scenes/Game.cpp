#include "Scenes.h"
#include "SceneManager.h"
#include "Options.h"

void Game::proceed(sf::RenderWindow& window) {
	sf::Event e;
	while (window.pollEvent(e)) {
		if (e.type == sf::Event::Closed) {
			window.close();
		}
		if (e.type == sf::Event::MouseButtonPressed) {
			SceneManager::switchScene(new Menu, window);
		}
	}
}

void Game::render(sf::RenderWindow& window) {
	window.clear(colorScheme[2]);
}