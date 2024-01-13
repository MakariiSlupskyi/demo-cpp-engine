#pragma once

#include <SFML/Graphics.hpp>
#include <array>

inline int WIDTH = 6 * 2 * 64;
inline int HEIGHT = 4 * 2 * 64;
inline int FPS = 60;

const std::array<sf::Color, 4> colorScheme = {
	sf::Color(22, 26, 48),
	sf::Color(49, 48, 77),
	sf::Color(182, 187, 196),
	sf::Color(240, 236, 229)
};