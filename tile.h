//**************************************************************************
// tile.h
// Class Name: Tile
//
// Summary: Constructs the Tile objects which make up the game board grid.
//
// Author: Mario Martinez
// Created: 20 April 2016
// Summary of Modifications: 
// 	
//**************************************************************************
#pragma once
#ifndef TILE_H
#define TILE_H

#include "character.h"

class Tile : public Character
{
private:
	int positionX;
	int positionY;

public:
	Tile();
	//**************************************************************************
	// Summary: Creates Tile objects which will be used to construct the grid of
	// the gameboard and also the boundaries for the Player and Ghost objects.
	// Precondition: The class is called and constructed.
	// Postcondition: The gameboard is constructed using a series of Tile objects.
	//**************************************************************************
	//
	void setX(int x) { this->positionX = x; }
	//**************************************************************************
	// Summary: Sets the x position of the Tile object.
	// Precondition: The Tile object is created.
	// Postcondition: The x position for the Tile is set.
	//**************************************************************************
	//
	void setY(int y) { this->positionY = y; }
	//**************************************************************************
	// Summary: Sets the y position of the Tile object.
	// Precondition:The Tile object is created.
	// Postcondition: The y position of the Tile is set.
	//**************************************************************************
	//
	int getX()const { return positionX; }
	//**************************************************************************
	// Summary: Returns the current x position of a particular Tile object.
	// Precondition: The object has been created and has an x position on the board.
	// Postcondition: The x position is returned.
	//**************************************************************************
	//
	int getY()const { return positionY; }
	//**************************************************************************
	// Summary: Returns the y position of the Tile object.
	// Precondition: The Tile object is constructed and has a y position on the board.
	// Postcondition: The y position of the object is returned.
	//**************************************************************************
	//
	void update(int x, int y);
	//**************************************************************************
	// Summary:  Allows for the Tile's x and y positions to be updated.
	// Precondition: The Tile object is created.
	// Postcondition: The Tile has a new position as determined by the values
	// passed in.
	//**************************************************************************
	//
};
#endif