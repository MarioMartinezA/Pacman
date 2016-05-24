#include "ball.h"
#include "character.h"

Ball::Ball()
{
	// we want this box to be same size as sprite because it will 
	// be the sprite's collision detection

	rect.setSize(sf::Vector2f(17, 18));
	rect.setPosition(sf::Vector2f(14 * 24, 20 * 24 + 4));
	rect.setFillColor(sf::Color::Green);

	sprite.setPosition(sf::Vector2f(0, 0));

	counterWalking = 0;

	isShowing = true;
	isLargePellet = false;

}

Ball::Ball(int x, int y)
{
	rect.setSize(sf::Vector2f(16, 16));
	rect.setPosition(sf::Vector2f(14 * 24, 20 * 24 + 5));
	rect.setFillColor(sf::Color::Green);

	sprite.setPosition(sf::Vector2f(x, y));
}

void Ball::setXYPosition(int x, int y)
{
	sprite.setPosition(sf::Vector2f(x-3, y-3));
	rect.setPosition(sf::Vector2f(x, y));

}
void Ball::update()
{

	sprite.setTextureRect(sf::IntRect(counterWalking * 24, 0, 24, 24));
	counterWalking++;

	if (counterWalking == 4)
	{
		counterWalking = 0;
	}

}