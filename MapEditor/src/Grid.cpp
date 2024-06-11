#include "Grid.h"
#include <iostream>


Grid::Grid(
	const sf::Vector2f& ini_position,
	const sf::Vector2f& ini_cellSize,
	const sf::Vector2i& ini_totalCell,
	const sf::Vector2f& ini_cellScale,
	const sf::Color& color,
	int ini_lineThickness
):
	lineThickness{ini_lineThickness}, hCell{ NULL }, vCell{ NULL },
	position{ini_position}, cellSize{ini_cellSize}, totalCell(ini_totalCell),
	cellScale{ini_cellScale}, lineColor{color}
	
{
}

Grid::~Grid()
{
	delete[]hCell;
	delete[]vCell;
}

void Grid::Initialize()
{
	vCell = new sf::RectangleShape[totalCell.x];
	hCell = new sf::RectangleShape[totalCell.y];

	mapSize = sf::Vector2f(
		totalCell.x * cellSize.x * cellScale.x,
		totalCell.y * cellSize.y * cellScale.y);

	for (int i = 0; i < totalCell.x; i++)
	{
		vCell[i].setSize(sf::Vector2f(cellSize.x * cellScale.x, cellSize.y * totalCell.y * cellScale.y));
		vCell[i].setPosition(sf::Vector2f(i * cellSize.x * cellScale.x + position.x, 0 + position.y));
		vCell[i].setFillColor(sf::Color::Transparent);
		vCell[i].setOutlineColor(lineColor);
		vCell[i].setOutlineThickness(-lineThickness);
	}

	for (int i = 0; i < totalCell.y; i++)
	{
		hCell[i].setSize(sf::Vector2f(totalCell.x * cellSize.x * cellScale.x, cellSize.y * cellScale.y));
		hCell[i].setPosition(sf::Vector2f(0 + position.x, i * cellSize.y * cellScale.y + position.y));
		hCell[i].setFillColor(sf::Color::Transparent);
		hCell[i].setOutlineColor(lineColor);
		hCell[i].setOutlineThickness(-lineThickness);
	}
}

void Grid::Load()
{
}

void Grid::Update(float deltaTime)
{
}

void Grid::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < totalCell.x; i++) window.draw(vCell[i]);
	for (int i = 0; i < totalCell.y; i++) window.draw(hCell[i]);
}

