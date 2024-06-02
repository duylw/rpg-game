#include <SFML/Graphics.hpp>
#include <iostream>

int main() 
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "RPG-Game");
	sf::CircleShape circle(50.0f);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(sf::Vector2f(100.0f, 100.0f));

	sf::RectangleShape rectangle(sf::Vector2f(100.0f, 200.0f));
	rectangle.setPosition(sf::Vector2f(10.0f, 10.0f));
	int x = rectangle.getPointCount();
	std::cout << x << std::endl;
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}

		window.clear();
		window.draw(rectangle);
		window.display();
	}


	return 1;
}