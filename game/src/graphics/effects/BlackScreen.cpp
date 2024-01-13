#include "graphics/Effects.h"
#include "graphics/SceneManager.h"
#include "Options.h"

using namespace Effects::Transition;

void BlackScreen::proceed(Scene* curScene, Scene* newScene, sf::RenderWindow& window) {
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(float(WIDTH), float(HEIGHT)));

	sf::Clock clock;
	for (float elapsed = 0; elapsed < 1; elapsed = clock.getElapsedTime().asSeconds() / duration) {

		if (elapsed < 0.5) {
			rect.setFillColor(sf::Color(0, 0, 0, int(510 * elapsed)));
			curScene->render(window);
		}
		else {
			rect.setFillColor(sf::Color(0, 0, 0, int(510 * (1 - elapsed))));
			newScene->render(window);
		}
		window.draw(rect);
		window.display();
	}
}