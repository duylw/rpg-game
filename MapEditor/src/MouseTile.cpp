#include "MouseTile.h"

MouseTile::MouseTile(
	const Grid &ini_grid,
	const sf::Vector2f& ini_tileSize,
	const sf::Vector2f& ini_tileScale,
	const sf::Vector2f& ini_offset) :
	grid{ini_grid}, tileSize {ini_tileSize},
	tileScale{ ini_tileScale }, offset{ ini_offset },
	isMouseOnGrid{false}, currentTileId{0}
{
}

MouseTile::~MouseTile()
{
}

void MouseTile::Initialize()
{
}

void MouseTile::Load()
{
	if (tileSheet.loadFromFile("D:/GameVersion/rpg-game/RPG-Game/assets/world/prison/tilesheet.png"))
	{
		tile.setTexture(tileSheet);
		currentTileId = 2;
		tile.setTextureRect(sf::IntRect(currentTileId* tileSize.x, 0, tileSize.x, tileSize.y));
		tile.setScale(sf::Vector2f(tileScale.x, tileScale.y));
	}
}

void MouseTile::Update(float deltaTime, sf::Vector2f& mousePositon)
{

	const sf::Vector2f& gridPosition = grid.getPosition();
	const sf::Vector2f& gridSize = grid.getSize();

	if (
		mousePositon.x >= gridPosition.x && mousePositon.x < gridPosition.x + gridSize.x &&
		mousePositon.y >= gridPosition.y && mousePositon.y < gridPosition.y + gridSize.y)
	{
		isMouseOnGrid = true;

		//Index of mapSprites
		indexOfGrid.x = (mousePositon.x - offset.x) / (tileSize.x * tileScale.x);
		indexOfGrid.y = (mousePositon.y - offset.y) / (tileSize.y * tileScale.y);

		//Actual Position Of mapSprites relative to Grid
		tilePosition.x = indexOfGrid.x * tileSize.x * tileScale.x + offset.x;
		tilePosition.y = indexOfGrid.y * tileSize.x * tileScale.x + offset.y;

		tile.setPosition(tilePosition);
	}
	else isMouseOnGrid = false;

}	

void MouseTile::Draw(sf::RenderWindow& window)
{
	window.draw(tile);
}

bool MouseTile::isMouseClickedOnTile(sf::Vector2f& m_tilePosition, sf::Vector2i& m_indexOfGrid) const
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && isMouseOnGrid)
	{
		m_tilePosition = tilePosition;
		m_indexOfGrid = indexOfGrid;
		return true;
	}

	return false;
}

