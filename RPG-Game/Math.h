#pragma once
#include <SFML/Graphics.hpp>
class Math
{
public:

	static void normalize(sf::Vector2f&);
	static bool isColliding(sf::FloatRect rect1, sf::FloatRect rect2);
};

