#pragma once
#include <SFML/Graphics.hpp>
#include "BulletManagment.h"

#include <list>

class Player
{
private:

	enum STATE{
		idle,
		up,
		left,
		down,
		right,
	};

	typedef Player::STATE entityState;

	STATE currentState;

	float maxStateTime;
	float stateTimeTimer;

	sf::Sprite sprite;

	sf::Vector2i texturePosition;

	sf::Texture texture;
	sf::Vector2f size;

	sf::Text healthBar;
	sf::Font font;

	sf::Sprite head;
	sf::Texture headTexture;

	sf::Sprite armor;
	sf::Texture armorTexture;	
	
	sf::Sprite weapon;
	sf::Texture weaponTexture;

	sf::RectangleShape borderBox;


	float playerSpeed;
	float maxFireRate;
	float fireRateTimer;
	int health;


public:


	Player();
	~Player();

	void changeHealth(int);
	void Initialize();
	void Load();
	void Draw(sf::RenderWindow&);
	void Update(float, BulletManagment&, sf::RenderWindow&);
	void updateTexture();


	inline const sf::FloatRect& getGolobalBounds()  { return sprite.getGlobalBounds(); }

	void onKeyBoard(float);
	void onClick(float, BulletManagment&, sf::RenderWindow&);
};

