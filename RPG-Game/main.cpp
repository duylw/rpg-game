#include <SFML/Graphics.hpp>
#include <iostream>


void normalize(sf::Vector2f &vector) 
{
	float lenght = sqrt(pow(vector.x, 2) + pow(vector.y, 2));
	vector = vector / lenght;
}

int main() 
{
	//Render window---
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG-Game");


	//Load Enemy---
	sf::Texture enemyTexture;
	sf::Sprite enemySprite;

	if (enemyTexture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png"))
	{
		std::cout << "Enemy Images Loaded!\n";
		enemySprite.setTexture(enemyTexture);
		enemySprite.setPosition(sf::Vector2f(400, 500));

		int XIndex = 0;
		int YIndex = 0;

		enemySprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
	}
	else
	{
		std::cout << "Load enemy texture failed!\n";
		return 0;
	}


	//Load Player---
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	if (playerTexture.loadFromFile("Assets/PLayer/Textures/spritesheet.png"))
	{
		std::cout << "PLayer Images Loaded!\n";
		playerSprite.setTexture(playerTexture);

		int XIndex = 0;
		int YIndex = 2;

		playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
	}
	else
	{
		std::cout << "Load player texture failed!\n";
		return 0;
	}


	//Load bullet---
	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 0.5f;
	sf::Vector2f bulletDirection(0, 0);

	
	//Calculate bullet direction---


	//Game Loop---
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();

		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) playerSprite.move(sf::Vector2f(0 ,-0.5f));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) playerSprite.move(sf::Vector2f(-0.5f, 0));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) playerSprite.move(sf::Vector2f(0, 0.5f));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) playerSprite.move(sf::Vector2f(0.5f, 0));

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			sf::RectangleShape newBullet = sf::RectangleShape(sf::Vector2f(20, 20));

			bullets.push_back(newBullet);
			
			int currentBulletInd = bullets.size() - 1;
			bullets[currentBulletInd].setPosition(playerSprite.getPosition());

		}

		for (int i = 0; i < bullets.size(); i++) 
		{

			bulletDirection = enemySprite.getPosition() - bullets[i].getPosition();
			normalize(bulletDirection);
			bullets[i].move(bulletDirection * bulletSpeed);
		}

		window.clear();

		window.draw(enemySprite);
		
		for (int i = 0; i < bullets.size(); i++) {
			window.draw(bullets[i]);
		}
		
		window.draw(playerSprite);
		window.display();
		
	}


	return 1;
}