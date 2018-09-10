//Included libraries
#include <sfml/Graphics.hpp> //Includes graphics
#include <SFML/Audio.hpp> //Includes audio

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
	gameMusic.play();

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
authorText.setStyle(sf::Text::Underlined | sf::Text::Italic);
	authorText.setCharacterSize(24);
	authorText.setFillColor(sf::Color::Cyan);
	
	authorText.setPosition(gameWindow.getSize().x / 2 - authorText.getLocalBounds().width / 2, gameWindow.getSize().y - 100); //Set the position of the text

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

		///---------------------------------------------
		///Draw graphics
		///---------------------------------------------

		//Clear the window to a single colour
		gameWindow.clear(sf::Color::Black);

		//Draw everything to the window
		gameWindow.draw(buttonSprite);
		gameWindow.draw(titleText);
		gameWindow.draw(authorText);

		//Display the window contents on the screen
		gameWindow.display();
	}
	//Exit point for program
	return 0;
}