#include "Player.h"
#include <iostream>
#include "Math.h"

Player::Player():
	playerSpeed{0.5f}, bulletSpeed{0.5f},
	maxFireRate{0}, fireRateTimer{ 250.0f }
{
}

Player::~Player() 
{
}

void Player::Initialize()
{

	borderBox.setFillColor(sf::Color::Transparent);
	borderBox.setOutlineColor(sf::Color::Red);
	borderBox.setOutlineThickness(1);
	borderBox.setPosition(sprite.getPosition());

	size = sf::Vector2f(64, 64);

}

void Player::Load()
{
	if (texture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
	{
		std::cout << "PLayer Images Loaded!\n";
		sprite.setTexture(texture);

		int XIndex = 0;
		int YIndex = 2;

		sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));

		sprite.setScale(sf::Vector2f(1, 1));

		borderBox.setSize(
			sf::Vector2f(sprite.getScale().x * size.x, sprite.getScale().y * size.y)
		);
	}
	else
	{
		std::cout << "Load player texture failed!\n";
	}
}

void Player::Draw(sf::RenderWindow &window)
{
	window.draw(borderBox);
	window.draw(sprite);

	for (Bullet& bullet : bullets)
	{
		bullet.Draw(window);
	}
}

void Player::Update(float deltaTime, Skeleton &enemy, sf::RenderWindow &window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) sprite.move(sf::Vector2f(0, -1) * playerSpeed * deltaTime );

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) sprite.move(sf::Vector2f(-1, 0) * playerSpeed * deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) sprite.move(sf::Vector2f(0, 1) * playerSpeed * deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) sprite.move(sf::Vector2f(1, 0) * playerSpeed * deltaTime);

	if (fireRateTimer < maxFireRate) fireRateTimer += deltaTime;

	//Update bullet container 
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= maxFireRate)
	{
		Bullet newBullet(sprite.getPosition(), sf::Mouse::getPosition(window));
		newBullet.Load();
		window.draw(newBullet.sprite);

		bullets.push_back(newBullet);
		fireRateTimer = 0;
	}
	
	//Update each bullet
	for (auto i = bullets.begin(); i != bullets.end(); )
	{
		if (i->Update(deltaTime, enemy)) 
		{

			i = bullets.erase(i);
		}
		else
		{
			std::advance(i, 1);
		}
	}

	//Update Boundy Box
	borderBox.setPosition(sprite.getPosition());

}
