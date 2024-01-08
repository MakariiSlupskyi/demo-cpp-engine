#include "Scenes.h"
#include "SceneManager.h"
#include "Options.h"
#include <cmath>

Menu::Menu() {
	// Text setup
	font.loadFromFile("res/fonts/chubby-choo-regular.ttf");
	text.setFont(font);
	text.setFillColor(colorScheme[3]);
	text.setCharacterSize(50);
	text.setString("Space to Start");
	auto center = text.getGlobalBounds().getSize() / 2.0f;
	center += text.getLocalBounds().getPosition();
	text.setOrigin(center);
	text.setPosition(sf::Vector2f(float(WIDTH / 2), float(HEIGHT / 3)));
}

void Menu::proceed(sf::RenderWindow& window) {
	sf::Event e;
	while (window.pollEvent(e)) {
		if (e.type == sf::Event::Closed) {
			window.close();
		}
		if (e.type == sf::Event::MouseButtonPressed) {
			SceneManager::switchScene(new Game, window);
		}
	}
}

void Menu::render(sf::RenderWindow& window) {
	window.clear(colorScheme[1]);
	window.draw(text);
}