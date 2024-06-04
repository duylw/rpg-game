#include "Math.h"

void Math::normalize(sf::Vector2f& vector)
{
	float lenght = sqrt(pow(vector.x, 2) + pow(vector.y, 2));
	vector = vector / lenght;
}
