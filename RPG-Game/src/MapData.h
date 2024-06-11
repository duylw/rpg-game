#pragma once
#include <iostream>

struct MapData
{

	int version;

	std::string tilesheet;
	std::string name;

	int tileWidth;
	int tileHeight;

	int mapWidth;
	int mapHeight;

	int scaleX;
	int scaleY;

	int dataLength; 
	int* data;
};