#pragma once

#include "Scene.h"
#include <memory>

class SceneManager
{
public:
	SceneManager() = delete;

	static void setScene(Scene* newScene);
	static void switchScene(Scene* newScene, sf::RenderWindow& window, float duration = 0.7f);

	static void proceedScene(sf::RenderWindow& window);
	static void renderScene(sf::RenderWindow& window);

private:
	static Scene* scene;
};