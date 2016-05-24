//**************************************************************************
// ghost.cpp
// Class Name: Ghost
//
// Summary: Creates the enemy ghosts that chase Pac-Man throughout the 
// gameboard. This class also controls the movmements of the ghosts
// throughout the gameboard.
//
//**************************************************************************

#include "ghost.h"
#include<cstdlib>
#include<time.h>
#include"character.h"
#include<iostream>
#include<ctime>

using namespace std;

int Ghost::getDirec()
{
	//return rand() % 10 + 1;//cases for the swtich statement
	return direc;

}

Ghost::Ghost()
{
	sprite.setPosition(sf::Vector2f(280, 410));
	rect.setPosition(sf::Vector2f(280, 410));

	rect.setSize(sf::Vector2f(17, 17));
	rect.setFillColor(sf::Color::Green);

	counterWalking = 0;
	isAfraid = false;
	isOutOfBox = false;
	isUpDirectBlock = false;
	isDownDirectBlock = false;
	isRightDirectBlock = false;
	isLeftDirectBlock = false;
	hitWall = false;

	rect2.setSize(sf::Vector2f(17, 17));
	rect2.setFillColor(sf::Color::Green);

	//Setting up the rectangel for a 4 directions

	upRect.setSize(sf::Vector2f(17,7));
	downRect.setSize(sf::Vector2f(17, 7));
	leftRect.setSize(sf::Vector2f(7, 17));
	rightRect.setSize(sf::Vector2f(7, 17));

	dirRect.setSize(sf::Vector2f(5,5));
	dirRect.setFillColor(sf::Color::Yellow);

	//Adding collor all 4 Rectangles
	upRect.setFillColor(sf::Color::Green);
	downRect.setFillColor(sf::Color::Blue);
	leftRect.setFillColor(sf::Color::Red);
	rightRect.setFillColor(sf::Color::Cyan);

}

void Ghost::update()
{
	sprite.setPosition(rect.getPosition().x - 4, rect.getPosition().y - 4);
	sprite2.setPosition(rect.getPosition().x - 4, rect.getPosition().y - 4);

	upRect.setPosition(rect.getPosition().x, rect.getPosition().y - 7);
	downRect.setPosition(rect.getPosition().x, rect.getPosition().y + 17);
	leftRect.setPosition(rect.getPosition().x - 7, rect.getPosition().y);
	rightRect.setPosition(rect.getPosition().x + 17, rect.getPosition().y);
	switch (direc)
	{
	case 1:
		dirRect.setPosition(rect.getPosition().x + 5, rect.getPosition().y + 17);
		break;
	case 2:
		dirRect.setPosition(rect.getPosition().x + 17, rect.getPosition().y +8);
		break;
	case 3:
		dirRect.setPosition(rect.getPosition().x - 5, rect.getPosition().y +8);
		break;
	case 4:
		dirRect.setPosition(rect.getPosition().x + 8, rect.getPosition().y - 5);
		break;
	}
}

void Ghost::setPosition(int x, int y)
{
	sprite.setPosition(sf::Vector2f(x, y));
	rect.setPosition(sf::Vector2f(x, y));
	sprite2.setPosition(sf::Vector2f(x, y));
}

void Ghost::moving1()//random ghost behavior 
{
	//setDirec(getDirec());
	switch (direc)
	{
	case 1:
		sprite.setTextureRect(sf::IntRect(24 * counterWalking + (24 * 6), 0, 24, 24));//to show the moving eyes
														   //cout << "Moving down" << endl;
		sprite.move(0, 3);//moves down
		rect.move(0, 3);
		sprite2.move(0, 3);
		break;
	case 2:
		sprite.setTextureRect(sf::IntRect(24 * counterWalking + 0, 0, 24, 24));
		//cout << "Moving left" << endl;
		sprite.move(3, 0);// moves to the Right
		rect.move(3, 0);
		sprite2.move(3, 0);
		break;
	case 3:
		sprite.setTextureRect(sf::IntRect(24 * counterWalking + (24 * 2), 0, 24, 24));
		//cout << "Moving to right" << endl;
		sprite.move(-3, 0); // moves to the Left
		rect.move(-3, 0);
		sprite2.move(-3, 0);
		break;
	case 4:
		sprite.setTextureRect(sf::IntRect(24 * counterWalking + (24 * 4), 0, 24, 24));
		//cout << "Moving up" << endl;
		sprite.move(0, -3); // moves up
		rect.move(0, -3);
		sprite2.move(0, -3);

		break;

	}
	counterWalking++;

	if (counterWalking == 2)
	{
		counterWalking = 0;
	}
}


void Ghost::randomMovement()
{


	int move = 0;
	bool pick = true;
	srand(time(0));
	/*
	switch (direc)
	{
	case 1:
		isUpDirectBlock = true;
		break;
	case 2:
		isLeftDirectBlock = true;
		break;
	case 3:
		isRightDirectBlock = true;
		break;
		isDownDirectBlock = true;
	case 4:
		break;
	}
	*/

	while (pick)
	{
		//std::cout << move << std::endl;

		move = rand() % 4 + 1;

		switch(move)
		{
		case 1:
			if (!isDownDirectBlock)
			{
				//std::cout << "First If\n";
				direc = 1;
				pick = false;
			}
			break;
		case 2:
			if (!isRightDirectBlock)
			{
				//std::cout << "Second If\n";
				direc = 2;
				pick = false;
			}
			break;
		case 3:
			if (!isLeftDirectBlock)
			{
				//std::cout << "Third If\n";
				direc = 3;

				pick = false;
			}
			break;
		case 4:
			if (!isUpDirectBlock)
			{
				//std::cout << "Fourth If\n";
				direc = 4;
				pick = false;
			}
			break;
		}

	}
}