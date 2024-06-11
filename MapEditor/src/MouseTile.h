#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"

class MouseTile
{
private:
	sf::Texture tileSheet;
	sf::Sprite tile;

	sf::Vector2f tileSize;
	sf::Vector2f tileScale;
	sf::Vector2f offset;

	sf::Vector2f tilePosition;
	sf::Vector2i indexOfGrid;

	const Grid& grid;

	bool isMouseOnGrid;
	int currentTileId;
public:
	MouseTile(
		const Grid& ini_grid,
		const sf::Vector2f& ini_tileSize,
		const sf::Vector2f& ini_tileScale,
		const sf::Vector2f& ini_offset);

	~MouseTile();

	void Initialize();
	void Load();
	void Update(float, sf::Vector2f& mousePosition);
	void Draw(sf::RenderWindow&);
	bool isMouseClickedOnTile(sf::Vector2f& m_tilePosition, sf::Vector2i& m_tileGrid) const;

	inline const sf::Sprite& getSprite() const { return tile; }
	inline const int getCurrentTileId() { return currentTileId; }
};

