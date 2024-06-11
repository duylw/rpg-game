#include "Player.h"
#include <iostream>
#include "Math.h"

Player::Player() :
	playerSpeed{ 0.2f },
	maxFireRate{ 250.0f }, fireRateTimer{ 0 }, health{100}, maxStateTime{40}, stateTimeTimer{ 0 },
	currentState{ entityState::idle }
{ 
}

Player::~Player()
{
}

void Player::changeHealth(int hp)
{
	health += hp;
	healthBar.setString(std::to_string(health));
}

void Player::Initialize()
{
	
	maxStateTime = playerSpeed * 600.0f;

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
		std::cout << "Player Images Loaded!\n";
		sprite.setTexture(texture);

		if (font.loadFromFile("Assets/Fonts/arial.ttf"))
		{
			healthBar.setFont(font);
			healthBar.setString(std::to_string(100));
		}
		if (headTexture.loadFromFile("Assets/Player/Textures/helmetsheet.png"))
		{
			head.setTexture(headTexture);
		}		
		if (armorTexture.loadFromFile("Assets/Player/Textures/armorsheet.png"))
		{
			armor.setTexture(armorTexture);
		}
		if (weaponTexture.loadFromFile("Assets/Player/Textures/spearsheet.png"))
		{
			weapon.setTexture(weaponTexture);
		}

		updateTexture();

		sprite.setScale(sf::Vector2f(1.0f, 1.0f));
		
		head.setScale(sprite.getScale());
		armor.setScale(sprite.getScale());
		weapon.setScale(sprite.getScale());

		borderBox.setSize(
			sf::Vector2f(sprite.getScale().x * size.x, sprite.getScale().y * size.y)
		);

	}
	else
	{
		std::cout << "Load player texture failed!\n";
		return;
	}
}

void Player::Draw(sf::RenderWindow &window)
{
	window.draw(borderBox);
	window.draw(sprite);
	window.draw(head);
	window.draw(armor);
	window.draw(weapon);
}

void Player::Update(float deltaTime, BulletManagment& BulletManage, sf::RenderWindow &window)
{
	if (fireRateTimer < maxFireRate) fireRateTimer += deltaTime;
	if (stateTimeTimer < maxStateTime) stateTimeTimer += deltaTime;

	onKeyBoard(deltaTime);
	onClick(deltaTime, BulletManage, window);

	//Update Boundy Box
	borderBox.setPosition(sprite.getPosition());
	healthBar.setPosition(sprite.getPosition());
	head.setPosition(sprite.getPosition());
	armor.setPosition(sprite.getPosition());
	weapon.setPosition(sprite.getPosition());
	

	updateTexture();

}

void Player::updateTexture()
{
	
	if (stateTimeTimer >= maxStateTime)
	{
		std::cout << "current state: " << currentState << std::endl;
		switch (currentState)
		{
		case Player::idle:
			texturePosition = sf::Vector2i(0, texturePosition.y);
			break;
		case Player::left:
			texturePosition = sf::Vector2i((texturePosition.x + 1) % 9, 1);
			break;

		case Player::right:
			texturePosition = sf::Vector2i((texturePosition.x + 1) % 9,3);
			break;		
		case Player::up:
				texturePosition = sf::Vector2i((texturePosition.x + 1) % 9, 0);
				break;
			case Player::down:
				texturePosition = sf::Vector2i((texturePosition.x + 1) % 9, 2);
				break;
		default:
			break;
		}
		stateTimeTimer = 0;
	}

	float newX = texturePosition.x * size.x;
	float newY = texturePosition.y * size.y;
	sprite.setTextureRect(sf::IntRect(newX , newY, size.x, size.y));
	head.setTextureRect(sf::IntRect(newX, newY, size.x, size.y));
	armor.setTextureRect(sf::IntRect(newX, newY, size.x, size.y));
	weapon.setTextureRect(sf::IntRect(newX, newY, size.x, size.y));

}

void Player::onKeyBoard(float deltaTime)
{
	sf::Vector2f movement(0, 0);

	bool isMoving = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		currentState = Player::right;
		movement.x += 1;
		isMoving = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		currentState = Player::left;
		movement.x -= 1;
		isMoving = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		currentState = Player::down;
		movement.y += 1;
		isMoving = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		currentState = Player::up;
		movement.y -= 1;
		isMoving = true;
	}
	if (!isMoving) {
		currentState = Player::idle;
		stateTimeTimer = maxStateTime;
	}

	sprite.move(movement * playerSpeed * deltaTime);
}

void Player::onClick(float deltaTime, BulletManagment& BulletManage, sf::RenderWindow &window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && fireRateTimer >= maxFireRate)
	{
		BulletManage.addBullet(sprite.getPosition(), sf::Vector2f(sf::Mouse::getPosition(window)));
		fireRateTimer = 0;
	}
}