#include "SceneManager.h"
#include "Options.h"

Scene* SceneManager::scene = nullptr;

void SceneManager::setScene(Scene* newScene) {
	delete SceneManager::scene;
	SceneManager::scene = newScene;
}

void SceneManager::switchScene(Scene* newScene, sf::RenderWindow& window, float duration) {
	if (SceneManager::scene->getId() == newScene->getId()) {
		return;
	}

	// Black screen
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(float(WIDTH), float(HEIGHT)));

	sf::Clock clock;
	for (float elapsed = 0; elapsed < 1; elapsed = clock.getElapsedTime().asSeconds() / duration) {
		
		if (elapsed < 0.5) {
			rect.setFillColor(sf::Color(0, 0, 0, int(510 * elapsed)));
			SceneManager::scene->render(window);
		}
		else {
			rect.setFillColor(sf::Color(0, 0, 0, int(510 * (1 - elapsed))));
			newScene->render(window);
		}
		window.draw(rect);
		window.display();
	}
	SceneManager::setScene(newScene);
}

void SceneManager::proceedScene(sf::RenderWindow& window) {
	SceneManager::scene->proceed(window);
}

void SceneManager::renderScene(sf::RenderWindow& window) {
	SceneManager::scene->render(window);
}