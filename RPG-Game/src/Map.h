#pragma once
#include <SFML/Graphics.hpp>
#include"Tile.h"
#include "MapLoader.h"
#include "MapData.h"

class Map
{
private:

	sf::Texture mapTileSet;
	Tile* tiles;

	MapLoader mapLoader;
	MapData mapData;

	int totalTile;
	int totalTileX;
	int totalTileY;

	int totalMapSprite;
	sf::Sprite *mapSprites;

public:
	Map();
	~Map();
	
	void Initialize();
	void Load(sf::RenderWindow&);
	void Update(float);
	void Draw(sf::RenderWindow&);
};

