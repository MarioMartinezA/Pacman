#include "player.h"

Player::Player()
{

	counterWalking = 1;
	movementSpeed = 3;
	lives = 3;
// we want this box to be same size as sprite because it will 
// be the sprite's collision detection
	
	rect.setSize(sf::Vector2f(3, 3)); 
	rect.setPosition(sf::Vector2f(14 * 24, 20 * 24 + 9));
	rect.setFillColor(sf::Color::Green);

	//rectangel 2
	rect2.setSize(sf::Vector2f(22,20));
	rect2.setPosition(sf::Vector2f(14 * 24, 20 * 24 + 4));
	rect2.setFillColor(sf::Color::Red);

	sprite.setPosition(sf::Vector2f(0, 0));

	upKeyPressed = false;
	downKeyPressed = false;
	leftKeyPressed = false;
	rightKeyPressed = false;



}
void Player::update()
{
	sprite.setPosition(rect.getPosition().x-11,rect.getPosition().y-11);
	rect2.setPosition(sprite.getPosition().x + 1, sprite.getPosition().y + 2 );
}

void Player::updateMovement()
{
	upKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	downKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
	leftKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	rightKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

	if (upKeyPressed) // Moving up
	{
		rect.move(0, -movementSpeed);
		sprite.setTextureRect(sf::IntRect(counterWalking * 24, 24 * 2, 24, 24));
		direction = 1;
	}

	else if (downKeyPressed) // Moving Down
	{
		rect.move(0, movementSpeed);
		sprite.setTextureRect(sf::IntRect(counterWalking * 24, 24 * 3, 24, 24));
		direction = 2;
	}

	else if (leftKeyPressed) // Moving left
	{
		rect.move(-movementSpeed, 0);
		sprite.setTextureRect(sf::IntRect(counterWalking * 24, 24 * 1, 24, 24));
		direction = 3;
	}

	else if (rightKeyPressed) // Moving Right
	{
		rect.move(movementSpeed, 0);
		sprite.setTextureRect(sf::IntRect(counterWalking * 24, 24 * 0, 24, 24));
		direction = 4;
	}

	counterWalking++;

	if (counterWalking == 3)
	{
		counterWalking = 0;
	}

}
void Player::playerDeath()
{
	sprite.setTextureRect(sf::IntRect(counterWalking * 24, 24 * 4, 24, 24));
	counterWalking++;
	if (counterWalking == 6)
	{
		counterWalking = 0;
	}
}