#pragma once
#include "Bullet.h"

#include <list>

class BulletManagment
{
private:
public:
	std::list<Bullet> bullets;
	void Initialize();
	void Load();
	void Update(float);
	void Draw(sf::RenderWindow&);

	void addBullet(const sf::Vector2f&,const sf::Vector2f&);
};

