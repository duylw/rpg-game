#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize() 
{
}

void Skeleton::Load()
{
	if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png"))
	{
		std::cout << "Enemy Images Loaded!\n";
		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(400, 500));

		int XIndex = 0;
		int YIndex = 0;

		sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
	}
	else
	{
		std::cout << "Load enemy texture failed!\n";
		return;
	}
}

void Skeleton::Update()
{
}

void Skeleton::Draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}

