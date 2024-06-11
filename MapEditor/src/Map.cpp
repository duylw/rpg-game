#include "Map.h"


Map::Map(const Grid& ini_grid, MouseTile &ini_mouseTile):
	mapSprites{NULL}, tile{NULL}, mapArray{NULL},
	grid{ini_grid}, mouseTile{ini_mouseTile}, totalSpriteSize{}
{	
}

Map::~Map()
{

}

void Map::Inialize()
{
	totalSpriteSize = grid.getTotalCell().x * grid.getTotalCell().y;

	mapSprites = new sf::Sprite[totalSpriteSize];
	mapArray = new int[totalSpriteSize];
	memset(mapArray, 0, sizeof(int) * totalSpriteSize);
}

void Map::Load()
{
}

void Map::Update(float deltaTime)
{
	sf::Vector2i spriteIndex;
	sf::Vector2f spritePosition;

	if (mouseTile.isMouseClickedOnTile(spritePosition, spriteIndex))
	{
		int actualIndex = spriteIndex.x + spriteIndex.y * grid.getTotalCell().x;
		mapArray[actualIndex] = mouseTile.getCurrentTileId();
		mapSprites[actualIndex] = mouseTile.getSprite();
	}
}

void Map::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < totalSpriteSize; i++)
	{
		window.draw(mapSprites[i]);
	}
}

