#include "tile.h"


Tile::Tile()
{
	positionX = 0;
	positionY = 0;

	rect.setSize(sf::Vector2f(24, 24));
	rect.setPosition(sf::Vector2f(positionX * 24, positionY * 24));
	rect.setFillColor(sf::Color::Cyan);

}
void Tile::update(int posX, int posY)
{
	rect.setPosition(sf::Vector2f(posX * 24, posY * 24));
}