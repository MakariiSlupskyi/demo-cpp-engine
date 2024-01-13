#include "graphics/SceneManager.h"
#include "Options.h"

std::stack<Scene*> SceneManager::scenes = {};

void SceneManager::setScene(Scene* newScene) {
	if (scenes.size() == 0) { return; }
	delete scenes.top();
	scenes.top() = newScene;
}

void SceneManager::setScene(Scene* newScene, sf::RenderWindow& window, TransitionEffect* effect) {
	if (scenes.size() == 0) { return; }
	effect->proceed(scenes.top(), newScene, window);
	delete scenes.top();
	scenes.top() = newScene;
}

void SceneManager::addScene(Scene* newScene) {
	if (scenes.size() > 0) {
		if (getSceneId() == newScene->getId()) { return; }
	}
	scenes.push(newScene);
}

void SceneManager::addScene(Scene* newScene, sf::RenderWindow& window, TransitionEffect* effect) {
	if (scenes.size() > 0) {
		if (getSceneId() == newScene->getId()) { return; }
	}
	effect->proceed(scenes.top(), newScene, window);
	scenes.push(newScene);
}

void SceneManager::exitScene() {
	if (scenes.size() == 1) { return; }
	scenes.pop();
}
void SceneManager::exitScene(sf::RenderWindow& window, TransitionEffect* effect) {
	if (scenes.size() == 1) { return; }
	auto curScene = scenes.top();
	scenes.pop();
	effect->proceed(curScene, scenes.top(), window);
}

void SceneManager::proceedScene(sf::RenderWindow& window) {
	scenes.top()->proceed(window);
}

void SceneManager::renderScene(sf::RenderWindow& window) {
	scenes.top()->render(window);
}