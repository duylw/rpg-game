#include "Skeleton.h"
#include "Math.h"
#include <iostream>


Skeleton::Skeleton() :
	skeletonSpeed{}, health{100}
{
}

Skeleton::~Skeleton()
{
}

void Skeleton::changeHealth(int hp)
{
	health += hp;
	healthBar.setString(std::to_string(health));
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
		sprite.setPosition(sf::Vector2f(Math::getRandomNum(0, 1024 - 1), Math::getRandomNum(0, 768 - 1)));

		if (font.loadFromFile("Assets/Fonts/arial.ttf"))
		{
			std::cout << "Font loaded\n";
			healthBar.setFont(font);
			healthBar.setString(std::to_string(health));
		}

		int XIndex = 0;
		int YIndex = 0;

		sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));

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

	if (!this->isDead())
	{
		healthBar.setPosition(sprite.getPosition());
		borderBox.setPosition(sprite.getPosition());
	}

}

void Skeleton::Draw(sf::RenderWindow &window)
{
	window.draw(healthBar);
	window.draw(borderBox);
	window.draw(sprite);
}

