#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"

class Player
{
private:
	
	sf::Texture texture;

public:

	sf::Sprite sprite;
	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 0.5f;

public:

	void Initialize();
	void Load();
	void Draw(sf::RenderWindow&);
	void Update(Skeleton&);
};

