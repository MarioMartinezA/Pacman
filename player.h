//**************************************************************************
// player.h
// Class Name: Player
//
// Summary: Constructs the Pac-Man player object for the game which the user
// will control during the game. Pac-Man is able to move throughout the
// board using the up, down, left, and right arrow keys.
//
// Author: Mario
// Created: 24 April 2016
// Summary of Modifications: 
// 	
//**************************************************************************

#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Player : public Character //Player inherits from the Character class
{
private:
	int direction;
	int movementSpeed;
	int counterWalking;
	bool isAlive;
	bool upKeyPressed;
	bool downKeyPressed;
	bool leftKeyPressed;
	bool rightKeyPressed;
	int lives;



public:
	Player();
	//**************************************************************************
	// Summary: Constructs the default Pac-Man character that the user will
	// be able to control during the game. 
	// Precondition: The gameboard is constructed.
	// Postcondition: the Player object is created and is set to appear at its
	// default position on the gameboard. 
	//**************************************************************************
	//
	void update();
	//**************************************************************************
	// Summary: This method updates the Player and its respective rectangle 
	// while the Player is being controlled by the user.
	// Precondition: The Player object is constructed and is able to be controlled
	// by the user using the keyboard arrow keys.
	// Postcondition: The Player's position is updated throughout the board.
	//**************************************************************************
	//
	void updateMovement();
	//**************************************************************************
	// Summary: Allows for the Player object to move depending on which key
	// the user is pressing. 
	// Precondition: The object is created and able to change position on the
	// gameboard.
	// Postcondition: The Player object moves throughout the board in accordance
	// with which key is pressed by the user. 
	//**************************************************************************
	//
	int getDirection()const { return direction; }
	//**************************************************************************
	// Summary: Returns the current direction of Pac-Man.
	// Precondition: The Player object is created and the user is able to control
	// the Player's movements.
	// Postcondition: Returns the integer value for direction.
	//**************************************************************************
	//
	void setLives(int lives) { this->lives = lives; }
	//**************************************************************************
	// Summary: Sets the number of lives the Player has.
	// Precondition: The Player object is created and is still alive.
	// Postcondition: The number of lives for the Player is set.
	//**************************************************************************
	//
	int getLives()const { return lives; }
	//**************************************************************************
	// Summary: Returns the number of lives the Player object as at any given time.
	// Precondition: The object is created and has lives.
	// Postcondition: The number of lives is returned.
	//**************************************************************************
	//
	void playerDeath();
	//**************************************************************************
	// Summary: Causes the player to cease movement once a life is lost.
	// Precondition: The object has collided with an object of the Ghost class.
	// Postcondition: The player stops moveing and dies. 
	//**************************************************************************
	//

};
#endif