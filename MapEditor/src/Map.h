#pragma once
#include <SFML/Graphics.hpp>
#include "MouseTile.h"
#include "Tile.h"
#include "Grid.h"

class Map
{
private:
	sf::Sprite* mapSprites;
	Tile* tile;

	MouseTile& mouseTile;
	const Grid& grid;

	int* mapArray;

	int totalSpriteSize;
public:
	Map(const Grid& ini_mapGrid, MouseTile& ini_mouseTile);
	~Map();

	void Inialize();
	void Load();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	inline const int gettotalSpriteSize() const { return totalSpriteSize; }
	inline const int *getMapArray() const { return mapArray; }

};

