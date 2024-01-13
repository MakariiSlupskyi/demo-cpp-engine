#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Window
{
public:
	Window() = delete;

	static void createWindow(int width, int height, std::string capture);

private:
	static sf::RenderWindow window;
};

