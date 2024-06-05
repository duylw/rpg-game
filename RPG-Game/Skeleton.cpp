#include "Skeleton.h"
#include <iostream>

Skeleton::Skeleton() :
	skeletonSpeed{}
{
}

Skeleton::~Skeleton()
{
}

void Skeleton::Initialize()
{
	skeletonSpeed = 0.5f;

	borderBox.setFillColor(sf::Color::Transparent);
	borderBox.setOutlineColor(sf::Color::Blue);
	borderBox.setOutlineThickness(1);
	borderBox.setPosition(sprite.getPosition());

	size = sf::Vector2f(64, 64);

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

		sprite.setScale(sf::Vector2f(1, 1));

		borderBox.setSize(
			sf::Vector2f(sprite.getScale().x * size.x, sprite.getScale().y * size.y)
		);
	}
	else
	{
		std::cout << "Load enemy texture failed!\n";
		return;
	}
}

void Skeleton::Update(float deltaTime)
{
	borderBox.setPosition(sprite.getPosition());
}

void Skeleton::Draw(sf::RenderWindow &window)
{
	window.draw(borderBox);
	window.draw(sprite);
}

