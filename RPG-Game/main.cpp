#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.h"
#include "Skeleton.h"
#include "FrameRate.h"
#include "Bullet.h"

int main() 
{	
	//Render window---
	sf::RenderWindow window(sf::VideoMode(1024, 768), "RPG-Game");
	window.setFramerateLimit(120);

	//Initialize---
	Player player;
	Skeleton enemy;
	FrameRate frameRate;

	sf::Clock clock;

	player.Initialize();
	enemy.Initialize();
	frameRate.Initialize();

	//Load---
	player.Load();
	enemy.Load();
	frameRate.Load();

	//Game Loop---
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();

		}

		sf::Time deltaTimeTimer = clock.restart();
		double deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0;
		
		//Update---
		enemy.Update(deltaTime);
		player.Update(deltaTime, enemy, window);
		frameRate.Update(deltaTime);

		//Draw---
		window.clear();

		enemy.Draw(window);
		player.Draw(window);
		frameRate.Draw(window);

		window.display();
	}

	return 1;
}