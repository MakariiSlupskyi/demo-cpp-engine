#include "graphics/Scenes.h"
#include "graphics/SceneManager.h"
#include "Options.h"
#include <cmath>

MainScreen::MainScreen() {
	// Text setup
	font.loadFromFile("res/fonts/chubby-choo-regular.ttf");
	text.setFont(font);
	text.setFillColor(colorScheme[3]);
	text.setCharacterSize(50);
	text.setString("Press Space to Start");
	auto center = text.getGlobalBounds().getSize() / 2.0f;
	center += text.getLocalBounds().getPosition();
	text.setOrigin(center);
	text.setPosition(sf::Vector2f(float(WIDTH / 2), float(HEIGHT / 2)));
}

void MainScreen::proceed(sf::RenderWindow& window) {
	sf::Event e;
	while (window.pollEvent(e)) {
		if (e.type == sf::Event::Closed) {
			window.close();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		SceneManager::setScene(new Game, window);
	}
}

void MainScreen::render(sf::RenderWindow& window) {
	window.clear(sf::Color(colorScheme[1].r, colorScheme[1].g, colorScheme[1].b, 2));

	sf::RectangleShape line(sf::Vector2f(float(WIDTH), 2.0f));
	line.setFillColor(colorScheme[0]);

	window.draw(text);
}