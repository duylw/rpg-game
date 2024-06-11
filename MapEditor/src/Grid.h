#pragma once
#include <SFML/Graphics.hpp>

class Grid
{
private:

	sf::RectangleShape* hCell;
	sf::RectangleShape* vCell;

	sf::Vector2f position;
	sf::Vector2i totalCell;
	sf::Vector2f cellSize;
	sf::Vector2f cellScale;
	sf::Color lineColor;
	sf::Vector2f mapSize;

	int lineThickness;

public:
	Grid(
		const sf::Vector2f& ini_position,
		const sf::Vector2f& ini_cellSize,
		const sf::Vector2i& ini_totalCell,
		const sf::Vector2f& ini_cellScale,
		const sf::Color& color,
		int ini_lineThickness);
	~Grid();

	void Initialize();
	void Load();
	void Update(float);
	void Draw(sf::RenderWindow&);

	inline const sf::Vector2f& getPosition() const { return position; }
	inline const sf::Vector2i& getTotalCell() const { return totalCell; }
	inline const sf::Vector2f& getCellSize() const { return cellSize; }
	inline const sf::Vector2f& getScale() const { return cellScale; }
	inline const sf::Vector2f& getSize() const { return mapSize; }
};

