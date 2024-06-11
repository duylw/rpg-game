#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.h"
#include "Skeleton.h"
#include "FrameRate.h"
#include "BulletManagment.h"
#include "Map.h"
#include "EntityObject.h"
#include "MapLoader.h"
#include "MapData.h"

void handleCollision(BulletManagment& BulletManage)
{
	auto& i = BulletManage.bullets;
	auto& j = EntityObject::skeleton;
	for (auto bullet = i.begin(); bullet != i.end();)
	{
		bool collisionDetected = false;
		for (auto skeleton = j.begin(); skeleton != j.end(); skeleton++)
		{
			if (Math::isColliding(bullet->getGlobalBounds(), skeleton->getGlobalBounds()))
			{
				collisionDetected = true;
				skeleton->changeHealth(-10);
				break;
			}
		}
		if (collisionDetected)
		{
			bullet = i.erase(bullet);
		}
		else
		{
			++bullet;
		}
	}
}

int main() 
{		
	//Render window---
	sf::RenderWindow window(sf::VideoMode(1024, 768), "RPG-Game");
	//window.setFramerateLimit(100);

	//Initialize---
	FrameRate frameRate;
	BulletManagment bulletManagement;
	Map map;

	sf::Clock clock;

	EntityObject::addPlayer();
	EntityObject::addSkeleton();


	frameRate.Initialize();
	bulletManagement.Initialize();
	map.Initialize();


	//Load---
	frameRate.Load();
	bulletManagement.Load();
	map.Load(window);

	//Game Loop---
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				EntityObject::deleteAllEntity();
				window.close();
			}

		}

		sf::Time deltaTimeTimer = clock.restart();
		double deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0;
		
		//Update---
		frameRate.Update(deltaTime);
		EntityObject::updateEnity(deltaTime, bulletManagement, window);
		bulletManagement.Update(deltaTime);

		handleCollision(bulletManagement);

		//Draw---
		window.clear();
		map.Draw(window);
		frameRate.Draw(window);
		bulletManagement.Draw(window);
		EntityObject::drawEntity(window);

		window.display();
	}

	return 1;
}