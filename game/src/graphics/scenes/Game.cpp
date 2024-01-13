#include "graphics/Scenes.h"
#include "graphics/SceneManager.h"
#include "graphics/Effects.h"
#include "Options.h"

void Game::proceed(sf::RenderWindow& window) {
	sf::Event e;
	while (window.pollEvent(e)) {
		if (e.type == sf::Event::Closed) {
			window.close();
		}
		if (e.type == sf::Event::MouseButtonPressed) {
			SceneManager::addScene(new OpeningCredits, window, new Effects::Transition::BlackScreen(0.4f));
		}
	}

	player.move();
}

void Game::render(sf::RenderWindow& window) {
	window.clear(colorScheme[0]);
	player.draw(window);
}