#pragma once
#include <SFML/Graphics.hpp>
#include <random>
class Math
{
public:

	static void normalize(sf::Vector2f&);
	static bool isColliding(sf::FloatRect rect1, sf::FloatRect rect2);
	static const int getRandomNum(int start, int end) ;
};

