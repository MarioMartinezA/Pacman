//**************************************************************************
// ball.h
// Class Name: Ball
//
// Summary: Creates Ball objects that will be the pellets Pac-Man eats
// throughout the game to get points.
//
// Author: Raquel Figueroa
// Created: 30 April 2016
// Summary of Modifications:
// 	Large Ball objects created by Mario.
//**************************************************************************

#ifndef BALL_H
#define BALL_H

#include "character.h"

class Ball : public Character
{

private:
	bool isShowing;
	int counterWalking;
	bool isLargePellet;

public:
	Ball();
	//**************************************************************************
	// Summary: Creates a Ball object for the gameboard.
	// Precondition: The gameborad tiles are created and laid out on the board.
	// Postcondition: The object is created but not yet placed on the board.
	//**************************************************************************
	//
	Ball(int x, int y);
	//**************************************************************************
	// Summary: Creates a Ball object with a specified x and y position coordinate.
	// Precondition: The gameboard tiles are created and laid out on the board.
	// Postcondition: The object is created and is placed at the specified
	// x and y positions passed into it.
	//**************************************************************************
	//
	void update();
	//**************************************************************************
	// Summary: Updates the sprite sheet to mimic the animation of the all objects.
	// Precondition: The correct image file is uploaded.
	// Postcondition: The objects appear to be twinkling on the board.
	//**************************************************************************
	//
	void setIsShowing(bool isShowing) { this->isShowing = isShowing; }
	//**************************************************************************
	// Summary: Determines if the object will show up on the board or not.
	// Precondition: The object is created and a boolean value is passed in.
	// Postcondition: The object is showing if set to true and not showing if false.
	//**************************************************************************
	//
	void setXYPosition(int x, int y);
	//**************************************************************************
	// Summary: Can change the position of the object on the board.
	// Precondition: The object is created.
	// Postcondition: The x and y positions of the object are set to their 
	// respective values passed in.
	//**************************************************************************
	//
	bool getIsShowing() const { return isShowing; }
	//**************************************************************************
	// Summary: Returns the boolean value is isShowing.
	// Precondition: The object is created.
	// Postcondition: The boolean value of isShowing is returned.
	//**************************************************************************
	//
	void setLargePellet(bool pellet) { this->isLargePellet = pellet; }
	//**************************************************************************
	// Summary: Creates a large pellet object.
	// Precondition: An object is created with the capability of being large.
	// Postcondition: The large pellet is created.
	//**************************************************************************
	//
	bool getIsLargePellet()const { return this->isLargePellet; }
	//**************************************************************************
	// Summary: Returns the boolean value if isLargePellet.
	// Precondition: The object is created.
	// Postcondition: The boolean value is returned.
	//**************************************************************************
	//

};

#endif 