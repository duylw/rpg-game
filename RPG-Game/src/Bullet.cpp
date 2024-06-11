#include "Bullet.h"

Bullet::Bullet(const sf::Vector2f&spawnLocation,const sf::Vector2f& target) :
	speed{0.5f}, lifeTime{800.0f},
	spawn{spawnLocation}
{
	dir = target - spawn;
	Math::normalize(dir);

	bullet.setSize(sf::Vector2f(50.0f, 50.0f));
	bullet.setFillColor(sf::Color::Green);
	bullet.setPosition(spawn);

}

Bullet::~Bullet(){}

void Bullet::Initialize()
{
}

void Bullet::Load()
{
}

void Bullet::Update(float deltaTime)
{	
	bullet.move(dir * speed * deltaTime);
	lifeTime -= deltaTime;
}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(bullet);
}

