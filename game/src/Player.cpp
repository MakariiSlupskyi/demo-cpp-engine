#include "Player.h"
#include "Options.h"

Player::Player() {
	texture.loadFromFile("res/graphics/player.png");
	sprite.setTexture(texture);
	sprite.setScale(5.0f, 5.0f);
	sprite.setOrigin(sprite.getLocalBounds().getSize() / 2.0f);
	sprite.setPosition(sf::Vector2f(WIDTH / 2.0f, HEIGHT / 2.0f));
}

void Player::move() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		sprite.move(sf::Vector2f(-5.0f, 0.0f));
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		sprite.move(sf::Vector2f(5.0f, 0.0f));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		sprite.move(sf::Vector2f(0.0f, -5.0f));
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		sprite.move(sf::Vector2f(0.0f, 5.0f));
	}
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}