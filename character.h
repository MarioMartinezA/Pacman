//**************************************************************************
// character.h
// Class Name: Character
//
// Summary: Creates a Character object with all of the sprite and rectangle
// functionality provided by the SFML library.
//
// Author: Mario
// Created: 30 April 2016
// Summary of Modifications:
// 	A new texture was added for the ghost to inherent from.
//**************************************************************************
#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

class Character
{
public:
	sf::RectangleShape rect;
	sf::RectangleShape rect2;
	sf::Sprite sprite;
	sf::Sprite sprite2;
	sf::Text text;
	Character();
	//**************************************************************************
	// Summary: Creates a Character object which acts as a parent to all
	// inheriting object classes.
	// Precondition: The correct library is included.
	// Postcondition: A Character objected is created with SFML functionalities.
	//**************************************************************************
	//
};

	#endif