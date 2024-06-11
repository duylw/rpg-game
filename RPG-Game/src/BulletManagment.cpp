#include "BulletManagment.h"

void BulletManagment::Initialize()
{
}

void BulletManagment::Load()
{
}

void BulletManagment::Update(float deltaTime)
{
	for (auto i = bullets.begin(); i != bullets.end();)
	{
		if (i->outOfLifeTime())
		{
			i = bullets.erase(i);
		}
		else
		{
			i->Update(deltaTime);
			++i;
		}
	}
}

void BulletManagment::Draw(sf::RenderWindow & window)
{
	for (auto& i : bullets) i.Draw(window);
}



void BulletManagment::addBullet(const sf::Vector2f& spawnLocation, const sf::Vector2f& target)
{
	bullets.emplace_back(Bullet(spawnLocation, target));
}
