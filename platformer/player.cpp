#include "player.h"

Player::Player() {
	playerSpeed = 4.0f;

	sprite.setRadius(100.0f); // debug
	sprite.setFillColor(sf::Color::Blue);
	sprite.setPosition(100.0f, 100.0f);
}

void Player::update(float xMov, float yMov) {
	sprite.move(xMov * playerSpeed, yMov * playerSpeed);
}

float Player::getXPosition() {
	return sprite.getPosition().x;
}
float Player::getYPosition() {
	return sprite.getPosition().y;
}
void Player::setXPosition(float xPos) {
	sprite.setPosition(xPos, this->sprite.getPosition().y);
}
void Player::setYPosition(float yPos) {
	sprite.setPosition(this->sprite.getPosition().x,yPos);
}

sf::CircleShape &Player::draw() {
	return sprite;
}