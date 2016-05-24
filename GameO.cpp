#include "GameO.h"
#include<iostream>
using namespace std;




Gameover::Gameover(float width, float height)
{
	if (!font.loadFromFile("consola.ttf"))
		std::cout << "Could not load font/n";

	finalScore.setFont(font);
	finalScore.setColor(sf::Color::Red);
	finalScore.setString("GAME OVER ");
	finalScore.setCharacterSize(100);
	finalScore.setPosition(sf::Vector2f(width / 6, height / 2));

}
void Gameover::draw(sf::RenderWindow & window)
{

	window.draw(finalScore);


}