#include "Map.h"
#include <iostream>
#include <fstream>

Map::Map() :
	
	totalMapSprite{},
	totalTileX{}, totalTileY{}, totalTile{}, tiles{ NULL },
	mapSprites{ NULL }
{
}

Map::~Map()
{
	delete[]tiles;
}



void Map::Initialize()
{
}

void Map::Load(sf::RenderWindow& window)
{

	mapLoader.Load("assets/Maps/newMap.rmap", mapData);


	if (mapTileSet.loadFromFile(mapData.tilesheet))
	{
		std::cout << "Map texture loaded successfully\n";

		totalTileX = mapTileSet.getSize().x / (mapData.tileWidth);
		totalTileY = mapTileSet.getSize().y / (mapData.tileHeight);
		totalTile = totalTileX * totalTileY;

		tiles = new Tile[totalTile];
		mapSprites = new sf::Sprite[mapData.dataLength];

		for (int y = 0; y < totalTileY; y++)
		{
			for (int x = 0; x < totalTileX; x++)
			{
				int i = x + y * totalTileX;

				tiles[i].position = sf::Vector2f(x * mapData.tileWidth, y * mapData.tileHeight);
			}
		}
	}
	else
	{
		std::cout << "Map texture loaded fail\n";
	}

	for (int y = 0; y < mapData.mapHeight; y++)
	{
		for (int x = 0; x < mapData.mapWidth; x++)
		{
			int i = x + y * mapData.mapWidth;
			int tileId = mapData.data[i];

			mapSprites[i].setTexture(mapTileSet);
			mapSprites[i].setScale(sf::Vector2f(mapData.scaleX,mapData.scaleY));
			mapSprites[i].setTextureRect(sf::IntRect(
				tiles[tileId].position.x,
				tiles[tileId].position.y,
				mapData.tileWidth,
				mapData.tileHeight
			));
			mapSprites[i].setPosition(sf::Vector2f(x * mapData.tileWidth * mapData.scaleX, y * mapData.tileHeight * mapData.scaleY));
		}
	}

}

void Map::Update(float deltaTime)
{}

void Map::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < mapData.dataLength; i++) window.draw(mapSprites[i]);
}
