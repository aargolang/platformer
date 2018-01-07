#include <SFML/Graphics.hpp>
#include "player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280.0f,900.0f), "Platformer Window");
	window.setFramerateLimit(60);

	sf::RectangleShape floor(sf::Vector2f(400,20));
	floor.setFillColor(sf::Color::Red);
	floor.setPosition(sf::Vector2f(0.0f, 700.0f));
	

	// player variables
	Player player;
	bool pressedLeft = false;
	bool pressedRight = false;
	float playerMoveX = 0.0f;
	float playerMoveY = 0.0f;
	float playerGravity = 0.05f;

	// debug 
	sf::Text debugMessage;
	sf::Font debugFont;
	debugFont.loadFromFile("Fonts/arial.ttf");
	debugMessage.setFillColor(sf::Color::White);
	debugMessage.setCharacterSize(12);
	debugMessage.setFont(debugFont);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			// player controls
			if (event.type == sf::Event::KeyPressed) 
			{
				if (!pressedLeft && event.key.code == sf::Keyboard::Left) {
					pressedLeft = true;
				}
				if (!pressedRight && event.key.code == sf::Keyboard::Right) {
					pressedRight = true;
				}
				if (event.key.code == sf::Keyboard::Z) {
					playerMoveY = -2.0f;
					player.draw().setFillColor(sf::Color::Green);
				}
				
			}
			if (event.type == sf::Event::KeyReleased) {
				if (pressedLeft && event.key.code == sf::Keyboard::Left) {
					pressedLeft = false;
				}
				if (pressedRight && event.key.code == sf::Keyboard::Right) {
					pressedRight = false;
				}
				if (event.key.code == sf::Keyboard::Z) {
					player.draw().setFillColor(sf::Color::Blue);
				}

			}
			// escape events
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();
			}
		}
		// acceleration due to gravity
		playerMoveY = playerMoveY + playerGravity;

		if (player.draw().getGlobalBounds().intersects(floor.getGlobalBounds())) {
			playerMoveY = 0.0f;
			player.setYPosition(floor.getPosition().y - 200);
		}


		playerMoveX = pressedRight - pressedLeft;
		player.update(playerMoveX, playerMoveY);

		// debug message
		debugMessage.setString(
			"player x position : " + std::to_string(player.getXPosition()) + '\n' +
			"player y position : " + std::to_string(player.getYPosition()) + '\n'
		);

		// drawing stage
		window.clear();
		window.draw(player.draw());
		window.draw(floor);
		window.draw(debugMessage);
		window.display();
	}

	return 0;
}