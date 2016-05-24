//**************************************************************************
// ghost.h
// Class Name: Ghost
//
// Summary: Constructs enemy ghosts which chase Pac-Man around the gameboard.
//
// Author: Evelyn murillo & Raquel figueroa
// Created: 29 April 2016
// Summary of Modifications: Raquel helped make the ghost follow pacman, made the ghost Smarter. 
// 	
//**************************************************************************

#ifndef GHOST_H_INCLUDED
#define GHOST_H_INCLUDED
#include "character.h"

class Ghost :public Character {

public:
	Ghost();
	//**************************************************************************
	// Summary: Constructs a Ghost object with a default gameboard position and 
	// rectangle attribute. 
	// Precondition: The gameboard is constructed allowing for the ghost
	// to be drawn at the default position.
	// Postcondition: The Ghost object is constructed with default attributes.
	//**************************************************************************
	//
	void update();
	//**************************************************************************
	// Summary: Updates the Ghost and its respective rectangle's position.
	// Precondition: The Ghost object and its respective rectangle is constructed.
	// Postcondition: The Ghost and its rectangle move in unison throughout the board.
	//**************************************************************************
	//
	int getDirec();
	//**************************************************************************
	// Summary: Returns the current direction of the Ghost object.
	// Precondition: The Ghost is constructed.
	// Postcondition: The direction of the Ghost is returned.
	//**************************************************************************
	//
	void setDirec(int m) { direc = m; }
	//**************************************************************************
	// Summary: Sets a new direction for the Ghost to follow.
	// Precondition: The Ghost object is constructed with the capability to 
	// move in any of the four directions.
	// Postcondition: The Ghost now moves in the new direction passed into the 
	// function.
	//**************************************************************************
	//
	int getDirection2() const { return direc; }
	//**************************************************************************
	// Summary: Sets a new direction for the Ghost to follow.
	// Precondition: The Ghost object is constructed with the capability to 
	// move in any of the four directions.
	// Postcondition: The Ghost now moves in the new direction passed into the 
	// function.
	//**************************************************************************
	//
	int getX()const { return x_coord; }
	//**************************************************************************
	// Summary: Grags the x position of the ghost
	// Precondition: It's updating the x position of the ghost as it moves.
	// Postcondition: It returns the x position of the ghost
	//**************************************************************************
	//
	int getY()const { return y_coord; }
	//**************************************************************************
	// Summary: Grags the y position of the ghost
	// Precondition: It's updating the y position of the ghost as it moves.
	// Postcondition: It returns the y position of the ghost
	//**************************************************************************
	//
	void setY(const int& y) { y_coord = y; }
	//**************************************************************************
	// Summary: It set's the y position of th ghost
	// Precondition: It takes in an int by pass by reference.
	// Postcondition: It set's a new value to the variable y_coord.
	//**************************************************************************
	//
	void setX(const int& x) { x_coord = x; }
	//**************************************************************************
	// Summary: It set's the x position of th ghost
	// Precondition: It takes in an int by pass by reference.
	// Postcondition: It set's a new value to the variable x_coord.
	//**************************************************************************
	//
	void moving1();//function of the first ghost
	//**************************************************************************
	 // Summary: This function is for one of the ghost, because all the ghost have different movements
	// Precondition: The object is constructed and is able to move.
	// Postcondition: It moves the ghost in a certain direction depending on the variable direc.
	//**************************************************************************

	void setPosition(int x, int y);
	//**************************************************************************
	// Summary: Sets the position of the ghost
	// Precondition: Takes in the x and y position for the ghost. 
	// Postcondition: The position of the ghost is updated with the new passed in x and y positions.
	//**************************************************************************
	//
	bool getIsAfraid()const { return this->isAfraid; }
	//**************************************************************************
	// Summary: This return the variable isAfraid.
	// Precondition: The object is constructed
	// Postcondition: Returns the variable isAfraid.
	//**************************************************************************
	//
	void setIsAfraid(bool afraid) { this->isAfraid = afraid; }
	//**************************************************************************
	// Summary: Updates the variable isAfraid to the new value being passed in.
	// Precondition: The bool variable afraid is passed in to the function.
	// Postcondition: It updates the isAfraid with the new given value.
	//**************************************************************************
	//
	bool getOutOfBox()const { return isOutOfBox; }
	//**************************************************************************
	// Summary: This returns a bool variable to see if the ghost is out the box.
	// Precondition: The object is constructed.
	// Postcondition: It returns the value of the variable isOutOfBox.
	//**************************************************************************
	//
	void setOutOfBox(bool out) { this->isOutOfBox = out; }
	//**************************************************************************
	// Summary: This updates the variable to the new passed in variable.
	// Precondition: A new variable is passed in.
	// Postcondition: It updates the isOutOfBox variable to the new passed in value.
	//**************************************************************************
	//
	void randomMovement();
	//**************************************************************************
	// Summary: It randomly picks a direction for the ghost.
	// Precondition: The object is constructed.
	// Postcondition: It returns the new direction for the ghost.
	//**************************************************************************
	//
	bool getHitWall()const { return hitWall; }
	//**************************************************************************
	// Summary: Returns true or false depending if the ghost hit the wall or not.
	// Precondition: The object was created.
	// Postcondition: This function returns a bool. The value depends on whether or not the
	// hit the wall.
	//**************************************************************************
	//
	void setHitWall(bool hit) { hitWall = hit; }
	//**************************************************************************
	// Summary: This sets a new value to the variable is hitWall with the passed in value
	// Precondition: A bool variable is passed in.
	// Postcondition: It sets the value of hitWall to the new passed in value.
	//**************************************************************************

	sf::RectangleShape upRect;
	sf::RectangleShape downRect;
	sf::RectangleShape leftRect;
	sf::RectangleShape rightRect;

	sf::RectangleShape dirRect;
	bool isOutOfBox;
	bool isUpDirectBlock = false;
	bool isDownDirectBlock = false;
	bool isRightDirectBlock = false;
	bool isLeftDirectBlock = false;

private:
	int direc;
	int y_coord;
	int x_coord;
	int counterWalking;

	bool isAlive;
	bool isAfraid;
	bool hitWall;




};

#endif // GHOST_H_INCLUDED