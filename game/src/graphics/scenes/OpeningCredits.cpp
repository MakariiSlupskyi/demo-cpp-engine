#include "graphics/Scenes.h"
#include "graphics/SceneManager.h"
#include "graphics/Effects.h"
#include "Options.h"

OpeningCredits::OpeningCredits() {
	logoTexture.loadFromFile("res/graphics/logo.png");
	logo.setTexture(logoTexture);
	logo.setScale(7.0f, 7.0f);
	logo.setOrigin(logo.getLocalBounds().getSize() / 2.0f);
	logo.setPosition(sf::Vector2f(WIDTH / 2.0f, HEIGHT / 2.0f));
}

void OpeningCredits::proceed(sf::RenderWindow& window) {
	sf::Event e;
	while (window.pollEvent(e)) {
		if (e.type == sf::Event::Closed) {
			window.close();
		}
		if (e.type == sf::Event::MouseButtonPressed) {
			SceneManager::exitScene(window, new Effects::Transition::BlackScreen(0.4f));
		}
	}
}

void OpeningCredits::render(sf::RenderWindow& window) {
	window.clear(sf::Color(10, 10, 10));
	window.draw(logo);
}