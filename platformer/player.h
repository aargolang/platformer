#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	sf::CircleShape &draw();
	void update(float xMov, float yMov);
	void setXPosition(float xPos);
	void setYPosition(float yPos);
	float getXPosition();
	float getYPosition();

private:
	sf::CircleShape sprite;
	float playerSpeed;

};