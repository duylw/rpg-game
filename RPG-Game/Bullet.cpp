#include "Bullet.h"

Bullet::Bullet():
	speed{0.5f}, damge{10}, castTimer{800.0}
{
}

Bullet::Bullet(const sf::Vector2f&playerPosition, const  sf::Vector2i &targetPosition) :
	speed{ 0.5f }, damge{ 10 }, castTimer{ 800.0 }, spawnLocation{playerPosition}
{

	direction = sf::Vector2f(targetPosition) - spawnLocation;
	Math::normalize(direction);

}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
}

void Bullet::Load()
{
	if (texture.loadFromFile("Assets/Projectiles/upbomber.png"))
	{
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(0, 0, 48, 48));
		sprite.setPosition(spawnLocation);
	}
	else
	{

	}
}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

bool Bullet::Update(float deltaTime, Skeleton& enemy)
{

	castTimer -= deltaTime;

	if (castTimer <= 0 || Math::isColliding(sprite.getGlobalBounds(), enemy.sprite.getGlobalBounds())) {
		return true;
	}

	sprite.move(direction * speed * deltaTime);

	return false;
}