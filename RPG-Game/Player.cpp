#include "Player.h"
#include <iostream>
#include "Math.h"

void Player::Initialize()
{
}

void Player::Load()
{
	if (texture.loadFromFile("Assets/PLayer/Textures/spritesheet.png"))
	{
		std::cout << "PLayer Images Loaded!\n";
		sprite.setTexture(texture);

		int XIndex = 0;
		int YIndex = 2;

		sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
	}
	else
	{
		std::cout << "Load player texture failed!\n";
	}
}

void Player::Draw(sf::RenderWindow &window)
{
	window.draw(sprite);

	for (int i = 0; i < bullets.size(); i++) 
	{
		window.draw(bullets[i]);
	}
}

void Player::Update(Skeleton &enemy)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) sprite.move(sf::Vector2f(0, -0.5f));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) sprite.move(sf::Vector2f(-0.5f, 0));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) sprite.move(sf::Vector2f(0, 0.5f));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) sprite.move(sf::Vector2f(0.5f, 0));

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		sf::RectangleShape newBullet = sf::RectangleShape(sf::Vector2f(20, 20));

		bullets.push_back(newBullet);

		int currentBulletInd = bullets.size() - 1;
		bullets[currentBulletInd].setPosition(sprite.getPosition());

	}

	for (int i = 0; i < bullets.size(); i++)
	{
		sf::Vector2f bulletDirection = enemy.sprite.getPosition() - bullets[i].getPosition();
		Math::normalize(bulletDirection);
		bullets[i].move(bulletDirection * bulletSpeed);
	}
}
