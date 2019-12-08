// Timber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include "General.h"
//#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>




int main()
{
	sf::VideoMode vm(WINDOW_HEIGHT, WINDOW_WIDTH);
	sf::RenderWindow window(vm, "Lumberjack", Style::Fullscreen);

	// Create textures, sprites and some logic
	Texture textureBackground;
	textureBackground.loadFromFile("graphics/background2.png");
	Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);

	Texture textureBackground2;
	textureBackground2.loadFromFile("graphics/152481_su2.jpg");
	Sprite spriteBackground2;
	spriteBackground2.setTexture(textureBackground2);
	spriteBackground2.setPosition(0, 0);

	Texture textureCoffeeCup;
	textureCoffeeCup.loadFromFile("graphics/timh.png");
	Sprite spriteCoffeeCup;
	spriteCoffeeCup.setTexture(textureCoffeeCup);
	spriteCoffeeCup.setPosition(780, 840);


	Texture textureTree;
	textureTree.loadFromFile("graphics/tree2.png");
	Sprite spriteTree;
	spriteTree.setTexture(textureTree);
	spriteTree.setPosition(810, 0);

	Texture textureTree2;
	textureTree2.loadFromFile("graphics/tree_secondary.png");
	Sprite spriteTree2, spriteTree3, spriteTree4, spriteTree5, spriteTree6;
	spriteTree2.setTexture(textureTree2);
	spriteTree3.setTexture(textureTree2);
	spriteTree4.setTexture(textureTree2);
	spriteTree5.setTexture(textureTree2);
	spriteTree6.setTexture(textureTree2);

	spriteTree2.setPosition(20, 0);
	spriteTree3.setPosition(300, -400);
	spriteTree4.setPosition(1300, -400);
	spriteTree5.setPosition(1500, -500);
	spriteTree6.setPosition(1900, 0);



	// Leaf
	Texture textureLeaf;
	textureLeaf.loadFromFile("graphics/canflag2.png");
	Sprite spriteLeaf;
	spriteLeaf.setTexture(textureLeaf);
	spriteLeaf.setPosition(0, 0);
	bool leafActive = false;
	float leafSpeed = 0.0f;



	// Bee
	Texture textureBee;
	textureBee.loadFromFile("graphics/bee2.png");
	Sprite spriteBee;
	spriteBee.setTexture(textureBee);
	spriteBee.setPosition(0, 800);

	bool beeActive = false;
	float beeSpeed = 0.0f;



	// make 3 cloud sprites from 1 texture
	Texture textureCloud;
	// Load 1 new texture
	textureCloud.loadFromFile("graphics/cloud3.png");

	const int NUM_CLOUDS = 6;
	Sprite spriteClouds[NUM_CLOUDS];
	int cloudsSpeed[NUM_CLOUDS];
	bool cloudsActive[NUM_CLOUDS];

	for (int i = 0 ; i < NUM_CLOUDS ; i++)
	{
		spriteClouds[i].setTexture(textureCloud);
		spriteClouds[i].setPosition(-300, i *  150);
		cloudsActive[i] = false;
		cloudsSpeed[i] = 0;
	}



	// Variables to control time itself
	Clock clock;

	RectangleShape timeBar;
	float timeBarStartWidth = 400;
	float timeBarHeight = 80;
	timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
	timeBar.setFillColor(Color::Red);
	timeBar.setPosition((1920 / 2) - timeBarStartWidth / 2, 980);

	Time gameTimeTotal;
	float timeRemaining = 6.0f;
	float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;



	// Track whether the game is running
	bool paused = true;
	// Draw some text
	int score = 0;


	sf::Text messageText;
	sf::Text scoreText;
	sf::Text fpsText;

	// We need to choose a font
	sf::Font fontKomikap;
	fontKomikap.loadFromFile("fonts/KOMIKAP_.ttf");
	sf::Font fontClear;
	fontClear.loadFromFile("fonts/OpenSans-Light.ttf");

	
	messageText.setFont(fontKomikap);
	messageText.setString("Press Enter to start!");
	messageText.setCharacterSize(75);
	messageText.setFillColor(Color::White);
	messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);

	scoreText.setFont(fontKomikap);
	scoreText.setString("Eh-o-meter = 0");
	scoreText.setCharacterSize(75);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(20, 20);

	fpsText.setFont(fontClear);
	fpsText.setCharacterSize(30);
	fpsText.setFillColor(Color::Blue);
	fpsText.setPosition(1700, 20);

	// Position the text
	FloatRect textRect = messageText.getLocalBounds();

	messageText.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);


	
	

	RectangleShape rectScore;
	rectScore.setFillColor(sf::Color(0, 0, 0, 150));
	rectScore.setSize(sf::Vector2f(800, 105));
	rectScore.setPosition(0,10);

	RectangleShape rectFPS;
	rectFPS.setFillColor(sf::Color(0, 0, 0, 150));
	rectFPS.setSize(sf::Vector2f(300, 60));
	rectFPS.setPosition(1685, 10);


	// Prepare 5 branches
	sf::Texture textureBranch;
	textureBranch.loadFromFile("graphics/branch.png");


	// Set the texture for each branch sprite
	for (int i = 0; i < NUM_BRANCHES; i++) {
		branches[i].setTexture(textureBranch);
		branches[i].setPosition(-2000, -2000);

		// Set the sprite's origin to dead centre
		// We can then spin it round without changing its position
		branches[i].setOrigin(220, 20);
	}




	// Prepare the player
	Texture texturePlayer;
	texturePlayer.loadFromFile("graphics/player.png");
	Sprite spritePlayer;
	spritePlayer.setTexture(texturePlayer);
	spritePlayer.setPosition(580, 720);

	// The player starts on the left
	side playerSide = side::LEFT;

	// Prepare the gravestone
	Texture textureRIP;
	textureRIP.loadFromFile("graphics/rip2.png");
	Sprite spriteRIP;
	spriteRIP.setTexture(textureRIP);
	spriteRIP.setPosition(675, 2000);

	// Prepare the axe
	Texture textureAxe;
	textureAxe.loadFromFile("graphics/axe.png");
	Sprite spriteAxe;
	spriteAxe.setTexture(textureAxe);
	spriteAxe.setPosition(2000, 850);
	spriteAxe.setOrigin(76, 37);
	spriteAxe.scale(-1, 1);

	// Line the axe up with the tree
	const float AXE_POSITION_LEFT = 780;
	const float AXE_POSITION_RIGHT = 1135;
	bool axeFlipped = false;

	// Prepare the flying log
	Texture textureLog;
	textureLog.loadFromFile("graphics/log.png");
	Sprite spriteLog;
	spriteLog.setTexture(textureLog);
	spriteLog.setPosition(810, 720);

	// Some other useful log related variables
	bool logActive = false;
	float logSpeedX = 1000;
	float logSpeedY = -1500;

	// Control the player input
	bool acceptInput = false;

	// Prepare the sound
	SoundBuffer chopBuffer;
	chopBuffer.loadFromFile("sound/chop.wav");
	Sound chop;
	chop.setBuffer(chopBuffer);


	SoundBuffer deathBuffer;
	deathBuffer.loadFromFile("sound/death.wav");
	Sound death;
	death.setBuffer(deathBuffer);

	// Out of time
	SoundBuffer outOfTimeBuffer;
	outOfTimeBuffer.loadFromFile("sound/out_of_time.wav");
	Sound outOfTime;
	outOfTime.setBuffer(outOfTimeBuffer);

	int lastDrawn = 0;

	float timeBetweenFrames = 1; //force first frame to be drawn
	
	while (window.isOpen())
	{
		//-----------------------------------------------------------
		// not tested
		// score ++;
		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::KeyReleased && !paused)
			{
				// Listen for key presses again
				acceptInput = true;

				// hide the axe
				spriteAxe.setPosition(2000, spriteAxe.getPosition().y);
			}

		}
		//-----------------------------------------------------------




		/*
		****************************************
		Handle the players input
		****************************************
		*/

		// quit game
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		// start match
		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			paused = false;

			// Reset the time and the score
			score = 0;
			timeRemaining = 6.0f;


			// clear all branches
			for (int i = 0; i < NUM_BRANCHES; i++)
			{
				branchPositions[i] = side::NONE;
			}

			//hide tombstone
			spriteRIP.setPosition(675, 2000);

			// Move the player into position
			spritePlayer.setPosition(580, 720);

			acceptInput = true;

		}

		//--------------------------------------
		//not tested
		// perform action
		if (acceptInput)
		{

			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				playerSide = side::RIGHT;
				spritePlayer.setPosition(1200, 720);

				if (axeFlipped == false) { axeFlipped = true; spriteAxe.scale(-1, 1);  }
				spriteAxe.setPosition(AXE_POSITION_RIGHT, spriteAxe.getPosition().y);

				score++;

				//timeRemaining += (2 / score) + .15;
				timeRemaining++;


				// update the branches
				updateBranches(score);

				// set the log flying to the left
				spriteLog.setPosition(810, 720);
				logSpeedX = -5000;
				logActive = true;


				acceptInput = false;

				// Play a chop sound
				chop.play();

			}

			// Handle the left cursor key
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				playerSide = side::LEFT;
				spritePlayer.setPosition(580, 720);
				if (axeFlipped == true) { axeFlipped = false; spriteAxe.scale(-1, 1); }
				spriteAxe.setPosition(AXE_POSITION_LEFT, spriteAxe.getPosition().y);

				score++;

				timeRemaining += (2 / score) + .15;

				// update the branches
				updateBranches(score);

				// set the log flying
				spriteLog.setPosition(810, 720);
				logSpeedX = 5000;
				logActive = true;


				acceptInput = false;

				// Play a chop sound
				chop.play();

			}


		}

		//--------------------------------------

		/*
		****************************************
		Update the scene
		****************************************
		*/

		if (paused == false) 
		{

			Time dt = clock.restart();
			timeBetweenFrames += dt.asSeconds();

			//std::cout << "Time diff: " << dt.asSeconds();

			// Subtract from the amount of time remaining
			timeRemaining -= dt.asSeconds();
			// size up the time bar
			timeBar.setSize(Vector2f(timeBarWidthPerSecond * timeRemaining, timeBarHeight));




			if (timeRemaining <= 0.0f) {

				// Pause the game
				paused = true;

				// Change the message shown to the player
				messageText.setString("Coffee time!");

				//Reposition the text based on its new size
				FloatRect textRect = messageText.getLocalBounds();

				messageText.setOrigin(textRect.left + textRect.width / 2.0f,
					textRect.top + textRect.height / 2.0f);

				messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);

				// Play the out of time sound
				outOfTime.play();

			}


			// Setup the bee
			if (!beeActive)
			{
				// How fast is the bee
				srand((int)time(0) * 10);
				beeSpeed = (rand() % 200) + 200;

				// How high is the bee
				srand((int)time(0) * 10);
				float height = (rand() % 500) + 500;
				spriteBee.setPosition(2000, height);
				beeActive = true;
			}
			else
				// Move the bee
			{

				spriteBee.setPosition(
					spriteBee.getPosition().x -
					(beeSpeed * dt.asSeconds()),
					spriteBee.getPosition().y);

				// Has the bee reached the right hand edge of the screen?
				if (spriteBee.getPosition().x < -100)
				{
					// Set it up ready to be a whole new cloud next frame
					beeActive = false;
				}
			}

			//manage cloud's array
			for(int i = 0 ; i < NUM_CLOUDS ; i++)
			{
				if (cloudsActive[i] == false) 
				{
					srand( (int)time(0) * i );
					cloudsSpeed[i] = ( rand() % 200 );

					srand((int)time(0)* i);
					float height = ( rand() % 150 );

					spriteClouds[i].setPosition(-200, height);
					cloudsActive[i] = true;
				}
				else
				{
					spriteClouds[i].setPosition(
						spriteClouds[i].getPosition().x + ( cloudsSpeed[i] * dt.asSeconds() ) ,
						spriteClouds[i].getPosition().y  );

					if (spriteClouds[i].getPosition().x > 1920 )
					{ cloudsActive[i] = false; }
				}
			}


			if (leafActive == false)
			{
				srand((int)time(0) * 40);
				leafSpeed = (rand() % 300);

				srand((int)time(0) * 40);
				float height = (rand() % 500);
				spriteLeaf.setPosition(-200, height);
				leafActive = true;
			}
			else
			{
				spriteLeaf.setPosition(
					spriteLeaf.getPosition().x +
					(leafSpeed * dt.asSeconds()),
					spriteLeaf.getPosition().y);

				if (spriteLeaf.getPosition().x > 1920)
				{
					leafActive = false;
				}
			}






			// Draw the score and the frame rate once every 100 frames
			lastDrawn++;
			if (lastDrawn == 100)
			{
				//std::stringstream ss;
				//ss << "Score = " << score;
				//scoreText.setString(ss.str());

				// Update the score text
				std::stringstream ss;
				ss << "Eh-o-meter = " << score;
				scoreText.setString(ss.str());

				std::stringstream ss2;
				ss2 << "FPS = " << 1 / dt.asSeconds();
				fpsText.setString(ss2.str());
				lastDrawn = 0;

			}

			// update the branch sprites
			for (int i = 0; i < NUM_BRANCHES; i++)
			{

				float height = i * 150;

				if (branchPositions[i] == side::LEFT)
				{
					// Move the sprite to the left side
					branches[i].setPosition(610, height);
					// Flip the sprite round the other way
					branches[i].setOrigin(220,40);
					branches[i].setRotation(180);
				}
				else if (branchPositions[i] == side::RIGHT)
				{
					// Move the sprite to the right side
					branches[i].setPosition(1330, height);
					// Set the sprite rotation to normal
					branches[i].setOrigin(220, 40);
					branches[i].setRotation(0);

				}
				else
				{
					// Hide the branch
					branches[i].setPosition(3000, height);
				}
			}

			//---------------------------------------
			// Handle a flying log				
			if (logActive)
			{

				spriteLog.setPosition(
					spriteLog.getPosition().x + ( logSpeedX * dt.asSeconds() ),
					spriteLog.getPosition().y + ( logSpeedY * dt.asSeconds() ) 
				);

				//check if log has left the visible area of the screen
				if (spriteLog.getPosition().x < -100 || spriteLog.getPosition().x > 2000)
				{
					logActive = false;
					spriteLog.setPosition(810, 720);
				}
			}



			/* 
			               [branches No]
				   .||----###  [0]
				   .||.        [1]
			 ###----||.        [2]
				   .||----###  [3]
				   .||.        [4]
				   .||----###  [5] <- [player level]
			*/

			// has the player been hit by a branch?
			if (branchPositions[5] == playerSide)
			{
				// death
				paused = true;
				acceptInput = false;

				//draw tombstone
				if (playerSide == side::LEFT) { spriteRIP.setPosition(600, 760);  }
				else { spriteRIP.setPosition(1200, 760);  }
				

				// hide the player
				spritePlayer.setPosition(2000, 660);
				spriteAxe.setPosition(2000,spriteAxe.getPosition().y);

				// Change the text of the message
				messageText.setString("Sorry!");

				// Center it on the screen
				FloatRect textRect = messageText.getLocalBounds();

				//set origin to the center of 'messageText'
				messageText.setOrigin(
					textRect.left + textRect.width / 2.0f,
					textRect.top + textRect.height / 2.0f
				);

				// move 'messageText' to the position below, but keeping in mind that these coordinates will be applied
				//  to its center
				messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);

				// Play the death sound
				death.play();


			}
			//---------------------------------------

		}// End if(!paused)


		

		/*
		****************************************
		Draw the scene
		****************************************
		*/

		////setting the framerate to 30fps - if the time between frames is lower than dt 0.033f skip drawing
		//if (timeBetweenFrames < 0.0167f && timeRemaining >= 0.0f) { continue; }
		//else { timeBetweenFrames = 0; }

		// clear screen
		window.clear();

		//background
		window.draw(spriteBackground2);
		window.draw(spriteBackground);

		

		for(int i = 0 ; i < NUM_CLOUDS ; i++)
		{ 
			window.draw(spriteClouds[i]);
		}

		window.draw(spriteLeaf);

		window.draw(spriteTree);
		window.draw(spriteTree2);
		window.draw(spriteTree3);
		window.draw(spriteTree4);
		window.draw(spriteTree5);
		window.draw(spriteTree6);



		// Draw branches
		for (int i = 0; i < NUM_BRANCHES; i++) {
			window.draw(branches[i]);
		}

		window.draw(spriteCoffeeCup);
		window.draw(spritePlayer);
		window.draw(spriteAxe);
		window.draw(spriteLog);
		window.draw(spriteRIP);
		window.draw(spriteBee);
		window.draw(rectScore);
		window.draw(rectFPS);
		window.draw(scoreText);
		window.draw(fpsText);
		window.draw(timeBar);

		if (paused)
		{
			// Draw our message
			window.draw(messageText);
		}
		//----------------------


		// Show everything we just drew
		window.display();


	}


    std::cout << "Hello World!\n";
	//int x;

	//std::cin >> x;

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
