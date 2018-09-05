//Included libraries
#include <sfml/Graphics.hpp>

//Entry point for program
int main()
{
	//Make a variable called gameWindow of type renderWindow
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Button Masher", sf::Style::Titlebar | sf::Style::Close);

	//Game Loop
	while (gameWindow.isOpen()) //Runs every frame until the game window is closed
	{
		//TODO: Check for input
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

		//TODO: Update game state

		//TODO: Draw graphics
	}
	//Exit point for program
	return 0;
}