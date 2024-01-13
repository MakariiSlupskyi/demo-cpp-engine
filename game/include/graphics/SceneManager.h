#pragma once

#include "graphics/Scene.h"
#include "graphics/Effects.h"
#include <stack>

class SceneManager
{
public:
	SceneManager() = delete;

	static void setScene(Scene* newScene);
	static void setScene(Scene* newScene, sf::RenderWindow& window, TransitionEffect* effect = new Effects::Transition::BlackScreen);

	static void addScene(Scene* newScene);
	static void addScene(Scene* newScene, sf::RenderWindow& window, TransitionEffect* effect = new Effects::Transition::BlackScreen);

	static void exitScene();
	static void exitScene(sf::RenderWindow& window, TransitionEffect* effect = new Effects::Transition::BlackScreen);

	static void proceedScene(sf::RenderWindow& window);
	static void renderScene(sf::RenderWindow& window);

	static int getSceneId() { return scenes.top()->getId(); }

private:
	static std::stack<Scene*> scenes;
};