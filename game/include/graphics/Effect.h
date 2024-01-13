#pragma once

#include <SFML/Graphics.hpp>
#include "graphics/Scene.h"

class Effect
{
public:
	virtual void run() = 0;
};

class TransitionEffect
{
public:
	TransitionEffect(float duration) : duration(duration)
	{}

	virtual void proceed(Scene* curScene, Scene* newScene, sf::RenderWindow& window) = 0;

protected:
	float duration;
};