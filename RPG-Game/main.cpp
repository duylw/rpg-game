#include <SFML/Graphics.hpp>
#include <iostream>

int main() 
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "RPG-Game");



	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	if (playerTexture.loadFromFile("Assets/PLayer/Textures/spritesheet.png"))
	{
		std::cout << "PLayer Images Loaded!\n";
		playerSprite.setTexture(playerTexture);


		int XIndex = 0;
		int YIndex = 0;

		playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
		playerSprite.setScale(sf::Vector2f(3, 3));
	}
	else
	{
		std::cout << "Load player texture failed!\n";
		return 0;
	}


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();

		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) playerSprite.move(sf::Vector2f(0 ,-0.1));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) playerSprite.move(sf::Vector2f(-0.1, 0));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) playerSprite.move(sf::Vector2f(0, 0.1));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) playerSprite.move(sf::Vector2f(0.1, 0));

		window.clear();

		window.draw(playerSprite);

		window.display();
		
	}


	return 1;
}