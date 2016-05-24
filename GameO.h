//**************************************************************************
// GameO.h
// Class Name: Gameover
//
// Summary: Brings about the Game Over screen once the player loses all
// lives.
//
// Author: Evelyn Murillo
// Created: 10 May 2016
// Summary of Modifications:
// 	Changed the screen from full screen to the defult size.
//**************************************************************************
#ifndef GAMEO_H
#define GAMEO_H
#include <SFML/Graphics.hpp>


class Gameover
{

public:
	Gameover(float width, float height);
	//**************************************************************************
	// Summary: Draws the Game Over Screen with the correct dimensions.
	// Precondition: The player has lost all three lives.
	// Postcondition: The game is over and the Game Over Screen opens.
	//**************************************************************************
	//
	void draw(sf::RenderWindow & window);
	//**************************************************************************
	// Summary: Allows for the screen to open and be viewed by the player.
	// Precondition: The object has been made with the correction functinalities.
	// Postcondition: The Game Over screen opens.
	//**************************************************************************
	//
	void setisGameOver(bool isGameOver) { this->isGameOver = isGameOver; }
	//**************************************************************************
	// Summary: Allows for the Game over screen to be created once isGameOver
	// is set to true.
	// Precondition: The object is created and the player loses all lives.
	// Postcondition: The Game Over board is instantiated.
	//**************************************************************************
	//
	bool getisGameOver()const { return isGameOver; }
	//**************************************************************************
	// Summary: Returns the boolean value if isGameOver.
	// Precondition: The object is created and the player's lives are
	// being monitored.
	// Postcondition: The boolean value isGameOver is returned.
	//**************************************************************************
	//

private:
	bool isGameOver;

	// creates the font that will be used in the screen
	sf::Font font;
	sf::Text finalScore;


};
#endif 