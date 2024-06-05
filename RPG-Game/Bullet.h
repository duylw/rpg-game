#pragma once
#include <SFML\Graphics.hpp>
#include "Math.h"
#include "Skeleton.h"

class Bullet
{
private:
	sf::Texture texture;

	float damge;
	float speed;
	float castTimer;

	sf::Vector2f spawnLocation;
	sf::Vector2f direction;
public:

	sf::Sprite sprite;

	Bullet();
	Bullet(const sf::Vector2f &, const  sf::Vector2i&);
	~Bullet();

	void Initialize();
	void Load();
	void Draw(sf::RenderWindow&);
	bool Update(float, Skeleton&);
};

