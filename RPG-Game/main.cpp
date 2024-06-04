#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Skeleton.h"

int main() 
{	
	//Render window---
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG-Game");


	Player player;
	Skeleton enemy;

	//Initialize---
	player.Initialize();
	enemy.Initialize();

	//Load---
	player.Load();
	enemy.Load();


	//Game Loop---
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();

		}

		//Update---
		enemy.Update();
		player.Update(enemy);


		//Draw---
		window.clear();

		enemy.Draw(window);
		player.Draw(window);
		
		window.display();
	}

	return 1;
}