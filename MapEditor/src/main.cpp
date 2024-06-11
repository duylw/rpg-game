#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "GUI\GUI.h"
#include "MouseTile.h"
#include "Grid.h"
#include "Map.h"
#include "MapSaver.h"
#include "Core/MapData.h"


using namespace GUI;

int main()
{
	//Render window---
	sf::RenderWindow window(sf::VideoMode(1024, 768), "RPG-Game");

	sf::Clock clock;
	sf::Vector2f offset(0, 0);
	Button button(sf::Vector2f(0, 0), sf::Vector2f(1, 1));

	Grid grid(
		offset,
		sf::Vector2f(16, 16),
		sf::Vector2i(32, 24),
		sf::Vector2f(2, 2),
		sf::Color(255, 0, 0, 100),
		1);

	MouseTile mouseTile(grid, sf::Vector2f(16, 16), sf::Vector2f(2, 2), offset);
	Map map(grid, mouseTile);

	//Initialize---
	grid.Initialize();
	mouseTile.Initialize();
	mouseTile.Initialize();
	map.Inialize();
	button.Initialize();

	//Load---
	grid.Load();
	mouseTile.Load();
	mouseTile.Load();
	map.Load();
	button.Load();

	//Game Loop---
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}  
		}

		sf::Time deltaTimeTimer = clock.restart();
		double deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0;

		sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

		//Update---
		grid.Update(deltaTime);
		mouseTile.Update(deltaTime, mousePosition);
		map.Update(deltaTime);
		button.Update(deltaTime, mousePosition);

		if (button.isPressed())
		{
			MapData mapData(
				"Level1", grid.getCellSize(), grid.getTotalCell(),
				grid.getScale(), map.gettotalSpriteSize(), map.getMapArray());

			MapSaver saver;
			saver.Save("D:/GameVersion/rpg-game/RPG-Game/assets/Maps/newMap.rmap", mapData);
		}

		//Draw---
		window.clear();

		grid.Draw(window);
		map.Draw(window);
		mouseTile.Draw(window);
		button.Draw(window);

		window.display();
	}

	return 1;
}