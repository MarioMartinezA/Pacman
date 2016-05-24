//**************************************************************************
// menu.h
// Class Name: Menu
//
// Summary: Opens the beginning Menu screen which allows the player to start
// a new game.
//
// Author: Mario Martinez
// Created: 24 April 2016
// Summary of Modifications:
// 	
//**************************************************************************
#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>


#define MAX_NUMBER_OF_ITEMS 2

class Menu
{

public:
	Menu(float width, float height);
	//**************************************************************************
	// Summary: Creates a Menu window to allow for the user to choose to play
	// the game.
	// Precondition: The game code is run. 
	// Postcondition: The Menu window opens and the user can choose an option.
	//**************************************************************************
	//
	~Menu();
	//**************************************************************************
	// Summary: This destroys the Menu after it is made.
	// Precondition: The Menu is constructed and the user has safely chosen
	// an option to play the game or not.
	// Postcondition: The Menu is safely destructed.
	//**************************************************************************
	//
	void draw(sf::RenderWindow & window);
	//**************************************************************************
	// Summary: Draws the Menu for the user to view.
	// Precondition: The code is run to allow for the function to be called.
	// Postcondition: The user sees the Menu board on the screen. 
	//**************************************************************************
	//
	void moveDown();
		//**************************************************************************
		// Summary: Helps to get the color orientation of the Menu correct.
		// Precondition: The Menu object is constructed.
		// Postcondition: The correct orientation of the colors for the Menu is
		// completed.
		//**************************************************************************
		//
	void moveUp();
		//**************************************************************************
		// Summary: Helps to traverse the Menu to allow for the correct coloring.
		// Precondition: The Menu object is constructed.
		// Postcondition: The correct orientation of the colors for the Menu is 
		// completed.
		//**************************************************************************
		//
	int getPressedItem() const { return selectedItemIndex; }
	//**************************************************************************
	// Summary: Returns the current selectedItemIndex.
	// Precondition: The Menu is constructed.
	// Postcondition: The selectedItemIndex is returned.
	//**************************************************************************
	//
	bool getIsMenuOn() const { return isMenuOn; }
	//**************************************************************************
	// Summary: Returns the boolean value for isMenuOn.
	// Precondition: The Menu object is constructed.
	// Postcondition: The boolean value for isMenuOn is returned.
	//**************************************************************************
	//
	void setIsMenuOn(bool turnOn) { isMenuOn = turnOn; }
	//**************************************************************************
	// Summary: Sets the isMenuOn variable to equal that of turnOn.
	// Precondition: The turnOn variable is defined and the Menu is constructed.
	// Postcondition: The isMenuOn is set to the same value as turnOn.
	//**************************************************************************
	//

private:
	int selectedItemIndex;
	bool isMenuOn;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};
#endif