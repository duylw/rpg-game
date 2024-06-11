#pragma once
#include <SFML/Graphics.hpp>

class Skeleton
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f size;
	sf::RectangleShape borderBox;

	sf::Text healthBar;
	sf::Font font;

	float skeletonSpeed;
	int health;

public:

	Skeleton();
	~Skeleton();

	void changeHealth(int);

	inline bool isDead() const { return health <= 0; }

	void Initialize();
	void Load();
	void Update(float);
	void Draw(sf::RenderWindow&);

	inline const sf::FloatRect& getGlobalBounds() const { return sprite.getGlobalBounds(); };
};

