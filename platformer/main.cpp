#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280.0f,720.0f), "Platformer Window");

	// circle properties
	sf::CircleShape shape;
	shape.setRadius(25.0f);
	shape.setPosition(100.0f,100.0f);
	shape.setFillColor(sf::Color::Magenta);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}