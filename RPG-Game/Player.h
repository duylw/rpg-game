#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"
#include "Bullet.h"

#include <list>

class Player
{
private:
	sf::Texture texture;
	sf::Vector2f size;

	sf::RectangleShape borderBox;

	std::list<Bullet> bullets;

	float bulletSpeed;
	float playerSpeed;
	float maxFireRate;
	float fireRateTimer;

public:

	sf::Sprite sprite;

	Player();
	~Player();

	void Initialize();
	void Load();
	void Draw(sf::RenderWindow&);
	void Update(float, Skeleton&, sf::RenderWindow&);
};

