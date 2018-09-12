//Included libraries
#include <sfml/Graphics.hpp> //Includes graphics
#include <SFML/Audio.hpp> //Includes audio
#include <string> //Include strings

//Entry point for program
int main()
{
	//Make a variable called gameWindow of type renderWindow
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Button Masher", sf::Style::Titlebar | sf::Style::Close);

	///-------------------------------------------------
	///SETUP
	///-------------------------------------------------

	///Sprites

	//Create a varible to hold the texture
	sf::Texture buttonTexture;
	buttonTexture.loadFromFile("graphics/button.png");

	//Create a sprite variable
	sf::Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);

	//Set the position of the sprite
	buttonSprite.setPosition(gameWindow.getSize().x / 2 - buttonTexture.getSize().x / 2, gameWindow.getSize().y / 2 - buttonTexture.getSize().y / 2);


	///Audio

	//Create a music variable, load in the music file and play it
	sf::Music gameMusic;
	gameMusic.openFromFile("audio/music.ogg");
	//gameMusic.play();

	//Create a sound effect for clicking on the button
	sf::SoundBuffer clickBuffer;
	clickBuffer.loadFromFile("audio/buttonclick.ogg");
	sf::Sound clickSound;
	clickSound.setBuffer(clickBuffer);

	//Create a sound effect for gameover
	sf::SoundBuffer gameOverBuffer;
	gameOverBuffer.loadFromFile("audio/gameover.ogg");
	sf::Sound gameOverSound;
	gameOverSound.setBuffer(gameOverBuffer);
	gameOverSound.play();

	//Sound effect for clicking outside of the button
	sf::SoundBuffer nonButtonClickBuffer;
	nonButtonClickBuffer.loadFromFile("audio/Wilhelm.ogg");
	sf::Sound wrongClick;
	wrongClick.setBuffer(nonButtonClickBuffer);

	///Fonts/Text
	
	//Set up a font and load it in
	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainFont.ttf");

	//Create the title text
	sf::Text titleText; //Create a variable to store the text
	titleText.setFont(gameFont); //Set a font for the text using the variable storing the font
	titleText.setString("Button Masher!"); //Set the text

	//Format the title text
	titleText.setCharacterSize(48); //Set the size of the text
	titleText.setFillColor(sf::Color::Cyan); //Set the colour of the text
	titleText.setStyle(sf::Text::Bold | sf::Text::Italic);
	titleText.setPosition(gameWindow.getSize().x / 2 - titleText.getLocalBounds().width / 2, 30);//Set the position of the text

	//Create the author text
	sf::Text authorText; //Create a variable to store the text
	authorText.setFont(gameFont); //Set a font for the text using the variable storing the font
	authorText.setString("By Craig Fletcher"); //Set the text

	//Format author text
	authorText.setCharacterSize(24);
	authorText.setFillColor(sf::Color::Cyan);
	authorText.setStyle(sf::Text::Italic | sf::Text::Underlined);
	authorText.setPosition(gameWindow.getSize().x / 2 - authorText.getLocalBounds().width / 2, gameWindow.getSize().y - 100); //Set the position of the text

	//Create and format score variable and text
	int score = 0;
	sf::Text scoreText;
	scoreText.setFont(gameFont);
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setCharacterSize(16);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(30, 30);

	//Create and format timer text
	sf::Text timerText;
	timerText.setFont(gameFont);
	timerText.setString("Time Remaining: 0");
	timerText.setCharacterSize(16);
	timerText.setFillColor(sf::Color::White);
	timerText.setPosition(gameWindow.getSize().x - timerText.getLocalBounds().width - 30, 30);

	//Create and format text to prompt player to start
	sf::Text promptText;
	promptText.setFont(gameFont);
	promptText.setString("Click the button to start the game!");
	promptText.setCharacterSize(16);
	promptText.setFillColor(sf::Color::Green);
	promptText.setPosition(gameWindow.getSize().x / 2 - promptText.getLocalBounds().width / 2, 200);

	///Time

	//Create time variable
	sf::Time timeLimit = sf::seconds(10.0f);
	sf::Time timeRemaining = timeLimit;
	sf::Clock gameClock;

	///Separate variables

	bool playing = false;

	///-------------------------------------------------
	///Game Loop
	///-------------------------------------------------
	while (gameWindow.isOpen()) //Runs every frame until the game window is closed
	{
		///---------------------------------------------
		///Check for input
		///---------------------------------------------
		sf::Event gameEvent;
		while (gameWindow.pollEvent(gameEvent))
		{
			//Process Events

			//Check if event is a mouse button pressed
			if (gameEvent.type == sf::Event::MouseButtonPressed)
			{
				if (buttonSprite.getGlobalBounds().contains(gameEvent.mouseButton.x, gameEvent.mouseButton.y))
				{
					if (playing == true)
					{
						score += 1;
					}
					else
					{
						playing = true;
						score = 0;
						timeRemaining = timeLimit;
						promptText.setString("Click the button as fast as you can!");
					}
					clickSound.play();
				}
				else
				{
					wrongClick.play();
				}
			}

			//Check if the event is the closed event
			if (gameEvent.type == sf::Event::Closed)
			{
				//Close the game window
				gameWindow.close();
			}
		}

		///---------------------------------------------
		///Update game state
		///-----------------------------------------------------

		sf::Time frameTime = gameClock.restart();
		if (playing == true)
		{
			timeRemaining -= frameTime;
			if (timeRemaining.asSeconds() <= 0)
			{
				playing = false;
				promptText.setString("Your final score was: " + std::to_string((int)timeRemaining.asSeconds()) + ". Click the button to start a new game!");
				gameOverSound.play();
			}
		}	
		timerText.setString("Time Remaining: " + std::to_string((int)timeRemaining.asSeconds()));

		scoreText.setString("Score: " + std::to_string(score));

		///---------------------------------------------
		///Draw graphics
		///---------------------------------------------

		//Clear the window to a single colour
		gameWindow.clear(sf::Color::Black);

		//Draw everything to the window
		gameWindow.draw(buttonSprite);
		gameWindow.draw(titleText);
		gameWindow.draw(authorText);
		gameWindow.draw(scoreText);
		gameWindow.draw(timerText);
		gameWindow.draw(promptText);

		//Display the window contents on the screen
		gameWindow.display();
	}
	//Exit point for program
	return 0;
}