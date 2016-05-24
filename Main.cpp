/*
g++ -c main.cpp
g++ *.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app


g++ -c main.cpp && g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system && ./sfml-app
*/



#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

#include "player.h"
#include "tile.h"
#include "menu.h"
#include "ghost.h"
#include "ball.h"
#include "GameO.h"

using namespace std;
using namespace sf;

int main()
{
	int scale = 3;
	int counter = 0;
	int counter2 = 0;
	int currentDirection = 0;
	int ballIndex = 0;
	int score = 0;
	int outOfBoxCounter = 0;
	const int maxBallCount = 245;
	bool wait = true;
	int positionGhost = 280;
	bool pinkOutBox = false;
	Clock boxClock;
	Clock introClock;
	Clock afraidClock;

	enum Status
	{
		Stopped,
		Paused,
		Playing
	};
	sf::RenderWindow window(sf::VideoMode(224 * scale, 288 *scale), "Pacman");
	window.setFramerateLimit(30);
				
				
	//***************************************************
	sf::Texture whiteGhost;

	if (!whiteGhost.loadFromFile("Images/whiteGhost.png"))
	{
		cout << "Error\n";
	}

	//pinky:
	std::vector<Ghost>::iterator ghostIter;
	std::vector<Ghost> ghostArray;

	Ghost pink;
	sf::IntRect rectPinkSprite(0, 0, 24, 24);
	sf::Texture pinkText;

	if (!pinkText.loadFromFile("Images/redGhost.png"))
	{
		std::cout << "Error\n";
	}
	pink.sprite.setTexture(pinkText);
	pink.sprite2.setTexture(whiteGhost);
	pink.sprite.setTextureRect(rectPinkSprite);
	pink.sprite2.setTextureRect(rectPinkSprite);
	pink.setPosition(positionGhost, 410);

	ghostArray.push_back(pink);


	Ghost inky;
	sf::IntRect rectInkySprite(0, 0, 24, 24);
	sf::Texture inkyText;
	inky.setPosition(positionGhost + 30, 410);

	if (!inkyText.loadFromFile("Images/blueGhost2.png"))
	{
		std::cout << "Error\n";
	}

	inky.sprite.setTexture(inkyText);
	inky.sprite2.setTexture(whiteGhost);
	inky.sprite2.setTextureRect(rectInkySprite);
	inky.sprite.setTextureRect(rectInkySprite);
	ghostArray.push_back(inky);


	Ghost blinky;
	sf::IntRect rectBlinkySprite(0, 0, 24, 24);
	sf::Texture blinkyText;
	blinky.setPosition(positionGhost + 60, 410);

	if (!blinkyText.loadFromFile("Images/pinkGhost.png"))
	{
		std::cout << "Error\n";
	}

	blinky.sprite.setTexture(blinkyText);
	blinky.sprite2.setTexture(whiteGhost);
	blinky.sprite2.setTextureRect(rectBlinkySprite);
	blinky.sprite.setTextureRect(rectBlinkySprite);
	ghostArray.push_back(blinky);


	Ghost clyde;
	sf::IntRect rectClydeSprite(0, 0, 24, 24);
	sf::Texture clydeText;
	clyde.setPosition(positionGhost + 90, 410);

	if (!clydeText.loadFromFile("Images/orangeGhost.png"))
	{
		std::cout << "Error\n";
	}

	clyde.sprite.setTexture(clydeText);
	clyde.sprite2.setTexture(whiteGhost);
	clyde.sprite2.setTextureRect(rectClydeSprite);
	clyde.sprite.setTextureRect(rectClydeSprite);
	ghostArray.push_back(clyde);




	//****************************************************

	//***************************************************
	//Loading in Map to position the walls
	std::ifstream fin;
	fin.open("level.txt");
	int val;
	if (fin.fail())
	{
		cout << "Error couldn't load file" << endl;
	}
	//***************************************************
	//balls:
	
	Ball ball;
	std::vector<Ball>::iterator ballIter;
	std::vector<Ball> ballArray;


	sf::IntRect rectBallSprite(0, 0, 24, 24);
	sf::Texture ballText;

	sf::Texture largePalletText;

	if (!ballText.loadFromFile("Images/pellets.png"))
	{
		std::cout << "Error\n";
	}
	if (!largePalletText.loadFromFile("Images/largePellet.png"))
	{
		std::cout << "Error\n";
	}

	
	
	//***************************************************
	// Setting up the tile that represent the walls
	//Positioning the walls in the map
	std::vector<Tile>::const_iterator tileIter;
	std::vector<Tile> tileArray;

	Tile tile;

	sf::Vector2i Grid(28 * scale, 36 * scale);

	for (int y = 0; y < 36; y++)
	{
		for (int x = 0; x < 28; x++)
		{
			fin >> val;
			cout << val;
			if (val == 1)
			{
				tile.update(x, y);
				tileArray.push_back(tile);
			}
			//setting coordinates for 250 ball objects in array
			
			if (((y >= 4 && y < 12) || (y >= 12 && (x == 6 || x == 21)) || (y >= 23 && y < 34))
				&& (val == 0) && (ballIndex < maxBallCount))
			{
				ball.setXYPosition(x * 24 + 3, y * 24 + 3);
				ball.sprite.setTexture(ballText);
				ball.sprite.setTextureRect(rectBallSprite);
				ball.setLargePellet(false);
				ballArray.push_back(ball);
				ballIndex++;
			}
			else if (val == 3)
			{
				ball.setXYPosition(x * 24 + 3, y * 24 + 3);
				ball.sprite.setTexture(largePalletText);
				ball.sprite.setTextureRect(rectBallSprite);
				ball.setLargePellet(true);
				ballArray.push_back(ball);
				ballIndex++;

			}
			
		}
	}
	//Setting up the walls for when pacman goes through the tunnel
	tile.update(-1, 16);
	tileArray.push_back(tile);
	tile.update(28, 16);
	tileArray.push_back(tile);

	tile.update(-1, 18);
	tileArray.push_back(tile);
	tile.update(28, 18);
	tileArray.push_back(tile);

	fin.close();
	//****************************************************
	//Background Setup:
	sf::Texture background;

	if (!background.loadFromFile("Images/pacmanMap.png"))
	{
		std::cout << "Error\n";
	}
	sf::Sprite map(background);
	map.scale(scale, scale);

	//******************************************************
	//Loading up the waka waka sound
	sf::SoundBuffer playsiren;
	if (!playsiren.loadFromFile("Sound/Pacman_Siren.wav"))
	{
		std::cout << "Couldn't load sound file.\n";
	}
	Sound siren;
	siren.setBuffer(playsiren);

	//******************************************************
	//Loading up the starting music
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("Sound/PacmanIntro.wav"))
	{
		std::cout << "Couldn't load sound file.\n";
	}
	Sound introMusic;
	introMusic.setBuffer(buffer);
	//*******************************************************
	//Loading up the waka waka sound
	sf::SoundBuffer wakaWaka;
	if (!wakaWaka.loadFromFile("Sound/Pacman_Waka_WakaV2.wav"))
	{
		std::cout << "Couldn't load sound file.\n";
	}
	Sound waka;
	waka.setBuffer(wakaWaka);

	//********************************************************
	//Player setup and Loading up the pacman image
	//Setting up the demensions of the sprite
	sf::IntRect rectSourceSprite(0, 0, 24, 24);

	Player player;
	sf::Texture pacText;
	if ( !pacText.loadFromFile( "Images/pacmanDirections.png" ) )
	{
		std::cout << "Error\n";
	}

	player.sprite.setTexture(pacText);
	player.sprite.setTextureRect(rectSourceSprite);
	//********************************************************
	//Lives
	sf::IntRect rectLiveSprite(24, 0, 24, 24);
	sf::Sprite live1;


	live1.setTexture(pacText);
	live1.setTextureRect(rectLiveSprite);
	live1.setOrigin(-600, -45);

	sf::Sprite live2;
	live2.setTexture(pacText);
	live2.setTextureRect(rectLiveSprite);
	live2.setOrigin(-624, -45);
	//********************************************************
	sf::IntRect recCherrieSprite(0, 0, 24, 24);
	sf::Texture cherrieText;
	if (!cherrieText.loadFromFile("Images/Cherrie2.png"))
	{
		std::cout << "Error\n";
	}
	Character cherrie;
	cherrie.sprite.setTexture(cherrieText);
	cherrie.sprite.setTextureRect(recCherrieSprite);
	cherrie.sprite.setOrigin(-100, -90);

	//********************************************************
	//Set Tiles to Grid 
	sf::Texture setGridTexture;
	sf::Sprite setGridSprite;
	setGridSprite.setTexture(setGridTexture);
	setGridSprite.setColor(sf::Color::Black);

	//*******************************************************
	//Creating a Grid
	//Creating a Texture and a sprite
	sf::RectangleShape tempGridSpriteOutline;
	tempGridSpriteOutline.setOutlineColor(sf::Color::White);
	tempGridSpriteOutline.setOutlineThickness(0.5);
	tempGridSpriteOutline.setFillColor(sf::Color::Transparent);
	tempGridSpriteOutline.setSize(sf::Vector2f(8 * scale, 8 * scale));

	sf::Font font;
	if (!font.loadFromFile("pacfont.ttf"))
	{
		cout << "fail" << endl;


	}
	sf::Font font2;
	if (!font2.loadFromFile("consola.ttf"))
	{
		cout << "fail" << endl;


	}
	sf::Text text;
	text.setFont(font);
	text.setString("score");
	text.setCharacterSize(43);
	text.setColor(sf::Color::White);
	text.setOrigin(-40, 0);
	
	Menu menu(window.getSize().x, window.getSize().y);
	Gameover gameover(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event) || menu.getIsMenuOn())
		{
			if (event.type == sf::Event::Closed)
				window.close();
			//********************************************************************
			//Creating the menu 
			if (menu.getIsMenuOn())
			{
				window.clear();
				menu.draw(window);
				window.display();
				switch (event.type)
				{
					case sf::Event::KeyReleased:
						switch (event.key.code)
						{
						case sf::Keyboard::Up:
							menu.moveUp();
							break;
						case sf::Keyboard::Down:
							menu.moveDown();
							break;
						case sf::Keyboard::Return:
							switch (menu.getPressedItem())
							{
							case 0:
								wait = true;
								introMusic.play();
								introClock.restart();
								menu.setIsMenuOn(false);
								break;
							case 1:
								window.close();
								break;
							}
						}

				}

			}// end of menu if statement
		} // of event for loop
		//***********************************************************************

		//Display the gameover screen once the player runs out of lives
		if (player.getLives() <= 1)
		{
			sf::RenderWindow window2(sf::VideoMode(224 * scale, 288 * scale), "Game Over");
			while (window2.isOpen())
			{
				window.close();

				while (window2.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window2.close();
					//********************************************************************
					//Creating the menu 

					//window2.clear();
					gameover.draw(window2);
					window2.display();



				}
			}
		}


		window.clear();

		//drawing background
		window.draw(map);
		// this font is for the number, since the other font i downloaded didnt have numbers in it
		sf::Text mytext;
		mytext.setFont(font2);//set the object to the new text
		std::stringstream ss;//converts a interger into a string
		ss << score;
		mytext.setString(ss.str().c_str());
		mytext.setColor(sf::Color::White);
		mytext.setCharacterSize(55);
		mytext.setOrigin(-80, 0);
		window.draw(mytext);
		//window.draw(cherrie.sprite);


		//Draw Grid
		for (int i = 0; i < Grid.x; i++)
		{
			for (int j = 0; j < Grid.y; j++)
			{
				tempGridSpriteOutline.setPosition(i * 8 * scale, j * 8 * scale);
				//window.draw(tempGridSpriteOutline);
			}
		}
		counter = 0;
		//******************************************************
		//Draws tiles throughout the map
		for (tileIter = tileArray.begin(); tileIter != tileArray.end(); tileIter++)
		{
			//window.draw(tileArray[counter].rect);
			counter++;
		}

		//***************************************************
		//Allows the player to move

		player.updateMovement();
		player.update();

		//*****************************************************
		//This gets the ghost out of the box at the start of the game.
		for (ghostIter = ghostArray.begin(); ghostIter < ghostArray.end(); ghostIter++)
		{
			if (outOfBoxCounter < 4)
			{
				switch (outOfBoxCounter)
					{
				case (0) : if (boxClock.getElapsedTime().asSeconds() > 4 &&
								boxClock.getElapsedTime().asSeconds() < 4.6 &&
								!ghostArray[outOfBoxCounter].getOutOfBox())
							{
								ghostArray[outOfBoxCounter].setDirec(2);
							}

						   else if (boxClock.getElapsedTime().asSeconds() > 4.6
							   && boxClock.getElapsedTime().asSeconds() < 4.7
							   && !pinkOutBox)
						   {
							   ghostArray[outOfBoxCounter].setDirec(4);
							   //ghostArray[outOfBoxCounter].setOutOfBox(true);
							   boxClock.restart();
							   outOfBoxCounter++;
						   }
						break;
				case(1) : if (boxClock.getElapsedTime().asSeconds() > 4 &&
								boxClock.getElapsedTime().asSeconds() < 4.2 &&
								!ghostArray[outOfBoxCounter].getOutOfBox())
						{
								ghostArray[outOfBoxCounter].setDirec(2);
						}

						else if (boxClock.getElapsedTime().asSeconds() > 4.2
							&& boxClock.getElapsedTime().asSeconds() < 4.4
							&& !pinkOutBox)
						{
							ghostArray[outOfBoxCounter].setDirec(4);
							//ghostArray[outOfBoxCounter].setOutOfBox(true);
							boxClock.restart();
							outOfBoxCounter++;
						}
						break;

				case(2) : if (boxClock.getElapsedTime().asSeconds() > 4 &&
							boxClock.getElapsedTime().asSeconds() < 4.2 &&
							!ghostArray[outOfBoxCounter].getOutOfBox())
						{
							ghostArray[outOfBoxCounter].setDirec(3);
						}

						 else if (boxClock.getElapsedTime().asSeconds() > 4.2
							  && boxClock.getElapsedTime().asSeconds() < 4.4
							  && !pinkOutBox)
						 {
							  ghostArray[outOfBoxCounter].setDirec(4);
							  //ghostArray[outOfBoxCounter].setOutOfBox(true);
							  boxClock.restart();
							  outOfBoxCounter++;
						 }
						break;
				case(3) : if (boxClock.getElapsedTime().asSeconds() > 4 &&
							boxClock.getElapsedTime().asSeconds() < 4.5 &&
							!ghostArray[outOfBoxCounter].getOutOfBox())
						{
							ghostArray[outOfBoxCounter].setDirec(3);
						}

						 else if (boxClock.getElapsedTime().asSeconds() > 4.5
							  && boxClock.getElapsedTime().asSeconds() < 4.7
							  && !pinkOutBox)
						 {
							  ghostArray[outOfBoxCounter].setDirec(4);
							  //ghostArray[outOfBoxCounter].setOutOfBox(true);
							  boxClock.restart();
							  outOfBoxCounter++;
						 }
						break;
					}
			}

		}


		

		//*************************************************
		//Tunnel mirror
		if (player.rect.getPosition().x <= -14)
		{
			//cout << "Out of the box" << endl;
			player.rect.setPosition(682, player.rect.getPosition().y);
		}
		else if (player.rect.getPosition().x >= 680)
		{
			player.rect.setPosition(-15, player.rect.getPosition().y);
		}

		//***************************************************
		// Wall detection when player collides with a wall
		counter = 0;
		for (tileIter = tileArray.begin(); tileIter != tileArray.end(); tileIter++)
		{
			if ((player.sprite.getPosition().x >= 300 && player.sprite.getPosition().x <= 360) &&
				(player.sprite.getPosition().y <= 370 && player.sprite.getPosition().y >= 351) && player.getDirection() == 2)
			{
				if (player.getDirection() == 2)
				{
					player.rect.move(0, -7);
					break;
				}
			}

			if (player.rect.getGlobalBounds().intersects(tileArray[counter].rect.getGlobalBounds()))
			{
				//cout << "Wall HIT AT: "<< tileArray[counter].rect.getPosition().x << "," << tileArray[counter].rect.getPosition().y << endl;
				currentDirection = player.getDirection();
				switch (currentDirection)
				{
				case 1: player.rect.move(0, 3);
					break;
				case 2: player.rect.move(0, -3);
					break;
				case 3: player.rect.move(3, 0);
					break;
				case 4:	player.rect.move(-3, 0);
					break;
				default:
					break;
				}
			}

			counter++;
		}//end for loop
		

		//********************************************************************
		//Changes the direction of the ghost once it hits a wall.
		counter = 0;
		counter2 = 0;
		bool hit = false;
		for (ghostIter = ghostArray.begin(); ghostIter != ghostArray.end(); ghostIter++)
		{
			ghostArray[counter].setHitWall(false);
			ghostArray[counter].isDownDirectBlock = false;
			ghostArray[counter].isUpDirectBlock = false;
			ghostArray[counter].isLeftDirectBlock = false;
			ghostArray[counter].isRightDirectBlock = false;

			for (tileIter = tileArray.begin(); tileIter != tileArray.end(); tileIter++)
			{
				if(ghostArray[counter].dirRect.getGlobalBounds().intersects(tileArray[counter2].rect.getGlobalBounds()))
				{
					ghostArray[counter].setHitWall(true);
					
					if (ghostArray[counter].rect.getGlobalBounds().intersects(tileArray[counter2].rect.getGlobalBounds()) && ghostArray[counter].getOutOfBox())
					{
					//cout << "Wall hit" << counter << endl;
					//currentDirection = player.getDirection();
					switch (ghostArray[counter].getDirection2())
					{
						case 1: ghostArray[counter].rect.move(0, -3);
						//ghostArray[counter].setDirec(4);
							break;
						case 2: ghostArray[counter].rect.move(-3, 0);
						//ghostArray[counter].setDirec(3);
							break;
						case 3: ghostArray[counter].rect.move(3, 0);
						//ghostArray[counter].setDirec(2);
							break;
						case 4:	ghostArray[counter].rect.move(0, 3);
						//ghostArray[counter].setDirec(1);
							break;
						default:
							break;
					}
					}
				}

				if (ghostArray[counter].upRect.getGlobalBounds().intersects(tileArray[counter2].rect.getGlobalBounds()) &&
					(ghostArray[counter].dirRect.getGlobalBounds().intersects(tileArray[counter2].rect.getGlobalBounds())))
				{
					ghostArray[counter].isUpDirectBlock = true;
					ghostArray[counter].setOutOfBox(true);
					hit = true;
					//ghostArray[counter].rect.move(0, 3);
				}
				if (ghostArray[counter].downRect.getGlobalBounds().intersects(tileArray[counter2].rect.getGlobalBounds()) &&
					(/*ghostArray[counter].rect.getGlobalBounds().intersects(tileArray[counter2].rect.getGlobalBounds())) &&*/ ghostArray[counter].getOutOfBox()))
				{
					ghostArray[counter].isDownDirectBlock = true;
					//ghostArray[counter].rect.move(0, -3);
				}
				if (ghostArray[counter].rightRect.getGlobalBounds().intersects(tileArray[counter2].rect.getGlobalBounds()) &&
					(/*ghostArray[counter].rect.getGlobalBounds().intersects(tileArray[counter2].rect.getGlobalBounds())) &&*/ ghostArray[counter].getOutOfBox()))
				{
					ghostArray[counter].isRightDirectBlock = true;
					//ghostArray[counter].rect.move(-3, 0);
				}
				if (ghostArray[counter].leftRect.getGlobalBounds().intersects(tileArray[counter2].rect.getGlobalBounds()) &&
					(/*ghostArray[counter].rect.getGlobalBounds().intersects(tileArray[counter2].rect.getGlobalBounds())) &&*/ ghostArray[counter].getOutOfBox()))
				{
					ghostArray[counter].isLeftDirectBlock = true;
					//ghostArray[counter].rect.move(3, 0);
				}
				ghostArray[counter].update();

				if (ghostArray[counter].getOutOfBox() && ghostArray[counter].getHitWall())
				{
					//cout << "Wall hit" << endl;
					ghostArray[counter].randomMovement();
				}
							
				counter2++;
			}//end inside for loop
			
			/*
			window.draw(ghostArray[counter].rect);
			window.draw(ghostArray[counter].upRect);
			window.draw(ghostArray[counter].downRect);
			window.draw(ghostArray[counter].leftRect);
			window.draw(ghostArray[counter].rightRect);
			
			window.draw(ghostArray[counter].dirRect);
			*/

			counter2 = 0;
			counter++;
		}// end for loop
		//***************************************************
		//This where the ghost are allowed to move.
		counter = 0;
		for (ghostIter = ghostArray.begin(); ghostIter != ghostArray.end(); ghostIter++)
		{
			ghostArray[counter].moving1();

			counter++;
		}
		//***************************************************
		// If the ghost are blue and eaten by pacman, then the ghost are placed back inside the box
		counter = 0;
		if (ghostArray[0].getIsAfraid())
		{
			for (ghostIter = ghostArray.begin(); ghostIter != ghostArray.end(); ghostIter++)
			{
				//send the ghost back inside the box
				if (player.sprite.getGlobalBounds().intersects(ghostArray[counter].sprite.getGlobalBounds()))
				{
					ghostArray[counter].setOutOfBox(false);
					ghostArray[counter].setPosition(positionGhost + 60, 410);
					score = score + 100;
					break;
				}
				counter++;
			}
		}
		//***************************************************
		//player touches ghost decrease the lifes by one
		int counter = 0;
		for (ghostIter = ghostArray.begin(); ghostIter != ghostArray.end(); ghostIter++)
		{
			//decrements lives if pacman hits ghost
			if (player.sprite.getGlobalBounds().intersects(ghostArray[counter].sprite.getGlobalBounds()) &&
				!ghostArray[counter].getIsAfraid())
			{
				player.sprite.setPosition(sf::Vector2f(14 * 24, 20 * 24 + 4));
				player.rect.setPosition(sf::Vector2f(14 * 24, 20 * 24 + 4));
				if (player.getLives() == 2)
				{
					live1.setOrigin(30, 0);
					player.setLives(player.getLives() - 1);

				}
				//player.sprite.setOrigin(14 * 24, 20 * 24 + 4);

				else if (player.getLives()>  1)
				{
					live2.setOrigin(30, 0);

					//player.sprite.setOrigin(14 * 24, 20 * 24 + 4);
					player.setLives(player.getLives() - 1);
				}

			}
			counter++;
		}

		//GameOver Display
		if (player.getLives() <= 0)
		{
			window.close();
			window.clear();
			gameover.draw(window);
			window.display();


		}// end of menu if statement

		//***************************************************
		// If player intersects with ball:
		counter = 0;
		counter2 = 0;
		for (ballIter = ballArray.begin(); ballIter != ballArray.end(); ballIter++)
		{
			if (player.rect.getGlobalBounds().intersects(ballArray[counter].rect.getGlobalBounds()))
			{
				ballArray[counter].setIsShowing(false);
				//Turn the ghost blue if the pacman eats a large pallet
				if (ballArray[counter].getIsLargePellet())
				{
					afraidClock.restart();
					for (ghostIter = ghostArray.begin(); ghostIter != ghostArray.end(); ghostIter++)
					{
						ghostArray[counter2].setIsAfraid(true);
						counter2++;
					}
					counter2 = 0;

				}
				if (introClock.getElapsedTime().asSeconds() >= 0.41)//introClock restarts
				{
					waka.play();
					//siren.stop();
					introClock.restart();
				}
				score++;
			}
			counter++;
		}// end for loop


		//This deletes the ball from the map
		counter = 0;
		for (ballIter = ballArray.begin(); ballIter != ballArray.end(); ballIter++)
		{
			if (!ballArray[counter].getIsShowing())
			{
				ballArray.erase(ballIter);
				break;
			}
			counter++;
		}// end for loop
		//**************************************************
	


		//**************************************************
		//reset ghost to their original sprite once time runs out
		counter = 0;
		if (afraidClock.getElapsedTime().asSeconds() > 8.0)
		{
			for (ghostIter = ghostArray.begin(); ghostIter != ghostArray.end(); ghostIter++)
			{
				ghostArray[counter].setIsAfraid(false);
				counter++;
			}
		}
		//**************************************************
		// If the siren is paused, unpause it
		if (siren.getStatus() == 0 && introClock.getElapsedTime().asSeconds() > 0.47)
		{
			siren.play();
		}
		//***************************************************
		//cherrie
		if (player.rect.getGlobalBounds().intersects(cherrie.sprite.getGlobalBounds()))
		{
			score += 100;
			cherrie.sprite.setPosition(-100, -50);
		}
		//ball drawn to screen:
		counter = 0;
		for (ballIter = ballArray.begin(); ballIter != ballArray.end(); ballIter++)
		{
			if (ballArray[counter].getIsShowing() == true)
			{
				window.draw(ballArray[counter].sprite);
				ballArray[counter].update();

				//window.draw(ballArray[ix].rect);
			}
			counter ++;
				
		}
		
		//**************************************************************
		//window.draw(player.rect2);
		//drawing the player sprite
		window.draw(player.sprite);
		//drawint the lives
		window.draw(live1);
		window.draw(live2);
		window.draw(cherrie.sprite);
		//window.draw(player.rect);
		//cout << "Player position: " << player.rect.getPosition().x << ", " << player.rect.getPosition().y << endl;
		//****************************************************************
		//Draws ghost to the screen. If they are afraid then the blue sprite shows up instead
		counter = 0;
		for (ghostIter = ghostArray.begin(); ghostIter != ghostArray.end(); ghostIter++)
		{
			if (!ghostArray[counter].getIsAfraid())
			{
				window.draw(ghostArray[counter].sprite);
			}
			else
			{
				window.draw(ghostArray[counter].sprite2);
			}
			//window.draw(ghostArray[counter].rect);
			counter++;
		}

		//*********************************************************
		
		//*********************************************************	
		window.display();
		while (introClock.getElapsedTime().asSeconds() <= 4.0 && wait)
		{
			boxClock.restart();
		}
		if (introClock.getElapsedTime().asSeconds() >= 4.1  && wait)
		{
			siren.setLoop(true);
			siren.play();
		}
		wait = false;

		if (player.getLives() < 1)
		{
			introClock.restart();
			while (introClock.getElapsedTime().asSeconds() < 6.0)
			{
				gameover.draw(window);
				window.display();
			}
			wait = true;
		}
		//cout << ballArray.size() << endl;
		
	}

	return 0;
}