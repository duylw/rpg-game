#include "Math.h"

void Math::normalize(sf::Vector2f& vector)
{
	float lenght = sqrt(pow(vector.x, 2) + pow(vector.y, 2));
	vector = vector / lenght;
}

bool Math::isColliding(sf::FloatRect obj1, sf::FloatRect obj2)
{

	int left = obj1.left - (obj2.left + obj2.width);
	int right = (obj1.left + obj1.width) - obj2.left;
	int bottom = (obj1.top + obj1.height) - obj2.top;
	int top = obj1.top - (obj2.top + obj2.height);

	return (left < 0 && right > 0 && bottom > 0 && top < 0);
}

const int Math::getRandomNum(int start, int end) 
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(start, end);
	return dist6(rng);
}
