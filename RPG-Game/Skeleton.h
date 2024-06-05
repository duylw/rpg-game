#pragma once
#include <SFML/Graphics.hpp>

class Skeleton
{
private:
	sf::Texture texture;
	sf::Vector2f size;
	sf::RectangleShape borderBox;

	float skeletonSpeed;

public:
	sf::Sprite sprite;



	Skeleton();
	~Skeleton();

	void Initialize();
	void Load();
	void Update(float);
	void Draw(sf::RenderWindow&);
};

