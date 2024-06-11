#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"

class Bullet
{
private:
	sf::Vector2f spawn;
	sf::Vector2f dir;
	sf::RectangleShape bullet;

	float speed;
	float lifeTime;

public:

	Bullet(const sf::Vector2f&,const sf::Vector2f&);
	~Bullet();

	void Initialize();
	void Load();
	void Update(float);
	void Draw(sf::RenderWindow&);

	inline bool outOfLifeTime() const { return lifeTime <= 0; };
	inline const sf::FloatRect getGlobalBounds() const { return bullet.getGlobalBounds(); }
};

