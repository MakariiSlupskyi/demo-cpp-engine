#include "Scenes.h"
#include "SceneManager.h"
#include "Options.h"

Menu::Menu() {
	circle.setRadius(10);
	circle.setFillColor(sf::Color::Red);
	font.loadFromFile("res/chubby-choo-regular.ttf");
	text.setFont(font);
}

void Menu::proceed(sf::RenderWindow& window) {
	sf::Event e;
	while (window.pollEvent(e)) {
		if (e.type == sf::Event::Closed) {
			window.close();
		}
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		SceneManager::switchScene(new Game, window);
	}
}

void Menu::render(sf::RenderWindow& window) {
	circle.setPosition(
		float(sf::Mouse::getPosition(window).x),
		float(sf::Mouse::getPosition(window).y)
	);

	window.clear(colorScheme[1]);
	window.draw(circle);
}